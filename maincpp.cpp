#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define String std::string


//----------------------------------------------------------------------------------Helper functions-----------------------------------------------------------------------

bool ParseandCheck(String Text, String UserDestination) {
	size_t bracketLocation = Text.find("]");

	String Destination = Text.substr(bracketLocation+2, Text.length() - bracketLocation);
	if (UserDestination == Destination)
		return true;
	return false;
}






int CheckFile(String Location, std::vector<String> &Tickets) {
	String Text;

	//open file and read from it 
	std::fstream FileName("Airline Database.txt");
	if (FileName.is_open()) {
		while (getline(FileName, Text)) {
			//find the destination and check if it matches
			if (ParseandCheck(Text, Location)) {
				Tickets.push_back(Text);
			}
		}
	}
	FileName.close();

	
	return 0;
}

int main() {
	std::cout << "Hello World\n";

	//1. Make the airline fights - Departure location and arrival location, as well as airline name, stored in the .txt file
	//2. Ask the user to enter what time their flight should leave at
	//3. Check to see if there are any availiable flights at that time

	std::vector<String> Tickets;

	String userLocation;


	std::cout << "Enter the location that you want to go to: \n";
	std::cin >> userLocation;

	CheckFile(userLocation, Tickets);

	for (String E : Tickets)
		std::cout << E << std::endl;


	//consider building your own database like sql or something


	/*
- get date of flight
- make else condition 
- Try taking the data out of an excel file or csv file. 
- make a departure date and arrival date for round trips
- Within country, departure and return should be the same
- Number of adults and children: calculate the fare based off of that
- calculate discounts on flights if applicable
- Include something with travel and baggage
	*/
}