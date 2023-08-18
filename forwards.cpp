#include <am-string.h>

#include "forwards.h"

DataAction OnSendData(const char* path, char* data, const size_t& maxLen)
{
    DataAction action {};

    char* buffer = (char*) malloc((maxLen + 1) * sizeof(char));
    ke::SafeStrcpyN(buffer, maxLen, data, strlen(data) + 1);

    onSendData->PushString(path);
    onSendData->PushStringEx(
            buffer, maxLen, SM_PARAM_STRING_UTF8 | SM_PARAM_STRING_COPY, SM_PARAM_COPYBACK
    );
    onSendData->PushCell((cell_t)maxLen);
    onSendData->Execute((cell_t *)&action);

    if(action < kReject_Immediately)
    {
        if(action == kReceive)
            ke::SafeStrcpyN(data, maxLen, buffer, strlen(buffer) + 1);

        OnDataReceived(path, data);
    }

    free(buffer);

    return action;
}

DataAction OnDataReceived(const char* path, const char* data)
{
    DataAction action = kContinue;

    onDataReceived->PushString(path);
    onDataReceived->PushString(data);
    onDataReceived->Execute((cell_t*)&action);

    return action;
}

