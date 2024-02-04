//backTrack함수 전후로 push, pop을 해주자(vis array가 있다면 이것도)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool vis[20]={false};
vector<int> v;
int m,n;
void backTrack(int k){
    if(v.size()==n){
        for(auto vv:v){
            cout<<vv<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=k+1;i<=m;i++){
        v.push_back(i);
        backTrack(i);
        v.pop_back();
    }
}
int main() {//3 2
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        v.push_back(i);
        backTrack(i);
        v.pop_back();
    }
    return 0;
}
