#include<iostream>
using namespace std;
//函数功能：冒泡排序 
void BubbleSort(int*list,int n){
	int i=0,j=0;
	bool flag=0;
	for(i=0;i<n;++i){
		flag=0;
		for(j=0;j<n-i-1;++j){
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
	int weight[8]={4,10,7,11,3,5,14,2};//古董清单 
	//我们需要在古董清单每次贪心选择都选择最轻的
	//则我们将其进行非递减排序比较好
	//在此为了写排序比较方面、使用冒泡排序	
	BubbleSort(weight,8);
	//排序输出验证
	int i;
	cout<<"weight:\n";
	for(i=0;i<8;i++){
		cout<<"\t"<<weight[i]<<endl;
	}
	int max=0,sum=0;
	cout<<"请你输入船的限重:";
	cin>>max;
	//开始进行贪心选择
	cout<<"您可以带走重量序列为:\n";
	for(i=0;i<8;i++){
		if(sum+weight[i]<=max){
			cout<<"\t"<<weight[i]<<endl;
			sum+=weight[i];
		}else{
			break;
		}
	} 
	cout<<"带走的总重量为:\n";
	cout<<"\t"<<sum<<endl;
	return 0;
}


