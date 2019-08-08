#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int number1, number2, op, result;   //The numbers we'll get from the user, operator and operation result variables.

//The random operator generator function.
void randomOp() {
	srand(time(NULL));     //Seeding the random number generator.
	op=rand()%6;           //Generates a random number between 0 and 5. Meanings are 0: Nothing, 1: Addition, 2: Substraction, 3: Multiplication, 4: Division, 5: Modulo.
}

//First operation function were defined due to preventing complexity and avoiding long codes.
int* first_switch(int number1, int number2) {
		
 	//Allocating string memories.
	char *history=(char*)malloc(sizeof(char)*1000);      //All saved history string.
	char *new_history=(char*)malloc(sizeof(char)*1000);  //New history that is going to be saved into history.
	
	switch(op) {        //Choosing what to process based on "op" variable that was randomized by the generator.
			case 1:
				printf("Your calculation operator is addition(+)\n");
				result=number1+number2;                               //Assigning the result into result variable.
				sprintf(new_history, "%d+%d", number1, number2);      //Saving new variables with the appropriate operator into new history.
				printf("%s=%d", new_history, result);                 //Showing the arithmetic expression.
				strcpy(history, new_history);                         //Saving new arithmetic expression in history.
				break;
			case 2:
				printf("Your calculation operator is substraction(-)\n");
				result=number1-number2;                              //Assigning the result into result variable.
				sprintf(new_history, "%d-%d", number1, number2);     //Saving new variables with the appropriate operator into new history.
				printf("%s=%d", new_history, result);                //Showing the arithmetic expression.
				strcpy(history, new_history);                        //Saving new arithmetic expression in history.
				break;
			case 3:
				printf("Your calculation operator is multiplication(*)\n");
				result=number1*number2;                              //Assigning the result into result variable.
				sprintf(new_history, "%d*%d", number1, number2);     //Saving new variables with the appropriate operator into new history.
				printf("%s=%d", new_history, result);                //Showing the arithmetic expression.
				strcpy(history, new_history);                        //Saving new arithmetic expression in history.
				break;
			case 4:
				printf("Your calculation operator is division(/)\n");
				result=number1/number2;                              //Assigning the result into result variable.
				sprintf(new_history, "%d/%d", number1, number2);     //Saving new variables with the appropriate operator into new history.
				printf("%s=%d", new_history, result);                //Showing the arithmetic expression.
				strcpy(history, new_history);                        //Saving new arithmetic expression in history.
				break;
			case 5:
				printf("Your calculation operator is modulo(%)\n");
				result=number1%number2;                              //Assigning the result into result variable.
				sprintf(new_history, "%d%%%d", number1, number2);    //Saving new variables with the appropriate operator into new history.
				printf("%s=%d", new_history, result);                //Showing the arithmetic expression.
				strcpy(history, new_history);                        //Saving new arithmetic expression in history.
				break;
			default: 
		    	break;
	}
return &history;       //Returning history string's memory address to main function.
}

