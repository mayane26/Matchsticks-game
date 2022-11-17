#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

void play();
void computer();
void quit();
void flush();

void color(int cText,int cBack)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,cBack*16+cText);
}

void decide(){

    int choice=0;
    printf("Do you want: \n"
           "1- To play again\n"
           "2- To quit\n"
           "Your choice :");

    scanf("%d", &choice);

    while(choice < 1 || choice > 2){
        printf("You cannot choose this number you cheater!\n"
               "Choose another number\n");

        flush();
        scanf("%d", &choice);

        break;
    }


    switch (choice) {
        case 1:
            printf("Welcome back!\n");
            play();


        case 2:
            quit();

    }

}

void flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

//Function to displays the matchs
void displayMatchs(int matchsticksNumbers){
    for (int a = 0; a < matchsticksNumbers; a++) {
        color(1,0);
        printf("| ");
    }
    color(15,0);

    for (int i = 0; i < 30 - matchsticksNumbers; i++) {
        color(1,0);
        printf("- ");
    }
    color(15,0);
}

//This is the Human mode, each player chooses the number of matches he wants to remove
void human() {

    // Name that does not exceed 20 characters
    char yourName[20] = "";

    //Ask the users to enter their names
    printf("Please enter your name:");
    scanf("%19s", &yourName);

    char friendName[20] = "";
    printf("Please enter the other name:");
    scanf("%19s", &friendName);


    //Initialization of the number of matches
    int matchsticksNumbers = 30;

    printf("It's your turn to play %s\n", &yourName);

    //Loop as long as the number of matches is not equal to 0
    while (matchsticksNumbers != 0) {

        //Initialization of the variables
        int choice = 0;
        int match = 0;
        int isJ1Playing;

        //Ask the user to pick between 1 and 3 matchsticks

        printf("Take 1 to 3 matches to remove them:\n");
        scanf("%d", &match);


        //Loop as long they do not enter between 1 and 3, a message is printed and the user must choose another number
        while(match < 1 || match > 3){
            printf("You cannot choose this number you cheater!\n"
                   "Choose another number\n");

            flush();
            scanf("%d", &match);

            break;
        }

        //If the matchs are equals to 1, 2 or 3 then:

        /*The variable matchsticksNumbers will change each time the user chooses a new matchstick number called match.
    MatchsticksNumbers inside the variable is always the last value retrieved */
        matchsticksNumbers = matchsticksNumbers - match;

        //print the matchsticks taking into consideration the last value of matchsticksNumbers
        displayMatchs(matchsticksNumbers);


        //If the matchsticksNumber is equal or inferior to 0 then the game is finished
        if (matchsticksNumbers <= 0) {

            if (isJ1Playing==0) {
                color(4,0);
                printf("O matchsticks left\n %s you have lost!\n", yourName);
                color(15,0);
                decide();
                break;

            }else{
                color(4,0);
                printf("O matchsticks left\n %s you have lost!\n", friendName);
                color(15,0);
                decide();
                break;
            }

        }



        if (isJ1Playing) {
            printf("\n%d matchsticks left\n", matchsticksNumbers);
            printf("\nIt's your turn to play %s\n", yourName);
            isJ1Playing = 0;

        } else {
            while(match < 1 || match > 3){
                printf("You cannot choose this number you cheater!\n"
                       "Choose another number\n");

                flush();
                scanf("%d", &match);

                break;
            }

            printf("\n");
            printf("%d"" matchsticks left\n"
                   "It's your turn to play %s\n", matchsticksNumbers, friendName);
            isJ1Playing = 1;

        }

    }


}


