#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função auxiliar para garantir que o usuário digite apenas números inteiros
int ler_inteiro() {
    int valor;
    while (scanf("%d", &valor) != 1) {  // Verifica se a leitura foi bem-sucedida
        while(getchar() != '\n');  // Limpa o buffer de entrada
        printf("Entrada inválida! Por favor, digite um número inteiro: ");
    }
    return valor;
}


// Function prototypes
int random_ataque1();
int random_ataque2();
int random_ataque3();
int random_heal();

int faca();
int revolver();
int marreta();
int cura();

void jogo();
void rank();
void menu();


// Variaveis globais!!
int win = 0, dead = 0;

//-----------------------------------------------

// Função para ataques aleatórios e cura (sem mudanças)

int random_ataque1() {
    return rand() % 10 + 5;
}

int random_ataque2() {
    return rand() % 30 + 10;
}

int random_ataque3() {
    return rand() % 22 + 20;
}

int random_heal() {
    return rand() % 30 + 11;
}

// Função que cria ataques aleatórios para o BOT
int faca() {
    return rand() % 10 + 5;
}

int revolver() {
    return rand() % 30 + 10;
}

int marreta() {
    return rand() % 22 + 20;
}

int cura() {
    return rand() % 30 + 11;
}

// Função de Jogo com verificação de entradas
void jogo() {
    int character = 100, bot = 100, contador = 2;

    printf("\n\n------------------\n");
    printf("! Start the game !\n");
    printf("------------------\n\n\n\n");

    while (character > 0 && bot > 0) {
        if (character > 150 && bot > 150) {
            printf("\n\n  -----------------------------------------\n");
            printf("| Oops... your life is already at the limit. |\n");
            printf("| Oops... your life is already at the limit. |\n");
            printf("| Oops... your life is already at the limit. |\n");
            printf("| Oops... your life is already at the limit. |\n");
            printf("  -----------------------------------------\n\n");
            jogo();
        } else {
            printf("STATISTICS:\n");
            printf("Your health is at %d, while the enemy's health is at %d \n\n", character, bot);
            printf("1 == Attack with the KNIFE\n");
            printf("2 == Attack with the GUN\n");
            printf("3 == Attack with the HAMMER\n\n");
            printf("4 == Healing potion\n\n");

            printf("Choose: ");
            int escolha = ler_inteiro();  // Usando a função de leitura para validar a entrada

            switch (escolha) {
                case 1:
                    printf("\n--You managed to stab him a few times!--\n\n");
                    bot = bot - faca();
                    character = character - random_ataque1();
                    if (bot <= 0) {
                        printf("!--WIN--!\n\n");
                        win = win = 1;
                        for (int i = 0; i <= 10; i++) {
                            menu();
                        }
                    } else if (character <= 0) {
                        printf("!--DEAD--!\n\n");
                        dead = dead + 1;
                        for (int i = 0; i <= 10; i++) {
                            menu();
                        }
                    }
                    break;

                case 2:
                    printf("\n--You managed to shoot him a few times!--\n\n");
                    bot = bot - revolver();
                    character = character - random_ataque2();
                    if (bot <= 0) {
                        printf("!--WIN--!\n\n");
                        win = win + 1;
                        for (int i = 0; i <= 10; i++) {
                            menu();
                        }
                    } else if (character <= 0) {
                        printf("!--DEAD--!\n\n");
                        dead = dead + 1;
                        for (int i = 0; i <= 10; i++) {
                            menu();
                        }
                    }
                    break;

                case 3:
                    printf("\n--You managed to hit him with the hammer!--\n\n");
                    bot = bot - marreta();
                    character = character - random_ataque3();
                    if (bot <= 0) {
                        printf("!--WIN--!\n\n");
                        win = win + 1;
                        for (int i = 0; i <= 10; i++) {
                            menu();
                        }
                    } else if (character <= 0) {
                        printf("!--DEAD--!\n\n");
                        dead = dead + 1;
                        for (int i = 0; i <= 10; i++) {
                            menu();
                        }
                    }
                    break;

                case 4:
                    if (contador > 0) {
                        printf("\n--You managed to heal yourself--\n\n");
                        bot = bot + cura();
                        character = character + random_heal();
                        contador = contador - 1;
                    } else {
                        printf("\n| Você não tem mais curas... |\n");
                    }
                    break;

                default:
                    printf("Escolha inválida! Tente novamente.\n");
            }
        }
    }
}

