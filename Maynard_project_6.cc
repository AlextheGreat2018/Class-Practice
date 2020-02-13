//---------------------------------------------------------------------------------------------------------
// FILE:	Maynard_project_5.cc
// TITLE:	Interest Calculator
// AUTHOR:	Alex Maynard
// COURSE:	CSCI 2000-A (C++)
// DATE:	11/7/17
//
// PURPOSE:	This program is an updated version of the previous programming project. It will use a series of back-end updates such as Top-Down Design, revamped menu structure, improved input validation, and brand new functionality.
//
//---------------------------------------------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// This function will display the main menu for the program.
void main_menu();

// This function will display a sub menu with tools for calculating the investment value.
void calc_menu();

// This function will display the input given by the user.
void future_value_display(double sa, double ai, int yc, int ti);

// This function will display tables showing the future value of investment after a certain amount of time.
void future_value_calc(double& sa, double& ai, int& yc, int& ti);

// This function will display a sub menu showing future functions.
void ret_menu();

// This function will validate the input for the program's retirement simulation feature.
void input_valid(double& ct, double& rt, double& ir, double& ai, int& ti, string instructions);

// This function will simulate both IRA and Roth IRA to see how much money will be saved between the two.
void ret_sim(double& ct, double& ir, double& ai, int& ti);

// This funcion will display a table displaying the input from the user and the results from the simulation.
void ret_display(double& ct, double& rt, double& ir, double& ai);

// This function will validate the input for the values used in calculating the future value of an investment.
void input_valid(double& sa, double& ai, int& yc, int& ti, string instructions);

// This function will display the value of the account after each compounding period.
void display_value(double& sa, double& ai);

// This function will display a sub menu for tax preparation.
void tax_menu();

// This function will provide an interview for the user to ask some questions.
void tax_interview(double iv[], char& file, int& i);

// This function will display the details inputted to the interview from the user.
void interview_details(double iv[], char file, int i);

// This function will calculate the user's inputted values and prepare a 1040-EZ tax plan.
void interview_calc(double iv[], char& file, int& i);

int main()
{

   main_menu();

   return 0;
}

void main_menu()
{

   // This will be the variable used for the user's input for the main menu.
   char main_menu_input;

   cout << "Interest Advisor\n";
   cout << "Version 2.1\n";
   cout << "by Alex Maynard\n\n";

   cout << "This program is an updated edition of the Interest Calculator with new menu capabilities.\n";

   // The menu will continue to loop until the user exits the program.
   do
   {
      cout << "Please select one of the following options:\n";
      cout << "Investment (C)alculation Tools\n";
      cout << "(R)etirement Planning\n";
      cout << "(T)ax Preparation";
      cout << "E(X)it the Program\n";
      cin >> main_menu_input;

      switch (main_menu_input)
      {
         case 'C':
         case 'c':
            calc_menu();
         break;

         case 'R':
         case 'r':
            ret_menu();
         break;

         case 'T':
         case 't':
            tax_menu();
         break;

         case 'X':
         case 'x':
            cout << "\n\nThanks for using our app! We hope you're happy with the results. Goodbye.";
         break;

         default:
            cout << "You entered: " << main_menu_input << " which is not valid.";
            cout << " Please enter either S, M, T, or X\n";
         break;
      }

   } while (main_menu_input != 'X' && main_menu_input != 'x');

   return;
}

void calc_menu()
{
   // These will be the variables used to calculate the future value of an investment.
   double start_amount, annual_interest;
   int yearly_compoundings, total_investment;
   // This will be the variable used for the user's input in this sub menu.
   char calc_menu_input;

   // The menu will continue to loop until the user returns to the main menu.
   do
   {
      cout << "Please select one of the following Calculation Tools:\n\n";
      cout << "Calculate the (F)uture Value of an Investment Account\n";
      cout << "(D)isplay the Value of the Account After Each Compounding Period\n";
      cout << "(R)eturn to Main Menu\n\n";
      cin >> calc_menu_input;

      switch (calc_menu_input)
      {
         case 'F':
         case 'f':
            input_valid(start_amount, annual_interest, yearly_compoundings, total_investment, "\nPlease enter the following information:\n");
            future_value_display(start_amount, annual_interest, yearly_compoundings, total_investment);
            future_value_calc(start_amount, annual_interest, yearly_compoundings, total_investment);
         break;

         case 'D':
         case 'd':
            input_valid(start_amount, annual_interest, yearly_compoundings, total_investment, "\nPlease enter the following information:\n");
            display_value(start_amount, annual_interest);
         break;

         case 'R':
         case 'r':
         break;

         default:
            cout << "Sorry! You entered " << calc_menu_input << " which is not valid.\n";
            cout << "Please enter either F, D, or R\n\n";
         break;
      }

   } while (calc_menu_input != 'R' && calc_menu_input != 'r');

   return;
}

