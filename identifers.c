#include <stdio.h>
#include <string.h>

int main() {
    char identifier[100];
    int i = 0, cs, error = 0;
    scanf("%s", identifier);
    enum state { q1, q2, q3, qf };

    if ((identifier[i] >= 'a' && identifier[i] <= 'z') || (identifier[i] >= 'A' && identifier[i] <= 'Z') || (identifier[i] == '_'))
        cs = q1;
    else{
        error = 1;
        cs= qf;
    }

    for (i = 1; i < strlen(identifier) && !error; i++) {
        switch (cs) {
            case q1:
                if (!((identifier[i] >= 'a' && identifier[i] <= 'z') || (identifier[i] >= 'A' && identifier[i] <= 'Z') || (identifier[i] >= '0' && identifier[i] <= '9') || (identifier[i] == '_')))
                    error = 1;
                break;
        }
    }

    if (!error)
        printf("Valid identifier\n");
    else
        printf("Not a valid identifier\n");

    return 0;
}
