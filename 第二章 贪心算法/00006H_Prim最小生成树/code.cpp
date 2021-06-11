/*Create by Wanlu Gao
* 2021/1/21 
* ʵ�ֹ���:
* �ڴ˳�����ʵ�ֵ�Ϊ�ڽӾ���洢ͼPrim��С������
*/
#include<iostream>
#include<cstdlib>
using namespace std;
//��������
const int INF=9999; 
//�洢ͼ�Ķ����� 
const int map_dot_num=7;
//��ʼ���ڽӾ���
const int map[map_dot_num][map_dot_num]={
{INF,23,INF,INF,INF,28,36},
{23,INF,20,INF,INF,INF,1},
{INF,20,INF,15,INF,INF,4},
{INF,INF,15,INF,3,INF,9},
{INF,INF,INF,3,INF,17,16},
{28,INF,INF,INF,17,INF,25},
{36,1,4,9,16,25,INF}};

//�������ܣ�����ڽӾ��� 
void PrintMap(void){
	int i,j;
	cout<<"Map:\n";
	for(i=0;i<map_dot_num;i++){
		cout<<"\t";
		for(j=0;j<map_dot_num;j++){
			if(map[i][j]==INF)
				cout<<" INF";
			else
				cout<<" "<<map[i][j];
		}
		cout<<endl;
	} 
}
int main(int argc,char**argv){
	int i=0,j=0;
	//����ڽӾ���
	PrintMap();
	//���弯������
	int s[map_dot_num]={0};//{0}��ʾs����Ϊ�ռ�
	//�������
	int start=0; 
	//����lowcost����
	int lowcost[map_dot_num]={INF};
	//��ʼ��closest����
	int closest[map_dot_num]={0};
	//���������0����s����
	s[start]=1;
	//��ʼ��lowcost������closest����
	for(i=0;i<map_dot_num;i++){
		if(i!=start){
			lowcost[i]=map[i][start];
			closest[i]=start; 
		}else{
			//����lowcost
			lowcost[i]=0; 
		}
	}
	//ʹ��Prim������С������Ҫmap_dot_num-1ѡ��С��
	for(i=1;i<map_dot_num;i++){
		//��lowcostѡһ����v-s���Ҿ���s��С��Ŀ��
		int target=start;
		int temp=INF;
		for(j=0;j<map_dot_num;j++){
			if(j!=start&&s[j]==0&&temp>lowcost[j]){
				temp=lowcost[j];
				target=j;
			}
		}
		if(target==start){
			break;//û���ҵ�Ŀ�� 
		}
		//����s����
		s[target]=1;
		//����lowcost��closest����
		for(j=0;j<map_dot_num;j++){
			if(j!=start&&s[j]==0&&lowcost[j]>map[target][j]){
				lowcost[j]=map[target][j];
				closest[j]=target;
			}
		} 
	}
	//���lowcost����
	cout<<"lowcost[]:\n\t";
	for(i=0;i<map_dot_num;i++){
		cout<<" "<<lowcost[i];
	}
	//���closest����
	cout<<"\nclosest[]:\n\t";
	for(i=0;i<map_dot_num;i++){
		cout<<" "<<closest[i];
	}	
	return 0;
}
 
