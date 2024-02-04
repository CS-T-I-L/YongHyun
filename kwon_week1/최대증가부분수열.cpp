//최대 증가 부분 수열은 dp인데 2중 for문을 사용한다는 것을 기억하자!
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    //n개의 숫자가 주어졌을때, 가장 긴 증가 부분 수열의 길이?
    int n;
    cin>>n;
    vector<int> v;
    int arr[1002]={};
    int cnt[1002]={1};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                v.push_back(cnt[j]);
            }
        }
        if(v.empty()){
            cnt[i]=1;

        }else{
            cnt[i]=*max_element(v.begin(),v.end())+1;
        }
        v.clear();
    }
    cout<<*max_element(cnt, cnt+n);
    return 0;
}
