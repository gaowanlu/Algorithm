#include<iostream>
using namespace std;
//��һ�ۿ�����������ô������װ��������Щ������
//���Ƕ���������̰�Ĳ��������

/*����:
 ����ɽ����n�ֱ��ÿ�ֱ�����һ������w����Ӧ��ֵv
 ë¿�����������ޣ�ֻ������m�����ı��һ�ֱ���ֻ������һ����
 ������Էָ��������ʹë¿���߱���ļ�ֵ����أ� 
 */
 
 //�ֲ����ţ�
 //ѡ���Լ۱����ı��� 
int main(int argc,char**argv){
	int i=0,j=0;
	//��������� 
	int w[10]={4,2,9,5,5,8,5,4,5,5};
	//����ļ�ֵ 
	int v[10]={3,8,18,6,8,20,5,6,7,15};
	//�Լ۱�
	float p[10]={0};
	//�����Լ۱�
	for(i=0;i<10;++i){
		p[i]=(float)v[i]/(float)w[i];
	}
	//������װ�����ƣ�����Ҳ���Լ۱Ƚ�������
	for(i=0;i<10;i++){
		for(j=0;j<10-i-1;j++){
			if(p[j]<p[j+1]){
				float temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				temp=w[j];
				w[j]=w[j+1];
				w[j+1]=temp;
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
	//�����֤
	for(i=0;i<10;i++){
		printf("p:%f\n",p[i]);
		printf("\tw:%d\tv:%d\n",w[i],v[i]);
	}
	//ë¿�ĳ�������
	float max=19.0;
	//��¼ë¿���ڵĳ����� 
	float now=0.0;
	//��¼���ߵļ�ֵ
	float sum=0.0;  
	//��ʼ̰��ѡ��
	for(i=0;i<10;i++){//����10�ֱ���
		if(now+w[i]<=max){//����װ 
			sum+=v[i];
			now+=w[i];
		}else{//ֻ��װ�벿�� 
			sum+=(max-now)*p[i];
			now+=max-now;
			break;
		}
	}
	//������ߵ��ܼ�ֵ
	printf("sum value is:\n\t%f\n",sum); 
	return 0;
} 
