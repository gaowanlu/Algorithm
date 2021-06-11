/*
动态规划算法:最长的公共子序列 
日期:2021/1/28 
编码:高万禄 
*/
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

//求解最长公共子序列函数 
void LCSL(string&s1,string&s2,int**c,int**b){
	//求解c b 数组元素值
	for(int i=1;i<s1.size()+1;i++){
		for(int j=1;j<s2.size()+1;j++){
			if(s1[i-1]==s2[j-1]){
				c[i][j]=c[i-1][j-1]+1;//最大公共序列与s1 s2右对齐 
				b[i][j]=1; 
			}else{
				if(c[i][j-1]>c[i-1][j]){
					c[i][j]=c[i][j-1];//最大公共序列与 s2 不右对齐 
					b[i][j]=2;
				}else{
					c[i][j]=c[i-1][j];//最大公共序列与 s1 不右对齐 
					b[i][j]=3;
				}
			}
		}
	}
	//利用vector做栈
	int i=s1.size(),j=s2.size();//从右下角开始
	vector<char> stack;
	while(i&&j){
		if(b[i][j]==1){//z 与 s1 s2右对齐 
			stack.push_back(s1[i-1]);
			i=i-1;
			j=j-1;
		}else{
			if(b[i][j]==2){//z 与 s2 不右对齐 
				j=j-1;
			}else{
				i=i-1;//z 与 s1 不右对齐 
			}
		}
	}
	//依次出栈
	cout<<"最长公共子序列为:\t";
	while(stack.size()!=0){
		cout<<stack[stack.size()-1]<<" ";
		stack.pop_back();
	} 
	cout<<endl;
} 


//打印c b 数组函数 
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

//主函数 
int main(int argc,char**argv){
	//存储字符串
	string s1,s2;
	//输入字符串
	cout<<"s1:\t"; 
	cin>>s1;
	cout<<"s2:\t";
	cin>>s2;
	//申请c 与 b 二维数组
	int **c=(int**)malloc(sizeof(int*)*(s1.size()+1));
	int **b=(int**)malloc(sizeof(int*)*(s1.size()+1));
	for(int i=0;i<s1.size()+1;i++){
		*(c+i)=(int*)malloc(sizeof(int)*(s2.size()+1));
		*(b+i)=(int*)malloc(sizeof(int)*(s2.size()+1));
	}
	//初始化c数组的第一行与第一列
	for(int i=0;i<s1.size()+1;i++){//第一列 
		c[i][0]=0;
		b[i][0]=0;
	}
	for(int i=0;i<s2.size()+1;i++){//第一行 
		c[0][i]=0;
		b[0][i]=0;
	}
	//求解最长公共子序列
	LCSL(s1,s2,c,b); 
	cout<<"c[][]"<<endl;
	print_c_b_array(c,s1.size()+1,s2.size()+1);
	cout<<"b[][]"<<endl;
	print_c_b_array(b,s1.size()+1,s2.size()+1);
	//释放c 与 b 数组内存
	for(int i=0;i<s1.size()+1;i++){
		free(*(c+i));
		free(*(b+i));
	} 
	free(b);
	free(c);
	return 0;
} 
