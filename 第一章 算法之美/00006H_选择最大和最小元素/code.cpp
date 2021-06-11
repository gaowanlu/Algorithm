/*
寻找最大和最小元素
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAX=100;
int list[MAX];
int main(void){
    int min,max,n;
    memset(list,0,sizeof(list));
    cout<<"请输入元素个数\n";
    cin>>n;
    cout<<"请输入元素\n";
    for(int i=0;i<n;i++){
        cin>>list[i];
    }
    min=list[0];
    max=list[1];
    for(int i=1;i<n;i++){
        if(min>list[i]){
            min=list[i];
        }
        if(max<list[i]){
            max=list[i];
        }
    }
    cout<<"min="<<min<<" max="<<max<<endl;
    return 0;
}
