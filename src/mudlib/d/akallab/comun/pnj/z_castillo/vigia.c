/*
DESCRIPCION  : un guardia vigia del castillo
FICHERO      : /d/akallab/comun/pnj/z_castillo/vigia.c
MODIFICACION : 14-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <gremios.h>


inherit PNJ("z_castillo/guardia");

#define CIUDAD "Zarkam"

create() {
  ::create();
  SetShort("un"+A_2+" guardia vigia orc"+AO2);
  SetLong(
     "Es un"+AO2+" de los guardias orcos que hay en el castillo. La mision de est"+AE2+" "
     "orc"+AO2+" fuerte y robust"+AO2+" es la de vigilar desde lo alto de esta torre lo "
     "que ocurre en la ciudad y a lo ancho del valle.\n");

  AddId(({"vigia"}));
  SetGuild(GC_LUCHADOR);

  InitChats(10,({
    MAY(ART2)+" guardia vigia mira hacia el extremo mas lejano del valle.\n",
    MAY(ART2)+" vigia bosteza ante la falta de actividad.\n",
    MAY(ART2)+" vigia observa la ciudad de "+CIUDAD+".\n",
    MAY(ART2)+" guardia vigia te dice:'Tu no deberias estar aqui. Largate!'.\n",
    MAY(ART2)+" vigia observa a una diligencia se aleja de la ciudad.\n"}));
}
