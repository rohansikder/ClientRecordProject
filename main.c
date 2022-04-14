#include<stdio.h>//Input/Output
#include<stdlib.h>//Memory Allocation
#include<string.h>

//Rohan Sikder - G00389052

//Change Debug value too 1 to enable Debuging info which will be outputted along with program
#define DEBUG 0

/*
*	Format Of rawData.txt
*		1 irish.ltd IRE 1923 ire@gmail.com John 743 17 42341.000000 1 2 3 1
*		2 british.ltd UK 1932 uk@gmail.com Sam 184 23 34871.000000 1 2 1 3
*		3 american.ltd USA 1954 usa@gmail.com Todd 103 32 50821.000000 3 1 2 1
*		4 australian.ltd AU 1973 au@gmail.com Jeff 132 78 92431.000000 2 3 2 3
*/;


/*
*	Things To Still Do:
*		- Make Email validation E.g must contain an @, a full stop and a .com
*		- List clients in order of last turn over
*		- Generate Statistics
*		- Menu Validation
*	Bugs:
*		- None :) so far
*/;

typedef struct node
{
	int CRN;
	char CoName[30];
	char CoCountry[30];
	int yearFounded;
	char email[30];
	char ContactName[30];
	int LastOrder;
	int NumOfEmployees;
	float AverageAnnualOrder;
	int VatReg;
	int AvgTurnover;
	int StaffNum;
	int AreaOfSales;

	struct node* NEXT;

}nodeT;

//Define Functions
void addAtTheStartList(struct node** top);
void addAtTheEndList(struct node* top);
void displayList(nodeT* top);
void displaySingle(nodeT* top, int location);
int search(nodeT* top, int searchCRN);
void deleteAtEnd(struct node* top);
void deleteAtStart(struct node** top);
void deleteAtLocation(struct node* top, int location);
int listLength(nodeT* top);
void initilizeStartLinkedList(struct node** top);
void initilizeEndLinkedList(struct node* top);
void saveRawData(struct node* top);
void createReport(struct node* top);
int login();
void updateClient(struct node* top);

