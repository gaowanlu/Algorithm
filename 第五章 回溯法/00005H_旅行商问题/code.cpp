//回溯法 旅行商问题
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int INF=1e7;//正无穷
int n;//节点个数
int m;//边的个数
int**matrix;//邻接矩阵
int*x;//当前路径
int*bestx;//最优路径
int cl;//当前路径长度
int bestl;//最优路径长度
void init(int n){
    //申请邻接矩阵空间
    matrix=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++)
        matrix[i]=(int*)malloc(sizeof(int)*n);
    //初始化邻接矩阵
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j]=matrix[j][i]=INF;//初始化不可达
        }
    }
    bestl=INF;
    cl=0;
    //申请当前路径存储空间
    x=(int*)malloc(sizeof(int)*n);
    //申请最优路径长度
    bestx=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        x[i]=i;
        bestx[i]=-1;//初始化无解
    }
}

void Traveling(int t){
    if(t>=n){//到达叶子节点
        //从末尾节点最优路径长度+末尾->起点<bestl 则是一个更优解
        if(matrix[x[n-1]][0]!=INF&&(cl+matrix[x[n-1]][0])<bestl){
            //更新路径最优解
            for(int j=0;j<n;j++){
                bestx[j]=x[j];
            }
            //更新最优路径长度
            bestl+=cl+matrix[x[n-1]][0];
        }
    }else{//没有到达叶子节点
        //逐个试探t层节点的孩子节点
        for(int j=t;j<n;j++){
            //t-1 层的节点 与 t 层的相连且有可能取得更优路线,否则进行界限剪枝处理
            if(matrix[x[t-1]][x[j]]!=INF&&(cl+matrix[x[t-1]][x[j]])<bestl){
                swap(x[t],x[j]);
                cl+=matrix[x[t-1]][x[t]];
                Traveling(t+1);
                cl-=matrix[x[t-1]][x[t]];
                swap(x[t],x[j]);
            }
        }
    }
}

int main(void){
    cout<<"请输入节点的个数"<<endl;
    cin>>n;
    cout<<"请输入边的个数"<<endl;
    cin>>m;
    init(n);//初始化邻接矩阵
    cout<<"输入两个节点的距离"<<endl;
    int v1,v2,w;
    for(int i=0;i<m;i++){
        cin>>v1>>v2>>w;
        matrix[v1][v2]=matrix[v2][v1]=w;
    }
    Traveling(1);//从0节点开始走
    for(int i=0;i<n;i++)free(matrix[i]);
    free(matrix);
    for(int i=0;i<n;i++){
        cout<<bestx[i]<<"--";
    }
    cout<<"0";
    free(x);
    free(bestx);
    return 0;
}
