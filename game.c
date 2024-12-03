#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função auxiliar para garantir que o usuário digite apenas números inteiros
int ler_inteiro() {
    int valor;

    while (scanf("%d", &valor) != 1) {  // Verifica se a leitura foi bem-sucedida
        while (getchar() != '\n');  // Limpa o buffer de entrada
        printf("Entrada inválida! Por favor, digite um número inteiro: ");
    }
    return valor;
}

// Protótipos das funções
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

// Variáveis globais
int win = 0, dead = 0;

//-----------------------------------------------

// Funções para ataques aleatórios e cura
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
    int personagem = 100, bot = 100, contador = 2;

    printf("\n\n------------------\n");
    printf("! Comece o jogo !\n");
    printf("------------------\n\n\n\n");

    while (personagem > 0 && bot > 0) {
        if (personagem > 150 && bot > 150) {
            printf("\n\n  -----------------------------------------\n");
            printf("| Oops... sua vida já está no limite. |\n");
            printf("| Oops... sua vida já está no limite. |\n");
            printf("| Oops... sua vida já está no limite. |\n");
            printf("| Oops... sua vida já está no limite. |\n");
            printf("  -----------------------------------------\n\n");
            jogo();
        } else {
            printf("ESTATÍSTICAS:\n");
            printf("Sua vida está em %d, enquanto a vida do inimigo está em %d \n\n", personagem, bot);
            printf("1 == Ataque com a FACA\n");
            printf("2 == Ataque com o REVÓLVER\n");
            printf("3 == Ataque com o MARTELO\n\n");
            printf("4 == Poção de cura\n\n");

            printf("Escolha: ");
            int escolha = ler_inteiro();

            switch (escolha) {
                case 1:
                    printf("\n--Você conseguiu esfaqueá-lo algumas vezes!--\n\n");
                    bot = bot - faca();
                    personagem = personagem - random_ataque1();
                    if (bot <= 0) {
                        printf("!--VITÓRIA--!\n\n");
                        win = win + 1;
                        menu();
                    } else if (personagem <= 0) {
                        printf("!--DERROTA--!\n\n");
                        dead = dead + 1;
                        menu();
                    }
                    break;

                case 2:
                    printf("\n--Você conseguiu atirar nele algumas vezes!--\n\n");
                    bot = bot - revolver();
                    personagem = personagem - random_ataque2();
                    if (bot <= 0) {
                        printf("!--VITÓRIA--!\n\n");
                        win = win + 1;
                        menu();
                    } else if (personagem <= 0) {
                        printf("!--DERROTA--!\n\n");
                        dead = dead + 1;
                        menu();
                    }
                    break;

                case 3:
                    printf("\n--Você conseguiu acertá-lo com o martelo!--\n\n");
                    bot = bot - marreta();
                    personagem = personagem - random_ataque3();
                    if (bot <= 0) {
                        printf("!--VITÓRIA--!\n\n");
                        win = win + 1;
                        menu();
                    } else if (personagem <= 0) {
                        printf("!--DERROTA--!\n\n");
                        dead = dead + 1;
                        menu();
                    }
                    break;

                case 4:
                    if (contador > 0) {
                        printf("\n--Você conseguiu se curar--\n\n");
                        bot = bot + cura();
                        personagem = personagem + random_heal();
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
    int opcao;

    printf("\n -----------------\n"
           "|      RANK       |\n"
           "|                 |\n"
           "|   1 = WIN/DEAD  |\n"
           "|   2 = SAIR      |\n"
           " -----------------\n"
           "OPÇÃO: ");
    opcao = ler_inteiro();

    while (opcao < 1 || opcao > 2) {
        printf("\n-------------------------------------------"
               "\n!!ERRO: Você entrou com um caractere incorreto!!"
               "\n-------------------------------------------"
               "\nOPÇÃO: ");
        opcao = ler_inteiro();
    }

    switch (opcao) {
        case 1:
            printf("\n -----------------\n"
                   "|   VITÓRIA / DERROTA |\n"
                   "|                     |\n"
                   "|   VITÓRIA = %d       |\n"
                   "|   DERROTA = %d       |\n"
                   "|                     |\n"
                   "|   2 = SAIR          |\n"
                   " -----------------\n"
                   "OPÇÃO: ", win, dead);
            opcao = ler_inteiro();
            while(opcao != 2){
                        printf("\n-------------------------------------------"
               "\n!!ERRO: Você entrou com um caractere incorreto!!"
               "\n-------------------------------------------"
               "\nOPÇÃO: ");
        opcao = ler_inteiro();
            }
            if(opcao == 2){
                menu();
            }
            break;

        case 2:
            menu();
            break;
    }
}

// Função Menu com verificação de entrada
void menu() {
    int opcao, sair_config;

    printf("\n -----------------\n"
           "|    The King     |\n"
           "|  Jogo de Luta   |\n"
           "|     1 x 1       |\n"
           "|                 |\n"
           "|   1 = NOVO JOGO |\n"
           "|   2 = CONFIG    |\n"
           "|   3 = RANK      |\n"
           "|   4 = SAIR      |\n"
           " -----------------\n"
           "OPÇÃO: ");
    opcao = ler_inteiro();

    while (opcao < 1 || opcao > 4) {
        printf("\n-------------------------------------------"
               "\n!!ERRO: Você entrou com um caractere incorreto!!"
               "\n-------------------------------------------"
               "\nOPÇÃO: ");
        opcao = ler_inteiro();
    }

    switch (opcao) {
        case 1:
            srand(time(NULL));
            jogo();
            break;

        case 2:
            printf("\n\n  -----CONFIGURAÇÕES-----\n"
                   "|      BOTÕES:           |\n"
                   "|     1  2  3  4         |\n"
                   "|                        |\n"
                   "|         Regras:        |\n"
                   "|                        |\n"
                   "| 1-O jogador sempre     |\n"
                   "| faz o primeiro         |\n"
                   "| movimento.             |\n"
                   "| 2-O bot atacará        |\n"
                   "| sempre na mesma        |\n"
                   "| proporção.             |\n"
                   " -------------------------\n"
                   "| 3 = SAIR | OPÇÃO: ");
            sair_config = ler_inteiro();

            if (sair_config == 3) {
                menu();
            } else {
                while (sair_config != 3) {
                    printf("\n-------------------------------------------"
                           "\n!!ERRO: Você entrou com um caractere incorreto!!"
                           "\n-------------------------------------------"
                           "\nOPÇÃO: ");
                    sair_config = ler_inteiro();
                    if (sair_config == 3) {
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
            printf("\n!!ERRO: Você entrou com um caractere incorreto!!");
            printf("\n-------------------------");
            break;
    }
}

// Função principal
int main() {
    menu();
    return 0;
}
