#include<stdio.h>
#include<string.h>
#define BUFF 100
struct Accounts{
	int Role;
	int Count;
	char *AccountNo;
	char *UserName;
	char *Password;
};
void disp(struct Accounts *a1)
{
	printf("%s %s %s %d %d",a1[0].AccountNo,a1[0].UserName,a1[0].Password,a1[0].Role,a1[0].Count);
}

int main()
{
	struct Accounts a1[100],temp;
	int i=0;
	FILE *fp;
	fp = fopen("Files/AccountDetails.csv", "a+");
	if (fp == NULL)
	{
		printf("Failed to open Account Details");
	}
	else
	{
		char str[BUFF];
		fgets(str, BUFF, fp);
		while(fgets(str, BUFF, fp)!=NULL)
		{
			 a1[i].AccountNo=strtok(str,",");
			 a1[i].UserName=strtok(NULL,",");
			 a1[i].Password=strtok(NULL,",");
			 a1[i].Role=atoi(strtok(NULL,","));
			 a1[i].Count=atoi(strtok(NULL,"\n"));
			// printf("%s\n",strtok(str,","));
			// printf("%s\n",strtok(NULL,","));
			// printf("%s\n",strtok(NULL,","));
			// printf("%d\n",atoi(strtok(NULL,",")));
			// printf("%d\n",atoi(strtok(NULL,"\n")));
			 printf("%s %s %s %d %d\n",a1[0].AccountNo,a1[0].UserName,a1[0].Password,a1[0].Role,a1[0].Count);
			 i++;
		}
		fclose(fp);
	}
	//disp(a1);
}
