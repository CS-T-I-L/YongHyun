#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,k;
int board[102][102]={0};

int drop_block(){
    for(int i=1;i<=n;i++){
        for(int j=k;j<=m+k-1;j++){
            if(board[i][j]!=0){
                return i-1;
            }
        }
    }
    return n;
}

int main() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>board[i][j];
        }
    }
    int temp=drop_block();
    for(int j=k;j<=m+k-1;j++){
        board[temp][j]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j]!=0){
                cout<<1<<' ';
            }else{
                cout<<0<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
