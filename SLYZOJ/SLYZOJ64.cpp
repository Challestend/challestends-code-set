#include<cstdio>
#define re register
#define maxn 10000000

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
	#define clop() fwrite(cltstream::cltout,1,cltstream::oh-cltstream::cltout,stdout)
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

int t,k,p;
int f[maxn+1],g[maxn+1],phi[maxn+1]={0,1};

inline int cltpow(re int x,re int y,re int mod){
	re int res=1;
	for(;y;){
		if(y&1)
			res=1LL*res*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return res;
}

int solve(re int k,re int p){
	return p==1?0:cltpow(k,solve(k,phi[p])+phi[p],p);
}

int main(){
	for(re int i=2;i<=maxn;++i){
		if(!f[i]){
			g[++g[0]]=i;
			phi[i]=i-1;
		}
		for(re int j=1;j<=g[0]&&i*g[j]<=maxn;++j){
			f[i*g[j]]=1;
			if(i%g[j])
				phi[i*g[j]]=phi[i]*phi[g[j]];
			else{
				phi[i*g[j]]=phi[i]*g[j];
				break;
			}
		}
	}
	cltstream::read(t);
	for(;t;--t){
		cltstream::read(k);
		cltstream::read(p);
		cltstream::write(solve(k,p),10);
	}
	clop();
	return 0;
}
