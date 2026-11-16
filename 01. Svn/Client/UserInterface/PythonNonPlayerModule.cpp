// Ara:
	CPythonNonPlayer& rkNonPlayer = CPythonNonPlayer::Instance();
	return Py_BuildValue("i", rkNonPlayer.GetMonsterMaxHP(race));
}

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
PyObject *nonplayerGetMonsterTargetInfo(PyObject *poSelf, PyObject *poArgs)
{
	int race;
	if (!PyTuple_GetInteger(poArgs, 0, &race))
		return Py_BuildException();

	const CPythonNonPlayer::TMobTable * pTable = CPythonNonPlayer::Instance().GetTable(race);
	if (!pTable)
		return Py_BuildValue("(iiiiiiiii)", 0, 0, 0, 0, 0, 0, 0, 0, 0);

	return Py_BuildValue("(iiiiiiiii)", pTable->wDef, pTable->bRegenCycle, pTable->bRegenPercent,
		pTable->cEnchants[CPythonNonPlayer::MOB_ENCHANT_CRITICAL], pTable->cEnchants[CPythonNonPlayer::MOB_ENCHANT_PENETRATE],
		pTable->dwMaxHP, pTable->bLevel, pTable->bType == 2 ? 1 : 0, pTable->dwRaceFlag);
}
#endif


// void initNonPlayer() icinde:
// Ara:
		{ "IsMonsterStone",				nonplayerIsMonsterStone,			METH_VARARGS },
		{ "GetMonsterResist",			nonplayerGetMonsterResist,			METH_VARARGS },
		{ "GetMonsterMaxHP",			nonplayerGetMonsterMaxHP,			METH_VARARGS },

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
		{ "GetMonsterTargetInfo",		nonplayerGetMonsterTargetInfo,		METH_VARARGS },
#endif

