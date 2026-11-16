// Ara:
{
	TeleportMap_Command(ch, argument);
}

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
#include "damage_trace.h"
ACMD(do_damage_trace)
{
	DamageTrace::Request(ch, argument);
}
#endif

