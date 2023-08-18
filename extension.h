#ifndef _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_

#include <jansson.h>

#include "smsdk_ext.h"

/**
 * @brief Sample implementation of the SDK Extension.
 * Note: Uncomment one of the pre-defined virtual functions in order to use it.
 */
class ClownCore : public SDKExtension
{
public:
	/**
	 * @brief This is called after the initial loading sequence has been processed.
	 *
	 * @param error		Error message buffer.
	 * @param maxlen	Size of error message buffer.
	 * @param late		Whether or not the module was loaded after map load.
	 * @return			True to succeed loading, false to fail.
	 */
	bool SDK_OnLoad(char *error, size_t maxlen, bool late) override;
	
	/**
	 * @brief This is called right before the extension is unloaded.
	 */
	void SDK_OnUnload() override;

	/**
	 * @brief This is called once all known extensions have been loaded.
	 * Note: It is is a good idea to add natives here, if any are provided.
	 */
	void SDK_OnAllLoaded() override;

    void OnCoreMapStart(edict_t *pEdictList, int edictCount, int clientMax) override;

    json_t* Config() const;

//	void OnCore

private:
	json_t* m_pConfig;
};

extern ClownCore g_ClownCoreExt;

#endif // _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
