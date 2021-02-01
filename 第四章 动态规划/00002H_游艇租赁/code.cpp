#include<iostream>
#include<cstdlib>
using namespace std;
#define N 1000
int price_map[N][N];//�۸��
int real_price[N][N];//���ż۸�
int strategy[N][N];//����ѡ��
//��ӡ������� 
void print(int i,int j){
	if(strategy[i][j]==0){
		cout<<"--"<<j;//i-->j ��ͬͣ����ֱ�ӵ�j
		return; 
	}
	print(i,strategy[i][j]);
	print(strategy[i][j],j);
} 
void solve(int&n,int&start,int&end){//����n��վ�� 
	for(int step=3;step<=n;step++){//������ֽ�Ϊ��СΪd��С���� 
		//���ȫ��С����
		for(int i=1;i<=n-step+1;i++){//��������
			int j=i+step-1;//�����յ� 
			//��̽ȫ��ͣ��վ
			for(int k=i+1;k<j;k++){
				int trial=real_price[i][k]+real_price[k][j];
				if(trial<real_price[i][j]){//�м�ͣ���Ƚ�ʡǮ 
					real_price[i][j]=trial;
					strategy[i][j]=k;//��¼�� i�� j���м�ͣ���� 
				} 
			}
		} 
	}
	//��ӡ�������
	cout<<start;
	print(start,end); 
	cout<<"\n����:  "<<real_price[start][end]<<endl;
}
int main(int argc,char**argv){
	cout<<"����վ�����\n";
	int number_of_sites=0;
	cin>>number_of_sites;
	//����۸��
	cout<<"����۸��\n";
	for(int i=1;i<=number_of_sites;i++){
		for(int j=i+1;j<=number_of_sites;j++){
			cin>>price_map[i][j];
			//��ʼ��real_priceΪprice_map
			real_price[i][j]=price_map[i][j]; 
		}
	}
	cout<<"Ѱ�ҽ��������...\n"; 
	int start=1,end=6;
	solve(number_of_sites,start,end);
	return 0;
}