void main()
{

	nodeT* headPtr = NULL;
	nodeT* newNode;
	nodeT* temp;
	int choice;
	char searchCo[30];
	int resultSearch;
	int resultDelete;
	int searchID;
	int deleteId;
	int loginCheck = 0;
	
	//Checks if login was correct or not if loginCheck == 1 the Correct
	do 
	{
		loginCheck = login();

	} while(loginCheck == 0);
	
	//Intilizaing LinkedLists
	initilizeStartLinkedList(&headPtr);
	initilizeEndLinkedList(headPtr);

	//Deleteing first item as i read first line of data twice - I dont know how to skip the first line whne im reading it to the end of the list
	deleteAtStart(&headPtr);

	printf("Please enter 1 to Add client (Note: Company Registeration Number must be unique)\n");//Done 
	printf("Please enter 2 to Display all client details\n");//Done
	printf("Please enter 3 to Display client details\n");//Done
	printf("Please enter 4 to Update a client details\n");//Done
	printf("Please enter 5 to Delete client\n");//Done
	printf("Please enter 6 to Generate statistics (a to c) based on the user selecting one of the criteria listed in I - II\n\tA. Less than 1 Million euro\n\tB. Less than 10 Million euro\n\tC. Over 10 Million euro\n\tI. Area of Company Sales\n\tII. Number of Employees\n");
	printf("Please enter 7 to Print all client details into a report file.\n");//Done
	printf("Please enter 8 to List all the clients in order of their last average turnover\n");
	printf("Please enter -1 to exit application\n");
	printf("\n");
	scanf("%d", &choice);
	printf("\n");


	while (choice != -1)
	{
		if (choice == 1)
		{
			if (headPtr == NULL)
			{
				addAtTheStartList(&headPtr);
			}

			else
			{
				addAtTheEndList(headPtr);
			}
			//Saves raw data after each menu as user could change/update details
			saveRawData(headPtr);
		}

		else if (choice == 2)
		{
				displayList(headPtr);

				//Saves raw data after each menu as user could change/update details
				saveRawData(headPtr);
		}

		else if (choice == 3)
		{
			printf("Please enter the Company Registration number you wish to search for\n");
			scanf("%d", &searchID);

			resultSearch = search(headPtr, searchID);

			if (resultSearch == -1) {
				printf("The Company %d does not exist in the list\n", searchID);
			}
			else {

				#if DEBUG
					printf("The Company %d is at location %d\n", searchID, resultSearch);
				#endif
					
				displaySingle(headPtr, resultSearch);
			}

		}

		else if (choice == 4)
		{
			updateClient(headPtr);
			//Saves raw data after each menu as user could change/update details
			saveRawData(headPtr);
		}

		else if (choice == 5)
		{
			printf("Please enter the Company Registration Number To delete all client information from database:\n");
			scanf("%d", &deleteId);

			resultDelete = search(headPtr, deleteId);

			if (headPtr == NULL)
			{
				printf("The database is empty\n");
			}
			else if (resultDelete<0 || resultDelete>(listLength(headPtr) - 1))
			{
				printf("The CRN is not valid\n");
			}

			else if (resultDelete == 0)
			{
				deleteAtStart(&headPtr);
			}

			else if (resultDelete == (listLength(headPtr) - 1))
			{
				deleteAtEnd(headPtr);
			}

			else
			{
				deleteAtLocation(headPtr, resultDelete);
			}

			printf("Client (CRN) %d  has been deleted", deleteId);

			//Saves raw data after each menu as user could change/update details
			saveRawData(headPtr);

		}

		else if (choice == 6)
		{
			//Saves raw data after each menu as user could change/update details
			saveRawData(headPtr);
		}

		else if (choice == 7)
		{
			createReport(headPtr);
			//Saves raw data after each menu as user could change/update details
			saveRawData(headPtr);
		}

		else if (choice == 8)
		{
			//Saves raw data after each menu as user could change/update details
			saveRawData(headPtr);
		}

		printf("\nPlease enter 1 to Add client (Note: Company Registeration Number must be unique)\n");
		printf("Please enter 2 to Display all client details\n");
		printf("Please enter 3 to Display client details\n");
		printf("Please enter 4 to Update a client details\n");
		printf("Please enter 5 to Delete client\n");
		printf("Please enter 6 to Generate statistics (a to c) based on the user selecting one of the criteria listed in I - II\n\tA. Less than 1 Million euro\n\tB. Less than 10 Million euro\n\tC. Over 10 Million euro\n\tI. Area of Company Sales\n\tII. Number of Employees\n");
		printf("Please enter 7 to Print all client details into a report file.\n");
		printf("Please enter 8 to List all the clients in order of their last average turnover\n");
		printf("Please enter -1 to exit application\n");
		scanf("%d", &choice);
		printf("\n");
	}//End OF while

}//End Of Main

