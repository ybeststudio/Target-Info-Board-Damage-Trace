// int CalcMeleeDamage(LPCHARACTER pkAttacker, LPCHARACTER pkVictim, bool bIgnoreDefense, bool bIgnoreTargetRating) icinde:
// Ara:
	}
	iAtk = static_cast<int>(iAtk * fAR);
	iAtk += pkAttacker->GetLevel() * 2;

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
	if (DamageTrace::IsActive(pkAttacker, pkVictim))
	{
		const long long llAttack = pkAttacker->GetPoint(POINT_ATT_GRADE) + ((pkAttacker->IsPC() && pkVictim->IsPvM()) ? pkAttacker->GetPoint(POINT_ATTBONUS_PVM_STR) : 0);
		DamageTrace::Step(pkAttacker, pkVictim, "ATTACK", llAttack);
		DamageTrace::Step(pkAttacker, pkVictim, "WEAPON", llAttack + iDam);
		DamageTrace::Step(pkAttacker, pkVictim, "ACCURACY", iAtk);
	}
#endif


// int CalcMeleeDamage(LPCHARACTER pkAttacker, LPCHARACTER pkVictim, bool bIgnoreDefense, bool bIgnoreTargetRating) icinde:
// Bul:
	return CalcBattleDamage(iDam, pkAttacker->GetLevel(), pkVictim->GetLevel());

// Degistir:
#ifdef ENABLE_DAMAGE_TRACE
	{
		const int iBattleDam = CalcBattleDamage(iDam, pkAttacker->GetLevel(), pkVictim->GetLevel());
		DAMAGE_TRACE_STEP(pkAttacker, pkVictim, "MINIMUM", iBattleDam);
		return iBattleDam;
	}
#else
	return CalcBattleDamage(iDam, pkAttacker->GetLevel(), pkVictim->GetLevel());
#endif


// int CalcArrowDamage(LPCHARACTER pkAttacker, LPCHARACTER pkVictim, LPITEM pkBow, LPITEM pkArrow, bool bIgnoreDefense) icinde:
// Bul:
#define ARROW_TRACE_STEP(key, value) do { } while (0)

// Degistir:
#ifdef ENABLE_DAMAGE_TRACE
	const bool bDamageTrace = !bIgnoreDefense && DamageTrace::IsActive(pkAttacker, pkVictim);
	if (bDamageTrace)
	{
		const long long llAttack = pkAttacker->GetPoint(POINT_ATT_GRADE) + ((pkAttacker->IsPC() && pkVictim->IsPvM()) ? pkAttacker->GetPoint(POINT_ATTBONUS_PVM_STR) : 0);
		DamageTrace::Step(pkAttacker, pkVictim, "ATTACK", llAttack);
		DamageTrace::Step(pkAttacker, pkVictim, "WEAPON", llAttack + iDam);
		DamageTrace::Step(pkAttacker, pkVictim, "ACCURACY", iAtk);
	}
#define ARROW_TRACE_STEP(key, value) do { if (bDamageTrace) DamageTrace::Step(pkAttacker, pkVictim, (key), (long long) (value)); } while (0)
#else
#define ARROW_TRACE_STEP(key, value) do { } while (0)
#endif