void input_valid(double& sa, double& ai, int& yc, int& ti, string instructions)
{

   do
   {
      // The instructions used here will be the instructions used in the function call.
      cout << instructions;

      //The user will be able to input the information here. The program will continue to loop until the input is correct.
      cout << "\nStarting amount: ";
      cin >> sa;

      cout << "\nAnnual interest rate (as a decimal): ";
      cin >> ai;

      cout << "\nNumber of compoundings in a year (has to be more than one): ";
      cin >> yc;

      cout << "\nTotal investment time (in years): ";
      cin >> ti;

   } while (sa < 0, ai < 0, yc < 1, ti < 0);

   return;
}

void future_value_display(double sa, double ai, int yc, int ti)
{

   // The program will echo the input to the user in the form of a table.
   cout << "\n\n------------------------------------------------------------------\n";
   cout << "Here is the information that you gave me:\n";
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "\nStarting amount: $" << sa << endl;
   cout.precision(3);
   cout << "Annual interest rate: " << ai << endl;
   cout << "Number of compoundings in a year: " << yc << endl;
   cout << "Total investment time: " << ti << " years." << endl;
   cout << "----------------------------------------------------------------------\n";

   return;
}

void future_value_calc(double& sa, double& ai, int& yc, int& ti)
{
   // This will be the variable used for the future value of an investment.
   double future_value;

   // This will be the calculation used to determine the future value.
   future_value = sa * pow(1 + (ai / 100) / yc, yc * ti);

   // The tables below will show the results for the future value of investment. It will show separate tables for five years and ten years.
   cout << "\n--------------------------------------------------------------------\n";
   cout << "The results for your future value are shown below:\n";
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "\nStarting amount: $" << sa << endl;
   cout << "Time of investment: " << ti << " years." << endl;
   cout << "Future value of investment: $" << future_value << endl;
   cout << "Interest earned: $" << sa * (1 + (ai * ti)) << endl;
   cout << "----------------------------------------------------------------------\n";

   cout << "\nLet's see what it would look like if we added 5 years to the investment.\n";
   cout << "\n---------------------------------------------------------------------\n";
   cout << "\nStarting amount: $" << sa << endl;
   cout << "Time of investment: " << ti + 5 << " years." << endl;
   cout << "Future value of investment: $" << sa * pow(1 + ai/100 / yc, yc * (ti + 5)) << endl;
   cout << "Interest earned: $" << sa * pow(1 + (ai / 100) / yc, yc * (ti + 5)) - sa << endl;
   cout << "------------------------------------------------------------------------\n";

   cout << "\nHow about 10 years?\n";
   cout << "\n----------------------------------------------------------------------\n";
   cout << "\nStarting amount: $" << sa << endl;
   cout << "Time of investment: " << ti + 10 << " years." << endl;
   cout << "Future value of investment: $" << sa * pow(1 + ai/100 / yc, yc * (ti + 10)) << endl;
   cout << "Interest earned: $" << sa * pow(1 + (ai / 100) / yc, yc * (ti + 10)) - sa << endl;
   cout << "------------------------------------------------------------------------\n";

   return;
}

void display_value(double& sa, double& ai)
{
   // This variable will be the compounding number (cn).
   int cn;

   // The program will output a table showing the value of the account after each compounding.
   cout << "\nCompounding Number:\t";
   cout << "Value of the Account:\t";
   cout << "Interest Earned to Date:\n";
   for (cn = 0; cn <= 20; cn++)
   {
      cout << cn << "\t\t\t";
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);
      cout << "$" << sa + (ai * cn) << "\t\t\t";
      cout << "$" << (ai * cn) << "\n";
   };

   return;
}

