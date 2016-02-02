/*
 * Parser to manager JSONObjects
 */

#include "JSONParser.h"

//#include "logger.h"
#define LOG_TAG "JSONParser"

namespace simplejson
{
    bool JSONParser::extractJSONArray(JSONObject &json, std::wstring &id, JSONArray &result, bool recursive)
    {
      if(recursive)
      {
        //LOGE("Recursive not supported yet");
        return false;
      }
      if (json[id]->IsArray())
  		{
  			result = json[id]->AsArray();
  			return true;
  		}
  		return false;
    }
		bool JSONParser::extractJSONObject(JSONObject &json, std::wstring &id, JSONObject &result, bool recursive)
    {
      if(recursive)
      {
        //LOGE("Recursive not supported yet");
        return false;
      }
      if (json.find(id) != json.end() && json[id]->IsObject())
  		{
  			result = json[id]->AsObject();
  			return true;
  		}
  		return false;
    }
		bool JSONParser::extractBool(JSONObject &json, std::wstring &id, bool &result, bool recursive)
    {
      if(recursive)
      {
        //LOGE("Recursive not supported yet");
        return false;
      }
      if (json.find(id) != json.end() && json[id]->IsBool())
  		{
  			result = json[id]->AsBool();
  			return true;
  		}
  		return false;
    }
		bool JSONParser::extractString(JSONObject &json, std::wstring &id, std::string &result, bool recursive)
    {
      if(recursive)
      {
        //LOGE("Recursive not supported yet");
        return false;
      }
      if (json.find(id) != json.end() && json[id]->IsString())
  		{
  			std::wstring wresult = json[id]->AsString();
  			result.assign(wresult.begin(), wresult.end());
  			return true;
  		}
  		return false;
    }
		bool JSONParser::extractInt(JSONObject &json, std::wstring &id, int &result, bool recursive)
    {
      if(recursive)
      {
        //LOGE("Recursive not supported yet");
        return false;
      }
      if (json.find(id) != json.end() && json[id]->IsNumber())
  		{
  			result = (int)json[id]->AsNumber();
  			return true;
  		}
  		return false;
    }
} // namespace simplejson
