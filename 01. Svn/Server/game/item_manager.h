// Ara:
		{
			return m_vecItems[GetOneIndex()];
		}

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
		DWORD GetItemSharePpm(size_t i) const
		{
			if (i >= m_vecProbs.size() || m_vecProbs.back() <= 0)
				return 0;
			const long long part = m_vecProbs[i] - (i ? m_vecProbs[i - 1] : 0);
			return (DWORD) (part * 1000000LL / m_vecProbs.back());
		}
#endif


// Ara:
		bool			CreateDropItemVector(LPCHARACTER pkChr, LPCHARACTER pkKiller, std::vector<std::pair<int,int> > & vec_item

// Altina ekle:
#ifdef ENABLE_TARGET_DROP_CHANCE
							, std::vector<DWORD>* pvec_chance = NULL
#endif

