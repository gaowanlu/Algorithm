//����:��������
//����:2021/2/1
//����:����»
#include<iostream>
using namespace std;
#define N 1000//���N-1������
int matrix_data[N];
int mul_num[N][N],strategy[N][N];
//���ֲ�����Ϣ
void matrix_mul(int&matrix_num){
	//�ÿ���Ϣ����
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			mul_num[i][j]=0;
			strategy[i][j]=0;
		}
	}
	for(int step=2;step<=matrix_num;step++){//��ⲻͬ��ͬ��ģ������
		 for(int i=1;i<=matrix_num-step+1;i++){//������� 
		 	int j=i+step-1;//�����յ�
			//��ʼ�������������������������λ��
			mul_num[i][j]=mul_num[i+1][j]+matrix_data[i-1]*matrix_data[i]*matrix_data[j];
			strategy[i][j]=i;
			//��������̽��������λ��
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
//��ӡ����
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
	cout<<"�������:\n";
	int matrix_num=0;
	cin>>matrix_num;
	cout<<"��������������һ�����������:\n";
	for(int i=0;i<=matrix_num;i++){
		cin>>matrix_data[i];
	} 
	//������Ϣ����matrix_mul
	matrix_mul(matrix_num);
	//��ӡ����
	print_result(1,matrix_num); 
	return 0;
} 
