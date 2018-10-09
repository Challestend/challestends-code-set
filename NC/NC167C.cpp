#include<cstdio>
#define re register
#define maxn 1048576

namespace cltstream{
    template <typename _tp>
    inline void read(_tp& x){
        int sn=1;
        char c=getchar();
        for(;c!=45&&(c<48||c>57);c=getchar());
        if(c==45)
            sn=-1,c=getchar();
        for(x=0;c>=48&&c<=57;x=(x<<3)+(x<<1)+(c^48),c=getchar());
        x*=sn;
    }

    template <typename _tp>
    inline void write(_tp x){
        if(x<0)
            putchar(45),x=-x;
        if(!x)
            putchar(48);
        else{
            int digit[20];
            for(digit[0]=0;x;digit[++digit[0]]=x%10,x/=10);
            for(;digit[0];putchar(digit[digit[0]--]^48));
        }
    }
}

int N;
int sum[2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];

int main(){
    cltstream::read(N);
    for(re int a=0,M=0;a<2&&M<N;++a)
    for(re int b=0;b<2&&M<N;++b)
    for(re int c=0;c<2&&M<N;++c)
    for(re int d=0;d<2&&M<N;++d)
    for(re int e=0;e<2&&M<N;++e)
    for(re int f=0;f<2&&M<N;++f)
    for(re int g=0;g<2&&M<N;++g)
    for(re int h=0;h<2&&M<N;++h)
    for(re int i=0;i<2&&M<N;++i)
    for(re int j=0;j<2&&M<N;++j)
    for(re int k=0;k<2&&M<N;++k)
    for(re int l=0;l<2&&M<N;++l)
    for(re int m=0;m<2&&M<N;++m)
    for(re int n=0;n<2&&M<N;++n)
    for(re int o=0;o<2&&M<N;++o)
    for(re int p=0;p<2&&M<N;++p)
    for(re int q=0;q<2&&M<N;++q)
    for(re int r=0;r<2&&M<N;++r)
    for(re int s=0;s<2&&M<N;++s)
    for(re int t=0;t<2&&M<N;++t){
        ++M;
        cltstream::read(sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]);
    }
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(t)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(s)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s-1][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(r)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r-1][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(q)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q-1][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(p)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p-1][q][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(o)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o-1][p][q][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(n)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n-1][o][p][q][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(m)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l][m-1][n][o][p][q][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(l)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k][l-1][m][n][o][p][q][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(k)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j][k-1][l][m][n][o][p][q][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(j)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i][j-1][k][l][m][n][o][p][q][r][s][t];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(i)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h][i-1][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(h)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g][h-1][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(g)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f][g-1][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(f)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e][f-1][g][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(e)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d][e-1][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(d)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c][d-1][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(c)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b][c-1][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(b)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a][b-1][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0;a<2;++a)
    for(re int b=0;b<2;++b)
    for(re int c=0;c<2;++c)
    for(re int d=0;d<2;++d)
    for(re int e=0;e<2;++e)
    for(re int f=0;f<2;++f)
    for(re int g=0;g<2;++g)
    for(re int h=0;h<2;++h)
    for(re int i=0;i<2;++i)
    for(re int j=0;j<2;++j)
    for(re int k=0;k<2;++k)
    for(re int l=0;l<2;++l)
    for(re int m=0;m<2;++m)
    for(re int n=0;n<2;++n)
    for(re int o=0;o<2;++o)
    for(re int p=0;p<2;++p)
    for(re int q=0;q<2;++q)
    for(re int r=0;r<2;++r)
    for(re int s=0;s<2;++s)
    for(re int t=0;t<2;++t)
    if(a)
    sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]+=sum[a-1][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t-1];
    for(re int a=0,M=0;a<2&&M<N;++a)
    for(re int b=0;b<2&&M<N;++b)
    for(re int c=0;c<2&&M<N;++c)
    for(re int d=0;d<2&&M<N;++d)
    for(re int e=0;e<2&&M<N;++e)
    for(re int f=0;f<2&&M<N;++f)
    for(re int g=0;g<2&&M<N;++g)
    for(re int h=0;h<2&&M<N;++h)
    for(re int i=0;i<2&&M<N;++i)
    for(re int j=0;j<2&&M<N;++j)
    for(re int k=0;k<2&&M<N;++k)
    for(re int l=0;l<2&&M<N;++l)
    for(re int m=0;m<2&&M<N;++m)
    for(re int n=0;n<2&&M<N;++n)
    for(re int o=0;o<2&&M<N;++o)
    for(re int p=0;p<2&&M<N;++p)
    for(re int q=0;q<2&&M<N;++q)
    for(re int r=0;r<2&&M<N;++r)
    for(re int s=0;s<2&&M<N;++s)
    for(re int t=0;t<2&&M<N;++t){
        ++M;
        cltstream::write(sum[a][b][c][d][e][f][g][h][i][j][k][l][m][n][o][p][q][r][s][t]);
        putchar(10);
    }
    return 0;
}