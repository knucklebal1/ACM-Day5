#include<iostream>
using namespace std;
const int N=10;
int n,a[N];

void dfs(int cnt,int st,int sum){//cnt 选了几个数；st 从哪个数开始；sum 这些初始的和
	if(sum>n) return;
	if(sum==n){
		for(int i=1;i<=cnt-1;++i){
			if(i==1) cout<<a[i];
			else cout<<'+'<<a[i];
		}
		cout<<'\n';
		return;
	}
	for(int i=st;i<=n-1;++i){
		a[cnt]=i;
		dfs(cnt+1,i,sum+i);//cnt+1 选择了下一个数；i 下一个数从i来选（避免重复组合）；sum+i 当前的和
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	dfs(1,1,0);
	return 0;
}
