/*
 *     File Name: 1611.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年09月10日 星期六 11时42分10秒
 */

#include<stdio.h>
#include<string.h>

#define MAX 30010

int father[MAX];
int son[MAX];

/* 根据人数设置相应的数组 */
/* 这里自己还是写错了， 令father[i] = i,
 * son[i] = 1; 说明自身算一个
 * */
void u_set(int n)
{
	int i;
	for(i = 0; i < n; i++){
		father[i] = i;
		son[i] = 1;
	}

}

/* 查找算法  */
int find(int x)
{
	int r = x;
	while(r != father[r])
		r = father[r];

		int i, j = x;
		while(r != father[j]){
			i = father[j];
			father[j] = r;
			j = i;
		}


		return r;	
	

	//return (x == father[x] ? x : find(father[x]));

}
/* Note here, union is keyword in c */
void Union(int x, int y)
{
	int xroot = find(x);
	int yroot = find(y);
	
	if(xroot < yroot){
		father[yroot] = xroot;
		son[xroot] += son[yroot];
	}
	else  if (yroot < xroot){
		father[xroot] = yroot;
		son[yroot] += son[xroot];

	}

}
int main()
{
	freopen("1611.in", "r", stdin);
	int n, m, k;
	int i;
	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0)
			break;
		memset(son, 0x00, sizeof(son));
		memset(father, 0x00, sizeof(father));
		/* 设置人数 here, 初始化并查集  */
		u_set(n);
		int l;
		while(m--){
			/* k is 每个组的成员数 */
			scanf("%d %d", &k, &l);

			/* 这一步的处理真聪明*/
			int i ;
			int tmp;
			for( i = 1; i < k; i++){
				scanf("%d", &tmp);
				Union(l, tmp);
			}


		};
		printf("%d\n", son[father[0]]);


	}
	return 0;
}
