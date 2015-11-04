/***********************************************************************************************************
*  FoundationProgramming.c	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	       *
* Create a program that displays the area of the room, how much it will cost for which paint is used.	   *
*  Sheel Shah	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	       *
*  14 October 2014	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	       *
***********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)

{
	 	 	 
	float height; 
	float Length_A;
	float Length_B;
	char name[30] = "";
	float coat = 0.50;
	float option;
	float Area;
	float lux = 1.75;
	float stan = 1.00;
	float econ = 0.45;
	float total;
	float vat = 0.2;
	float labour;
	float materials;
	char undercoat;
	char c;
			
		printf("\nPlease enter the customer name...\nName: ");
		scanf("%s", name); /* Stores input into name */
		fflush(stdin);
		printf("\n\nHello %s! Now let's begin.", name);
		
	/* Height - Add a while statement so they can only enter a number between 2 and 6! */

	do 
	{	 
	printf("\n\nPlease enter the height of the room between 2 and 6.");
	printf("\nHeight: ");  /* Takes in the users input*/
	scanf("%f", &height);
	fflush(stdin);	  
	
	}while((height <= 1.0) || (height >=7.0) && height !=' '); /* They can only enter a number between 2 and 6 */
	system("cls"); /* Clears the screen*/
	
	/* Length A */
	do 
	{
	printf("\n\nPlease enter the adjacent of one wall in metres between 1 and 25...\nLength: ");
	scanf("%f", &Length_A);
	fflush(stdin);	  
	}while((Length_A <=0) || (Length_A >=26)); /* Lets the user enter a number between 1 and 25*/
	system("cls");
	/* Length B */
	do 
	{
	printf("\n\nPlease enter other adjacent of one wall in metres between 1 and 25...\nLength: ");
	scanf("%f", &Length_B);
	fflush(stdin);	   	   
	}while((Length_B <=0) || (Length_B >=26));
	system("cls");
	/* User defined functions */
	
	Area= ( (Length_A * height) * 2 ) + ((Length_B * height ) * 2 )  + ( Length_A * Length_B );
	printf("\n\nArea: %g cm^2\n", Area);  	  	  
	system("pause");
	system("cls");

	/* Paint choice */;	   	   
	do 
	{
	printf("Does the customer require an undercoat? This shall cost 0.50p per metre\n Enter Y/N to choose. \n Y/N:");
	scanf("%c", &undercoat);
	fflush(stdin);
	
	}while ((undercoat!= 'Y' ) && (undercoat != 'y') && (undercoat!='n') && (undercoat!='N')); /* If undercoat = Y then it goes to a specific loop, else if it equals to N then it goes to a different loop*/
	system("cls");
	
	/*Labour cost*/
	do
	{
	printf("\nPlease enter the labour cost.\nLabour: ");
	scanf("%g",&labour);
	fflush(stdin);
	/* Tests program is positive*/
	}while (!(labour > 0)); 
	system("cls");
	 
	/*Materials used*/
	

	printf("Enter tha amount of materials used.\nMaterials: ");
	scanf("%g",&materials);
	fflush(stdin);;
	
	system("cls");
	/* Paint choices*/
	do{	   	   
	printf("\nWhich type of paint does the customer wish to choose?");
	printf("\n\n[]Option 1: Luxury quality which costs 1.75 pounds per square metre ");
	printf("\n[]Option 2: Standard quality which cost 1.00 pounds per square metre");
	printf("\n[]Option 3:Economy quality which costs 0.45 pounds per square metre\nOption: ");
	scanf("%f",&option);
	}while (option == 1 && option == 2 && option  == 3);

	/*Customer chooses an undercoat and an option*/
	
	if (undercoat == 'y' || undercoat =='Y')
	{
		printf("\nYou have chosen option %g with a paint choice",option); 
	
	/* If cases */
		if(option == 1  ) 
		{
			/* Calculation */
			printf("\nLuxury:-");
			printf("\n\nMaterials used: %g",materials);
			printf("\ncost: %g pounds",lux * Area + labour + coat);
			printf("\nVAT: %4g pounds ",(lux * Area + labour) * vat);
			printf("\nTotal %3g pounds",(lux * Area + labour + coat) + (lux * Area +labour + coat) * vat);
		}
		
			else if(option == 2) 
		{ 
			printf("\nStandard:-");
			printf("\n\nMaterials used: %g",materials);
			printf("\nCost: %g",stan * Area + labour + coat);
			printf("\n With VAT: %4g",(stan * Area + labour) * vat);
			printf("\nTotal %3g pounds",(stan * Area + coat + labour) + (stan * Area + coat + labour) * vat);
		} 				
		else if(option == 3) 
		{
			printf("\nEconomy:-");
			printf("\n\nMaterials used: %g",materials);
			printf("\n Cost: %g",econ * Area + coat + labour);
			printf("\nVAT: %4g",total * vat + coat + labour);
			printf("\nTotal %3g pounds",(econ * Area + coat + labour) + (econ * Area + coat + labour ) * vat);
		
		}
	}

	
	
	/*Customer does not choose an  undercoat but an option*/
	else if(undercoat =='n' || undercoat =='N') 
	{
		printf("\nYou have chosen option %g without a paint choice",option);
	
		/* If cases */
		if(option == 1) 
		{
			/* Calculation */
			printf("\nLuxury:-");
			printf("\n\nMaterials used: %g",materials);                                                                                                                                                                                                                                                                             
			printf("\ncost: %g pounds",lux * Area + labour);
			printf("\nVAT: %4g pounds ",(lux * Area + labour) * vat);
			printf("\nTotal %3g pounds",(lux * Area + labour) + (lux * Area + labour) * vat);
		}
	
		else if(option == 2) 
		{	 
			printf("\nStandard:-");
			printf("\n\nMaterials used: %g",materials);
			printf("\nCost: %g pounds",stan * Area + labour);
			printf("\n With VAT: %4g pounds",total * vat + labour);
			printf("\nTotal %3g pounds",(stan * Area + labour) + (stan * Area + labour) * vat);
		} 				
		else if(option == 3) 
		{
			printf("\nEconomy:-");
			printf("\n\nMaterials used: %g",materials);
			printf("\n Cost: %g pounds",econ * Area + labour);
			printf("\nVAT: %4g pounds",total * vat + labour);
			printf("\nTotal: %3g pounds",(econ * Area + labour) + (econ * Area + labour) *vat);
		} 	  	  
	}

system("pause");
	
return 0;	
}

