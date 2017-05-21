/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
  
  SetStandard("Marla","medio-elfo",10+random(3),GENERO_FEMENINO);
  SetShort("Marla la tendera");
  SetLong("Es una bella medio elfa propietaria de esta tienda. Sus ojos azules no parecen perder detalle de todos los que entran en su tienda.\n");
  SetIds(({"Marla","marla","elfa","semielfa","tendera"}));
  Set(P_CANT_LURE,1);
  SetAlign(300);
  InitChats(3,({
	"Marla ordena las estanterías.\n",
	"Marla suspira apesadumbrada.\n",
	"Marla coge un plumero y se pone a quitar el polvo.\n"}));
}