//Add to start of the list
void addAtTheEndList(struct node* top)
{

	struct node* temp = top;
	struct node* newNode;

	//Checks if CRN exists already

	int checkCRN, checkResult;

	printf("Please enter Company Registration Number(CRN) to check if it is available:\n");
	scanf("%d",&checkCRN);

	checkResult = search(temp, checkCRN);

	#if DEBUG 
		printf("\nThis is check result %d end of list-  checkCRN is %d\n", checkResult, checkCRN);
	#endif

	if (checkResult == -1) {
		newNode = (struct node*)malloc(sizeof(struct node));
		printf("Company Registration Number(CRN) is available!\n");

		printf("Please enter Company Registration Number(CRN) :\n");
		scanf("%d", &newNode -> CRN);
		printf("Please enter Company Name:\n");
		scanf("%s", newNode->CoName);
		printf("Please enter Company Country:\n");
		scanf("%s", newNode->CoCountry);
		printf("Please enter Year Company was Founded:\n");
		scanf("%d", &newNode->yearFounded);
		printf("Please enter Company Email Address(Must be valid email!):\n");
		scanf("%s", newNode->email);
		printf("Please enter Company Contact Name:\n");
		scanf("%s", newNode->ContactName);
		printf("Please enter Last Order:\n");
		scanf("%d", &newNode->LastOrder);
		printf("Please enter Number Of Employees:\n");
		scanf("%d", &newNode->NumOfEmployees);
		printf("Please enter Average Annual Order:\n");
		scanf("%f", &newNode->AverageAnnualOrder);
		printf("Is the Company Vat Registered?(Please Enter 1 for Yes or 2 for No.):\n");
		scanf("%d", &newNode->VatReg);
		printf("What is the Company's Average Turnover?:\n\t-Please enter 1 For Less than €1 Million\n\t-Please enter 2 for Less than €10 Million\n\t-Please enter 3 for Over €10 Million\n");
		scanf("%d", &newNode->AvgTurnover);
		printf("How many staff are employed in the Company?:\n\t-Please enter 1 For Less than 10\n\t-Please enter 2 for Less than 100\n\t-Please enter 3 for Over 100\n");
		scanf("%d", &newNode->StaffNum);
		printf("Which area of sales is the company?:\n\t-Please enter 1 For ICT\n\t-Please enter 2 for Medical Devices\n\t-Please enter 3 for Other area\n");
		scanf("%d", &newNode->AreaOfSales);
		while (temp->NEXT != NULL)
		{
			temp = temp->NEXT;
		}

		newNode->NEXT = NULL;
		temp->NEXT = newNode;
	}
	else {
		printf("The Company %d already exits, Please Try again\n", checkCRN);
	}//End of if else

}//End of addAtEndList

//Add to end the list
void addAtTheStartList(struct node** top)
{

		struct node* newNode;

		newNode = (struct node*)malloc(sizeof(struct node));

		printf("Please enter Company Registration Number(CRN):\n");
		scanf("%d", &newNode->CRN);
		printf("Please enter Company Name:\n");
		scanf("%s", newNode->CoName);
		printf("Please enter Company Country:\n");
		scanf("%s", newNode->CoCountry);
		printf("Please enter Year Company was Founded:\n");
		scanf("%d", &newNode->yearFounded);
		printf("Please enter Company Email Address(Must be valid email!):\n");
		scanf("%s", newNode->email);
		printf("Please enter Company Contact Name:\n");
		scanf("%s", newNode->ContactName);
		printf("Please enter Last Order:\n");
		scanf("%d", &newNode->LastOrder);
		printf("Please enter Number Of Employees:\n");
		scanf("%d", &newNode->NumOfEmployees);
		printf("Please enter Average Annual Order:\n");
		scanf("%f", &newNode->AverageAnnualOrder);
		printf("Is the Company Vat Registered?(Please Enter 1 for Yes or 2 for No.):\n");
		scanf("%d", &newNode->VatReg);
		printf("What is the Company's Average Turnover?:\n-Please enter 1 For Less than €1 Million\n\t-Please enter 2 for Less than €10 Million\n\t-Please enter 3 for Over €10 Million\n");
		scanf("%d", &newNode->AvgTurnover);
		printf("How many staff are employed in the Company?:\n\t-Please enter 1 For Less than 10\n\t-Please enter 2 for Less than 100\n\t-Please enter 3 for Over 100\n");
		scanf("%d", &newNode->StaffNum);
		printf("Which area of sales is the company?:\n\t-Please enter 1 For ICT\n\t-Please enter 2 for Medical Devices\n\t-Please enter 3 for Other area\n");
		scanf("%d", &newNode->AreaOfSales);


		newNode->NEXT = *top;
		*top = newNode;
	
}//End of addAtStartList

