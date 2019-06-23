#include <stdio.h>
#include <stdlib.h>
typedef struct {

    char nome[50];
    int media;
    int idade;


    } aluno;
void show_aluno(aluno *a) {
    printf("%s", a->nome);
    printf("%i", a->media);
    printf("%i", a->idade);



}

int main() {

    aluno a;
    aluno *b = &a;
    b->nome[50] = "k";
    b->media = 4;
    b->idade = 40;
    show_aluno(a);
    return 0;

}