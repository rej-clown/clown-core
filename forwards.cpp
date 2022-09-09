#include "forwards.h"

FORWARD_RESULT SendData(const std::string &path, const std::string &data)
{
    const char *buffer = data.c_str();

    FORWARD_RESULT result {
        kContinue, data.length(), data
    };

    onDataSent->PushString(path.c_str());
    onDataSent->PushString(buffer);
    onDataSent->Execute((cell_t *)&result.what);

    if(buffer != nullptr && result.what == kReceive)
        result = { kReceive, strlen(buffer), buffer };

    return result;
}

void ReceivedData(const std::string &path, const std::string &data)
{
    onDataReceived->PushString(path.c_str());
    onDataReceived->PushString(data.c_str());
    onDataReceived->Execute(nullptr);
}

