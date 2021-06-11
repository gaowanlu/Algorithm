/*
����:01�������ݷ����
����:����»
����:2021/3/15 
*/ 
#include<iostream>
#include<cstdlib>
/*�������� 
�洢��Ʒ����
4
���ﳵ����      10
����������Ʒ����W[]     2 5 4 2
����������Ʒ��ֵV[]     6 3 5 4
W[]--V[]:       2--6    5--3    4--5    2--4
ѡ�е���Ʒ���Ϊ:       0       2       3
*/

using namespace std;
float nowWeight=0.0f;//��ǰ����
float nowPrice=0.0f;//��ǰװ��ļ�ֵ
float bestPrice=0.0f;//���Ž��ֵ
float sumWeight=0.0;//ͳ��������Ʒ����
float sumPrice=0.0;//ͳ��������Ʒ�ܼ�ֵ

float bound(float*V,int i,int N){
	float temp=0.0f;
	for(;i<N;i++){
		temp+=V[i];
	}
	return nowPrice+temp;
} 


//���ݷ����
//�����ռ䣬t�������ڵ���չ�ڵ�t�� 
void backTrack(float*W,float*V,int N,float M,int *bestChoose,int*tempChoose,int t){
	//�ж��Ƿ񵽴���Ҷ�ӽڵ�
	if(t>=N){
		//���浱ǰ���Ž�
		for(int i=0;i<N;i++){
			bestChoose[i]=tempChoose[i];
		}
		bestPrice=nowPrice;
		return;
	}
	//�Ƿ�������������������
	if(nowWeight+W[t]<=M){
		tempChoose[t]=1;
		nowWeight+=W[t];
		nowPrice+=V[t];
		backTrack(W,V,N,M,bestChoose,tempChoose,t+1);//̽������������ 
		nowWeight-=W[t];//���� 
		nowPrice-=V[t];
	}
	//�Ƿ�������������������
	if(bound(V,t+1,N)>bestPrice){
		tempChoose[t]=0;
		//̽��������
		backTrack(W,V,N,M,bestChoose,tempChoose,t+1); 
	} 
}

//����bool���� 
int* knapsack(float*W,float*V,int N,float M){
	//���
	for(int i=0;i<N;i++){
		sumWeight+=W[i];
		sumPrice+=V[i];
	} 
	//�ж��Ƿ���Խ�ȫ����Ʒ���빺�ﳵ
	if(sumWeight<=M){
		bestPrice=sumPrice;
		cout<<"��������Ʒ���빺�ﳵ\n";
		return NULL;
	}
	//��¼��Ӧ�±���Ʒ�Ƿ���빺�ﳵ
	int *bestChoose=(int*)malloc(sizeof(int)*N);
	//��ʱ�洢����Ӧ�±���Ʒ�Ƿ���빺�ﳵ
	int *tempChoose=(int*)malloc(sizeof(int)*N); 
	//���ݷ����
	backTrack(W,V,N,M,bestChoose,tempChoose,0);
	free(tempChoose);
	return bestChoose;
}

//������ 
int main(int argc,char**argv){
	int N;//�洢��Ʒ�ĸ���
	cout<<"�洢��Ʒ����\t";
	cin>>N;
	float M;
	cout<<"���ﳵ����\t";
	cin>>M;
	float *W=(float*)malloc(sizeof(float)*(N));
	float *V=(float*)malloc(sizeof(float)*(N));
	cout<<"����������Ʒ����W[]\t";
	for(int i=0;i<N;i++){
		cin>>W[i];
	}
	cout<<"����������Ʒ��ֵV[]\t";
	for(int i=0;i<N;i++){
		cin>>V[i];
	}
	//������֤
	cout<<"W[]--V[]:\t";
	for(int i=0;i<N;i++){
		cout<<W[i]<<"--"<<V[i]<<"\t";
	} 
	cout<<"\n";
	int* result=knapsack(W,V,N,M);
	free(W);free(V);
	cout<<"ѡ�е���Ʒ���Ϊ:\t"; 
	for(int i=0;i<N;i++){
		if(result[i]==1)
	    	cout<<i<<"\t";
	}
	cout<<"\n";
	free(result);
	return 0;
} 
