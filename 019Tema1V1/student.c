/** ============================================================
 *  File:   student.c
 *  Author: Mihai Cornel    mhcrnl@gmail.com    0722270796
 *  System: Ubuntu 16.04    Code::Blocks 13.12  gcc
 *          Fedora 23       Code::Blocks 16.01  gcc version 5.3.1
 *
 =================================================================*/
#include "student.h"

STUDENT citireStudent()
{
    STUDENT stud;

    printf("Introduce-ti numele studentului: ");
    scanf("%s", stud.nume);
    printf("Introduce-ti nota 1 la matematica : ");
    scanf("%d", &stud.mat.nota1);
    printf("Introduce-ti nota 2 la matematica: ");
    scanf("%d", &stud.mat.nota2);
    printf("Introduce-ti nota 3 la matematica: ");
    scanf("%d", &stud.mat.nota3);

    printf("Introduce-ti nota 1 la lb. romana : ");
    scanf("%d", &stud.lit.nota1);
    printf("Introduce-ti nota 2 la lb. romana: ");
    scanf("%d", &stud.lit.nota2);
    printf("Introduce-ti nota 3 la lb. romana: ");
    scanf("%d", &stud.lit.nota3);

    printf("Introduce-ti nota 1 la fizica : ");
    scanf("%d", &stud.fiz.nota1);
    printf("Introduce-ti nota 2 la fizica: ");
    scanf("%d", &stud.fiz.nota2);
    printf("Introduce-ti nota 3 la fizica: ");
    scanf("%d", &stud.fiz.nota3);

    return stud;
}

int meniu(void)
{
    int selectie;

    printf("\t1.\t Adaugati studentul si notele acestuia.\n");
    printf("\t2.\t Selectati studentul dupa nume.\n");
    printf("\t3.\t Afisati studentii.\n");
    printf("\t4.\t Sortare studentii.\n");

    printf("\t5.\t Iesire din aplicatie.\n");

    printf("Introduce-ti selectia dumneavoastra: ");
    scanf("%d", &selectie);

    return selectie;
}

void afisareStudent(STUDENT stud)
{
    printf("Nume: %s\n.", stud.nume);
    printf("Note matematica: %d %d %d.\n", stud.mat.nota1, stud.mat.nota2, stud.mat.nota3);
    printf("Note romana: %d %d %d.\n", stud.lit.nota1, stud.lit.nota2, stud.lit.nota3);
    printf("Note fizica: %d %d %d.\n\n", stud.fiz.nota1, stud.fiz.nota2, stud.fiz.nota3);

}

STUDENT cautaStudent(STUDENT studenti[], char numeStudent[], int nrElemente){
    STUDENT studentCautat;
    int i;
    for(i=0; i<nrElemente; i++){
        if(strcmp(studenti[i].nume, numeStudent) == 0){
            studentCautat = studenti[i];
        }  else {
            printf("Studentul cu numele %s nu a fost gasit.\n", numeStudent);
        }
    }
    return studentCautat;
}

STUDENT celMaiBun(STUDENT studenti[], int materie, int nrElemente){
    puts("Rulam metoda celMaiBun()");
    STUDENT stud;
    float medie1, medie2;
    int i;
    stud = studenti[0];
    if(materie == 1){
        for(i=1; i<nrElemente; i++){
           medie1 = (studenti[i].mat.nota1+studenti[i].mat.nota2+studenti[i].mat.nota3)/3;
           medie2 = (studenti[i+1].mat.nota1+studenti[i+1].mat.nota2+studenti[i+1].mat.nota3)/3;
           if(medie1>medie2){
                printf("media1 > media2 : %f > %f ", medie1, medie2);
                stud = studenti[i];
           } else if(medie1<medie2){
                stud =  studenti[i+1];
           } else {

           }
        }
    }
    //char *materieSt[20];
//    materieSt = strcpy("studenti.", materie);
    //printf("%s", materieSt);

    return stud;
}
