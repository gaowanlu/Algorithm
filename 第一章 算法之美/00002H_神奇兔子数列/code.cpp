#include<iostream>
#include<cstdlib>
using namespace std;
//쳲��������еݹ��㷨
//������쳲��������е�n��Ԫ�� 
int Fib1(int n){ 
	if(n<1){
		return -1;
	}
	if(n==1||n==2){
		return 1;
	}else{
		return Fib1(n-1)+Fib1(n-2);
	}
} 
int* Fib2(int n){
	if(n<1){//�ж�n�Ƿ�Ϸ� 
		return NULL;
	}	
	//ʹ�ö�̬�ڴ������ 
	int *list=(int*)malloc(sizeof(int)*(n+1));//�����Ϊn+1 �±�Ϊ0�ռ䲻ʹ��
	list[1]=1;
	list[2]=1;
	//��ʼ��������
	int i=3;
	for(i=3;i<=n;i++){
		list[i]=list[i-1]+list[i-2];
	} 
	return list;
}
int Fib3(int n){
	if(n<1){//�ж�n�Ƿ�Ϸ� 
		return -1;
	}
	if(n==1||n==2){
		return 1;
	}
	int i=1,v1=1,v2=1;
	//�������
	for(i=3;i<=n;++i){
		v2=v1+v2;
		v1=v2-v1;
	}
	return v2;
}
int main(int argc,char**argv){
	cout<<Fib1(15)<<endl;
	//���ǻᷢ���������㷨���Ӷȼ���������Ǽ���Fib1(101)����Ҫ����һ��
	//�ܲ��ܽ���ʱ�临�Ӷ��ϵ��Ż�?
	//�����������������ÿ����һ�ζ�Ҫ��n�ݹ鵽1�����ǲ�û�м�¼�м������¼��쳲�������
	//���ǽ�����һ���ĸĽ�:���鿴Fib2���� 
	//ʹ��Fib2
	int *list=Fib2(15);
	if(list){
		cout<<list[15]<<endl;
		free(list);//�ͷ�list�ռ�	
	} 
	//�ɼ�ʱ�������ǽ����˿ɼ����Ż����ܲ��ܽ������Ż�?
	//ʱ�临�Ӷ������Ż�����O(n),�ռ临�Ӷ�ҲΪO(n)
	//����ֻ��Ҫ������е�n��ĺͣ���ȫû�б�Ҫȥ��¼1~n-1������ֵ
	//�������ǾͿ��Խ��ռ临�ӶȽ����Ż�:�뿴Fib3()
	cout<<Fib3(15)<<endl;
	cout<<"Change the world and yourself with code. Hold on, hold on.\n";
	return 0;
}
