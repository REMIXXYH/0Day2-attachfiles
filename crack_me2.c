#include <stdio.h> 
#define PASSWORD "3xsh0re" 
#define FLAG     "flag{stack_overflow_right?}"
int verify_password (char *password) 
{ 
    int authenticated; 
    char buffer[8];// add local buffto be overflowed 
    authenticated=strcmp(password,PASSWORD); 
    strcpy(buffer,password);//over flowed here! 
    return authenticated; 
} 
main() 
{ 
    int valid_flag=0; 
    char password[1024]; 
    while(1) 
    { 
        printf("please input password: "); 
        scanf("%s",password); 
        valid_flag = verify_password(password); 
    if(valid_flag) 
        { 
            printf("incorrect password!\n\n"); 
        } 
    else 
        { 
            printf("Congratulation! You have got the flag:%s!\n",FLAG); 
            break; 
        } 
    } 
} 
