//int nx,int ny를 설정하니까 코드가 훨씬 간결해졌다
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n,k;
vector<pair<int,int>> v;
int board[102][102]={false};
bool vis[102][102]={false};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int ans=0;
//시작점의 위치
bool check(int x,int y){
    if(x<1 ||x>n ||y<1 ||y>n){
        return false;
    }
    if(vis[x][y]){
        return false;
    }
    if(board[x][y]==1){
        return false;
    }
    return true;
}
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
        ans++;
        vis[a][b]=true;
    }
    for(auto vv:v){
        queue<pair<int,int>> q;
        q.push(vv);
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=temp.first+dx[i];
                int ny=temp.second+dy[i];
                if(check(nx,ny)){
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
