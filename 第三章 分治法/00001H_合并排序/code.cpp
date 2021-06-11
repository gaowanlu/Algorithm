#include<iostream>
#include<cstdlib>
using namespace std;
struct Data{
	int flag;
};  


void MergeFunction(struct Data*list,int low,int middle,int high){
	//���븨���ռ�
	int size=high-low;
	struct Data*space=(struct Data*)malloc(sizeof(struct Data)*size);
	int i=low,j=middle+1;
	int now=0;
	while(i<=middle||j<=high){
		if(i<=middle&&j<=high){
			//�Ƚ�i j flag
			if(list[i].flag<list[j].flag){
				space[now++]=list[i++];
			}else{
				space[now++]=list[j++];
			} 
		}else if(i<=middle){//i����ȫװ��space 
			space[now++]=list[i++]; 
		}else{//j����װ��space 
			space[now++]=list[j++];
		}
	}
	//��space�ڵ�����װ��ԭ���б���
	for(i=low;i<=high;i++){
		list[i]=space[i-low];
	} 
	free(space);
}


void MergeSort(struct Data*list,int low,int high){
	if(low>=high){//=˵��ֻ��һ��Ԫ�ز������� 
		return;
	}
	int middle=(low+high)/2;
	//��middle�������
	MergeSort(list,low,middle);
	//��middle�ұ����� 
	MergeSort(list,middle+1,high);
	//�ϲ�
	MergeFunction(list,low,middle,high);
}

int main(int argc,char**argv){
	struct Data list[5]={{34},{5},{2},{7},{10}};
	MergeSort(list,0,4);
	//���
	for(int i=0;i<5;i++){
		cout<<" "<<list[i].flag;
	} 
	cout<<endl;
	return 0;
}
