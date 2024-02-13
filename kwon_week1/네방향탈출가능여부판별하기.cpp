//main에서 다음 x,y를 찾는 부분의 가독성이 좋지 않음->int nx,int ny라고 설정하고 가자
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n,m;
int arr[102][102]={0};
bool vis[102][102]={false};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool check_range(int x,int y){
    if(x>n ||x<1 ||y>m ||y<1){
        return false;
    }
    if(vis[x][y]){
        return false;
    }
    if(arr[x][y]==0){
        return false;
    }
    return true;
}
int main() {
    cin>>n>>m;
    //1 1에서 출발해서 n m까지 가야됨
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    q.push({1,1});
    vis[1][1]=true;
    while(!q.empty()){
        pair<int,int> temp=q.front();
        vis[temp.first][temp.second]=true;
        q.pop();
        for(int i=0;i<4;i++){
            if(check_range(temp.first+dx[i],temp.second+dy[i])){
                if(temp.first+dx[i]==n &&temp.second+dy[i]==m){
                    cout<<1;
                    return 0;
                }
                q.push({temp.first+dx[i],temp.second+dy[i]});
            }
        }
    }
    cout<<0;
    return 0;
}
