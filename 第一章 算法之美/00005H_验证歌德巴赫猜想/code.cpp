#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
//验证任意大于2的偶数都可以表示成两个素数之和

//判断一个数是否为素数
/*算法流程:试除法 
用 2、3、4、...、sqrt(n)去除n
如果能被整除则为合数
不能整除则为素数 
*/
bool judge(int n){
	//先对n进行判断
	if(n<=1){
		return 0;
	}
	if(n==2){
		return 1;
	}
	//开始迭代判断
	int i=2;
	int sqrt_n=(int)sqrt((double)n);
	for(i=2;i<=sqrt_n;++i){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
//验证猜想_1 
void function_1(void){
	int i,n;
	for(i=4;i<=2000;i+=2){//从4开始验证 
		//将i分解为两个数、这两个数的和等于i
		for(n=2;n<i;n++){//最小的素数为2、从2开始遍历 
			//判断n是否为素数
			if(judge(n)){//n为素数 
				//求出另一个加数
				if(judge(i-n)){//得到一对符合要求的素数 
					cout<<i<<":\n";
					cout<<"\t "<<n<<" "<<i-n<<endl; 
					//对偶数 i 验证成功
					break; 
				} 
			}
		}
		//如果上面的循环体结束后,i==n则对i没有验证成功 
		if(i==n){
			cout<<"Error: "<<i<<endl; 
		} 
	}
}
//验证猜想_2
void function_2(){
	int i,n;
	for(i=4;i<=2000;i+=2){//从4开始验证 
		//将i分解为两个数、这两个数的和等于i
		for(n=2;n<=i/2;n++){//最小的素数为2、从2开始遍历 
			//判断n是否为素数
			if(judge(n)){//n为素数 
				//求出另一个加数
				if(judge(i-n)){//得到一对符合要求的素数 
					cout<<i<<":\n";
					cout<<"\t "<<n<<" "<<i-n<<endl; 
					//对偶数 i 验证成功
					break; 
				} 
			}
		}
		//如果上面的循环体结束后,i==n则对i没有验证成功 
		if(i==n){
			cout<<"Error: "<<i<<endl; 
		} 
	}
} 

//验证猜想_3
void function_3(void){
	//我们可以申请一个表
	int* list=(int*)malloc(sizeof(int)*(2001));//第1个空间不使用
	int i=2;
	for(i=2;i<=1999;++i){
		if(judge(i)){
			list[i]=1;
		}else{
			list[i]=0;
		}
	}
	//进行验证
	int n;
	for(i=4;i<=2000;i+=2){//从4开始验证 
		//将i分解为两个数、这两个数的和等于i
		for(n=2;n<=i/2;n++){//最小的素数为2、从2开始遍历 
			//判断n是否为素数
			if(list[n]&&list[i-n]){//n为素数 
				cout<<i<<":\n";
				cout<<"\t "<<n<<" "<<i-n<<endl; 
				//对偶数 i 验证成功
				break; 
			}
		}
		//如果上面的循环体结束后,i==n则对i没有验证成功 
		if(i==n){
			cout<<"Error: "<<i<<endl; 
		} 
	}
	//释放申请的内存空间
	free(list); 
} 
int main(int argc,char**argv){
	function_1();
	//可见验证猜想是成功的
	//怎样进一步优化算法
	//(1)偶数的分解存在重复
	/*
	i=4 (2*,2) |(3,1)
	i=6 (2,4) (3*,3) (4,2) |(5,1)
	i=8 (2,6) (3,5) (4*,4) (5,3) (6,2) |(7,1)
	有规律可见，除最后一项、从i/2开始出现对称性重复 
	而且最后一项我们会发现、1不是素数。所以我们可以完全不验证最后一项 
	*/
	function_2();
	//可见我们也完美的进行了验证
	
	//怎样再优化?
	//我们可以知道、judge函数调用了不少次呢？
	//而且judge函数作用被重复调用
	function_3(); 
	cout<<"Donald Ervin Knuth 说 \"程序是蓝色的诗!\""<<endl;
	cout<<"持之以恒地学习，没有什么是学不会的，行动起来，没有什么不可以。"; 
	cout<<"趁着年轻加油吧小伙子！实现自己地梦想、而不是将来的上班下班吃饭睡觉上班下班......";
	return 0;
}
