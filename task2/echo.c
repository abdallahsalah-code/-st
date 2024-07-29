#include<stdio.h>

void echo(char*args[],int argc){
for(int i=1;i<=argc;i++){
printf("%s ",args[i]);
}
}
