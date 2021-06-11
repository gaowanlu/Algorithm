#include<iostream>
using namespace std;
#define N 1000
int map[N][N];//ͼ���ڽӾ���
int strategy[N][N];//��¼i j �м�����Ÿ��
int m[N][N];//��¼i j֮���и������Ȩ�� 

//�����и� 
void convex_triangular_cutting(int n){
	//��ʼ������Ȩ������Ծ���
	for(int i=0;i<n;i++){
		strategy[i][i]=0;
		map[i][i]=0;
	} 
	//����������������⿪ʼ��step���������n����������� 
	for(int step=2;step<n;step++){ 
		for(int i=1;i<n-step+1;i++){//������𶥵� i-1
			int j=i+step-1;//�����ն���
			//��ʼm[i][j] �� ���Ų��Էָ��
			m[i][j]=m[i+1][j]+map[i-1][i]+map[i][j]+map[i-1][j];
			strategy[i][j]=i;
			//Ѱ��i-1 j֮��������и��k
			for(int k=i+1;k<j;k++){
				int temp=m[i][k]+m[k+1][j]+map[i-1][k]+map[k][j]+map[i-1][j];
				if(m[i][j]>temp){
					m[i][j]=temp;//��������Ȩ�����и�� 
					strategy[i][j]=k;
				}
			}
			
		} 
	}
}
//���������
void print_result(int i,int j){
	if(i==j){
		return;
	}
	if(strategy[i][j]>i){//i-1 j���⣬�����и�����i,��Ϊi���ڲ��и� 
		cout<<"  {"<<i-1<<","<<strategy[i][j]<<"}  ";
	}
	if(strategy[i][j]+1<j){//i-1 j���⣬�����и��С��j-1 ��Ϊj-1���ڲ��и� 
		cout<<"  {"<<strategy[i][j]<<","<<j<<"}  ";
	}
	print_result(i,strategy[i][j]);
	print_result(strategy[i][j]+1,j);
} 

int main(int argc,char**argv){
	int n=0;
	cout<<"���붥�����\n";
	cin>>n;
	cout<<"������������������Ȩֵ\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	convex_triangular_cutting(n);
	print_result(1,n-1);//��ӡ��� 
	return 0;
}
