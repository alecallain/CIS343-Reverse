#ifndef FILE_UTILS_H_INCLUDED
#define FILE_UTILS_H_INCLUDED

/**
 * This header file is used to instanciate the
 * methods used in the file_utils.c and reverse.c
 * files
 *
 * @author Alec Allain
 * @version 9/9/18
 */

int read_file (char* filename, char** buffer);

int write_file (char* filename, char* buffer, int fileSize);

#endif // FILE_UTILS_H_INCLUDED
