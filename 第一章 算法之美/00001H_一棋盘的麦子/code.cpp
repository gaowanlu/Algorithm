#include<iostream>
using namespace std;
int main(int argc,char**argv){
	int n;
	//����n
	cin>>n;
	//�ж�n�Ƿ�Ϸ�
	if(n<=0||n>11){
		cout<<"Error:n input error\n";
		return -1;
	}
	//һ��ʼsum=0
	int sum=0;
	int now=1;//ʹ��now����¼���������ĸ��ӵ��������� 
	int i=1;
	for(i=1;i<=n;++i){
		sum+=now;
		now*=2; 
	}
	cout<<"sum is "<<sum<<endl;
	return 0;
}
