/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();

  SetStandard("Bolge","medioelfo",15+random(3),GENERO_MASCULINO);
  SetShort("Bolge");
  SetLong(W("Es un anciano con rasgos élficos perteneciente a la noble familia "
  "Benjus. Su alta estatura contrasta con la delicadeza de su cuerpo.\n"));
  SetIds(({"humano","pueblerino","hombre","bolge","Bolge","anciano","viejo",
  "noble","medio elfo","medioelfo"}));
  SetAlign(100);
  InitChats(4,({
    "Bolge se rasca la cabeza pensativo.\n",
    "Bolge dice: 'Los orcos no aceptan ley ni orden que no pongan ellos'\n",
    "Bolge dice: 'El paso cerrado nos está produciendo pérdidas comerciales'\n",
    "Bolge dice: 'Se debería mandar otra expedición'\n",
    "Bolge dice: 'La guerra producirá pérdidas'\n"}));
}
