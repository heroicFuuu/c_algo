#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	// struct site
	// {
	// 	char name[] = "GeeksforGeeks";// can't assign value
	// 	int no_of_pages = 200;// can't assign value
	// };

    
	// struct site *ptr;
	// printf("%d",ptr->no_of_pages);
	// printf("%s",ptr->name); 
	// getchar();

    struct site
	{
		char name[20];
		int no_of_pages; 
	};
    char *words = "GeeksforGeeks";
    struct site *ptr = malloc(sizeof(struct site));

    memcpy(ptr->name, words, strlen(words)+1);
    ptr->no_of_pages = 200;

    printf("%d\n", ptr->no_of_pages);
    printf("%s\n", ptr->name);
    




	return 0;
}

