/*
 * Parser to manager JSONObjects
 */

#include "JSONParser.h"

//#include "logger.h"
#define LOG_TAG "JSONParser"

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <cstring>
#include <algorithm>
#include <fstream>

namespace simplejson
{
  bool parseIntoJSONObject(std::string &jsondata, JSONObject &result)
  {
      // JSON message
  		JSONValue *value = JSON::Parse(jsondata.c_str());

      if(!result.empty())
      {
        //LOGW("JSONObject provided is not empty");
      }

  		// Did it go wrong?
  		if (value == NULL)
  		{
  				//LOGW("jsondata is not a valid JSON");
          return false;
  		}
  		else
  		{
  			// Retrieve the main object
  			if (value->IsObject() == false)
  			{
  				//LOGW("No value into JSON");
  				return false;
  			}
  			else
  			{
  				result = value->AsObject();
  			}
  		}
      // free memory
  		delete value;
  }
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

  void JSONParser::readFile(const std::string &absoluteFileName, std::string &completeFile)
	{
		//LOGD("Opening file: %s", absoluteFileName.c_str());

		// Read whole file
		std::ifstream file;
		long begin, end, size;
		file.open(absoluteFileName.c_str(), std::ios::binary);
		file.seekg(0, std::ios::beg);

		if(!file.is_open())
		{
			//LOGE("Cannot open file");
			return;
		}
		completeFile.assign(    (std::istreambuf_iterator<char>(file) ),
				(std::istreambuf_iterator<char>()    ) );

		file.seekg(0, std::ios::beg);
		begin = file.tellg();
		file.seekg(0, std::ios::end);
		end = file.tellg();
		size = end - begin;
		//LOGD("Processing: %ld bytes", size);
		file.close();
	}
  void JSONParser::createFile(const std::string &absoluteFileName, std::string &completeFile)
	{
		//LOGD("Creating file: %s", absoluteFileName.c_str());

		std::ofstream os(absoluteFileName.c_str());
		if (!os)
		{
			//LOGE("Cannot create file: %s", absoluteFileName.c_str());
		}
		else
		{
			os << completeFile;
		}
	}
} // namespace simplejson
