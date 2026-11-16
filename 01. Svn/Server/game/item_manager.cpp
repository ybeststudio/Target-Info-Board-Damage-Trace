// bool ITEM_MANAGER::CreateDropItemVector(LPCHARACTER pkChr, LPCHARACTER pkKiller, std::vector<std::pair<int,int> > & vec_item, ...) icinde:
// Ara:
bool ITEM_MANAGER::CreateDropItemVector(LPCHARACTER pkChr, LPCHARACTER pkKiller, std::vector<std::pair<int,int> > & vec_item

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
	, std::vector<DWORD>* pvec_chance
#endif


// bool ITEM_MANAGER::CreateDropItemVector(LPCHARACTER pkChr, LPCHARACTER pkKiller, std::vector<std::pair<int,int> > & vec_item, ...) icinde:
// Bul:
#define DROP_CHANCE_PUSH(value) do { } while (0)

// Degistir:
#ifdef ENABLE_TARGET_DROP_CHANCE
	int iChanceDelta = 100, iChanceRange = 4000000;
	if (!GetDropPct(pkChr, pkKiller, iChanceDelta, iChanceRange))
	{
		iChanceDelta = 100;
		iChanceRange = 4000000;
	}
	struct FChance
	{
		static DWORD Ppm(long long llPercent, long long llRange)
		{
			if (llRange <= 0 || llPercent <= 0)
				return 0;
			const long long v = llPercent * 1000000LL / llRange;
			return (DWORD) MIN(v, 1000000LL);
		}
	};
#define DROP_CHANCE_PUSH(value) do { if (pvec_chance) pvec_chance->push_back(value); } while (0)
#else
#define DROP_CHANCE_PUSH(value) do { } while (0)
#endif


// bool ITEM_MANAGER::CreateDropItemVector(LPCHARACTER pkChr, LPCHARACTER pkKiller, std::vector<std::pair<int,int> > & vec_item, ...) icinde:
// Ara:
			if (pGroup && !pGroup->IsEmpty())
			{
				auto vec_items = pGroup->GetVector();

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
				const DWORD dwGroupPpm = pGroup->GetKillPerDrop() > 0 ? FChance::Ppm(40000LL * iChanceDelta / pGroup->GetKillPerDrop(), iChanceRange) : 0;
				size_t uiIndex = 0;
#endif

