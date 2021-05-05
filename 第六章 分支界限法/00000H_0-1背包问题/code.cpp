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

int main(void){

    return 0;
}
