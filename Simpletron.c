#include <stdio.h>

// E/S OPERATIONS
#define READ 10
#define WRITE 11
#define WRITE_S 12
// ACCUMULATOR OPERATIONS
#define LOAD 20
#define STORE 21
//ARITMETHIC OPERATIONS
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
//GOTO OPERATIONS
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
// ENDING OPERATIONS
#define HALT 43

int main()
{

    int memory[100];
    float y[100] = {0};
    float accumulator = 0;
    int instructionCounter = 0;
    int operationCode;
    int operand;
    int instructionRegister;
    int x = 0;
    int input;

    printf("*** Bem vindo ao Simpletron! ***\n*** Favor digitar seu programa, uma instrucao ***\n*** (ou palavra de dados) por vez. Mostrarei ***\n*** o numero do local e uma interrogacao (?). ***\n*** Voce, entao, devera digitar a palavra para esse ***\n*** local. Digite a sentinela -1869f para ***\n*** encerrar a entrada do seu programa. ***\n\n");



    while (1) {

        if (x < 10) {


            printf("0");


            }
        printf("%i ? ", x);
        scanf("%i", &input);

        if (input == -99999) {


            break;
            }

        memory[x] = input;
        x++;

        }

    printf("*** Carga do programa concluida    ***\n*** Iniciando execucao do programa ***\n\n");

    while (instructionCounter <= x)  {

        instructionRegister = memory[instructionCounter];

        operationCode = instructionRegister / 100;

        operand = instructionRegister % 100;

        switch (operationCode) {

            case WRITE_S:

                printf("%c", operand);

                break;

            case READ:

                printf("\n? ");

                scanf("%f", &y[operand]);

                memory[operand] = y[operand];

                y[operand] = y[operand] - memory[operand];

                break;

            case WRITE:

                    if (y[operand] > 0 || y[operand] < 0) {

                        printf("\n%.2f\n", (float)memory[operand] + y[operand]);

                        }
                    else {

                        printf("\n%i\n", memory[operand]);
                        }
                break;


             case LOAD:

                accumulator = (float)memory[operand] + y[operand];

                break;


             case STORE:

                memory[operand] = accumulator;
                y[operand] = accumulator;
                y[operand] -= memory[operand];

                break;

             case ADD:

                accumulator = accumulator + memory[operand] + y[operand];


                break;

            case SUBTRACT:

                accumulator = accumulator - memory[operand] - y[operand];

                break;

            case DIVIDE:

                if (accumulator == 0 || (float)memory[operand] + y[operand] == 0) {

                    printf("\n*** ERRO: DIVISAO POR ZERO ***\n");

                    }

                else {
                    accumulator = accumulator / ((float)memory[operand] + y[operand]);
                    }

                break;

            case MULTIPLY:

                accumulator = accumulator * (memory[operand] + y[operand]);

                break;

            case BRANCH:

                instructionCounter = operand;



                break;

             case BRANCHZERO:


                if (accumulator == 0) {

                    instructionCounter = operand;

                        }


                break;

              case BRANCHNEG:

                if (accumulator < 0) {

                    instructionCounter = operand;

                    }

                break;

               case HALT:

                printf("\nFIM\n");

                x = 0;

                break;


            }





        if (operationCode != BRANCH && operationCode != BRANCHNEG && operationCode != BRANCHZERO) {

            ++instructionCounter;


            }

        }

    return 0;
}
