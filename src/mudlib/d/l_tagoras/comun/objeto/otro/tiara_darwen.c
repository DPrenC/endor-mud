/*
Archivo: tiara_darwen.c
Autor(es): [T] Tagoras
Fecha: 10/03/2009
[T] 12/03/2009: Hecho que el short muestre [RETO] al player que ha de cogerlo.
[T] 21/03/2009: Hago que herede de BASE_ITEM_DARWEN.
*/

#include "path.h"
#include <colours.h>
#include <properties.h>

inherit BASE_ITEM_DARWEN;

public void create()
{
	::create();
	SetShort("la tiara de Darwen");
	SetLong("Es una tiara de platino engarzada con múltiples "+TC_BOLD+TC_RED+"rubíes"+TC_NORMAL+" y "+TC_BOLD+TC_GREEN+"esmeraldas"+TC_NORMAL+".\n");
	AddSubDetail(({"rubi", "rubí", "rubíes", "rubies"}), "Son una gemas de color "+TC_BOLD+TC_RED+"rojo"+TC_NORMAL+" de gran belleza.\n");
	AddSubDetail(({"esmeralda", "esmeraldas"}), "Son una gemas de color "+TC_BOLD+TC_GREEN+"verde"+TC_NORMAL+" de gran pureza.\n");
	SetMaterial(M_PLATINO);
	SetWeight(250);
	SetValue(45000);
	SetIds(({"tiara", "tiara_darwen"}));
	SetAds(({"la", "de", "Darwen"}));
	SetGender(GENERO_FEMENINO);
}
