/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();

  SetStandard("Pelgas","humano",9+random(3),GENERO_MASCULINO);
  SetShort("Pelgas");
  SetLong(W("Es un viejo humano ciudadano de Enalel. Pasa el día en la posada "
  "con sus amigos.\n"));
  SetIds(({"humano","pueblerino","hombre","pelgas","Pelgas","anciano","viejo"}));
  SetAlign(100);
  InitChats(5,({
    "Pelgas bebe un poco de sidra.\n",
    "Pelgas dice: 'Dicen que los elfos vuelven a estar en guerra con los orcos'\n",
    "Pelgas suspira aburrido.\n",
    "Pelgas dice: 'Creo que van a preparar una expedición para explorar las cuevas "
    "que hay a mitad del sendero del Pomar'\n",
    "Pelgas dice: 'Creo que hace poco los orcos atacaron la ciudad de Crowy'\n"}));
}
