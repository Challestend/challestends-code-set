#include<cstdio>
#include<cstring>
#define re register
#define maxn 1000000
#define mod 19930726
#define max(a,b) ((a)>=(b)?(a):(b))
#define min(a,b) ((a)<=(b)?(a):(b))

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

int n,sum=1;
long long m;
char str[maxn+5];
int maxRight,mid,ans[(maxn<<1)+5];
long long cnt[maxn+5];

int cltpow(re int x,re long long y){
	if(y==0)
		return 1;
	else{
		re int res=cltpow(x,y>>1);
		res=1LL*res*res%mod;
		if(y&1)
			res=1LL*res*x%mod;
		return res;
	}
}

int main(){
	cltstream::read(n);
	cltstream::read(m);
	for(re int i=1;i<=n;++i){
		str[i]=cltstream::gc();
		for(;str[i]<'a'||str[i]>'z';str[i]=cltstream::gc());
	}
	for(re int i=1;i<=n;++i){
		ans[i]=max(min(ans[(mid<<1)-i],maxRight-i+1),1);
		for(;i-ans[i]>=1&&i+ans[i]<=n&&str[i-ans[i]]==str[i+ans[i]];++ans[i]);
		if(i+ans[i]-1>maxRight){
			maxRight=i+ans[i]-1;
			mid=i;
		}
		++cnt[(ans[i]<<1)-1];
	}
	for(re int i=n;i>=1;--i){
		cnt[i]+=cnt[i+2];
		if(m>cnt[i]){
			sum=1LL*sum*cltpow(i,cnt[i])%mod;
			m-=cnt[i];
		}
		else{
			sum=1LL*sum*cltpow(i,m)%mod;
			m=0;
			break;
		}
	}
	cltstream::write(m?-1:sum);
	clop();
	return 0;
}
