#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;

const int N=100;//物品最大数量
bool bestChoose[N];//辅助空间记录最优解

//定义结点数据结构
struct Node{
    int cp,rp;//cp为包内价值,rp为剩余物品的总价值
    int rw;//背包剩余容量
    int id;//物品号
    bool x[N];//当前节点解向量
    Node(){
        memset(x,0,sizeof(x));//初始化x
    }
    Node(int _cp,int _rp,int _rw,int _id){
        cp=_cp;
        rp=_rp;
        rw=_rw;
        id=_id;
    }
};

//物品数据结构
struct Goods{
    int value;
    int weight;
}goods[N];

int bestValue;//最优解总价值
int MaxWeight;//背包最大重量
int n;//物品个数
int sumWeight;//物品总重量
int sumValue;//物品总价值


//广度优先搜索求解
int bfs();

int main(void){
    //输入物品个数
    std::cout<<"请输入物品的个数\n";
    std::cin>>n;
    if(n>N){
        std::cout<<"n过大\n";
        return -1;
    }
    //输入背包的容量
    std::cout<<"请输入背包的最大容量\n";
    std::cin>>MaxWeight;
    std::cout<<"请依次输入每个物品的重量w和价值v，用空格分开\n";
    bestValue=0;//初始化最优价值
    sumWeight=0;//所有物品的总重量与总价值
    sumValue=0;
    for(int i=0;i<n;i++){
        std::cin>>goods[i].weight>>goods[i].value;//输入第i个物品的重量与价值
        //迭代求和
        sumWeight+=goods[i].weight;
        sumValue+=goods[i].value;
    }
    //判断背包是否可以装下所有物品
    if(sumWeight<=MaxWeight){
        bestValue=sumValue;
        std::cout<<"放入购物车的物品的最大价值为"<<bestValue<<std::endl;
        std::cout<<"将所有物品放入购物车.\n";
        return 0;
    }
    //广度优先搜索
    bfs();
    std::cout<<"放入背包的物品的最大价值为"<<bestValue<<std::endl;
    std::cout<<"放入背包的物品的序号为: ";
    //输出序号
    for(int i=0;i<n;i++){
        if(bestChoose[i]){
            std::cout<<i<<"  ";
        }
    }
    std::cout<<"\n";
    return 0;
}

//广度优先搜索子集树
int bfs(){
    int t,tcp,trp,trw;
    //当前层数t,当前节点背包价值,当前节点后面的价值,背包剩余容量
    
    //新建队列
    queue<Node> Queue;
    //压入一个新节点
    Queue.push(Node(0,sumValue,MaxWeight,0));
    //现在背包价值为0,剩余价值为sumValue,背包剩余容量为MaxWeight,当前层数为0

    //广度优先搜索
    while(!Queue.empty()){
        //创建三个此时节点,左孩子，右孩子
        Node parent,lchild,rchild;
        //取出队列的头元素取出作为父节点即扩展节点
        parent=Queue.front();
        Queue.pop();
        //当前处理节点的层数,即处理的为第几个物品
        t=parent.id;

        if(t>n||parent.rw==0){//parent为叶子 或者 当前节点的背包剩余容量为0
            //判断是否为更优解
            if(parent.cp>=bestValue){
                //迭代最优解
                for(int i=0;i<n;i++){
                    bestChoose[i]=parent.x[i];
                }
                bestValue=parent.cp;
            }
            continue;//不扩展此节点,剪枝
        }

        //判断当前节点是否满足界限 扩展条件
        if(parent.cp+parent.rp<bestValue){//当前节点价值+此节点后面全部价值都小于当前最优解
            continue;
        }

        
        //左右孩子信息
        tcp=parent.cp;
        trp=parent.rp-goods[t].value;//无论t物品是否装入，孩子节点的剩余价值都会减少
        trw=parent.rw;//剩余重量



        //扩展左孩子，即装入t物品
        //左孩子信息,当前节点变为新建左节点
        //判断背包剩余容量是否可以装下t物品
        if(trw>=goods[t].weight){
            lchild.rw=trw-goods[t].weight;
            lchild.cp=tcp+goods[t].value;
            lchild=Node(lchild.cp,trp,lchild.rw,t+1);//创建左结点实例
            //复制以前的解向量
            for(int i=0;i<t;i++){
                lchild.x[i]=parent.x[i];
            }
            lchild.x[t]=true;//选中t物品
            if(lchild.cp>bestValue){
                bestValue=lchild.cp;
            }
            //左孩子入队列
            Queue.push(lchild);
        }


        //扩展右孩子
        if(tcp+trp>=bestValue){//不装入t还有可能超过最优解
            rchild=Node(tcp,trp,trw,t+1);
            //复制以前的解向量
            for(int i=0;i<t;i++){
                rchild.x[i]=parent.x[i];
            }
            rchild.x[t]=false;//不装入t节点
            //右孩子入队列
            Queue.push(rchild);
        }
    }

    //返回最优价值
    return bestValue;
}


