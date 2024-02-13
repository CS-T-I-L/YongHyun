#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n,m;
int arr[102][102]={0};
bool vis[102][102]={false};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int cnt_board[102][102]={0};
bool check_bounds(int x,int y){
    if(x>n||x<1||y>m||y<1){
        return false;
    }
    if(arr[x][y]==0){
        return false;
    }
    if(vis[x][y]){
        return false;
    }
    return true;
}

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    queue<pair<int,int>> q;
    q.push({1,1});
    vis[1][1]=true;
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=temp.first+dx[i];
            int ny=temp.second+dy[i];
            if(check_bounds(nx,ny)){
                vis[nx][ny]=true;
                q.push({nx,ny});
                cnt_board[nx][ny]=cnt_board[temp.first][temp.second]+1;
            }
        }
    }
    if(cnt_board[n][m]==0){
        cout<<-1;
    }else{
        cout<<cnt_board[n][m];
    }

    return 0;
}
