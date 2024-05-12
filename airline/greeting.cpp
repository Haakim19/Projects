#include<iostream>
#include<string>
using namespace std;

string array[7];
void greeting(int& num)
{
    
    cout << "\t\t" << "    **********WELCOME**********    " << endl;
    cout << "\t\t" << "  -----THOUSAND SUNNY AIRLINE-----  " << endl;
    cout << "\t" << "PRESS 1 : Customer Registration. " << endl ;
    cout << "\t" << "PRESS 2 : Your Details. " << endl ;
    cout << "\t" << "PRESS 3 : Ticket Booking. " << endl ;
    cout << "\t" << "PRESS 4 : Check Your Bookings. " << endl ;
    cout << "\t" << "PRESS 5 : EXIT. " << endl ;
    cout << "Select a Number(1 to 5): ";
    cin >> num;

}


int main ()
{
  
   greeting(Number);
    return 0;
}