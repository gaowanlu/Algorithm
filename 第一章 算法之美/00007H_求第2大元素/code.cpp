/*
求第k大元素
算法思想:
(1) 顺序比较
    顺序比较找出最大元素
    从剩下的n-1个元素中找到最大，就是第2大元素
(2) 锦标赛算法
    两两分组，大者进入下一轮
    每个元素用数表记录每次比较时小于自己的元素，最后得出最大的数，最大数小于它的哪一个为第2大元素
*/
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
int list[MAX];
int FindMax(int*list,int s,int e){
    if(e<=s){//只有一个元素
        return list[s];
    }
    int max,lmax;
    max=list[s];
    lmax=list[s];
    for(int i=s;i<=e;i++){
        if(max<list[i]){
            lmax=max;
            max=list[i];
        }
    }
    return lmax;
}
int main(void){
    int n;
    memset(list,0,sizeof(list));
    cout<<"输入元素个数\n";
    cin>>n;
    cout<<"输入元素\n";
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    for(int i=0;i<n;i++){
        cout<<list[i]<<" ";
    }
    cout<<"lmax="<<FindMax(list,0,n-1)<<endl;
    return 0;
}