// Função Rank com verificação de entrada
void rank() {
    int option;

    printf("\n -----------------\n"
           "|      RANK       |\n"
           "|                 |\n"
           "|   1 = WIN/DEAD  |\n"
           "|   2 = EXIT      |\n"
           " -----------------\n"
           "OPTION: ");
    option = ler_inteiro();  // Usando a função de leitura para validar a entrada

    while (option < 1 || option > 2) {
        printf("\n-------------------------------------------"
               "\n!!ERRO:Você entrou com um caractere incorreto!!"
               "\n-------------------------------------------"
               "\nOPTION: ");
        option = ler_inteiro();  // Usando a função de leitura para validar a entrada
    }

    switch (option) {
        case 1:
            printf("\n -----------------\n"
                   "|    WIN / DEAD   |\n"
                   "|                 |\n"
                   "|   WIN = %d       |\n"
                   "|   DEAD = %d      |\n"
                   "|                 |\n"
                   "|   2 = EXIT      |\n"
                   " -----------------\n"
                   "OPTION: ", win, dead);
            option = ler_inteiro();  // Usando a função de leitura para validar a entrada
            break;

        case 2:
            menu();
            break;
    }
}

// Função Menu com verificação de entrada
void menu() {
    int option, exit_settings;

    printf("\n -----------------\n"
           "|    THE KING     |\n"
           "|  Fighting Game  |\n"
           "|     1 v 1       |\n"
           "|                 |\n"
           "|   1 = NEW GAME  |\n"
           "|   2 = SETTINGS  |\n"
           "|   3 = RANK      |\n"
           "|   4 = EXIT      |\n"
           " -----------------\n"
           "OPTION: ");
    option = ler_inteiro();  // Usando a função de leitura para validar a entrada

    while (option < 1 || option > 4) {
        printf("\n-------------------------------------------"
               "\n!!ERRO:Você entrou com um caractere incorreto!!"
               "\n-------------------------------------------"
               "\nOPTION: ");
        option = ler_inteiro();  // Usando a função de leitura para validar a entrada
    }

    switch (option) {
        case 1:
            srand(time(NULL));
            jogo();
            break;

        case 2:
            printf("\n\n  -----SETTINGS-----\n"
                   "|      BUTTONS:      |\n"
                   "|     1  2  3  4     |\n"
                   "|                    |\n"
                   "|         rule:      |\n"
                   "|                    |\n"
                   "| 1-everyone always  |\n"
                   "| makes the first    |\n"
                   "| move.              |\n"
                   "| 2-the bot will     |\n"
                   "| always attack in   |\n"
                   "| the same proportion|\n"
                   " -------------------- \n"
                   "| 3 = EXIT | OPTION: ");
            exit_settings = ler_inteiro();  // Usando a função de leitura para validar a entrada

            if (exit_settings == 3) {
                menu();
            } else {
                while (exit_settings != 3) {
                    printf("\n-------------------------------------------"
                           "\n!!ERRO:Você entrou com um caractere incorreto!!"
                           "\n-------------------------------------------"
                           "\nOPTION: ");
                    exit_settings = ler_inteiro();  // Usando a função de leitura para validar a entrada
                    if (exit_settings == 3) {
                        menu();
                    }
                }
            }
            break;

        case 3:
            rank();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\n-------------------------");
            printf("\n!!ERRO:Você entrou com um caractere incorreto!!");
            printf("\n-------------------------");
            break;
    }
}

// Função main
int main() {
    menu();
    return 0;
}