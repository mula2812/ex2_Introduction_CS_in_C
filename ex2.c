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
    unsigned long long taskTwoSaveBitsNum=0, taskTwoExtractBitsNum=0;

    // task three vars
    long long taskThreeBaseNum=0, taskThreeExponentNum=0, taskThreeResultNum=1;

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

        // Transform the char value to decimal according to the value of the char 0
        userChoiceNumber = (int)(userChoice)-decimalValueOfCharZero;

        switch(userChoiceNumber)
        {
            // TASK 1: Ducky's Unity Game
            case 1:
                printf("please enter a positive number:\n");
                scanf(" %d", &taskOneChoosingNum);
                
                // Until we don't get positive number
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
                    // if(sumOfMovementUntilEndOfIntSize>0){
                        
                    // moving 1 bit to right for check the next bit
                    taskOneHelpInt = taskOneHelpInt>>1;
                        
                    //     // now we can move one less step until we end 
                    //     // all the max bits in the size of int
                    //     sumOfMovementUntilEndOfIntSize -=1;
                    // }
                }
                
                printf("Ducky earns %d corns\n", sumOfOnesForTaskOne);
                break;
                

            // TASK 2: The Memory Game
            case 2:

                printf("please enter the number of ducks:\n");
                scanf(" %d",&taskTwoDucksNum);
                printf("you entered %d ducks\n", taskTwoDucksNum);

                // Until we don't get positive number
                while(taskTwoDucksNum<=0){
                    printf("Invalid number, please try again\n");
                    scanf(" %d", &taskTwoDucksNum);
                }

                int userChoiceQuackSh;
                for(int i=1; i<=taskTwoDucksNum; i++){
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i);
                    scanf(" %d", &userChoiceQuackSh);
                    while(userChoiceQuackSh!=1 && userChoiceQuackSh!=0){
                        printf("Invalid number, please try again\n");    
                    }
                    taskTwoSaveBitsNum+=userChoiceQuackSh<<i; //Check this!!!!!!!!!!!!!!!!!!!!
                }
                
                taskTwoExtractBitsNum = taskTwoSaveBitsNum>>1;//Check this!!!!!!!!!!!!!!!!!!!!
                
                for(int i=0; i<taskTwoDucksNum; i++){
                    
                    int checkQuackBit = taskTwoExtractBitsNum & 1;
                    taskTwoExtractBitsNum = taskTwoExtractBitsNum >> 1;
                    printf("%llu: \n", taskTwoSaveBitsNum);
                    if(checkQuackBit){
                        printf("duck number %d do Quak\n", i);
                    }
                    else{
                        printf("duck number %d do Sh...\n", i);
                    }
                }

                break;

            // TASK 3: Professor Pat's Power Calculation
            case 3:
                printf("please enter the number\n");
                scanf(" %lld", &taskThreeBaseNum);
                while(taskThreeBaseNum<0){
                    printf("Invalid number, please try again\n");
                    scanf(" %lld", &taskThreeBaseNum);
                }
                printf("please enter the exponent\n");
                scanf(" %lld", &taskThreeExponentNum);
                while(taskThreeExponentNum<0){
                    printf("Invalid number, please try again\n");
                    scanf(" %lld", &taskThreeExponentNum);
                }

                for(int i=0; i<taskThreeExponentNum; i++){
                    taskThreeResultNum *= taskThreeBaseNum;
                }

                printf("your power is: %lld\n", taskThreeResultNum);
                break;

            
            // TASK 4: The Duck Parade
            case 4:
                break;
            // TASK 5: The Mystery of the Repeated Digits
            case 5:
                break;
            // TASK 6: EXIT
            case 6:
                printf("Good night! see you at the pond tomorrow.");
                break;

            // INVALID INPUT HANDLING
            default:
                printf("Invalid number, please try again");
                break;
        }
    }
    while (
        // condition to continue looping until user choose exsit (6)
        userChoiceNumber != 6
    );
    printf("Done");
    return 0;
}
