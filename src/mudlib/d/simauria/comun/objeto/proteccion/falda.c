inherit ARMOUR;
#include "path.h"
#include <combat.h>;

#include <properties.h>;

create()
	{
	::create();
	SetStandard(AT_TROUSERS,0, P_SIZE_MEDIUM, M_TELA);
	SetIds(({"falda"}));
	SetAds(({"de tela","una"}));
	SetShort("una falda de tela");
	SetLong(
	"Es una falda de tela confeccionada para el uso diario.\n"
	);
	SetResetQuality(100);
	Set(P_MATERIAL,M_TELA);
	SetSize(P_SIZE_MEDIUM);
	Set(P_NUMBER, NUMBER_SINGULAR);
	Set(P_GENDER, GENDER_FEMALE);
	SetWeight(450);
	SetValue(600);
	} // Create
