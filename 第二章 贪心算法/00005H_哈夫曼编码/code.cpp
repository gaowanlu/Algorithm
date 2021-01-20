//��������������� 
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
//����ڵ�������ݽṹ
struct HuffNode{
	float weight;//�ڵ�Ȩ�� 
	int parent;//�ڵ�ĸ��ڵ��±� 
	int lchild;//�ڵ�������±� 
	int rchild;//�ڵ���Һ����±� 
	char value;//�ڵ��ֵ 
}; 
typedef struct HuffNode HuffNode;

//��ӡ����������Ϣ
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

//����������
void PrintHuffCode(HuffNode*HuffTree,int root,vector<char>&HuffCode){
	//ÿ�εݹ鵽����Ϊ-1,�Һ���Ϊ-1���������
	if(HuffTree[root].lchild!=-1||HuffTree[root].rchild!=-1){//û������Ҷ�ӽڵ� 
		//����������
		HuffCode.push_back('0');
		PrintHuffCode(HuffTree,HuffTree[root].lchild,HuffCode);
		//����������
		HuffCode.push_back('1');
		PrintHuffCode(HuffTree,HuffTree[root].rchild,HuffCode);
		//����������������������Ҫ��Ϊroot�ڵ�ı���λɾ��
		HuffCode.erase(HuffCode.end()-1); 
	}else{//����Ҷ�ӽڵ� 
		cout<<HuffTree[root].value<<":\n\t";
		int i;
		for(i=0;i<HuffCode.size();i++){
			cout<<HuffCode[i];
		}
		cout<<endl;
		//���root�ڵ�����,��Ϊroot�ڵ�ı���λɾ�� 
		HuffCode.erase(HuffCode.end()-1); 
	} 
	return;
}

int main(int argc,char**argv){
	//�洢Ҫ�������Ϣ�������� 
	const int node_num=6;
	//�����ǹ���Ҫ2*node_num-1���ڵ㣬��Ϊ������HuffTree����node_num���ڵ�
	//ʹ�ö�̬�ڴ�����
	struct HuffNode*HuffTree=(struct HuffNode*)malloc(sizeof(struct HuffNode)*(2*node_num-1));
	if(!HuffTree) return -1;//�ڴ�����ʧ��
	//��ʼ����������ԭʼ����
	int i;
	for(i=0;i<2*node_num-1;++i){
		HuffTree[i].weight=0;
		HuffTree[i].parent=-1;
		HuffTree[i].lchild=-1;
		HuffTree[i].rchild=-1;
	} 
	float weight[node_num]={5,32,18,7,25,13};
	char value[node_num]={'a','b','c','d','e','f'};
	//Ȩֵ�Լ��ڵ����ݳ�ʼ��
	for(i=0;i<node_num;++i){
		HuffTree[i].weight=weight[i];
		HuffTree[i].value=value[i];
	} 
	//�����ʼ����Ĺ�������
	PrintHuffTree(HuffTree,node_num);
	
	//��ʼ������������
	//һ����Ҫnode_num-1�κϲ�
	for(i=0;i<node_num-1;i++){
		//��������СȨ���Ҹ��ڵ��±�Ϊ-1�������ڵ�
		//�����ҵ����Ȩ��
		int j;
		float max_weight=-1;
		for(j=0;j<node_num+i;j++){
			if(max_weight<HuffTree[j].weight){
				max_weight=HuffTree[j].weight;
			}
		} 
		float weight_1=max_weight+1,weight_2=max_weight+1;//�洢�����ڵ��Ȩ��
		int index_1=-1,index_2=-1;//�洢��������Ҫ��Ľڵ���±�
		for(j=0;j<node_num+i;j++){//����С 
			if(HuffTree[j].weight<weight_1&&HuffTree[j].weight<weight_2&&HuffTree[j].parent==-1){//�ȴ�С����С��С 
				weight_2=weight_1;
				index_2=index_1;
				weight_1=HuffTree[j].weight;
				index_1=j;
			}else if(HuffTree[j].weight<weight_2&&HuffTree[j].parent==-1){//�ȴ�СС 
				weight_2=HuffTree[j].weight;
				index_2=j;
			}
		} 
		//�����½ڵ�
		HuffTree[index_1].parent=node_num+i;//��������С�ڵ�ĸ��ڵ�
		HuffTree[index_2].parent=node_num+i;
		//�����½ڵ�Ȩֵ
		HuffTree[node_num+i].weight=weight_1+weight_2;
		HuffTree[node_num+i].lchild=index_1;//��С 
		HuffTree[node_num+i].rchild=index_2;//��С 
		
	} 
	//�������������Ϣ
	PrintHuffTree(HuffTree,node_num);
	//�������������(���õݹ鷽��)
	vector<char>huff_code;
	cout<<"HuffCode:\n";
	PrintHuffCode(HuffTree,2*node_num-2,huff_code);
	 
	
	//�ͷŹ��������ڴ�
	free(HuffTree); 
	return 0;
} 
