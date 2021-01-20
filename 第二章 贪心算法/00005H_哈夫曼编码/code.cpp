//哈夫曼树及其编码 
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
//定义节点抽象数据结构
struct HuffNode{
	float weight;//节点权重 
	int parent;//节点的父节点下标 
	int lchild;//节点的左孩子下标 
	int rchild;//节点的右孩子下标 
	char value;//节点的值 
}; 
typedef struct HuffNode HuffNode;

//打印哈夫曼树信息
void PrintHuffTree(HuffNode*HuffTree,int node_num){
	int i;
	cout<<"HuffTree:\n";
	for(i=0;i<2*node_num-1;++i){
		cout<<"\t"<<HuffTree[i].weight<<" ";
		cout<<HuffTree[i].parent<<" ";
		cout<<HuffTree[i].lchild<<" ";
		cout<<HuffTree[i].rchild<<" ";
		cout<<HuffTree[i].value<<"\n"; 
	}
} 

//哈夫曼编码
void PrintHuffCode(HuffNode*HuffTree,int root,vector<char>&HuffCode){
	//每次递归到左孩子为-1,右孩子为-1就输出编码
	if(HuffTree[root].lchild!=-1||HuffTree[root].rchild!=-1){//没有遇见叶子节点 
		//遍历左子树
		HuffCode.push_back('0');
		PrintHuffCode(HuffTree,HuffTree[root].lchild,HuffCode);
		//遍历右子树
		HuffCode.push_back('1');
		PrintHuffCode(HuffTree,HuffTree[root].rchild,HuffCode);
		//遍历完左子树与右子树后，要将为root节点的编码位删除
		HuffCode.erase(HuffCode.end()-1); 
	}else{//遇到叶子节点 
		cout<<HuffTree[root].value<<":\n\t";
		int i;
		for(i=0;i<HuffCode.size();i++){
			cout<<HuffCode[i];
		}
		cout<<endl;
		//输出root节点编码后,将为root节点的编码位删除 
		HuffCode.erase(HuffCode.end()-1); 
	} 
	return;
}

int main(int argc,char**argv){
	//存储要编码的信息个体数量 
	const int node_num=6;
	//则我们共需要2*node_num-1个节点，因为构建的HuffTree共有node_num个节点
	//使用动态内存申请
	struct HuffNode*HuffTree=(struct HuffNode*)malloc(sizeof(struct HuffNode)*(2*node_num-1));
	if(!HuffTree) return -1;//内存申请失败
	//初始化哈夫曼树原始数据
	int i;
	for(i=0;i<2*node_num-1;++i){
		HuffTree[i].weight=0;
		HuffTree[i].parent=-1;
		HuffTree[i].lchild=-1;
		HuffTree[i].rchild=-1;
	} 
	float weight[node_num]={5,32,18,7,25,13};
	char value[node_num]={'a','b','c','d','e','f'};
	//权值以及节点数据初始化
	for(i=0;i<node_num;++i){
		HuffTree[i].weight=weight[i];
		HuffTree[i].value=value[i];
	} 
	//输出初始化后的哈夫曼树
	PrintHuffTree(HuffTree,node_num);
	
	//开始构建哈夫曼树
	//一共需要node_num-1次合并
	for(i=0;i<node_num-1;i++){
		//找两个最小权重且父节点下标为-1的两个节点
		//遍历找到最大权重
		int j;
		float max_weight=-1;
		for(j=0;j<node_num+i;j++){
			if(max_weight<HuffTree[j].weight){
				max_weight=HuffTree[j].weight;
			}
		} 
		float weight_1=max_weight+1,weight_2=max_weight+1;//存储两个节点的权重
		int index_1=-1,index_2=-1;//存储两个符合要求的节点的下标
		for(j=0;j<node_num+i;j++){//找两小 
			if(HuffTree[j].weight<weight_1&&HuffTree[j].weight<weight_2&&HuffTree[j].parent==-1){//比次小与最小都小 
				weight_2=weight_1;
				index_2=index_1;
				weight_1=HuffTree[j].weight;
				index_1=j;
			}else if(HuffTree[j].weight<weight_2&&HuffTree[j].parent==-1){//比次小小 
				weight_2=HuffTree[j].weight;
				index_2=j;
			}
		} 
		//构建新节点
		HuffTree[index_1].parent=node_num+i;//更新两最小节点的父节点
		HuffTree[index_2].parent=node_num+i;
		//更新新节点权值
		HuffTree[node_num+i].weight=weight_1+weight_2;
		HuffTree[node_num+i].lchild=index_1;//最小 
		HuffTree[node_num+i].rchild=index_2;//次小 
		
	} 
	//输出哈夫曼树信息
	PrintHuffTree(HuffTree,node_num);
	//输出哈夫曼编码(采用递归方法)
	vector<char>huff_code;
	cout<<"HuffCode:\n";
	PrintHuffCode(HuffTree,2*node_num-2,huff_code);
	 
	
	//释放哈夫曼树内存
	free(HuffTree); 
	return 0;
} 
