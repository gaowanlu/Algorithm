#include<iostream>
using namespace std;
#define SIZE 5//有SIZE个物品
#define LoadingCapacity 10 //装载能力 
int Weight[SIZE+1]={0,2,5,4,2,3};//重量 2,5,4,2,3
int Value[SIZE+1]={0,6,3,5,4,6};//相应物品的价值 6,3,5,4,6
int C[SIZE+1][LoadingCapacity+1];//最大价值数组
int Result[SIZE+1]={0};//记录相应下标物品是否放入购物车 

int get_max(int a,int b){
	int var_return=a>b?a:b;
	return var_return;
}

void init_C(void){
	//初始化最大价值数组
	for(int i=0;i<SIZE+1;i++){//第1列赋值为0 
		C[i][0]=0;
	} 
	for(int i=0;i<LoadingCapacity+1;i++){//第1行赋值为0 
		C[0][i]=0; 
	}	
	//输出Weight Value数组
	cout<<"Weight Array:\n\t";
	for(int i=1;i<SIZE+1;i++){
		cout<<" "<<Weight[i];
	}
	cout<<"\nValue Array:\n\t";
	for(int i=1;i<SIZE+1;i++){
		cout<<" "<<Value[i];
	}
	cout<<"\n";
}

void calculate_C(void){
	//计算C数组
	for(int i=1;i<SIZE+1;i++){
		for(int j=1;j<LoadingCapacity+1;j++){
			if(j<Weight[i]){//当前容量小于当前物品重量，装不下，装前i-1个 
				C[i][j]=C[i-1][j];
			}else{//比较此物品放，与不放是否使得价值最大
				C[i][j]=get_max(C[i-1][j],C[i-1][j-Weight[i]]+Value[i]);
			} 
		}
	}
	cout<<"购物车装入最大价值为: "<<C[SIZE][LoadingCapacity]<<"\n";
}

void print_C(void){
	//输出C数组
	cout<<"C Array:\n";
	for(int i=0;i<SIZE+1;i++){
		cout<<"\t";
		for(int j=0;j<LoadingCapacity+1;j++){
			cout<<" "<<C[i][j];
		}
		cout<<"\n";
	} 
}

void get_result(void){
	int i=SIZE,j=LoadingCapacity;
	for(;i>0;i--){
		if(C[i][j]>C[i-1][j]){
			Result[i]=1;
			j-=Weight[i];
		}else{
			Result[i]=0;
		}
	}
	cout<<"装入物品序号为:\n\t";
	for(int i=1;i<SIZE+1;i++){
		if(Result[i]==1){
			cout<<" "<<i;
		}
	}
	cout<<"\n";
}

int main(void){
	init_C();//初始化最大价值数组
	calculate_C();//计算最大价值数组 
	print_C();//输出C数组 
	get_result();//最优解 
	return 0;
} 
