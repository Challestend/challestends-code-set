#include<cstdio>
#define re register
#define maxn 32768
#define mod 998244353
#define swap(a,b) a^=b,b^=a,a^=b

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

int n,m;
int a[maxn+1],F[maxn+1],G[maxn+1];
int unit[2][24],rev[maxn+1];

inline int cltpow(re int x,re int y){
	re int res=1;
	for(;y;){
		if(y&1)
			res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return res;
}

inline void NTT(re int* F,re int n,re int tp){
	for(re int i=0;i<n;++i)
		if(i<(rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0)))
			swap(F[i],F[rev[i]]);
	for(re int k=1,p=1;p<n;++k,p<<=1)
		for(re int i=0;i<n;i+=p<<1)
			for(re int j=i,tmp=1;j<i+p;++j,tmp=1LL*tmp*unit[tp][k]%mod){
				re int x=F[j],y=1LL*F[j+p]*tmp%mod;
				F[j]=(x+y)%mod;
				F[j+p]=(x-y+mod)%mod;
			}
	re int v=cltpow(n,tp*(mod-2));
	for(re int i=0;i<n;++i)
		F[i]=1LL*F[i]*v%mod;
}

inline void polymul(re int* F,re int n,re int* G,re int m){
	re int N=1;
	for(;N<n+m-1;N<<=1);
	for(re int i=n;i<N;++i)
		F[i]=0;
	NTT(F,N,0);
	for(re int i=m;i<N;++i)
		G[i]=0;
	NTT(G,N,0);
	for(re int i=0;i<N;++i)
		F[i]=1LL*F[i]*G[i]%mod;
	NTT(F,N,1);
}

inline void solve(re int l,re int r){
	if(l<r){
		re int mid=(l+r)>>1;
		solve(l,mid);
		solve(mid+1,r);
		F[0]=G[0]=1;
		for(re int i=l;i<=mid;++i)
			F[i-l+1]=a[i];
		for(re int i=mid+1;i<=r;++i)
			G[i-mid]=a[i];
		polymul(F,mid-l+2,G,r-mid+1);
		for(re int i=l;i<=r;++i)
			a[i]=F[i-l+1];
	}
}

int main(){
	a[0]=1;
	unit[0][23]=cltpow(3,119);
	unit[1][23]=cltpow(332748118,119);
	for(re int i=0;i<2;++i)
		for(re int j=22;j>=0;--j)
			unit[i][j]=1LL*unit[i][j+1]*unit[i][j+1]%mod;
	cltstream::read(n);
	for(re int i=1;i<=n;++i)
		a[i]=i;
	solve(1,n);
	for(re int i=0;i<=n;++i)
		cltstream::write(a[i],32);
	clop();
	return 0;
}
