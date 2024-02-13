//index는 항상 조심하자
//ide가 아니여서 오타한번 나면 못고친다 -> 처음에 할때 제대로
#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[22]={0};
vector<int> v;
int ans=0;
int temp=0;
void backTrack(int x){
    if(v.size()==m){
        int temp=v[0];
        for(int i=1;i<v.size();i++){
            temp=temp^v[i];
        }
        if(ans<temp){
            ans=temp;
        }
        return;
    }
    if(x>n){
        return;
    }
    for(int i=x+1;i<=n;i++){
        v.push_back(arr[i]);
        backTrack(i);
        v.pop_back();
    }

}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n-m+1;i++){
        v.push_back(arr[i]);
        backTrack(i);
        v.pop_back();
    }
    cout<<ans;
    return 0;
}
