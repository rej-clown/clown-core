#include "extension.h"

ClownCore clownCore;

SMEXT_LINK(&clownCore);

IForward *onDataSent;
IForward *onDataReceived;

bool ClownCore::SDK_OnLoad(char *error, size_t maxlength, bool late)
{
    if((onDataSent = forwards->CreateForward("clown_OnDataSent", ET_Hook, 2, nullptr, Param_String, Param_Cell)) == nullptr)
        smutils->LogError(myself, "Failed on create forward %s", "clown_OnDataSent");

    if((onDataReceived = forwards->CreateForward("clown_OnDataReceived", ET_Ignore, 2, nullptr, Param_String, Param_Cell)) == nullptr)
        smutils->LogError(myself, "Failed on create forward %s", "clown_OnDataReceived");

    sharesys->AddNatives(myself, natives);
    sharesys->RegisterLibrary(myself, "clown-core");

    return true;
}

void ClownCore::SDK_OnAllLoaded()
{
    // char *error;
    // size_t maxlength;

    SM_GET_LATE_IFACE(EXTENSIONMANAGER, m_pManager);
        // g_pSM->LogError(myself, "");
}

void ClownCore::OnMapStart()
{
    char path[256];
    g_pSM->BuildPath(Path_SM, path, 256, "configs/clowncore/settings.ini");

    SMCError err;
    SMCStates states;
    if((err = textparsers->ParseFile_SMC(path, this, &states)) != SMCError_Okay)
        m_pManager->UnloadExtension(myself);
}

SMCResult ClownCore::ReadSMC_KeyValue(const SMCStates *states, const char *key, const char *value) 
{
    if(!key || !value)
        return SMCResult_Continue;

    return SMCResult_Continue;
}

void ClownCore::SDK_OnUnload()
{
    forwards->ReleaseForward(onDataSent);
    forwards->ReleaseForward(onDataReceived);
}