#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
// printf("parse start\n");
 char command_cpy[8096];
// printf("command_cpy declaration\n");
 strcpy(command_cpy, command);
// printf("strcpy\n");

 int n = 0;
 char *ptr;
 
 ptr=strtok(command_cpy, " \n\t");
// printf("strtok\n");

 argv[0] = (char**)malloc(sizeof(char*)*10);
 for(int i=0; i<10; i++)
 {
  argv[0][i] = (char*)malloc(sizeof(char)*100);
 }
// printf("malloc ok\n");

// printf("while start\n");
 
 while(ptr != NULL)
 {
//  printf("while do\n");
  strcpy(argv[0][n], ptr);
//  printf("string cpy\n");
  n++;
  ptr = strtok(NULL, " \n\t");
 }
// printf("while end\n");
 *argc = n;
 if(*argc<=0)
 {
  *argc = 1;
  strcpy(argv[0][0],"");
 }
 // TODO: Fill this!
}
