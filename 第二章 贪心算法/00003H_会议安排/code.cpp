//会议时间表
//会议       1   2   3   4   5   6   7   8   9   10
//开始时间   8   9   10  11  13  14  15  17  18  26  
//结束时间   10  11  15  14  16  17  17  18  20  19
//贪心策略：局部最优解，选择结束最早的
//相容且最早结束
#include<iostream>
using namespace std;
struct Meeting{
	int num;//会议序号 
	float start;//会议开始时间 
	float end;//会议结束时间
	int flag;//记录是否被选中 
};
void printMeeting(struct Meeting*meet,int n){
	int i=0;
	if(!meet||n<=0){
		return;
	}
	for(i=0;i<n;i++){
		printf("DATA:%d:\n",meet[i].num);
		printf("\tstart:%f\n",meet[i].start);
		printf("\tend:%f\n",meet[i].end);
		printf("\tflag:%d\n",meet[i].flag);
	}
} 
int main(int argc,char**argv){
	int i=0,j=0;
	//建立数组存储会议信息
	struct Meeting meet[10]={
		{1,8,10,0},
		{2,9,11,0},
		{3,10,15,0},
		{4,11,14,0},
		{5,13,16,0},
		{6,14,17,0},
		{7,15,17,0},
		{8,17,18,0},
		{9,18,20,0},
		{10,16,19,0}
	};
	//信息输出
	printMeeting(meet,10);
	//我们既然要选择结束最早的，那么我们最好以end将meet进行排序,以便操作
	//在此为了，便于操作数据较少，采用了冒泡排序
	//如果对时间复杂度要求严格，可改进排序算法
	for(i=0;i<10;i++){
		for(j=0;j<10-i-1;j++){
			if(meet[j].end>meet[j+1].end){
				struct Meeting temp=meet[j];
				meet[j]=meet[j+1];
				meet[j+1]=temp;
			}
		}
	}
	//排序后输出
	printf("进行排序后\n");
	printMeeting(meet,10);
	//存储可利用时间段信息
	int time_start=8,time_end=20;
	//开始进行贪心选择
	int now=time_start;//记录可以用时间段的开始时间
	for(i=0;i<10;i++){
		if(meet[i].start>=now&&meet[i].end<=time_end){
			meet[i].flag=1;//选中
			now=meet[i].end;//更新now 
		}else if(meet[i].end>time_end){
			break;
		} 
	}
	//输出会议安排序列
	printf("会议序列为:\n");
	for(i=0;i<10;i++){
		if(meet[i].flag){
			printf("\t%d",meet[i].num);
		}
	} 
	//可见会议安排问题的解并不唯一,当多个会议的end相同
	//且都相容时，我们对其不同选择，会产生不同的结果
	//此题还可能为:1 4 7 8 9 ,同样有5个会议
	//我们可以将一些会议加上权重值，进而解决这种问题 
	return 0;
} 
