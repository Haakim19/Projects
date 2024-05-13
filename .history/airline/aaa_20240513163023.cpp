void ticket_booking_first(const string& flight_code1)
{
    ifstream in_file("pricing.txt");
    if (in_file.is_open())
    { 
        int a_price = 0;
        int k1_price = 0;
        int k2_price = 0;
        bool found = false;

        string current_flight_code; // Variable to store the flight code being read

        while(getline(in_file, line))
        {
            // Check if the line contains the flight code
            if (line.find("FLIGHT_CODE: ") != string::npos)
            {
                // Extract the flight code from the line
                current_flight_code = line.substr(line.find(":") + 2);
            }

            // Check if the current flight code matches the desired flight code
            if (current_flight_code == flight_code1)
            {
                // If the line contains the class and the flight code matches, set found to true
                if (line.find("FIRST CLASS") != string::npos)
                {
                    found = true;
                }

                // If the line contains the prices, extract them
                if (found && line.find("PRICE PER ADULT: ") != string::npos)
                {
                    string value = line.substr(line.find(":") + 2);
                    a_price = stoi(value);
                }
                else if (found && line.find("PRICE PER KID(2 TO 12 YEARS): ") != string::npos)
                {
                    string value = line.substr(line.find(":") + 2);
                    k1_price = stoi(value);
                }
                else if (found && line.find("PRICE PER KID(UNDER 2 YEARS): ") != string::npos)
                {
                    string value = line.substr(line.find(":") + 2);
                    k2_price = stoi(value);
                    break; // No need to continue reading lines after getting all prices
                }
            }
        }

        if (found)
        {
            cout << "First Class Prices:" << endl;
            cout << "Price per Adult: " << a_price << endl;
            cout << "Price per Kid (2 to 12 years): " << k1_price << endl;
            cout << "Price per Kid (under 2 years): " << k2_price << endl;
        }
        else
        {
            cout << "Flight details not found for code: " << flight_code1 << endl;
        }
        
        in_file.close();
    }
    else
    {
        cout << "Unable to open pricing.txt file" << endl;
    }
}