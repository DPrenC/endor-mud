/*
	SIMAURIA
  	========

	[g] Guybrush
	[n] Nemesis
	
	01/12/97 [g] Creacion del objeto ganzua.
	02/12/97 [g] Anyade las funciones para el estado de la ganzua.
	Mar'99 [n] Castellanizado.
*/


#define ME TO
#include <properties.h>
inherit "/std/thing";

// El "WC" de una ganzua (pickpower)
private static mixed Ppickpower=1;
public mixed SetPickPower (int i)
{
 if (i<1) i=1;
 if (i>10) i=10;
 return Ppickpower = i;
}
public mixed QueryPickPower() { return Ppickpower; }

create () {
  ::create();
  SetShort("una ganzúa");
  SetLong("Una simple ganzúa.\n");
  SetValue(10);
  SetWeight(25);
  AddId("ganzúa");
  AddId("ganzua");
  Set(P_GENDER, GENDER_FEMALE);
  SetPickPower(QueryPickPower());
}

