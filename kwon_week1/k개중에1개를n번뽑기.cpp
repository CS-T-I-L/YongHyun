//백트래킹에서 설정과 되돌리는 것은 최대한 빨리 하는 것이 좋다
//재귀함수니까 이스케이프 조건을 맨 처음에 명시를 해줘야된다
//이스케이프 조건에서 pop을 하면 2번 pop하는거니까 하지 말자
#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<int> v;
void backTrack(){
    if(v.size()==n){
        for(auto vv:v){
            cout<<vv<<' ';
        }
        cout<<endl;
        return;
    }else{
        for(int i=1;i<=k;i++){
        v.push_back(i);
        backTrack();
        v.pop_back();
    }
    }
}

int main(){
    cin>>k>>n;
    backTrack();
}
