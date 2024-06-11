/*
AUTO
BREAK
CHAR CONTINUE CONST CASE
DEFAULT DO DOUBLE
ENUM ELSE EXTERN
FOR FLOAT
GOTO
IF INT
LONG
REGISTER RETURN
SWITCH STATIC SHORT STRUCT SIGNED  SIZEOF
TYPEDEF 
UNION UNSIGNED 
VOID VOLATILE 
WHILE 
*/
 #include <stdio.h>
#include <string.h>

int main() {
    char keyword[20];
    int cs;
    int size;
    printf("keyword > ");
    fgets(keyword,sizeof(keyword),stdin);
    printf("%s",keyword);
        if (keyword[strlen(keyword) - 1] == '\n')
        keyword[strlen(keyword) - 1] = '\0';

    enum states { q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, qf };

    cs = q0;
    size = strlen(keyword);
    switch (keyword[0]) {
        case 'a':
            cs = q0;
            break;
        case 'b':
            cs = q1;
            break;
        case 'c':
            cs = q2;
            break;
        case 'd':
            cs = q3;
            break;
        case 'e':
            cs = q4;
            break;
        case 'f':
            cs = q5;
            break;
        case 'g':
            cs = q6;
            break;
        case 'i':
            cs = q7;
            break;
        case 'l':
            cs = q8;
            break;
        case 'r':
            cs = q9;
            break;
        case 's':
            cs = q10;
            break;
        case 't':
            cs = q11;
            break;
        case 'u':
            cs = q12;
            break;
        case 'v':
            cs = q13;
            break;
        case 'w':
            cs = q14;
            break;
        default:
            cs = q15; // for keywords starting with other letters
            break;
    }

    switch (cs) {
        case q0:
            if (strcmp(keyword, "auto") == 0 )
                cs = qf;
            break;
        case q1:
            if (strcmp(keyword, "break") == 0)
                cs = qf;
            break;
        case q2:
            if (strcmp(keyword, "char") == 0 || strcmp(keyword, "const") == 0 || strcmp(keyword, "case") == 0)
                cs = qf;
            break;
        case q3:
            if (strcmp(keyword, "default") == 0 || strcmp(keyword, "do") == 0 ||
                strcmp(keyword, "double") == 0)
                cs = qf;
            break;
        case q4:
            if (strcmp(keyword, "else") == 0 || strcmp(keyword, "enum") == 0 ||
                strcmp(keyword, "extern") == 0)
                cs = qf;
            break;
        case q5:
            if (strcmp(keyword, "for") == 0 || strcmp(keyword, "float") == 0)
                cs = qf;
            break;
        case q6:
            if (strcmp(keyword, "goto") == 0)
                cs = qf;
            break;
        case q7:
            if (strcmp(keyword, "if") == 0 || strcmp(keyword, "int") == 0)
                cs = qf;
            break;
        case q8:
            if (strcmp(keyword, "long") == 0)
                cs = qf;
            break;
        case q9:
            if (strcmp(keyword, "register") == 0 || strcmp(keyword, "return") == 0)
                cs = qf;
            break;
        case q10:
            if (strcmp(keyword, "switch") == 0 || strcmp(keyword, "static") == 0 ||
                strcmp(keyword, "short") == 0 || strcmp(keyword, "struct") == 0 ||
                strcmp(keyword, "signed") == 0 || strcmp(keyword, "sizeof") == 0)
                cs = qf;
            break;
        case q11:
            if (strcmp(keyword, "typedef") == 0)
                cs = qf;
            break;
        case q12:
            if (strcmp(keyword, "union") == 0 || strcmp(keyword, "unsigned") == 0)
                cs = qf;
            break;
        case q13:
            if (strcmp(keyword, "void") == 0 || strcmp(keyword, "volatile") == 0)
                cs = qf;
            break;
        case q14:
            if (strcmp(keyword, "while") == 0)
                cs = qf;
            break;
        default:
            break;
    }

    if (cs == qf)
        printf("keyword");
    else
        printf("not keyword");

    return 0;
}
