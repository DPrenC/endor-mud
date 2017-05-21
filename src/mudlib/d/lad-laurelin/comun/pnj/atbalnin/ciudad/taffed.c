/*
	Taffed la tendera
	Theuzifan, 23-07-99
*/
	
#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
  ::create();

  SetStandard("taffed", "humano", 6, GENDER_FEMALE);
  SetShort("Taffed la tendera");
  SetLong(W("Taffed parece ser una curtida vendedora humana entrada en años. "
  	"Su tez morena parece indicar que proviene de la zona sur de "
  	"Simauria, y por su incisiva mirada puedes deducir que es una "
  	"gran comerciante.\n"));
  	
  InitChats(1,({
  	"Taffed carraspea indicándote que se da cuenta de tu presencia.\n",
  	"Ves como la tendera continúa limpiando y engrasando un espadón.\n",
  	"Taffed se va a la trastienda y vuelve en seguida.\n"}));
}
