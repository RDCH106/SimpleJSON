#include "JSONString.h"
#include "codifier.h"

namespace simplejson
{
  void JSONString::startJSONObject()
  {
      _jsonstring += "{";
  }

  void JSONString::continueJSONObject()
  {
      _jsonstring += ",";
  }

  void JSONString::endJSONObject()
  {
      _jsonstring += "}";
  }

  void JSONString::startJSONArray()
  {
      _jsonstring += "[";
  }

  void JSONString::continueJSONArray()
  {
      _jsonstring += ",";
  }

  void JSONString::endJSONArray()
  {
      _jsonstring += "]";
  }

  void JSONString::addBool(std::string id, bool data)
  {
  	std::ostringstream os;

  	if(data)
  	{
  		os << "true" ;

  	}
    else
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

  void JSONString::addJSONArray(std::string id, std::string data)
  {
      _jsonstring += "\"";
      _jsonstring += id;
      _jsonstring += "\"";
      _jsonstring += ":";
      _jsonstring += data;
  }

  void JSONString::addJSONArrayData(std::string data)
  {
      _jsonstring += data;
  }

  void JSONString::addJSONObject(std::string id, std::string data)
  {
      _jsonstring += "\"";
      _jsonstring += id;
      _jsonstring += "\"";
      _jsonstring += ":";
      _jsonstring += data;
  }

  void JSONString::addJSONObjectData(std::string data)
  {
      _jsonstring += data;
  }

  void JSONString::printString()
  {
      printf("%s", _jsonstring.c_str());
  }
} // namespace simplejson
