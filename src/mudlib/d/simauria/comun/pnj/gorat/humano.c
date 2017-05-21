/*
	gorateño estándar
	Maler 2000
*/
	
#include <properties.h>
#include <living.h>
#include <nightday.h>
#include <moving.h>
#include <rooms.h>
#include <combat.h>
inherit NPC;

#define where environment()
#define me TO

int desayunado, comido, cenado;

create()
{
  string nombre, short;
  int gender,i;

  ::create();

  if (random(2)) gender=GENDER_MALE;
  else gender=GENDER_FEMALE;

  nombre=(gender==GENDER_FEMALE?"humana":"humano");
  short=(gender==GENDER_FEMALE?"una humana":"un humano");
  SetStandard(nombre, "humano", 5+random(3), gender);
  SetShort(short);
//  SetLong(W("Es un "+short+" corriente.\n"));
}
