#if defined _clown_core_included_
    #endinput
#endif
#define _clown_core_included_

enum DataAction
{
    kContinue = 0,
    kReceive,
    kReject,
    kRejectImmedently
};

forward DataAction clown_OnDataSent(const char[] path, char[] data, int maxLen);

// Final data send state
forward DataAction clown_OnDataReceived(const char[] path, const char[] data);

methodmap ClownCore
{
    // @desc Sending data to the environment (clown_OnDataReceived after call result 'll ignore)
    // 
    // @param path      Some virtual path
    // @param data      Some data buffer
    // @param maxLen    Some data buffer max length
    // 
    // @return          kContinue - data with out changes
    //                  kReceive  - data with changes
    //                  kReject   - call rejected (with out data change)
    //                  kRejectImmendently - call rejected (with out data change and clown_OnDataReceived call)
    public static native DataAction SendData(const char[] path, char[] data, int maxLen);

    // @desc Sending signal to the environment (clown_OnDataReceived call)
    //
    // @param path      Some virtual path
    // @param data      Some data
    //
    // @return          custom things
    public static native DataAction SendSignal(const char[] path, const char[] data = NULL_STRING);

    // @return Self API key
    public static native bool GetMyToken(char[] buffer, int maxLen);
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