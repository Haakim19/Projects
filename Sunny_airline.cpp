#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string array[7];
char res;
struct user_details 
{
    string name;
    string birthday;
    string gender;
    string passport_number;
    string issue_date;
    string expire_date;
    string nationality;
};
struct flights_details
{
    string from;
    string to;
    string date;
    string time;
    string flight_code;
    int price;
    int total_seats;

};
//! THIS FUNCTION FOR SHOWING THE MAIN MENU TO USER 
void greeting(int& num)
{
    //this is the welcome menu that to choose what user wants
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

//! THIS FUNCTION FOR REGISTER CUSTOMER DETAILS
void customer_registration(user_details user[7])
{                            //this all are for input user details
  cin.ignore();
  cout << "FULL NAME: " ;
  getline(cin, user[1].name);
  
  cout << "BIRTHDAY (DD/MM/YYYY): ";
  cin >> user[2].birthday;
  
  cout << "GENDER: ";
  cin >> user[3].gender;
   
  cout << "NATIONALITY: ";
  cin.ignore();
  getline(cin,user[4].nationality);

  cout << "PASSPORT NUMBER: ";
  cin >> user[0].passport_number;
  
  cout << "PASSPORT ISSUE DATE (DD/MM/YYYY): ";
  cin >> user[5].issue_date;
  
  cout << "PASSPORT EXPIRE DATE (DD/MM/YYYY): ";
  cin >> user[6].expire_date;
    

//Open a File for Writing
  //open the file to save.
    ofstream out_file("customer_details.txt",ios :: app);//this is for save the details into the file name called customer_details.txt
    if (out_file.is_open())
    {
        out_file <<"PASSPORT NUMBER: " << user[0].passport_number << endl;
        out_file << "NAME: " << user[1].name << endl;
        out_file << "BIRTHDAY: " << user[2].birthday << endl;
        out_file << "GENDER: " << user[3].gender << endl;
        out_file << "NATIONALITY: " << user[4].nationality << endl;
        out_file << "PASSPORT ISSUE DATE: " << user[5].issue_date << endl;
        out_file << "PASSPORT EXPIRE DATE: " << user[6].expire_date << endl;
    
    out_file.close();///Closing the File 
    cout << "ALL THE DETAILS ARE SUCCESSFULLY SAVED TO THE DATA BASE." << endl;
    }

    else 
     {
         cout << "Unable to open file." << endl;
     }

}

void ticket_booking()

{
    cout << "hello";
}

//! THIS FUNCTION FOR TAKE ALL THE FLIGHT DETAILS AND SAVE IN TO A FILE 
void details_save(flights_details flights)// SAVE ALL THE FLIGHT DETAILS (NOT FOR USER)
{   
    
    
    cout << "TIME: ";
    cin >> flights.time;
   
    cin.ignore();
    cout << "FROM: ";
    getline(cin, flights.from);
    
    cout << "TO: ";
    getline (cin, flights.to);
    
    cout << "DATE: ";
    cin >> flights.date;

    cout << "PRICE PER TICKET: ";
    cin >> flights.price;
    
    cout << "TOTAL SEATS: ";
    cin >> flights.total_seats;

    cout << "FLIGHT CODE: ";
    cin >> flights.flight_code;

    

    ofstream out_file ("flight_details.txt" , ios:: app);
    if (out_file.is_open())
    {
        out_file << "FROM: " << flights.from << endl;
        out_file << "TO: " << flights.to << endl;
        out_file << "DATE: " << flights.date << endl;
        out_file << "TIME: " << flights.time << endl;
        out_file << "PRICE PER TICKET: " << flights.price << endl;
        out_file << "TOTAL SEATS: " << flights.total_seats << endl;
        out_file << "FLIGHT_CODE: " << flights.flight_code;
        out_file.close();
        cout << "Sucssefully addad" << endl;
    }
    else 
    {
        cout << "Unable to open file." << endl;
    }
}

//! THIS FUNCTION FOR FIND THE FLIGHT DETAILS THAT USER SEARCHING
void  flights_details_display(const string& from , const string& to)
{
    ifstream in_file("flight_details.txt" , ios::in); 
    if (in_file.is_open())
    {
        string line;
        bool found = false;
        while (getline(in_file, line))
        {
            if (line.find("FROM: " + from)  && line.find("TO: " + to)) 
            {
                found =true;
                cout << "FROM: " << from << endl; 
                cout << "TO: " << to << endl;
                for (int i = 0 ; i < 4 ; i++)
                {
                    getline(in_file, line);
                    cout << "\t" << line << endl;
                }
                cout << "\n" ;;
                
            }
        }
        if (!found)
        {
            cout << "Flight details not found! from: " << from << " to: " << to << "." << endl;
        }
        in_file.close();
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }
}

//! THIS FUNCTION FOR SHOWING USER DETAILS
void check_your_details(const string& passport_number)
{
    ifstream in_file("customer_details.txt");
    if (in_file.is_open())
    {
        string line;
        bool found = false;
        while (getline(in_file, line))
        {
            if (line.find("PASSPORT NUMBER: " + passport_number) != string::npos) 
            {
                found = true;
                cout << "\n" <<"User Details for Passport Number: " << passport_number << ".\n" << endl;
                for (int i = 0; i < 6; ++i) 
                {
                    getline(in_file, line); // Consume the next line
                    cout << "\t" <<line << endl;   // Output the line
                }
                cout <<"\n" ;
                break;
            }
        }
        if (!found) 
        {
            cout << "User details not found for Passport Number " << passport_number << "." << endl;
        }
        in_file.close();
    } 
    else 
    {
        cout << "Unable to open file." << endl;
    }
}

int check_your_bookings();

int main ()
{
  
  int Number;
  
  while (Number!=5)
  {
    
      greeting(Number);

    if (Number == 1)
    {
      user_details user[7];
      customer_registration(user);

    }
    
    else if (Number == 2)
    {   
        string passport_number;
        cin.ignore();
        cout << "Enter Passport Number: ";
        
        getline (cin, passport_number);
        check_your_details(passport_number);

    }
    
    else if (Number == 3)
    {
        string from;
        string to;
        cin.ignore();
        cout << "FROM WHARE YOU WANT TO BOOK YOUR TICKET: ";
        getline(cin, from);
        cout << "YOUR DESTINATION: ";
        getline(cin, to);
        flights_details_display(from , to);
        cout << "DO YOU WANT TO BOOK A TICKET (y/n): ";
        cin >> res;
        if (res == 'N' || 'n')
            {
                cout << "BACK TO MENU" << endl;
                greeting(Number);
            }
        else if (res == 'Y' || 'y')
            {
                ticket_booking();
            }
        
    }

    else if (Number == 11)
    {
       
        string pin;
        string in_pin = "haakim20030213";
        cout << "Enter the pin number: ";
        cin >> pin;
        if (pin == in_pin)
        {
           do
           {
            flights_details flights;
            details_save(flights);
            cout << "Do you want to add another detail(y/n)? ";
            cin >> res;
            if (res == 'N' || 'n')
            {
                break;
            }
           } while (res == 'Y' || 'y');
            
        }
        else 
        {
            cout << "Invalid entry!";
            greeting(Number);
        }
        
      
    }
  }
return 0;

}