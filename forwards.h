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

DataAction SendData(const std::string &path, cell_t*);
void ReceivedData(const std::string &path, const cell_t*);

#endif //CCP_DEVC_FORWARDS_H
