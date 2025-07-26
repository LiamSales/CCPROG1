/***************************************************************************
This is to certify that this project is my own work, based on my personal efforts in
studying and applying the concepts learned. I have constructed the functions and
their respective algorithms and corresponding code by myself. The program was
run, tested, and debugged by my own efforts. I further certify that I have not copied
in part or whole or otherwise plagiarized the work of other students and/or persons.
***************************************************************************/

/*
Description:This program is an ordering system that asks the user for inputs,
generates a random meal set, confirms whether the users are sure of the orders,
gives discounts when necessary, and computes for the subtotal and total prices.
Programmed by: Liam Miguel V. Sales S26A
Last modified: December 5, 2022
Version: 14
Acknowledgements:	https://dlsu.instructure.com/
					https://www.tutorialspoint.com/rand-and-srand-in-c
					https://www.geeksforgeeks.org/generating-random-number-range-c/				
*/

#include <stdio.h>
#include <stdlib.h>

//main prices
#define CHICKEN 90.00
#define PORK 105.00
#define FISH 120.00
#define BEEF 135.00

//side prices
#define STEAMED_RICE 20.00
#define SHREDDED_CORN 35.00
#define MASHED_POTATOES 50.00
#define STEAM_VEGETABLES 65.00

//drink prices
#define MINERAL_WATER 25.00
#define ICED_TEA 35.00
#define SODA 45.00
#define FRUIT_JUICE 55.00


/*  This function displays the list of items and prices and their respective IDs.
*/
void displayMenu()
{
	printf("\n\t\t\t\tWELCOME!\nHere is the menu.\n\nPlease select your order by inputting digits based on the IDs given:\n(Input 0 if you wish to omit a part of the meal.)\n");
	printf("\n*************************************************************************\n");
	
	printf("\t\t\t\tMAINS:\n\n");
	printf("\tID:\tType:\t\t\t\t\t\tPrice:\n\n");
	printf("\t[1]\tChicken\t\t\t\t\t\tP  %.2f\n",CHICKEN);
	printf("\t[2]\tPork\t\t\t\t\t\tP %.2f\n",PORK);
	printf("\t[3]\tFish\t\t\t\t\t\tP %.2f\n",FISH);
	printf("\t[4]\tBeef\t\t\t\t\t\tP %.2f\n",BEEF);
	
	printf("\n*************************************************************************\n");
	
	printf("\t\t\t\tSIDES:\n\n");
	printf("\tID:\tType:\t\t\t\t\t\tPrice:\n\n");
	printf("\t[1]\tSteamed Rice\t\t\t\t\tP %.2f\n",STEAMED_RICE);
	printf("\t[2]\tShredded Corn\t\t\t\t\tP %.2f\n",SHREDDED_CORN);
	printf("\t[3]\tMashed Potatoes\t\t\t\t\tP %.2f\n",MASHED_POTATOES);
	printf("\t[4]\tSteam Vegetables\t\t\t\tP %.2f\n",STEAM_VEGETABLES);
	
	printf("\n*************************************************************************\n");

	printf("\t\t\t\tDRINKS:\n\n");
	printf("\tID:\tType:\t\t\t\t\t\tPrice:\n\n");
	printf("\t[1]\tMineral Water\t\t\t\t\tP %.2f\n",MINERAL_WATER);
	printf("\t[2]\tIced Tea\t\t\t\t\tP %.2f\n",ICED_TEA);
	printf("\t[3]\tSoda\t\t\t\t\t\tP %.2f\n",SODA);
	printf("\t[4]\tFruit Juice\t\t\t\t\tP %.2f\n",FRUIT_JUICE);
	
	printf("\n*************************************************************************\n\n");
}


/*  This function prints out the name of the main item based on the ID number given.
	Precondition: Only valid IDs will be passed here, based on the function invalid(int var).
	@param nMain is the ID number of the main item, based on what is displayed in the menu.
*/
void displayMain(int nMain)
{
	switch (nMain)
	{
		case 1:
			printf("Chicken");
			break;
		case 2:
			printf("Pork");
			break;
		case 3:
			printf("Fish");
			break;
		case 4:
			printf("Beef");
			break;
		default:
			printf("none");
	}
}

