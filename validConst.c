#include <stdio.h>
#include <string.h>

int main(){
    char input[10];
    int cs, i, size, error = 0;
    scanf("%s", input);
    enum states {q1, q2, q3, q4, qf};

    // printf("%s", input);
    
    if (input[0] >= '0' && input[0] <= '9')
        cs = q1;
    else if(input[0] == 'e' || input[0] == 'E')
        cs = q2;
    else
        error = 1;

    i = 1;
    size = strlen(input);
    while (i < size && !error) {
        switch (cs) {
            case q1:
                if (input[i] == '-' || input[i] == '+')
                    cs = q2;
                else if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.')
                    cs = q1;
                else
                    error = 1;
                break;

            case q2:
                if (input[i] == 'e' || input[i] == 'E')
                    cs = q2;
                else if ((input[i] >= '+' && input[i] <= '-') || input[i] == '.')
                    cs = q1;
                else
                    error = 1;
                break;
        }
        i++;
    }

    if (error == 1)
        printf("not valid\n");
    else
        printf("valid\n");

    return 0;
}
