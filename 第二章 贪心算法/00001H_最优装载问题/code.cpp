#include<iostream>
using namespace std;
//�������ܣ�ð������ 
void BubbleSort(int*list,int n){
	int i=0,j=0;
	bool flag=0;
	for(i=0;i<n;++i){
		flag=0;
		for(j=0;j<n-i-1;++j){
			if(list[j]>list[j+1]){
				flag=1;
				int temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp; 
			}
		}
		if(!flag){
			break;
		}
	}
}
int main(int argc,char**argv){
	int weight[8]={4,10,7,11,3,5,14,2};//�Ŷ��嵥 
	//������Ҫ�ڹŶ��嵥ÿ��̰��ѡ��ѡ�������
	//�����ǽ�����зǵݼ�����ȽϺ�
	//�ڴ�Ϊ��д����ȽϷ��桢ʹ��ð������	
	BubbleSort(weight,8);
	//���������֤
	int i;
	cout<<"weight:\n";
	for(i=0;i<8;i++){
		cout<<"\t"<<weight[i]<<endl;
	}
	int max=0,sum=0;
	cout<<"�������봬������:";
	cin>>max;
	//��ʼ����̰��ѡ��
	cout<<"�����Դ�����������Ϊ:\n";
	for(i=0;i<8;i++){
		if(sum+weight[i]<=max){
			cout<<"\t"<<weight[i]<<endl;
			sum+=weight[i];
		}else{
			break;
		}
	} 
	cout<<"���ߵ�������Ϊ:\n";
	cout<<"\t"<<sum<<endl;
	return 0;
}


