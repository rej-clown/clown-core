#include "natives.h"

static cell_t sendData(IPluginContext *pContext, const cell_t *params)
{
    char *path;
    pContext->LocalToString(params[1], &path);

    char *data;
    pContext->LocalToString(params[2], &data);

    FORWARD_RESULT result =
        SendData(path, data);

    if(result.what < kReject_Immediately)
        ReceivedData(path, result.data);

    pContext->StringToLocalUTF8(params[2], params[3], result.data.c_str(), &result.size);
    return result.what;
}

const sp_nativeinfo_t natives[] = {
    "ClownCore.SendData", sendData
};