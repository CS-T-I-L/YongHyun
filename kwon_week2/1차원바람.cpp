#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
int n,m,q;
pair<int,char> cmd;
int arr[102][102]={0};
char move_left(int row){
    int temp=arr[row][1];
    for(int i=1;i<m;i++){
        arr[row][i]=arr[row][i+1];
    }
    arr[row][m]=temp;
    return 'R';
}

char move_right(int row){
    int temp=arr[row][m];
    for(int i=m;i>1;i--){
        arr[row][i]=arr[row][i-1];
    }
    arr[row][1]=temp;
    return 'L';
}

bool check_upper(int row){
    for(int i=1;i<=m;i++){
        if(arr[row-1][i]==arr[row][i]){
            return true;
        }
    }
    return false;
}
bool check_down(int row){
    for(int i=1;i<=m;i++){
        if(arr[row+1][i]==arr[row][i]){
            return true;
        }
    }
    return false;
}


void iter_up(char dir, int row){
    for(int i=row;i>=1;i--){
        if(dir=='L'){
            dir=move_left(i);
        }else if(dir=='R'){
            dir=move_right(i);
        }else{
            break;
        }
        if(!check_upper(i)){
            return;
        }
    }
}
void iter_down(char dir, int row){
    for(int i=row;i<=n;i++){
        if(dir=='L'){
            dir=move_left(i);
        }else if(dir=='R'){
            dir=move_right(i);
        }else{
            break;
        }
        if(!check_down(i)){
            return;
        }
    }
}

void execute(int row,char dir){
    int temp[102]={0};
    char up='o';
    char down='o';
    for(int i=1;i<=m;i++){
        temp[i]=arr[row][i];
    }
    iter_up(dir,row);
    for(int i=1;i<=m;i++){
        arr[row][i]=temp[i];
    }
    iter_down(dir,row);
}

int main() {
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>cmd.first>>cmd.second;
        if(cmd.second=='L'){
            execute(cmd.first, 'R');
        }else{
            execute(cmd.first, 'L');
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
