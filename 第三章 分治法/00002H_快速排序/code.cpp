#include<iostream>
#include<cstdlib>
using namespace std;
struct Data{
	int flag;
};

//�������򻮷ֺ���,���ػ�׼Ԫ�������±� 
int Partition(struct Data*list,int low,int high){
	struct Data temp;
	int i=low,j=high,p=low;
	while(i<j){
		//��������
		while(j>i&&list[j].flag>list[p].flag){
			j--;
		}
		//����Ԫ�ؽ���
		if(j>i){ 
			temp=list[j];
			list[j]=list[i];
			list[i]=temp;
			p=j;
			i++; 
		} 
		//��������
		while(j>i&&list[i].flag<=list[p].flag){
			i++;
		} 
		//����Ԫ�ؽ���
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

//��������ݹ麯��
void QuickSort(struct Data*list,int low,int high){
	if(low<high){
		//���л���
		int middle=Partition(list,low,high);
		//�󲿷ֿ�������
		QuickSort(list,low,middle-1);
		//�Ҳ��ֿ�������
		QuickSort(list,middle+1,high);	
	}
} 


//�Ż���Ļ��ֺ���
//���ǲ�������ɨ�裬����������ɨ�裬����
//������ȫ��������ɨ�裬����ɨ�裬Ȼ�󽻻� 
int Partition_Pro(struct Data*list,int low,int high){
	struct Data temp;
	struct Data base=list[low];
	int i=low,j=high;
	while(i<j){
		//����ɨ��
		while(i<j&&list[j].flag>base.flag){
			j--;
		} 
		//����ɨ��
		while(i<j&&list[i].flag<=base.flag){
			i++;
		} 
		//����
		if(i<j){
			temp=list[i];
			list[i]=list[j];
			list[j]=temp;
		}
	}
	//����׼Ԫ�طŵ���ȷλ��
	if(list[i].flag>base.flag){//��׼Ԫ��С��i,j��λ��flag����Ҫ����׼Ԫ�ط���i-1λ�� 
		temp=list[i-1];
		list[i-1]=list[low];
		list[low]=temp;
		return i-1;
	}else{//����i��low 
		temp=list[i];
		list[i]=list[low];
		list[low]=temp;
		return i;
	}
	
}

//��������Pro
void QuickSort_Pro(struct Data*list,int low,int high){
		if(low<high){
		//���л���
		int middle=Partition(list,low,high);
		//�󲿷ֿ�������
		QuickSort(list,low,middle-1);
		//�Ҳ��ֿ�������
		QuickSort(list,middle+1,high);	
	}
} 

//���Ժ���
void Test(int method){
		struct Data list[10];
	//�������ݼ��� 
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
	//���п������� 
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