//Display entire List 
void displayList(nodeT* top)
{
	struct node* temp;

	temp = top;

	while (temp != NULL)
	{
		printf("\nCompany Registration Number(CRN) is: %d\n", temp->CRN);
		printf("Company Name is %s.\n", temp->CoName);
		printf("Company's is located in: %s.\n", temp->CoCountry);
		printf("Year Company was founded in %d.\n", temp->yearFounded);
		printf("Company Email Address is %s.\n", temp->email);
		printf("Company Contact Name is %s.\n", temp->ContactName);
		printf("Company's Last order was %d.\n", temp->LastOrder);
		printf("Company has %d employees.\n", temp->NumOfEmployees);
		printf("Company's average annual order is %f\n", temp->AverageAnnualOrder);
		printf("Is Company Vat Registered (1 == Yes and 2 == No) : %d\n", temp->VatReg);
		printf("Companys Average Turnover (1 == Less than 1 Million, 2 == Less than 10 Million, 3 == Over 10 Million): %d\n", temp->AvgTurnover);
		printf("Number of Staff employeed at company is (1 == Less than 10, 2 == Less than 100, 3 == Over 100): %d\n", temp->StaffNum);
		printf("Area of sales of company is (1 == ICT, 2 == Medical Devices, 3 == Over Area): %d\n", temp->AreaOfSales);

		temp = temp->NEXT;
	}
}//End of displayLiST

//Display single client from users choice
void displaySingle(nodeT* top, int location)
{
	struct node* temp = top;
	struct node* prev;
	int i;

	for (i = 0; i < location; i++)
	{
		prev = temp;
		temp = temp->NEXT;
	}

	prev->NEXT = temp->NEXT;

	printf("Company Registration Number(CRN) is: %d\n", temp->CRN);
	printf("Company Name is %s.\n", temp->CoName);
	printf("Company's is located in: %s.\n", temp->CoCountry);
	printf("Year Company was founded in %d.\n", temp->yearFounded);
	printf("Company Email Address is %s.\n", temp->email);
	printf("Company Contact Name is %s.\n", temp->ContactName);
	printf("Company's Last order was %d.\n", temp->LastOrder);
	printf("Company has %d employees.\n", temp->NumOfEmployees);
	printf("Company's average annual order is %f\n", temp->AverageAnnualOrder);
	printf("Is Company Vat Registered (1 == Yes and 2 == No) : %d\n", temp->VatReg);
	printf("Companys Average Turnover (1 == Less than 1 Million, 2 == Less than 10 Million, 3 == Over 10 Million): %d\n", temp->AvgTurnover);
	printf("Number of Staff employeed at company is (1 == Less than 10, 2 == Less than 100, 3 == Over 100): %d\n", temp->StaffNum);
	printf("Area of sales of company is (1 == ICT, 2 == Medical Devices, 3 == Over Area): %d\n", temp->AreaOfSales);

}//End of displaySingle

//Search if CRN exists in database
int search(nodeT* top, int searchCRN)
{
	struct node* temp = top;

	int found = -1;
	int count = 0;

	while (temp != NULL)
	{
		if (temp->CRN == searchCRN)
		{
			found = count;
		}

		temp = temp->NEXT;
		count++;
	}

	return found;
}//End of search

