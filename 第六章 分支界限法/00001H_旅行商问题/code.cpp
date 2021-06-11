#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int INF=1e7;//正无穷
const int N=100;//最大地点容量
double graph[N][N];//地点邻接矩阵
int bestRoad[N];//最优路径
double bestlong;//最优路径长度
int n,m;

//排列树节点
struct Node{
    double nowlong;//走过的长度
    int index;//正在寻找第几个景点
    int road[N];//路径
    Node(){

    }
    Node(double _nowlong,int _index){
        nowlong=_nowlong;
        index=_index;//排列树层数
    }
};

//定义优先队列优先级:nowlong越小越优先
bool operator < (const Node&a,const Node&b){
    return a.nowlong>b.nowlong;
}


void init();//初始化
double bfs();//优先队列bfs
void print();//打印解


//主函数
int main(void){
    int u,v,w;//u---v u,v为地点 w为二者之间的距离
    cout<<"请输入景点的个数(即无向图节点个数)\n";
    cin>>n;
    init();//初始化
    cout<<"请输入景点之间的边数\n";
    cin>>m;
    cout<<"请依次输入u v w,u:顶点 v:顶点 w:v--v距离\n";
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        graph[u][v]=graph[v][u]=w;
    }
    //广度优先求最优
    bfs();
    //输出最优解
    print();
    return 0;
}

//初始化
void init(){
    //初始化最优路径长度：正无穷，因为要迭代求最优
    bestlong=INF;
    //初始化解向量
    for(int i=0;i<=n;i++){
        bestRoad[i]=0;
    }
    //初始化邻接矩阵
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            graph[i][j]=graph[j][i]=INF;//默认任意两点不可达
        }
    }
}

//打印解
void print(){
    cout<<"最优路径:";
    for(int i=1;i<=n;i++){
        cout<<bestRoad[i]<<"--->";
    }
    cout<<1<<endl;
    cout<<"最优路径长度:"<<bestlong<<endl;
}


//排列树
/*
 *                  *(node 0)
 *                  |1
 *                  *(根节点)
 *          |2      |3       |4
 *          *       *        *
 *       |3    |4 |2  |4   |2  |3
 *       *     *  *   *    *   *
 *       |4    |3 |4  |2   |3  |2
 *       *     *  *   *    *   *
 * */

//优先队列 bfs:默认从景点1出发
double bfs(){
    //当前所在排列树的层数
    int nowStep;
    Node liveNode;//当前扩展节点
    Node newNode;//生成新节点
    //创建优先队列
    priority_queue<Node> nodeQueue;
    //创建根节点
    newNode=Node(0,2);
    for(int i=1;i<=n;i++){//初始化根节点的解向量
        newNode.road[i]=i;
    }
    //根节点加入队列
    nodeQueue.push(newNode);

    while(!nodeQueue.empty()){
        liveNode=nodeQueue.top();//最队头作为扩展节点
        nodeQueue.pop();
        nowStep=liveNode.index;//当前处理景区序号:开始时nowStep=2 因为第1层默认选景点1，直接跳过起点
        if(nowStep==n){//到达了排列树倒数第二层时
            //判断是不是解，是不是更优解
            //判断当前节点到对应的叶子节点之间是否有路径 判断叶子节点到根节点是否有路径(因为要旅游一圈回到起点)
            if(graph[liveNode.road[n-1]][liveNode.road[n]]!=INF&&graph[liveNode.road[n]][1]!=INF){
                //判断是否是更优解
                if(liveNode.nowlong+graph[liveNode.road[n-1]][liveNode.road[n]]+graph[liveNode.road[n]][1]<bestlong){
                    //迭代最优解长度
                    bestlong=liveNode.nowlong+graph[liveNode.road[n-1]][liveNode.road[n]]+graph[liveNode.road[n]][1];
                    //记录最优解的解向量
                    for(int i=1;i<=n;i++){
                        bestRoad[i]=liveNode.road[i];
                    }
                }
                continue;//结束队当前扩展节点的操作，是倒数第二层节点不用将叶子节点在入队列了，没必要
            } 
        }

        //判断是否满足扩展界限条件
        //不扩展
        if(liveNode.nowlong>=bestlong){//此方案，从起点到当前扩展节点的距离已经没有最优解优了
            continue;
        }
        //扩展
        //生成扩展节点的所有分支
        for(int j=nowStep;j<=n;j++){
            //如果扩展节点与分支节点之间有路径
            if(graph[liveNode.road[nowStep-1]][liveNode.road[nowStep]]!=INF){
                double templong=liveNode.nowlong+graph[liveNode.road[nowStep-1]][liveNode.road[j]];
                if(templong<bestlong){//界限条件
                    newNode=Node(templong,nowStep+1);
                    for(int i=1;i<=n;i++){//复制以前的解向量
                        newNode.road[i]=liveNode.road[i];
                    }
                    swap(newNode.road[nowStep],newNode.road[j]);//交换road[nowStep]与road[j]
                    //新节点入队列
                    nodeQueue.push(newNode);
                }
            }
        }
    }
    return bestlong;
}
