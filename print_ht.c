#include "main.h"

void print_ht(hashtable *head)
{
	if (head != NULL)
	{
		hashtable *temp = head;
		while (temp)
		{
			printf ("word->%s\tfile count: %d\n", (temp)->word, (temp)->file_count);
			sl_file_table *temp1 = (temp)->file_table;
			while (temp1)
			{
				printf ("	filename: %s\tword count: %d\n", (temp1)->file_name, (temp1)->word_count);
				temp1 = (temp1)->tab_link;
			}
			temp = (temp)->link;
			putchar('\n');
		}
	}
}
