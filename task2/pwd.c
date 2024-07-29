#include<stdio.h>
#include<unistd.h>
void pwd(){
char msg[1000];
char*path= msg;
getcwd(msg,sizeof(msg));
printf("cwd:%s \n",msg);
return ;
}

