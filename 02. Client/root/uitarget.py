# Ara:
if app.ENABLE_MESSENGER_BLOCK:
	import uiCommon

# Altina ekle:
if app.ENABLE_DAMAGE_TRACE:
	import uiTrackDamage


# TargetBoard.__init__ icinde ara:
			self.elementImage = elementImage
		self.closeButton = closeButton

# Altina ekle:
		if app.ENABLE_DAMAGE_TRACE:
			self.damageDetails = None


# TargetBoard.Destroy icinde ara:
		if app.ENABLE_MOB_DROP_INFO:
			self.infoButton = None

# Altina ekle:
		if app.ENABLE_DAMAGE_TRACE:
			if self.damageDetails:
				self.damageDetails.Destroy()
			self.damageDetails = None


# TargetBoard.Close icinde ara:
		if app.ENABLE_MOB_DROP_INFO:
			self.infoButton.showWnd.Close()

# Altina ekle:
		if app.ENABLE_DAMAGE_TRACE:
			self.CloseDamageDetails()


# TargetBoard icinde ara:
		self.Hide()

# Altina ekle:
	if app.ENABLE_DAMAGE_TRACE:
		def ToggleDamageDetails(self):
			if self.damageDetails and self.damageDetails.IsShow():
				self.CloseDamageDetails()
				return
			if not self.vid:
				return
			if not self.damageDetails:
				self.damageDetails = uiTrackDamage.DamageDetails()
			anchor = self.infoButton.showWnd if app.ENABLE_MOB_DROP_INFO else self
			self.damageDetails.Open(self.vid, anchor)

		def CloseDamageDetails(self):
			if self.damageDetails and self.damageDetails.IsShow():
				self.damageDetails.Close()

		def OnDamageTraceBegin(self, request, vid, hitType, count):
			if self.damageDetails:
				self.damageDetails.Begin(request, vid, hitType, count)

		def OnDamageTraceRow(self, request, index, key, before, after):
			if self.damageDetails:
				self.damageDetails.Row(request, index, key, before, after)

		def OnDamageTraceEnd(self, request, displayed, hpLoss):
			if self.damageDetails:
				self.damageDetails.End(request, displayed, hpLoss)


# TargetBoard.SetTargetVID icinde ara:
	def SetTargetVID(self, vid):

# Altina ekle:
		if app.ENABLE_DAMAGE_TRACE and vid != self.vid:
			self.CloseDamageDetails()


# TargetBoard.InfoBoard.__Build icinde ara:
				self.AppendSeperator()
				self.__AppendTargetBonuses(isStone, raceFlag, nonplayer.GetGradeByVID(player.GetTargetVID()) if player.GetTargetVID() else 0)

# Altina ekle:
				if app.ENABLE_DAMAGE_TRACE:
					self.__AppendDamageButton()

