/******************
Name:Ilan Mulakandov
ID:325842847
Assignment: 2
*******************/

#include <stdio.h>

int main()
{
    // VARIABLES DECLARATION
    char userChoice = 0;
    const int decimalValueOfCharZero = '0';
    int userChoiceNumber=0;
    int nextChar=0;

    // task one vars
    int taskOneChoosingNum=0;
    int taskOneHelpInt=0;
    int sumOfOnesForTaskOne=0;

    // task two vars
    int taskTwoDucksNum=0;
    int isQuackBit=0;
    int userChoiceQuackOrSh=0;
    unsigned long long taskTwoBitsNum=0;

    // task three vars
    int taskThreeBaseNum=0;
    int taskThreeExponentNum=0;
    int taskThreeResultNum=1;

    // task four vars
    int taskFourDucksNum=0;
    const int taskFourMaxDucksInARow=10;

    // task five vars
    int taskFiveInputNum=0;
    int taskFiveHelpVarForSavingInput=0;
    int taskFiveHowManyDigitInTheInput=0;
    int currentDigit=0;
    const int decimalBase=10;

    // MAIN MENU LOOP
    do
    {
        printf("Welcome to our games, please choose an option\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");

        
        scanf(" %c", &userChoice);

        // until we don't get a valid char number from '0' to '9'
        nextChar = getchar();
        if(nextChar!= '\n' && nextChar != EOF){
            while (nextChar != '\n' && nextChar != EOF) {
                nextChar = getchar(); 
            }
            userChoice = ' '; // reset userChoice to an invalid value
        }

        // Transform the char value to decimal according to the value of the char 0
        userChoiceNumber = (int)(userChoice)-decimalValueOfCharZero;

        switch(userChoiceNumber)
        {
            // TASK 1: Ducky's Unity Game
            case 1:
                printf("please enter a positive number:\n");
                scanf(" %d", &taskOneChoosingNum);
                
                // until we don't get positive number
                while(taskOneChoosingNum<=0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskOneChoosingNum);
                    
                    // clearing the input buffer
                    nextChar = getchar();
                    while (nextChar != '\n' && nextChar != EOF) {
                        nextChar = getchar(); 
                    }
                }

                taskOneHelpInt = taskOneChoosingNum;
                
                while(taskOneHelpInt>0)
                {
                    // Check using & if the last bit is 1 
                    if(taskOneHelpInt & 1){
                        // ducky earned one more golden corn
                        sumOfOnesForTaskOne +=1;
                    }
                        
                    // moving 1 bit to right for check the next bit
                    taskOneHelpInt = taskOneHelpInt>>1;

                }
                
                printf("Ducky earns %d corns\n", sumOfOnesForTaskOne);
                sumOfOnesForTaskOne=0; // resetting for future use
                break;
                

            // TASK 2: The Memory Game
            case 2:
                
                // resetting for future use
                taskTwoBitsNum=0; 
                
                printf("please enter the number of ducks:\n");
                scanf(" %d",&taskTwoDucksNum);
                printf("you entered %d ducks\n", taskTwoDucksNum);

                // until we don't get positive number
                while(taskTwoDucksNum<=0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskTwoDucksNum);
                    
                    // clearing the input buffer
                    nextChar = getchar();
                    while (nextChar != '\n' && nextChar != EOF) {
                        nextChar = getchar(); 
                    }
                }

                // getting the quack/shout choices from the user
                for(int i=0; i<taskTwoDucksNum; i++){
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i+1);
                    scanf(" %d", &userChoiceQuackOrSh);
                    while(userChoiceQuackOrSh!=1 && userChoiceQuackOrSh!=0){
                        printf("Invalid number, please try again\n");
                        scanf(" %d", &userChoiceQuackOrSh);
                        
                        // clearing the input buffer
                        nextChar = getchar();
                        while (nextChar != '\n' && nextChar != EOF) {
                            nextChar = getchar(); 
                        }
                    }
                    if(userChoiceQuackOrSh){
                        taskTwoBitsNum|=(unsigned long long)userChoiceQuackOrSh<<i; //Check this!!!!!!!!!!!!!!!!!!!!
                    }
                }
                                
                // printing the quack/shout choices
                for(int i=0; i<taskTwoDucksNum; i++){
                    
                    // checking if the last bit is 1 or 0 using &
                    isQuackBit = (taskTwoBitsNum >> i) & 1;
                    
                    // printing according to the extracted bit
                    if(isQuackBit){
                        printf("duck number %d do Quak\n", i+1);
                    }
                    else{
                        printf("duck number %d do Sh...\n", i+1);
                    }
                }

                break;

            // TASK 3: Professor Pat's Power Calculation
            case 3:

                // resetting for future use
                taskThreeResultNum=1;

                printf("please enter the number\n");
                scanf(" %d", &taskThreeBaseNum);

                // until we don't get non negetive number we keep asking for input
                while(taskThreeBaseNum<0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskThreeBaseNum);
                    
                    // clearing the input buffer
                    nextChar = getchar();
                    while (nextChar != '\n' && nextChar != EOF) {
                        nextChar = getchar(); 
                    }
                }

                printf("please enter the exponent\n");
                scanf(" %d", &taskThreeExponentNum);

                // until we don't get non negetive number we keep asking for input
                while(taskThreeExponentNum<0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskThreeExponentNum);
                    
                    // clearing the input buffer
                    nextChar = getchar();
                    while (nextChar != '\n' && nextChar != EOF) {
                        nextChar = getchar(); 
                    }
                }

                // calculating the number by the power
                for(int i=0; i<taskThreeExponentNum; i++){
                    taskThreeResultNum *= taskThreeBaseNum;
                }

                printf("your power is: %d\n", taskThreeResultNum);
                break;

            
            // TASK 4: The Duck Parade
            case 4:
                printf("please enter number of ducks:\n");
                scanf(" %d",&taskFourDucksNum);
                
                // until we don't get positive number we keep asking for input
                while(taskFourDucksNum<0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskFourDucksNum);
                    
                    // clearing the input buffer
                    nextChar = getchar();
                    while (nextChar != '\n' && nextChar != EOF) {
                        nextChar = getchar(); 
                    }
                }
                
                // until we have more ducks than the max in a row
                while (taskFourDucksNum > taskFourMaxDucksInARow){
                    // print a full row (10 ducks) heades
                    for(int i=0; i<taskFourMaxDucksInARow; i++){
                        printf("   _\t\t");
                    }
                    printf("\n");

                    // print a full row (10 ducks) beaks
                    for(int i=0; i<taskFourMaxDucksInARow; i++){
                        printf("__(o)>\t\t");
                    }

                    // print a full row (10 ducks) bodies
                    printf("\n");
                    for(int i=0; i<taskFourMaxDucksInARow; i++){
                        printf("\\___)\t\t");
                    }
                    printf("\n");

                    // decrease the number of ducks left to print
                    taskFourDucksNum -= taskFourMaxDucksInARow;
                }

                // print the last row with the remaining ducks

                for(int i=0; i<taskFourDucksNum; i++){
                    printf("   _\t\t");
                }
                printf("\n");
                for(int i=0; i<taskFourDucksNum; i++){
                    printf("__(o)>\t\t");
                }
                printf("\n");
                for(int i=0; i<taskFourDucksNum; i++){
                    printf("\\___)\t\t");
                }
                printf("\n");
                break;

            // TASK 5: The Mystery of the Repeated Digits
            case 5:

                // resetting for future use
                taskFiveHowManyDigitInTheInput=0;
                taskFiveInputNum=0;

                printf("please enter number:\n");
                scanf(" %d", &taskFiveInputNum);
                
                // until we don't get positive number we keep asking for input
                while(taskFiveInputNum<=0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskFiveInputNum);
                    
                    // clearing the input buffer
                    nextChar = getchar();
                    while (nextChar != '\n' && nextChar != EOF) {
                        nextChar = getchar(); 
                    }
                }

                // resetting vars for future use
                taskFiveHelpVarForSavingInput=taskFiveInputNum;
                
                // counting how many digits in the input number
                // and saving it in taskFiveHowManyDigitInTheInput
                while(taskFiveHelpVarForSavingInput>0){
                    // counting one more digit
                    taskFiveHowManyDigitInTheInput+=1;

                    // cutting the last digit
                    taskFiveHelpVarForSavingInput= taskFiveHelpVarForSavingInput/decimalBase;
                }

                // resetting for future use
                taskFiveHelpVarForSavingInput=taskFiveInputNum;
                
                // checking for each digit if it appears more than once
                // acording to orders
                for(int i=0;i<taskFiveHowManyDigitInTheInput;i++){
                    currentDigit=taskFiveHelpVarForSavingInput%decimalBase;
                    
                    // checking if we have the same digit in the rest of the digits
                    while(taskFiveHelpVarForSavingInput>0){
                        
                        taskFiveHelpVarForSavingInput= taskFiveHelpVarForSavingInput/decimalBase;
                        
                        // if we reach 0 it means we checked all the digits
                        if(taskFiveHelpVarForSavingInput==0){
                            break;
                        }
                        
                        // if we found the same digit we print and break
                        if(currentDigit==taskFiveHelpVarForSavingInput%decimalBase){
                            printf("%d appears more than once!\n", currentDigit);
                            break;
                        }
                    }

                    // preparing for the next digit check
                    // cutting the last digit that we just checked and saving the rest
                    taskFiveInputNum=taskFiveInputNum/decimalBase;
                    taskFiveHelpVarForSavingInput=taskFiveInputNum;
                }
                break;
            // TASK 6: EXIT
            case 6:
                printf("Good night! See you at the pond tomorrow.");
                break;

            // INVALID INPUT HANDLING
            default:
                printf("Invalid option, please try again\n");
                break;
        }
    }
    while (
        // condition to continue looping until user choose exsit (6)
        userChoiceNumber != 6
    );
    return 0;
}