/*  This function prints out the name of the side item based on the ID number given.
	Precondition: Only valid IDs will be passed here, based on the function invalid(int var).
	@param nSide is the ID number of the side item, based on what is displayed in the menu.
*/
void displaySide(int nSide)
{
	switch (nSide)
	{
		case 1:
			printf("Steamed Rice");
			break;
		case 2:
			printf("Shredded Corn");
			break;
		case 3:
			printf("Mashed Potatoes");
			break;
		case 4:
			printf("Steam Vegetables");
			break;
		default:
			printf("none");
	}
}

/*	This function prints out the name of the drink item based on the ID number given.
	Precondition: Only valid IDs will be passed here, based on the function invalid(int var).
	@param nDrink is the ID number of the drink item, based on what is displayed in the menu.
*/
void displayDrink(int nDrink)
{
	switch (nDrink)
	{
		case 1:
			printf("Mineral Water");
			break;
		case 2:
			printf("Iced Tea");
			break;
		case 3:
			printf("Soda");
			break;
		case 4:
			printf("Fruit Juice");
			break;
		default:
			printf("none");
	}
}

/*	This function returns the cost of the main item based on the ID number given.
	Precondition: Only valid IDs will be passed here, based on the function invalid(int var).
	@param nMain is the ID number of the main item, based on what is displayed in the menu.
	@return the resulting cost of the main item, based on the preprocessor directives
*/
float getMainCost(int nMain)
{
	float mainCost;
	switch (nMain)
	{
		case 1:
			mainCost=CHICKEN;
			break;
		case 2:
			mainCost=PORK;
			break;
		case 3:
			mainCost=FISH;
			break;
		case 4:
			mainCost=BEEF;
			break;
		default:
			mainCost=0;
	}
	return mainCost;
}

/*	This function returns the cost of the side item based on the ID number given.
	Precondition: Only valid IDs will be passed here, based on the function invalid(int var).
	@param nSide is the ID number of the side item, based on what is displayed in the menu.
	@return the resulting cost of the side item, based on the preprocessor directives
*/
float getSideCost(int nSide)
{
	float sideCost;
	switch (nSide)
	{
		case 1:
			sideCost=STEAMED_RICE;
			break;
		case 2:
			sideCost=SHREDDED_CORN;
			break;
		case 3:
			sideCost=MASHED_POTATOES;
			break;
		case 4:
			sideCost=STEAM_VEGETABLES;
			break;
		default:
			sideCost=0;
	}
	return sideCost;
}

/*	This function returns the cost of the drink item based on the ID number given.
	Precondition: Only valid IDs will be passed here, based on the function invalid(int var).
	@param nDrink is the ID number of the drink item, based on what is displayed in the menu.
	@return the resulting cost of the drink item, based on the preprocessor directives
*/
float getDrinkCost(int nDrink)
{
	float drinkCost;
	switch (nDrink)
	{
		case 1:
			drinkCost=MINERAL_WATER;
			break;
		case 2:
			drinkCost=ICED_TEA;
			break;
		case 3:
			drinkCost=SODA;
			break;
		case 4:
			drinkCost=FRUIT_JUICE;
			break;
		default:
			drinkCost=0;
	}
	return drinkCost;
}

/*	This function computes the total cost of the order using the return values of the previous 3 functions.
	Precondition: Only valid IDs will be passed here, based on the function invalid(int var).
	@param fMain is the ID of the selected main item.
	@param fSide is the ID of the selected side item.
	@param fDrink is the ID of the selected drink item.
	@return the resulting cost of the order
*/
float getOrderCost(int nMain, int nSide, int nDrink)
{
	//addition of each meal component's price
	return getMainCost(nMain)+getSideCost(nSide)+getDrinkCost(nDrink);
}

/*	This function checks whether a value passed to it is invalid.
	Precondition: Only integers can be passed to this.
	@param var is the integer passed by the function inputOrder, which is a user-input.
	@return 1 if the value is invalid and 0 if it is valid.
*/
int nInvalid(int var)
{
	// returns returns 0 if the value is within the range of 1 to 4 and returns 1 if not
	return var<0||var>4;
}

