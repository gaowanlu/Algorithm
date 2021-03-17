#include<iostream>
#include<cstdlib>
using namespace std;

//初始化邻接矩阵
int** getM(int n){
    int** M=(int**)malloc(sizeof(int*)*(n));
    for(int i=0;i<n;i++){
        M[i]=(int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M[i][j]=M[i][j]=0;
        }
    }
    //输入关系个数
    int edge=0;
    cout<<"输入关系个数(边个数)\n";
    cin>>edge;
    cout<<"输入边信息\n";
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;//输入边
        M[u][v]=M[v][u]=1;
    }
    return M;
}

//检测前t-1个节点与第t个节点相连的节点的颜色与t选择的是否有一样的
bool Judge(int t,int**M,int*n,int*choose){
    for(int i=0;i<=t-1;i++){
        if(M[t][i]){
            if(choose[i]==choose[t]){
                return false;
            }
        }
    }
    return true;//t选择的与前t-1与t相连的颜色都不同
}


//递归回溯
void Backtrack(int t,int**M,int *m,int* n,int* sum,int*choose){
    //判断是否到达叶子节点找到一个解决方案
    if(t>=*n){
        *sum=(*sum)+1;
        cout<<"第"<<*sum<<"种方案\n";
        //输出方案
        for(int i=0;i<*n;i++){
            cout<<choose[i]<<"\t";
        }
        cout<<endl;
    }else{
        //依次尝试每种颜色进行递归
        for(int i=0;i<*m;i++){
            choose[t]=i;
            if(Judge(t,M,n,choose)){//第t个节点可以选择第i种颜色
                //递归t+1个节点
                Backtrack(t+1,M,m,n,sum,choose);
            }
        }
    }
}


int main(int argc,char**argv){
    int n=0;//结点数
    cout<<"输入节点数\n";
    cin>>n;
    cout<<"节点数:"<<n<<"\n";
    cout<<"输入颜色数量\n";
    int m=0;
    cin>>m;
    cout<<"颜色数量:"<<m<<"\n";
    //建立无向图的邻接矩阵
    int**M=getM(n);
    //递归回溯解决方案
    int sum=0;//共有sum种解决方案
    int* choose=(int*)malloc(sizeof(int)*n);
    Backtrack(0,M,&m,&n,&sum,choose);
    //释放内存
    free(choose);
    for(int i=0;i<n;i++){
        free(M[i]);
    }
    free(M);
    return 0;
}
