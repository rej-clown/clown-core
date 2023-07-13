#ifndef CLOWN_CORE_CCLOWNCORE_H
#define CLOWN_CORE_CCLOWNCORE_H

#include <public/IClownCore.h>

namespace nClownCore {

    class CClownCore : public IClownCore {
    public:
        CClownCore();
        virtual ~CClownCore();
    };

} // nClownCore

extern nClownCore::CClownCore g_ClownCore;

#endif //CLOWN_CORE_CCLOWNCORE_H
