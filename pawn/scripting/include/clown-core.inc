#if defined _clown_core_included_
    #endinput
#endif
#define _clown_core_included_

enum DataAction
{
    kContinue = 0,
    kReceive,
    kReject,
    kReject_Immedently
};

forward DataAction clown_OnDataSent(const char[] path, char[] data, int maxLen);

forward void clown_OnDataReceived(const char[] path, const char[] data);

methodmap ClownCore
{
    // @desc 
    // 
    // @param path      Some virtual path
    // @param data      Json data
    // 
    // @return          kContinue - data with out changes
    //                  kReceive  - data with changes (obv in json format)
    //                  kReject   - call rejected (with out data change)
    //                  kReject_Immendently - call rejected (with out data change and post call)
    public static native DataAction SendData(const char[] path, char[] data, int maxLen);

    // ...
    public static native void SendSignal(const char[] path, const char[] data = NULL_STRING);
};

/**
 * Do not edit below this line!
 */
public Extension __ext_clown_core =
{
    name = "Clown Core",
    file = "clown-core.ext",
#if defined AUTOLOAD_EXTENSIONS
    autoload = 1,
#else
    autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
    required = 1,
#else
    required = 0,
#endif
};