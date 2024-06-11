#include <stdio.h>
#include <string.h>

char str[100];
int l, i = 0, e = 0;

void E();
void T();
void E_();
void T_();
void F();

int main() {
    printf("Recursive Descent Parser:\n");
    printf("\nE -> TE'"
           "\nE' -> +TE'|ε"
           "\nT -> FT'"
           "\nT' -> *FT'|ε"
           "\nF -> (E)|id\n");

    printf("\nEnter the expression: ");
    scanf("%s", str);
    l = strlen(str);
    E();
    if (i == l && !e) {
        printf("\naccepted\n");
    } else {
        printf("\nnot accepted\n");
    }
    return 0;
}

void E() {
    T();
    E_();
}

void T() {
    F();
    T_();
}

void E_() {
    if (str[i] == '+') {
        i++;
        T();
        E_();
    }
}

void T_() {
    if (str[i] == '*') {
        i++;
        F();
        T_();
    }
}

void F() {
    if (str[i] == '(') {
        i++;
        E();
        if (str[i] == ')') {
            i++;
        } else {
            e = 1;
        }
    } else if (strncmp(&str[i], "id", 2) == 0) {
        i += 2;
    } else {
        e = 1; 
    }
}
