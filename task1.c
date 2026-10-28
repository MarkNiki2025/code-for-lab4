#include <stdio.h>
#define N 15

int main() {
    int funcValues [N] ={0};
    printf("Write values of the func \n");
    printf("Write -1 if you wanna stop \n");
    for (int i = 0; i <= N; i++) {
        printf("Your value: ");
        int funcvalue = 0;
        scanf("%d", &funcvalue);
        if(funcvalue == -1) break;
        funcValues[i] = funcvalue;
        printf("\n");
    }
    int funcBit[N][5] = {0};
    for (int i = 0; i < N ; i++) {
        for(int k = 3; k >= 0; k--) {
            funcBit[i][k] = funcValues[i] % 2;
            funcValues[i] /= 2;
        }
        printf("\n");
    }
    for(int i = 0; i< N; i++) {
        for(int k = 0; k < 5; k++) {
            printf("%d",funcBit[i][k]);
        }
        printf("\n");
    }
    return 0;
}