/******************
Name:
ID:
Assignment:
*******************/

#include <stdio.h>

int main()
{
    // TASK 1: Ducky's Unity Game

    // TASK 2: The Memory Game

    // TASK 3: Professor Pat's Power Calculation

    // TASK 4: The Duck Parade

    // TASK 5: The Mystery of the Repeated Digits

    // TASK 6: EXIT

    // dont forget through all the necessary parts to validate invalid input.
    char userChoice = 0;
    const int decimalValueOfCharZero = 48;
    int userChoiceNumber;

    // task one vars
    int taskOneChoosingNum=0, taskOneHelpInt=0, sumOfOnesForTaskOne=0 ;

    // task two vars
    int taskTwoDucksNum=0;
    long long taskTwoSaveBitsNum=0, taskTwoExtractBitsNum=0;

    // task three vars
    int taskThreeBaseNum=0, taskThreeExponentNum=0, taskThreeResultNum=1;

    // task four vars
    int taskFourDucksNum=0;
    const int taskFourmaxDucksInARow=10;

    // task five vars
    int taskFiveInputNum=0, newNumbers=0;
    int taskFiveHelpVarForSavingInput=0,taskFivehowManyDigitInTheInput=0, helpNewNumbers=0;
    int currentDigit=0, currentDigitPlaceValue=0;
    bool isDigitInNewNumbers;
    // MAIN MENU LOOP
    do
    {
        printf("Welcome to our games, plase choose an option\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");

        
        scanf(" %C", &userChoice);

        // until we don't get a valid char number from '0' to '9'
        int nextChar = getchar();
        if (userChoice >= '0' && userChoice <= '6'){
            if(nextChar!= '\n' && nextChar != EOF){
                while (nextChar != '\n' && nextChar != EOF) {
                    nextChar = getchar(); 
                }
                userChoice = ' '; // reset userChoice to an invalid value
            }
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

                printf("please enter the number of ducks:\n");
                scanf(" %d",&taskTwoDucksNum);
                printf("you entered %d ducks\n", taskTwoDucksNum);

                // until we don't get positive number
                while(taskTwoDucksNum<=0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskTwoDucksNum);
                }

                int userChoiceQuackSh;

                // getting the quack/shout choices from the user
                for(int i=1; i<=taskTwoDucksNum; i++){
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i);
                    scanf(" %d", &userChoiceQuackSh);
                    while(userChoiceQuackSh!=1 && userChoiceQuackSh!=0){
                        printf("Invalid number, please try again\n");
                        scanf(" %d", &userChoiceQuackSh);
                    }
                    taskTwoSaveBitsNum|=userChoiceQuackSh<<i; //Check this!!!!!!!!!!!!!!!!!!!!
                }
                
                // extracting one bit because their is an extra 0 at the start
                // that added because the shifting in the end of the loop  
                taskTwoExtractBitsNum = taskTwoSaveBitsNum>>1;//Check this!!!!!!!!!!!!!!!!!!!!
                
                // printing the quack/shout choices
                for(int i=1; i<=taskTwoDucksNum; i++){
                    
                    // checking if the last bit is 1 or 0 using &
                    int checkQuackBit = taskTwoExtractBitsNum & 1;
                    
                    printf("%lld: \n", taskTwoSaveBitsNum);

                    // printing according to the extracted bit
                    if(checkQuackBit){
                        printf("duck number %d do Quak\n", i);
                    }
                    else{
                        printf("duck number %d do Sh...\n", i);
                    }
                    
                    // moving 1 bit to right for extract the next bit
                    taskTwoExtractBitsNum = taskTwoExtractBitsNum >> 1;
                }

                break;

            // TASK 3: Professor Pat's Power Calculation
            case 3:
                printf("please enter the number\n");
                scanf(" %d", &taskThreeBaseNum);

                // until we don't get non negetive number we keep asking for input
                while(taskThreeBaseNum<0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskThreeBaseNum);
                }

                printf("please enter the exponent\n");
                scanf(" %d", &taskThreeExponentNum);

                // until we don't get non negetive number we keep asking for input
                while(taskThreeExponentNum<0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskThreeExponentNum);
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
                }
                
                // until we have more ducks than the max in a row
                while (taskFourDucksNum > taskFourmaxDucksInARow){
                    // print a full row (10 ducks) heades
                    for(int i=0; i<taskFourmaxDucksInARow; i++){
                        printf("   _        ");
                    }
                    printf("\n");

                    // print a full row (10 ducks) beaks
                    for(int i=0; i<taskFourmaxDucksInARow; i++){
                        printf("__(o)>      ");
                    }

                    // print a full row (10 ducks) bodies
                    printf("\n");
                    for(int i=0; i<taskFourmaxDucksInARow; i++){
                        printf("\\___)       ");
                    }
                    printf("\n");

                    // decrease the number of ducks left to print
                    taskFourDucksNum -= taskFourmaxDucksInARow;
                }

                // print the last row with the remaining ducks

                for(int i=0; i<taskFourDucksNum; i++){
                    printf("   _        ");
                }
                printf("\n");
                for(int i=0; i<taskFourDucksNum; i++){
                    printf("__(o)>      ");
                }
                printf("\n");
                for(int i=0; i<taskFourDucksNum; i++){
                    printf("\\___)       ");
                }
                printf("\n");
                break;

            // TASK 5: The Mystery of the Repeated Digits
            case 5:
                printf("please enter number:\n");
                scanf(" %d", &taskFiveInputNum);
                
                // until we don't get positive number we keep asking for input
                while(taskFiveInputNum<=0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskFiveInputNum);
                }

                // resetting vars for future use
                taskFiveHelpVarForSavingInput=taskFiveInputNum;
                
                // counting how many digits in the input number
                // and saving it in taskFivehowManyDigitInTheInput
                while(taskFiveHelpVarForSavingInput>0){
                    taskFivehowManyDigitInTheInput+=1;
                    taskFiveHelpVarForSavingInput= taskFiveHelpVarForSavingInput/10;
                }


                taskFiveHelpVarForSavingInput=taskFiveInputNum;
                
                // checking for each digit if it appears more than once
                // acording to orders
                for(int i=0;i<taskFivehowManyDigitInTheInput;i++){
                    currentDigit=taskFiveHelpVarForSavingInput%10;
                    
                    // checking if we have the same digit in the rest of the digits
                    while(taskFiveHelpVarForSavingInput>0){
                        
                        taskFiveHelpVarForSavingInput= taskFiveHelpVarForSavingInput/10;
                        
                        // if we reach 0 it means we checked all the digits
                        if(taskFiveHelpVarForSavingInput==0){
                            break;
                        }
                        
                        // if we found the same digit we print and break
                        if(currentDigit==taskFiveHelpVarForSavingInput%10){
                            printf("%d appears more than once!\n", currentDigit);
                            break;
                        }
                    }

                    // preparing for the next digit check
                    // cutting the last digit that we just checked and saving the rest
                    taskFiveInputNum=taskFiveInputNum/10;
                    taskFiveHelpVarForSavingInput=taskFiveInputNum;
                }
                break;
            // TASK 6: EXIT
            case 6:
                printf("Good night! see you at the pond tomorrow.");
                break;

            // INVALID INPUT HANDLING
            default:
                printf("Invalid number, please try again\n");
                break;
        }
    }
    while (
        // condition to continue looping until user choose exsit (6)
        userChoiceNumber != 6
    );
    return 0;
}
