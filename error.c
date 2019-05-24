#include "main.h"

int error_check(hashtable **head, data_t *str)
{
	int i;
	for (i=0;i<SIZE;i++)
	{
		if (head != NULL)
		{
			hashtable *temp = *head;
			while (temp)
			{
				sl_file_table *temp1 = (temp)->file_table;
				while (temp1)
				{
					if (strcmp(temp1->file_name,str) == 0)
					{
						return SUCCESS;
					}
					temp1 = (temp1)->tab_link;
				}
				temp = (temp)->link;
			}	
		}
	}
	return FAILURE;
}
