#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n;
int board[102][102]={0};
bool vis[102][102]={false};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int bomb_cnt=0;
int max_cnt=0;
bool check_bounds(int k, int x,int y){
    if(x>n ||x<1||y>n||y<1){
        return false;
    }
    if(vis[x][y]){
        return false;
    }
    if(board[x][y]!=k){
        return false;
    }
    return true;
}
int bfs(int k,int x,int y){
    int cnt=0;
    queue<pair<int,int>> q;
    vis[x][y]=true;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> temp=q.front();
        q.pop();
        cnt++;
        for(int i=0;i<4;i++){
            int nx=temp.first+dx[i];
            int ny=temp.second+dy[i];
            if(check_bounds(k,nx,ny)){
                q.push({nx,ny});
                vis[nx][ny]=true;
            }
        }
    }
    return cnt;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]){
               int cnt=bfs(board[i][j],i,j);
               if(cnt>=4){
                bomb_cnt++;
               }
               if(max_cnt<cnt){
                max_cnt=cnt;
               }
            }
        }
    }
    cout<<bomb_cnt<<' '<<max_cnt;
    return 0;
}
