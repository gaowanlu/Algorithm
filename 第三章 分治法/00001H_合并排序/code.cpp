#include<iostream>
#include<cstdlib>
using namespace std;
struct Data{
	int flag;
};
void MergeFunction(struct Data*list,int low,int middle,int high){
	//申请辅助空间
	int size=high-low;
	struct Data*space=(struct Data*)malloc(sizeof(struct Data)*size);
	int i=low,j=middle+1;
	int now=0;
	while(i<=middle||j<=high){
		if(i<=middle&&j<=high){
			//比较i j flag
			if(list[i].flag<list[j].flag){
				space[now++]=list[i++];
			}else{
				space[now++]=list[j++];
			} 
		}else if(i<=middle){//i迭代全装入space 
			space[now++]=list[i++]; 
		}else{//j迭代装入space 
			space[now++]=list[j++];
		}
	}
	//将space内的内容装入原来列表内
	for(i=low;i<=high;i++){
		list[i]=space[i-low];
	} 
	free(space);
}
void MergeSort(struct Data*list,int low,int high){
	if(low>=high){//=说明只有一个元素不用排序 
		return;
	}
	int middle=(low+high)/2;
	//对middle左边排序
	MergeSort(list,low,middle);
	//对middle右边排序 
	MergeSort(list,middle+1,high);
	//合并
	MergeFunction(list,low,middle,high);
}
int main(int argc,char**argv){
	struct Data list[5]={{34},{5},{2},{7},{10}};
	MergeSort(list,0,4);
	//输出
	for(int i=0;i<5;i++){
		cout<<" "<<list[i].flag;
	} 
	cout<<endl;
	return 0;
}
