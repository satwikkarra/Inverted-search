#include "main.h"

void save_db(hashtable *head, char *str)
{
	FILE *fp = fopen(str, "a");
	if (fp == NULL)
	{
		perror("fopen");
	}
	if (head != NULL)
	{
		hashtable *temp = head;
		while (temp)
		{
			fprintf (fp,"word->%s\tfile count: %d\n", (temp)->word, (temp)->file_count);
			sl_file_table *temp1 = (temp)->file_table;
			while (temp1)
			{
				fprintf (fp,"	filename: %s\tword count: %d\n", (temp1)->file_name, (temp1)->word_count);
				temp1 = (temp1)->tab_link;
			}
			temp = (temp)->link;
		}
	}
	fclose(fp);
}
