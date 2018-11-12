// 大家好，我叫陈世琛，我不会做这题，但我会写暴力，如果评测机够快，这发暴力就会AC
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define llp(i,x,y) for(int i=x;i<y;++i) // [x,y) x->y
#define rlp(i,x,y) for(int i=y-1;i>=x;--i)  // [x,y) y->x
#define mem(a,x) memset(a,x,sizeof a)

ll gcd(ll a,ll b){ll x;while(b){x = a%b;a = b;b = x;}return a;}

ull a[300010];
bool yes[300010];
int n,M;
ull pp[300010];
void add(int i,int n){
    ull x = pp[i];
    for(;i<=n;i+=i&(-i))
        a[i] += x;
}
ull sum(int i){
    ull ans = 0;
    for(;i;i-=i&(-i))
        ans += a[i];
    return ans;
}
ull range(int x,int y){
    return sum(y) - sum(x-1);
}
int sta[300010],tot;
void change(int x){
    tot = 0;

    // 1..M-x -> x+1..M
    int L = 1;
    while(L <= M-x){
        int l = L, r = M-x;
        while(l<=r){
            int mid = (l+r)/2;
            if ( range(L, mid)*pp[x] != range(x+L, x+mid) )
                r = mid-1;
            else l = mid+1;
        }
        if (l <= M-x && yes[x+l] == 0) {
            sta[tot++] = x+l;
        }
        L = l+1;
    }

    // M-x+1..M -> 1..x 
    L = M-x+1;
    while(L <= M){
        int l = L, r = M;
        while(l<=r){
            int mid = (l+r)/2;
            if ( range(L, mid) != range(L-(M-x), mid-(M-x))*pp[M-x] )
                r = mid-1;
            else l = mid+1;
        }
        if (l <= M && yes[l-(M-x)] == 0) sta[tot++] = l - (M-x);
        L = l+1;
    }

    while(tot) {
        yes[sta[tot-1]] = 1;
        add(sta[tot-1],M);
        tot--;
    }
}
int main(){
    scanf("%d%d",&n,&M);
    pp[0] = 1;
    llp(i,1,M+1) pp[i] = pp[i-1]*23ull; 

    int aa;
    yes[1] = 1;add(1,M);
    llp(i,0,n) {
        scanf("%d",&aa);
        change(aa);
    }
    int q,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&r);
        if (yes[r+1]) puts("YES");
        else puts("NO");
    }
}