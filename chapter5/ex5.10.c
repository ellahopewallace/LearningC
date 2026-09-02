#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


#define MAXOPS 50
#define MAXNUMS 100

int expr(int *, char *);

int main(int argc, char *argv[]){
    char operators[MAXOPS];
    char *poperators = operators;
    int numbers[MAXNUMS];
    int *pnumbers = numbers;

    if (argc < 4){
        printf("Usage: polish calculator");
        return -1;
    }
    while (--argc > 0 && !isdigit(*argv[argc])){
        *poperators++ = *argv[argc];
    }
    *poperators = '\0';
    *pnumbers++ = atoi(argv[argc]);
    while (--argc > 0){
        *pnumbers++ = atoi(argv[argc]);
    }
    *pnumbers = '\0';
    int answer = expr(numbers, operators);
    printf("%d\n", answer);
    return 0;
}

int expr(int *nums, char *ops){
    int answer = 0;
    while (*ops != '\0'){
        int num2 = *nums++;
        int num1 = *nums++;
        char op = *ops++;
        int subAnswer;
        switch(op){
            case '+':
                subAnswer = num1 + num2;
                break;
            case '-':
                subAnswer = num1 - num2;
                break;
            case '*':
                subAnswer = num1 * num2;
                break;
            case '/':
                if (num2 == 0){
                    printf("division by zero error\n");
                    return -1;
                }
                subAnswer = num1 / num2;
                break;
            default:
                printf("Unsupported operand\n");
                return -1;
        }
        if (*nums++ != '\0'){
            *--nums = subAnswer;
        }
        else {
            answer = subAnswer;
            break;
        }
    }
    return answer;
}