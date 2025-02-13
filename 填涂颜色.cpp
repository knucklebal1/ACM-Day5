#include<iostream>
using namespace std;
const int N=40;
int a[N][N],n;
int dtx[4]={0,1,0,-1};
int dty[4]={1,0,-1,0};

void dfs(int x,int y){
	a[x][y]=3;//将外围的0染色成3
	int new_x,new_y;
	for(int i=0;i<4;++i){
		new_x=x+dtx[i];
		new_y=y+dty[i];
		//注意边界扩大条件是扩大后的方阵边界
		if(new_x>=0&&new_x<=n+1&&new_y>=0&&new_y<=n+1&&a[new_x][new_y]==0){
			dfs(new_x,new_y);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	dfs(0,0);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]==3) cout<<0<<' ';
			else if(a[i][j]==1) cout<<1<<' ';
			else cout<<2<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