//This is the easy level computer method, the user chooses 1, 2 or 3 matchsticks and the computer chooses randomly
void easy() {



    // Name that does not exceed 20 characters
    char yourName[20] = "";

    //Ask the users to enter their names
    printf("Please enter your name:");

    scanf("%19s", &yourName);

    printf("Hi, me it's the computer Mr Robot!\n");

    //Initialization of the number of matches
    int matchsticksNumbers = 30;

    int isJ1Playing;

    //loop as long as the number of matches is not equal to 0
    while (matchsticksNumbers != 0) {

        //Initialization of the variables

        int match = 0;
        int num;

        //Ask the user to pick between 1 and 3 matchsticks

        printf("%s Take 1 to 3 matches to remove them:\n", &yourName);

        scanf("%d", &match);

        //Loop as long they do not enter between 1 and 3, a message is printed and the user must choose another number
        while (match > 3 || match < 1) {
            printf("You cannot choose this number you cheater!\n"
                   "Choose another number\n");
            flush();
            scanf("%d", &match);

            break;
        }


        /*The variable matchsticksNumbers will change each time the user chooses a new matchstick number called match.
        MatchsticksNumbers inside the variable is always the last value retrieved */
        matchsticksNumbers = matchsticksNumbers - match;


        //print the matchsticks taking into consideration the last value of matchsticksNumbers
        displayMatchs(matchsticksNumbers);


        //The turn to the computer
        printf("\n");
        printf("%d"" matchsticks left\n", matchsticksNumbers);

        if (isJ1Playing) {

            isJ1Playing = 0;

            //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
            if (matchsticksNumbers <= 0) {

                if (isJ1Playing==0) {

                    color(4,0);
                    printf("%s you have lost!\n", yourName);
                    color(15,0);
                    decide();
                    break;

                }


            }




        }else{

            isJ1Playing = 1;

            //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
            if (matchsticksNumbers <= 0) {

                if (isJ1Playing==1) {

                    color(4,0);
                    printf("O matchsticks left\n %s you have lost mrRobot!\n");
                    color(15,0);
                    decide();
                    break;

                }


            }

            printf("It's my turn\n");
            /*Use of the multiple's strategy, if the player decides to take 1 match, the computer will take 3. If the player takes 2, the computer
 will take 2 and if the player takes 3 the computer will take 1. */

            if (matchsticksNumbers == 1 ) {
                num = 1;
            }
            else if (matchsticksNumbers == 2 ) {
                num = 1;
            }
            else if (matchsticksNumbers == 3 ) {
                num = 2;
            }else {
                num = rand() % 3 + 1; // use rand() function to get the random
                // number
            }
                printf(" %d \n", num);


            matchsticksNumbers = matchsticksNumbers - num;
            displayMatchs(matchsticksNumbers);

            printf("\n");
            printf("%d matchsticks left\n", matchsticksNumbers);


        }



    }

}

void difficult() {

    // Name that does not exceed 20 characters
    char yourName[20] = "";

    //Ask the users to enter their names
    printf("Please enter your name:");

    scanf("%19s", &yourName);

    printf("Hi, me it's the computer Mr Robot!\n");

    //Initialization of the number of matches
    int matchsticksNumbers = 30;


    int isJ1Playing;

    //loop as long as the number of matches is not equal to 0
    while (matchsticksNumbers != 0) {

        //Initialization of the variables
        int choice=0;
        int match = 0;
        int matchComputer;

        //Ask the user to pick between 1 and 3 matchsticks

        printf("%s Take 1 to 3 matches to remove them:\n", &yourName);

        scanf("%d", &match);

        //Loop as long they do not enter between 1 and 3, a message is printed and the user must choose another number
        while (match > 3 || match < 1) {
            printf("You cannot choose this number you cheater!\n"
                   "Choose another number\n");
            flush();
            scanf("%d", &match);

            break;
        }


        /*The variable matchsticksNumbers will change each time the user chooses a new matchstick number called match.
        MatchsticksNumbers inside the variable is always the last value retrieved */
        matchsticksNumbers = matchsticksNumbers - match;


        //print the matchsticks taking into consideration the last value of matchsticksNumbers
        displayMatchs(matchsticksNumbers);


        //The turn to the computer
        printf("\n");
        printf("%d"" matchsticks left\n", matchsticksNumbers);

        if (isJ1Playing) {

            isJ1Playing = 0;

            //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
            if (matchsticksNumbers <= 0) {

                if (isJ1Playing==0) {

                    color(4,0);
                    printf("%s you have lost!\n", yourName);
                    color(15,0);
                    decide();
                    break;

                }


            }

            printf("It's your turn to play %s\n", &yourName);


        }else{
            isJ1Playing = 1;

            if (matchsticksNumbers <= 0) {
                //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
                if (isJ1Playing==1) {

                    color(4,0);
                    printf("O matchsticks left\n %s you have lost mrRobot!\n");
                    color(15,0);
                    decide();
                    break;

                }


            }

            printf("It's my turn\n");
            /*Use of the multiple's strategy, if the player decides to take 1 match, the computer will take 3. If the player takes 2, the computer
 will take 2 and if the player takes 3 the computer will take 1. */

            if (matchsticksNumbers == 1 ) {
                matchComputer = 1;
            }
            else if (matchsticksNumbers == 2 ) {
                matchComputer = 1;
            }
            else if (matchsticksNumbers == 3 ) {
                matchComputer = 2;
            }
            else if (matchsticksNumbers == 4 ) {
                matchComputer = 3;
            }
            else{
                matchComputer = matchsticksNumbers % 4 + 1;
            }


            matchsticksNumbers = matchsticksNumbers - matchComputer;
            displayMatchs(matchsticksNumbers);



            printf("\n");
            printf("%d matchsticks left\n", matchsticksNumbers);

        }





    }

}


//Second function, the computer plays against the player according to the player's choice of level

