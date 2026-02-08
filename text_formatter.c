//open the og file
//strip out bad characters line by line
//remove empty lines
//remove numbers
//print into formatted file
//close everything up
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

const char *books[] = {
	"book1",
	"book2",
	"book3",
	"book4",
	"book5",
	"book6",
	"book7",
	"book8",
	"book9",
	"book10",
	"book11",
	"book12"
};

int FormatBook(const char *inputFileName, FILE *outputFile);
void clean_line(char *src);

void clean_line(char *src) {
    char *dst = src;
    while (*src) {
        // Only keep characters that are NOT digits
        if (!isdigit((unsigned char)*src)) {
			*dst = *src;
			dst++;
        }
        src++;
    }
    *dst = '\0'; // Null-terminate the "new" shorter string
}

int FormatBook(const char *inputFileName, FILE *outputFile)
{
	FILE *inputFile = fopen(inputFileName, "r");
	if (inputFile == NULL) {
		printf("ERROR: Could not open %s", inputFileName);
		return 1;
	}
	char buffer[512];
	while (fgets(buffer, 512, inputFile)) {
		clean_line(buffer);
	if (buffer[0] != '\n' && buffer[0] != '\r' && buffer[0] != '\0') {
			fputs(buffer, outputFile);
		}
	}
	fclose (inputFile);
	return 0;
}

int main(void)
{
	int numBooks = sizeof(books) / sizeof(books[0]);
	char inName[32];
	char outName[32];
	int errorDetected = 0;
	FILE *outputFile = fopen("aeneid.txt", "w");
	if (outputFile == NULL) {
		printf("ERROR: Could not open aenied.txt");
		return 1;
	}
	for (int i=0; i<numBooks; i++) {
		sprintf(inName, "%s.txt", books[i]);
		if (FormatBook(inName, outputFile) != 0) {
			printf("ERROR: %s failed", inName);
			errorDetected = 1;
			break;
		}
	}
	fclose (outputFile);
	if (errorDetected > 0) {
		printf("Program exited with an error.");
	} else {
		printf("Program exited succesfully!");
	}
	return 0;
}
