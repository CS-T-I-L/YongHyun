#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
bool vis[10]={false};
void backTrack(int k){
    if(v.size()==n){
        for(auto vv:v){
            cout<<vv<<' ';
        }
        cout<<endl;
        return;
    }
        for(int i=n;i>=1;i--){
        if(!vis[i]){
        v.push_back(i);
         vis[i]=true;
        backTrack(i);
        v.pop_back();
        vis[i]=false;
        }
        }
    
    }    





int main() {
    cin>>n;
    for(int i=n;i>=1;i--){
        vis[i]=true;
        v.push_back(i);
        backTrack(i);
        v.pop_back();
        vis[i]=false;
    }
    return 0;
}