/*	This function checks whether a character passed to it is invalid.
	Precondition: Only one character can be passed to this at a time.
	@param var is the character passed by the function inputOrder or main, which is a user-input.
	@return 1 if the character is invalid and 0 if it is valid.
*/
int cInvalid(char var)
{
	// returns 0 if the character is a yes or no answer and returns 1 if not
	return var!='Y'&&var!='y'&&var!='N'&&var!='n';
}

/*	This function asks the user whether they would like to cancel or modify the current order made
	@return 1 if the user wishes to modify the order and 0 if they wish to cancel it.
*/
int changeOrder()
{
	int nChange;
	
	printf("\nWould you like to cancel or modify the current order?:\nIf you wish to cancel it [0]:\nIf you wish to modify it [1]:\t\t\t\t\t");
	scanf("%d",&nChange);
	
	while(nChange>1||nChange<0)
		{
		printf("\nSorry, that answer was invalid.\nPlease try again:\t\t\t\t\t\t");
		scanf("%d", &nChange);
		}
	
	return nChange;
}

/*	This function asks for the user-inputs of the IDs to get each component of their order,
	passes them to nInvalid to check validity and asks to repeat if invalid,
	passes them to the other functions to get the name and cost of each item,
	passes the inputs to getOrderCost to compute for the subtotal of the order,
	and checks if it corresponds to the meal set of the day to give a discount if it is.
	
	Precondition:	The user will only input integers for the order components,
					and only one character for the order confirmation.
					
	@param setMain is the same integer that was passed for the main dish ID of displaySetMeal
	@param setSide is the same integer that was passed for the side dish ID of displaySetMeal
	@param setDrink is the same integer that was passed for the drink ID of displaySetMeal
	@param *nMain is the pointer variable that will change the value of each main order in the main function
	@param *nSide is the pointer variable that will change the value of each side order in the main function
	@param *nDrink is the pointer variable that will change the value of each drink order in the main function
	@return the resulting subcost of the order, with the discount when applicable
*/
float inputOrder(int setMain, int setSide, int setDrink, int *nMain, int *nSide, int *nDrink)
{
	float fSub;
	
		//asks for the main dish ID and displays the name if it is valid, repeats if it is invalid
		printf("\n\tMain:\t\t\t\t");
		scanf("%d",nMain);
			while (nInvalid(*nMain))
			{
				printf("\n\tSorry, that main input was invalid.\n\tPlease try again:\t\t");
				scanf("%d",nMain);
			}
		printf("\t\t\t\t\t");
		displayMain(*nMain);

		//asks for the side dish ID and displays the name if it is valid, repeats if it is invalid
		printf("\n\n\n\tSide:\t\t\t\t");
		scanf("%d",nSide);	
		while (nInvalid(*nSide))
			{
			printf("\n\tSorry, that side input was invalid.\n\tPlease try again:\t\t");
			scanf("%d",nSide);
			}
		printf("\t\t\t\t\t");
		displaySide(*nSide);
	
		//asks for the drink ID and displays the name if it is valid, repeats if it is invalid
		printf("\n\n\n\tDrink:\t\t\t\t");
		scanf("%d",nDrink);
			while (nInvalid(*nDrink))
			{
			printf("\n\tSorry, that drink input was invalid.\n\tPlease try again:\t\t");
			scanf("%d",nDrink);
			}
		printf("\t\t\t\t\t");
		displayDrink(*nDrink);
		
		//passes the values of the inputs to getOrderCost in order to recieve the total of the prices of the 3 inputs
		fSub=getOrderCost(*nMain, *nSide, *nDrink);

		//prints the subtotal price of the order
		printf("\n\n\t\t\t\t\tSubtotal:\t\tP %.2f",fSub);
		
	
		//checks if the order corresponds to the meal set of the day to give a discount if it is, prints to tell the user that it is
		if (*nMain==setMain&&*nSide==setSide&&*nDrink==setDrink)
		{
		fSub*=0.85;
		printf("\n\n\tMeal Set of the Day (15%% discount)\n\n\t\t\t     Discounted Subtotal:\t\tP %.2f",fSub);
		}	
		

	//returns the subtotal price, after the user has confirmed their order
	return fSub;
}

