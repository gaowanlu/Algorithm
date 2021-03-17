/*
算法：最大团问题
日期:2021/3/17
编码:高万禄
*/
#include<iostream>
#include<cstdlib>
using namespace std;

//申请大小为n*n得二维数组，并将值初始化为0
int** getM(int n){
    int **M=(int**)malloc(sizeof(int*)*(n));
    for(int i=0;i<n;i++){
        M[i]=(int*)malloc(sizeof(int)*(n));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M[i][j]=0;
        }
    }
    return M;
}
//释放申请的矩阵空间
void freeM(int**M,int n){
    for(int i=0;i<n;i++){
        free(M[i]);
    }
    free(M);
}

//打印M
void printM(int**M,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
    }
}


//判断第t个人是否与前面的t-1中选中的每个人都有关系，都有关系则返回true否则返回false
bool Judge(int**M,int u,int t,bool* tempChoose){
    bool return_bool=true;
    for(int i=0;i<t;i++){
        if(tempChoose[i]&&M[t][i]==0){//前t-1个被选中的且与t没有友好关系
            return_bool=false;
            break;
        }
    }
    return return_bool;
}

//递归回溯求解
void Backtrack(int t,int**M,int u,bool*bestChoose,int*bestCount,bool *tempChoose,int*tempCount){
	//判断是否到达叶子节点
    if(t>=u){//到达叶子，更新最优解
        for(int i=0;i<u;i++){
            bestChoose[i]=tempChoose[i];
        }
        //更新最优团人数
        *bestCount=*tempCount;
        return;//回溯
    }
    //判断是否满足探索左子树条件
    if(Judge(M,u,t,tempChoose)){//满足条件则探索左子树
        //可选择t入团
        tempChoose[t]=true;
        *tempCount=(*tempCount)+1;
        //递归探索t+1
        Backtrack(t+1,M,u,bestChoose,bestCount,tempChoose,tempCount);
        //回溯,即从t+1回到t
        *tempCount=(*tempCount)-1;
    }
    //判断是否满足探索右子树条件
    if((*tempCount)+u-t>*bestCount){//如果这个节点跳过去，是否有潜在可能构造更优解
        tempChoose[t]=false;
        Backtrack(t+1,M,u,bestChoose,bestCount,tempChoose,tempCount);
    }
}
int main(int argc,char**argv){
    //使用关系矩阵存储关系
    int u,v;//u,v 顶点数与关系数(即边数)
    cout<<"input people count\n";
    cin>>u;
    cout<<"relation count\n";
    cin>>v;
    //获得邻接矩阵
    int**M=getM(u);
    cout<<"input relation\n";
    for(int i=0;i<v;i++){
        int u1,u2;
        cin>>u1>>u2;
        M[u2][u1]=M[u1][u2]=1;
    }
    cout<<"relation map\n";
    printM(M,u);
    //存储是否选中相应下标的人（最优）
    bool*bestChoose=(bool*)malloc(sizeof(bool)*u);
    //临时存储是否选中相应下标的人（对bestChoose更新）
    bool*tempChoose=(bool*)malloc(sizeof(bool)*u);
    //初始化选择数组
    for(int i=0;i<u;i++){
        bestChoose[i]=false;
    }
    //存储最优团人数
    int bestCount=0;
    //临时存储最优团人数
    int tempCount=0;
    //回溯法求解
    Backtrack(0,M,u,bestChoose,&bestCount,tempChoose,&tempCount);
    //输出最大团
    cout<<"Best Choose\n";
    for(int i=0;i<u;i++){
        if(bestChoose[i]==true){
            cout<<i<<"\t";
        }
    }
    cout<<endl;
    cout<<"BestCount\n";
    cout<<bestCount<<endl;
    //释放内存
    free(M);
    free(bestChoose);
    free(tempChoose);
    return 0;
}
