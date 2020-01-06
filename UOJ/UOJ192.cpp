#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<map>
#define re register
#define maxn 100000
#define maxs 10000
#define maxval 100000000

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

int n,ec;
int f[maxs+1],g[maxs+1];
long long h[maxval+1];
int des[2*maxn+1],suc[2*maxn+1],len[2*maxn+1],las[maxn+1];
long long val[maxn+1];
std::map<long long,int> M;

inline long long rnd(){
	return ((rand()&0x7fff)<<16)+((rand()&0x7fff)<<1)+(rand()&1);
}

inline void connect(re int u,re int v,re int w){
	des[++ec]=v;
	suc[ec]=las[u];
	len[ec]=w;
	las[u]=ec;
}

void dfs(re int cur,re int ftr){
	for(re int i=las[cur];i;i=suc[i])
		if(des[i]!=ftr){
			val[des[i]]^=val[cur];
			for(re int j=1;j<=g[0]&&g[j]<=len[i];++j)
				for(;len[i]%g[j]==0;len[i]/=g[j],val[des[i]]^=h[j]);
			if(len[i]>1)
				val[des[i]]^=h[i]?h[i]:h[i]=(rnd()<<30)|rnd();
			dfs(des[i],cur);
		}
}

int main(){
	for(re int i=2;i<=maxs;++i){
		if(!f[i]){
			g[++g[0]]=i;
			h[i]=(rnd()<<30)|rnd();
		}
		for(re int j=1;j<=g[0]&&i*g[j]<=maxs;++j){
			f[i*g[j]]=1;
			if(i%g[j]==0)
				break;
		}
	}
	cltstream::read(n);
	for(re int i=1;i<n;++i){
		int u,v,w;
		cltstream::read(u);
		cltstream::read(v);
		cltstream::read(w);
		connect(u,v,w);
		connect(v,u,w);
	}
	dfs(1,0);
	re long long ans=0;
	for(re int i=1;i<=n;++i){
		ans+=M[val[i]];
		++M[val[i]];
	}
	cltstream::write(2*ans);
	clop();
	return 0;
}