/*************************************************************************
     File Name: poj2251two.cpp
     Author: yubo
     Mail: yuzibode@126.com 
     Created Time: 2014年05月30日 星期五 05时11分28秒
     学习重点:三维迷宫，重点是那个queue的应用，自己学了不少东西！加油！
3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

 ************************************************************************/

#include<cstring>
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int L,R,C;
int S_x,S_y,S_z;
char maze[40][40][40];//标记地图
int dir[6][3]={
	-1,0,0,1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1,
};//三维方向的数组，仔细想一想
int vis[40][40][40];
typedef struct{
	int x,y,z;
	int depth;//
}SE;
int judge(int x,int y,int z)//自己写的
{
	if(x>=0 && x<L && y>=0 && y<R && z>=0 && z<C)
		return 1;
	else
		return 0;
}//简练的应用
int ans;
void bfs(int i,int j,int k)
{
	queue<SE> q;
	SE q0,q1,q2;
	q0.x=i;
	q0.y=j;
	q0.z=k;
	q0.depth=0;
	q.push(q0);
	while(!q.empty()){
		q1=q.front();//读取第一个元素要及时抛弃
		q.pop();
		for(int i=0;i<6;i++){
			int tmp1=q1.x+dir[i][0];
			int tmp2=q1.y+dir[i][1];
			int tmp3=q1.z+dir[i][2];
			if(judge(tmp1,tmp2,tmp3) && !vis[tmp1][tmp2][tmp3] && maze[tmp1][tmp2][tmp3]!='#')
			{
				if(maze[tmp1][tmp2][tmp3]=='E'){
					ans=q1.depth+1;
					return ;
				}
				q2.x=tmp1;
				q2.y=tmp2;
				q2.z=tmp3;
				q2.depth=q1.depth+1;
				vis[tmp1][tmp2][tmp3]=1;
				q.push(q2);
			}

		}
	}

}
int main()
{
	freopen("in.txt","r",stdin);
	char tmp;
	while(scanf("%d%d%d",&L,&R,&C)){
		if(!L&&!R&&!C)
			break;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<L;i++)
			for(int j=0;j<R;j++)
				for(int k=0;k<C;k++){
					cin>>maze[i][j][k];
					if(maze[i][j][k]=='S'){
						S_x=i;
						S_y=j;
						S_z=k;
					}
				}
		ans=-1;
		bfs(S_x,S_y,S_z);
		if(ans!=-1)//这里貌似有陷阱
			printf("Escaped in %d minute(s).\n",ans);
		else
			printf("Trapped!\n");
	}
	

}
