#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int n;
vector<pair<int,int>> position;
vector<int> bombs;
bool vis[22][22]={false};
int board[22][22]={0};
int ans=0;
void first(int x,int y){
    for(int i=x-2;i<=x+2;i++){
        if(i<=n && i>=1){
            vis[i][y]=true;;
        }
    }
}//맞고
void second(int x,int y){
    for(int i=x-1;i<=x+1;i++){
        if(i<=n && i>=1){
            vis[i][y]=true;;
        }
    }
    for(int i=y-1;i<=y+1;i++){
        if(i<=n && i>=1){
            vis[x][i]=true;;
        }
    }
}//맞고
void third(int x,int y){
    vis[x-1][y-1]=true;
    vis[x+1][y-1]=true;
    vis[x-1][y+1]=true;
    vis[x+1][y+1]=true;
    vis[x][y]=true;
}//맞고
void init_vis(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[i][j]=false;
        }
    }
}//맞고
int count_area(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}//맞고
void color(){
    for(int i=0;i<bombs.size();i++){
        if(bombs[i]==1){
            first(position[i].first,position[i].second);
        }else if(bombs[i]==2){
            second(position[i].first,position[i].second);
        }else if(bombs[i]==3){
            third(position[i].first,position[i].second);
        }
    }
}//맞고
void backTrack(){//여기서 뭔가 초기화가 안되는건가
    if(position.size()==bombs.size()){
        color();//영역 칠하고
        int return_val=count_area();//세고

        if(return_val>ans){
            ans=return_val;//할당하고
        }
        init_vis();//초기화 했는데..?
        return;
    }
    for(int i=1;i<=3;i++){
        bombs.push_back(i);
        backTrack();
        bombs.pop_back();
    }

}


int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            board[i][j]=a;
            if(a==1){
                position.push_back({i,j});
            }
        }
    }
    backTrack();
    cout<<ans;
    return 0;
}
