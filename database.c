/************************************************************************************
*	Program 1, creating file														*
*	This program lets the user enter customer detail and writes it to a file		*
*	sheel shah																		*
*	6/12/2014																		*
*************************************************************************************/


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define ENTEREDPW 9
#define NAME 10
#define ENTEREDNAME 10 
#define STOREDPW 9
#define LIM 10
struct custinfo
{
	char firstname[LIM];
	char lastname[LIM];
	int day;
	int month;
	int year;
	int height;
	int measurement;
	int weight;
	int waist;
	char comment[LIM];
	char storage[LIM];
};

struct dob
{
	char username;
	char password;
		
};
/* User Defined Functions*/
void getLogin(char enteredpw[ENTEREDPW],char enteredname[ENTEREDNAME] , char ch);
void getMenu(char ch,int i,struct custinfo database[]);
int plusCustomer(struct custinfo database[], int i);
void writeFile(struct custinfo database[],int i );

int main()
{	
	struct custinfo database[50]; /* 50 Structures */
    char storedpw[STOREDPW][LIM]={"efghiss","UFXX|TWI","UFXX|TWi","ufxx|twi","12312312"}; /* Stored Encryptions */
    char enteredpw[9] , enteredname[NAME]; 
	char name[NAME][LIM]={"admin","D123467","T234567","C234567","J234567"}; /* Stored Usernames */
	char ch;
	int i; /* count */
	int p;
	int validuser = 0;
	
	while( validuser == 0 ) /* If username and password does not match, it prints out invalid password or username or even both */ 
	{
		system("cls");
		system("color 1f");
	    printf("\n\n\n\t\t\t*********************************");
		printf("\n\n\n\n\t\t\tEnter the username:");
		scanf("%s",&enteredname);
		printf("\t\t\tEnter the password: ");
        for( i=0; i<8; i++ )
        {	
         	ch=getch();    
            printf("*"); /* Encrypts Password */
			enteredpw[i]=ch+5;

			if((strcmp(storedpw[1],enteredpw)==0) && strcmp(name[1],enteredname)==0) /* Notices if the encrypted password matches */
			{
				validuser = 1;
				break;
			}
		}
	}

	 
		enteredpw[i]='\0';
		printf("\n\n\n\t\t\t********************************");	   
		getMenu(ch,i,database);	   	   
return 0;	 
}
/*Get Menu, user selects an option and directs them to another user defined function */  
void getMenu(char ch,int i,struct custinfo database[])  
{    
	system("cls");  
    system("color 1f");  
	while(ch!='3') /* If choice is 3, it closes the console */  
	{  
	   printf("\n\n\n\t\t\tDataBase");  
	   printf("\n\t\t\t1) Enter a Customer");  
	   printf("\n\t\t\t2)Write File");  
	   printf("\n\t\t\t3)Leave the Program");  
	   printf("\n\t\t\tOption: ");  
	   ch=getch(); /* Takes in only 1 - 3 */  
	   fflush(stdin);  
	   switch(ch)  
	   {  
	  	case '1':  
                i = plusCustomer(database,i);  
	            break;  
	    case '2':  
	            writeFile(database,i);      
	            break;  
	    case '3':  
	    	    break;  
		default:  
	          	system("cls");  
	            system("color 0c");  
	            system("cls");  
	            printf("\n\n\t\t\tInvalid Choice, please choose again!");  
	            printf("\n______________________________________________________________________________");  
	   }  
	}  
}         
/* Option 1, user enters the data and that gets stored into Database[i] */
int plusCustomer(struct custinfo database[], int i)
{	    	
	system("color 1f"); 
	for(i = 0; i < 1; i++)
	{
		system("cls");
		printf("______________________________________________________________________________");
		printf("\n\t\t\t\tPatient Details");
		printf("\t\t\tRecord %d",i);
		printf("\n______________________________________________________________________________");	   
		printf("\nEnter Customers First Name: ");
		scanf("%s",database[i].firstname);
		fflush(stdin);
		
		printf("\nEnter Customers Last Name: ");
		scanf("%s",database[i].lastname);
		fflush(stdin);

		printf("\nEnter Date of birth in the form of DD/MM/YYYY:   ");
		scanf("%2d/%2d/%4d",&database[i].day,&database[i].month,&database[i].year);	   
		fflush(stdin);
		
		printf("\nHeight in ft: ");
		scanf("%d",&database[i].height);
		fflush(stdin);	
		
		printf("\nWaist measurement in inches: ");
		scanf("%d",&database[i].waist);
		fflush(stdin);   
		
		printf("\nWeight in kg: ");
		scanf("%d",&database[i].weight);
		fflush(stdin);
		
		printf("\nComment: ");
		scanf("%[^\n]",database[i].comment); /* Takes the entire line of string */
		fflush(stdin);
		system("cls");
	}
return i;
}
/* Writes the file, into the format of lastname and their DOB */
void writeFile(struct custinfo database[],int i)
{

	FILE *f;
	char filename[1000];
	for(i = 0; i < 1; i++)
	{
	   
		sprintf(filename,"%s%d%d%d.pat ", database[i].lastname, database[i].day,database[i].month,database[i].year);
		f = fopen(filename,"w"); 
		fprintf(f,"First Name: %s \n Last Name: %s \n Date Of Birth: %2d %2d %4d \n Height: %d \n Waist: %d \n Weight: %d \n Comment: %s",database[i].firstname,database[i].lastname,
		 database[i].day, database[i].month,database[i].year, database[i].height, database[i].waist, database[i].weight, database[i].comment);
		system("color 2f"); /* Green background, white text */
		getchar(); 
		system("cls");
		fclose(f);
		printf("File has been saved");

		return;
		
	}
}

