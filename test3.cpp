#include<iostream>
#include<fstream>
#include<string>

using namespace std;
string from;
string to;

void flights_today(const string& from , const string& to)
{
   
    ifstream file1("today_flights.txt",ios::in); //? open today_flights.txt file check 'from'
    
    if (file1.is_open())
    {
        string line1;
        bool found = false;
        while (getline(file1, line1))
        {
            if ((line1.find ("FROM: " + from) ) )
            
            {
                found = true;
                ifstream in_file1("today_flights.txt", ios::app); //? open today_filghts.txt file for check 'to'
                if (in_file1.is_open())
                {
                    string line11;
                    bool foundx = false;
                    while (getline(in_file1, line11))
                    {
                        if ((line11.find ("TO: " + to )))
                        {
                            foundx = true;
                            for (int i = 0 ; i < 3 ; i ++)
                                {
                                    getline(in_file1, line11);
                                    cout << line11 << endl;
                                }
                    
                        }
                    } 
                }
                in_file1.close();
                
                    

            }
        }
    }
    
    file1.close();


}

void flights_this_week (const string& from , const string& to)
{

    ifstream file2("this_week_flights.txt");//? open this_week_flights.txt file

    if (file2.is_open())
    {
        string line2;
        bool found = false;
        cout << "\n" ;
        while (getline (file2, line2))
        {
            if ((line2.find ("FROM: " + from)) && (line2.find ("TO: " + to) != string::npos))
            {
                found = true;
                for (int i = 0 ; i < 3 ; i ++ )
                {
                        
                    getline (file2, line2);
                    cout << line2 << endl;
                        
                }
            }
                
        }
    }

    file2.close();


}

int main()
{
   
    cout << "FROM: ";
    getline(cin, from);
    cout << "TO: ";
    getline(cin, to);
    cout << "\n" << endl;
    flights_today(from,to);
    
    return 0;
}