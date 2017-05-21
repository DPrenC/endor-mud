#include "path.h"
#include <combat.h>;

#include <properties.h>;
#include <materials.h>

inherit ARMOUR;

create()
	{
	::create();
	SetStandard(AT_ARMOUR,0, P_SIZE_MEDIUM, M_TELA);
	SetIds(({"blusa"}));
	SetAds(({"de tela","una"}));
	SetShort("una blusa");
	SetLong(
	"Es una bonita blusa de tela.\n"
	);
	SetResetQuality(100);
	Set(P_MATERIAL,M_TELA);
	SetSize(P_SIZE_MEDIUM);
	Set(P_NUMBER, NUMBER_SINGULAR);
	Set(P_GENDER, GENDER_FEMALE);
	SetWeight(200);
	SetValue(400);
	} // Create
