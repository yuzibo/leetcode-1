/*
 *     File Name: 367.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年06月30日 星期四 10时37分55秒
 */

/**
 *	思路： 一开始我使用的枚举，结果说我运行超时，肯定是
 *	效率不高
 *	@1: 牛顿迭代法目前还没有掌握，那个求一个的平方根比较简单
 *	但是如何呢；
 *	@2： 使用二分法 L = 1. R = num/2 + 1;
 *
 *
 *
 */
#include<stdio.h>
bool isPerfectSquare(int num){
	long long  L = 1, R = (num >> 1) + 1;
	while(L <= R){
		long long middle = L + (R - L)/2;
		long long value = middle * middle;
		if(value == num)
			return true;
		else if(value > num)
			R = middle - 1;
		else
			L = middle + 1;

	}
	return false;



}
int main(){
	int a;
	scanf("%d",&a);
	if(isPerfectSquare(a))
		printf("yes");
	else
		printf("No\n");
}
