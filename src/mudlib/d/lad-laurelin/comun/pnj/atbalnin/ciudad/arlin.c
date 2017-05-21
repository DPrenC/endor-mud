/*
	Arlin el manitas
	Theuzifan, 14-03-99
*/
	
#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
  ::create();

  SetStandard("Arlin", "elfo", 10, GENDER_MALE);
  SetShort("Arlin el Manitas");
  SetLong(W("Arlin es el manitas local. Arregla todo lo que se pueda "
	"arreglar por métodos tradicionales, sin el uso de magia. Por la "
	"tienda ves distintos accesorios y bastantes cacharros sobre los que "
	"está trabajando.\n"));
  	
  SetIds(({"arlin", "elfo"}));
  	
  InitChats(1,({
  	"Arlin se pone a martillear alegremente sobre un trasto roto.\n",
  	"Arlin deja el martillo sobre una mesa.\n",
  	"",
  	"Arlin se pone a rebuscar algo por la desordenada mesa.\n",
  	""}));
}
