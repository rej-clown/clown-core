#ifndef CCP_DEVC_NATIVES_H
#define CCP_DEVC_NATIVES_H

#include <sp_vm_types.h>

#include "forwards.h"

extern cell_t SendData(SourcePawn::IPluginContext *pContext, const cell_t *params);

extern const sp_nativeinfo_t natives[];

#endif //CCP_DEVC_NATIVES_H
