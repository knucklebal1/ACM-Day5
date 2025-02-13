#include<iostream>
using namespace std;
const int N=30;
int Vitamin[N][N],Need[N];
//两个数组分别是饲料各维他命含量，牛所需维他命量
int visit[N],Anvisit[N],ans=5000;
//visit用来存放当前饲料编号，Anvisit存放答案的饲料编号
//ans存放答案数量，初始值为一个比较大的数
int v=0,g=0;
bool ok(int x){
	//该函数用来判断当前情况下是否已满足需求
	//x是已投喂的饲料总数
	if (!x)return false;
	//如果一种饲料都没加直接pass
	for (int i=1;i<=v;++i){
		int sum=0;
		for (int j=1;j<=x;++j)
			sum+=Vitamin[visit[j]][i];
		//累加，算出每种维生素的含量
		if (sum<Need[i])return false;
		//一旦出现有一种含量小于需求的直接false
	}
	return true;
}
void dfs(int number,int count){
	//number为饲料编号，count为饲料总数，这样设置参数可以很大程度上避免思考得过于复杂
	if(number>g)
		return;
	//边界
	if(ok(count)){//如果满足条件
		if(count<ans) {//并且新答案比原答案小
			ans=count;
			for(int i=1;i<=count;++i) Anvisit[i]=visit[i];
			//更新答案
		}
		return;
		//使命完成，直接返回，不需要再向下执行
	}
	visit[count+1]=number+1;
	//准备访问，先打标记
	dfs(number+1,count+1);
	//访问下一种饲料并加入
	visit[count+1]=0;
	//访问结束，消除标记
	dfs(number+1,count);
	//访问下一种饲料但不加入
}
int main(){
	cin>>v;
	for (int i=1;i<=v;++i)
		cin>>Need[i];
	cin>>g;
	for (int i=1;i<=g;++i){
		for (int j=1;j<=v;++j) cin>>Vitamin[i][j];
	}	
	dfs(0, 0);
	//注意从编号零开始搜索，因为编号一也要搜索加或者不加两条路
	cout<<ans<<' ';
	for (int i=1;i<=ans;++i)
		cout<<Anvisit[i]<<' ';
	return 0;
}
