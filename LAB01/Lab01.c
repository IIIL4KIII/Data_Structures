#include <stdio.h>
#include <math.h>


int main(void) {

    int cestasJoao, joaoPoints = 0;
    float xCoord, yCoord;
    int points;
    scanf("%i", &cestasJoao);
    for (int i = 0 ; i < cestasJoao; i++) {
        scanf("%f %f", &xCoord, &yCoord);
        points = pow(pow(xCoord, 2.0) + pow(yCoord - 500, 2.0), 0.5);
        joaoPoints += points;
    }

    int cestasTeresa, teresaPoints = 0;
    scanf("%i", &cestasTeresa);
    for (int i = 0; i < cestasTeresa; i ++) {
        scanf("%f %f", &xCoord, &yCoord);
        points = pow(pow(xCoord, 2.0) + pow(yCoord - 500, 2.0), 0.5);
        teresaPoints += points;
    }

    printf("Joao fez %i pontos, Teresa fez %i pontos.\n", joaoPoints, teresaPoints);
    if (teresaPoints > joaoPoints)
        printf("Teresa venceu.\n");
    else if (joaoPoints > teresaPoints)
        printf("Joao venceu.\n");
    else
        printf("Ninguem venceu.\n");

}
