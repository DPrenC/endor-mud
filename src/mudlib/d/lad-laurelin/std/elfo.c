/*
	Elfo estándar
	Theuzifan, 31-05-99
*/

#include "path.h"
#include <properties.h>
#include <living.h>
#include <nightday.h>

inherit NPC;

create()
{
  string nombre, short;
  int gender;

  ::create();
  if (random(2)) gender=GENDER_MALE;
  else gender=GENDER_FEMALE;

  nombre=(gender==GENDER_FEMALE?"elfa":"elfo");
  short=(gender==GENDER_FEMALE?"una elfa":"un elfo");
  SetStandard(nombre, "elfo", 5+random(3), gender);
  SetShort(short);
//  SetLong("Es un "+short+" corriente.\n");
  SetGoChance(25);
}
