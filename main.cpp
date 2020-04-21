#include <iostream>
#include <string>
#include <fstream>

#include "TreasureMap.h"
#include "FileReadException.h"
#include "Location.h"

using namespace std;

//Overload operator << of Location class, no changes needed
ostream& operator<<(ostream& os, Location& pt) {
	return os << pt.getName();
}

//Overload operator >> of Location class, no changes needed
istream& operator>>(istream& os, Location& pt) {
	string name;
	float x,y;
	os >> name >> x >> y;
	pt.setName(name);
	pt.setX(x);
	pt.setY(y);
	
	return os;
}


//FIX ME: Implement readmap function that reads from a file and return a proper TreasureMap object
/*
 *Function readMap():
 *This is a template function that takes in two arguments, a string file_name and an int for max_steps. 
 *It returns a TreasureMap of type T.
 *
 *This function first opens the file with the file_name and if it doesn't exists, throws a FileReadException exception with this message:
 *Error reading map: <file_name> does not exists!

 *The function will create a new TreasureMap of type T, then for each item in the input file, 
 *use the extraction operator (>>) to read in a new element of type T and add it into the map with addStep() member function of the TreasureMap class.
 *
 *However, if there are more items in the input file than the provided max_steps (2nd argument of readMap), then throw a FileReadException with this message:
 *Error reading map: <file_name> contains more than <max_steps> steps!
 *
 *After reading (without issues), the function returns that TreasureMap object.
 */
template<typename T>
TreasureMap<T> readMap(string file_name, int max_steps)
{
    ifstream inFS;

    inFS.open(file_name);
    if (!inFS.is_open())
    {
        string error = "Error reading map: ";
        error += file_name;
        error += " does not exisits!";

        throw FileReadException(error);
    }

    TreasureMap<T> newMap(max_steps);
    T step;
    int num_step = 0;

    while (!inFS.eof())
    {
        inFS >> step;
        num_step++;

        if (num_step > max_steps)
        {
            string error = "Error reading map: ";
            error += file_name;
            error += " contains more than ";
            error += to_string(max_steps);
            error += " steps!";
   
            throw FileReadException(error);
        }

        newMap.addStep(step);
    }

    return newMap;
}


int main()
{
    string file_name, file_type;
    int max_steps;
    cin >> file_name >> file_type >> max_steps;
    
    
    try
    {
        if (file_type == "string")
        {
            TreasureMap<string> Tmap = readMap<string>(file_name, max_steps);

            for (int i = 0; i < Tmap.getTotalSteps() - 1; i ++)
            {
                Tmap.nextStep();
            }
        } 
        else if (file_type == "int")
        {
            TreasureMap<int> Tmap = readMap<int>(file_name, max_steps);

            for (int i = 0; i < Tmap.getTotalSteps() - 1; i++) 
            {
                Tmap.nextStep();
            }
        } 
        else if (file_type == "char")
        {
            TreasureMap<char> Tmap = readMap<char>(file_name, max_steps);

            for (int i = 0; i < Tmap.getTotalSteps() - 1; i++)
            {
                Tmap.nextStep();
            }
        } 
        else if (file_type == "location")
        {
            TreasureMap<Location> Tmap = readMap<Location>(file_name, max_steps);

            for (int i = 0; i < Tmap.getTotalSteps() - 1; i++)
            {
                Tmap.nextStep();
            }
        }
    }
    catch (FileReadException e)
    {
        cout << e.getMessage() << endl;
    }

    return 0;
}