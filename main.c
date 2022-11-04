#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>


//First function, this is the Human mode, each player chooses the number of matches he wants to remove

int human() {

    // Name that does not exceed 20 characters
    char yourName[20]= "" ;
    
    //Ask the users to enter their names
    printf("Please enter your name:");
    scanf("%19s",&yourName);

    char friendName[20]= "" ;
    printf("Please enter the other name:");
    scanf("%19s",&friendName);
    
    //Initialization of the number of matches
    int matchsticksNumbers = 30 ;

    printf("It's your turn to play %s\n",&yourName);

    //loop as long as the number of matches is not equal to 0
    while (matchsticksNumbers!=0) {

        //Initialization of the variables
        int choice = 0;
        int match = 0;

        //Ask the user to pick between 1 and 3 matchsticks
        printf("Take 1 to 3 matches to remove them:\n");
        scanf("%d", &match);

        //Loop as long they do not enter between 1 and 3, a message is printed and the user must choose another number
        while(match > 3 || match < 1){
            printf("You cannot choose this number you cheater!\n"
                   "Choose another number\n");
            scanf("%d", &match);

            break;
        }
        
        /*The variable matchsticksNumbers will change each time the user chooses a new matchstick number called match. 
        MatchsticksNumbers inside the variable is always the last value retrieved */
        matchsticksNumbers = matchsticksNumbers - match;
 
        //print the matchsticks taking into consideration the last value of matchsticksNumbers
        for(int a =0; a<matchsticksNumbers;a++ ){
            printf("| ");
        }

        //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
        if(matchsticksNumbers <= 0){

            printf("O matchsticks left\n"
                       "you have lost!\n");
            printf("Do you want: \n"
                   "1- To play again\n"
                   "2- To see the scores\n"
                   "3- To quit\n"
                   "Your choice :");
            scanf("%d",&choice);
            if (choice == 1){
                printf("Welcome back!\n");

            }

            break;
        }
        
        //It's the turn to the other player
        printf("\n");
        printf("%d"" matchsticks left\nIt's your turn to play %s\n",matchsticksNumbers,&friendName);

    }

}

int easy(){

    // Name that does not exceed 20 characters
    char yourName[20]= "" ;

    //Ask the users to enter their names
    printf("Please enter your name:");

    scanf("%19s",&yourName);

    printf("Hi, me it's the computer Mr Robot!\n");

    //Initialization of the number of matches
    int matchsticksNumbers = 30 ;

    printf("It's your turn to play %s\n",&yourName);

    //loop as long as the number of matches is not equal to 0
    while (matchsticksNumbers!=0) {

        //Initialization of the variable
        int match = 0;
        
        //Ask the user to pick between 1 and 3 matchsticks
        printf("Take 1 to 3 matches to remove them: %s \n", &yourName);
        scanf("%d", &match);

        //Loop as long they do not enter between 1 and 3, a message is printed and the user must choose another number
        while(match > 3 || match < 1){
            printf("You cannot choose this number you cheater!\n"
                   "Choose another number\n");
            scanf("%d", &match);

            break;
        }
 
        /*The variable matchsticksNumbers will change each time the user chooses a new matchstick number called match. 
        MatchsticksNumbers inside the variable is always the last value retrieved */
        matchsticksNumbers = matchsticksNumbers - match;

        
        //print the matchsticks taking into consideration the last value of matchsticksNumbers
        for(int a =0; a<matchsticksNumbers;a++ ){
            printf("| ");
        }

        //Time to the computer to play!
        printf("\n");
        printf("%d"" matchsticks left\nIt's the turn to the computer to play\n",matchsticksNumbers);


        //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
        if(matchsticksNumbers <= 0){

            printf("O matchsticks left\n"
                   "you have lost!\n");
            break;
        }

           
            int num = rand() % 3 + 1; // use rand() function to get the random number
            printf(" %d ", num);
            getch();

            //print the number of matchsticks left
            printf("\n");
            printf("%d"" matchsticks left\n",matchsticksNumbers);



    }

}

