#include<iostream>
#include<queue>
using namespace std;
const int N=190;
int n,m;
int dis[N][N];//存0到达1最短距离
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};//向上下左右移动
char gr[N][N];//存01矩阵 因为数字间无空格所以用字符数组存储
int new_x,new_y;
void bfs(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,y});//入队
	while(q.size()){
		pair<int,int> now=q.front();//取队头
		q.pop();//出队
		int a=now.first,b=now.second;
		for(int i = 0;i<=3;i++){//向四个方向移动
			new_x=a+dx[i];
			new_y=b+dy[i];
			if(new_x>=1&&new_x<=n&&new_y>=1&&new_y<=m&&gr[new_x][new_y]=='0'&&dis[new_x][new_y]>dis[a][b]+1){
				//判断是否越界 是否能走 是否得更短距离
				dis[new_x][new_y]=dis[a][b]+1;//距离+1
				q.push({new_x,new_y});//入队
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			cin >> gr[i][j];
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			dis[i][j]=1e6;//初始化 因为是求最小值，如果不初始化数值不会改变
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(gr[i][j]=='1'){
				dis[i][j]=0;
				bfs(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(gr[i][j]=='1') cout<<0<<' ';//如果是‘1’那么本身就是白色色块
			else cout<<dis[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
