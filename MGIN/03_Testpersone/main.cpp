#include <iostream>

using namespace std;

typedef struct person {
    int persnr;
    char name[40];
} TPERSON;
#define ANZ  3

void sort_persnr(TPERSON* p, int anzahl);

int main(int argc, char* argv[]){
    TPERSON wir[ANZ];
    int i;

    printf("\nBitte %d Datensaetze eingeben:\n", ANZ);
    for (i=0; i < ANZ; i++){
        printf("\n%d:persnr> ", i);
        scanf("%d", &(wir[i].persnr));
        printf("%d:Name> ", i);
        scanf("%s", wir[i].name);
    }

    // Das Array mit dem Namen wir soll sortiert werden
    sort_persnr(wir, ANZ);


    printf("\nAusgabe: Sortiert wurde nach persnr:\n");
    for (i=0; i < ANZ; i++){
        printf("\n%6d | %-20s", wir[i].persnr , wir[i].name);
    }
    return 0;
}

void sort_persnr(TPERSON* p, int anzahl){
    int i;
    int fertig;

    fertig=0;
    while (0==fertig){

  fertig= 1;
        for (i=0; i < anzahl-1; i++){
            if ( p[i].persnr > (p[i+1].persnr)){
                TPERSON help;
                help= p[i];
                p[i] = p[i+1];
                p[i+1] = help;
                fertig= 0;
            }//if
        }//for

    }//while
}

