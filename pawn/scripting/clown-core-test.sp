#pragma newdecls required

#include <clown-core>

public void OnMapStart() {

    char data[] = "Hello";

    LogMessage("OnReceiveCode: %d", ClownCore.SendData("self.ping", data, sizeof(data)));
    LogMessage("OnDataReceived: %s", data);
}

public DataAction clown_OnDataSent(const char[] path, char[] data, int maxLen) {
    if(!strcmp("self.ping", path))
        FormatEx(data, maxLen, "%s", "Draw, brother!");

    return strcmp("self.ping", path) == 0 ? kReceive : kContinue;
}