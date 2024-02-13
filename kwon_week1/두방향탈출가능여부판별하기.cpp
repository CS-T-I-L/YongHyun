//range 확인하는 부분을 함수로 빼면 어떨까? -> 실수를 할 여지가 줄어든다
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int arr[102][102]={0};
bool vis[102][102]={false};
int dx[2]={1,0};
int dy[2]={0,1};
bool flag=false;
void backTrack(int x,int y){
    if(x>n || y>m){
        return;
    }
    if(x==n && y==m){
        flag=true;
    }
    vis[x][y]=true;
    for(int i=0;i<2;i++){
        if(arr[x+dx[i]][y+dy[i]]==1 && !vis[x+dx[i]][y+dy[i]]){
            backTrack(x+dx[i],y+dy[i]);
        }
    }
}

int main() {
   cin>>n>>m;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        cin>>arr[i][j];
    }

   backTrack(1,1);
   if(flag){
    cout<<1;
   }else{
    cout<<0;
   }
    return 0;
}
