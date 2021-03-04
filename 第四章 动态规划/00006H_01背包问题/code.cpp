#include<iostream>
using namespace std;
#define SIZE 5//��SIZE����Ʒ
#define LoadingCapacity 10 //װ������ 
int Weight[SIZE+1]={0,2,5,4,2,3};//���� 2,5,4,2,3
int Value[SIZE+1]={0,6,3,5,4,6};//��Ӧ��Ʒ�ļ�ֵ 6,3,5,4,6
int C[SIZE+1][LoadingCapacity+1];//����ֵ����
int Result[SIZE+1]={0};//��¼��Ӧ�±���Ʒ�Ƿ���빺�ﳵ 

int get_max(int a,int b){
	int var_return=a>b?a:b;
	return var_return;
}

void init_C(void){
	//��ʼ������ֵ����
	for(int i=0;i<SIZE+1;i++){//��1�и�ֵΪ0 
		C[i][0]=0;
	} 
	for(int i=0;i<LoadingCapacity+1;i++){//��1�и�ֵΪ0 
		C[0][i]=0; 
	}	
	//���Weight Value����
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
	//����C����
	for(int i=1;i<SIZE+1;i++){
		for(int j=1;j<LoadingCapacity+1;j++){
			if(j<Weight[i]){//��ǰ����С�ڵ�ǰ��Ʒ������װ���£�װǰi-1�� 
				C[i][j]=C[i-1][j];
			}else{//�Ƚϴ���Ʒ�ţ��벻���Ƿ�ʹ�ü�ֵ���
				C[i][j]=get_max(C[i-1][j],C[i-1][j-Weight[i]]+Value[i]);
			} 
		}
	}
	cout<<"���ﳵװ������ֵΪ: "<<C[SIZE][LoadingCapacity]<<"\n";
}

void print_C(void){
	//���C����
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
	cout<<"װ����Ʒ���Ϊ:\n\t";
	for(int i=1;i<SIZE+1;i++){
		if(Result[i]==1){
			cout<<" "<<i;
		}
	}
	cout<<"\n";
}

int main(void){
	init_C();//��ʼ������ֵ����
	calculate_C();//��������ֵ���� 
	print_C();//���C���� 
	get_result();//���Ž� 
	return 0;
} 
