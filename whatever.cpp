#include<cstdio>
#include<cstdlib>
#include<ctime>
#define re register

namespace cltstream{
    #ifdef ONLINE_JUDGE
        #define size 1048576
        char str[size+1],*head=str,*tail=str;
        inline char gc(){
            if(head==tail){
                tail=(head=str)+fread(str,1,size,stdin);
                if(head==tail)
                    return EOF;
            }
            return *head++;
        }
        #undef size
    #else
        #define gc getchar
    #endif

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
    inline void write(_tp x,char text=' '){
        if(x<0)
            putchar(45),x=-x;
        if(!x)
            putchar(48);
        else{
            int digit[20];
            for(digit[0]=0;x;digit[++digit[0]]=x%10,x/=10);
            for(;digit[0];putchar(digit[digit[0]--]^48));
        }
        putchar(text);
    }
}

int n=1000,m=1000,maxval=1000;

int main(){
    freopen("whatever.out","w",stdout);
    srand(998244353);
    cltstream::write(n);
    cltstream::write(m,'\n');
    for(re int i=1;i<=n;++i){
        cltstream::write(1LL*rand()*rand()%(2*maxval+1)-maxval,'\n');
        srand(clock()*rand());
    }
    putchar(10);
    for(re int i=1;i<=m;++i){
        int opt=(1LL*rand()*rand()&1)+1;
        cltstream::write(opt);
        cltstream::write(1LL*rand()*rand()%n+1);
        if(opt==1)
            cltstream::write(1LL*rand()*rand()%n+1,'\n');
        else
            cltstream::write(1LL*rand()*rand()%(2*maxval+1)-maxval,'\n');
        srand(clock()*rand());
    }
    return 0;
}
