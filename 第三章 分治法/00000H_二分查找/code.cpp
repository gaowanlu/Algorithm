#include<iostream>
#include<algorithm>
using namespace std;
struct Data{
	int flag;
};
bool compare(struct Data a,struct Data b){
	return a.flag<b.flag;
}
//二分查找(迭代)
int BinarySearch(int size,struct Data *list,int flag){
	//定义low、high、middle
	int low=0,high=size-1;
	while(low<=high){
		int middle=(low+high)/2;
		if(list[middle].flag==flag){
			return middle;
		}else if(flag<list[middle].flag){
			//更新low与high
			high=middle-1; 
		}else{
			low=middle+1;
		}
	}
	return -1;//没有找到 
}

//二分查找(递归)
int recursionBS(int low,int high,struct Data*list,int flag){
	//判定条件
	if(low>high){
		return -1;//没找到 
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
	//将数据根据flag进行非递减排序 
	sort(list,list+10,compare);
	//输出
	cout<<"list flag:\n\t["; 
	for(int i=0;i<10;i++){
		cout<<list[i].flag;
		if(i==9){
			cout<<"]\n";
		}else{
			cout<<",";
		}
	}
	//测试
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