int main() {
	int result2, status;    //Result and integer checking variables.
	 	
//Allocating string memories.
char *history=(char*)malloc(sizeof(char)*1000);       //All saved history string.
char *new_history=(char*)malloc(sizeof(char)*1000);   //New history that is going to be saved into history.
	
	do {
	printf("Enter the first number(Integer)(Ctrl-Z to exit): ");     //Asking the first number from the user.
	status=scanf("%d", &number1);                                    //Getting the data from the user.
	if(status==EOF) return 0;                                        //Shuts down the application when the user enters EOF(Ctrl-Z) value.
	else if(status<1) {                                              //Checking if the value is correctly entered or not.
		printf("\n*****Please enter an integer value to continue.*****\n");
		fflush(stdin);                                               //Cleaning the scanf memory that wrongly entered.
		continue;
	}
}while(status!=1);
	
	do {
	printf("Enter the next number(Integer)(Ctrl-Z to exit): ");      //Asking the next number from the user.
	status=scanf("%d", &number2);                                    //Getting the data from the user.
	if(status==EOF) return 0;                                        //Shuts down the application when the user enters EOF(Ctrl-Z) value.
	else if(status<1) {                                              //Checking if the value is correctly entered or not.
		printf("\n*****Please enter an integer value to continue.*****\n");
		fflush(stdin);                                               //Cleaning the scanf memory that wrongly entered.
		continue;
	}
	randomOp();         //Generates a random operator.
	if(op==0) op+=1;    //If the operator is nothing at the begining, increases by 1. It prevents a string error.
}while(status!=1);
	
	strcpy(history, *first_switch(number1, number2));    //Calls the function that computes first operations.
	
	do {
		randomOp();     //Generates a random operator.
		do {
		printf("\nEnter the next number(Integer)(Ctrl-Z to exit): ");  //Asking the next number from the user.
		status=scanf("%d", &number2);                                  //Getting the data from the user.
		if(status==EOF) return 0;                                      //Shuts down the application when the user enters EOF(Ctrl-Z) value.
		else if(status<1) {                                            //Checking if the value is correctly entered or not.
			printf("\n*****Please enter an integer value to continue.*****");
			fflush(stdin);                                             //Cleaning the scanf memory that wrongly entered.
			continue;
	}
	randomOp();        //Generates a random operator.
	if(op==0) {        //If the operator is nothing, executes the loop one more time.
	printf("Your calculation operator is nothing. Try again.");
	continue;
}
}while(status!=1);
	
		switch(op) {         //Choosing what to process based on "op" variable that was randomized by the generator.
			case 1:
				printf("Your calculation operator is addition(+)\n");   
				result2=result+number2;                                //Assigning the result into result variable.
				sprintf(new_history, "+%d", number2);                  //Saving new variables with the appropriate operator into new history.
				strcat(history, new_history);                          //Compounding new and old arithmetic expressions.
				printf("%s=%d", history, result2);                     //Showing the arithmetic expression.
				result=result2;                                        //Gives the last result to up next loop.
				break;
			case 2:
				printf("Your calculation operator is substraction(-)\n");
				result2=result-number2;                                //Assigning the result into result variable.
				sprintf(new_history, "-%d", number2);                  //Saving new variables with the appropriate operator into new history.
				strcat(history, new_history);                          //Compounding new and old arithmetic expressions.
				printf("%s=%d", history, result2);                     //Showing the arithmetic expression.
				result=result2;                                        //Gives the last result to up next loop.
				break;
			case 3:
				printf("Your calculation operator is multiplication(*)\n");
				result2=result*number2;                                //Assigning the result into result variable.
				sprintf(new_history, "*%d", number2);                  //Saving new variables with the appropriate operator into new history.
				strcat(history, new_history);                          //Compounding new and old arithmetic expressions.
				printf("%s=%d", history, result2);                     //Showing the arithmetic expression.
				result=result2;                                        //Gives the last result to up next loop.
				break;
			case 4:
				printf("Your calculation operator is division(/)\n");
				result2=result/number2;                                //Assigning the result into result variable.
				sprintf(new_history, "/%d", number2);                  //Saving new variables with the appropriate operator into new history.
				strcat(history, new_history);                          //Compounding new and old arithmetic expressions.
				printf("%s=%d", history, result2);                     //Showing the arithmetic expression.
				result=result2;                                        //Gives the last result to up next loop.
				break;
			case 5:
				printf("Your calculation operator is modulo(%)\n");
				result2=result%number2;                                //Assigning the result into result variable.
				sprintf(new_history, "%%%d", number2);                 //Saving new variables with the appropriate operator into new history.
				strcat(history, new_history);                          //Compounding new and old arithmetic expressions.
				printf("%s=%d", history, result2);                     //Showing the arithmetic expression.
				result=result2;                                        //Gives the last result to up next loop.
				break;
			default: 
		    	break;
	} 
} while(1);
	
	return 0;
}
