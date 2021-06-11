/*
二分图:又称作二部图,设G=(V,E)是一个无向图，
如果结点集V可分割为两个互不相交的子集(V1,V2),
并且图中的每条边(i,j)所关联的两个结点i和j分别属于这两个不同的结点集(i<-V1,j<-V2)
匹配：在图论中，一个匹配是一个边的集合，其中任意两条边都没有公共结点。
最大匹配：一个图所有匹配中，边数最多的匹配，称为这个图的最大匹配。

V1          V2  边 1--6   
1           5      1--7
                   2--5
2           6      3--7
                   4--5
3          
            7
4
配对网络，增加源点s->v1[i]，与汇点v2[j]->t
*/

/*配对网络算法
(1) 构建网络：根据输入的数据，增加源点汇点，每条边的容量设为1、创建混合网络
(2) 求网络最大流
(3) 输出最大流值就是最大匹配对数
(4) 搜索V1结点的邻接表，流量为1的边对应的邻接点就是一个最佳配对方案
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=0x3ffffffff;
const int N=100;
const int M=10000;
int top;//V1 V2结点集总共的结点数量
int h[N],pre[N],graph[N];
//邻接表相关数据结构
struct Vertex{
    int first;
}V[N];
struct Edge{
    int v,next;
    int cap,flow;
}E[M];


void init();//初始化
void add(int u,int v,int c);
void add_edge(int u,int v,int c);
void printGraph(int n);//输出邻接表
int Isap(int s,int t,int n);//匹配算法
void set_h(int t,int n);

int main(void){
    int n,m,total;
    int u,v;
    cout<<"请输入女员工人数m和男员工人数n: \n";
    cin>>m>>n;
    //初始化
    init();
    total=m+n;//V1 V2总共的结点数量
    //初始化网络
    for(int i=1;i<=m;i++){
        //源点到V1结点集中的点
        add(0,i,1);
    }
    //V2结点集中的结点到汇点
    for(int i=m+1;i<=total;i++){
        add(i,total+1,1);
    }
    cout<<"输入可以配和的V1与V2结点可组合的对,u--v,当u=-1且v=-1时结束输入\n";
    while(cin>>u>>v,u+v!=-2){
        add(u,v,1);
    }
    //输出邻接表
    printGraph(total+2);
    cout<<"最大匹配对数: "<<Isap(0,total+1,total+2)<<endl;
    //输出邻接表
    printGraph(total+2);
    //输出匹配方案
    printFlow(m);
    return 0;
}

//初始化
void init(){
    memset(V,-1,sizeof(V));//初始化每个结点的first为-1，初始化邻接表
    top=0;//边列表递增序号
}

//添加网络边
void add(int u,int v,int c){
    add_edge(u,v,c);
    add_edge(v,u,0);
}
void add_edge(int u,int v,int c){
    E[top].v=v;//邻接表插入新节点，头插法
    E[top].cap=c;
    E[top].flow=0;
    E[top].next=V[u].first;
    V[u].first=top++;
}

//输出邻接表
void printGraph(int n){
    cout<<"网络邻接表:\n";
    for(int i=0;i<=n;i++){
        cout<<"v"<<i<<" ["<<V[i].first;
        for(int j=V[i].first;~j;j=E[j].next){
            cout<<"]--["<<E[j].v<<"  "<<E[j].cap<<"  "<<E[j].flow<<" "<<E[j].next;
        }
        cout<<"]\n";
    }
}

//匹配算法
int Isap(int s,int t,int n){
    set_h(t,n);
}

void set_h(int t,int n){
    
}