void ret_menu()
{
   // These will be the variables used to simulate retirement savings in IRA vs Roth IRA.
   double current_tax, retire_tax, interest_rate, annual_investment;
   int total_investment;

   // This will be the variable for the user input.
   char ret_menu_input;

   // This sub menu will continue to loop until the user returns to the main menu.
   do
   {
      cout << "\n\nPlease select one of the following options for retirement planning:\n\n";
      cout << "(S)imulate Retirement Savings in IRA vs Roth IRA\n";
      cout << "(R)eturn to Main Menu\n\n";
      cin >> ret_menu_input;

      switch (ret_menu_input)
      {
         case 'S':
         case 's':
            input_valid(current_tax, retire_tax, interest_rate, annual_investment, total_investment, "\nThis feature will take the user input and determine whether it would be better to use IRA or Roth IRA. Please input the information below: \n\n");
            ret_sim(current_tax, interest_rate, annual_investment, total_investment);
            ret_display(current_tax, retire_tax, interest_rate, annual_investment);
         break;

         case 'R':
         case 'r':
         break;

         default:
            cout << "Sorry! You entered " << ret_menu_input << " which is not valid.\n";
            cout << "Please enter either S or R\n\n";
         break;
      }

   } while (ret_menu_input != 'R' && ret_menu_input != 'r');

   return;
}

void input_valid(double& ct, double & rt, double& ir, double& ai, int& ti, string instructions)
{

   // The instructions here will be the instructions used in the function call.
   cout << instructions;
   // Until the user inputs the correct values, the program will continue to loop.
   do
   {
   cout << "Current tax rate (in decimal form): ";
   cin >> ct;
   cout << "\nEstimated retirement tax rate (in decimal form): ";
   cin >> rt;
   cout << "\nAnnual interest rate (in decimal form): ";
   cin >> ir;
   cout << "\nAnnual investment: ";
   cin >> ai;
   cout << "\nTotal investment time (in years): ";
   cin >> ti;
   } while (ct < 0, rt < 0, ir < 0, ai < 0, ai > 5500, ti < 0);

   return;
}

void ret_sim(double& ct, double& ir, double& ai, int& ti)
{
   // This variable will be the starting balance for an account.
   double balance = 0;

   // The program will simulate the growing for both IRA and Roth IRA.
   cout << "\nIRA Simulation: \n\n";
   cout << "Year:\t\t";
   cout << "Account Value:\n";
   for (ti = 0; ti <= 15; ti++)
   {
      cout << ti << "\t\t";
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2);
      cout << "$" << balance + (ai * ti) * (1 + ir) << "\n";
   }
   cout << "\nRoth IRA Simulation: \n\n";
   cout << "Year:\t\t";
   cout << "Account Value:\n";
   for (ti = 0; ti <= 20; ti++)
   {
      cout << ti << "\t\t";
      cout << "$" << balance + ((ai * ti) * (1 - ct)) * (1 + ir) << "\n";
   }

   return;
}

void ret_display(double& ct, double& rt, double& ir, double& ai)
{
   // These will be the variables used to calculate the future value of the account for both pretax and post tax.
   double ira, rira, balance = 0;

   // These will be the calculations used for pretax and post tax.
   ira = balance + (ai * 15) * (1 + ir);
   rira = balance + ((ai * 15) * (1 - ct)) * (1 + ir);

   // This will be the table displaying the user input and the results for the future value.
   cout << "\t\t\t";
   cout << "Regular IRA\t";
   cout << "Roth IRA\t";
   cout << "Difference\n";
   cout << "Current Tax Rate:\t\t";
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(3);
   cout << ct << "\t\t";
   cout << ct << "\t\t";
   cout << ct - ct << "\n";
   cout << "Estimated Retirement Tax Rate:\t";
   cout << rt << "\t\t";
   cout << rt << "\t\t";
   cout << rt - rt << "\n";
   cout << "Annual Investment:\t";
   cout.precision(2);
   cout << "$" << ai << "\t";
   cout << "$" << ai << "\t";
   cout << "$" << ai - ai << "\n";
   cout << "Actual Annual Investment:\t";
   cout << "$" << ai << "\t";
   cout << "$" << ai * (1 - ct) << "\t";
   cout << "$" << ai - (ai * (1 - ct)) << "\n";
   cout << "Annual Interest Rate:\t\t";
   cout.precision(3);
   cout << ir << "\t\t";
   cout << ir << "\t\t";
   cout << ir - ir << "\n";
   cout << "Years till Retirement:\t\t";
   cout << "15\t\t";
   cout << "15\t\t";
   cout << "0 years\n";
   cout << "Future Value of the Account(pretax):\t";
   cout.precision(2);
   cout << "$" << ira << "\t";
   cout << "$" << rira << "\t";
   cout << "$" << ira - rira << "\n";
   cout << "Future Value of the Account(post tax):\t";
   cout << "$" << ira * (1 - ct) << "\t";
   cout << "$" << rira << "\t";
   cout << "$" << (ira * (1 - ct) - rira) << "\n\n";

   // The program will tell the user which retirement plan is better based on how much money will be saved.
   if (ira > rira)
   {
      cout << "Based on the information given, IRA would prove to be much better than Roth IRA.\n";
      cout << "You would be saving at most $" << ira - rira << " doing so.";
   }
   else
   {
      cout << "Based on the information given, Roth IRA would prove much better than IRA.\n";
      cout << "You would be saving at most $" << rira - ira << " doing so.";
   }

   return;
}

