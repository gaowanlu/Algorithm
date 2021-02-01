#include<iostream>
#include<cstdlib>
using namespace std;
#define N 1000
int price_map[N][N];//价格表
int real_price[N][N];//最优价格
int strategy[N][N];//策略选择
//打印解决方案 
void print(int i,int j){
	if(strategy[i][j]==0){
		cout<<"--"<<j;//i-->j 不同停靠则直接到j
		return; 
	}
	print(i,strategy[i][j]);
	print(strategy[i][j],j);
} 
void solve(int&n,int&start,int&end){//共有n个站点 
	for(int step=3;step<=n;step++){//将问题分解为大小为d的小问题 
		//解决全部小问题
		for(int i=1;i<=n-step+1;i++){//问题的起点
			int j=i+step-1;//问题终点 
			//试探全部停靠站
			for(int k=i+1;k<j;k++){
				int trial=real_price[i][k]+real_price[k][j];
				if(trial<real_price[i][j]){//中间停靠比较省钱 
					real_price[i][j]=trial;
					strategy[i][j]=k;//记录从 i到 j的中间停靠点 
				} 
			}
		} 
	}
	//打印解决方案
	cout<<start;
	print(start,end); 
	cout<<"\n花费:  "<<real_price[start][end]<<endl;
}
int main(int argc,char**argv){
	cout<<"输入站点个数\n";
	int number_of_sites=0;
	cin>>number_of_sites;
	//输入价格表
	cout<<"输入价格表\n";
	for(int i=1;i<=number_of_sites;i++){
		for(int j=i+1;j<=number_of_sites;j++){
			cin>>price_map[i][j];
			//初始化real_price为price_map
			real_price[i][j]=price_map[i][j]; 
		}
	}
	cout<<"寻找解决方案中...\n"; 
	int start=1,end=6;
	solve(number_of_sites,start,end);
	return 0;
}
