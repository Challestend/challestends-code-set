#include<cstdio>
#include<algorithm>
#define re register
#define maxn 10000
#define max(a,b) ((a)>=(b)?(a):(b))

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

int t,n,w,h;
struct seg{
	long long x,y1,y2,w;

	seg(re long long _x=0,re long long _y1=0,re long long _y2=0,re long long _w=0){
		x=_x;
		y1=_y1;
		y2=_y2;
		w=_w;
	}
};
seg a[(maxn<<1)+1];
long long p[(maxn<<1)+1],mx[(maxn<<3)+1],add[(maxn<<3)+1];

inline bool operator<(re seg p1,re seg p2){
	return p1.x!=p2.x?p1.x<p2.x:p1.w<p2.w;
}

void update(re int L,re int R,re long long x,re int cur,re int l,re int r){
	if(l>=L&&r<=R){
		mx[cur]+=x;
		add[cur]+=x;
	}
	else{
		mx[cur<<1]+=add[cur];
		add[cur<<1]+=add[cur];
		mx[cur<<1|1]+=add[cur];
		add[cur<<1|1]+=add[cur];
		add[cur]=0;
		re int mid=(l+r)>>1;
		if(L<=mid)
			update(L,R,x,cur<<1,l,mid);
		if(R>mid)
			update(L,R,x,cur<<1|1,mid+1,r);
		mx[cur]=max(mx[cur<<1],mx[cur<<1|1]);
	}
}

int main(){
	cltstream::read(t);
	for(;t;--t){
		cltstream::read(n);
		cltstream::read(w);
		cltstream::read(h);
		for(re int i=1;i<=n;++i){
			long long x,y,z;
			cltstream::read(x);
			cltstream::read(y);
			cltstream::read(z);
			a[(i<<1)-1]=seg(x,y,y+h-1,z);
			a[(i<<1)]=seg(x+w,y,y+h-1,-z);
			p[(i<<1)-1]=y;
			p[(i<<1)]=y+h-1;
		}
		std::sort(p+1,p+(n<<1)+1);
		p[0]=std::unique(p+1,p+(n<<1)+1)-p-1;
		for(re int i=1;i<=(n<<1);++i){
			a[i].y1=std::lower_bound(p+1,p+p[0]+1,a[i].y1)-p;
			a[i].y2=std::lower_bound(p+1,p+p[0]+1,a[i].y2)-p;
		}
		std::sort(a+1,a+(n<<1)+1);
		re long long ans=0;
		for(re int i=1;i<=(n<<1);++i){
			update(a[i].y1,a[i].y2,a[i].w,1,1,p[0]);
			ans=max(ans,mx[1]);
		}
		cltstream::write(ans,10);
	}
	clop();
	return 0;
}