/*	This function returns a random integer from 1 to 4.
	Precondition: the srand() function in main() changes the seed for every run.
	@return the randomly generated integer from 1 to 4
*/
int randMeal()
{
	// rand() % (maximum value) + (minimum value)
    return rand()%4+1;
}

/*	This function prints the items of the Meal Set of the Day, with their respective IDs, and then displays subtotal price with a discount.
	Precondition: All 3 IDs must be valid, based on the maximum and minimum values set in randMeal
	@param setMain is the randomly generated integer passed from main().
	@param setSide is a different randomly generated integer passed from main().
	@param setDrink is a different randomly generated integer passed from main().
*/
void displaySetMeal(int setMain, int setSide, int setDrink)
{
	printf("\tMeal set of the day (15%% discount):\n\n\t");
	
	//prints out the name of the items in the set
	displayMain(setMain);
	printf(" and ");
	displaySide(setSide);
	printf(" with ");
	displayDrink(setDrink);

	//prints out the subtotal price of the set, with the discount included
	printf("\t\tP %.2f",getOrderCost(setMain, setSide, setDrink)*0.85);
	
	//prints out the respective IDs of the set's main, side, and drink items
	printf("\n\t[%d] [%d] [%d]", setMain, setSide,setDrink);

	printf("\n\n*************************************************************************\n\n");
}

/*	This function displays the subtotal costs of each order made and computes the total sum of all orders.
	Precondition: The subtotal values passed are accurate to the user's orders.
	@param fOrder1 is the subtotal cost of the first order.
	@param fOrder2 is the subtotal cost of the second order.
	@param fOrder3 is the subtotal cost of the third order.
	@params m1, m2, and m3 are the main items from each respective order.
	@params s1, s2, and s3 are the side items from each respective order.
	@params d1, d2, and d3 are the drink items from each respective order.
	@params sM, sS, and sD are the randomly generated main, side and drinks respectively.
	@return the total amount due
*/
void TotalAmountDue(float fOrder1, float fOrder2, float fOrder3,int m1,int m2,int m3,int s1,int s2,int s3,int d1,int d2,int d3, int sM, int sS, int sD)
{
	float fTotal;
	
	//equates the unmade orders to 0
	if(fOrder1==1)
	fOrder1=0;
	if(fOrder2==1)
	fOrder2=0;
	if(fOrder3==1)
	fOrder3=0;
	
	//prints out the subtotals of each order, will not print unordered items and empty orders
	if(fOrder1)
	{
	printf("\t\t\t\tOrder 1:\n");
		if(m1)
		{
			printf("\n\tP %.2f ", getMainCost(m1));
			displayMain(m1);
		}
		if(s1)
		{
			printf("\n\tP %.2f  ", getSideCost(s1));
			displaySide(s1);
		}	
		if(d1)
		{
			printf("\n\tP %.2f  ", getDrinkCost(d1));
			displayDrink(d1);
		}
	
	if (m1==sM&&s1==sS&&d1==sD)
	printf("\n\n\tMeal Set of the day (15%% discount)");
	
	printf("\n\n\tSubtotal:\t\t\t\t\t\tP %.2f\n", fOrder1);
	printf("-------------------------------------------------------------------------\n");
	}
	
	if(fOrder2)
	{
	printf("\t\t\t\tOrder 2:\n");
		if(m2)
		{
			printf("\n\tP %.2f ", getMainCost(m2));
			displayMain(m2);
		}
		if(s2)
		{
			printf("\n\tP %.2f  ", getSideCost(s2));
			displaySide(s2);
		}	
		if(d2)
		{
			printf("\n\tP %.2f  ", getDrinkCost(d2));
			displayDrink(d2);
		}
	
		
	if (m2==sM&&s2==sS&&d2==sD)
	printf("\n\n\tMeal Set of the day (15%% discount)");
	
	printf("\n\n\tSubtotal:\t\t\t\t\t\tP %.2f\n", fOrder2);
	printf("-------------------------------------------------------------------------\n");
	}

	if(fOrder3)
	{
	printf("\t\t\t\tOrder 3:\n");
		if(m3)
		{
			printf("\n\tP %.2f ", getMainCost(m3));
			displayMain(m3);
		}
		if(s3)
		{
			printf("\n\tP %.2f  ", getSideCost(s3));
			displaySide(s3);
		}	
		if(d3)
		{
			printf("\n\tP %.2f  ", getDrinkCost(d3));
			displayDrink(d3);
		}
	
		
	if (m3==sM&&s3==sS&&d3==sD)
	printf("\n\n\tMeal Set of the day (15%% discount)");
	
	printf("\n\n\tSubtotal:\t\t\t\t\t\tP %.2f\n", fOrder3);
	printf("-------------------------------------------------------------------------\n");
	}
	
	//computes for the total by adding all 3 subtotals
	fTotal=fOrder1+fOrder2+fOrder3;
	
	printf("\n\tTotal Amount Due:\t\t\t\t\tP %.2f",fTotal);

}

