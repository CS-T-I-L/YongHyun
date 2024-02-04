//역시나 함수로 찢는건 좋은 선택일 수 있다.
//x,y 위치 헷갈리지 말자
//함수명, 변수명을 코테에서도 가독성 좋게 설정하자

#include <iostream>
using namespace std;
int arr[202][202]={};
int n,m;
int ans=0;
int count_1(int i,int j){
    return arr[i][j]+arr[i+1][j]+arr[i+1][j+1];
}
int count_2(int i,int j){
return arr[i][j]+arr[i+1][j]+arr[i][j+1];
}
int count_3(int i,int j){
    return arr[i][j]+arr[i][j+1]+arr[i+1][j+1];
}
int count_4(int i,int j){
    return arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1];
}
int count_row(int i,int j){
    return arr[i][j]+arr[i+1][j]+arr[i+2][j];
}
int count_column(int i,int j){
    return arr[i][j]+arr[i][j+1]+arr[i][j+2];
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            if(ans<count_1(i,j)){
                ans=count_1(i,j);
            }
            if(ans<count_2(i,j)){
                ans=count_2(i,j);
            }
            if(ans<count_3(i,j)){
                ans=count_3(i,j);
            }
            if(ans<count_4(i,j)){
                ans=count_4(i,j);
            }
        }
        }
    
    for(int i=1;i<=n-2;i++){
        for(int j=1;j<=m;j++){
            if(ans<count_row(i,j)){
                ans=count_row(i,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-2;j++){
            if(ans<count_column(i,j)){
                ans=count_column(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}
