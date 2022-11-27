#include <queue>
#include <iostream>

using namespace std;

const int N = 110;

int n,m;
queue < pair<int,int> > q;
int map[N][N],d[N][N];

int bfs(){
    q.push({0,0});
    memset(d,-1,sizeof d);
    d[0][0] = 0;
    // 前后左右
    int dx[] = {0,0,1,-1},dy[] = {1,-1,0,0};
    while(!q.empty()){
        auto curPoint = q.front();
        for(int i = 0;i < 4;i ++){
            int x = curPoint.first + dx[i],y = curPoint.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && map[x][y] == 0 && d[x][y] == -1){
                d[x][y] = d[curPoint.first][curPoint.second] + 1;
                q.push({x,y});
            }
        }
        q.pop();
    }
    return d[n - 1][m - 1];
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < n; i++){
        for(int j = 0;j < m;j ++){
            cin >> map[i][j];
        }
    }
    cout << bfs() << endl;
    return 0;
}