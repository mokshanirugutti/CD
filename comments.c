/*
    // 
    /* 
    #

*/

#include <stdio.h>
#include <string.h>

int main(){
    char comment[30];
    int cs,size;
    printf("comment > ");
    fgets(comment, sizeof(comment), stdin);
    printf("%s ",comment);
    enum states {q0, q1,q2, q3,qf};
    if (comment[0] == '#')  cs = qf;

    else if (comment[0] == '/') {
        if(comment[1] == '/')   cs = qf;
        if (comment[1] == '*')  cs = q2;
    }
    size = strlen(comment);
    switch (cs)
    {
        case q2:
            if (comment[size-3]=='*' && comment[size-2]=='/')
                cs = qf;
            else cs = q0;
            break;
    }    
    if (cs == qf) printf("Comment");
    else printf("!Comment");
}