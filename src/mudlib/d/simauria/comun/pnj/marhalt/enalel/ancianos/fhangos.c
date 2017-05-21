/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();

  SetStandard("Fhangos","medioelfo",15+random(3),GENERO_MASCULINO);
  SetShort("Fhangos");
  SetLong(W("Es un anciano con rasgos élficos perteneciente a la noble familia "
  "Fhainfos. Su noble porte lo identifica como un miembro del noble linaje de "
  "Enalel.\n"));
  SetIds(({"humano","pueblerino","hombre","fhangos","Fhangos","anciano","viejo",
  "noble","medio elfo","medioelfo"}));
  SetAlign(1000);
  InitChats(4,({
    "Fhangos se rasca la cabeza pensativo.\n",
    "Fhangos dice: 'Los orcos no aceptan ley ni orden que no pongan ellos'\n",
    "Fhangos dice: 'Tenemos que apoyar a nuestros hermanos elfos, los humanos también están afectados'\n",
    "Fhangos dice: 'Cualquier día nos atacarán a nosotros esos perros orcos'\n",
    "Fhangos dice: 'El paso hacia el pomar ya debería haber sido abierto'\n"}));
}
