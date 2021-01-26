//大整数乘法 
#include<cstdlib>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int M =1000;
//存放两个要乘的大数 
char A[M];
char B[M];

struct Node{
	char num[M];
	int l;//记录长度 
	int c;//记录次幂 
};

//分解函数
//功能将old内从下标index及后面共size位装入target 
void decompose(struct Node&old,struct Node&target,int index,int size){
	for(int i=index,j=0;j<size;j++,i++){
		target.num[j]=old.num[i];
	}
	//更新target的长度与次幂
	target.l=size;
	target.c=index+old.c;//取出来部分的次幂等于原来次幂数加没有取得低位数
	//从index下标开始取则将错过了index位低位数据 
}

//相加函数
//功能:将两个有次幂的数进行相加
//即 C+A+B
//以673*10^2 + 98*10^4
//0  0 | 0 0 8 9 （左侧补零） 
//0  0 | 3 7 6 0 （右侧补零）
//加法计算
/*0 0 8 9
+ 3 7 6 0
= 3 7 4 0 1
则  673*10^2 + 98*10^4 = 10473*10^2
*/ 
void add(struct Node &A,struct Node &B,struct Node&C){
	//首先确定那个数的次幂高与低，以便计算
	if(A.c<B.c){
		struct Node temp=A;
		A=B;
		B=temp;
	} 
	//确保A的次幂大于等于B的次幂
	//C的次幂则为A与B低的次幂
	C.c=B.c;
	//计算A + B的结果值最多一共多少位
	int c_length=0;
	if(A.c+A.l>B.c+B.l){
		c_length=A.c+A.l;
	}else{
		c_length=B.c+B.l;
	}
	//计算A左侧需要补零的数量:高幂减低幂 
	int A_left_zeros_num= A.c-B.c;
	int cc=0;//记录进位
	//结果的数值部分最大长度为总长度 c_length - 低幂
	int i=0;
	for(i=0;i<c_length-C.c;i++){
		int ta=0,tb=0;
		if(i<A_left_zeros_num){
			ta=0;//A左侧补零 
		}else{
			ta=A.num[i-A_left_zeros_num]-48;
		}
		if(i<B.l){
			tb=B.num[i]-48;
		}else{//B右侧补零 
			tb=0;
		}
		if(i>=A.l+A_left_zeros_num){
			ta=0;
		}
		C.num[i]=((ta+tb+cc)%10)+48;
		cc=(ta+tb+cc)/10;
	} 
	if(cc){//进位处理 
		C.num[i++]=cc+48;
	}
	C.l=i;
} 



//大数 A mul B函数，分治核心函数 
void mul(struct Node A_node,struct Node B_node,struct Node&AmulB_node){
	if(A_node.l/2==0||B_node.l/2==0){//(递归出口): A B两个数中有1位数的 
		if(A_node.l/2==0){//如果数A的长度为1，则将A B交换，A的长度大于等于B的长度 
			struct Node temp=A_node;
			A_node=B_node;
			B_node=temp;
		}
		//计算结果的次幂(等于两数次幂相加)
		AmulB_node.c=A_node.c+B_node.c;
		//现在我们已经确保数B只有一位
		//计算A*B
		int cc=0;//使用cc记录进位
		int i=0;
		for(i=0;i<A_node.l;i++){//乘法迭代 
			AmulB_node.num[i]=(((B_node.num[0]-48)*(A_node.num[i]-48)+cc)%10)+48;
			cc=((B_node.num[0]-48)*(A_node.num[i]-48)+cc)/10;
		}
		//如果最后进位不为0则要处理进位
		if(cc){
			AmulB_node.num[i++]=cc+48;
		} 
		AmulB_node.l=i;
		//cout<"mul "<<AmulB_node.num<<endl;
		return;//递归出口 
	}
	//进行分解
	struct Node A_low_node,A_high_node;
	struct Node B_low_node,B_high_node;
	decompose(A_node,A_low_node,0,A_node.l/2);//A低位 
	decompose(A_node,A_high_node,A_node.l/2,A_node.l-(A_node.l/2));//A高位 
	decompose(B_node,B_low_node,0,B_node.l/2);//B低位 
	decompose(B_node,B_high_node,B_node.l/2,B_node.l-(B_node.l/2));//B高位 
	//处理(将四部分相乘)
	struct Node t1,t2,t3,t4;
	mul(A_high_node,B_high_node,t1);
	mul(A_high_node,B_low_node,t2);
	mul(A_low_node,B_high_node,t3);
	mul(A_low_node,B_low_node,t4); 
	//合并
	struct Node temp;
	add(t1,t2,AmulB_node);
	add(t3,AmulB_node,temp);
	add(temp,t4,AmulB_node);
}

int main(int argc,char**argv){
	struct Node A_node,B_node,AmulB_node;  
	cout<<"输入大数A: ";
	cin>>A;
	cout<<"输入大数B: ";
	cin>>B;
	cout<<"大数A: "<<A<<endl;
	cout<<"大数B: "<<B<<endl;
	//处理A
	for(int j=strlen(A)-1,i=0;j>=0;i++,j--){//数值处理 
		A_node.num[i]=A[j];
	}
	A_node.c=0;//次幂处理
	A_node.l=strlen(A);//长度处理
	//处理B
	for(int j=strlen(B)-1,i=0;j>=0;i++,j--){//数值处理 
		B_node.num[i]=B[j];
	}
	B_node.c=0;//次幂处理
	B_node.l=strlen(B);//长度处理 
	//输出Anum
	cout<<endl;
	for(int i=0;i<A_node.l;i++){
		cout<<A_node.num[i];
	} 
	cout<<endl;
	//输出Bnum
	for(int i=0;i<B_node.l;i++){
		cout<<B_node.num[i];
	} 
	cout<<endl;
	//计算A*B
	mul(A_node,B_node,AmulB_node);
	//输出计算结果
	cout<<endl;
	for(int i=AmulB_node.l-1;i>=0;i--){
		cout<<AmulB_node.num[i];
	} 
	cout<<endl;
	return 0;
}
