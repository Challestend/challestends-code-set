#include<cstdio>
#include<algorithm>
#define re register
#define maxn 300000

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

	template <typename _tp>
	inline void swap(_tp& x,_tp& y){
		_tp z=x;
		x=y;
		y=z;
	}
}

struct LinkCutTree{
	struct SplayNode{
		SplayNode *ftr,*ls,*rs;
		int val,sum,rev;

		inline int isRoot(){
			return ftr==NULL||(ftr->ls!=this&&ftr->rs!=this);
		}

		inline void reverse(){
			std::swap(ls,rs);
			rev^=1;
		}

		inline void pushDown(){
			if(rev){
				if(ls!=NULL)
					ls->reverse();
				if(rs!=NULL)
					rs->reverse();
				rev=0;
			}
		}

		inline void pushUp(){
			sum=val;
			if(ls!=NULL)
				sum^=ls->sum;
			if(rs!=NULL)
				sum^=rs->sum;
		}
	};

	SplayNode mempool[maxn+1];

	inline void rotate(re SplayNode* p){
		re SplayNode* q=p->ftr;
		q->pushDown();
		p->pushDown();
		p->ftr=q->ftr;
		if(p->ftr!=NULL){
			if(p->ftr->ls==q)
				p->ftr->ls=p;
			if(p->ftr->rs==q)
				p->ftr->rs=p;
		}
		if(q->rs==p){
			q->rs=p->ls;
			if(q->rs!=NULL)
				q->rs->ftr=q;
			p->ls=q;
			q->ftr=p;
		}
		else{
			q->ls=p->rs;
			if(q->ls!=NULL)
				q->ls->ftr=q;
			p->rs=q;
			q->ftr=p;
		}
		q->pushUp();
		p->pushUp();
	}

	inline void splay(re SplayNode* p){
		for(;!p->isRoot();rotate(p))
			if(!p->ftr->isRoot())
				rotate((p->ftr->ftr->ls==p->ftr)==(p->ftr->ls==p)?p->ftr:p);
	}

	inline void build(re int n){
		for(re int i=1;i<=n;++i){
			re SplayNode* p=mempool+i;
			p->ftr=p->ls=p->rs=NULL;
			cltstream::read(p->val);
			p->sum=p->val;
			p->rev=0;
		}
	}

	inline void access(re SplayNode* p){
		splay(p);
		p->pushDown();
		p->rs=NULL;
		p->pushUp();
		for(re SplayNode* q=p;q->ftr!=NULL;q=q->ftr){
			splay(q->ftr);
			q->ftr->pushDown();
			q->ftr->rs=q;
			q->ftr->pushUp();
		}
		splay(p);
	}

	inline SplayNode* findRoot(re SplayNode* p){
		access(p);
		for(;p->ls!=NULL;p=p->ls);
		splay(p);
		return p;
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
		if(findRoot(q)!=p)
			p->ftr=q;
	}

	inline void cut(re SplayNode* p,re SplayNode* q){
		makeRoot(p);
		if(findRoot(q)==p&&q->ftr==p&&q->ls==NULL){
			q->ftr=p->rs=NULL;
			p->pushUp();
		}
	}

	inline int queryPathXorSum(re int x,re int y){
		split(mempool+x,mempool+y);
		return (mempool+y)->sum;
	}

	inline void createEdge(re int x,re int y){
		link(mempool+x,mempool+y);
	}

	inline void destoryEdge(re int x,re int y){
		cut(mempool+x,mempool+y);
	}

	inline void modifyVertice(re int x,re int y){
		splay(mempool+x);
		(mempool+x)->val=y;
		(mempool+x)->pushUp();
	}

	void printTree(re SplayNode* p){
		if(p!=NULL){
			p->pushDown();
			printTree(p->ls);
			printf(
				"%d(%d,%d,%d)\n",
				p-mempool,
				p->ftr!=NULL?p->ftr-mempool:-1,
				p->ls!=NULL?p->ls-mempool:-1,
				p->rs!=NULL?p->rs-mempool:-1
			);
			printTree(p->rs);
		}
	}
};

int n,m;
LinkCutTree QAQ;

int main(){\
	cltstream::read(n);
	cltstream::read(m);
	QAQ.build(n);
	for(re int i=1;i<=m;++i){
		int opt,x,y;
		cltstream::read(opt);
		cltstream::read(x);
		cltstream::read(y);
		switch(opt){
			case 0:
				cltstream::write(QAQ.queryPathXorSum(x,y),10);
				break;
			case 1:
				QAQ.createEdge(x,y);
				break;
			case 2:
				QAQ.destoryEdge(x,y);
				break;
			case 3:
				QAQ.modifyVertice(x,y);
				break;
		}
	}
	clop();
	return 0;
}
