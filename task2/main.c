#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include <errno.h>
#include <sys/stat.h>
void pwd();
void help();
void cdp(const char *src, const char *dst_dir, char *dst) {
    const char *base_name = strrchr(src, '/');
    base_name = base_name ? base_name + 1 : src;
    snprintf(dst, 256, "%s/%s", dst_dir, base_name);
}

int move(const char *src, const char *dest) {
    printf("Moving from '%s' to '%s'\n", src, dest);
    if (rename(src, dest) != 0) {
        perror("rename");
        return -1;
    }
    return 0;
}


void echo(char*argv[],int i);
int copy(const char*src,const char*dest);
int move();
// Function to remove newline character from the args
void remove_newline(char *str) {
    char *pos;
    
    if ((pos = strchr(str, '\n')) != NULL) {
        
        *pos = '\0';
    }}
int main(){
//varible declarition
	char command[100];
	ssize_t readsize;
	char *tkn;
	char str[100];
	const char *msg = "shobek-lobek>";
	char*args[1024];
	char newpath[1024];
	char newpath2[1024];
while(1){
// print our msg in terminal (stdout_1_)
int i=0;
write(1,msg,strlen(msg));
//store our line from terminal (stdin_0_) in the buffer commmand
	readsize = read(0,command,sizeof(command));
//get first token
	tkn=strtok(command," ");
while(tkn!=NULL){
	args[i]=tkn;
	/*strcpy(str,args[i]);
	if(str[  strlen( args[i] ) ]  ==  '\n'  ) {
		str[strlen(args[i])]='\0';
	}
	strcpy(args[i],str);*/
	remove_newline(args[0]);
	tkn=strtok(NULL," ");
	
	i++;		
	//printf("%lu   =%s",strlen(args[0]),args[0]);
		}
if(strcmp(args[0],"\n")==0) return 0;
else if(strcmp(args[0],"pwd")==0){
	pwd();

			    }

else if(strcmp(args[0],"help")==0){
	help();		
			   }

else if(strcmp(args[0],"echo")==0){
       echo(args,i-1);
      // for(int x=1;x<=i;x++){ printf("%s",args[x]);}
}

else if(strcmp(args[0],"copy")==0){
	struct stat path_stat;
       if(stat(args[2],&path_stat)==0){
       if(S_ISDIR(path_stat.st_mode)==1){
       cdp(args[1],args[2],newpath);
       args[2]=newpath;
       }}
       	copy(args[1],args[2]);         
                           }

else if (strcmp(args[0],"move")==0){
struct stat path_stat;
       if(stat(args[2],&path_stat)==0){
       if(S_ISDIR(path_stat.st_mode)==1){
       cdp(args[1],args[2],newpath2);
       args[2]=newpath2;
       }}
       move(args[1],args[2]);

}
else if (strcmp(args[0],"exit")==0){
	printf("goodbye\n");			
	exit(1);
	
				   }
else 
{
fprintf(stderr,"unknown:input \n");
errno=-1;
perror("error");
}


memset(command,0,sizeof(command));
memset(args,0,sizeof(args));

}
}
