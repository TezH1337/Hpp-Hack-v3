#pragma once

#include "Windows.h"

#include "ValveSDK/wrect.h"
#include "ValveSDK/cl_dll.h"
#include "ValveSDK/r_studioint.h"
#include "ValveSDK/cl_entity.h"
#include "ValveSDK/triangleapi.h"
#include "ValveSDK/pmtrace.h"
#include "ValveSDK/pm_defs.h"
#include "ValveSDK/pm_info.h"
#include "ValveSDK/cvardef.h"
#include "ValveSDK/util_vector.h"
#include "ValveSDK/studio.h"
#include "ValveSDK/event_args.h"
#include "ValveSDK/event_flags.h"
#include "ValveSDK/keydefs.h"
#include "ValveSDK/ref_params.h"
#include "ValveSDK/studio_event.h"
#include "ValveSDK/net_api.h"
#include "ValveSDK/r_efx.h"
#include "ValveSDK/event_api.h"
#include "ValveSDK/screenfade.h"
#include "ValveSDK/engine_launcher_api.h"
#include "ValveSDK/entity_types.h"
#include "ValveSDK/com_model.h"
#include "ValveSDK/parsemsg.h"

#include "Defines.h"
#include "Main_Structures.h"
#include "Offsets.h"
#include "Utils.h"
#include "Client.h"

extern cl_clientfunc_t *g_pClient;
extern cl_enginefunc_t *g_pEngine;
extern engine_studio_api_t *g_pStudio;

extern cl_clientfunc_t g_Client;
extern cl_enginefunc_t g_Engine;
extern engine_studio_api_t g_Studio;