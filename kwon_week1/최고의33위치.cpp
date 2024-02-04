//격자 탐색을 할때는 왼쪽 상단의 점을 기준으로 잡고 순회하자
//함수를 분리하는 것이 좋은 선택이 될 수도 있다
//변수를 설정할때 초기화는 습관적으로 해주자
#include <iostream>
using namespace std;
int ans=0;
int arr[22][22]={};
int count_coins(int x,int y){
    int cnt=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[x+i][y+j]==1){
                cnt++;
            }
        }
    }
    return cnt;
}





int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n-2;i++){
        for(int j=1;j<=n-2;j++){
            int a=count_coins(i,j);
            if(a>ans){
                ans=a;
            }
        }
    }
    cout<<ans;
}
