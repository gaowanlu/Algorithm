#include<iostream>
using namespace std;
//第一眼看背包问题怎么和最优装载问题有些相似呢
//它们都可以利用贪心策略来求解

/*问题:
 假设山洞有n种宝物，每种宝物有一定重量w和相应价值v
 毛驴运载能力有限，只能运走m重量的宝物，一种宝物只能拿走一样，
 宝物可以分割，怎样才能使毛驴运走宝物的价值最大呢？ 
 */
 
 //局部最优：
 //选择性价比最大的宝物 
int main(int argc,char**argv){
	int i=0,j=0;
	//宝物的重量 
	int w[10]={4,2,9,5,5,8,5,4,5,5};
	//宝物的价值 
	int v[10]={3,8,18,6,8,20,5,6,7,15};
	//性价比
	float p[10]={0};
	//计算性价比
	for(i=0;i<10;++i){
		p[i]=(float)v[i]/(float)w[i];
	}
	//与最优装载类似，我们也将性价比进行排序
	for(i=0;i<10;i++){
		for(j=0;j<10-i-1;j++){
			if(p[j]<p[j+1]){
				float temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	//输出验证
	for(i=0;i<10;i++){
		printf("p:%f\n",p[i]);
		printf("\tw:%d\tv:%d\n",w[i],v[i]);
	}
	//毛驴的承载能力
	float max=19.0;
	//记录毛驴现在的承重量 
	float now=0.0;
	//记录拉走的价值
	float sum=0.0;  
	//开始贪心选择
	for(i=0;i<10;i++){//共有10种宝物
		if(now+w[i]<=max){//还能装 
			sum+=v[i];
			now+=w[i];
		}else{//只能装入部分 
			sum+=(max-now)*p[i];
			now+=max-now;
			break;
		}
	}
	//输出拿走的总价值
	printf("sum value is:\n\t%f\n",sum); 
	return 0;
} 
