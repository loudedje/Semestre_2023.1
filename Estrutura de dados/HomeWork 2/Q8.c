#include <stdio.h>

int main() {
    float altura_Anto = 1.50;
    float altura_carl = 1.10;
    float CresA = 0.02;
    float cresC = 0.03;
    int i = 0;
    
    while (altura_Anto > altura_carl) {
        altura_Anto += CresA;
        altura_carl += cresC;
        i++;
    }

    printf("Os dois vão crescer juntos quando estiverem %d anos.\n", i);

    return 0;
}
