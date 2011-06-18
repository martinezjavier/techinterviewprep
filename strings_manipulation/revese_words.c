#include <stdio.h>
#include <string.h>

void reverse(char *);

int main(void)
{
	char string[] = "Hello World";

	reverse(string);

	printf("%s\n", string);
}

void reverse(char *string)
{
	int i, j;
	int l = strlen(string)-1;

	for (i = 0, j = l; i < j; i++, j--) {
		string[l+1] = string[i];
		string[i] = string[j];
		string[j] = string[l+1];
	}

	string[l+1] = '\0';
}

