#include "main.h"

int search(hashtable *head, data_t *string)
{
	if (head != NULL)
	{
		hashtable *temp = head;
		while (temp)
		{
			if (strcmp(temp->word, string) == 0)
			{
			printf ("no of files: %d\n",(temp)->file_count);
			sl_file_table *temp1 = (temp)->file_table;
			while (temp1)
			{
				printf ("	filename: %s\tword count: %d\n", (temp1)->file_name, (temp1)->word_count);
				temp1 = (temp1)->tab_link;
			}
			return SUCCESS;
			}
			temp = (temp)->link;
		}
	}
	return DATA_NOT_FOUND;
}
