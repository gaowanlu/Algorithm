/*
名称:01背包回溯法求解
编码:高万禄
日期:2021/3/15 
*/ 
#include<iostream>
#include<cstdlib>
/*测试样例 
存储物品个数
4
购物车容量      10
依次输入物品重量W[]     2 5 4 2
依次输入物品价值V[]     6 3 5 4
W[]--V[]:       2--6    5--3    4--5    2--4
选中的物品序号为:       0       2       3
*/

using namespace std;
float nowWeight=0.0f;//当前载重
float nowPrice=0.0f;//当前装入的价值
float bestPrice=0.0f;//最优解价值
float sumWeight=0.0;//统计所有物品重量
float sumPrice=0.0;//统计所有物品总价值

float bound(float*V,int i,int N){
	float temp=0.0f;
	for(;i<N;i++){
		temp+=V[i];
	}
	return nowPrice+temp;
} 


//回溯法求解
//搜索空间，t代表现在的扩展在第t层 
void backTrack(float*W,float*V,int N,float M,int *bestChoose,int*tempChoose,int t){
	//判断是否到达了叶子节点
	if(t>=N){
		//保存当前最优解
		for(int i=0;i<N;i++){
			bestChoose[i]=tempChoose[i];
		}
		bestPrice=nowPrice;
		return;
	}
	//是否满足条件搜索左子树
	if(nowWeight+W[t]<=M){
		tempChoose[t]=1;
		nowWeight+=W[t];
		nowPrice+=V[t];
		backTrack(W,V,N,M,bestChoose,tempChoose,t+1);//探索完左子树后 
		nowWeight-=W[t];//回溯 
		nowPrice-=V[t];
	}
	//是否满足条件搜索右子树
	if(bound(V,t+1,N)>bestPrice){
		tempChoose[t]=0;
		//探索右子树
		backTrack(W,V,N,M,bestChoose,tempChoose,t+1); 
	} 
}

//返回bool数组 
int* knapsack(float*W,float*V,int N,float M){
	//求和
	for(int i=0;i<N;i++){
		sumWeight+=W[i];
		sumPrice+=V[i];
	} 
	//判断是否可以将全部物品放入购物车
	if(sumWeight<=M){
		bestPrice=sumPrice;
		cout<<"将所有物品放入购物车\n";
		return NULL;
	}
	//记录相应下标物品是否放入购物车
	int *bestChoose=(int*)malloc(sizeof(int)*N);
	//临时存储，相应下标物品是否放入购物车
	int *tempChoose=(int*)malloc(sizeof(int)*N); 
	//回溯法求解
	backTrack(W,V,N,M,bestChoose,tempChoose,0);
	free(tempChoose);
	return bestChoose;
}

//主函数 
int main(int argc,char**argv){
	int N;//存储物品的个数
	cout<<"存储物品个数\t";
	cin>>N;
	float M;
	cout<<"购物车容量\t";
	cin>>M;
	float *W=(float*)malloc(sizeof(float)*(N));
	float *V=(float*)malloc(sizeof(float)*(N));
	cout<<"依次输入物品重量W[]\t";
	for(int i=0;i<N;i++){
		cin>>W[i];
	}
	cout<<"依次输入物品价值V[]\t";
	for(int i=0;i<N;i++){
		cin>>V[i];
	}
	//输入验证
	cout<<"W[]--V[]:\t";
	for(int i=0;i<N;i++){
		cout<<W[i]<<"--"<<V[i]<<"\t";
	} 
	cout<<"\n";
	int* result=knapsack(W,V,N,M);
	free(W);free(V);
	cout<<"选中的物品序号为:\t"; 
	for(int i=0;i<N;i++){
		if(result[i]==1)
	    	cout<<i<<"\t";
	}
	cout<<"\n";
	free(result);
	return 0;
} 
