#include<iostream>
#include<string>
#include<fstream>
using namespace std;

string array[7];
char res;

string line;
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
    int adult , adult1 , adult2;
    int kids1 , kids11 , kids12;
    int kids2 , kids21 , kids22;
    int total_seats;

};
//! THIS FUNCTION FOR SHOWING THE MAIN MENU TO USER (more improve)
void greeting(int& num)
{
    //this is the welcome menu that to choose what user wants
    cout << "\t\t*************************************************" << endl;
    cout << "\t\t\t" << "    **********WELCOME**********    " << endl;
    cout << "\t\t\t" << "  -----THOUSAND SUNNY AIRLINE-----  " << endl;
    cout << "\t\t _______________________________________________ " << endl;
    cout << "\t\t|-----------------------------------------------| " << endl;
    cout << "\t\t|   " << "      1 | Customer Registration.      " <<"      |"<< endl ;
    cout << "\t\t|   " << "      2 | Your Details.               " <<"      |"<<endl ;
    cout << "\t\t|   " << "      3 | Ticket Booking.             " <<"      |"<<endl ;
    cout << "\t\t|   " << "      4 | Check Your Bookings.        " <<"      |"<< endl ;
    cout << "\t\t|   " << "      5 | EXIT.                       " <<"      |"<< endl ;
    cout << "\t\t|_______________________________________________|" << endl;
    cout << "\t\t*************************************************" << endl;
    cout << "Select the service you want (1 to 5): ";
    cin >> num;

}

