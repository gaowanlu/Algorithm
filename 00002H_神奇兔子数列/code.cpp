#include<iostream>
#include<cstdlib>
using namespace std;
//斐波那契数列递归算法
//功能求斐波那契数列第n个元素 
int Fib1(int n){ 
	if(n<1){
		return -1;
	}
	if(n==1||n==2){
		return 1;
	}else{
		return Fib1(n-1)+Fib1(n-2);
	}
} 
int* Fib2(int n){
	if(n<1){//判断n是否合法 
		return NULL;
	}	
	//使用动态内存申请表 
	int *list=(int*)malloc(sizeof(int)*(n+1));//申请表长为n+1 下标为0空间不使用
	list[1]=1;
	list[2]=1;
	//开始迭代计算
	int i=3;
	for(i=3;i<=n;i++){
		list[i]=list[i-1]+list[i-2];
	} 
	return list;
}
int Fib3(int n){
	if(n<1){//判断n是否合法 
		return -1;
	}
	if(n==1||n==2){
		return 1;
	}
	int i=1,v1=1,v2=1;
	//迭代的妙处
	for(i=3;i<=n;++i){
		v2=v1+v2;
		v1=v2-v1;
	}
	return v2;
}
int main(int argc,char**argv){
	cout<<Fib1(15)<<endl;
	//我们会发现这样的算法复杂度极大、如果我们计算Fib1(101)估计要计算一年
	//能不能进行时间复杂度上的优化?
	//这样的问题出在我们每计算一次都要从n递归到1，我们并没有记录中间的所记录的斐波那契数
	//我们进行下一步的改进:详情看Fib2函数 
	//使用Fib2
	int *list=Fib2(15);
	if(list){
		cout<<list[15]<<endl;
		free(list);//释放list空间	
	} 
	//可见时间上我们进行了可见的优化，能不能进行再优化?
	//时间复杂度我们优化到了O(n),空间复杂度也为O(n)
	//我们只需要获得数列第n项的和，完全没有必要去记录1~n-1的数列值
	//这样我们就可以将空间复杂度进行优化:请看Fib3()
	cout<<Fib3(15)<<endl;
	cout<<"Change the world and yourself with code. Hold on, hold on.\n";
	return 0;
}
