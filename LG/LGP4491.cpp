#include<cstdio>
#define re register
#define maxn 10000000
#define mod 1004535809
#define min(a,b) ((a)<=(b)?(a):(b))
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

int n,m,s,l;
int unit[2][22],rev[maxn+1],fac[maxn+1],inv[maxn+1];
int w[maxn+1],F[maxn+1],G[maxn+1];

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

int main(){
	unit[0][21]=cltpow(3,479);
	unit[1][21]=cltpow(334845270,479);
	for(re int i=0;i<2;++i)
		for(re int j=20;j>=0;--j)
			unit[i][j]=1LL*unit[i][j+1]*unit[i][j+1]%mod;
	cltstream::read(n);
	cltstream::read(m);
	cltstream::read(s);
	l=min(n/s,m);
	inv[1]=1;
	for(re int i=2;i<=n||i<=m;++i)
		inv[i]=(mod-1LL*mod/i*inv[mod%i]%mod)%mod;
	fac[0]=inv[0]=1;
	for(re int i=1;i<=n||i<=m;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
		inv[i]=1LL*inv[i-1]*inv[i]%mod;
	}
	for(re int i=0;i<=m;++i)
		cltstream::read(w[i]);
	for(re int i=0,j=1;i<=l;++i,j=1LL*j*(mod-1)%mod){
		F[i]=1LL*j*inv[i]%mod;
		G[l-i]=1LL*cltpow(m-i,n-i*s)*inv[m-i]%mod*inv[n-i*s]%mod*cltpow(inv[s],i)%mod;
	}
	re int N=1;
	for(;N<(l<<1|1);N<<=1);
	NTT(F,N,0);
	NTT(G,N,0);
	for(re int i=0;i<N;++i)
		F[i]=1LL*F[i]*G[i]%mod;
	NTT(F,N,1);
	re int ans=0;
	for(re int i=0;i<=l;++i)
		ans=(ans+1LL*F[l-i]*inv[i]%mod*w[i]%mod)%mod;
	cltstream::write(1LL*fac[n]*fac[m]%mod*ans%mod);
	clop();
	return 0;
}
