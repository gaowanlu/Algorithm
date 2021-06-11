/*
��̬�滮�㷨:��Ĺ��������� 
����:2021/1/28 
����:����» 
*/
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

//�������������к��� 
void LCSL(string&s1,string&s2,int**c,int**b){
	//���c b ����Ԫ��ֵ
	for(int i=1;i<s1.size()+1;i++){
		for(int j=1;j<s2.size()+1;j++){
			if(s1[i-1]==s2[j-1]){
				c[i][j]=c[i-1][j-1]+1;//��󹫹�������s1 s2�Ҷ��� 
				b[i][j]=1; 
			}else{
				if(c[i][j-1]>c[i-1][j]){
					c[i][j]=c[i][j-1];//��󹫹������� s2 ���Ҷ��� 
					b[i][j]=2;
				}else{
					c[i][j]=c[i-1][j];//��󹫹������� s1 ���Ҷ��� 
					b[i][j]=3;
				}
			}
		}
	}
	//����vector��ջ
	int i=s1.size(),j=s2.size();//�����½ǿ�ʼ
	vector<char> stack;
	while(i&&j){
		if(b[i][j]==1){//z �� s1 s2�Ҷ��� 
			stack.push_back(s1[i-1]);
			i=i-1;
			j=j-1;
		}else{
			if(b[i][j]==2){//z �� s2 ���Ҷ��� 
				j=j-1;
			}else{
				i=i-1;//z �� s1 ���Ҷ��� 
			}
		}
	}
	//���γ�ջ
	cout<<"�����������Ϊ:\t";
	while(stack.size()!=0){
		cout<<stack[stack.size()-1]<<" ";
		stack.pop_back();
	} 
	cout<<endl;
} 


//��ӡc b ���麯�� 
void print_c_b_array(int**array,int rows,int cols){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<40;i++){
		cout<<"-";
	}
	cout<<endl;
} 

//������ 
int main(int argc,char**argv){
	//�洢�ַ���
	string s1,s2;
	//�����ַ���
	cout<<"s1:\t"; 
	cin>>s1;
	cout<<"s2:\t";
	cin>>s2;
	//����c �� b ��ά����
	int **c=(int**)malloc(sizeof(int*)*(s1.size()+1));
	int **b=(int**)malloc(sizeof(int*)*(s1.size()+1));
	for(int i=0;i<s1.size()+1;i++){
		*(c+i)=(int*)malloc(sizeof(int)*(s2.size()+1));
		*(b+i)=(int*)malloc(sizeof(int)*(s2.size()+1));
	}
	//��ʼ��c����ĵ�һ�����һ��
	for(int i=0;i<s1.size()+1;i++){//��һ�� 
		c[i][0]=0;
		b[i][0]=0;
	}
	for(int i=0;i<s2.size()+1;i++){//��һ�� 
		c[0][i]=0;
		b[0][i]=0;
	}
	//��������������
	LCSL(s1,s2,c,b); 
	cout<<"c[][]"<<endl;
	print_c_b_array(c,s1.size()+1,s2.size()+1);
	cout<<"b[][]"<<endl;
	print_c_b_array(b,s1.size()+1,s2.size()+1);
	//�ͷ�c �� b �����ڴ�
	for(int i=0;i<s1.size()+1;i++){
		free(*(c+i));
		free(*(b+i));
	} 
	free(b);
	free(c);
	return 0;
} 