int main()
{
	int setMain, setSide, setDrink, m1,m2,m3,s1,s2,s3,d1,d2,d3, nChange;
	
	float fOrder1, fOrder2, fOrder3;
	
	char cCorrect, cProceed, cCancel;
	
	//gives a different seed for every run
	srand(time(0));
	
	//initializes the 3 components of the Meal Set of the Day, using 3 different randomly generated values in randMeal().
	setMain=randMeal();
	setSide=randMeal();
	setDrink=randMeal();

	//displays the menu IDs, items, prices, and the set meal details under it
	displayMenu();
	displaySetMeal(setMain,setSide,setDrink);

do{
	
		//initializes Orders as equal to 1 for the program to see if the user had chosen to skip these orders or not.
		fOrder1=1;
		fOrder2=1;
		fOrder3=1;

		//initializes nChange as value that is neither 1 nor 0
		nChange=2;
	do{
		
	printf("\nOrder 1:\n");

	//calls the inputOrder function to ask for inputs then equates Order 1 to its corresponding subtotal
	fOrder1=inputOrder(setMain,setSide,setDrink, &m1, &s1, &d1);
	
		//asks the user to confirm whether the order is correct or if they wish to repeat.
		printf("\n\nIs this meal set order correct? (Y/N):\t\t\t\t");
		scanf(" %c", &cCorrect);
	
			//repeats the question if the answer was not a valid "yes" or "no" input
			while(cInvalid(cCorrect))
			{
			printf("\nSorry, that answer was invalid.\nPlease try again:\t\t\t\t\t\t");
			scanf(" %c", &cCorrect);
			}
			
			if(cCorrect=='n'||cCorrect=='N')
			nChange=changeOrder();
			
		}while (cCorrect!='y'&&cCorrect!='Y'&&nChange==1);
		
		if (!nChange)
		fOrder1=1;
		nChange=2;
	
	//asks if the user would like to skip to the getting the amount due already
	printf("\nWould you like to proceed with another order? (Y/N):\t\t");
	scanf(" %c", &cProceed);
	
		//repeats the question if the answer was not a valid "yes" or "no" input
		while(cInvalid(cProceed))
			{
			printf("\nSorry, that answer was invalid.\nPlease try again:\t\t\t\t\t\t");
			scanf(" %c", &cProceed);
			}
		
	//proceeds to Order 2 if the user wishes to
	if (cProceed=='Y'||cProceed=='y')
	{
	printf("\n*************************************************************************\n");
	
	do{
	//calls the inputOrder function to ask for inputs then equates Order 2 to its corresponding subtotal
	printf("\nOrder 2:\n");
	fOrder2=inputOrder(setMain,setSide,setDrink, &m2, &s2, &d2);

		//asks the user to confirm whether the order is correct or if they wish to repeat.
		printf("\n\nIs this meal set order correct? (Y/N):\t\t\t\t");
		scanf(" %c", &cCorrect);
			
			//repeats the question if the answer was not a valid "yes" or "no" input
			while(cInvalid(cCorrect))
			{
			printf("\nSorry, that answer was invalid.\nPlease try again:\t\t\t\t\t\t");
			scanf(" %c", &cCorrect);
			}
			
			if(cCorrect=='n'||cCorrect=='N')
			nChange=changeOrder();
			
		}while (cCorrect!='y'&&cCorrect!='Y'&&nChange==1);
		
		if (!nChange)
		fOrder2=1;
		nChange=2;
		
	//asks if the user would like to skip to the getting the amount due already
	printf("\nWould you like to proceed with another order? (Y/N):\t\t");
	scanf(" %c", &cProceed);
	
		//repeats the question if the answer was not a valid "yes" or "no" input
		while(cInvalid(cProceed))
			{
			printf("\nSorry, that answer was invalid.\nPlease try again:\t\t\t\t\t\t");
			scanf(" %c", &cProceed);
			}
		
	//proceeds to Order 3 if the user wishes to
	if (cProceed=='Y'||cProceed=='y')
	{
	printf("\n*************************************************************************\n");
	
	do{
	//calls the inputOrder function to ask for inputs then equates Order 3 to its corresponding subtotal
	printf("\nOrder 3:\n");
	fOrder3=inputOrder(setMain,setSide,setDrink, &m3, &s3, &d3);
	
		//asks the user to confirm whether the order is correct or if they wish to repeat.
		printf("\n\nIs this meal set order correct? (Y/N):\t\t\t\t");
		scanf(" %c", &cCorrect);
			
			//repeats the question if the answer was not a valid "yes" or "no" input
			while(cInvalid(cCorrect))
			{
			printf("\nSorry, that answer was invalid.\nPlease try again:\t\t\t\t\t\t");
			scanf(" %c", &cCorrect);
			}
			
			if(cCorrect=='n'||cCorrect=='N')
			nChange=changeOrder();
			
		}while (cCorrect!='y'&&cCorrect!='Y'&&nChange==1);
		
		if (!nChange)
		fOrder3=1;
	}
	}
	
	printf("\n*************************************************************************\n\n");

		//checks whether only one order was made
		if(fOrder2==1&&fOrder3==1)
			
			//would not show the options to cancel Orders 2 and 3 since said orders were not made anyway.
			printf("Would you like to cancel your previous order?\n\nPlease input [Y] if you wish to cancel it:\nPlease input [N] if you wish to proceed with it:\t\t");
			
			//checks whether only 2 orders were made
			else if(fOrder2!=1&&fOrder3==1)
			
			//would not show the option to cancel Order 3 since said order were not made anyway.
			printf("Would you like to cancel any of your previous orders?\n\nPlease input the order number:\t\t    [1] [2]:\n\n\t\tIf you wish to cancel all\t[Y]:\n\n\t\tIf you wish to proceed with all\t[N]:\t\t");
		
			//asks whether the user would like to cancel either one, none, or all of the orders made
			else
			printf("Would you like to cancel any of your previous orders?\n\nPlease input the order number:\t\t[1] [2] [3]:\n\n\t\tIf you wish to cancel all\t[Y]:\n\n\t\tIf you wish to proceed with all\t[N]:\t\t");

	scanf(" %c", &cCancel);

	//repeats the question if the answer was not a valid input
	while(cCancel!='1'&&cCancel!='2'&&cCancel!='3'&&cInvalid(cCancel))
			{
			printf("\nSorry, that answer was invalid.\nPlease try again:\t\t\t\t\t\t");
			scanf(" %c", &cCancel);
			}
			
	//equates the canelled orders to 0
	switch(cCancel)
	{
		case '1':
			fOrder1=0;
			break;
		case '2':
			fOrder2=0;
			break;
		case '3':
			fOrder3=0;
			break;
	}
	
	printf("\n*************************************************************************\n");
	
} while (cCancel=='Y'||cCancel=='y');

	TotalAmountDue(fOrder1,fOrder2,fOrder3, m1,m2,m3,s1,s2,s3,d1,d2,d3, setMain,setSide,setDrink);
	
	//Thanks the user and ends the code
	printf("\n\n*************************************************************************\n\t\t\t\tThank you!\n");
	
return 0;
}
