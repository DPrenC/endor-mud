inherit ARMOUR;
#include "path.h"
#include <combat.h>;

#include <properties.h>;

create()
	{
	::create();
	SetStandard(AT_TROUSERS,0,P_SIZE_GENERIC,M_TELA);
	SetIds(({"pantalón","pantalon","pantalones"}));
	SetAds(({"de tela","unos","un"}));
	SetShort("unos pantalones de tela");
	SetLong(
	"Son unos pantalones de tela confeccionados para el uso diario.\n"
	);
	SetResetQuality(100);
	Set(P_MATERIAL,M_TELA);
	SetSize(P_SIZE_LARGE);
	Set(P_NUMBER, NUMBER_PLURAL);
	SetWeight(250);
	SetValue(300);
	} // Create