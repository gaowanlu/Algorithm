/*
最短可增广路:重贴标签算法Isap
算法设计:
1、确定合适数据结构，采用邻接表存储网络。
2、对网络结点贴标签，即标高操作。
3、对源点的高度>=结点数，则转向第(6)步，否则从源点开始，沿着高度h(u)=h(v)+1且有可行邻接边(cap>flow)
的方向前进，如果到达汇点，则转向第(4)步；如果无法行进，则转向第(5)步。
4、增流操作：沿着找到的可增广路同向边增流，反向边剑流。注意：在原网络上操作。
5、重贴标签：如果拥有当前结点高度的结点只有一个，则转向第(6)步；令当前结点的高度=所有邻接点高度的最小值+1，如果没有可行邻接边，
则令当前结点的高度=结点数；退回一步；转向第（3）步。
6、算法结束：已找到最大流。
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=0x3fffffff;
const int N=100;
const int M=10000;
int top;
int h[N],pre[N],g[N];
//h[]记录各结点的高度
//g[]记录距离h[]的结点的个数,g[3]记录h为3的结点个数        E[i]
//pre[]记录结点的前驱边，根据pre可以倒推可增广路径pre[v]=i ----->v
//邻接表头结点
struct Vertex{
    int first;
}V[N];
struct Edge{
    int v,next;
    int cap,flow;
}E[M];
void init(){

}
void add_edge(int u,int v,int c){//添加单条边

}
void add(int u,int v,int c){//添加正负两边

}
void set_h(){//标高函数

}
int Isap(int s,int t,int n){//isap增广算法

}
void printg(int n){//输出邻接表

}
void printflow(){//输出实流边

}
int main(void){
     
}



