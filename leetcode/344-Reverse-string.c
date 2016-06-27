/*
 *     File Name: 344-Reverse-string.c
 *     Author: Bo Yu
 *     Mail: tsu.yubo@gmail.com
 *     Created Time: 2016年06月27日 星期一 08时24分06秒
 */
#include<stdio.h>
#include<string.h>
char* reverseString(char* s){
	int i = strlen(s) - 1;
	if(i >= 0){
		char* str = (char*)malloc(strlen(s) + 1);
		do{
			*str = s[i];
			str++;
		}while(i--);
		*str = '\0';
		str = str - strlen(s);
		s = str;
	}
	return s;
}
int main(){
	char* str = "hello,wrold";
	char* res = reverseString(str);
	printf("%s\n",res);
}
