/****************************************************************************
Fichero: pantalon_p.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: unos pantalones pequeños
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 1, P_SIZE_SMALL, M_TELA);
    SetShort("unos pantalones rojos");
    SetLong("Son unos llamativos pantalones rojos, de tela áspera pero resistente.\n");
    AddId(({"pantalón", "pantalones", "pantalon", "ropa"}));
    AddAdjective(({"de", "tela", "rojo", "rojos", "pequeños"}));
    SetWeight(300);
    Set(P_NUMBER, NUMBER_PLURAL); 
    
  }