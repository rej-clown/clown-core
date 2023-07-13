#ifndef CLOWN_CORE_ICLOWNCORE_H
#define CLOWN_CORE_ICLOWNCORE_H

#include <ISourceMod.h>

#define SMINTERFACE_CLOWNCORE_NAME        "IClownCore"

// 8 bits on major
// 12 bits on minor (guaranteed backward compatibility)
// 12 bits on bugs (guaranteed backward compatibility)
#define SMINTERFACE_CLOWNCORE_VERSION	   ((0 << 24) & (1 << 12) & 0)

namespace nClownCore
{
    class IClownCore : public SourceMod::SMInterface {
    public:
        unsigned int GetInterfaceVersion() override {
            return SMINTERFACE_CLOWNCORE_VERSION;
        }

        const char *GetInterfaceName() override {
            return SMINTERFACE_CLOWNCORE_NAME;
        }

        bool IsVersionCompatible(unsigned int version) override {
            return (((GetInterfaceVersion() >> 24) & (version >> 24)) == 1);
        }
    };
};

#endif //CLOWN_CORE_ICLOWNCORE_H
