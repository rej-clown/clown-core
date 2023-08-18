#include "extension.h"
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

cell_t ClownGetMyKey(IPluginContext *pContext, const cell_t *params)
{
    char *buffer;
    pContext->LocalToString(params[1], &buffer);

    auto& size = (size_t&)params[2];

    static const char* TOKEN = "api.key";

    json_t* obj;
    if(!(obj = json_object_get(ClownCore::pConfig, TOKEN)))
        return 0;

    const char* str = nullptr;
    if(json_is_string(obj) && (str = json_string_value(obj)) != nullptr)
        ke::SafeStrcpyN(buffer, size, str, strlen(str) + 1);

    bool done;
    if((done = str != nullptr))
        free((void*) str);

    json_decref(obj);

    return done;
}

const sp_nativeinfo_t natives[] = {
    { "ClownCore.SendData", SendData },
    { "ClownCore.SendSignal", SendSignal },
    { "ClownCore.GetMyToken", ClownGetMyKey  },
    { nullptr, nullptr }
};