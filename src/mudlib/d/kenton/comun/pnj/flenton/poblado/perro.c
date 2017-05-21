/***************************************************************************************
 ARCHIVO:	perro.c
 AUTOR:		[z] Zomax
 FECHA:		27-01-2002
 COMENTARIOS:	Un perro para el poblado de Flenton.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit NPC;

create(){
  ::create();
  SetStandard("un perro","perro",1+random(5),GENERO_MASCULINO);
  SetHands(({({"pata derecha",1,1}),({"pata izquierda",1,1}),({"sus colmillos",1,5})}));
  SetIds(({"perro"}));
  SetAlign(50);
  SetWhimpy(5);
  SetGoChance(10);
  SetWeight(5000);

  SetShort("un perro");
  SetLong(W("Es uno de los perros que vagabundean por la aldea. Parece bien alimentado, se "
  	"ve que los aldeanos cuidan a los animales.\n"));

  InitChats(5,({"El perro te pone una miradita que te parte el corazón.\n",
   		"El perro te huele y mueve la cola.\n",
   		"El perro se pone a aullar para atraer tu atención.\n",
   		"El perro dice: ¿¡Guau!?\n",
   		"El perro se rasca las pulgas.\n"}));
}

DoDamage(int dmg)
{
	InitChats(0,"");
	return ::DoDamage(dmg);
}

move(dest,method,stuff)
{
	if(method==M_GO && environment() && environment()->QueryLocate()!=dest->QueryLocate())
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
