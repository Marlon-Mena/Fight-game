#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that creates a random attack, with
// the values inside it; this function is for the
// player. This character is the blacksmith!
int random_ataque1(){
return rand() % 10 + 5;
}
int random_ataque2(){
    return rand() % 30 + 10; 
}
int random_ataque3(){
    return rand() % 22 + 20; 
}
int random_heal(){
    return rand() % 30 + 11; 
}

// Function that creates a random attack with
// the values inside it; this function is for the
// BOT. This character is the GAINT!
int faca(){
    return rand() % 10 + 5; 
}
int revolver(){
    return rand() % 30 + 10; 
}
int marreta(){
    return rand() % 22 + 20; 
}
int cura(){
    return rand() % 30 + 11; 
}


// Game function
// the fight takes place in this code
void jogo()
{
    int character = 100, bot = 100; 
    
    printf("\n\n------------------\n");
    printf("! Start the game !");
    printf("\n------------------\n\n\n\n");

// here he will choose which attack to use on the enemy and receive  
// but as long as one of the health points doesn't reach 0, it will keep repeating
    while (character > 0 && bot > 0){
        printf("STATISTICS:\n"); 
        printf("Your health is at %d, while the enemy's health is at %d \n\n", character, bot); 
        printf("1 == Attack with the KNIFE\n"); 
        printf("2 == Attack with the GUN\n");
        printf("3 == Attack with the HAMMER\n\n"); 
        printf("4 == Healing potion\n\n");
        
        printf("Choose: ");  
        int escolha; 
        scanf("%d", &escolha); 
             
        switch(escolha){
            case 1: 
                printf("\n--You managed to stab him a few times!--\n\n"); 
                bot = bot - faca(); 
                character = character - random_ataque1();
                    if(bot <= 0){
                        printf("!--WIN--!");
                    }
                    else if(character <= 0){
                        printf("!--DEAD--!");
                    }
                break;
            case 2: 
                printf("\n--You managed to shoot him a few times!--\n\n"); 
                bot = bot - revolver();
                character = character - random_ataque2();
                    if(bot <= 0){
                        printf("!--WIN--!");
                    }
                    else if(character <= 0){
                        printf("!--DEAD--!");
                    }
                break;
            case 3: 
                printf("\n--You managed to hit him with the hammer!--\n\n"); 
                bot = bot - marreta();
                character = character - random_ataque3();
                    if(bot <= 0){
                        printf("!--WIN--!");
                    }
                    else if(character <= 0){
                        printf("!--DEAD--!");
                    }
                break;
                
            case 4:
                printf("\n--You managed to heal yourself--\n\n");
                bot = bot + cura();
                character = character + random_heal();
                    if(bot <= 0){
                        printf("!--WIN--!\n\n");
                    }
                    else if(character <= 0){
                        printf("!--DEAD--!\n\n");
                    }
                break;
                    
            default:
                printf("\n-------------------------------------------"
                    "\n!!ERRO:You entered an incorrect character!!"
                    "\n-------------------------------------------"
                    "\nOPTION: ");
                break;
                
        }
    }
}

//Rank
void rank(){
	int option;

	printf("\n -----------------\n"
        "|      RANK       |\n"
        "|                 |\n"
        "|   1 = WIN/DEAD  |\n"
        "|   2 = EXIT      |\n"
        " -----------------\n"
        "OPTION: ");
	scanf("%d", &option);

	while (option != 1|| option != 2){
	printf("OPTION: ");
	scanf("%d", &option);
	}

	switch(option){
		case 1:

			break;
		case 2:
			exit;
			break;
	}
}

// main game code  
// menu, settings, and others
void menu(){
    
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
    scanf("%d", &option);
    
    while (option <= 0 || option >= 4){
        printf("\n-------------------------------------------"
            "\n!!ERRO:You entered an incorrect character!!"
            "\n-------------------------------------------"
            "\nOPTION: ");
        scanf("%d", &option);
    }
    
    switch(option){
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
            
            scanf("%d", &exit_settings);
                if(exit_settings == 3){
                    menu();
                }
                else{
                    while (exit_settings != 3){
                        printf("\n-------------------------------------------"
                            "\n!!ERRO:You entered an incorrect character!!"
                            "\n-------------------------------------------"
                            "\nOPTION: ");
                        scanf("%d", &exit_settings);
                            if(exit_settings == 3){
                                menu();
                        }
                    }
                }
            break;

	case 3:
		rank();
	    break;
        case 4:
            	exit;
                break;
        default:
            printf("\n-------------------------");
            printf("\n!!ERRO:You entered an incorrect character!!");
            printf("\n--------------------------------");
                break;
    }
}

// MAIN, or principal, is the main code
// that call' the menu function to
// initialize the game
int main(){
           menu(); 
    return 0;
    
}
