#include<iostream>
using namespace std;
const int N=1e3+5;
int n;
int mp[N][N];//二维数组存图
int vis[N][N];//访问数组  
int dx[9]={0,-1,-1,-1,0,0,1,1,1};
int dy[9]={0,-1,0,1,-1,1,-1,0,1};//相邻的八个点
int ans1,ans2,flag;//山峰，山谷,标记（1为山谷，2为山峰，-1啥也不是） 
int nx,ny;
void dfs(int x,int y){
	for(int i=1;i<=8;i++){//搜索相邻的八个点 
		nx=x+dx[i];
		ny=y+dy[i];
		if(!(nx>=1&&nx<=n&&ny>=1&&ny<=n)) continue;//越界，跳过 
		else if(mp[x][y]==mp[nx][ny]&&vis[nx][ny]==0){//没去过，搜一下 
			vis[nx][ny]=1;
			dfs(nx,ny);	
		}else if(mp[x][y]<mp[nx][ny]&&flag==2){ 
			flag=-1;
		}else if(mp[x][y]>mp[nx][ny]&&flag==1){//与本来状态冲突，即，啥也不是 
			flag=-1;
		}else if(flag==0){//赋初始状态，是山峰还是山谷 
			if(mp[x][y]>mp[nx][ny])flag=2;
			if(mp[x][y]<mp[nx][ny])flag=1;
		}
	}
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
		}
	}
	int x=mp[1][1];
	flag=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]!=x){
				flag=0;
				break;
			}
		}
		if(flag==0)break;
	}
	if(flag==1){
		cout<<"1 1";
		return 0;//特判，所有高度相同，既是山峰也是山谷，各为1 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				flag=0;
				vis[i][j]=1;
				dfs(i,j); 
				if(flag==2)ans1++;
				if(flag==1)ans2++;
			}
		}
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
