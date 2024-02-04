//vector의 원소들의 합을 구할때, numeric 을 include 해서, accumulate 함수를 쓰자! 굉장히 유용함
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int n;
int arr[12][12]={0};
vector<int> v;
bool vis[12]={false};
int ans=0;
int temp=0;
int idx=0;
void backTrack(int k){
    if(v.size()==n){
        if(ans<accumulate(v.begin(), v.end(), 0)){
            ans=accumulate(v.begin(), v.end(), 0);
        }
    }else{
        for(int i=1;i<=n;i++){
        if(!vis[i]){
            idx++;
            vis[i]=true;
            v.push_back(arr[idx][i]);
            backTrack(i);
            idx--;
            v.pop_back();
            vis[i]=false;
        }
    }
    }
}


int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        idx++;
        vis[i]=true;
        v.push_back(arr[idx][i]);
        backTrack(i);
        v.pop_back();
        vis[i]=false;
        idx--;
    }
    cout<<ans;
    return 0;
}
