inherit ARMOUR;
#include "path.h"
#include <combat.h>;

#include <properties.h>;

create()
	{
	::create();
	SetStandard(AT_GLOVES,0,P_SIZE_GENERIC,M_TELA);
	SetIds(({"guante","guantes"}));
	SetAds(({"de tela","unos","un"}));
	SetShort("unos guantes de tela");
	SetLong(
	"Son unos guantes de tela confeccionados para el uso diario. "
	"Parecen abrigar mucho.\n"
	);
	SetResetQuality(100);
	Set(P_MATERIAL,M_TELA);
	SetSize(P_SIZE_MEDIUM);
	Set(P_NUMBER, NUMBER_PLURAL);
	SetWeight(50);
	SetValue(300);
	} // Create
