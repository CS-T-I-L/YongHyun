#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[100002]={0};
int dp[100002]={0};
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }//arr에 다 담는다
    dp[1]=arr[1];//1은 기본적으로 들어가있다
    for(int i=2;i<=n;i++){//
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
    }
    

    cout<<*max_element(dp+1, dp+n+1);
    return 0;
}
