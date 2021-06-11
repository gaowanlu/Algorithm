/*
算法：最优搜索二叉树(动态规划法)
编码人员:高万禄
日期:2021/3/13
*/

#include<iostream>
#include<cstdlib>
#include<cmath>


//输入N
int scanfN(void){
    int temp;
    std::cin>>temp;
    if(temp>0){
        return temp;
    }else{//异常
        return 0;
    }
}

//申请一维表
double * getP(int *N){
    double *P=NULL;
    P=(double*)malloc(sizeof(double)*(*N+1));
    if(!P)std::cout<<"Error:malloc NULL\n";
    return P;
}

//输入P数组
double * scanfP(int *N){
    //输入实节点的概率,下标0位置不使用
    double *P=getP(N);
    //输入P
    std::cout<<"CIN P Array:\n";
    for(int i=1;i<=*N;i++){
        std::cin>>P[i];
    }
    //输出P
    std::cout<<"P[]:\n";
    for(int i=1;i<=*N;i++){
        std::cout<<P[i]<<"\t";
    }
    std::cout<<"\n";
    return P;
}

//输入Q数组
double * scanfQ(int*N){
    double *Q=NULL;
    Q=getP(N);//申请数组
    std::cout<<"CIN Q Array\n";
    for(int i=0;i<=*N;i++){
        std::cin>>Q[i];
    }
    //输出Q
    std::cout<<"Q[]:\n";
    for(int i=0;i<=*N;i++){
        std::cout<<Q[i]<<"\t";
    }
    std::cout<<"\n";
    return Q;
} 

//申请W表
double** getW(int*N){
    double **W=NULL;
    W=(double**)malloc(sizeof(double*)*(*N+2));
    for(int i=0;i<=*N+1;i++){
        *(W+i)=(double*)malloc(sizeof(double)*(*N+1));
    }
    return W;
}

//申请S表
int** getS(int*N){
    int **W=NULL;
    W=(int**)malloc(sizeof(int*)*(*N+2));
    for(int i=0;i<=*N+1;i++){
        *(W+i)=(int*)malloc(sizeof(int)*(*N+1));
    }
    return W;
}

//动态规划求最优二叉搜索树
void Optimal_BST(double *P,double*Q,double**W,double **C,int **S,int*N){
    //初始化W数组与C数组,因为涉及到递归式求解，第一步求解就要用递归式，但以前还没有可利用的，必须初始化
    for(int i=1;i<=*N+1;i++){
        C[i][i-1]=0.0f;
        W[i][i-1]=Q[i-1];
    }
    //从几个实节点规模树选根节点（规模）
    for(int t=1;t<=*N;t++){
        //从下标[i,j]选出最优的那个根节点
        for(int i=1;i<=*N-t+1;i++){
            int j=i+t-1;
            //涉及到迭代求最小问题，需要现进行初始化最小，再迭代求最小,默认选i做根
            W[i][j]=W[i][j-1]+P[j]+Q[j];
            C[i][j]=C[i][i-1]+C[i+1][j];
            S[i][j]=i;//[i,j]实节点规模树,存储选中的根节点
            //根节点向后迭代选出最优根
            for(int k=i+1;k<=j;k++){
                double temp=C[i][k-1]+C[k+1][j];
                if(temp<C[i][j]&&fabs(temp-C[i][j])>1E-6){//后者条件为二者不相等
                    C[i][j]=temp;//迭代最优根
                    S[i][j]=k;
                }
            }
            C[i][j]+=W[i][j];
        }
    }
}


