#include <iostream>
using namespace std;

const int N = 10;

int n;
int path[N];
bool flag[N];

void dfs(int u){
    if(u == n){
        for(int i = 0;i < n;i ++){
            printf("%d ",path[i]);
        }
        puts("");
        return;
    }
    for(int i = 1;i <= n;i++){
        if(!flag[i]){
            path[i] = i;
            flag[i] = true;
            dfs(i + 1);
            flag[i] = false;
        }
    }
}

int main(){
    cin >> n;
    dfs(n);
    return 0;
}