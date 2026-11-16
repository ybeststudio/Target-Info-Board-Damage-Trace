# GameWindow icinde ara:
			import uiTeleportMap
			uiTeleportMap.ShowResult(int(result), int(tpIdx))

# Altina ekle:
	if app.ENABLE_DAMAGE_TRACE:
		def __DamageTraceBegin(self, request, vid, hitType, count):
			self.targetBoard.OnDamageTraceBegin(int(request), int(vid), int(hitType), int(count))

		def __DamageTraceRow(self, request, index, key, before, after):
			self.targetBoard.OnDamageTraceRow(int(request), int(index), key, long(before), long(after))

		def __DamageTraceEnd(self, request, displayed, hpLoss):
			self.targetBoard.OnDamageTraceEnd(int(request), int(displayed), int(hpLoss))


# GameWindow.__ServerCommand_Build icinde ara:
			serverCommandList["ikashop_sold"] = self.__IkashopSold
			serverCommandList["AnkaOpenShopResult"] = self.__AnkaOpenShopResult

# Altina ekle:
		if app.ENABLE_DAMAGE_TRACE:
			serverCommandList["DamageTraceBegin"] = self.__DamageTraceBegin
			serverCommandList["DamageTraceRow"] = self.__DamageTraceRow
			serverCommandList["DamageTraceEnd"] = self.__DamageTraceEnd

