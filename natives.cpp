#include "natives.h"

static cell_t sendData(IPluginContext *pContext, const cell_t *params)
{
    char *path;
    pContext->LocalToString(params[1], &path);

    DataAction result;

    if((result = SendData(path, &params[2])) < kReject_Immediately)
        ReceivedData(path, &params[2]);


    return result;
}

const sp_nativeinfo_t natives[] = {
    { "ClownCore.SendData", sendData }
};