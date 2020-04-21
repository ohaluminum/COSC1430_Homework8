#include <iostream>

using namespace std;

class FileReadException
{
private:
	string err_message;

public:
	FileReadException();
	FileReadException(string message);
	string getMessage();
};

