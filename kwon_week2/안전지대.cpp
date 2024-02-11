#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int n,m;
int arr[52][52]={0};
bool vis[52][52]={false};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int k_max=0;
int ans=0;
int ans_k=1;
bool check_bounds(int x,int y, int k){
    if(vis[x][y]){
        return false;
    }
    if(arr[x][y]<=k){
        return false;
    }
    if(x>n||x<1||y>m||y<1){
        return false;
    }
    return true;
}

void init_vis(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=false;
        }
    }
}

void bfs(int k){
    int result=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check_bounds(i,j,k)){
                result++;
                if(ans<result){
                    ans=result;
                    ans_k=k;
                }
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    pair<int,int> temp=q.front();
                    q.pop();
                    vis[temp.first][temp.second]=true;
                    for(int ni=0;ni<4;ni++){
                        int nx=temp.first+dx[ni];
                        int ny=temp.second+dy[ni];
                        if(check_bounds(nx,ny,k)){
                            q.push({nx,ny});
                            vis[nx][ny]=true;
                        }
                    }
                }
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){
            int a;
            cin>>a;
            arr[i][j]=a;
            if(k_max<a){
                k_max=a;
            }
        }
    }
    for(int k=1;k<k_max;k++){
        init_vis();
        bfs(k);
    }
    cout<<ans_k<<' '<<ans;
    return 0;
}

