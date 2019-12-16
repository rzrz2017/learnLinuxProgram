#include <stdio.h>
#include <iconv.h>

#include "simple_list.h"
#include "double_linklist.h"
#include "parser.h"


#define file_path "/home/rz/share/456/1234.lrc"

//typedef long unsigned int  size_t;

int main(int argc, char *argv[]){
	FILE *fp = NULL;
	char buff[255] = {0};
	char c;

	pElem list;
	list = CreatList();
	
	fp = fopen(file_path,"r");

	printf("strlen: %d\n",strlen(buff));
	printf("sizeof: %d\n",sizeof(buff));
	
	int j = 0;
	int time = 0;
	char text[256] = {0};
	
	while(fgets(buff, sizeof(buff), (FILE*) fp)){
		printf("buff = %s\n", buff);
		parse(buff, &time, text);
		insertElemTail(list, time, text);
	}

	printf("strlen(buff) = %d\n",strlen(buff));

	printf("------便利链表:------\n");
	IlluList(list);	

	fclose(fp);
	return 0;
}

int UTF8toGBK(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
	iconv_t cd;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open("gbk","utf-8");//gb2312
	if(0 == cd)
		return -1;
	if(-1 == iconv(cd, pin, &inlen, pout, &outlen))
	{
		iconv_close(cd);
		return -1;
	}

	iconv_close(cd);
	return 0;
}


