#include<cstdio>
#include<algorithm>
#define re register
#define maxn 300

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

int n;
long long ans;
int h[maxn+1];

int main(){
    cltstream::read(n);
    for(re int i=1;i<=n;++i)
        cltstream::read(h[i]);
    std::sort(h+1,h+n+1);
    for(re int head=0,tail=n;head<tail;){
        ans+=(h[tail]-h[head])*(h[tail]-h[head]);
        ++head;
        if(head==tail)
            break;
        ans+=(h[tail]-h[head])*(h[tail]-h[head]);
        --tail;
    }
    cltstream::write(ans);
    clop();
    return 0;
}
