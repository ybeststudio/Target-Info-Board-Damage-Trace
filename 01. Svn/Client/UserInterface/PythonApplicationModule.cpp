// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_DROP_DIALOG_RENEWAL", 0);

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
	PyModule_AddIntConstant(poModule, "ENABLE_DAMAGE_TRACE", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_DAMAGE_TRACE", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_DAMAGE_TRACE", 0);

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
	PyModule_AddIntConstant(poModule, "ENABLE_TARGET_DROP_CHANCE", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_TARGET_DROP_CHANCE", 0);
#endif

