/*********************************************************************
 * File Name : damage_trace.h
 * Author    : BestStudio
 * Version   : 1.0.0
 * Date      : 10-11-2026  
 */

#pragma once

#ifdef ENABLE_DAMAGE_TRACE
namespace DamageTrace
{
	// "/damage_trace <vid> <request>": watch a target (vid 0 stops)
	void Request(LPCHARACTER ch, const char* argument);
	void Forget(LPCHARACTER ch);

	// one CHARACTER::Attack call; at most one recorded hit per second
	void BeginHit(LPCHARACTER attacker, LPCHARACTER victim, BYTE bType);
	void EndHit(LPCHARACTER attacker);

	bool IsActive(const CHARACTER* attacker, const CHARACTER* victim);
	void Step(const CHARACTER* attacker, const CHARACTER* victim, const char* key, long long value);
	void Final(const CHARACTER* attacker, const CHARACTER* victim, int displayed, int hpLoss);

	enum { HIT_ARROW = 255 };

	struct FHitScope
	{
		LPCHARACTER m_ch;
		FHitScope(LPCHARACTER attacker, LPCHARACTER victim, BYTE bType) : m_ch(attacker) { BeginHit(attacker, victim, bType); }
		~FHitScope() { EndHit(m_ch); }
	};
}

#define DAMAGE_TRACE_STEP(attacker, victim, key, value) \
	do { if (DamageTrace::IsActive((attacker), (victim))) DamageTrace::Step((attacker), (victim), (key), (long long) (value)); } while (0)
#else
#define DAMAGE_TRACE_STEP(attacker, victim, key, value) do { } while (0)
#endif
