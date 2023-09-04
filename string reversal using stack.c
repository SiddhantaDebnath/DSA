#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 50
char stk[Max];
int top=-1;
void push(char c){
	top=top+1;
	stk[top]=c;
}
char pop(){
	return stk[top--];
}
int main(){
	char str[Max],revstr[Max];
	int i,len;
	printf("Enter a string:");
	scanf("%[^\n]s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	push(str[i]);
	for(i=0;i<len;i++)
		revstr[i]=pop();
	printf("Reversed string:");
	for(i=0;i<len;i++)
	 printf("%c",revstr[i]);	
}

