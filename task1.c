
#include <stdio.h>
#define N 16

int main() {
    int funcValues[N] = {0};
    int numOfValues = 0;
    int status = 0;
    char variables[] = {'p', 'q', 'r', 'd'};

    printf("Write arguments of the function where f = 1\n");
    printf("Write -1 if you want to stop\n");

    for (int i = 0; i < N; i++) {
        int funcvalue = 0;

        printf("Your value: ");
        status = scanf("%d", &funcvalue);

        if (status != 1) {
            printf("Invalid input. Please enter an integer.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            i--;
            continue;
        }

        if (funcvalue == -1) {
            break;
        }

        if (funcvalue < 0 || funcvalue >= N) {
            printf("Incorrect value. Enter a number from 0 to 15.\n");
            i--;
            continue;
        }

        int duplicate = 0;

        for (int j = 0; j < numOfValues; j++) {
            if (funcValues[j] == funcvalue) {
                duplicate = 1;
                break;
            }
        }

        if (duplicate) {
            printf("This value was already entered.\n");
            i--;
            continue;
        }

        funcValues[numOfValues] = funcvalue;
        numOfValues++;

        printf("\n");
    }

    int funcBit[N][4] = {0};

    for (int i = 0; i < N; i++) {
        int cp = i;

        for (int k = 3; k >= 0; k--) {
            funcBit[i][k] = cp % 2;
            cp /= 2;
        }
    }

    printf("------------------------------------------\n");
    printf("| num ||  p  ||  q  ||  r  ||  d  ||  f  |\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        int isTrue = 0;

        for (int k = 0; k < numOfValues; k++) {
            if (i == funcValues[k]) {
                isTrue = 1;
                break;
            }
        }

        printf("| %2d  |", i);

        for (int k = 0; k < 4; k++) {
            printf("|  %d  ", funcBit[i][k]);
        }

        printf("|  %d  |\n", isTrue);
    }

    printf("------------------------------------------\n");

    printf("DDNF: ");

    for (int i = 0; i < numOfValues; i++) {
        int index = funcValues[i];

        printf("(");

        for (int k = 0; k < 4; k++) {
            if (funcBit[index][k] == 0) {
                printf("!%c", variables[k]);
            } else {
                printf("%c", variables[k]);
            }

            if (k < 3) {
                printf(" & ");
            }
        }

        printf(")");

        if (i < numOfValues - 1) {
            printf(" | ");
        }
    }

    printf("\nDKNF: ");

    int indexesOfZeros[N] = {0};
    int numOfZeros = 0;

    for (int i = 0; i < N; i++) {
        int found = 0;

        for (int q = 0; q < numOfValues; q++) {
            if (funcValues[q] == i) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            indexesOfZeros[numOfZeros] = i;
            numOfZeros++;
        }
    }

    for (int i = 0; i < numOfZeros; i++) {
        int index = indexesOfZeros[i];

        printf("(");

        for (int k = 0; k < 4; k++) {
            if (funcBit[index][k] == 1) {
                printf("!%c", variables[k]);
            } else {
                printf("%c", variables[k]);
            }

            if (k < 3) {
                printf(" | ");
            }
        }

        printf(")");

        if (i < numOfZeros - 1) {
            printf(" & ");
        }
    }

    printf("\n");

    return 0;
}
