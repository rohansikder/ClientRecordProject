#include<stdio.h>//Input/Output
#include<stdlib.h>//Memory Allocation
#include<string.h>

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
int search(nodeT* top, int searchCRN);
void deleteAtEnd(struct node* top);
void deleteAtStart(struct node** top);
void deleteAtLocation(struct node* top, int location);
int listLength(nodeT* top);
void outputToFile(struct node* top);


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


	printf("Please enter 1 to Add client (Note: Company Registeration Number must be unique)\n");//Done But not unique
	printf("Please enter 2 to Display all client details\n");//Done
	printf("Please enter 3 to Display client details\n");
	printf("Please enter 4 to Update a client details\n");
	printf("Please enter 5 to Delete client\n");//Done
	printf("Please enter 6 to Generate statistics (a to c) based on the user selecting one of the criteria listed in I - II\n\tA. Less than €1 Million\n\tB. Less than €10 Million\n\tC. Over €10 Million\n\tI. Area of Company Sales\n\tII. Number of Employees\n");
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
		}

		else if (choice == 2)
		{
			displayList(headPtr);
		}

		else if (choice == 3)
		{
			printf("Please enter the Company Resgistration number you wish to search for\n");
			scanf("%d", &searchID);

			resultSearch = search(headPtr, searchID);

			if (resultSearch == -1) {
				printf("The Company %d does not exist in the list\n", searchID);
			}
			else {
				printf("The Company %d is at location %d\n", searchID, resultSearch);
			}
		}

		else if (choice == 4)
		{

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

		}

		else if (choice == 6)
		{

		}

		else if (choice == 7)
		{
			outputToFile(headPtr);
		}

		else if (choice == 8)
		{

		}


		printf("\nPlease enter 1 to Add client (Note: Company Registeration Number must be unique)\n");
		printf("Please enter 2 to Display all client details\n");
		printf("Please enter 3 to Display client details\n");
		printf("Please enter 4 to Update a client details\n");
		printf("Please enter 5 to Delete client\n");
		printf("Please enter 6 to Generate statistics (a – c) based on the user selecting one of the criteria listed in I - II\n\tA. Less than €1 Million\n\tB. Less than €10 Million\n\tC. Over €10 Million\n\tI. Area of Company Sales\n\tII. Number of Employees\n");
		printf("Please enter 7 to Print all client details into a report file.\n");
		printf("Please enter 8 to List all the clients in order of their last average turnover\n");
		printf("Please enter -1 to exit application\n");
		scanf("%d", &choice);
		printf("\n");
	}//End OF while

}//End Of Main

void addAtTheEndList(struct node* top)
{

	struct node* temp = top;
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter Company Registration Number(CRN):\n");
	scanf("%d", &newNode->CRN);
	printf("Please enter Company Name:\n");
	scanf("%s", newNode->CoName);

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newNode->NEXT = NULL;
	temp->NEXT = newNode;


}//End of addAtEndList

void addAtTheStartList(struct node** top)
{

	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Please enter Company Registration Number(CRN):\n");
	scanf("%d", &newNode->CRN);
	printf("Please enter Company Name:\n");
	scanf("%s", newNode->CoName);


	newNode->NEXT = *top;
	*top = newNode;

}//End of addAtStartList

void displayList(nodeT* top)
{
	struct node* temp;

	temp = top;

	while (temp != NULL)
	{
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

		temp = temp->NEXT;
	}
}//End of displayLiST

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

void outputToFile(struct node* top)
{
	struct node* temp;
	FILE* fp;
	temp = top;

	fp = fopen("clientDataBase.txt", "w");

	while (temp != NULL)
	{
		if (fp != NULL)
		{
			fprintf(fp, "Company Registration Number(CRN) is: %d\n", temp->CRN);
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
}

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

void deleteAtStart(struct node** top)
{
	struct node* temp = *top;

	*top = (*top)->NEXT;

	free(temp);
}

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
