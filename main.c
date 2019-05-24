/***************************************************************************************************************************************************
 *Author		:Emertxe(http://www.emertxe.com)
 *Date		:Mon 22 May 2017 14:00:05 IST
 *File		:main.c
 *Title		:Driver function
 *Description	:This function acts like the driver function for the project inverted search
 ****************************************************************************************************************************************************/
#include "main.h"

int main()
{
	hashtable *head[SIZE] = {NULL};
	char word[100], filename[20];
	FILE *file1;
	char ch,str[10];
	char buff[10];
	int option, i = 0,x,flag=1;
	int count;
	while (1)
	{
		printf("Select the option\n1.Create Database\n2.Print Databse\n3.Search database\n4.Save Database\n5.Quit\n");
		scanf("%d", &option);
		switch (option)
		{
			case 1:
				printf("Enter the file name\n");
				scanf("%s", filename);
				if (error_check(head, filename) == SUCCESS)
				{
						printf ("File already inserted in database\n");
						putchar('\n');
						break;
				}
				else
				{
				file1 = fopen(filename, "r");
				if(file1 == NULL)
				{
					perror("fopen");
					printf("enter the correct file name\n");
					return 0;
				}	
				while(fscanf(file1,"%s",buff)!=EOF)
				{
					printf("%s\n",buff);	
					if (buff[0] >='A' && buff[0] <='Z')
					{
						x = buff[0] - 'A';
					}
					if (buff[0] >= 'a' && buff[0] <= 'z')
					{
						x = buff[0]-'a';
					}
					create_database(&head[x%SIZE],buff,filename);
				}
				}
				break;
			case 2:
				for (i=0; i<SIZE;i++)
				{
					print_ht(head[i]);
				}
				break;
			case 3:
				printf ("Enter search string: ");
				scanf ("%s", str);
				if (str[0] >='A' && str[0] <='Z')
				{
					x = str[0] - 'A';
				}
				if (str[0] >= 'a' && str[0] <= 'z')
				{
					x = str[0]-'a';
				}
				if (search(head[x%SIZE],str) == SUCCESS)
				{
					printf ("DATA FOUND\n");
				}
				else
				{
					printf ("DATA NOT FOUND\n");
				}
				break;
			case 4:
				printf ("Enter output file: ");
				scanf ("%s", str);
				for (i = 0; i < SIZE; i++)
				{
					save_db(head[i],str);
				}
				break;
			default:
				return 0;
				break;
		}
	}

}

