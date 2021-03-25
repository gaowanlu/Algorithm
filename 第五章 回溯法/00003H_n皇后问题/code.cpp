#include<iostream>
#include<cmath>
using namespace std;
int resultCount=0;//记录解的个数
int n=0;//皇后个数
int result[1000]={0};
bool Place(int t){
    bool re=true;
    //判断与前面的t-1个皇后位置是否冲突
    for(int i=0;i<t;i++){
        if(result[t]==result[i]||t-i==fabs(result[t]-result[i])){
            re=false;
            break;
        }
    }
    return re;
}

void Backtrack(int t){
    if(t>=n){
        resultCount++;
        //打印解
        for(int i=0;i<n;i++){
            cout<<result[i]<<"  ";
        }
        cout<<endl;
        cout<<"_______\n";
    }else{
        //求第t个皇后的可能行的位置
        for(int i=0;i<n;i++){
            result[t]=i;
            if(Place(t)){
                Backtrack(t+1);
            }
        }
    }

}


int main(void)  {
    cout<<"输入皇后个数n\n";
    cin>>n;
    Backtrack(0);
    cout<<"解的个数:"<<resultCount<<endl;
    return 0;
}
