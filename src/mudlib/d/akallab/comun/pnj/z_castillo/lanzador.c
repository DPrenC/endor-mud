/*
DESCRIPCION  : un guardia entranandose en el lanzamiento de dagas
FICHERO      : /d/akallab/comun/pnj/z_castillo/lanzador.c
MODIFICACION : 14-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <gremios.h>


inherit PNJ("z_castillo/guardia");

create() {
  ::create();
 seteuid(getuid());
  SetLong(
     "Es un"+AO2+" de los guardias orcos que hay en el castillo, un"+AO2+" orc"+AO2+" fuerte y robust"+AO2+" "
     "cuya mision es la de proteger este lugar. En este momento se esta entrenando en "
     "lanzamiento de dagas con las dianas del patio del castillo. Por lo que ves, "
     "tiene bastante puntería.\n");

  SetDex(QueryDex()+1);

  AddItem(ARMA("daga"),REFRESH_REMOVE,3);
  SetGuild(GC_LUCHADOR);

  InitChats(10,({
  //--------------------------------------------------------------------------------
    MAY(ART2)+" guardia grita:'Apartate del medio o te usare a ti como blanco!'\n",
    MAY(ART2)+" guardia lanza una daga que se clava en el centro de la diana.\n",
    MAY(ART2)+" guardia se concentra antes de lanzar una daga.\n",
    MAY(ART2)+" se acerca a la diana y recoge las dagas que habia alli clavadas.\n",
    MAY(ART2)+" guardia descansa un momento.\n",
    "Una daga cruza el aire a toda velocidad y se clava en una diana.\n",
    MAY(ART2)+" guardia lanza una daga a la diana.\n"}));

}
