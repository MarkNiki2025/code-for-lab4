#include <stdio.h>
#define N 16

int main() {
    int funcValues [N] ={0};
    int numOfValues = 0;
    int status = 0;
    char variables[] = {'p','q','r','d'};
    printf("Write argue of the func where func is true\n");
    printf("Write -1 if you wanna stop \n");
    for (int i = 0; i < N; i++) {
        printf("Your value: ");
        int funcvalue = 0;
        status = scanf("%d", &funcvalue);
        if ((!status || funcvalue > 15 || funcvalue < 0 ) && funcvalue != -1) {
            printf("It is not correct option\n ");
            printf("Pls try again\n");
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
    printf("DDNF: ");
    int arr[N][4] = {0};
    for (int i = 0; i < N; i++){
        if(!numOfValues || i >= numOfValues) break;
        int index = funcValues[i];
        printf("(");
        for(int k =0; k<4; k++) {
            if (funcBit[index][k] == 0) {
                arr[index][k] = 1;
                printf("!%c", variables[k]);
                if(k != 3) {
                    printf(" & ");
                }
            }else {
                printf("%c",variables[k]);
                    if(k != 3) {
                        printf(" & ");
                    }
            }
        }    
        printf(")");
        if(numOfValues > 1 && i+1 < numOfValues){
            printf(" | ");
        }
    }
    printf("\n");
    printf("DKNF: ");
    for(int i = 0; i < N; ++i) {
        for(int k = 0; k < 4; ++k) {
            arr[i][k] = 0;
        }
    }
    for (int i = 0; i < N; i++){
        if(!numOfValues || i >= numOfValues) break;
        int index = funcValues[i];
        printf("(");
        for(int k =0; k<4; k++) {
            if (funcBit[index][k] == 1) {
                arr[index][k] = 0;
                printf("!%c", variables[k]);
                if(k != 3) {
                    printf(" | ");
                }
            }else {
                printf("%c",variables[k]);
                    if(k != 3) {
                        printf(" | ");
                    }
            }
        }    
        printf(")");
        if(numOfValues > 1 && i+1 < numOfValues){
            printf(" & ");
        }
    }
    return 0;
}