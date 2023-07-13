#ifndef CCP_DEVC_FORWARDS_H
#define CCP_DEVC_FORWARDS_H

#include <IForwardSys.h>

enum DataAction
{
    kContinue = 0,
    kReceive,
    kReject,
    kReject_Immediately
};

extern DataAction OnSendData(const char* path, char* data, const size_t& maxLen);
extern void OnDataReceived(const char* path, const char* data);

extern SourceMod::IForward *onSendData;
extern SourceMod::IForward *onDataReceived;

#endif //CCP_DEVC_FORWARDS_H
