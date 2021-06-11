#include<iostream>
#include<algorithm>
using namespace std;
struct Data{
	int flag;
};
bool compare(struct Data a,struct Data b){
	return a.flag<b.flag;
}
//���ֲ���(����)
int BinarySearch(int size,struct Data *list,int flag){
	//����low��high��middle
	int low=0,high=size-1;
	while(low<=high){
		int middle=(low+high)/2;
		if(list[middle].flag==flag){
			return middle;
		}else if(flag<list[middle].flag){
			//����low��high
			high=middle-1; 
		}else{
			low=middle+1;
		}
	}
	return -1;//û���ҵ� 
}

//���ֲ���(�ݹ�)
int recursionBS(int low,int high,struct Data*list,int flag){
	//�ж�����
	if(low>high){
		return -1;//û�ҵ� 
	} 
	int middle=(low+high)/2;
	if(list[middle].flag==flag){
		return middle;
	}else if(flag<list[middle].flag){
		return recursionBS(low,middle-1,list,flag);
	}else{
		return recursionBS(middle+1,high,list,flag);
	}
}


 
int main(int argc,char**argv){
	struct Data list[10]={{12},{32},{423},{54},{65},{42},{65},{34},{12},{76}};
	//�����ݸ���flag���зǵݼ����� 
	sort(list,list+10,compare);
	//���
	cout<<"list flag:\n\t["; 
	for(int i=0;i<10;i++){
		cout<<list[i].flag;
		if(i==9){
			cout<<"]\n";
		}else{
			cout<<",";
		}
	}
	//����
	cout<<"("<<12<<","; 
	cout<<BinarySearch(10,list,12)<<",";
	cout<<recursionBS(0,10-1,list,12)<<")"<<endl;
	cout<<"("<<423<<","; 
	cout<<BinarySearch(10,list,423)<<",";
	cout<<recursionBS(0,10-1,list,423)<<")"<<endl;
	cout<<"("<<65<<","; 
	cout<<BinarySearch(10,list,65)<<",";
	cout<<recursionBS(0,10-1,list,65)<<")"<<endl;	
	cout<<"("<<43<<","; 
	cout<<BinarySearch(10,list,43)<<",";
	cout<<recursionBS(0,10-1,list,43)<<")"<<endl;
	return 0;
}
