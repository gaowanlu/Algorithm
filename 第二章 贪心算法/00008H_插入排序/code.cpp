#include<iostream>
using namespace std;
const int MAX=1000;
int list[MAX];
//贪心策略：从没有插入过的元素找一个，插入到有序列中，且使其称为有序列
/*
步骤解析
   0 1 2 3 4 5
例:5 2 4 6 1 3
i=1 x=2 j=0
x=2 < 5

0 1 2 3 4 5 
5 5 4 6 1 3
j-1 j=-1
list[i+1=0]=x

0 1 2 3 4 5
2 5 4 6 1 3

i=2
j=1
x=4
4<5
0 1 2 3 4 5
2 5 5 6 1 3
j=0 2<4
0 1 2 3 4 5
2 4 5 6 1 3
.
.
.
.

*/

void insertSort(int *list,int start,int end){
    //1个元素默认有序
    //从第二个元素，向前找位置
    for(int i=start+1;i<=end;i++){
        int x=list[i];//先将要找插入位置的数据暂存
        int j=i-1;//j 要找插入位置的数据前一个数据位置
        while(j>=start&&x<list[j]){
            list[j+1]=list[j];
            j-=1;
        }
        list[j+1]=x;
    }
}
void printList(int n){
    cout<<"array[]={";
    for(int i=0;i<n;i++){
        cout<<" "<<list[i];
        if(i!=n-1){
            cout<<",";
        }
    }
    cout<<" }\n";
}
int main(void){
    int n;
    cout<<"请输入数列的元素个数n\n";
    cin>>n;
    cout<<"请输入数据\n";
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    printList(n);
    //调用插入排序算法
    insertSort(list,0,n-1);
    cout<<"sorted\n";
    printList(n);
    return 0;
}