int difficult() {

    // Name that does not exceed 20 characters
    char yourName[20] = "";

    //Ask the users to enter their names
    printf("Please enter your name:");

    scanf("%19s", &yourName);

    printf("Hi, me it's the computer Mr Robot!\n");

    //Initialization of the number of matches
    int matchsticksNumbers = 30;

    printf("It's your turn to play %s\n", &yourName);

    //loop as long as the number of matches is not equal to 0
    while (matchsticksNumbers != 0) {

        //Initialization of the variables
        int match = 0;

        //Ask the user to pick between 1 and 3 matchsticks
        printf("Take 1 to 3 matches to remove them:\n");
        scanf("%d", &match);

        //Loop as long they do not enter between 1 and 3, a message is printed and the user must choose another number
        while (match > 3 || match < 1) {
            printf("You cannot choose this number you cheater!\n"
                   "Choose another number\n");
            scanf("%d", &match);

            break;
        }

        /*The variable matchsticksNumbers will change each time the user chooses a new matchstick number called match. 
        MatchsticksNumbers inside the variable is always the last value retrieved */
        matchsticksNumbers = matchsticksNumbers - match;

        
        //print the matchsticks taking into consideration the last value of matchsticksNumbers
        for (int a = 0; a < matchsticksNumbers; a++) {
            printf("| ");
        }

        //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
        if (matchsticksNumbers <= 0 ) {

            printf("O matchsticks left\n"
                   "you have lost!\n");
            break;
        }

        //The turn to the computer
        printf("\n");
        printf("%d"" matchsticks left\nIt's the turn to the computer to play\n", matchsticksNumbers);

        /*Use of the multiples strategy, if the player decides to take 1 match, the computer will take 3. If the player takes 2, the computer 
        will take 2 and if the player takes 3 the computer will take 1. */

        switch (match) {
            case 1 :
                matchsticksNumbers = matchsticksNumbers - 3;
                for (int a = 0; a < matchsticksNumbers; a++) {
                    printf("| ");
                }

                printf("\n");
                printf("%d"" matchsticks left\n", matchsticksNumbers);
                break;
            case 2 :
                matchsticksNumbers = matchsticksNumbers - 2;
                for (int a = 0; a < matchsticksNumbers; a++) {
                    printf("| ");
                }

                printf("\n");
                printf("%d"" matchsticks left\n", matchsticksNumbers);
                break;
            case 3:
                matchsticksNumbers = matchsticksNumbers - 1;
                for (int a = 0; a < matchsticksNumbers; a++) {
                    printf("| ");
                }

                printf("\n");
                printf("%d"" matchsticks left\n", matchsticksNumbers);
                break;


        }
        
        //If the value matchsticksNumbers is smaller or equal to 0, so the last who played lost, return the function!
        if (matchsticksNumbers <= 0) {

            printf("O matchsticks left\n"
                   "the computer has lost!\n");
            break;
        }


    }

}

//Second function, the computer plays against the player according to the player's choice of level

int computer() {

    int choice = 0;

    //Ask the user to choose between 2 modes
    printf("Hi, My name is Mr Robot\n"
                            "Please choose the level mode: \n"
                            "1 - Easy\n"
                            "2 - Difficult\n"
                            "Your choice:\n");

    scanf("%d", &choice);

    //Option 1 is the easy level
    if (choice == 1) {

        printf("You chose the easy level!\n");
        return easy();
    }
    
    //Option 2 is the difficult level
    if (choice == 2) {
            printf("You chose the difficult level\n");
            return difficult();
        }
        return 0;
}


//Third function is to choose the mode

int play() {

        int choice = 0;

        //Ask the user to choose between the human mode or the computer mode
        printf("What mode do you want to choose?\n"
               "Your choice:\n"
               "1- Human mode\n"
               "2- Computer mode\n");

        scanf("%d", &choice);

        // Option 1 is the easy level
        if (choice == 1) {
            printf("You chose human mode!\n");
            return human();
        }
        
        //Option 2 is the difficult level
        if (choice == 2) {
            printf("You chose computer mode!\n");
            return computer();
        }
    }

//Fourth function is to quit the game
int quit() {

    printf("See you next time! Come back soon, we already miss you");
}



//Main function : Introductions, rules, see the scores, play or quit

int main() {

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
             "   3 - To see the scores\n"
             "   4 - To quit\n"
             "Your choice : ");

      scanf("%d", &choice);

      //Function to quit
      if (choice == 4) {
          return quit();

      }
      
      //Function to see the rules
      if (choice == 2) {
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
                 "Your choice:  "
          );
          scanf("%d", &choice);
          
          //Function to play 
          if (choice==1) {
              
              return play();
          }
          
          //Function to quit
          if (choice==2){
              
              return quit();
          }    
          
      }
        
      //Function to play the game
      if (choice == 1) {
          return play();
      }

      //Function to see the score
      if (choice == 3) {
          printf("Here are the score\n");
          printf("Return to the menu if you want!\n"
                 "1- Yes\n"
                 "2- No (quit)\n");
          scanf("%d", &choice );

          if (choice == 1) {
              return main();
          }

          if (choice == 2) {
              return quit();
          }

      }

   }

}


