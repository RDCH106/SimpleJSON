#pragma once

#include "JSON.h"
#include "JSONValue.h"

namespace simplejson
{
	typedef std::vector<JSONValue*> JSONArray;
	typedef std::map<std::wstring, JSONValue*> JSONObject;

	class JSONParser
	{
	public:
		/**
		* \brief Process jsondata to get a JSONObject with info
		*
		* \param[in] json in a string
		* \param[in|out] a empty JSONObject
		* \return TRUE if Success
		*/
		static bool parseIntoJSONObject(std::string &jsondata, JSONObject &result);
		/**
		* \brief Extract JSONArray from JSONObject if is posible
		*
		* \param[in] json
		* \param[in] id to look for
		* \return TRUE if Success
		*/
		static bool extractJSONArray(JSONObject &json, std::wstring &id, JSONArray &result, bool recursive = false);
		static bool extractJSONObject(JSONObject &json, std::wstring &id, JSONObject &result, bool recursive = false);
		static bool extractBool(JSONObject &json, std::wstring &id, bool &result, bool recursive = false);
		static bool extractString(JSONObject &json, std::wstring &id, std::string &result, bool recursive = false);
		static bool extractInt(JSONObject &json, std::wstring &id, int &result, bool recursive = false);

		// File management
		static void readFile(const std::string &absoluteFileName, std::string &completeFile);
		static void createFile(const std::string &absoluteFileName, std::string &completeFile);

	private:
		static bool _verbose;
	};
}	// namespace simplejson
