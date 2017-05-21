inherit ARMOUR;
#include "path.h"
#include <combat.h>;

#include <properties.h>;

create()
	{
	::create();
	SetStandard(AT_ARMOUR,0, P_SIZE_MEDIUM, M_TELA);
	SetIds(({"camisa"}));
	SetAds(({"de tela","una"}));
	SetShort("una camisa de tela");
	SetLong(
	"Es una camisa de tela confeccionada para el uso diario.\n"
	);
	SetResetQuality(100);
	Set(P_MATERIAL,M_TELA);
	SetSize(P_SIZE_MEDIUM);
	Set(P_NUMBER, NUMBER_SINGULAR);
	Set(P_GENDER, GENDER_FEMALE);
	SetWeight(250);
	SetValue(300);
	} // Create