//--------------------------------------------------------------
// Purpose: To create a spreadsheet using two-dimensional arrays
// Author: Christopher Snead
//--------------------------------------------------------------

#include <cmath>
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

// Global constants
const int ROWS = 26;
const int COLS = 26;

// Get input from user
void GetInput(int & c1, int & r1, int & c2, int & r2)
{

   // Error checking
   bool valid = false;
   string col1, row1, col2, row2;
   while (!valid)
   {
      // Prompt user for inputs
      string col1, row1, col2, row2;
      cout << "Please enter col1 row1: ";
      cin >> col1 >> row1;
      cout << "Please enter col2 row2: ";
      cin >> col2 >> row2;

      // Convert A...Z to 0...25
      c1 = col1[0] - 'A';
      c2 = col2[0] - 'A';

      // Convert 1...26 to 0...25
      r1 = atoi(row1.c_str()) - 1;
      r2 = atoi(row2.c_str()) - 1;

      valid = true;
      if (c1 < 0 || c1 > 25 || c2 < 0 || c2 > 25 ||
          r1 < 0 || r1 > 25 || r2 < 0 || r2 > 25)
      valid = false;
   }
}

// Store specified data value
void specified_data(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   float value = 0;
   cout << "Enter value: " << endl;
   cin >> value;
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         data[r][c] = value;
      }
   }
}

// Store random data values
void random_data(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         data[r][c] = random() % 10;
      }
   }
}

// Calculate minimum of data values
void get_min(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   int min = data[0][0];
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         if (data[r][c] < min)
	 {
            min = data[r][c];
	 }
      }
   }
   cout << "Min = " << min << endl;
}

// Calculate maximum of data values
void get_max(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   int max = data[0][0];
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         if (data[r][c] > max)
         {
            max = data[r][c];
	 }
      }
   }
   cout << "Max = " << max << endl;
}

// Calculate sum of data values
void get_sum(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   float total = 0;
   int count = 0;
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         total = total + data[r][c];
         count++;
      }
   }
   cout << "Sum = " << total << endl;
}

// Calculate product of data values
void get_product(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   float total = 1;
   int count = 0;
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         total = total * data[r][c];
         count++;
      }
   }
   cout << "Product = " << total << endl;
}

// Calculate average of data values
void get_average(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   int count = 0;
   float total = 0;
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         total = total + data[r][c];
         count++;
      }
   }
   cout << "Average: " << total / count << endl;
}

// Calculate standard deviation of data values
void standard_deviation(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   float value = 0;
   int count = 0;
   float total = 0;
   float std_total = 0;
   float standard_deviation = 0;
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         total = total + data[r][c];
         count++;
      }
   }
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         std_total = std_total + (data[r][c] - total / count) * (data[r][c] - total / count);
      }
   }
   standard_deviation = sqrt(std_total / count);
   cout << "Standard Deviation: " << standard_deviation << endl;
}

// Print data values
void print_data(float data[ROWS][COLS])
{
   int c1;
   int r1;
   int c2;
   int r2;
   GetInput(c1, r1, c2, r2);
   for (int r = r1; r <= r2; r++)
   {
      for (int c = c1; c <= c2; c++)
      {
         cout << data[r][c] << " ";
      }
      cout << endl;
   }
}
//---------------------------------------------------
// Print command menu to user and get input
//---------------------------------------------------
int get_menu_choice()
{
   // Print command menu
   cout << "Welcome to MiniCalc\n"
        << "   1) Store specified data value\n"
        << "   2) Store random data values\n"
        << "   3) Calculate minimum of data values\n"
        << "   4) Calculate maximum of data values\n"
        << "   5) Calculate sum of data values\n"
        << "   6) Calculate product of data values\n"
        << "   7) Calculate average of data values\n"
        << "   8) Calculate standard deviation of data values\n"
        << "   9) Print data values\n"
        << "   0) Quit the program\n"
        << "Enter command: ";

   // Get user input
   int command;
   cin >> command;
   if (command >=0 && command <= 9)
      return command;
   else
      return get_menu_choice();
}

//---------------------------------------------------
// Main program
//---------------------------------------------------
int main()
{

   // Declare spreadsheet
   float data[ROWS][COLS];

   for (int r = 0; r < ROWS; r++)
   {
      for (int c = 0; c < COLS; c++)
      {
         data[r][c] = 0;
      }
   }

   // Loop processing menu commands
   int command = get_menu_choice();
   while (command != 0)
   {
      // Get command
      if (command == 1)
      {
         specified_data(data);
      }
      else if (command == 2)
      {
         random_data(data);
      }
      else if (command == 3)
      {
         get_min(data);
      }
      else if (command == 4)
      {
         get_max(data);
      }
      else if (command == 5)
      {
         get_sum(data);
      }
      else if (command == 6)
      {
         get_product(data);
      }
      else if (command == 7)
      {
         get_average(data);
      }
      else if (command == 8)
      {
         standard_deviation(data);
      }
      else if (command == 9)
      {
         print_data(data);
      }

      // Get next command
      command = get_menu_choice();
   }

return 0;
}
