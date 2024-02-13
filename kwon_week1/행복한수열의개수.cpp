//연속으로 x개 존재한다->스택을 사용하는 것이 좋은 선택일수도 있다
//이때는 스택을 전부 비운뒤, 추가를 해줘야된다.
#include <iostream>
#include <stack>
using namespace std;
int arr[102][102]={};
int n,m;
int ans=0;


void count_column(int i){
    stack<int> s;
    for(int j=1;j<=n;j++){
        if(s.empty() || s.top()==arr[i][j]){
            s.push(arr[i][j]);
            if(s.size()==m){
                ans++;
                return;
            }
        }else{
            while(!s.empty()){
                s.pop();
            }
            s.push(arr[i][j]);
        }
    }
}

void count_row(int j){
    stack<int> s;
    for(int i=1;i<=n;i++){
        if(s.empty() || s.top()==arr[i][j]){
            s.push(arr[i][j]);
            if(s.size()==m){
                ans++;
                return;
            }
        }else{
            while(!s.empty()){
                s.pop();
            }
            s.push(arr[i][j]);
        }
    }
}


int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        count_row(i);
    }
    for(int j=1;j<=n;j++){
        count_column(j);
    }
    cout<<ans;
    return 0;
}