void computer() {

    int choice = 0;

    //Ask the user to choose between 2 modes
    printf("Hi, My name is Mr Robot\n"
           "Please choose the level mode: \n"
           "1 - Easy\n"
           "2 - Difficult\n"
           "Your choice:\n");

    scanf("%d", &choice);

    //Loop as long they do not enter between 1 and 3, a message is printed and the user must choose another number
    while(choice < 1 || choice > 2){
        printf("It is not an option!\n"
               "Please choose between 1 or 2\n");
        flush();
        scanf("%d", &choice);

        break;
    }

    switch (choice) {
        //Option 1 is the easy level
        case 1:
            printf("You chose the easy level!\n");
            easy();
            break;

            //Option 2 is the difficult level
        case 2:
            printf("You chose the difficult level\n");
            difficult();
            break;
    }

}


//Third function is to choose the mode
void play() {

    int choice = 0;

    //Ask the user to choose between the human mode or the computer mode
    printf("What mode do you want to choose?\n"
           "Your choice:\n"
           "1- Human mode\n"
           "2- Computer mode\n");


    scanf("%d", &choice);

    //Loop as long they do not enter between 1 or 2
    while(choice < 1 || choice > 2){
        printf("You cannot choose this option!\n"
               "Please choose another number\n");
        flush();
        scanf("%d", &choice);

        break;
    }

    switch (choice) {
        //Option 1 is the Human mode
        case 1:

            printf("You chose human mode!\n");
            human();
            break;

        case 2:

            printf("You chose computer mode!\n");
            computer();
            break;
    }



}


//Fourth function is to quit the game
void quit() {

    char ch;

    printf("Please press the ENTER key\n");

//read a single character
    ch=fgetc(stdin);
    if(ch==0x0A)
    {
        printf("Thank you, see you next time! Come back soon, we already miss you!\n");

    }



}

void rules(){

    //Set the variable choice
    int choice =0;

    //Print the rules and let the user choice if he wants to play or quit
    printf("The goal of the game is simple\n"
           "This game is played with one or two players\n"
           "There are two modes:\n"
           "  1 - Human mode (play with a friend for example)\n"
           "  2 - Computer mode\n"
           "For the human mode each player removes 1 to 3 matchsticks maximum. The loser is the one "
           "who has to remove the last one\n"
           "matchstick\n"
           "For the computer mode, the user plays against the computer\n"
           "** Warning! For the computer mode, there are 2 levels. **\n"
           "The easy level for beginners and the hard level for the experimented ones\n"
           " *** What to do? ***\n"
           "    1 - Play\n"
           "    2 - Quit\n"
           "Your choice:  ");

    scanf("%d", &choice);

    //Loop as long they do not enter between 1 or 2
    while(choice < 1 || choice > 2){
        printf("You cannot choose this option!\n"
               "Please choose another number\n");
        flush();
        scanf("%d", &choice);

    }

    switch (choice) {

        //Function to play
        case 1:
            play();
            break;

            //Function to quit
        case 2:
            quit();
            break;

    }

}



//Main function : Introductions, rules, see the scores, play or quit

void main() {

    bool isRunning = true;

    while(isRunning) {

        int choice = 0;

        //Ask the user to choose between 4 options
        printf("  **** Hello, and welcome to the matchsticks game!****\n"
               "Here are 3 menus:\n"
               "You will first choose if you want to see the rules of the games or not,\n"
               "then the matchsticks number to use,\n"
               "and finally the numbers of the players...\n"
               "  *What to do* ?\n"
               "   1 - To play\n"
               "   2 - To see the rules of the game\n"
               "   3 - To see the credits\n"
               "   4 - To quit\n"
               "Your choice : ");


        scanf("%d", &choice);

        //Loop as long they do not enter options between 1 and 4
        while(choice < 1 || choice > 4){
            printf("You cannot choose this option!\n"
                   "Please choose another option\n");
            flush();
            scanf("%d", &choice);

            break;
        }


        switch (choice) {

            //Function to play
            case 1:
                play();
                break;

                //Function to see the rules
            case 2:
                rules();
                break;

                //To see the credits
            case 3:
                printf("************** CREDITS ****************\n"
                       " **This code was made by Mayane Maman**\n\n ");
                printf("Do you want to play again or not?\n"
                       "1- Play\n"
                       "2- Quit\n");
                flush();
                scanf("%d", &choice );

                //Loop as long they do not enter between 1 or 2
                while(choice < 1 || choice > 2){
                    printf("You cannot choose this option!\n"
                           "Please choose another number\n");

                    flush();
                    scanf("%d", &choice);

                }

                switch (choice) {
                    case 1:
                        play();
                        break;
                    case 2:
                        quit();
                        break;


                }
                break;


                //Function to quit
            case 4:
                quit();
                break;

        }break;


    }

}


