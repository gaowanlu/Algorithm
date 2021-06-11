/*Create by Wanlu Gao
* 2021/1/21 
* 实现功能:
* 在此程序中实现的为邻接矩阵存储图Prim最小生成树
*/
#include<iostream>
#include<cstdlib>
using namespace std;
//定义无穷
const int INF=9999; 
//存储图的顶点数 
const int map_dot_num=7;
//初始化邻接矩阵
const int map[map_dot_num][map_dot_num]={
{INF,23,INF,INF,INF,28,36},
{23,INF,20,INF,INF,INF,1},
{INF,20,INF,15,INF,INF,4},
{INF,INF,15,INF,3,INF,9},
{INF,INF,INF,3,INF,17,16},
{28,INF,INF,INF,17,INF,25},
{36,1,4,9,16,25,INF}};

//函数功能：输出邻接矩阵 
void PrintMap(void){
	int i,j;
	cout<<"Map:\n";
	for(i=0;i<map_dot_num;i++){
		cout<<"\t";
		for(j=0;j<map_dot_num;j++){
			if(map[i][j]==INF)
				cout<<" INF";
			else
				cout<<" "<<map[i][j];
		}
		cout<<endl;
	} 
}
int main(int argc,char**argv){
	int i=0,j=0;
	//输出邻接矩阵
	PrintMap();
	//定义集合数组
	int s[map_dot_num]={0};//{0}表示s集合为空集
	//定义起点
	int start=0; 
	//定义lowcost数组
	int lowcost[map_dot_num]={INF};
	//初始化closest数组
	int closest[map_dot_num]={0};
	//首先让起点0加入s集合
	s[start]=1;
	//初始化lowcost数组与closest数组
	for(i=0;i<map_dot_num;i++){
		if(i!=start){
			lowcost[i]=map[i][start];
			closest[i]=start; 
		}else{
			//更新lowcost
			lowcost[i]=0; 
		}
	}
	//使用Prim生成最小树，需要map_dot_num-1选最小边
	for(i=1;i<map_dot_num;i++){
		//在lowcost选一个在v-s，且距离s最小的目标
		int target=start;
		int temp=INF;
		for(j=0;j<map_dot_num;j++){
			if(j!=start&&s[j]==0&&temp>lowcost[j]){
				temp=lowcost[j];
				target=j;
			}
		}
		if(target==start){
			break;//没有找到目标 
		}
		//加入s集合
		s[target]=1;
		//更新lowcost与closest数组
		for(j=0;j<map_dot_num;j++){
			if(j!=start&&s[j]==0&&lowcost[j]>map[target][j]){
				lowcost[j]=map[target][j];
				closest[j]=target;
			}
		} 
	}
	//输出lowcost数组
	cout<<"lowcost[]:\n\t";
	for(i=0;i<map_dot_num;i++){
		cout<<" "<<lowcost[i];
	}
	//输出closest数组
	cout<<"\nclosest[]:\n\t";
	for(i=0;i<map_dot_num;i++){
		cout<<" "<<closest[i];
	}	
	return 0;
}
 
