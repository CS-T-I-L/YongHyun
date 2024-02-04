//조건을 잘 사용해야된다

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector<int> arr(m+1,m+1);//n+1개를 n+1로 초기화
    arr[0]=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
        arr[a]=1;
    }
    sort(v.begin(),v.end(),greater<>());
    for(int i=1;i<=m;i++){
        for(auto vv:v){
            if(vv<=i){
                arr[i]=min(arr[i],arr[i-vv]+1);
            }
        }
    }
    if(arr[m]!=m+1){
        cout<<arr[m];
    }else{
        cout<<-1;
    }
}
