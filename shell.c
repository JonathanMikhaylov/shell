#include "shell.h"

int main() {
  char c[100];

  int x = 1;
  while(x) {
    printf("Please type command:");
    fgets(c,99,stdin);
    char *l = c;
    x = runLine(l);  
  }
  return 0;
}

int runLine(char *l) {
  int x = 1;
  char *n = l;
  char * lineArr[15];
  
  int i;
  int j;
  for(i = 0; (lineArr[i] = strsep( &n, ";")); i++); 
  for(j = 0; lineArr[j]; j++) { x = x && runCmd( lineArr[j] );}
  return x;
}

int runCmd(char *cmd) {
  char *n = cmd;
  char c[100];
  if(!strlen(cmd)) return 1;
  
  int i = 0;
  char *hold = c;
  char *cmdArr[100];
  while(hold) {
    cmdArr[i] = strsep(&hold," ");
    i++;
  }
  cmdArr[i] = 0;

  if ( !strcmp("exit",cmdArr[0])) return 0;
  else if( !(strcmp("cd",cmdArr[0])) ) cdFunct(cmdArr[1]);
  else {
    int s;
    int f = fork();
    if(f==0) {
      execvp(cmdArr[0], cmdArr);
      exit(0);
    }
    else{
      wait(&s);
    }
  }
  return 1;
}

void cdFunct(char * t) {
  int e;
  if(t) e = chdir(t);
  else e = chdir(" ");
  if(e) printf("cd-ERROR: %s: %s \n\n", t, strerror(errno));
}
