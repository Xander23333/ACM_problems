#include<bits/stdc++.h>
using namespace std;

#define llp(i,a,b) for (int i = a;i<b;++i)

struct node{
    int l,r,o,sta;
    bool operator < (const node& x)const {
        return r < x.r;
    }
}show[2000];
int dp[2010][1050];

int ma[100000];
int tmp[3000],tmpt;

int main(){
    int n;
    scanf("%d",&n);
    int tot = 0;
    llp(i,0,n) {
        int m;
        scanf("%d",&m);
        llp(j,0,m) {
            int ll,rr,oo;
            scanf("%d%d%d",&ll,&rr,&oo);
            show[tot].l = ll;
            show[tot].r = rr;
            show[tot].o = oo;
            show[tot].sta = i;
            tot++;

            tmp[tmpt++] = ll;tmp[tmpt++] = rr;
        }
    }
    
    sort(tmp,tmp+tmpt);
    tmpt = unique(tmp,tmp+tmpt)-tmp;
    llp(i,0,tmpt) ma[ tmp[i] ] = i+1;
    llp(i,0,tot) show[i].l = ma[show[i].l], show[i].r = ma[show[i].r];

    sort(show,show+tot);

    int all = (1<<n);
    
    mem(dp,-1);
    llp(i,0,tmpt+1) dp[i][0] = 0;
    int pos = 0;
    llp(i,1,tmpt+1){
        while(pos < tot && show[pos].r == i) {
            int staa = (1<<show[pos].sta);
            llp(j,0,all) if (~dp[show[pos].l][j]) dp[i][j|staa] = max(dp[i][j|staa], dp[show[pos].l][j] + show[pos].o);
            pos++;
        }
        llp(j,0,all) dp[i][j] = max(dp[i-1][j], dp[i][j]);
    }

    printf("%d\n",ans==0?-1:ans);
}