#include <stdio.h>
#define N 16

int main() {
    int funcValues [N] ={0};
    int numOfValues = 0;
    int status = 0;
    printf("Write argue of the func where func is true\n");
    printf("Write -1 if you wanna stop \n");
    for (int i = 0; i < N; i++) {
        printf("Your value: ");
        int funcvalue = 0;
        status = scanf("%d", &funcvalue);
        if (!status || funcvalue > 15 || funcvalue < 0) {
            printf("It is not correct option\n Pls try again\n");
            --i;
        }
        if(funcvalue == -1 || i == 16) break;
        funcValues[i] = funcvalue;
        ++numOfValues;
        printf("\n");
    }
    int funcBit[N][4] = {0};
    for (int i = 0; i < N; i++) {
        int cp = i;
        for(int k = 3; k >= 0; k--) {
            funcBit[i][k] = cp % 2;
            cp /= 2;
        }
        printf("\n");
    }
    printf("------------------------------------------ \n");
    printf("| num ||  p  ||  q  ||  r  ||  d  ||  f  |\n");
    printf("------------------------------------------ \n");
    for(int i = 0; i < N; i++) {
        int isTrue = 0;
        if(i>9) {
            printf("|  %d |",i);
        }else{
            printf("|  %d  |",i);
        }
        for(int k = 0; k < 4; k++) {
            printf("|  %d  |",funcBit[i][k]);
        }
        for (int k = 0; k < numOfValues; k++ ){
            if(i == funcValues[k]) {
                isTrue = 1;
            }
        }
        printf("|  %d  |", isTrue);
        printf("\n");
    }
    printf("------------------------------------------ \n");
    return 0;
}