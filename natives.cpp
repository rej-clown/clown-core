#include "natives.h"

cell_t SendData(IPluginContext *pContext, const cell_t *params)
{
    char *path;
    pContext->LocalToString(params[1], &path);

    char* data;
    pContext->LocalToString(params[2], &data);

    return OnSendData(path, data, params[3]);
}

cell_t SendSignal(IPluginContext *pContext, const cell_t *params)
{
    char *path;
    pContext->LocalToString(params[1], &path);

    char* data;
    pContext->LocalToString(params[2], &data);

    return OnDataReceived(path, data);
}

const sp_nativeinfo_t natives[] = {
    { "ClownCore.SendData", SendData },
    { "ClownCore.SendSignal", SendSignal },
    { nullptr, nullptr }
};