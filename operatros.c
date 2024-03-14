/*
    + - * / %
    = += -= *= /= %= 
    == > < != >= <=
    && || !
    ++ --
    & | ~ ^  << >>

*/
#include <stdio.h>
#include <string.h>

int main() {
    char oprtr[20];
    int size;
    int cs = 0;
    printf("operator > ");
    scanf("%s", oprtr);
    size = strlen(oprtr);
    enum states { q0, q1, q2, q3, q4, q5, q6, q7, qf };
    
    // Single-character operators
    if (size == 1) {
        switch (oprtr[0]) {
            case '+':
            case '=':
            case '-':
            case '*':
            case '/':
            case '%':
            case '<':
            case '>':
            case '!':
            case '&':
            case '|':
            case '~':
            case '^':
                cs = qf;
                break;
            default:
                break;
        }
    } 
    // Multi-character operators
    else {
        switch (oprtr[0]) {
            case '+':
                if (oprtr[1] == '+' || oprtr[1] == '=') cs = qf;
                break;
            case '-':
                if (oprtr[1] == '-' || oprtr[1] == '=') cs = qf;
                break;
            case '=':
                if (oprtr[1] == '=') cs = qf;
                break;
            case '<':
                if (oprtr[1] == '=' || oprtr[1] == '<' || oprtr[1] == '>') cs = qf;
                break;
            case '>':
                if (oprtr[1] == '=' || oprtr[1] == '>') cs = qf;
                break;
            case '&':
                if (oprtr[1] == '&' || oprtr[1] == '=') cs = qf;
                break;
            case '|':
                if (oprtr[1] == '|' || oprtr[1] == '=') cs = qf;
                break;
            default:
                break;
        }
    }

    if (cs == qf)     printf("it's an operator");
    else   printf("not an operator");
    return 0;
}
