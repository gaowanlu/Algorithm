#include<iostream>
using namespace std;
/*冒泡排序是一种贪心算法策略
每次总大问题中选择一个局部最优解
然后问题规模进一步减小
解决子问题的方法和上一次解决问题方法是一样的
*/ 
void function(int*list,int n){
	int i=0,j=0;
	bool flag=0;
	for(i=0;i<n;++i){
		flag=0;
		for(int j=0;j<n-i-1;j++){
			if(list[j]>list[j+1]){
				flag=1;
				int temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
		}
		if(!flag){
			break;
		}
	} 
}
int main(int argc,char**argv){
	int list[10]={2,4,6,5,3,1,9,7,8,0};
	//将list进行冒泡排序 
	function(list,10);
	int i=0;
	cout<<"list:\n";
	for(i;i<10;++i){
		cout<<"\t"<<list[i]<<endl;
	}
	return 0;
}
