#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/**
* This class defines the read and write
* methods for the reverse.c file
*
* @author Alec Allain
* @version 9/9/18
*/

/** Global variables */

/**
* This method reads the contents of a file
*
* @param filename is the name of the file
* @param buffer is allocated memory
*/
int read_file (char* filename, char** buffer) {

    // Opens new/exisiting input file
    FILE* file = fopen(filename, "r");

    // Determines size of the file
    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    // Reads the file
    fread(*buffer, size, 1, file);

    // Closes the currently open file
    fclose(file);

    // Size is returned for writing the file
    return size;
}

/**
* This method takes the contents of a previous
* file and puts them into a output file
*
* @param filename is the name of the file
* @param buffer is allocated memory
* @param fileSize is the size of the file
*/
int write_file (char* filename, char* buffer, int fileSize) {

    // Opens new/existing output file
    FILE* file = fopen(filename, "w");

    // Contents of the file are retrieved from previous
    // file are written into the output fiel
    for (int i = fileSize - 1; i >= 0; i--) {
        fwrite(buffer + i, sizeof(char), 1, file);
	//fprintf(file, "%s", buffer + i);
    }

    // Closes the currently open file
    fclose(file);

    // Returns standard exit procedure
    return 0;

}
