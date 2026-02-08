#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LINES 9889

int main(void)
{
	FILE *book;
	book = fopen("aeneid.txt", "r");
	if (book == NULL) {
		printf("Error: Unable to open book!");
	}
	srand((unsigned int)time(NULL));
	int randLine = rand() % NUM_LINES;
	char buffer[128];
	for (int i=0; i<=randLine; i++) {
		if (fgets(buffer, 128, book) == NULL) {
			printf("Error reading line %d", i);
			return 1;
		}
	}
	printf("%s", buffer);
	fclose(book);
	return 0;
}
