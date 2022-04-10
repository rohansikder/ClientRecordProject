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


void main()
{
	nodeT* headPtr = NULL;
	nodeT* newNode;
	nodeT* temp;
	int choice;

	printf("Please enter 1 to Add client (Note: Company Registeration Number must be unique)\n");
	printf("Please enter 2 to Display all client details\n");
	printf("Please enter 3 to Display client details\n");
	printf("Please enter 4 to Update a client details\n");
	printf("Please enter 5 to Delete client\n");
	printf("Please enter 6 to Generate statistics (a to c) based on the user selecting one of the criteria listed in I - II\n---A. Less than €1 Million\n---B. Less than €10 Million\n---C. Over €10 Million\n---I. Area of Company Sales\n---II. Number of Employees\n");
	printf("\nPlease enter 7 to Print all client details into a report file.\n");
	printf("Please enter 8 to List all the clients in order of their last average turnover\n");
	printf("Please enter -1 to exit application\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
		{
			addAtTheStartList(&headPtr);
		}

		else if (choice == 2)
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

		else if (choice == 3)
		{
			
		}

		else if (choice == 4)
		{
			
		}

		else if (choice == 5)
		{

			
		}

		else if (choice == 6)
		{
			
		}

		else if (choice == 7)
		{
			
		}

		else if (choice == 8)
		{
			
		}


		printf("Please enter 1 to Add client (Note: Company Registeration Number must be unique)\n");
		printf("Please enter 2 to Display all client details\n");
		printf("Please enter 3 to Display client details\n");
		printf("Please enter 4 to Update a client details\n");
		printf("Please enter 5 to Delete client\n");
		printf("Please enter 6 to Generate statistics (a – c) based on the user selecting one of the criteria listed in I - II\n---A. Less than €1 Million\n---B. Less than €10 Million\n---C. Over €10 Million\n---I. Area of Company Sales\n---II. Number of Employees\n");
		printf("\nPlease enter 7 to Print all client details into a report file.\n");
		printf("Please enter 8 to List all the clients in order of their last average turnover\n");
		printf("Please enter -1 to exit application\n");
		scanf("%d", &choice);
	}

}//End Of Main

void addAtTheEndList(struct node* top)
{
	struct node* temp = top;
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter Company Registration Number(CRN):\n");
	scanf("%d",&newNode->CRN);
	printf("\nPlease enter Company Name:\n");
	scanf("%s", newNode->CoName);
	printf("\nPlease enter Company Country:\n");
	scanf("%s", newNode->CoCountry);
	printf("\nPlease enter Year Company was Founded:\n");
	scanf("%d", &newNode->yearFounded);
	printf("\nPlease enter Company Email Addres(Must be valid email!):\n");
	scanf("%s", newNode->email);
	printf("Please enter Company Contact Name:\n");
	scanf("%s", newNode->ContactName);
	printf("\nPlease enter Last Order:\n");
	scanf("%d", &newNode->LastOrder);
	printf("\nPlease enter Number Of Employees:\n");
	scanf("%d", &newNode->NumOfEmployees);
	printf("\nPlease enter Average Annual Order:\n");
	scanf("%f", &newNode->AverageAnnualOrder);
	printf("\nIs the Company Vat Registered?(Please Enter 1 for Yes or 2 for No.):\n");
	scanf("%d", &newNode->VatReg);
	printf("\nWhat is the Company's Average Turnover?:\n-Please enter 1 For Less than €1 Million\n-Please enter 2 for Less than €10 Million\n-Please enter 3 for Over €10 Million\n");
	scanf("%d", &newNode->AvgTurnover);
	printf("\nHow many staff are employed in the Company?:\n-Please enter 1 For Less than 10\n-Please enter 2 for Less than 100\n-Please enter 3 for Over 100\n");
	scanf("%d", &newNode->StaffNum);
	printf("\nWhich area of sales is the company?:\n-Please enter 1 For ICT\n-Please enter 2 for Medical Devices\n-Please enter 3 for Other area\n");
	scanf("%d", &newNode->AreaOfSales);

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}

void addAtTheStartList(struct node** top)
{
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter Company Registration Number(CRN):\n");
	scanf("%d", &newNode->CRN);
	printf("\nPlease enter Company Name:\n");
	scanf("%s", newNode->CoName);
	printf("\nPlease enter Company Country:\n");
	scanf("%s", newNode->CoCountry);
	printf("\nPlease enter Year Company was Founded:\n");
	scanf("%d", &newNode->yearFounded);
	printf("\nPlease enter Company Email Addres(Must be valid email!):\n");
	scanf("%s", newNode->email);
	printf("Please enter Company Contact Name:\n");
	scanf("%s", newNode->ContactName);
	printf("\nPlease enter Last Order:\n");
	scanf("%d", &newNode->LastOrder);
	printf("\nPlease enter Number Of Employees:\n");
	scanf("%d", &newNode->NumOfEmployees);
	printf("\nPlease enter Average Annual Order:\n");
	scanf("%f", &newNode->AverageAnnualOrder);
	printf("\nIs the Company Vat Registered?(Please Enter 1 for Yes or 2 for No.):\n");
	scanf("%d", &newNode->VatReg);
	printf("\nWhat is the Company's Average Turnover?:\n-Please enter 1 For Less than €1 Million\n-Please enter 2 for Less than €10 Million\n-Please enter 3 for Over €10 Million\n");
	scanf("%d", &newNode->AvgTurnover);
	printf("\nHow many staff are employed in the Company?:\n-Please enter 1 For Less than 10\n-Please enter 2 for Less than 100\n-Please enter 3 for Over 100\n");
	scanf("%d", &newNode->StaffNum);
	printf("\nWhich area of sales is the company?:\n-Please enter 1 For ICT\n-Please enter 2 for Medical Devices\n-Please enter 3 for Other area\n");
	scanf("%d", &newNode->AreaOfSales);

	newNode->NEXT = *top;
	*top = newNode;

}