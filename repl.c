#include <stdio.h> 
#include <stdlib.h>
#ifdef _WIN32
#include <string.h>
static char buffer[2048];

/*Fake readline function*/
char* readline(char* prompt){ 
    fputs(prompt, stdout);
    fgets(buffer,2048, stdin);
    char* cpy = malloc(strlen(buffer)+1); 
    strcpy(cpy,buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

/* Fake Add History function */
void add_history(char* unused){}
#else
#include <editline/readline.h>
/* include editline/history.h */
/* On mac, readline only but need to specify in compilation */
// cc -std=c99 -Wall repl.c -ledit  -o prompt
// sudo apt-get install libedit-dev -> Linux
// su -c "yum install libedit-dev*" --> Fedora 
// brew install readline -> mac
// Will cover this with a shell script in the install 
#endif 

int main(int argc, char** argv){ 
    /* Print Version and Exit information */
    puts("Rodeo 0.1");
    puts("Press Ctrl+c to Exit\n");

    /* in a never ending loop */
    while(1){
        /* ouput our prompt */    
        char* input = readline("<rodeo>"); 

        /* Add input to history */
        add_history(input); 

        /*echo back input */ 
        printf("%s\n", input);

        /* free retrieved input */

        free(input);  





    }

    return 0;
}