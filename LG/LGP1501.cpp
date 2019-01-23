#include<cstdio>
#include<algorithm>
#define re register
#define maxn 100000
#define mod 51061

namespace cltstream{
	#define size 1048576
	char cltin[size+1],*ih=cltin,*it=cltin;
	inline char gc(){
		#ifdef ONLINE_JUDGE
			if(ih==it){
				it=(ih=cltin)+fread(cltin,1,size,stdin);
				if(ih==it)
					return EOF;
			}
			return *ih++;
		#else
			return getchar();
		#endif
	}

	char cltout[size+1],*oh=cltout,*ot=cltout+size;
	inline void pc(char c){
		if(oh==ot){
			fwrite(cltout,1,size,stdout);
			oh=cltout;
		}
		*oh++=c;
	}
	#define clop() fwrite(cltstream::cltout,1,cltstream::oh-cltstream::cltout,stdout),cltstream::oh=cltstream::cltout
	#undef size

	template <typename _tp>
	inline void read(_tp& x){
		int sn=1;
		char c=gc();
		for(;c!=45&&(c<48||c>57)&&c!=EOF;c=gc());
		if(c==45&&c!=EOF)
			sn=-1,c=gc();
		for(x=0;c>=48&&c<=57&&c!=EOF;x=(x<<3)+(x<<1)+(c^48),c=gc());
		x*=sn;
	}

	template <typename _tp>
	inline void write(_tp x,char text=-1){
		if(x<0)
			pc(45),x=-x;
		if(!x)
			pc(48);
		else{
			int digit[22];
			for(digit[0]=0;x;digit[++digit[0]]=x%10,x/=10);
			for(;digit[0];pc(digit[digit[0]--]^48));
		}
		if(text>=0)
			pc(text);
	}
}

struct LinkCutTree{
	int n,m;
	struct SplayNode{
		SplayNode *ftr,*lc,*rc;
		int size,val,sum,mul,add,rev;

		inline int isRoot(){
			return ftr==NULL||(ftr->lc!=this&&ftr->rc!=this);
		}

		inline void reverse(){
			std::swap(lc,rc);
			rev^=1;
		}

		inline void pushDown(){
			if(lc!=NULL){
				lc->val=(1LL*mul*lc->val+add)%mod;
				lc->sum=(1LL*mul*lc->sum+1LL*lc->size*add)%mod;
				lc->mul=1LL*mul*lc->mul%mod;
				lc->add=(1LL*mul*lc->add+add)%mod;
				if(rev)
					lc->reverse();
			}
			if(rc!=NULL){
				rc->val=(1LL*mul*rc->val+add)%mod;
				rc->sum=(1LL*mul*rc->sum+1LL*rc->size*add)%mod;
				rc->mul=1LL*mul*rc->mul%mod;
				rc->add=(1LL*mul*rc->add+add)%mod;
				if(rev)
					rc->reverse();
			}
			mul=1;
			add=rev=0;
		}

		inline void pushUp(){
			size=1;
			sum=val;
			if(lc!=NULL){
				size+=lc->size;
				sum=(sum+lc->sum)%mod;
			}
			if(rc!=NULL){
				size+=rc->size;
				sum=(sum+rc->sum)%mod;
			}
		}

		SplayNode(){
			size=val=sum=mul=1;
		}
	};
	SplayNode mempool[maxn+1],*stk[maxn+1];

	inline void rotate(re SplayNode* p){
		re SplayNode* q=p->ftr;
		p->ftr=q->ftr;
		if(p->ftr!=NULL){
			if(p->ftr->lc==q)
				p->ftr->lc=p;
			if(p->ftr->rc==q)
				p->ftr->rc=p;
		}
		if(q->rc==p){
			q->rc=p->lc;
			if(q->rc!=NULL)
				q->rc->ftr=q;
			p->lc=q;
			q->ftr=p;
		}
		else{
			q->lc=p->rc;
			if(q->lc!=NULL)
				q->lc->ftr=q;
			p->rc=q;
			q->ftr=p;
		}
		q->pushUp();
		p->pushUp();
	}

	inline void splay(re SplayNode* p){
		re int top=1;
		stk[top]=p;
		for(re SplayNode* q=p;!q->isRoot();stk[++top]=q=q->ftr);
		for(;top;stk[top--]->pushDown());
		for(;!p->isRoot();rotate(p))
			if(!p->ftr->isRoot())
				rotate((p->ftr->ftr->lc==p->ftr)==(p->ftr->lc==p)?p->ftr:p);
	}

	inline void access(re SplayNode* p){
		splay(p);
		p->pushDown();
		p->rc=NULL;
		p->pushUp();
		for(re SplayNode* q=p;q->ftr!=NULL;q=q->ftr){
			splay(q->ftr);
			q->ftr->pushDown();
			q->ftr->rc=q;
			q->ftr->pushUp();
		}
		splay(p);
	}

	inline void makeRoot(re SplayNode* p){
		access(p);
		p->reverse();
	}

	inline void split(re SplayNode* p,re SplayNode* q){
		makeRoot(p);
		access(q);
	}

	inline void link(re SplayNode* p,re SplayNode* q){
		makeRoot(p);
		p->ftr=q;
	}

	inline void cut(re SplayNode* p,re SplayNode* q){
		split(p,q);
		q->lc=p->ftr=NULL;
		q->pushUp();
	}

	LinkCutTree(){
		cltstream::read(n);
		cltstream::read(m);
		for(re int i=1;i<n;++i){
			int x,y;
			cltstream::read(x);
			cltstream::read(y);
			link(mempool+x,mempool+y);
		}
		for(re int i=1;i<=m;++i){
			re char opt=cltstream::gc();
			for(;opt!='+'&&opt!='*'&&opt!='-'&&opt!='/';opt=cltstream::gc());
			int x,y,z,w;
			cltstream::read(x);
			cltstream::read(y);
			switch(opt){
				case '+':
					cltstream::read(z);
					split(mempool+x,mempool+y);
					(mempool+y)->val=((mempool+y)->val+z)%mod;
					(mempool+y)->sum=((mempool+y)->sum+1LL*(mempool+y)->size*z)%mod;
					(mempool+y)->add=((mempool+y)->add+z)%mod;
					break;
				case '*':
					cltstream::read(z);
					split(mempool+x,mempool+y);
					(mempool+y)->val=1LL*(mempool+y)->val*z%mod;
					(mempool+y)->sum=1LL*(mempool+y)->sum*z%mod;
					(mempool+y)->mul=1LL*(mempool+y)->mul*z%mod;
					(mempool+y)->add=1LL*(mempool+y)->add*z%mod;
					break;
				case '-':
					cltstream::read(z);
					cltstream::read(w);
					cut(mempool+x,mempool+y);
					link(mempool+z,mempool+w);
					break;
				case '/':
					split(mempool+x,mempool+y);
					cltstream::write((mempool+y)->sum,10);
					break;
			}
		}
		clop();
	}
};
LinkCutTree CLT;

int main(){
	return 0;
}
