#include <stdio.h>
#include <ctype.h>

int menufunc(){
    int menuchoice = 0;
    printf("\nMENU\n 1. Play the game\n 2. See the answers\n 3. Exit the game\n");
    printf("Enter your choice: ");
    scanf("%d", &menuchoice);   
    while(getchar() != '\n');   //clearing the input in case someone writes '12' or '32' accidentally
   
    return menuchoice;
}


void game(char questions[4][1000], char options[4][1000]){

     char userChoice;
     char answers[] = {'B', 'C', 'D', 'A'};
   
    int score = 0;

    for(int i = 0; i < 4; i++){

        printf("\n%s", questions[i]);
        printf("\n%s", options[i]);

        printf("\nEnter your choice: ");
        scanf(" %c", &userChoice);
        while (getchar() != '\n');
        
        userChoice = toupper(userChoice);  // 1. convert lowercase input ('a', 'b') to uppercase ('A', 'B')

        // 2. validate if it's A, B, C, or D
        if (userChoice < 'A' || userChoice > 'D') {
            printf("Invalid input! Please enter A, B, C, or D.\n");
        } 

        else if (userChoice == answers[i]) { // or choice1 == 'A', etc.
            printf("Correct! You earned one point.\n");
            score++;
        } 

        else {
            printf("Incorrect answer!\n");
        }
    
}

 if(score >= 2){
    printf("\nCongrats! Your final score is: %d \n", score);
 }
 else{
    printf("\nYour final score is %d, better luck next time!", score);
 }
  

int playagainchoice = 0;
    do{
       printf("\nDo you want to play again? 1 for YES, 2 for NO(Return to the Menu): ");
    if (scanf("%d", &playagainchoice) != 1) {
        playagainchoice = 0; // if you typed the letter
    }
    while (getchar() != '\n'); 

    if (playagainchoice == 1) {
        game(questions, options);
    } 
    else if (playagainchoice == 2) {
        break; // we dont need to type in menufunc(), because it will show automatically therefore it would double if we called the function here
    } 
    else {
        printf("\nInvalid choice! Type in 1 or 2.\n"); 
    }

    }while(playagainchoice != 1 && playagainchoice != 2);
    



int main() {

    printf("** QUIZZ GAME ** \n");

    char questions[4][50]  = {"What is the capital of USA?",        
                              "What is the closest planet to sun?",
                              "What is the derivative of x^2 ?", 
                              "Who invented Three Laws of Motion?"};

    char options[][100] = {
        "A. Washington\nB. Dallas\nC. Philadelphia\nD. Wyoming",
        "A. Mars\nB. Mercury\nC. Moon\nD. Jupiter",
        "A. 8x\nB. 4x\nC. We cant compute a derivative\nD. 2x",
        "A. DiCaprio\nB. Newton\nC. Einstein\nD. Bohr"
    };

    int menuchoice = 0;

    do {
        
        menuchoice = menufunc(); 

        switch (menuchoice) {
            case 1:
                game(questions, options);
                break;

            case 2:
                printf("\nAnswers: 'A', 'B', 'D', 'B'\n\n");
                break; // just break, because it will lead to infinite loop of Answers

            case 3:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (menuchoice != 3);  // doing the code until the input bumber is 3


    return 0;
}
