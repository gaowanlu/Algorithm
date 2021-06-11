#include<iostream>
using namespace std;
int main(int argc,char**argv){
	int n;
	//输入n
	cin>>n;
	//判断n是否合法
	if(n<=0||n>11){
		cout<<"Error:n input error\n";
		return -1;
	}
	//一开始sum=0
	int sum=0;
	int now=1;//使用now来记录，迭代到的格子的麦子粒数 
	int i=1;
	for(i=1;i<=n;++i){
		sum+=now;
		now*=2; 
	}
	cout<<"sum is "<<sum<<endl;
	return 0;
}
