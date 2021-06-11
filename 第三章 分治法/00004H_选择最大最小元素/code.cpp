/*
在第一章中，我们用迭代枚举求解了，寻找最大最小元素
学了分治思想算法，我们能否利用分治的思想
来解决，在数字序列中寻找 最大元素 与 最小元素呢
let's we get start
算法步骤
1 2 3 4 5
分为两部分
1 2                     3 4 5
min=1 max=2            3                  4 5
                    min=3 max=3        min=4  max=5
					       min=3  max=5
min=1 max=2               min=3   max=5
    result=> min=1 max=5
                     
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=100;
int list[MAX];

//分治算法之寻找最大和最小元素
void FindMaxMin(int *list,int s,int e,int *maxmin){
    if(e-s<=1){//两个元素时
        if(list[e]>list[s]){
            maxmin[0]=list[e];
            maxmin[1]=list[s];
        }else{
            maxmin[0]=list[e];
            maxmin[1]=list[s];
        }
        return;
    }else{
        /*从中间分开，left right 分为两部分 
        寻找两边的最小元素 与 最大元素
        经过比较再选出整体的最大元素与最小元素
        */
        int mid=(s+e)/2;
        int leftmaxmin[2];
        int rightmaxmin[2];
        FindMaxMin(list,s,mid,leftmaxmin);
        FindMaxMin(list,mid+1,e,rightmaxmin);
        //比较选出最大值
        if(leftmaxmin[0]<rightmaxmin[0]){
            maxmin[0]=rightmaxmin[0];
        }else{
            maxmin[0]=leftmaxmin[0];
        }
        //比较选出最小值
        if(leftmaxmin[1]<rightmaxmin[1]){
            maxmin[1]=leftmaxmin[1];
        }else{
            maxmin[1]=rightmaxmin[1];
        }
    }
}

int main(void){
    memset(list,0,sizeof(list));
    int maxmin[2];
    int n;
    cout<<"请输入元素个数n\n";
    cin>>n;
    cout<<"n="<<n<<endl;
    cout<<"请输入元素\n";
    for(int i=0;i<n;i++){
        scanf("%d",&list[i]);
    }
    cout<<"over input list\n";
    cout<<"list[]={";
    for(int i=0;i<n;i++){
        cout<<list[i]<<" ";
        if(i!=n-1){
            cout<<",";
        }
    }
    cout<<"}\n";
    FindMaxMin(list,0,n-1,maxmin);
    cout<<"max="<<maxmin[0]<<" min="<<maxmin[1]<<endl;
    return 0;
}
