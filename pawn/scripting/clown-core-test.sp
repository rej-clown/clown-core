#pragma newdecls required

#include <clown-core>

#define PING "core.ping"

public void OnMapStart() {

    ClownCore.SendSignal(PING, );

}

public DataAction clown_OnDataSent(const char[] path, char[] data, int maxLen) {
    if(!strcmp("self.ping", path))
        FormatEx(data, maxLen, "%s", "Draw, brother!");

    return strcmp("self.ping", path) == 0 ? kReceive : kContinue;
}