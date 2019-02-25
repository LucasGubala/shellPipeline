#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]){
    if( argc == 1){
        printf("Please enter a valid input\n");
        return 0;
    }

    char *args1[10];    //list of arguments for cmd1
    char *args2[10];    //list of arguments for cmd2
    char cmd1[25];      //shell command for <arg1>
    char cmd2[25];      //shell command for <arg2>
    bool noArg2;
    bool noArg1;

    //printf("testing");

    int count1 =0;
    for ( int i = 1 ; i < argc ; i++ ){     //parse arguments into two chunks <arg1> and <arg2>
        if(strcmp(argv[i],":") == 0){       //connector reached
            //count1++;
            break;
        }
        
        args1[count1] = argv[i];
        count1++;
    }
    
    //printf("count1: %d\n",count1);  
    if( count1 != 0 ){
        strcpy(cmd1,args1[0]);                  //catch shell command
        cmd1[ strlen(args1[0])+1 ] = '\0';
    //printf("cmd1: %s\n",cmd1);
    }
    else{
        noArg1 = true;
    }

    int count2 =0;
    for( int x =(count1+2); x < argc; x++){
        if(strcmp(argv[x],":") == 0){
            printf("connector\n");
            break;
        }

        args2[count2] = argv[x];
        count2++;
    }
    
    //printf("count2: %d\n",count2);
    if( count2 != 0 ){
        strcpy(cmd2,args2[0]);
        cmd2[ strlen(args2[0])+1 ] = '\0';
    //printf("cmd2: %s\n",cmd2);
    }
    else{
        noArg2 = true;
    }


    for( int j =0;j<count1;j++){            //printing for checking
        printf("%s\n",args1[j]);
    }
    printf("----------------\n");
    for( int j =0;j<count2;j++){
        printf("%s\n",args2[j]);
    }
    

}