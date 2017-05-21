/*
DESCRIPCION  : un guardia de patrulla
FICHERO      : /d/akallab/comun/pnj/z_castillo/patrullero.c
MODIFICACION : 30-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <gremios.h>


inherit PNJ("z_castillo/guardia");

#define CIUDAD "Zarkam"

create() {
  ::create();
 SetGuild(GC_LUCHADOR);
  SetGoChance(50);
  InitChats(10,({
      MAY(ART2)+" guardia observa este lugar antes de irse a otro.\n",
      MAY(ART2)+" guardia patrulla en busca de cosas extranyas en este lugar.\n",
      MAY(ART2)+" guardia te mira con mala cara:'Que demonios haces tu aqui? Nada bueno'.\n",
      MAY(ART2)+" guardia te dice:'Tu no deberias estar aqui. Largate!'.\n",
      MAY(ART2)+" guardia te sonrie maliciosamente al tiempo que pasa el dedo sobre el filo "
      "de su arma. No te hace ninguna gracia.\n"}));
}
