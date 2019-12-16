#include <stdio.h>
#include <string.h>
#include "parser.h"

static int isDigit(char c);
static int isLetter(char c);

int parse(char* text, int* time, char lyric[])
{
	char *buff;
	buff = strrchr(text, ']');
	//printf("buff = %s\n", buff+1);
	strcpy(lyric,buff+1);
	printf("lyric = %s\n",lyric);

	char buff2[16] = {0};
	char *left,*right;
	int n;
	int num = 0;
	int i;
	left = strchr(text, '[');
	if(left == NULL){
		return -1;
	}
	right = strchr(text, '.');
	
	int c;
	if(right != NULL && left != NULL){
		n = right - left -1;
		strncpy(buff2,left+1,n);
		printf("time = %s\n",buff2);
		for(i = 1;i < n+1;i++){
			c = *(left + i);
#if 1
			if(i == 1){
				if(isDigit(*(left + i))){
					num += atoi(&c)*600;		
				}	
			}else if(i == 2){
				if(isDigit(*(left + i))){
					num += atoi(&c)*60;
				}
			}else if(i == 4){
				if(isDigit(*(left + i))){
					num += atoi(&c)*10;
				}
			}else if(i == 5){
				if(isDigit(*(left + i))){
					num += atoi(&c);
				}
			}				
#endif
		}
		*time = num;
		printf("time num = %d\n",num);
	}

	return 0;
}

static int isDigit(char c){
	return (c >= '0' && c <= '9');
}

static int isLetter(char c){
	return ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'));
}
