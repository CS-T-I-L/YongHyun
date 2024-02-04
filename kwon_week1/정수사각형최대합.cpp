#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[102][102]={};
    int cnt[102][102]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i+1][j+1];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt[i+1][j+1]=max(cnt[i][j+1],cnt[i+1][j])+arr[i+1][j+1];
        }
    }
    cout<<cnt[n][n];
    return 0;
}
