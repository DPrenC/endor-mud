/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	PNJ de Enalel
 *****************************************************************************/

#include "path.h"
#include <properties.h>

inherit ENALPNJ"base";

create(){
  ::create();
  
  SetStandard("Rombrat","humano",9+random(3),GENERO_MASCULINO);
  SetShort("Rombrat");
  SetLong("Es un viejo humano ciudadano de Enalel. Pasa el día en la posada.\n");
  SetIds(({"humano","pueblerino","hombre","rombrat","Rombrat","anciano","viejo"}));
  SetAlign(100);
  InitChats(7,({
    "Rombrat bebe un poco de sidra.\n",
    "Rombrat dice: 'Mi primo Roalf me ha comentado algo sobre una guerra'\n",
    "Rombrat suspira aburrido.\n",
    "Rombrat dice: 'Me han dicho que el sendero del pomar está cerrado'\n"}));
}
