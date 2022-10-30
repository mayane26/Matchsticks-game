int main() {

    char yourName[20]= "" ;

    printf("Please enter your name:");

    scanf("%19s",&yourName);

    printf("Hi, me it's the computer Mr Robot!\n");

    int matchsticksNumbers = 30 ;

    printf("It's your turn to play %s\n",&yourName);

    while (matchsticksNumbers!=0) {

        int match = 0;

        printf("Take 1 to 3 matches to remove them:\n");
        scanf("%d", &match);


        while(match > 3 || match < 1){
            printf("You cannot choose this number you cheater!\n"
                   "Choose another number\n");
            scanf("%d", &match);

            break;
        }

        matchsticksNumbers = matchsticksNumbers - match;
        for(int a =0; a<matchsticksNumbers;a++ ){
            printf("| ");
        }

        printf("\n");
        printf("%d"" matchsticks left\nIt's the turn to the computer to play\n",matchsticksNumbers);


        if(matchsticksNumbers <= 0){

            printf("O matchsticks left\n"
                   "you have lost!\n");
            break;
        }

        for (int i = 1; i++;) {
            int num = rand() % 3 + 1; // use rand() function to get the random number
            printf(" %d ", num);
            getch();

        }


    }

}
