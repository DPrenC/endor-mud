/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
  
  SetStandard("Pofor","elfo",10+random(3),GENERO_MASCULINO);
  SetShort("Pofor el tendero");
  SetLong(W("Es un excéntrico elfo de aspecto sombrío. Sus ropajes y sus ojos "
  "son de un color oscuro inquietante. Cada vez que te mira, algo dentro de ti "
  "se remueve de intranquilidad.\n"));
  SetIds(({"Pofor","pofor","elfo","tendero"}));
  Set(P_CANT_LURE,1);
  SetAlign(-200);
  InitChats(3,({
	"Pofor consulta un libro de pastas oscuras.\n",
	"Pofor coge un frasco con un líquido oscuro.\n",
	"Pofor coge un cuenco y mezcla unos ingredientes.\n",
	"Pofor te mira y te pregunta con voz áspera:\n¿Quieres algo?\n"}));
}
