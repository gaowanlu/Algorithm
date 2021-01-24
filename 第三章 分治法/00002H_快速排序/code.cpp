#include<iostream>
#include<cstdlib>
using namespace std;
struct Data{
	int flag;
};

//快速排序划分函数,返回基准元素最后的下标 
int Partition(struct Data*list,int low,int high){
	struct Data temp;
	int i=low,j=high,p=low;
	while(i<j){
		//从右向左
		while(j>i&&list[j].flag>list[p].flag){
			j--;
		}
		//进行元素交换
		if(j>i){ 
			temp=list[j];
			list[j]=list[i];
			list[i]=temp;
			p=j;
			i++; 
		} 
		//从左向右
		while(j>i&&list[i].flag<=list[p].flag){
			i++;
		} 
		//进行元素交换
		if(j>i){
			temp=list[i];
			list[i]=list[j];
			list[j]=temp;
			p=i;
			j--;
		} 
	} 
	return p;	
}

//快速排序递归函数
void QuickSort(struct Data*list,int low,int high){
	if(low<high){
		//进行划分
		int middle=Partition(list,low,high);
		//左部分快速排序
		QuickSort(list,low,middle-1);
		//右部分快速排序
		QuickSort(list,middle+1,high);	
	}
} 


//优化后的划分函数
//我们不用向左扫描，交换，向右扫描，交换
//我们完全可以向左扫描，向右扫描，然后交换 
int Partition_Pro(struct Data*list,int low,int high){
	struct Data temp;
	struct Data base=list[low];
	int i=low,j=high;
	while(i<j){
		//向左扫描
		while(i<j&&list[j].flag>base.flag){
			j--;
		} 
		//向右扫描
		while(i<j&&list[i].flag<=base.flag){
			i++;
		} 
		//交换
		if(i<j){
			temp=list[i];
			list[i]=list[j];
			list[j]=temp;
		}
	}
	//将基准元素放到正确位置
	if(list[i].flag>base.flag){//基准元素小于i,j的位置flag，则要将基准元素放在i-1位置 
		temp=list[i-1];
		list[i-1]=list[low];
		list[low]=temp;
		return i-1;
	}else{//交换i与low 
		temp=list[i];
		list[i]=list[low];
		list[low]=temp;
		return i;
	}
	
}

//快速排序Pro
void QuickSort_Pro(struct Data*list,int low,int high){
		if(low<high){
		//进行划分
		int middle=Partition(list,low,high);
		//左部分快速排序
		QuickSort(list,low,middle-1);
		//右部分快速排序
		QuickSort(list,middle+1,high);	
	}
} 

//测试函数
void Test(int method){
		struct Data list[10];
	//测试数据加载 
	for(int i=0;i<10;i++){
		if(i%2==0){
			list[i].flag=i*3;                                     
		}else{
			list[i].flag=i;
		}
	}
	cout<<"Test Data:";
	for(int i=0;i<10;++i){
		cout<<" "<<list[i].flag;
	}
	//进行快速排序 
	if(!method)
		QuickSort(list,0,9);
	else
		QuickSort_Pro(list,0,9);
	cout<<"\nUse QuickSort:";
	for(int i=0;i<10;++i){
		cout<<" "<<list[i].flag;
	}
	cout<<endl;
} 
int main(int argc,char** argv){
	Test(0);
	Test(1);
	return 0;
}
