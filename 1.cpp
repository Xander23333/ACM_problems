#include<bits/stdc++.h>
using namespace std;

const int n = 20;
bool ver[n], lob[n], rob[n];
int qpos[n];
int ans=0;
void dfs(int row){
    if (row == 8) {
        ans ++ ;
        return ;
    }
    for(int i = 0; i < 8; ++i) if (!ver[i] && !rob[row+i] && !lob[7+row-i]){
        ver[i] = rob[row+i] = lob[7+row-i] = 1;
        qpos[row] = i;
        dfs(row+1);
        ver[i] = rob[row+i] = lob[7+row-i] = 0;
    }
}
int main(){
    dfs(0);
    cout<<ans<<endl;
}