void tax_menu()
{

   int forms;
   double interview_input[7];
   char tax_menu_input, joint_file;
   bool interview = false;

   // This will be the sub menu for tax preparation.
   do
   {
      cout << "\n\nTax Preparation (1040-EZ ONLY):\n";
      cout << "\nAnswer Tax Questions in an Online (I)nterview\n";
      cout << "(D)isplay the Details of your Tax Interview\n";
      cout << "(C)alculate and Prepare your 1040-EZ\n";
      cout << "(R)eturn to Main Menu\n";
      cin >> tax_menu_input;

      switch (tax_menu_input)
      {
         case 'I':
         case 'i':
            tax_interview(interview_input[7], joint_file, forms);
            // Once the interview is complete, the boolean variable, interview will become true.
            interview = true;
         break;

         case 'D':
         case 'd':
            if (interview = true)
               interview_details(interview_input[7], joint_file, forms);
            else
               cout << "\nSorry! Your interview has not yet been completed. Please complete the interview before going further.\n";
         break;

         case 'C':
         case 'c':
            if (interview = true)
               interview_calc(interview_input[7], joint_file, forms);
            else
               cout << "\nSorry! Your interview has not yet been completed. Please complete the interview before going further.\n";
         break;

         case 'R':
         case 'r':

         break;

         default:
            cout << "\nYou entered: " << tax_menu_input << " which is not a valid input. Please enter either I, D, C, or R.\n";
         break;
      }
   } while (tax_menu_input != 'R' && tax_menu_input != 'r');

   return;
}

void tax_interview(double iv[], char& file, int& i)
{

   // This entire segment of code will be the interview given to the user.
   cout << "\n\nYou will be asked some questions regarding your income tax return.\n";
   do
   {
      cout << "\nHow many W-2's do you have?\n";
      cout << "\nW-2's: ";
      cin >> iv[i];
      if (iv[i] <= 0)
      {
         for(i = 1; i <= iv[i]; i++)
         {
            cout << "\nPlease enter your wages, tips and salaries.\n";
            cout << "\nWages: ";
            cin >> iv[2];
            cout << "\n\nTips: ";
            cin >> iv[3];
            cout << "\n\nSalaries: ";
            cin >> iv[4];
         };
      }
      cout << "\n\nPlease enter your taxable interest: ";
      cin >> iv[5];
      if(iv[5] > 1500)
         cout << "I'm sorry, but you are not eligible for the 1040-EZ plan.";
      cout << "\nAre you filing (s)ingle or (j)ointly? ";
      cin >> file;
      do
      {
         switch (file)
         {
            case 'S':
            case 's':

            break;

            case 'J':
            case 'j':

            break;

            default:
               cout << "\nYou entered: " << file << " which is not a valid input. Please enter either S or J.\n";
            break;
         }
      } while (file != 'S' && file != 's' && file != file != 'J' && file != 'j');
      cout << "\nHow much tax was withheld?\n";
      cout << "Tax withheld: ";
      cin >> iv[6];
   } while (iv[1] < 0 && iv[2] < 0 && iv[3] < 0 && iv[4] < 0 && iv[5] < 0 && iv[5] > 1500 && file != 'S' && file != 's' && file != 'J' && file != 'j' && iv[6] < 0);
   cout << "\nThank you for participating in our interview!\n";
   cout << "Be sure to check your interview results and prepare a 1040-EZ plan.\n";

   return;
}

