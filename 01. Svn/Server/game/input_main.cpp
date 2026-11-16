// void CInputMain::TargetInfoLoad(LPCHARACTER ch, const char* c_pData) icinde:
// Ara:
    // Bot karakterleri tamamen hariç tut
    if (ch->IsBotCharacter() || m_pkChrTarget->IsBotCharacter())
        return;

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
	static std::vector<DWORD> s_vec_chance;
	s_vec_chance.clear();
#endif


// void CInputMain::TargetInfoLoad(LPCHARACTER ch, const char* c_pData) icinde:
// Ara:
	if ((m_pkChrTarget->IsMonster() || m_pkChrTarget->IsStone()) && ITEM_MANAGER::instance().CreateDropItemVector(m_pkChrTarget, ch, s_vec_item

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
		, &s_vec_chance
#endif


// void CInputMain::TargetInfoLoad(LPCHARACTER ch, const char* c_pData) icinde:
// Ara:
			pInfo.race = m_pkChrTarget->GetRaceNum();
			pInfo.dwVnum = iter->first;
			pInfo.count = iter->second;

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
			{
				const size_t uiIndex = iter - s_vec_item.begin();
				pInfo.dwChance = uiIndex < s_vec_chance.size() ? s_vec_chance[uiIndex] : 0;
			}
#endif

