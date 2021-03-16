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

int main(int argc,char**argv){
    //使用关系矩阵存储关系
    int u,v;//u,v 顶点数与关系数(即边数)
    cout<<"输入人数\n";
    cin>>u;
    cout<<"输入关系数\\n";
    cin>>v;
    //获得邻接矩阵
    int**M=getM(u);
    cout<<"输入关系\n";
    for(int i=0;i<v;i++){
        int u1,u2;
        cin>>u1;
        cin>>u2;
        M[u1][u2]=1;
    }
    cout<<"关系矩阵\n";
    printM(M,u);
    //free(M);
    return 0;
}
