#include<iostream>
using namespace std;
#define N 1000
#define INF 99999//无穷 
int stones[N];//存储每堆石子数量 
int Min[N][N],Max[N][N];
int sum[N];//计算1 - i堆的石子和 
//公路玩法 
void highway(int n){
	//初始化Min Max矩阵
	for(int i=1;i<=n;i++){
		Min[i][i]=0;
		Max[i][i]=0;
	}
	//初始sum数组
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+stones[i];
	} 
	for(int step=2;step<=n;step++){//问题规模从2堆石子开始解决 
		for(int i=1;i<=n-step+1;i++){//起点 
			int j=i+step-1;//终点
			//初始化min[i][j] max[i][j] 
			Min[i][j]=INF;
			Max[i][j]=-1;
			int temp=sum[j]-sum[i-1];//获得从 i堆到j堆，石子总数,即解决i j大问题花费 
			//将i j问题以k划分为两大堆，选出最优与最差的划分两大堆方案 
			for(int k=i;k<j;k++){
				if(Min[i][j]>Min[i][k]+Min[k+1][j]+temp){
					Min[i][j]=Min[i][k]+Min[k+1][j]+temp;
				}
				if(Max[i][j]<Max[i][k]+Max[k+1][j]+temp){
					Max[i][j]=Max[i][k]+Max[k+1][j]+temp;
				}
			} 
		}
	}
	
}
//操场玩法
void playground(int n){
	//将操场环形转换为直线型
	for(int i=1;i<=n-1;i++){
		stones[n+i]=stones[i];
	} 
	n=2*n-1;
	//直线求解
	highway(n);
	n=(n+1)/2;
	int temp_min=Min[1][n];
	int temp_max=Max[1][n];
	//选出最大最小的
	/*
	1 2 3 4
	1 2 3 4 1 2 3
	state:
	1 2 3 4
	2 3 4 1
	3 4 1 2
	4 1 2 3
	*/
	for(int i=2;i<=n;i++){ 
		if(Min[i][n+i-1]<temp_min){
			temp_min=Min[i][n+i-1];
		}
		if(Max[i][n+i-1]>temp_max){
			temp_max=Max[i][n+i-1];
		}
	}
	cout<<"操场玩法\n";
	cout<<"Min "<<temp_min<<endl;
	cout<<"Max "<<temp_max<<endl; 
}
int main(int argc,char**argv){
	int n;
	cout<<"输入石子的堆数\n";
	cin>>n;
	cout<<"输入各堆的石子数量\n";
	for(int i=1;i<=n;i++){
		cin>>stones[i];
	}
	//公路玩法 
	highway(n);
	cout<<"公路玩法\n";
	cout<<"Min "<<Min[1][n]<<endl;
	cout<<"Max "<<Max[1][n]<<endl;
	//操场玩法
	playground(n);
	return 0;
} 
