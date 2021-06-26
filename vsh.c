


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LINE 70
#define MAX_NUM_TOKENS 10
void functionSS(char *args[],char *inputCmd){	

        printf("say----- something\n");
        printf("%s\n",args[0]);////bin/ls
        printf("%s\n",args[1]);
        //printf("%s\n",args[2]);
	printf("%s\n",inputCmd);
	char absPath[MAX_NUM_TOKENS];
	strcat(absPath,args[0]);
	strcat(absPath,"/");
	strcat(absPath,inputCmd);
	printf("%s\n",absPath);
	//printf("%s\n",args[0]);
	printf("say----- something\n");
}
int main(int argc, char *argv[]) {
    char *args[] = { "/bin", "-1", 0 };//mimic real one
    char *envp[] = { 0 };
    int pid;
    int status;
    char input[MAX_INPUT_LINE];
    char *token[MAX_NUM_TOKENS];
    char *t;
    int  i;
    int  line_len;
    int  num_tokens;
    char ediStr[10];
    fprintf(stdout, "vsh%%");
    fflush(stdout);
    fgets(input, MAX_INPUT_LINE, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
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
    printf("the total number of token is: %ld\n\n",strlen(*token));
    for (i = 0; i < num_tokens; i++) {
        printf("token %d inputs are==>:%s\n", i+1, token[i]);
	char *p1;
	printf("token has length:%ld\n",strlen(token[i]));	
	//printf("%c\n",token[i][strlen(token[i])-1]);
	char a=':';
	if(a==token[i][0]&&a==token[i][1]){
	printf("Good the filename is after the ::\n");
	*ediStr=token[i][2];
	printf("%s\n",&token[i][2]);
	}
	
  	else if(a==token[i][strlen(token[i])-1]&&a==token[i][strlen(token[i])-2]){
	printf("Goof the filename is before the ::\n");
	strncpy(ediStr,token[i],strlen(token[i])-2); 
	printf("%s\n",ediStr);//ediStr is the filename
	
	}
	functionSS(args,token[i]);	

	//once the :: founded, try to resize the ::token
   printf("\n"); 
    }	
	

    printf("\n\n");//seperate work zone!!


    printf("whats next boys ?\n");
}















	