void PrintResult(double **W,double **C,int **S,int *N){
    //打印W
    std::cout<<"_________________________________________\n";
    std::cout<<"W[][]:\n";
    for(int i=1;i<=*N+1;i++){
        for(int j=0;j<=*N;j++){
            std::cout<<W[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    std::cout<<"_________________________________________\n";
    //打印C
    std::cout<<"C[][]:\n";
        for(int i=1;i<=*N+1;i++){
        for(int j=0;j<=*N;j++){
            std::cout<<C[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    std::cout<<"_________________________________________\n";
    //打印S
    std::cout<<"S[][]:\n";
        for(int i=1;i<=*N+1;i++){
        for(int j=0;j<=*N;j++){
            std::cout<<S[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}

void freeP(double*P,int*N){
    free(P);
}
void freeQ(double*Q,int*N){
    free(Q);
}
void freeS(int**S,int*N){
    for(int i=0;i<=*N+1;i++){
        free(S[i]);
    }
    free(S);
}
void freeW(double**W,int*N){
    for(int i=0;i<=*N+1;i++){
        free(W[i]);
    }
    free(W);
}
void freeC(double**C,int*N){
    for(int i=0;i<=*N+1;i++){
        free(C[i]);
    }
    free(C);
}

//主函数
int main(int argc,char**argv){
    int N;//使用N来存储实节点的个数
    //输入N
    N=scanfN();
    double *P=scanfP(&N);//存储实节点概率;下标[1,N]
    double *Q=scanfQ(&N);//存储虚节点概率;下标[0,N]
    //申请W表与C表,关于W表与C表详情请看main函数下面的文字描述
    double **W=getW(&N);
    double **C=getW(&N);
    int **S=getS(&N);
    Optimal_BST(P,Q,W,C,S,&N);//最优二叉树求解
    PrintResult(W,C,S,&N);
    freeP(P,&N);freeQ(Q,&N);freeS(S,&N);freeC(C,&N);freeW(W,&N);
    return 0;
}

/*
q0    p1    q1    p2   q2   p3   q3     p4    q4   p5   q5   p6   q6
0.06  0.04  0.08  0.09 0.1  0.08 0.07   0.02  0.05 0.12 0.05 0.14 0.1
W表:
例如W[1][4]:代表从p1 <-> p4:0.06+0.04+0.08+0.09+0.1+0.08+0.07+0.02+0.05
W[][]利用动态规划思想递归式：
W[i][j]=W[i][j-1]+P[j]+Q[j]

C表存储子树的搜索成本
C[i][j]=min{  C[i][k-1]+C[k+1][j]+W[i][j] }
        i<=k<=j
C[i][j]:代表实节点为P[i,j]的子树情况,故要在i<=k<=j之间选择代价最小的一个根节点
C[i][k-1]：为左子树代价
C[K+1][j]: 为右子树代价
W[i][j]: 为整棵树代价

那么代价不是加重复了吗?
    没错，你想对了?我们要的就是重复的效果，为什么呢?
    我们可以看一个简单的二叉搜索树:
0        5              二叉搜索树的搜索成本:
        / \             实节点:(节点深度+1)*概率
1      e   9            虚节点:(节点深度)*概率
          / \               
2        e   12
            /  \
3          e    15

    这么以看，就是需要重复着加起来，才能满足要求
计算公式:
      n                          n
    累加 (depth(S[i])+1)*P[i] + 累加 depth(E[i])*Q[i]
     i=1                        i=0


程序样例
6
CIN P Array:
0.04 0.09 0.08 0.02 0.12 0.14
P[]:
0.04    0.09    0.08    0.02    0.12    0.14
CIN Q Array
0.06 0.08 0.1 0.07 0.05 0.05 0.1
Q[]:
0.06    0.08    0.1     0.07    0.05    0.05    0.1
_________________________________________
W[][]:
0.06    0.18    0.37    0.52    0.59    0.76    1
0       0.08    0.27    0.42    0.49    0.66    0.9
0       0       0.1     0.25    0.32    0.49    0.73
0       0       0       0.07    0.14    0.31    0.55
0       0       0       0       0.05    0.22    0.46
0       0       0       6.95294e-310    0       0.05    0.29
0       0       0       0       0       0       0.1
_________________________________________
C[][]:
0       0.18    0.55    0.95    1.23    1.76    2.52
0       0       0.27    0.67    0.9     1.38    2.09    
0       0       0       0.25    0.46    0.94    1.48
3.59837e-013    3.50594e+064    1.7113e+059     0       0.14    0.45    0.98
0       0       0       0       0       0.22    0.68
0       0       0       0       0       0       0.29
0       0       0       0       0       0       0
_________________________________________
S[][]:
0       1       2       2       2       3       5
0       0       2       2       3       3       5
0       0       0       3       3       3       5
0       0       0       0       4       5       5
0       0       0       0       0       5       6
0       0       0       0       0       0       6
0       0       0       0       0       0       0





//构造最优解
_________________________________________
S[][]:
  0       1       2       3       4       5      6
_________________________________________________
1|0       1       2       2       2       3       5
2|0       0       2       2       3       3       5
3|0       0       0       3       3       3       5
4|0       0       0       0       4       5       5
5|0       0       0       0       0       5       6
6|0       0       0       0       0       0       6
7|0       0       0       0       0       0       0
//从S数组内可以构造最优解
先看S[1][6]左上角,即5
则1-6规模树，根为5
            5
        /       \
    1 2 3 4      6
S[1][4]=2
            5
          /  \
         2    6
        /\
       1  34
S[3][4]=3
            5
          /  \
         2    6
        /\
       1  3
           \ 
            4
则最优搜索二叉树为
            5
          /  \
         2    6
        /\
       1  3
           \ 
            4
*/