#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    char idt[100];
    int i=0;
    scanf("%s",&idt);
    if ((idt[i] >= 'a' && idt[i] < 'z' ) || (idt[i] >= 'A' && idt[i] < 'Z' ))
    {
        for ( i = 1; i < strlen(idt); i++)
        {
            if (!((idt[i] >='a' && idt[i] <='z' )  || (idt[i] >='A' && idt[i] <='Z' )  ||  (idt[i] >='0' && idt[i] <='9' ) || (idt[i] == '_')))
            {
                printf("Not identifier");
                exit(0);
            }           
        }
        printf("identifier");
    }  else printf("Not identifier");
    return 0;
}