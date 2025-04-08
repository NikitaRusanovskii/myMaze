#include "MyExceptions.h"

using namespace std;

Exception::Exception(string message) : message(message) {}
string Exception::getInfo() {
	return message;
}