/*问题引入
 *工厂最大收益--单纯形算法
 *某工厂共有3个加工车间、第1个车间用1个单位的原料N可以加工出5个单位的A或2个单位的产品B
 *产品A直接出售、售价为10元。
 *产品B直接出售、售价为16元。
 *如果在第2车间继续加工产品A,要额外加工费5元、加工后售价为19元。
 *如果在第3车间继续加工产品B,要额外加工费4元、加工后售价为24元。
 *原料N的单位购入价为5元。
 *每工时工资为15元。
 *第1车间加工一个单位N需要0.05个工时。
 *第2车间加工一个单位需要0.1个工时。
 *第3车间加工一个单位需要0.08工时。
 *每个月最多可以得到12000单位的原料N。
 *工时最多为1000工时。
 *如何安排生产，才能使得工厂的收益最大呢？
 * */
/*问题分析
 * x1:卖出A x2:卖出二次加工的A x3:卖出的B x4:卖出二次加工的B x5:第1车间共使用原料N的总单位
 *目标函数:max z=10*x1+12.5*x2+16*x3+18.8*x4-5.75*x5
 *约束条件:
 *x1+x2-5*x5=0
 *x3+x4-2*x5=0
 *x5<=12000
 *0.1*x2+0.08*x4+0.05*x5<=1000
 *xi>=0(i=0,1,2,3,4,5)
 *
 *
 *转化为标准型
 *max z=10*x1+12.5*x2+16*x3+18.8*x4-5.75*x5
 *
 *
 *x1+x2-5*x5=0
 *x3+x4-2*x5=0
 *x5+x6=12000
 *0.1*x2+0.08*x4+0.05*x5+x7=1000
 *xi>=0(i=1,2,3,4,5,6,7)
 *
 *基本变量：x1\x3\x6\x7
 *非基本变量:x2\x4\x5
 *
 *目标函数由非基本变量表示
 *x1=5*x5-x2  x3=2*x5-x4
 *目标函数:max z=2.5*x2+2.8*x4+76.25*x5
 * */
#include<iostream>
#include<math.h>
using namespace std;
float kernel[100][100];//存储非单纯形表
char FJL[100]={};//非基本变量
char JL[100]={};//基本变量
int m,n;//m:非基本变量的个数 n:基本变量的个数

void print();//打印表
void DCXA();//单纯形算法

int main(void){
    cout<<"请输入非基本变量的个数与非基本变量的下标\n";
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>FJL[i];
    }
    cout<<"请输入基本变量个数与非基本变量的下标\n";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>JL[i];
    }
    cout<<"请输入约束标准型初始单纯形表参数\n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin>>kernel[i][j];
        }
    }
    print();
    DCXA();
    return 0;
}


//打印表
void print(){
    cout<<"单纯形表\n";
    cout<<"       b ";
    for(int i=1;i<=n;i++){
        cout<<"      x"<<FJL[i];
    }
    cout<<"\n";
    cout<<"c ";
    for(int i=0;i<=n;i++){
        if(i>=1){
            cout<<"x"<<JL[i];
        }
        for(int j=0;j<=m;j++){
            cout<<"      "<<kernel[i][j]<<" ";
        }
        cout<<"\n";
    }

}


//单纯形算法
void  DCXA(){
    float max1;//存放最大检验数
    float max2;//存放最大正检验数对应的基本变量的最大系数
    int enter=-1;//入基变量下标
    int quit=-1;//离基变量下标
    float min=0;
    while(1){//循环迭代直到找到解或者确定无解
        max1=0;
        max2=0;
        min=100000000;
        //算法步骤1：寻找入基变量(检验数最大的那一列) 目标函数系数最大
        for(int i=1;i<=m;i++){
            if(max1<kernel[0][i]){
                max1=kernel[0][i];
                enter=i;
            } 
        }
        //算法步骤2：判断最优解情况
        //如果所有检验数<=0,则满足最优解条件
        if(max1<=0){
            cout<<"获得最优解: "<<kernel[0][0]<<"\n";
            print();
            return;//停止求解
        }
        //如果正检验数对应的列都小于等于0,则无界
        for(int j=1;j<=m;j++){
            max2=0;
            if(kernel[0][j]>0){//检验数为正
                for(int i=1;i<=n;i++){
                    if(max2<kernel[i][j]){
                        max2=kernel[i][j];
                    }
                }
                if(max2==0){
                    cout<<"解无界\n";
                    return;//停止求解
                }
            }
        }

        //算法步骤3:找离基行(常数列/入基列正比值最小对应的行)
        for(int i=1;i<=n;i++){
            float temp=kernel[i][0]/kernel[i][enter];
            if(temp>0&&temp<min){
                min=temp;
                quit=i;
            }
        }

        //算法步骤4:变基变换
        char temp=FJL[enter];
        FJL[enter]=JL[quit];
        JL[quit]=temp;


        //算法步骤5:计算新的单纯形表
        for(int i=0;i<=n;i++){
            if(i!=quit){
                for(int j=0;j<=m;j++){
                    if(j!=enter){
                        if(i==0&&j==0){//[0,0]位置
                            kernel[i][j]=kernel[i][j]+kernel[i][enter]*kernel[quit][j]/kernel[quit][enter];
                        }else{//一般位置
                            kernel[i][j]=kernel[i][j]-kernel[i][enter]*kernel[quit][j]/kernel[quit][enter];
                        }
                    }
                }
            }
        }

        //入基列的元素
        for(int i=0;i<=n;i++){
            if(i!=quit){
                kernel[i][enter]=-kernel[i][enter]/kernel[quit][enter];
            }
        }
        //离基行的元素
        for(int i=0;i<=m;i++){
            if(i!=enter){
                kernel[quit][i]=kernel[quit][i]/kernel[quit][enter];
            }
        }
        //交叉位置
        kernel[quit][enter]=1.0/kernel[quit][enter];
        
        print();
    } 
}


