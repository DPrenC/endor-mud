/*
Archivo: pendientes_darwen.c
Autor: [T] Tagoras
Fecha: 12/03/2009
Descripción: Pendientes para los retos de Darwen.
*/

#include "path.h"
#include <colours.h>
#include <properties.h>

inherit BASE_ITEM_DARWEN;

public void create()
{
	::create();
	SetShort("los pendientes de Darwen");
	SetLong("Son unos pendientes de mithril con dos finos diamantes levemente "+TC_BOLD+TC_BLUE+"azulados"+TC_NORMAL+" engarzados en ellos.\n");
	AddSubDetail(({"diamantes", "diamante"}), "Son dos trozos de carbón que tras pasar eones sometidos a grandes presiones han cristalizado en forma de brillantes. Luego han sido tallados magníficamente por algún maestro tallador élfico. El ligero color "+TC_BLUE+"azul"+TC_NORMAL+" que presentan se debe a alguna impureza que no quita ni un ápice de la belleza que exhiben.\n");
	SetMaterial(M_MITHRIL);
	SetValue(15000);
	SetIds(({"pendientes", "pendientes_darwen"}));
	SetAds(({"los", "de", "Darwen"}));
	Set(P_NUMBER, NUMERO_PLURAL);
}
