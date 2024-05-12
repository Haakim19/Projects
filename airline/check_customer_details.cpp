#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void check_your_details(const string& passport_number)
{
    ifstream in_file("customer_details.txt");
    if (in_file.is_open())
    {
        string line ;
        bool fount = false;
        while (getline (in_file , line))
        {
            if (line.find("Passport Number: " + passport_number) != string::npos)
                fount = true;
                cout << "User Details for Passport Number " << passport_number << ":" << endl;
                for (int i=0 ; i < 7 ; i++)
                {
                    getline (in_file , line);
                    cout << line << endl;
                }
        }
    }
   
    
    
   
    
}

int main ()
{
   char choice;
   string passport_number;
   cout << "Enter Passport Number: ";
   getline (cin, passport_number);
   check_your_details(passport_number);
   cout << "Do you want to see your details Y (yes) N (no): ";
   
   
    return 0;
}