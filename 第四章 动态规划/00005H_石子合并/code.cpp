#include<iostream>
using namespace std;
#define N 1000
#define INF 99999//���� 
int stones[N];//�洢ÿ��ʯ������ 
int Min[N][N],Max[N][N];
int sum[N];//����1 - i�ѵ�ʯ�Ӻ� 
//��·�淨 
void highway(int n){
	//��ʼ��Min Max����
	for(int i=1;i<=n;i++){
		Min[i][i]=0;
		Max[i][i]=0;
	}
	//��ʼsum����
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+stones[i];
	} 
	for(int step=2;step<=n;step++){//�����ģ��2��ʯ�ӿ�ʼ��� 
		for(int i=1;i<=n-step+1;i++){//��� 
			int j=i+step-1;//�յ�
			//��ʼ��min[i][j] max[i][j] 
			Min[i][j]=INF;
			Max[i][j]=-1;
			int temp=sum[j]-sum[i-1];//��ô� i�ѵ�j�ѣ�ʯ������,�����i j�����⻨�� 
			//��i j������k����Ϊ����ѣ�ѡ�����������Ļ�������ѷ��� 
			for(int k=i;k<j;k++){
				if(Min[i][j]>Min[i][k]+Min[k+1][j]+temp){
					Min[i][j]=Min[i][k]+Min[k+1][j]+temp;
				}
				if(Max[i][j]<Max[i][k]+Max[k+1][j]+temp){
					Max[i][j]=Max[i][k]+Max[k+1][j]+temp;
				}
			} 
		}
	}
	
}
//�ٳ��淨
void playground(int n){
	//���ٳ�����ת��Ϊֱ����
	for(int i=1;i<=n-1;i++){
		stones[n+i]=stones[i];
	} 
	n=2*n-1;
	//ֱ�����
	highway(n);
	n=(n+1)/2;
	int temp_min=Min[1][n];
	int temp_max=Max[1][n];
	//ѡ�������С��
	/*
	1 2 3 4
	1 2 3 4 1 2 3
	state:
	1 2 3 4
	2 3 4 1
	3 4 1 2
	4 1 2 3
	*/
	for(int i=2;i<=n;i++){ 
		if(Min[i][n+i-1]<temp_min){
			temp_min=Min[i][n+i-1];
		}
		if(Max[i][n+i-1]>temp_max){
			temp_max=Max[i][n+i-1];
		}
	}
	cout<<"�ٳ��淨\n";
	cout<<"Min "<<temp_min<<endl;
	cout<<"Max "<<temp_max<<endl; 
}
int main(int argc,char**argv){
	int n;
	cout<<"����ʯ�ӵĶ���\n";
	cin>>n;
	cout<<"������ѵ�ʯ������\n";
	for(int i=1;i<=n;i++){
		cin>>stones[i];
	}
	//��·�淨 
	highway(n);
	cout<<"��·�淨\n";
	cout<<"Min "<<Min[1][n]<<endl;
	cout<<"Max "<<Max[1][n]<<endl;
	//�ٳ��淨
	playground(n);
	return 0;
} 
