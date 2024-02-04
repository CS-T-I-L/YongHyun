#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[1002]={};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;
    int cnt[1002]={};
    for(int i=0;i<n;i++){
        cnt[i]=1;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                v.push_back(cnt[j]);
            }
        }
        if(!v.empty()){
            cnt[i]=*max_element(v.begin(),v.end())+1;
        }
        v.clear();
    }
    cout<<*max_element(cnt,cnt+n);
    return 0;
}
