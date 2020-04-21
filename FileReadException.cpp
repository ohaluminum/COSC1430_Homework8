#include "FileReadException.h"

FileReadException::FileReadException()
{
	err_message = "";
}

FileReadException::FileReadException(string message)
{
	err_message = message;
}

string FileReadException::getMessage()
{
	return err_message;
}


