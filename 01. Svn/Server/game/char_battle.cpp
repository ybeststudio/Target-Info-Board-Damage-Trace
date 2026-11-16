// bool CHARACTER::Attack(LPCHARACTER pkVictim, BYTE bType) icinde:
// Ara:
		// Ama saldýrý sýrasýnda rezervasyon kontrolü yapmýyoruz, damage iþlemesi için
		CHARACTER_MANAGER::instance().ReserveTarget(dwTargetVID, dwPlayerPID);
	}

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
	DamageTrace::FHitScope damageTraceScope(this, pkVictim, bType);
#endif


// bool CHARACTER::Damage(LPCHARACTER pAttacker, int dam, EDamageType type) icinde:
// Ara:
		dam = dam * iDmgPct / 100;
	}
	DAMAGE_TRACE_STEP(pAttacker, this, "SERVER_RATE", dam);

// Altina ekle:
#ifdef ENABLE_METIN_DAMAGE_CAP
	if (IsStone() && pAttacker && GetMaxHP() > 0)
		dam = MIN(dam, MAX(1, GetMaxHP() / 10));
	DAMAGE_TRACE_STEP(pAttacker, this, "METIN_CAP", dam);
#endif


// bool CHARACTER::Damage(LPCHARACTER pAttacker, int dam, EDamageType type) icinde:
// Ara:
	}
	DAMAGE_TRACE_STEP(pAttacker, this, "RULES", dam);

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
	if (DamageTrace::IsActive(pAttacker, this))
		DamageTrace::Final(pAttacker, this, dam, cannot_dead ? 0 : MIN(dam, MAX(0, GetHP())));
#endif


// Ara:
					return;
			}
			LPITEM pkBow, pkArrow;

// Altina ekle:
#ifdef ENABLE_DAMAGE_TRACE
			DamageTrace::FHitScope damageTraceScope(m_me, pkVictim, m_bType == 0 ? (BYTE) DamageTrace::HIT_ARROW : m_bType);
#endif

