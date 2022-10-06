#include "forwards.h"

DataAction SendData(const std::string &path, cell_t* data)
{
    DataAction action;

    onDataSent->PushString(path.c_str());
    onDataSent->PushCellByRef(buffer, );
    onDataSent->Execute((cell_t *)&action);

    if(action < kReject_Immediately)
        ReceivedData(path, (const cell_t *) data);

    return action;
}

void ReceivedData(const std::string &path, const cell_t *data)
{
    onDataReceived->PushString(path.c_str());
    onDataReceived->PushCell(*data);
    onDataReceived->Execute(nullptr);
}

