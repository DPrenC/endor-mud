/****************************************************************************
Fichero: pantalon_roorg.c
Autor: Ratwor
Fecha: 08/05/2010
Descripción: Unos pantalones de piel de roorg para la guardia de Berat.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 1, P_SIZE_LARGE, M_PIEL);
    SetShort("unos pantalones de piel de roorg");
    SetLong("Son unos pantalones oscuros de piel de roorg, un pez carnívoro que habita "
    "en el delta del río Raxal.\n La prenda se ajusta apretadamente a las piernas "
    "y las diminutas escamas funcionan como un magnífico aislante térmico e "
    "impermeable.\n");
    AddId(({"pantalón", "pantalones", "pantalón de piel", "pantalones de piel"}));
    SetWeight(400);
    Set(P_NUMBER, NUMBER_PLURAL); 
    
  }