//Create a report for user
void createReport(struct node* top)
{
	struct node* temp;
	FILE* fp;
	temp = top;

	fp = fopen("clientDataBase.txt", "w");

	while (temp != NULL)
	{
		if (fp != NULL)
		{
			fprintf(fp, "\nCompany Registration Number(CRN) is: %d\n", temp->CRN);
			fprintf(fp, "Company Name is %s.\n", temp->CoName);
			fprintf(fp, "Company's is located in: %s.\n", temp->CoCountry);
			fprintf(fp, "Year Company was founded in %d.\n", temp->yearFounded);
			fprintf(fp, "Company Email Address is %s.\n", temp->email);
			fprintf(fp, "Company Contact Name is %s.\n", temp->ContactName);
			fprintf(fp, "Company's Last order was %d.\n", temp->LastOrder);
			fprintf(fp, "Company has %d employees.\n", temp->NumOfEmployees);
			fprintf(fp, "Company's average annual order is %f\n", temp->AverageAnnualOrder);
			fprintf(fp, "Is Company Vat Registered (1 == Yes and 2 == No) : %d\n", temp->VatReg);
			fprintf(fp, "Companys Average Turnover (1 == Less than 1 Million, 2 == Less than 10 Million, 3 == Over 10 Million): %d\n", temp->AvgTurnover);
			fprintf(fp, "Number of Staff employeed at company is (1 == Less than 10, 2 == Less than 100, 3 == Over 100): %d\n", temp->StaffNum);
			fprintf(fp, "Area of sales of company is (1 == ICT, 2 == Medical Devices, 3 == Over Area): %d\n", temp->AreaOfSales);
		}
		temp = temp->NEXT;
	}

	if (fp != NULL)
	{
		fclose(fp);
	}

	printf("A report with all cliental info has been outputted.\n");
}

//Gets Length of list
int listLength(nodeT* top)
{
	struct node* temp = top;
	int count = 0;

	while (temp != NULL)
	{
		count = count + 1;
		temp = temp->NEXT;
	}

	return count;
}

//Deletes from end of the list
void deleteAtEnd(struct node* top)
{
	struct node* temp = top;
	struct node* prev = NULL;

	while (temp->NEXT != NULL)
	{
		prev = temp;
		temp = temp->NEXT;
	}

	prev->NEXT = NULL;
	free(temp);
}

//Deletes from start of the list
void deleteAtStart(struct node** top)
{
	struct node* temp = *top;

	*top = (*top)->NEXT;

	free(temp);
}

//Deletes from anywhere bar start and end of the list
void deleteAtLocation(struct node* top, int location)
{
	struct node* temp = top;
	struct node* prev;
	int i;

	for (i = 0; i < location; i++)
	{
		prev = temp;
		temp = temp->NEXT;
	}

	prev->NEXT = temp->NEXT;
	free(temp);
}

//Saves raw data for system to save and retrieve and initilize linked list
void saveRawData(struct node* top)
{
	struct node* temp;
	FILE* fp;
	temp = top;

	fp = fopen("rawData.txt", "w");

	while (temp != NULL)
	{
		if (fp != NULL)
		{
			fprintf(fp, "%d %s %s %d %s %s %d %d %f %d %d %d %d\n", temp->CRN,temp->CoName,temp->CoCountry,temp->yearFounded,temp->email, temp->ContactName,temp->LastOrder,temp->NumOfEmployees,temp->AverageAnnualOrder,temp->VatReg,temp->AvgTurnover,temp->StaffNum,temp->AreaOfSales);
		}
		temp = temp->NEXT;
	}

	if (fp != NULL)
	{
		fclose(fp);
	}
}

//Checks for login details from file and cheks with user input
int login() 
{
	FILE* fptr;
	char userName[10];
	char password[10], c;
	int index = 0;

	char name1[6];
	char pass1[6];

	char name2[6];
	char pass2[6];

	char name3[6];
	char pass3[6];

	int decision;

	printf("Please enter your username(Username should not exceed 6 Charecters):\n");
	scanf("%s", userName);


	printf("Please enter your password(Passwprd should not exceed 6 Charecters):\n");

	// 13 is ASCII value of * character 
	while ((c = getch()) != 13) {
		if (index < 0)
			index = 0;
		// 8 is ASCII value of BACKSPACE character 
		if (c == 8) {
			putch('\b');
			putch(NULL);
			putch('\b');
			index--;
			continue;
		}
		password[index++] = c;
		putch('*');
	}
	password[index] = '\0';


	fptr = fopen("USERDETAILS.txt", "r");

	//Checks if file is valid
	if (fptr == NULL)
	{
		printf("Please check if Login file is vaild!!\n");
	}
	else {
		while (!feof(fptr))
		{
			//Grabs info from file
			fscanf(fptr, "%s\n%s\n%s\n%s\n%s\n%s", name1, pass1, name2, pass2, name3, pass3);
		}
		fclose(fptr);
	}

	#if DEBUG 
		 printf("\n%s %s %s %s %s %s\n", name1, pass1, name2, pass2, name3, pass3);
	#endif

	//Compares if details from file is same as user

	if (((strcmp(userName, name1) == 0) && (strcmp(password, pass1) == 0))) {
		printf("\nCorrect\n");
		return 1;
	}
	else if (((strcmp(userName, name2) == 0) && (strcmp(password, pass2) == 0)))
	{
		printf("\nCorrect\n");
		return 1;
	}
	else if (((strcmp(userName, name3) == 0) && (strcmp(password, pass3) == 0)))
	{
		printf("\nCorrect\n");
		return 1;
	}else{
		printf("\nYou have entered the wrong password or username, Please try again\n");
		return 0;
	}

}

