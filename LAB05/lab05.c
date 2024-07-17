#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int calendar (int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    
    int K = year % 100;
    int J = year / 100;
    int h = -1;
    if ((day <= 2 && month <= 9 && year == 1752) || (month < 9 && year == 1752) || year < 1752)
        h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + 5 - J) % 7; // Juliano
    else if ((month >= 9 && year == 1752) || year > 1752)
        h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) - 2 * J) % 7; // Gregoriano

    if (h < 0)
        h += 7;

    return h;
}

// Is valid verifica absurdos em relacoes as datas, ou seja possiveis indeficoes.

int isValidData(int day, int month, int year) {
        int leapYear = 0, valid;
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            leapYear++;

        if ((leapYear == 0 && day == 29 && month == 2) || day <= 0 || month <= 0 || year <= 0 || day > 31 || month > 12)
            valid = 0;
        else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31)
            valid = 0;
        else if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            valid = 0;
        else if (month == 2 && day > 29)
            valid = 0;
        else if (day > 2 && day < 14 && month == 9 && year == 1752)
            valid = 0;
        else
            valid = 1;

        return valid;
}

typedef struct {
    int day;
    int month;
    int year;
} date;

int main (void) {
    date infodate;
    // char days[][7] = {"domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"};

    while (1) {
        scanf("%i %i %i", &infodate.day, &infodate.month, &infodate.year);
        if (infodate.day == 0 && infodate.month == 0 && infodate.year ==0)
            break;
        int day = -1;
        int validData = isValidData (infodate.day, infodate.month, infodate.year);

        if (((infodate.day <= 2 && infodate.month <= 9 && infodate.year == 1752) || infodate.year < 1752) && validData == 1)
            day = calendar(infodate.day, infodate.month, infodate.year);
        else if (((infodate.day > 2 && infodate.month <= 9 && infodate.year == 1752) || (infodate.month > 9 && infodate.year == 1752) || infodate.year > 1752) && validData == 1) 
            day = calendar(infodate.day, infodate.month, infodate.year);
        else if (validData == 0)
            day = 7;

        printf("%02d/%02d/%04d: ", infodate.day, infodate.month, infodate.year);
        switch(day) {
            case 0:
                printf("sabado\n");
                break;
            case 1:
                printf("domingo\n");
                break;
            case 2:
                printf("segunda\n");
                break;
            case 3:
                printf("terca\n");
                break;
            case 4:
                printf("quarta\n");
                break;
            case 5:
                printf("quinta\n");
                break;
            case 6:
                printf("sexta\n");
                break;
            default:
                printf("invalida\n");
                break;
        }
    }

}



