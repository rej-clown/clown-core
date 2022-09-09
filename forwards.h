#ifndef CCP_DEVC_FORWARDS_H
#define CCP_DEVC_FORWARDS_H

#include <string>
#include "extension.h"

// template<class T>
struct FORWARD_RESULT
{
    DataAction what;
    size_t size;
    // T data;
    std::string data;
};

FORWARD_RESULT SendData(const std::string &path, const std::string &data);
void ReceivedData(const std::string &path, const std::string &data);

#endif //CCP_DEVC_FORWARDS_H
