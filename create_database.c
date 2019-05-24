#include "main.h"

int create_database(hashtable **head1, data_t *string, data_t *filename)
{
	if (*head1 == NULL)
	{
		hashtable *new = malloc(sizeof(hashtable));
		sl_file_table *f_table = malloc(sizeof(sl_file_table));

		f_table->word_count = 1;
		strcpy(f_table->file_name,filename);
		f_table->tab_link = NULL;

		new->file_count = 1;
		strcpy(new->word,string);
		new->link = NULL;
		new->file_table = f_table;

		*head1 = new;
		return SUCCESS;
	}
	else
	{
		hashtable *ptr = *head1;
		hashtable *ptr1;
		while (ptr)
		{
			if (strcmp(string,(ptr)->word) == 0)
			{
				sl_file_table *temp = (ptr)->file_table;
				sl_file_table *temp1;
				while (temp)
				{
					if(strcmp((temp)->file_name,filename) == 0 )
					{
						(temp)->word_count++;
						return SUCCESS;
					}
					temp1 = temp;
					temp = temp->tab_link;
				}
				sl_file_table *f_table = malloc(sizeof(sl_file_table));

				f_table->word_count = 1;
				strcpy(f_table->file_name,filename);
				f_table->tab_link = NULL;
	
				temp1->tab_link = f_table;
				ptr->file_count++;

				return SUCCESS;
			}
			ptr1 = ptr;
			ptr = ptr->link;
		}
		hashtable *new = malloc(sizeof(hashtable));
		sl_file_table *f_table = malloc(sizeof(sl_file_table));

		f_table->word_count = 1;
		strcpy(f_table->file_name,filename);
		f_table->tab_link = NULL;

		new->file_count = 1;
		strcpy(new->word,string);
		new->link = NULL;
		new->file_table = f_table;

		ptr1->link = new;
		return SUCCESS;
	}
}
