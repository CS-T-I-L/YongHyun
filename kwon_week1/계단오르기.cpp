#include <iostream>
//2개 or 3개 올라갈 수 있다.
using namespace std;
int main() {
    int arr[1002]={};
    arr[2]=1;
    arr[3]=1;
    int n;
    cin>>n;
    for(int i=4;i<=n;i++){
        arr[i]=(arr[i-2]+arr[i-3])%10007;
    }
    if(arr[n]==0){
        cout<<0<<endl;
    }else{
        cout<<arr[n]<<endl;
    }
    return 0;
}
