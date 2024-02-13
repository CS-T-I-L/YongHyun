//자구에서 풀었던 문제
//복잡할건 없는데 입력 받을때 1부터 받자->런타임 에러 발생할 여지를 없애야지?
#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[1002][1002]={0};
bool vis[1002]={false};
int ans=0;
void dfs(int x){
    for(int i=2;i<=n;i++){
        if(arr[x][i]==1 && !vis[i]){
            ans++;
            vis[i]=true;
            dfs(i);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[a][b]=arr[b][a]=1;
    }
    dfs(1);
    cout<<ans;
}
