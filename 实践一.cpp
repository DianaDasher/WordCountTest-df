#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    FILE *fp;
    int sum= 0; 
    int i; 
    char choose; 
    if((fp=fopen(argv[2], "r"))== NULL)
    {
        puts("文件打开失败!\n");
        return 0;
    }  //判断文件是否成功打开 
    choose=argv[1][1];
    
    if(choose=='w') // 若在命令行输入w则统计单词个数 
    {
        char word[10000];    
        while ((fscanf(fp,"%s",word))!= EOF)
        {
            sum++;
            int l=strlen(word)-1;
            for (i=1;i<l; i++)
                if (word[i-1]!=','&&word[i]==','&&word[i+1]!=',') 
                {
                    sum++;
                }//若字符i为逗号，他的前后字符都不是逗号，则是一个单词 
        }
        printf("单词数=%d\n",sum);
    }
    else if(choose== 'c') // 若在命令行输入c则字符个数 
    {
        char c;
        while ((c=fgetc(fp))!= EOF) 
        {
		 sum++;
	    }
        printf("字符数=%d",sum);
    }
    else
    {
    	printf("参数输入错误，请输入w统计单词数或c统计字符数！");
	}
    fclose(fp);//关闭文件 
    return 0;
}

