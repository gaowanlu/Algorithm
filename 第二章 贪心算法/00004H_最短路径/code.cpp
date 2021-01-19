//迪科斯彻最短路径算法（单源最短路径）
#include<iostream>
using namespace std;
//顶点个数
const int CITY = 5;
//定义无穷
const int INF = 1000;
//使用二维数组存储邻接矩阵
//在此我们直接在源代码中添加邻接矩阵信息
//为了是弄懂程序流程而非实际问题
int map[CITY][CITY]={
{INF,2,5,INF,INF},
{INF,INF,2,6,INF},
{INF,INF,INF,7,1},
{INF,INF,2,INF,4},
{INF,INF,INF,INF,INF}
};
//dist数组与p前驱数组
int dist[CITY]={0};
int p[CITY]={0}; 
//标志数组(表示顶点是否加入了S战队)
int Flag[CITY]={0}; 

//输出路径 
void FindRoad(int last,int origin){
	if(dist[last]==INF){
		printf("Error not find Road\n");
	}
	if(last==origin){
		printf(" %d ",last);
		return;
	}
	FindRoad(p[last],origin);
	printf(" %d ",last);
}

//主函数 
int main(int argc,char**argv){
	int i,j;
	//输出邻接矩阵 
	printf("map:\n");
	for(i=0;i<CITY;i++){
		for(j=0;j<CITY;j++){
			if(map[i][j]==INF)
				printf(" INF ");
			else
				printf(" %d ",map[i][j]);
		}
		printf("\n");
	}
	//选择源点,选择0为源点
	int origin=0;
	//将源点入S战队
	Flag[origin]=1; 
	//初始化dist数组与前驱数组
	for(i=0;i<CITY;i++){ 
		if(i==origin){//dist数组
			dist[i]=0;
			p[i]=-1;
		}else{
			dist[i]=map[origin][i];
			if(map[origin][i]==INF){
				p[i]=-1;
			}else{
				p[i]=origin;
			}
		}
	}
	//输出dist数组与前驱数组
	printf("dist:\n");
	for(i=0;i<CITY;i++){
		printf(" %d ",dist[i]);
	}
	printf("\np:\n");
	for(i=0;i<CITY;i++){
		printf(" %d ",p[i]);
	}	
	printf("\n");
	//我们要选择n次最小dist
	for(i=0;i<CITY;i++){
		//在集合v-s中找dist最小的
		int temp = INF,t=origin;//t为找到的结果
		for(j=0;j<CITY;j++){
			if(Flag[j]==0&&dist[j]<temp){
				temp=dist[j];
				t=j;
			}
		} 
		if(t==origin){//v-s为空 
			break;
		}
		//更新S战队
		Flag[t]=1;
		//更新dist数组与前驱数组,即借东风
		for(j=0;j<CITY;j++){
			if(Flag[j]==0&&map[t][j]<INF){
				if(dist[j]>dist[t]+map[t][j]){
					dist[j]=dist[t]+map[t][j];
					p[j]=t;
				}
			}
		} 
	} 		
	//输出前驱数组
	printf("最短路径前驱数组为\n");
	for(i=0;i<CITY;i++){
		printf(" %d ",p[i]);
	} 
	printf("\n");
	
	//求最短路径我们可以采用递归或者利用栈的方法
	//FindRoad(4,origin);//第一个参数为终点，第二个参数为源点 
	for(i=0;i<CITY;i++){
		FindRoad(i,origin);
		printf("\n");
	} 
	return 0;
} 
