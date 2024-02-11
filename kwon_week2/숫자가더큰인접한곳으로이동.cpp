#include <iostream>

using namespace std;
int n,r,c;
int arr[102][102]={0};
//상하좌우
bool move(){//격자 밖은 0이니까 벗어날 일이 없다
    if(arr[r-1][c]>arr[r][c]){
        r=r-1;
        return true;
    }else if(arr[r+1][c]>arr[r][c]){
        r=r+1;
        return true;
    }else if(arr[r][c-1]>arr[r][c]){
        c=c-1;
        return true;
    }else if(arr[r][c+1]>arr[r][c]){
        c=c+1;
        return true;
    }
    return false;
}
int main() {
    cin>>n>>r>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<arr[r][c]<<' ';
    while(move()){
        cout<<arr[r][c]<<' ';
    }

    return 0;
}
