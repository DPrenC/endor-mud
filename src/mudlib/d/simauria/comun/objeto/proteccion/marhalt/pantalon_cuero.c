/****************************************************************************
Fichero: pantalon_cuero.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: unos pantalones de cuero.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 2, P_SIZE_LARGE, M_CUERO);
    SetShort("unos pantalones de cuero");
    SetLong("Unos ajustados pantalones de cuero blando, muy c�modos y perfectos "
            "para deslizarse entre la espesura sin provocar roces.\n");
    SetIds(({"pantal�n", "pantalones", "pantalon", "ropa"}));
    AddAdjective(({"de", "cuero", "blando", "c�modos", "comodos", "ajustados"}));
    SetWeight(900);
    Set(P_NUMBER, NUMBER_PLURAL); 
    
  }
  