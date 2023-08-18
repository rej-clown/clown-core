#pragma newdecls required

#include <clown-core>

#define PING "core.ping"

public void OnMapStart() {

    ClownCore.SendSignal(PING, GetMyTokenEx());

}

stock char[] GetMyTokenEx()
{
    char buffer[512];

    if(!ClownCore.GetMyToken(buffer, sizeof(buffer)))
        buffer[0] = 0;

    return buffer;
}