void interview_details(double iv[], char file, int i)
{

   // The function will display the values inputted by the user.
   cout << "\nNumber of W-2 forms: ";
   cout << iv[i];

   for (i = 1; i <= iv[i]; i++)
   {
      cout << "\nWages: " << iv[2] << endl;
      cout << "Tips: " << iv[3] << endl;
      cout << "Salaries: " << iv[4] << endl;
   }
   cout << "Taxable interest: " << iv[5] << endl;
   cout << "\nMethod of filing: ";
   if (file == 'S' || file == 's')
      cout << "Single\n";
   else if (file == 'J' || file == 'j')
      cout << "Married filing jointly\n";
   cout << "Tax withheld: " << iv[6] << endl;

   return;
}

void interview_calc(double iv[], char& file, int& i)
{
   double gross_income, single = 9750, married = 19500, taxable_income, refund, debt;

   // This is the calculation used for finding the adjusted gross income.
   gross_income = (iv[2] + iv[3] + iv[4]) * iv[i];

   cout << "\nAccording to calculations, your adjusted gross income will be: $" << gross_income << endl;
   if (file == 'S' || file == 's')
      cout << "\nSince you're filing single, you shall receive $9,750.\n";
   else if (file == 'J' || file == 'j')
      cout << "\nSince you're married filing jointly, you shall receive $19,500.\n";

   if (file == 'S' || file == 's')
   {
      taxable_income = gross_income - single;
      if (taxable_income >= 0)
         cout << "\nYour taxable income will be: $" << taxable_income << endl;
      else if (taxable_income < 0)
         cout << "\nYour taxable income will be: $0\n";
   }
   cout << "\nYour total payments and credits are: $" << iv[6] << endl;

   // The program will calculate tax based on the tax table in the 1040-EZ form.
   if (file == 'S' || file == 's' && taxable_income <= 8700)
      cout << "\nYour tax rate is going to be: 10%\n";
   else if (file == 'J' || file == 'j' && taxable_income <= 17400)
      cout << "\nYour tax rate is going to be: 10%\n";
   else if (file == 'S' || file == 's' && taxable_income >= 8701 && taxable_income <= 35350)
      cout << "\nYour tax rate is going to be: 15%\n";
   else if (file == 'J' || file == 'j' && taxable_income >= 17400 && taxable_income <= 70700)
      cout << "\nYour tax rate is going to be: 15%\n";
   else if (file == 'S' || file == 's' && taxable_income >= 35351 && taxable_income <= 85650)
      cout << "\nYour tax rate is going to be: 25%\n";
   else if (file == 'J' || file == 'j' && taxable_income >= 70701 && taxable_income <= 142700)
      cout << "\nYour tax rate is going to be: 25%\n";
   else if (file == 'S' || file == 's' && taxable_income >= 85651 && taxable_income <= 178650)
      cout << "\nYour tax rate is going to be: 28%\n";
   else if (file == 'J' || file == 'j' && taxable_income >= 142701 && taxable_income <= 217450)
      cout << "\nYour tax rate is going to be: 28%\n";
   else if (file == 'S' || file == 's' && taxable_income >= 178651 && taxable_income <= 388350)
      cout << "\nYour tax rate is going to be: 33%\n";
   else if (file == 'J' || file == 'j' && taxable_income >= 217451 && taxable_income <= 388350)
      cout << "\nYour tax rate is going to be: 33%\n";
   else if (file == 'S' || file == 's' && taxable_income >= 388351)
      cout << "\nYour tax rate is going to be: 35%\n";
   else if (file == 'J' || file == 'j' && taxable_income >= 388351)
      cout << "\nYour tax rate is going to be: 35%\n";

   if (iv[6] > taxable_income)
      {
         refund = iv[6] - taxable_income;
         cout << "\nThis is how much you'll be given back: $" << refund << endl;
      }
   else if (iv[6] < taxable_income)
      {
         debt = taxable_income - iv[6];
         cout << "\nThis is how much you owe: $" << debt << endl;
      }

   return;
}
