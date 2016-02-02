#include "JSONString.h"
#include "codifier.h"

namespace simplejson
{
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

  void JSONString::addBool(std::string id, bool data)
  {
  	std::ostringstream os;

  	if(data)
  	{
  		os << "true" ;

  	}else
  	{
  		os << "false";
  	}

      _jsonstring += "\"";
      _jsonstring += id;
      _jsonstring += "\"";
      _jsonstring += ":";
      _jsonstring += os.str();
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

  void JSONString::addFloat(std::string id, float data)
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

  void JSONString::addStringSHA1(std::string id, std::string data)
  {
      std::string dataSHA1 = simplejson::Codifier::toSHA1(data);
      _jsonstring += "\"";
      _jsonstring += id;
      _jsonstring += "\"";
      _jsonstring += ":";
      _jsonstring += "\"";
      _jsonstring += dataSHA1;
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

  void JSONString::addArrayData(std::string data)
  {
      _jsonstring += data;
  }

  void JSONString::addObject(std::string id, std::string data)
  {
      _jsonstring += "\"";
      _jsonstring += id;
      _jsonstring += "\"";
      _jsonstring += ":";
      _jsonstring += data;
  }

  void JSONString::addObjectData(std::string data)
  {
      _jsonstring += data;
  }

  void JSONString::printString()
  {
      printf("%s", _jsonstring.c_str());
  }
} // namespace simplejson
