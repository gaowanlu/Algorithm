/*
最短增广路C++实现
参考资料:《趣学算法》陈小玉 人民邮电出版社
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXNODESIZE=100;//网络最大节点数
const int INF=(1<<30)-1;
int residualNetwork[MAXNODESIZE][MAXNODESIZE];//残余网络
int realFlowNetwork[MAXNODESIZE][MAXNODESIZE];//实流网络
int preArray[MAXNODESIZE];//前驱数组
bool looked[MAXNODESIZE];//访问数组:记录节点是否已经访问过了
int nodeSize,edgeSize;//节点个数与边个数

bool bfs(int snode,int enode);//bfs找可增广路
int EK(int snode,int enode);
//找最短增广路具体算法：对实流网络以及残余网络的操作
void print();//输出实流网络

int main(void){
    int u,v,w;
    //残余网络初始化为0
    memset(residualNetwork,0,sizeof(residualNetwork));
    //实流网络初始化为0
    memset(realFlowNetwork,0,sizeof(realFlowNetwork));
    cout<<"请输入结点个数n与边的数量m: \n";
    cin>>nodeSize>>edgeSize;
    cout<<"请输入两个结点u,v以及u--v的最大容量cap:\n";
    for(int i=1;i<=edgeSize;i++){
        cin>>u>>v>>w;
        residualNetwork[u][v]+=w;
    }
    cout<<"网络的最大流值为: "<<EK(1,nodeSize)<<endl;
    print();//输出实流网络
    return 0;
}
//bfs找可增广路
bool bfs(int snode,int enode){
    //初始化前驱数组
    memset(preArray,-1,sizeof(preArray));
    //初始化访问数组
    memset(looked,false,sizeof(looked));
    queue<int>Queue;
    //源点设为已访问
    looked[snode]=true;
    //源点入队列
    Queue.push(snode);
    while(!Queue.empty()){//如果队列不为空则bfs
        int now=Queue.front();
        Queue.pop();
        for(int i=1;i<=nodeSize;i++){//寻找可增广路
            if(!looked[i]&&residualNetwork[now][i]>0){//now-->i:i没有访问过，且残余网络now-->i还可以增广
                looked[i]=true;//结点i设为已访问
                preArray[i]=now;//记录结点i的前驱结点
                if(i==enode){//到达汇点，找到一条可增广路
                    return true;
                }
                Queue.push(i);//结点i入队列
            }
        }
    }
    return false;//找不到可增广路
}
//找最短增广路具体算法：对实流网络以及残余网络的操作
int EK(int snode,int enode){
    int v,w,d,maxflow;//v--->w  d:可增广路的可增广量  maxflow:最大流量
    maxflow=0;//初始化最大流值
    while(bfs(snode,enode)){//不断更新网络，以达到不再可增广
        v=enode;
        d=INF;
        while(v!=snode){//寻找可增广路的可增量:在可增广路中找最小的边权值
            w=preArray[v];
            if(d>residualNetwork[w][v]){
                d=residualNetwork[w][v];
            }
            v=w;
        }
        maxflow+=d;//将新加的量加到总流量上
        //更新网络
        v=enode;
        while(v!=snode){
            w=preArray[v];
            residualNetwork[w][v]-=d;//残余网络更新
            residualNetwork[v][w]+=d;
            //实流网络更新
            if(realFlowNetwork[v][w]>0){//正常来说是w--->v增广,如果[v][w]>0则代表实际流向为w<---v,增广量为w--->v的增加
                realFlowNetwork[v][w]-=d;
            }else{
                realFlowNetwork[w][v]+=d;
            }
            v=w;
        }
    }
    return maxflow;//返回网络最大流量
}
//输出实流网络
void print(){
    cout<<"实流网络：\n";
    for(int i=1;i<=nodeSize;i++){
        cout<<"       v"<<i;
    }
    cout<<"\n";
    for(int i=1;i<=nodeSize;i++){
        cout<<"v"<<i;
        for(int j=1;j<=nodeSize;j++){
            cout<<"      "<<realFlowNetwork[i][j];
        }
        cout<<"\n";
    }
}
