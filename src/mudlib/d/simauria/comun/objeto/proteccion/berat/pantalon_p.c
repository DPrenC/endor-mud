/****************************************************************************
Fichero: pantalon_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripci�n: unos pantalones peque�os
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 1, P_SIZE_SMALL, M_TELA);
    SetShort("unos pantalones rojos");
    SetLong("Son unos llamativos pantalones rojos, de tela �spera pero resistente.\n");
    AddId(({"pantal�n", "pantalones", "pantalon", "ropa"}));
    AddAdjective(({"de", "tela", "rojo", "rojos", "peque�os"}));
    SetWeight(300);
    Set(P_NUMBER, NUMBER_PLURAL); 
    
  }