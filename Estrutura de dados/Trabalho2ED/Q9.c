#include <stdio.h>
#include <string.h>

int main() {
    int somA = 0, somB = 0, somC = 0, somD = 0;
    char time1[10], time2[10], time3[10], time4[10];
    int numGol = 0, numGol2 = 0, numGol3 = 0, numGol4 = 0;

    printf("Digite o nome do primeiro time: ");
    scanf("%s", time1);
    printf("Digite o nome do segundo time: ");
    scanf("%s", time2);
    printf("Digite o nome do terceiro time: ");
    scanf("%s", time3);
    printf("Digite o nome do quarto time: ");
    scanf("%s", time4);

    while (numGol >0) {
        printf("Digite o numero de gols do %s: ", time1);
        scanf("%d", &numGol);
        printf("Digite o numero de gols do %s: ", time2);
        scanf("%d", &numGol2);
        printf("Digite o numero de gols do %s: ", time3);
        scanf("%d", &numGol3);
        printf("Digite o numero de gols do %s: ", time4);
        scanf("%d", &numGol4);

        if (numGol == numGol2) {
            if (strcmp(time1, "A") == 0 || strcmp(time2, "A") == 0) {
                somA += 1;
            }
            else if (strcmp(time1, "B") == 0 || strcmp(time2, "B") == 0) {
                somB += 1;
            }
            else if (strcmp(time1, "C") == 0 || strcmp(time2, "C") == 0) {
                somC += 1;
            }
            else if (strcmp(time1, "D") == 0 || strcmp(time2, "D") == 0) {
                somD += 1;
            }
        }
        else 
        break;

    }

    return 0;
}
