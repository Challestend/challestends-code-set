#include<cstdio>
#include<cstdlib>
#include<ctime>
#include"F:/clt/challestends-code-set/Libraries/cltrnd.h"
#define re register

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

int n=10,m=10,k=10;

int main(){
	cltlib::srnd(2281701377LL*time(0));
	freopen("data.in","w",stdout);
	cltstream::write(n,32);
	cltstream::write(k,10);
	for(re int i=2;i<=n;++i){
		cltstream::write(cltlib::rnd()%(i-1)+1,32);
		cltstream::write(i,10);
	}
	for(re int i=1;i<=n;++i)
		cltstream::write(cltlib::rnd()%10000,i<n?32:10);
	cltstream::write(m,10);
	for(re int i=1;i<=m;++i){
		cltstream::write(cltlib::rnd()%n+1,32);
		cltstream::write(cltlib::rnd()%n+1,10);
	}
	clop();
	return 0;
}