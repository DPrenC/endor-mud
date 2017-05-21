/*****************************************************/
//
//	"cimit2"
//
//	cimitarra especial WC: 5
//			   WC: 8 si la empu�a un orco	
//	11-12-01: Kodex -> Creaci�n
//	11-12-01: Kodex -> Modificaci�n
//
/******************************************************/
inherit WEAPON;

#include <combat.h>
#include <properties.h>
#include "../path.h"
create()
{
::create();

SetStandard(WT_ESPADA,5,P_SIZE_LARGE,M_ACERO);

SetShort("una cimitarra orca");
SetLong(W("Es un sable curvado con un brillo especial."
" La cimitarra est� forjada en acero y su forma es una "
"aut�ntica obra de arte, el esp�ritu del Caos debi� guiar "
"a los herreros que la forjaron. Tiene muescas en la hoja "
"seguramente marcas de enemigos ca�dos.\n"));
SetIds(({"arma","cimitarra"}));
SetWeight(QueryWeight() - 350);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  if (wielder->QueryRace() == "uruk")
  {
    tell_object(wielder,"Tu f�rrea garra se cierra con satisfacci�n sobre esta pesada cimitarra. Te sientes capaz de destripar a una legi�n de enemigos t� solo y la sed de sangre te invade.\n");
    SetWC(10);
  }
  return ::ChkEquip(wielder, weapon, flags);
}

public varargs mixed ChkUnequip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  SetWC(5);
  return ::ChkUnequip(wielder, weapon, flags);
}