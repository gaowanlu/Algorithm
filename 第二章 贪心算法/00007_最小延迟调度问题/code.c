#include<stdio.h>
#define N 100

struct Comst{
    int id;//客户序号
    int T;//预计对客户的服务时间
    int D;//客户希望的服务结束时间
}comst[N];
int n;//输入客户总数量
int f[N];//记录每个客户的开始时间


//划分函数
int Partition(struct Comst r[],int low,int high){
    int i=low,j=high,pivot=r[low].D;
    while(i<j){
        while(i<j&&r[j].D>pivot){//向左扫描
            j--;
        }
        if(i<j){
            struct Comst temp=r[i];
            r[i]=r[j];
            r[j]=temp;
        }
        while(i<j&&r[i].D<=pivot){//向右扫描
            i++;
        }
        if(i<j){
            struct Comst temp=r[i];
            r[i]=r[j];
            r[j]=temp;
        }
    }
    return i;
}

//快速排序递归算法
void QuickSort(struct Comst R[],int low,int high){
    int mid;
    if(low<high){
        mid=Partition(R,low,high);//基准位置
        QuickSort(R,low,mid-1);//左区间快排
        QuickSort(R,mid+1,high);//右区间快排
    }
}

void printT_D(){
       printf("T[]:\n");
       for(int i=0;i<n;i++){
            printf("%d ",comst[i].T);
                             
       }
       printf("\nD[]:\n");
       for(int i=0;i<n;i++){
            printf("%d ",comst[i].D);                       
       }
       printf("\n");
}


//贪心法求解
void Result(){
    f[0]=0;
    for(int i=1;i<n;i++){
        f[i]=f[i-1]+comst[i-1].T;
    }
}



int main(void){
    printf("请输入客户的数量n\n");
    scanf("%d",&n);
    if(n>=N){
        printf("n过大\n");
        return -1;
    }
    printf("请输入每位客户的预计服务时长与客户希望服务结束的时间中间用空格隔开\n");
    for(int i=0;i<n;i++){
        comst[i].id=i;
        scanf("%d",&comst[i].T);
        scanf("%d",&comst[i].D);
    }
    //输出T[] 与 D[]
    printf("T[]:\n");
    for(int i=0;i<n;i++){
        printf("%d ",comst[i].T);
    }
    printf("\nD[]:\n");
    for(int i=0;i<n;i++){
        printf("%d ",comst[i].D);
    }
    printf("\n");

    printT_D();
    //排序使得D[0]<=D[1]<=D[2]<=...<=D[n-1],同时T[]跟随D[]排序
    //输出排序后的
    QuickSort(comst,0,n-1);
    printT_D();

    //贪心法求解
    Result();

    //输出解序列
    printf("\n\n\n贪心法求解为:\n");
    for(int i=0;i<n;i++){
        printf("%d-执行事件id:%d-开始执行时刻-%d\n",i,comst[i].id,f[i]);
    }
    return 0;
}
