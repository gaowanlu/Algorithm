#include<iostream>
using namespace std;

int main(int argc,char**argv){
	//x+y+z=30
	//3x+2y+z=50
	
	//��2x+y=20
	//���б������
	int x,y,z;
	for(x=1;x<=9;x++){
		y=20-2*x;
		z=30-x-y;
		if(3*x+2*y+z==50){//����Ҫ��Ľ� 
			cout<<"x y z:\n\t"<<x<<" "<<y<<" "<<z<<endl;
		} 
	} 
	return 0;
}
