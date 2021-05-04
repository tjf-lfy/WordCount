// WordCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int charCount = 0; //�ַ���
	int wordCount = 0; //������
	FILE* fp;
	char* fileName;
	char ch;
	int word=0; //���

	fileName = argv[2]; //�ļ�·��

	if(strcmp(argv[1],"-c")==0) //���Ʋ���Ϊ"-c"�����
	{
		if ((fp = fopen(fileName,"r")) == NULL)
		{
			printf("Fail to open the file!\n");
            exit(-1);
		}
        while((ch = fgetc(fp))!=EOF)
		{
		    charCount++;
		}
		printf("%d",charCount);
	}
	else if(strcmp(argv[1],"-w")==0)//���Ʋ���Ϊ"-w"�����
	{
		if ((fp = fopen(fileName,"r")) == NULL)
		{
			printf("Fail to open the file!\n");
            exit(-1);
		}
		while((ch = fgetc(fp))!=EOF)
		{
			if(ch==' ' || ch==',')
			{
				word = 0;
			}
			else if(word==0)
			{
				word = 1;
				wordCount++;
			}
		}
		printf("%d",wordCount);
	}
	fclose(fp);
	return 0;
}

