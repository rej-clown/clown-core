#if defined _clown_core_stocks_included_
    #endinput
#endif
#define _clown_core_stocks_included_


#if defined CLOWN_USE_JANSSON
stock int FindStringValue_json(const JsonArray& array, const char[] value, const int maxValueSize = 512)
{
    if(!array)
        return -1;

    char[] buffer = new char[maxValueSize];

    for(int i, size = array.Length; i < size; i++)
        if(array.GetString(i, buffer, maxValueSize) && !strcmp(value, buffer))
            return i;

    return -1;
}

stock int FindIntValue_json(const JsonArray& array, const int value)
{
    if(!array)
        return -1;

    for(int i, size = array.Length; i < size; i++)
        if(array.Get(i) == value)
            return i;

    return -1;
}

stock JsonArray GetArrayFromJsonObject(const Json& json, const char[] key)
{
    if(!json 
    || json.Type != JSON_OBJECT 
    || !asJSONO(json).HasKey(key) 
    || asJSONO(json).GetType(key) != JSON_ARRAY)
        return null;

    return asJSONA(asJSONO(json).Get(key));
}

stock JsonArray GetArrayFromJsonArray(const Json& json, const int position)
{
    if(position < 0 
    || !json 
    || json.Type != JSON_ARRAY 
    || asJSONA(json).Length <= position 
    || asJSONA(json).GetType(i) != JSON_ARRAY)
        return null;

    return asJSONA(asJSONA(json).Get(position));
}

#endif