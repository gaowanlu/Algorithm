#include<iostream>
using namespace std;

int main(int argc,char**argv){
	//x+y+z=30
	//3x+2y+z=50
	
	//得2x+y=20
	//进行遍历穷举
	int x,y,z;
	for(x=1;x<=9;x++){
		y=20-2*x;
		z=30-x-y;
		if(3*x+2*y+z==50){//满足要求的阶 
			cout<<"x y z:\n\t"<<x<<" "<<y<<" "<<z<<endl;
		} 
	} 
	return 0;
}
