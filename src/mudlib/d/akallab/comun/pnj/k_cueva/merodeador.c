/*
DESCRIPCION  : un troll merodeador
FICHERO      : /d/akallab/comun/pnj/k_cueva/merodeador.c
MODIFICACION : 11-11-98 [Angor@Simauria] Creacion
	       17-11-98 [Theuzifan] Le anyade un SetName, o el heart_beat
	       peta al hacer un capitalize de 0.
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <gremios.h>


inherit  PNJ("std/troll");

create() {
  ::create();
 SetName("Merodeador");
  SetGoChance(50);
  SetAggressive(1);
  SetGuild(GC_LUCHADOR);

  InitChats(10,({
    MAY(ART2)+" troll grunye y te muestra los colmillos.\n",
    "Ves como "+ART2+" troll merodea por la zona.\n",
    MAY(ART2)+" troll te mira desconfiad"+AO2+".\n",
    MAY(ART2)+" troll saca algo de comida de alguna parte y se pone a comersela.\n",
    MAY(ART2)+" troll te mira fijamente. Resulta inquietante.\n"
    }));
}
