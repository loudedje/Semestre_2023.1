#include <stdio.h>
#include "Data.h"

int main() {
    Data data = {20, 12};
    Data data1 = {10, 4};
    printf("Dia %d\n", extraiData(data));
    extraiData(data);
    comparar(data, data1);
    return 0;
}
