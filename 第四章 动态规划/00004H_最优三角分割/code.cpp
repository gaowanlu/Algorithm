#include<iostream>
using namespace std;
#define N 1000
int map[N][N];//图的邻接矩阵
int strategy[N][N];//记录i j 中间的最优割点
int m[N][N];//记录i j之间切割的最优权重 

//三角切割 
void convex_triangular_cutting(int n){
	//初始化最优权重与策略矩阵
	for(int i=0;i<n;i++){
		strategy[i][i]=0;
		map[i][i]=0;
	} 
	//从有三个顶点的问题开始，step迭代到解决n个顶点的问题 
	for(int step=2;step<n;step++){ 
		for(int i=1;i<n-step+1;i++){//问题的起顶点 i-1
			int j=i+step-1;//问题终顶点
			//初始m[i][j] 与 最优策略分割顶点
			m[i][j]=m[i+1][j]+map[i-1][i]+map[i][j]+map[i-1][j];
			strategy[i][j]=i;
			//寻找i-1 j之间的最优切割点k
			for(int k=i+1;k<j;k++){
				int temp=m[i][k]+m[k+1][j]+map[i-1][k]+map[k][j]+map[i-1][j];
				if(m[i][j]>temp){
					m[i][j]=temp;//更新最优权重与切割点 
					strategy[i][j]=k;
				}
			}
			
		} 
	}
}
//输出所有弦
void print_result(int i,int j){
	if(i==j){
		return;
	}
	if(strategy[i][j]>i){//i-1 j问题，最优切割点大于i,因为i等于不切割 
		cout<<"  {"<<i-1<<","<<strategy[i][j]<<"}  ";
	}
	if(strategy[i][j]+1<j){//i-1 j问题，最优切割点小于j-1 ，为j-1等于不切割 
		cout<<"  {"<<strategy[i][j]<<","<<j<<"}  ";
	}
	print_result(i,strategy[i][j]);
	print_result(strategy[i][j]+1,j);
} 

int main(int argc,char**argv){
	int n=0;
	cout<<"输入顶点个数\n";
	cin>>n;
	cout<<"依次输入各顶点的连续权值\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	convex_triangular_cutting(n);
	print_result(1,n-1);//打印结果 
	return 0;
}
