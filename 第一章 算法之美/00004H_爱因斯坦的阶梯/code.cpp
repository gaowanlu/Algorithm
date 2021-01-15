#include<iostream>
using namespace std;
void function_1(void){
	int n=1;
	while(1){
		if(n%2==1&&n%3==2&&n%5==4&&n%6==5&&n%7==0){
			cout<<n<<endl;
			return;
		}else{
			++n;
		}
	}
}
void function_2(void){
	int n=7;
	while(1){
		if(n%2==1&&n%3==2&&n%5==4&&n%6==5&&n%7==0){
			cout<<n<<endl;
			return;
		}else{
			n+=7;
		}
	}
}
int main(int argc,char**argv){
	function_1();
	//进行优化
	function_2();
	return 0;
} 
