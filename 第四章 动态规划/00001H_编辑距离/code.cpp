//动态规划-编辑距离
 #include<iostream>
 #include<string>
 #include<cstdlib>
 using namespace std;

 int min(int a,int b,int c){
 	int temp=a<b?a:b;
 	temp=temp<c?temp:c;
 	return temp;
 } 
 int edit_distance(string&s1,string&s2,int**d){
 	//计算d数组元素
	for(int i=1;i<s1.size()+1;i++){
		for(int j=1;j<s2.size()+1;j++){
			//计算diff
			int diff=1;
			if(s1[i-1]==s2[j-1]){
				diff=0;
			} 
			//求d[i][j]
			d[i][j]=min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+diff);
		}
	}
	return d[s1.size()][s2.size()];
 }
 int main(int argc,char**argv){
 	cout<<"s1:	";
 	string s1;
 	cin>>s1;
 	cout<<"s2:	";
 	string s2;
 	cin>>s2;
 	cout<<"s1:	"<<s1<<endl;
 	cout<<"s2:	"<<s2<<endl;
 	//申请d数组
	int**d=(int**)malloc(sizeof(int*)*(s1.size()+1));
	for(int i=0;i<s1.size()+1;i++){
		*(d+i)=(int*)malloc(sizeof(int)*(s2.size()+1));
	} 
	//初始化d数组
	//第一行
	for(int i=0;i<s2.size()+1;i++){
		d[0][i]=i;
	} 
	//第一列
	for(int i=0;i<s1.size()+1;i++){
		d[i][0]=i;
	} 
 	//计算编辑距离
 	//即将s1编辑为s2 
	cout<<"编辑距离:	"<<edit_distance(s1,s2,d)<<endl;;
	//输出d数组
	cout<<"d[][]:\n";
	for(int i=0;i<s1.size()+1;i++){
		for(int j=0;j<s2.size()+1;j++){
			cout<<d[i][j]<<" ";
		} 
		cout<<"\n";
	}
	//释放d数组内存
	for(int i=0;i<s1.size();i++){
		free(*(d+i));
	} 
	free(d);
	return 0;
 }
