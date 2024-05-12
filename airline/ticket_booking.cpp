#include<iostream>
#include<string>
using namespace std;

class ticket_booking
{

public:
    ticket_booking(/* args */);
    ~ticket_booking();
};

ticket_booking::ticket_booking(/* args */)
{
}

ticket_booking::~ticket_booking()
{
}

int ticket_booking()
{
    string flight[2];
    int passengers = 0;
    cout << "\t\t" << "**********BOOK YOUR TICKETS HEAR***********" << endl;
    cout << "\t" << "FROM: ";
    getline(cin, flight[0]);
    cout << "\t" << "TO: ";
    getline(cin, flight[1]);
    cout << "\t" << "PASSENGERS: ";
    cin >> passengers;

    
    





























}



int main ()
{
 ticket_booking();



    return 0;
}