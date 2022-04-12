# ClientRecordProject

XYX Medical Supplier Ltd currently manually store client record but have requested you to
develop a new client record application for them.
This program will create a database which will store the details of all the client in the
company. In addition to storing all the client data the application should allow overall client
statistics to be generated.
Your program should create the database (which for your purpose MUST be implemented
as a linked list) and be able to save, restore, retrieve, add, delete and update client details.
For each client, you will store the following details:

• Company Registration Number (Assume an integer – must be unique)

• Company Name

• Company Country

• Year Company Founded

• Email Address (must contain an @, a full stop and a .com)

• Company Contact Name

• Last Order

• Number of Employees

• Average Annual Order

• Is the Client Vat Registered?
▪ Yes
▪ No

• What are the Clients Average Turnover?
▪ Less than €1 Million
▪ Less than €10 Million
▪ Over €10 Million

• How many staff are employed in the Client Company?
▪ Less than 10
▪ Less than €100
▪ Over 100

• Which area of sales is the company?
▪ ICT
▪ Medical Devices
▪ Other area

The system is password protected and only the correct username and password details will
allow the user to gain access to the system.
The username and password (6 characters in length) will be stored in a login structure which
is read in from a login file which holds three login records. Ensure that when the user enters
in the password that it cannot be seen on the screen. (It only shows an * for each character.
E.g. ******)

Your program should initialise the linked list based on the patient profiles stored in the
clients.txt file. This file should be updated when the user terminates the program.
Your program should provide a menu as follows:

1) Add client (Note: Company Registeration Number must be unique).
2) Display all client details to screen
3) Display client details
4) Update a client details
5) Delete client
6) Generate statistics (a – c) based on the user selecting one of the criteria listed in I - II
A. Less than €1 Million
B. Less than €10 Million
C. Over €10 Million
I. Area of Company Sales
II. Number of Employees
7) Print all client details into a report file.
8) List all the clients in order of their last average turnover

Add Client: This will add a new patient in your linked list. The Company Registration number
must be unique. If it is not a unique Company Registration number then the user show be
given the opportunity to update the client’s details.

Display all client details to screen: Display all client details to screen
Display client details: Allow the user to input the Client’s Registration Number and display
the details for that client.

Update Client: Allows the user to update client details based on either the company
registration number.

Delete Patient: Allows the user to delete a client from the list by Company Registration
Number.

Print all Client Details into a report file: Display a client report which outputs the following
information of the clients to file:
• All client details
• Client Statistics (based upon item 6 of the menu)

Validation:
Your program should perform validation on all menu inputs.
