#include<iostream>
#include<string>
#include<fstream>
using namespace std;


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
//? function to register customer details
void customer_registration(user_details user[7])
{
  cout << "PASSPORT NUMBER: ";
  cin >> user[0].passport_number;

  cout << "FULL NAME: " ;
  getline(cin, user[1].name);
  
  cout << "BIRTHDAY (DD/MM/YYYY): ";
  cin >> user[2].birthday;
  
  cout << "GENDER: ";
  cin >> user[3].gender;
   
  cout << "NATIONALITY: ";
  cin.ignore();
  getline(cin,user[4].nationality);
  
  cout << "PASSPORT ISSUE DATE (DD/MM/YYYY): ";
  cin >> user[5].issue_date;
  
  cout << "PASSPORT EXPIRE DATE (DD/MM/YYYY): ";
  cin >> user[6].expire_date;
    

//Open a File for Writing
  //open the file to save.
    ofstream out_file("customer_details.txt",ios :: app);
    if (out_file.is_open())
    {
        out_file << "NAME: " << user[1].name << endl;
        out_file << "BIRTHDAY: " << user[2].birthday << endl;
        out_file << "GENDER: " << user[3].gender << endl;
        out_file << "NATIONALITY: " << user[4].nationality << endl;
        out_file << "PASSPORT NUMBER: " << user[0].passport_number << endl;
        out_file << "ISSUE DATE: " << user[5].issue_date << endl;
        out_file << "EXPIRE DATE: " << user[6].expire_date << endl;
    
    out_file.close();///Closing the File 
    cout << "ALL THE DETAILS ARE SUCCESSFULLY SAVED TO 'customer_details.txt'." << endl;
    }

    else 
     {
         cout << "Unable to open file." << endl;
     }
}


int main()
{
   string details[7];
   customer_registration(details);
    return 0;
}