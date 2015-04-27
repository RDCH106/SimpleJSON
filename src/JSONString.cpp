#include "JSONString.h"

void JSONString::startJSON()
{
    _jsonstring += "{";
}

void JSONString::finishJSON()
{
    _jsonstring += "}";
}

void JSONString::continueJSON()
{
    _jsonstring += ",";
}

void JSONString::startArray()
{
    _jsonstring += "[";
}

void JSONString::finishArray()
{
    _jsonstring += "]";
}

void JSONString::addInt(std::string id, int data)
{
	std::ostringstream os;
	os << data ;

    _jsonstring += "\"";
    _jsonstring += id;
    _jsonstring += "\"";
    _jsonstring += ":";
    _jsonstring += os.str();
}

void JSONString::addUnsignedInt(std::string id, unsigned int data)
{
	std::ostringstream os;
	os << data ;

    _jsonstring += "\"";
    _jsonstring += id;
    _jsonstring += "\"";
    _jsonstring += ":";
    _jsonstring += os.str();
}

void JSONString::addString(std::string id, std::string data)
{
    _jsonstring += "\"";
    _jsonstring += id;
    _jsonstring += "\"";
    _jsonstring += ":";
    _jsonstring += "\"";
    _jsonstring += data;
    _jsonstring += "\"";
}

void JSONString::addArray(std::string id, std::string data)
{
    _jsonstring += "\"";
    _jsonstring += id;
    _jsonstring += "\"";
    _jsonstring += ":";
    _jsonstring += data;
}

void JSONString::printString()
{
    printf("%s", _jsonstring.c_str());
}