//Initilizes first line of data to linked list
void initilizeStartLinkedList(struct node** top) {

	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));

	FILE* fptr;

	fptr = fopen("rawData.txt", "r");

	//Checks if file is valid
	if (fptr == NULL)
	{
		printf("Please check if rawData file is vaild!! - Data has not been initilized\n");
	}
	else {
		//Grabs info from file
		fscanf(fptr, "%d %s %s %d %s %s %d %d %f %d %d %d %d", &newNode->CRN, newNode->CoName, newNode->CoCountry, &newNode->yearFounded, newNode->email, newNode->ContactName, &newNode->LastOrder, &newNode->NumOfEmployees, &newNode->AverageAnnualOrder, &newNode->VatReg, &newNode->AvgTurnover, &newNode->StaffNum, &newNode->AreaOfSales);
		fclose(fptr);
	}
	
	newNode->NEXT = *top;
	*top = newNode;
}

//Initilizes all data to linked liost bar first line
void initilizeEndLinkedList(struct node* top) {

	FILE* fptr;

	fptr = fopen("rawData.txt", "r");

	//Checks if file is valid
	if (fptr == NULL)
	{
		printf("Please check if rawData file is vaild!! - Data has not been initilized\n");
	}
	else {
		
		while (!feof(fptr))
		{
			struct node* temp = top;
			struct node* newNode;
			newNode = (struct node*)malloc(sizeof(struct node));

			//Grabs info from file
			fscanf(fptr, "%d %s %s %d %s %s %d %d %f %d %d %d %d\n", &newNode->CRN, newNode->CoName, newNode->CoCountry, &newNode->yearFounded, newNode->email, newNode->ContactName, &newNode->LastOrder, &newNode->NumOfEmployees, &newNode->AverageAnnualOrder, &newNode->VatReg, &newNode->AvgTurnover, &newNode->StaffNum, &newNode->AreaOfSales);
			
			while (temp->NEXT != NULL)
			{
				temp = temp->NEXT;
			}

			newNode->NEXT = NULL;
			temp->NEXT = newNode;
		}
		fclose(fptr);
	}



}

//Updates existing client info
void updateClient(struct node* top) {

	struct node* temp = top;
	int updateID, resultUpdate;

	printf("Please enter the Company Registration Number of client you would like to update:\n");
	scanf("%d", &updateID);

	resultUpdate = search(temp, updateID);

	if (temp == NULL)
	{
		printf("The database is empty\n");
	}
	else if (resultUpdate<0 || resultUpdate>(listLength(temp) - 1))
	{
		printf("The CRN is not valid\n");
	}

	else if (resultUpdate == 0)
	{
		deleteAtStart(&temp);
	}

	else if (resultUpdate == (listLength(temp) - 1))
	{
		deleteAtEnd(temp);
	}

	else
	{
		deleteAtLocation(temp, resultUpdate);
	}

	if (temp == NULL)
	{
		addAtTheStartList(&temp);
	}

	else
	{
		addAtTheEndList(temp);
	}

}
