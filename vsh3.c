/*

 * This shows how input from the user can be broken down into individual
 * words / tokens.
 *
 * To understand this code, you must be *completely* convinced that a
 * "char *" variables does *not* store a string. Rather, it stores 
 * an address to memory location storing a character. If the value stored
 * at that memory location changes, but the "char *" value doesn't, then
 * it is the new contents at the memory location which appear, not the old.
 *
 * Important: strtok modifies the char array which is being tokenized.
 * If you need to keep the original string, then make a copy of it before
 * running strtok.
 */
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#define MAX_INPUT_LINE 70
#define MAX_NUM_TOKENS 10//10
void functionSS(char *preDir,char *cmdList[],int numCMD,char *stI,char *stO){	


        printf("\n\nsay----- something\n");
        //printf("%s\n",args[0]);////bin/ls
        //printf("%s\n",args[1]);
        //printf("%s\n",args[2]);
	char *secCMD=cmdList[1];
	char absPath[MAX_INPUT_LINE];
	strcat(absPath,preDir);
	strcat(absPath,"/");
	strcat(absPath,cmdList[0]);
	printf("the directory of first command is:%s\n",&absPath[1]);
	printf("the absPath:%c\n",absPath[1]);
	printf("The First command is :%s\n",cmdList[0]);
	printf("The Second command is :%s\n",secCMD);
	//printf("%s\n",args[0]);
	printf("its input file is :%s\n",stI);
        printf("its output file is :%s\n",stO);
	printf("the Number of commands are:%d\n",numCMD);
        int y;
        for(y=0;y<numCMD;y++){
                printf("The Collected cmd is :%s\n",cmdList[y]);
        }


        char *envp[] = { 0 };
 	char *args[]={&absPath[1],secCMD,0};
	printf("the First cmd in args:%s\n",args[0]);
	printf("the Second cmd in args:%s\n\n\n",args[1]);

	
	int pid,fd;
	int status;
	if (pid = fork()){
	    printf("Not even here?%s\n",stO);   
            if(stI==NULL&&stO==NULL){//CHILDREN's POWER START
            printf("child: about to start.!.111.\n");
            printf("%s\n",args[0]);
                }
	else if(stO!=NULL&&stI==NULL){
            	printf("child: about to start.!.222.\n");
		fd = open(stO, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
        	if (fd == -1) {
            		fprintf(stderr, "cannot open output.txt for writing\n");
            		exit(1);
        	}
        	dup2(fd, 1);
        	dup2(fd, 2);
		}
	else if(stO==NULL&&stI!=NULL){
                printf("child: about to start.!.21112.\n");
                fd = open(stI, O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
                if (fd == -1) {
                        fprintf(stderr, "cannot open output.txt for writing\n");
                        exit(1);
                }
                dup2(fd, 0);
                dup2(fd, 2);
                }
	else if(stI!=NULL&&stO!=NULL){
                printf("child: about to start.!.333.\n");
              
			
                fd=open(stI, O_RDONLY, S_IRUSR|S_IWUSR);
		if(fd==-1){
			fprintf(stderr, "cannot open output.txt for writing\n");
                        exit(1);
		}
		int fd2;	
		fd2 = open(stO, O_WRONLY|O_CREAT|O_RDWR, S_IRUSR|S_IWUSR);
                if (fd2 == -1) {
                        fprintf(stderr, "cannot open output.txt for writing\n");
                        exit(1);
                }
		printf(">>>fd %d\n",fd);
		printf(">>>fd2 %d\n",fd2);
       	        dup2(fd,0);
		dup2(fd2,1); 
		dup2(fd2,2);
                               }
	execve(args[0], args, envp);
       	printf("child: SHOULDN'T BE HERE.\n");
}//fork
	printf("parentL waiting for child to finish...\n");
	waitpid(pid,&status,0);
	printf("parent: child is finished.\n");
	
	printf("say----- something\n");
}
int main(int argc, char *arigv[]) {
    struct timeval before, after;
    char *args[] = { "/bin", "-1", 0 };//mimic real one
    char *preDir=args[0];
    //char *envp[] = { 0 };
    int pid;
    int status;
    char input[MAX_INPUT_LINE];
    char *token[MAX_NUM_TOKENS];
    char *t;
    int  i;
    int  line_len;
    int  num_tokens;
    char ediStr[MAX_INPUT_LINE]="";
    int loop;
    for(loop=0;loop<10;loop++) {
    memset(input, 0, MAX_INPUT_LINE);
    memset(token, 0, MAX_NUM_TOKENS);
    fprintf(stdout, "vsh%%");
    fflush(stdout);

    gettimeofday(&before, NULL);//TIME
    fgets(input, MAX_INPUT_LINE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    if (strcmp(input, "exit") == 0) {
            exit(0);
        }
    num_tokens = 0;
    t = strtok(input, " ");
    while (t != NULL && num_tokens < MAX_NUM_TOKENS) {
        token[num_tokens] = t;
        num_tokens++;
        t = strtok(NULL, " ");
    }

    /* print out the user inputed commands
     * 
     * each space seperate a command
     *
     * FOR TESTING
     */
    char times='N';
    char *stI=NULL;
    char *stO=NULL;
    char *cmdList[MAX_NUM_TOKENS];
    int numCMD=0;
    printf("the total number of token is: %ld\n\n",strlen(*token));
    for (i = 0; i < num_tokens; i++) {
        printf("token %d inputs are==>:%s\n", i+1, token[i]);
	printf("token has length:%ld\n",strlen(token[i]));	
	//printf("%c\n",token[i][strlen(token[i])-1]);
	char a=':';
	char b='#';
	if(b==token[i][0]&&b==token[i][0]){
	times='Y';
	}
	if(a==token[i][0]&&a==token[i][1]){
	printf("Good the filename is after the ::\n");
	//*ediStr=token[i][2];
	printf("%s\n",&token[i][2]);
	stO=&token[i][2];//Getting the std out file 

	}
	
  	else if(a==token[i][strlen(token[i])-1]&&a==token[i][strlen(token[i])-2]){
	printf("GooD the filename is before the ::\n");
	strncpy(ediStr,token[i],strlen(token[i])-2); 
	printf("%s\n",ediStr);//ediStr is the filename
	stI=ediStr;//getting the std in file


        }	
	else{
	//strcat(cmdList,token[i]);
	cmdList[numCMD]=token[i];
	numCMD++;	

	}
        //*ediStr="";

	//once the :: founded, try to resize the ::token
   printf("\n"); 
    }		
    	printf("The stdIN is :%s\n",stI);
	printf("The stdOUT is :%s\n",stO);

	printf("Contains %d commands\n",numCMD);
	int z;
	for(z=0;z<numCMD;z++){
		printf("The Collected cmd is :%s\n",cmdList[z]); 
	}
	//:w
	functionSS(preDir,cmdList,numCMD,stI,stO);	



    printf("\n\n");//seperate work zone!!


    printf("whats next  ?(FROM MAIN())\n");
    gettimeofday(&after, NULL);
    if(times=='Y'){
    printf("The process spent %lu microseconds in nested loop\n",
        (after.tv_sec - before.tv_sec) * 1000000 +
            after.tv_usec - before.tv_usec);

    }
    }//for loop user prompt
}














	

