#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "file_utils.h"

/**
* This class takes an input file,
* reverses it's contents and puts the
* updated contents into an output file
*
* @author Alec Allain
* @version 9/8/18
*/

/** Insanciated methods */
int read_file (char* filename, char** buffer);
int write_file (char* filename, char* buffer, int fileSize);

/** Global variables */
//FILE* file;
char* buffer;
char* fileName;
char* outFile;
int size;
int secondSize;

/**
* Main method
*/
int main (int argc, char** argv) {

    // Instanciating variables
    fileName = argv[1];
    outFile = argv[2];
    buffer = malloc(100 * sizeof(char));

    // Only stops program if no files are detected when running a.out
    if (fileName == NULL || outFile == NULL) {
	fprintf(stderr, "Please enter an input and output file name to begin the program\n");
	exit(0);
    }

    printf("\nCurrently reading file...");

    // The input file is read and size of read file is returned 
    size = read_file(fileName, &buffer);

    // The output file is written and 0 is returned
    secondSize = write_file(outFile, buffer, size);

    printf("\nA new file called \"%s\" has been created\n\n", outFile);

    //file = fopen(argv[0], "r");

    // Frees up allocated memory
    free(buffer);

    return secondSize;
}
