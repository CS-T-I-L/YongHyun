//내용동일
#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
bool vis[10] = {false};
int n;

void backTrack() {
    if(ans.size() == n){
        for(auto vv : ans){
            cout << vv << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            ans.push_back(i);
            backTrack();
            vis[i] = false;
            ans.pop_back();  
        }
    }
}

int main() {
    cin >> n;
    backTrack();
    return 0;
}

