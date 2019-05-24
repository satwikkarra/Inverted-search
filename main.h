#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define FAILURE -1
#define EMPTY 5
#define DATA_NOT_FOUND -2
#define SUCCESS 0
#define SIZE 26
#define CREATE_DATABASE 1
#define DISPLAY_DATABASE 2
#define UPDATE_DATABASE 3
#define SEARCH 4
#define SAVE_DATABASE 5

typedef char data_t;

typedef struct fi_tab
{
	int word_count;
	char file_name[20];
	struct fi_tab *tab_link;
}sl_file_table;

typedef struct node
{
	int file_count;
	struct node *link;
	char word[100];
	struct fi_tab *file_table;
}hashtable;

//hashtable *head[SIZE] = {NULL};

int create_database(hashtable **head, data_t *string, data_t *filename);

void save_db(hashtable *head, char *str);

int search(hashtable *head, data_t *string);

void print_ht(hashtable *head);

int error_check(hashtable **head, data_t *str);

#endif

