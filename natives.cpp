#include "natives.h"

cell_t SendData(IPluginContext *pContext, const cell_t *params)
{
    char *path;
    pContext->LocalToString(params[1], &path);

    char* data;
    pContext->LocalToString(params[2], &data);

    return OnSendData(path, data, params[3]);
}

const sp_nativeinfo_t natives[] = {
    { "ClownCore.SendData", SendData },
    { nullptr, nullptr }
};