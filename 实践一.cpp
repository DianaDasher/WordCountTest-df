#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[])
{
    FILE *fp;
    int sum= 0;
    int i; 
    if((fp=fopen(argv[2], "r"))== NULL)
    {
        puts("�ļ���ʧ��!\n");
        return 0;
    }  //�ж��ļ��Ƿ�ɹ��� 
   
    if(argv[1][1] =='w') // ��������������w��ͳ�Ƶ��ʸ��� 
    {
        char word[10000];
        int x;
        
        while ((fscanf(fp,"%s",word))!= EOF)
        {
            sum++;
            int l=strlen(word)-1;
            for (i=1;i<l; i++)
                if (word[i-1]!=','&&word[i]==','&&word[i+1]!=',') 
                {
                    sum++;
                }//���ַ�iΪ���ţ�����ǰ���ַ������Ƕ��ţ�����һ������ 
        }
        printf("������=%d\n",sum);
    }
    else if(argv[1][1] == 'c') // ��������������c���ַ����� 
    {
        char c;
        while ((c=fgetc(fp))!= EOF) 
        {
		 sum++;
	    }
        printf("�ַ���=%d",sum);
    }
    fclose(fp);//�ر��ļ� 
    return 0;
}

