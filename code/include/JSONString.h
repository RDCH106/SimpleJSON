#pragma once

#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <stdio.h>

namespace simplejson
{
  /**
  * \brief Class to create a string with JSON format easy
  *
  */
  class JSONString
  {
  public:
    JSONString():_jsonstring(""){};
    JSONString(std::string initial):_jsonstring(initial){};

    /**
    * \brief Use this method to start a JSONObject as string manually. Add { to internal string
    */
    void startJSONObject();
    /**
    * \brief Use this method to separate a JSONObject as string manually. Add , to internal string
    */
    void continueJSONObject();
    /**
    * \brief Use this method to finish a JSONObject as string manually. Add } to internal string
    */
    void endJSONObject();

    /**
    * \brief Use this method to start a JSONArray as string manually. Add [ to internal string
    */
    void startJSONArray();
    /**
    * \brief Use this method to separate a JSONObject as string manually. Add , to internal string
    */
    void continueJSONArray();
    /**
    * \brief Use this method to finish a JSONObject as string manually. Add ] to internal string
    */
    void endJSONArray();

    /**
    * \brief Add a boolean value with id. Call between startJSON/continueJSON/endJSON
    */
    void addBool(std::string id, bool data);
    /**
    * \brief Add a int value with id. Call between startJSON/continueJSON/endJSON
    */
    void addInt(std::string id, int data);
    /**
    * \brief Add a unsigned int value with id. Call between startJSON/continueJSON/endJSON
    */
    void addUnsignedInt(std::string id, unsigned int data);
    /**
    * \brief Add a float value with id. Call between startJSON/continueJSON/endJSON
    */
    void addFloat(std::string id, float data);
    /**
    * \brief Add a string value with id. Call between startJSON/continueJSON/endJSON
    */
    void addString(std::string id, std::string data);
    /**
    * \brief Add a string value after codify as SHA1 with id. Call between startJSON/continueJSON/endJSON
    */
    void addStringSHA1(std::string id, std::string data);
    /**
    * \brief Add a JSONArray value with id. Call between startJSON/continueJSON/endJSON
    */
    void addJSONArray(std::string id, std::string data);
    /**
    * \brief Add a raw JSONArray value without id. Call between startJSON/continueJSON/endJSON
    */
    void addJSONArrayData(std::string data);
    /**
    * \brief Add a JSONObject value with id. Call between startJSON/continueJSON/endJSON
    */
    void addJSONObject(std::string id, std::string data);
    /**
    * \brief Add a raw JSONObject value without id. Call between startJSON/continueJSON/endJSON
    */
    void addJSONObjectData(std::string data);

    std::string getString() { return _jsonstring; };
    const char* getChar() { return _jsonstring.c_str(); };

    void printString();

  private:
    std::string _jsonstring;
  };
} // namespace simplejson
