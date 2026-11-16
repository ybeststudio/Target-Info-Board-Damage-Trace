// Ara:
ACMD(do_teleport_map);

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
ACMD(do_damage_trace);
#endif


// Ara:
	{ "teleport_map", do_teleport_map, 0, POS_DEAD, GM_PLAYER },

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
	{ "damage_trace", do_damage_trace, 0, POS_DEAD, GM_PLAYER },
#endif

