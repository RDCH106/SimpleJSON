#pragma once

#include "JSON.h"
#include "JSONValue.h"

namespace simplejson
{
	typedef std::vector<JSONValue*> JSONArray;
	typedef std::map<std::wstring, JSONValue*> JSONObject;
	typedef std::pair<std::string, std::string> StringPair;
	typedef std::vector<StringPair > StringPairArray;

/**
* \brief Auxiliary class to manage JSONObject/JSONArray/JSONString automatically 
*/
	class JSONParser
	{
	public:
		/**
		* \brief Process a string json objets sintaxis to get a JSONObject
		*
		* \param[in] json in a string
		* \param[in|out] a empty JSONObject
		* \return TRUE if Success
		*/
		static bool parseIntoJSONObject(std::string &jsondata, JSONObject &result);
		/**
		* \brief Process a string json objets sintaxis to get a JSONObject
		*
		* \param[in] json in a string
		* \param[in|out] a empty JSONObject
		* \return TRUE if Success
		*/
		static bool parseIntoJSONArray(std::string &jsondata, JSONArray &result);
		/**
		* \brief Extract JSONArray from JSONObject if is posible
		*
		* \param[in] json
		* \param[in] id
		* \return TRUE if Success
		*/
		static bool extractJSONArray(JSONObject &json, std::wstring &id, JSONArray &result, bool recursive = false);
		/**
		* \brief Extract JSONObject from JSONObject if is posible
		*
		* \param[in] json
		* \param[in] id
		* \return TRUE if Success
		*/
		static bool extractJSONObject(JSONObject &json, std::wstring &id, JSONObject &result, bool recursive = false);
		/**
		* \brief Extract bool from JSONObject if is a bool
		*
		* \param[in] json
		* \param[in] id
		* \return TRUE if Success
		*/
		static bool extractBool(JSONObject &json, std::wstring &id, bool &result, bool recursive = false);
		/**
		* \brief Extract string from JSONObject if is a string
		*
		* \param[in] json
		* \param[in] id
		* \return TRUE if Success
		*/
		static bool extractString(JSONObject &json, std::wstring &id, std::string &result, bool recursive = false);
		/**
		* \brief Extract a vector with strings from JSONObject if is a string
		*
		* \param[in] json
		* \param[in] id
		* \return TRUE if Success
		*/
		static bool extractStringPairs(JSONObject &json, StringPairArray &result, bool recursive = false);
		/**
		* \brief Extract int from JSONObject if is a int
		*
		* \param[in] json
		* \param[in] id
		* \return TRUE if Success
		*/
		static bool extractInt(JSONObject &json, std::wstring &id, int &result, bool recursive = false);

		static bool existID(JSONObject &json, std::wstring &id, bool recursive = false);

		// File management
		static void readFile(const std::string &absoluteFileName, std::string &completeFile);
		static void createFile(const std::string &absoluteFileName, std::string &completeFile);

	private:
		static bool _verbose;
	};
}	// namespace simplejson
