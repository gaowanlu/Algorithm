//�������˷� 
#include<cstdlib>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int M =1000;
//�������Ҫ�˵Ĵ��� 
char A[M];
char B[M];

struct Node{
	char num[M];
	int l;//��¼���� 
	int c;//��¼���� 
};

//�ֽ⺯��
//���ܽ�old�ڴ��±�index�����湲sizeλװ��target 
void decompose(struct Node&old,struct Node&target,int index,int size){
	for(int i=index,j=0;j<size;j++,i++){
		target.num[j]=old.num[i];
	}
	//����target�ĳ��������
	target.l=size;
	target.c=index+old.c;//ȡ�������ֵĴ��ݵ���ԭ����������û��ȡ�õ�λ��
	//��index�±꿪ʼȡ�򽫴����indexλ��λ���� 
}

//��Ӻ���
//����:�������д��ݵ����������
//�� C+A+B
//��673*10^2 + 98*10^4
//0  0 | 0 0 8 9 ����ಹ�㣩 
//0  0 | 3 7 6 0 ���Ҳಹ�㣩
//�ӷ�����
/*0 0 8 9
+ 3 7 6 0
= 3 7 4 0 1
��  673*10^2 + 98*10^4 = 10473*10^2
*/ 
void add(struct Node &A,struct Node &B,struct Node&C){
	//����ȷ���Ǹ����Ĵ��ݸ���ͣ��Ա����
	if(A.c<B.c){
		struct Node temp=A;
		A=B;
		B=temp;
	} 
	//ȷ��A�Ĵ��ݴ��ڵ���B�Ĵ���
	//C�Ĵ�����ΪA��B�͵Ĵ���
	C.c=B.c;
	//����A + B�Ľ��ֵ���һ������λ
	int c_length=0;
	if(A.c+A.l>B.c+B.l){
		c_length=A.c+A.l;
	}else{
		c_length=B.c+B.l;
	}
	//����A�����Ҫ���������:���ݼ����� 
	int A_left_zeros_num= A.c-B.c;
	int cc=0;//��¼��λ
	//�������ֵ������󳤶�Ϊ�ܳ��� c_length - ����
	int i=0;
	for(i=0;i<c_length-C.c;i++){
		int ta=0,tb=0;
		if(i<A_left_zeros_num){
			ta=0;//A��ಹ�� 
		}else{
			ta=A.num[i-A_left_zeros_num]-48;
		}
		if(i<B.l){
			tb=B.num[i]-48;
		}else{//B�Ҳಹ�� 
			tb=0;
		}
		if(i>=A.l+A_left_zeros_num){
			ta=0;
		}
		C.num[i]=((ta+tb+cc)%10)+48;
		cc=(ta+tb+cc)/10;
	} 
	if(cc){//��λ���� 
		C.num[i++]=cc+48;
	}
	C.l=i;
} 



//���� A mul B���������κ��ĺ��� 
void mul(struct Node A_node,struct Node B_node,struct Node&AmulB_node){
	if(A_node.l/2==0||B_node.l/2==0){//(�ݹ����): A B����������1λ���� 
		if(A_node.l/2==0){//�����A�ĳ���Ϊ1����A B������A�ĳ��ȴ��ڵ���B�ĳ��� 
			struct Node temp=A_node;
			A_node=B_node;
			B_node=temp;
		}
		//�������Ĵ���(���������������)
		AmulB_node.c=A_node.c+B_node.c;
		//���������Ѿ�ȷ����Bֻ��һλ
		//����A*B
		int cc=0;//ʹ��cc��¼��λ
		int i=0;
		for(i=0;i<A_node.l;i++){//�˷����� 
			AmulB_node.num[i]=(((B_node.num[0]-48)*(A_node.num[i]-48)+cc)%10)+48;
			cc=((B_node.num[0]-48)*(A_node.num[i]-48)+cc)/10;
		}
		//�������λ��Ϊ0��Ҫ�����λ
		if(cc){
			AmulB_node.num[i++]=cc+48;
		} 
		AmulB_node.l=i;
		//cout<"mul "<<AmulB_node.num<<endl;
		return;//�ݹ���� 
	}
	//���зֽ�
	struct Node A_low_node,A_high_node;
	struct Node B_low_node,B_high_node;
	decompose(A_node,A_low_node,0,A_node.l/2);//A��λ 
	decompose(A_node,A_high_node,A_node.l/2,A_node.l-(A_node.l/2));//A��λ 
	decompose(B_node,B_low_node,0,B_node.l/2);//B��λ 
	decompose(B_node,B_high_node,B_node.l/2,B_node.l-(B_node.l/2));//B��λ 
	//����(���Ĳ������)
	struct Node t1,t2,t3,t4;
	mul(A_high_node,B_high_node,t1);
	mul(A_high_node,B_low_node,t2);
	mul(A_low_node,B_high_node,t3);
	mul(A_low_node,B_low_node,t4); 
	//�ϲ�
	struct Node temp;
	add(t1,t2,AmulB_node);
	add(t3,AmulB_node,temp);
	add(temp,t4,AmulB_node);
}

int main(int argc,char**argv){
	struct Node A_node,B_node,AmulB_node;  
	cout<<"�������A: ";
	cin>>A;
	cout<<"�������B: ";
	cin>>B;
	cout<<"����A: "<<A<<endl;
	cout<<"����B: "<<B<<endl;
	//����A
	for(int j=strlen(A)-1,i=0;j>=0;i++,j--){//��ֵ���� 
		A_node.num[i]=A[j];
	}
	A_node.c=0;//���ݴ���
	A_node.l=strlen(A);//���ȴ���
	//����B
	for(int j=strlen(B)-1,i=0;j>=0;i++,j--){//��ֵ���� 
		B_node.num[i]=B[j];
	}
	B_node.c=0;//���ݴ���
	B_node.l=strlen(B);//���ȴ��� 
	//���Anum
	cout<<endl;
	for(int i=0;i<A_node.l;i++){
		cout<<A_node.num[i];
	} 
	cout<<endl;
	//���Bnum
	for(int i=0;i<B_node.l;i++){
		cout<<B_node.num[i];
	} 
	cout<<endl;
	//����A*B
	mul(A_node,B_node,AmulB_node);
	//���������
	cout<<endl;
	for(int i=AmulB_node.l-1;i>=0;i--){
		cout<<AmulB_node.num[i];
	} 
	cout<<endl;
	return 0;
}
