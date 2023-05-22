#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* str;

	str = (char*)malloc(sizeof(char) * 13);
	str = "Hello world!";

	printf("free Àü : %s\n", str);
	free(str);
	printf("free ÈÄ : %s\n", str);
	return (0);
}