//! THIS FUNCTION FOR REGISTER CUSTOMER DETAILS (ok)
void customer_registration(user_details user[7])
{                            //this all are for input user details
  cin.ignore();
  cout << "\t***********************************" << endl;
  cout << "1. FULL NAME: " ;
  getline(cin, user[1].name);
  
  cout << "2. BIRTHDAY (DD/MM/YYYY): ";
  cin >> user[2].birthday;
  
  cout << "3. GENDER: ";
  cin >> user[3].gender;
   
  cout << "4. NATIONALITY: ";
  cin.ignore();
  getline(cin,user[4].nationality);

  cout << "5. PASSPORT NUMBER: ";
  cin >> user[0].passport_number;
  
  cout << "6. PASSPORT ISSUE DATE (DD/MM/YYYY): ";
  cin >> user[5].issue_date;
  
  cout << "7. PASSPORT EXPIRE DATE (DD/MM/YYYY): ";
  cin >> user[6].expire_date;

  cout << "\t----ALL YOUR DETAILS ARE SAVED-----" << endl;
  cout << "\t***********************************" << endl;
    

//Open a File for Writing
  //open the file to save.
    ofstream out_file("customer_details.txt",ios :: app);//this is for save the details into the file name called customer_details.txt
    if (out_file.is_open())
    {
        out_file << "PASSPORT NUMBER: " << user[0].passport_number << endl;
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
//! THIS FUNCTION FOR CALCULATE FINAL BILL 
void final_bill (int& a_price , int& k1_price , int& k2_price) // called this function inside the ticket_booking function 
{
    int number_of_adults, number_of_kid1 , number_of_kid2 , t_a , t_k1 , t_k2; // t_a = total adult price , t_k1 = total kids1 price , t_k2 = total kids2 price
    cout << "NUMBER OF ADULTS: ";// passengers amount adults
    cin >> number_of_adults;
    cout << "NUMBER OF KIDS (2 TO 12 YEARS): ";//passengers amount kids 2 to 12 years
    cin >> number_of_kid1;
    cout << "NUMBER OF KIDS(UNDER 2 YEARS): ";//passengers amount kids under 2 years
    cin >> number_of_kid2;
    t_a = number_of_adults * a_price;
    t_k1 = number_of_kid1 * k1_price;
    t_k2 = number_of_kid2 * k2_price;
    cout << t_a << endl;
    cout << t_k1 << endl;
    cout << t_k2 << endl;

    
}
//! THIS FUNCTION IS FOR EXTRACT THE PRICES OF TICKET THAT USER SELECTED FLIGHT (ok , need to add class)
void ticket_booking(const string&  flight_code1)

{
    ifstream in_file("pricing.txt", ios :: in);
    if (in_file.is_open())
    { 
        
        int adults = 0 ;
        int a_price = 0 ;
        int kids1 = 0 ;
        int k1_price = 0 ;
        int kids2 = 0 ;
        int k2_price = 0; //? a_price = adult ticket price , kids1 = kids 2 to 12 , k1_price = kids1 ticket price  
        bool found = false;                                         //? kids2 = kids under 2 years , k2_price =  kids2 ticket price
        bool found_price1 = false;
        bool found_price2 = false;
        bool found_price3 = false;
       

        while(getline (in_file, line) )
        {
           if (line.find("FLIGHT_CODE: " + flight_code1) != string ::npos)
           {
            found = true;
           }
           if (found){
            if (line.find("PRICE PER ADUULT: ") !=string :: npos )//extracting the values of price per adult
            {
               found_price1 = true;
               string value1 = line.substr(line.find(":") + 2);
               a_price = stoi (value1);
               
            }
             else if (line.find("PRICE PER KID(2 TO 12 YEARS): ") !=string :: npos )//extracting the values of price of kids from 2 to 12 years
            {
               found_price2 = true;
               string value2 = line.substr(line.find(":") + 2);
               k1_price = stoi (value2);
            }
             else if (line.find("PRICE PER KID(UNDER 2 YEARS): ") !=string :: npos )//extracting the values of price of kids under 2 years
            {
               found_price3 = true;
               string value3 = line.substr(line.find(":") + 2);
               k2_price = stoi (value3);
               
            }
           }
           
        }
        // Handle cases where some prices are not found
        if (!found) 
        {
            cout << "Flight details not found for code: " << flight_code1 << endl;
        } 
        else if (a_price == 0) 
        {
            cout << "Adults price information for flight code: " << flight_code1 << endl;
            // price for Adults are missing 
        }  
        else if (k1_price == 0 )
        {
             cout << "Kids (2 to 12 years) price information for flight code: " << flight_code1 << endl;
             //price for Kids (2 to 12 years) are missing
        }
        else if (k2_price == 0)
        {
             cout << "Kids (under 2 years) price information for flight code: " << flight_code1 << endl;
             //price for Kids (under 2 years) are missing
        }
            
       final_bill(a_price , k1_price , k2_price);// sending the values to final_bill function
       
        
    }
    else 
    {
        cout << "Unable to open pricing.txt file" << endl;
    }
}

//(how to replace values in file by user input)
//! THIS FUNCTION FOR TAKE ALL THE FLIGHT DETAILS AND SAVE IN TO A FILE (3 classes added to save to file)
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
    
    cout << "----------FIRST CLASS----------" << endl;
    cout << "PRICE FOR ADULT: ";
    cin >> flights.adult;
    
    cout << "PRICE FOR KID(2 TO 12 YEARS): ";
    cin >> flights.kids1;

    cout << "PRICE FOR KID(UNDER 2 YEARS): ";
    cin >> flights.kids2;
     

    cout << "----------BUSINESS CLASS-----------" << endl;
    cout << "PRICE FOR ADULT: ";
    cin >> flights.adult1;
    
    cout << "PRICE FOR KID(2 TO 12 YEARS): ";
    cin >> flights.kids11;

    cout << "PRICE FOR KID(UNDER 2 YEARS): ";
    cin >> flights.kids21;
     

    cout << "----------ECONOMY CLASS----------" << endl;
    cout << "PRICE FOR ADULT: ";
    cin >> flights.adult2;
    
    cout << "PRICE FOR KID(2 TO 12 YEARS): ";
    cin >> flights.kids12;

    cout << "PRICE FOR KID(UNDER 2 YEARS): ";
    cin >> flights.kids22;

    
    cout << "TOTAL SEATS: ";
    cin >> flights.total_seats;

    cout << "FLIGHT CODE: ";
    cin >> flights.flight_code;

    

    ofstream out_file ("flight_details.txt" , ios:: app);
    if (out_file.is_open())
    {
        
        out_file <<  "FROM: " << flights.from << endl;
        out_file << "TO: " << flights.to << endl;
        out_file << "DATE: " << flights.date << endl;
        out_file << "TIME: " << flights.time << endl;
        out_file << "----------FIRST CLASS----------" << endl;
        out_file << "PRICE PER ADUULT: " << flights.adult << endl;
        out_file << "PRICE PER KID(2 TO 12 YEARS): " << flights.kids1 << endl;
        out_file << "PRICE PER KID(UNDER 2 YEARS): " << flights.kids2 << endl;
        out_file << "*********************************************************" << endl;
        out_file << "----------BUSINESS CLASS----------" << endl;
        out_file << "PRICE PER ADUULT: " << flights.adult1 << endl;
        out_file << "PRICE PER KID(2 TO 12 YEARS): " << flights.kids11 << endl;
        out_file << "PRICE PER KID(UNDER 2 YEARS): " << flights.kids21 << endl;
        out_file << "*********************************************************" << endl;
        out_file << "----------ECONOMY CLASS----------" << endl;
        out_file << "PRICE PER ADUULT: " << flights.adult2 << endl;
        out_file << "PRICE PER KID(2 TO 12 YEARS): " << flights.kids12 << endl;
        out_file << "PRICE PER KID(UNDER 2 YEARS): " << flights.kids22 << endl;
        out_file << "*********************************************************" << endl;
        out_file << "TOTAL SEATS: " << flights.total_seats << endl;
        out_file << "FLIGHT_CODE: " << flights.flight_code << endl;
        out_file.close();
        cout << "Sucssefully addad to 'flight_details.txt'." << endl;
    }
    else 
    {
        cout << "Unable to open 'flight_details.txt' file." << endl;
    }
    ofstream out_file1 ("pricing.txt" , ios :: app);
    if (out_file1.is_open())
    {
        
        out_file1 << "FLIGHT_CODE: " << flights.flight_code << endl;
        out_file << "*********************************************************" << endl;
        out_file << "----------FIRST CLASS----------" << endl;
        out_file << "PRICE PER ADUULT: " << flights.adult << endl;
        out_file << "PRICE PER KID(2 TO 12 YEARS): " << flights.kids1 << endl;
        out_file << "PRICE PER KID(UNDER 2 YEARS): " << flights.kids2 << endl;
        out_file << "*********************************************************" << endl;
        out_file << "----------BUSINESS CLASS----------" << endl;
        out_file << "PRICE PER ADUULT: " << flights.adult1 << endl;
        out_file << "PRICE PER KID(2 TO 12 YEARS): " << flights.kids11 << endl;
        out_file << "PRICE PER KID(UNDER 2 YEARS): " << flights.kids21 << endl;
        out_file << "*********************************************************" << endl;
        out_file << "----------ECONOMY CLASS----------" << endl;
        out_file << "PRICE PER ADUULT: " << flights.adult2 << endl;
        out_file << "PRICE PER KID(2 TO 12 YEARS): " << flights.kids12 << endl;
        out_file << "PRICE PER KID(UNDER 2 YEARS): " << flights.kids22 << endl;
        out_file << "*********************************************************" << endl;
        out_file1 << "TOTAL SEATS: " << flights.total_seats << endl;
        out_file1.close();
        cout << "sucssefully added to 'pricing.txt'." << endl;
    }
    else 
    {
        cout << "Unable to open 'pricing.txt' file." << endl;
    }
}

//! THIS FUNCTION FOR FIND THE FLIGHT DETAILS THAT USER SEARCHING
void  flights_details_display(const string& from , const string& to)
{
    ifstream in_file("flight_details.txt" , ios::in); 
    if (in_file.is_open())
    {
        
        bool found = false;
        while (getline(in_file, line))
        {
            if (line.find("FROM: " + from)  && line.find("TO: " + to)) 
            {
                found =true;
                cout << "****************************************************" << endl;
                cout << "\t"<< "FROM: " << from << endl; 
                cout << "\t" << "TO: " << to << endl;
                for (int i = 0 ; i < 19 ; i++)
                {
                    getline(in_file, line);
                    cout << "\t" << line << endl;
                }
                cout << "****************************************************" << endl;
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

//! THIS FUNCTION FOR SHOWING USER DETAILS (ok)
void check_your_details(const string& passport_number)
{
    ifstream in_file("customer_details.txt");
    if (in_file.is_open())
    {
       
        bool found = false;
        while (getline(in_file, line))
        {
            if (line.find("PASSPORT NUMBER: " + passport_number) != string::npos) 
            {
                found = true;
                cout << "\t\t|***********************************************|" << endl;
                cout << "\n\t|  " <<"User Details for Passport Number: " << passport_number << "  |\n" << endl;
                for (int i = 0; i < 6; ++i) 
                {
                    getline(in_file, line); // Consume the next line
                    cout << "\t\t|   " <<line <<"   |" << endl;   // Output the line
                }
                cout << "\t\t|***********************************************|" << endl;
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
        cin.ignore(); //clear input buffer
        cout << "STARTING POINT: ";
        getline(cin, from);
        cout << "ENDING POINT: ";
        getline(cin, to);
        flights_details_display(from , to);
        cout << "DO YOU WANT TO BOOK A TICKET (y/n): ";
        cin >> res;
        cin.ignore();// clear input buffer
        if (res == 'N' || res == 'n')
            {
                cout << "BACK TO MENU" << endl;
                greeting(Number);
            }
        else if (res == 'Y' || res == 'y')
            {
                string flight_code1;
                cout << "Pleas enter the flight code that you want to book:";
                cin >> flight_code1;
                ticket_booking(flight_code1);
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