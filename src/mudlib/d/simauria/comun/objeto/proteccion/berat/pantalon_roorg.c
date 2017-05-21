/****************************************************************************
Fichero: pantalon_roorg.c
Autor: Ratwor
Fecha: 08/05/2010
Descripci�n: Unos pantalones de piel de roorg para la guardia de Berat.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 1, P_SIZE_LARGE, M_PIEL);
    SetShort("unos pantalones de piel de roorg");
    SetLong("Son unos pantalones oscuros de piel de roorg, un pez carn�voro que habita "
    "en el delta del r�o Raxal.\n La prenda se ajusta apretadamente a las piernas "
    "y las diminutas escamas funcionan como un magn�fico aislante t�rmico e "
    "impermeable.\n");
    AddId(({"pantal�n", "pantalones", "pantal�n de piel", "pantalones de piel"}));
    SetWeight(400);
    Set(P_NUMBER, NUMBER_PLURAL); 
    
  }