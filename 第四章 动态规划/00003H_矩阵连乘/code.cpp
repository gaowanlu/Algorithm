//问题:矩阵连乘
//日期:2021/2/1
//编码:高万禄
#include<iostream>
using namespace std;
#define N 1000//最多N-1个矩阵
int matrix_data[N];
int mul_num[N][N],strategy[N][N];
//发现策略信息
void matrix_mul(int&matrix_num){
	//置空信息矩阵
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			mul_num[i][j]=0;
			strategy[i][j]=0;
		}
	}
	for(int step=2;step<=matrix_num;step++){//求解不同不同规模子问题
		 for(int i=1;i<=matrix_num-step+1;i++){//矩阵起点 
		 	int j=i+step-1;//矩阵终点
			//初始化解决方案，迭代求最优括号位置
			mul_num[i][j]=mul_num[i+1][j]+matrix_data[i-1]*matrix_data[i]*matrix_data[j];
			strategy[i][j]=i;
			//向后迭代试探的右括号位置
			for(int k=i+1;k<j;k++){
				int temp_mul=mul_num[i][k]+mul_num[k+1][j]+matrix_data[i-1]*matrix_data[k]*matrix_data[j];
				if(temp_mul<mul_num[i][j]){
					mul_num[i][j]=temp_mul;
					strategy[i][j]=k;
				}
			} 
		 }
		
	}
} 
//打印策略
void print_result(int i,int j){
	if(i==j){
		cout<<"M["<<i<<"]";
		return;
	}
	cout<<"(";
	print_result(i,strategy[i][j]);
	cout<<"*";
	print_result(strategy[i][j]+1,j);
	cout<<")";
} 
int main(int argc,char**argv){
	cout<<"矩阵个数:\n";
	int matrix_num=0;
	cin>>matrix_num;
	cout<<"矩阵的行数与最后一个矩阵的列数:\n";
	for(int i=0;i<=matrix_num;i++){
		cin>>matrix_data[i];
	} 
	//策略信息发现matrix_mul
	matrix_mul(matrix_num);
	//打印策略
	print_result(1,matrix_num); 
	return 0;
} 
