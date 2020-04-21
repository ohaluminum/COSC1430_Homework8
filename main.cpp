#include <iostream>
#include <string>
#include <fstream>

#include "TreasureMap.h"
#include "FileReadException.h"
#include "Location.h"

using namespace std;

//overload operator << of Location class, no changes needed
ostream& operator<<(ostream& os, Location& pt) {
	return os << pt.getName();
}

//overload operator >> of Location class, no changes needed
istream& operator >> (istream& os, Location& pt) {
	string name;
	float x,y;
	os >> name >> x >> y;
	pt.setName(name);
	pt.setX(x);
	pt.setY(y);
	
	return os;
}


//FIX ME: Implement readmap function that reads from a file and return a proper TreasureMap object


int main()
{
    string file_name, file_type;
    int max_steps;
    cin >> file_name >> file_type >> max_steps;
    
    
    try{
        if (file_type == "string"){
            TreasureMap<string> Tmap = readMap<string>(file_name, max_steps);
            for (int i = 0; i < Tmap.getTotalSteps()-1; i ++){
                Tmap.nextStep();
            }
        } else if (file_type == "int"){
            //FIX ME: Create a TreasureMap of type int, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
        } else if (file_type == "char"){
            //FIX ME: Create a TreasureMap of type char, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
        } else if (file_type == "location"){
            //FIX ME: Create a TreasureMap of type Location, call readMap to read the file_name and file_type
            //Then use a for loop to call the map.nextStep()
        }
    }catch(/*FIX ME: define exception type here*/){
        //FIX ME: prints out the exception message using getMessage() here
    }
    return 0;
}
