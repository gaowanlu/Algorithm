/*第一台机器可以连续加工,第二台机器工作的开始时间为第一台机器结束与第二台机器结束的最大值
 * */
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
#define MAX 9999
int n;//存储机器零件的个数
int T1[MAX];
int T2[MAX];
int tempChoose[MAX];
int bestChoose[MAX];
int bestLast;//最优结束时间
int last1,last2;//当前第一台机器结束时间与第二台机器结束时间
void Backtrack(int t);
int main(void){
    cout<<"请输入机器零件的个数\n";
    cin>>n;
    cout<<"请输入每个机器零件需要的第一台机器加工时间与第二台机器加工时间\n";
    for(int i=0;i<n;i++){
        cin>>T1[i];
        cin>>T2[i];
        //初始化默认选择方式
        tempChoose[i]=i;
    }
    bestLast=INF;
    last1=last2=0;
    for(int i=0;i<n;i++){
        bestChoose[i]=0;
    }
    //回溯法求解
    Backtrack(0);
    cout<<"最优加工顺序\n";
    for(int i=0;i<n;i++){
        cout<<bestChoose[i]<<" ";
    }
    cout<<endl;
    cout<<"最优的机器零件加工的时间为\n";
    cout<<bestLast<<endl;
    return 0;
}

//回溯求解最优加工顺序
void Backtrack(int t){
    if(t>=n){
        //更新最优
        for(int i=0;i<n;i++){
            bestChoose[i]=tempChoose[i];
        }
        //更新最优结束时间
        bestLast=last2;//当机器二不用再加工东西时就结束了
        return;//回到上个节点
    }

    //枚举t以后的节点
    for(int i=t;i<n;i++){
        //第一台机器再加工一个零件
        last1+=T1[tempChoose[i]];//更新last1,即使用机器一进行加工
        int temp=last2;
        last2=max(last1,last2)+T2[tempChoose[i]];//更新last2
        if(last2<bestLast){//此时last2小于最优时间则代表,还有可能超过最优解
            swap(tempChoose[t],tempChoose[i]);//确定第t个节点
            Backtrack(t+1);//探索t+1
            swap(tempChoose[t],tempChoose[i]);//取消第t个节点
        }
        last1-=T1[tempChoose[i]];//取消第t个节点机器一需要的时间
        last2=temp;//取消第t个节点机器二需要的时间
    }
}







