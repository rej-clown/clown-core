#include <src/CClownCore.h>

#include "natives.h"
#include "extension.h"

ClownCore g_ClownCoreExt;

SMEXT_LINK(&g_ClownCoreExt);

nClownCore::CClownCore g_ClownCore;

IForward *onSendData;
IForward *onDataReceived;

bool ClownCore::SDK_OnLoad(char *error, size_t maxlength, bool late)
{
    if((onSendData = forwards->CreateForward(
            "clown_OnDataSent", ET_Hook, 3, nullptr, Param_String, Param_String, Param_Cell
    )) == nullptr)
        smutils->LogError(myself, "Failed on create forward %s", "clown_OnDataSent");

    if((onDataReceived = forwards->CreateForward(
            "clown_OnDataReceived", ET_Ignore, 2, nullptr, Param_String, Param_String
    )) == nullptr)
        smutils->LogError(myself, "Failed on create forward %s", "clown_OnDataReceived");

    sharesys->AddNatives(myself, natives);
    sharesys->RegisterLibrary(myself, "clown-core");

    return sharesys->AddInterface(myself, &g_ClownCore);
}

void ClownCore::SDK_OnAllLoaded()
{
//    pass
}


void ClownCore::SDK_OnUnload()
{
    forwards->ReleaseForward(onSendData);
    forwards->ReleaseForward(onDataReceived);
}

void ClownCore::OnCoreMapStart(edict_t *pEdictList, int edictCount, int clientMax) {

    char path[PLATFORM_MAX_PATH];
    g_pSM->BuildPath(Path_SM, path, PLATFORM_MAX_PATH, SMEXT_CONF_CONFIG);

    json_t* object;
    json_error_t error = {};
    if((object = json_load_file(path, 0, &error)) == nullptr)
        smutils->LogError(myself, "Error on json config load (%d; %s): %s [l: %d; c: %d; p: %d]",
                          json_error_code(&error),
                          error.source,
                          error.text,
                          error.line,
                          error.column,
                          error.position);


    if(object == nullptr)
        return;

    if(m_pConfig != nullptr)
    {
        json_decref(m_pConfig);
        m_pConfig = nullptr;
    }

    m_pConfig = object;

    IExtensionInterface::OnCoreMapStart(pEdictList, edictCount, clientMax);
}
