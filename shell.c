#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shell.h>

int main() {
  printf("Please type command:");

  int x=1;
  while(x) {
    char *in = prompt();
    char *l = readline(in);
    x = checkLine(l);  
  }
  return 0;
}

int checkLine(char *l) {
  int x = 1;
  char *n = l;
  char * lineArr[15];
  
  for(int i = 0; (lineArr[i] = strsep( &n, ";")); i++); 
  for(int j = 0; line[j]; j++) {
    x = x && runCmd( lineArr[j] );
  }
  return x;
}

int runCmd(char *cmd) {
  char *n = cmd;
  char * c[100];
  if(!strlen(cmd) return 1;
  
  c[strlen(c)-1] = 0; //terminating null in string
    int n = 0;
  while(holder){
    command[n] = strsep(&holder," ");
    n++;
  }
  command[n] = 0; //terminating null in array

  int s;
  int f = fork();
  if(f==0) {
    execvp(command[0], command);
  }
  else{
    wait(&s);
  }
  }
  return 0;
}
