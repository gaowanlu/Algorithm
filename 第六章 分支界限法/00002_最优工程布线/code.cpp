/*分支界限-最优工程布线-bfs
 *
 * a _ *    a-*               可知走四步可以从a到b
 * _ _ _    | |                         上  下  左  右
 * _ _ b    *-*-*                     ---- ---- ---- ----
 *          | | |              ---- 。。。。。。。。。。。。
 *          *-*-b
 *          形成四叉树，每个节点的分支为上下左右四个方向的决策
 *     约束条件:非障碍物或边界且未曾布线
 *     界限条件:最先碰到的一定是距离最短的，因此无界限条件
 *     为什么先搜到的终点路径就是最短路:因为bfs按树层级搜索，先搜到的肯定短
 *     为什么别的路线占了，后来的路线不能占，因为先占的路线，从起点到那个点的路径一定更短
 * */
#include<iostream>
#include<queue>
#include<iomanip>//I/O控制头文件，像C里的格式化输出
using namespace std;
typedef struct{
    int x;
    int y;
}Position;//位置
int graph[100][100];//地图

void init(int m,int n);//初始化
bool findPath(Position s,Position e,Position*&road,int &Len);//bfs

int main(void){
    Position startPoint,endPoint;//起点与终点
    Position *road;//路径
    int Len,m,n;//Len路径长度 m*n大小方阵
    cout<<"请输入方阵大小M行n列：输入格式m n\n";
    cin>>m>>n;
    init(m,n);//初始化
    while(!(m==0&&n==0)){
        cout<<"输入障碍物坐标x,y(输入 0 0 结束)\n";
        cin>>m>>n;
        graph[m][n]=-2;//设置障碍物
    }
    //设置起点
    cout<<"请输入起点\n";
    cin>>startPoint.x>>startPoint.y;
    cout<<"请输入终点\n";
    cin>>endPoint.x>>endPoint.y;
    if(findPath(startPoint,endPoint,road,Len)){
        cout<<"最短路长度为:"<<Len<<endl;
        cout<<"路线为:\n";
        for(int i=0;i<Len;i++){
            cout<<"["<<road[i].x<<","<<road[i].y<<"]  ";
        }
        cout<<endl;
    }else{
        cout<<"没有找到有效路径\n";
    }
    //设置终点
    return 0;
}


//初始化地图，标记>0表示已经布线，未布线-1 墙壁-2
void init(int m,int n){
    //方阵全初始化为-1
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            graph[i][j]=-1;
        }
    }
    //方阵上下围墙
    for(int i=0;i<=n+1;i++){
        graph[0][i]=graph[m+1][i]=-2;
    }
    //方阵左右围墙
    for(int i=0;i<=m+1;i++){
        graph[i][0]=graph[i][n+1]=-2;
    }
    /*
     *-2 -2 -2 -2 -2
     *-2 -1 -1 -1 -2
     *-2 -1 -1 -1 -2
     *-2 -2 -2 -2 -2
     */
}

bool findPath(Position s,Position e,Position*&road,int &Len){
   //检测起点是不是就是终点
    if((s.x==e.x)&&(s.y==e.y)){
        Len=0;
        return true;
    }
    Position DIR[4];//上下左右
    Position here,next;//当前位置与下一个位置
    //初始化DIR
    //   -1  0  1 
    // -1    3
    //  0 2     0
    //  1    1
    DIR[0].x=0;
    DIR[0].y=1;
    DIR[1].x=1;
    DIR[1].y=0;
    DIR[2].x=0;
    DIR[2].y=-1;
    DIR[3].x=-1;
    DIR[3].y=0;
    here=s;
    graph[here.x][here.y]=0;//起点距离为0
    queue<Position>Queue;
    while(1){
        for(int i=0;i<4;i++){//探索当前节点的四个分支
            next.x=here.x+DIR[i].x;
            next.y=here.y+DIR[i].y;
            //检测分支节点是否能布线
            if(graph[next.x][next.y]==-1){//还未布线
                graph[next.x][next.y]=graph[here.x][here.y]+1;
                Queue.push(next);
            }
            if((next.x==e.x)&&(next.y==e.y)){
                //到了终点
                break;
            }
        }
        //到了终点
        if((next.x==e.x)&&(next.y==e.y)){
            break;
        }
        if(Queue.empty()){
            return false;
        }else{
            here=Queue.front();
            Queue.pop();
        }
    }
    //逆着寻找布线方案
    Len=graph[e.x][e.y];
    road=new Position[Len];
    here=e;
    for(int i=Len-1;i>=0;i--){
        road[i]=here;
        for(int j=0;j<4;j++){//右下左上
            next.x=here.x+DIR[j].x;
            next.y=here.y+DIR[j].y;
            if(graph[next.x][next.y]==i){
                break;
            }
        }
        here=next;
    }
    return true;
}
