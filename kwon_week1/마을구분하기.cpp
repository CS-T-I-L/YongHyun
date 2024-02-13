//check bounds 부분을 함수로 빼니까 함수가 훨씬 간결해진다.
//지금 보니까 main 함수 안에서도 check bounds 쓸 수 있네?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//nxn크기의 2차원 영역
int n;
bool vis[27][27];
int arr[27][27];
int ans=0;
vector<int> ans_town;
int town=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool check_bounds(int x,int y){
    if(x>n ||x<1||y>n||y<1){
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

void dfs(int x,int y){
    if(!check_bounds(x,y)){
        return;
    }
    ans++;
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        dfs(x+dx[i],y+dy[i]);
    }
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j] && arr[i][j]==1){
                town++;
                dfs(i,j);
                ans_town.push_back(ans);
                ans=0;
            }
        }
    }
    sort(ans_town.begin(),ans_town.end());
    cout<<town<<endl;
    for(auto vv:ans_town){
        cout<<vv<<'\n';
    }
    return 0;
}
