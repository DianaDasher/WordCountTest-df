#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    FILE *fp;
    int tool = 0;
    int i; 
    if((fp=fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if(argv[1][1] =='w') // 单词个数 
    {
        char s[1024];
        int x;
        while (fscanf(fp,"%s",s) != EOF)
        {
            tool ++;
            for (i=1;i<strlen(s)-1; i++)
                if (s[i]==','&&s[i-1]!=','&&s[i+1]!=',') 
                {
                    tool ++;
                }
        }
        printf("单词数=%d\n",tool);
    }
    else if(argv[1][1] == 'c') // 字符个数 
    {
        char c;
        while ((c = fgetc(fp)) != EOF) 
        {
		 tool ++;
	    }
        printf("字符数=%d", tool);
    }
    fclose(fp);
    return 0;
}

