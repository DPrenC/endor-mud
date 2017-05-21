/****************************************************************************
Fichero: pantalon_ancho.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: unos pantalones anchos para los estivadores.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 1, P_SIZE_LARGE, M_TELA);
    SetShort("unos pantalones anchos");
    SetLong("Son unos sucios pantalones de tela vasta y de amplias perneras. Se "
    "sujetan a la cintura mediante unas tiras de cuero, anudadas por delante.\n");
    AddId(({"pantalón", "pantalones", "pantalon", "ropa"}));
    AddAdjective(({"de", "tela", "anchos"}));
    SetWeight(400);
    Set(P_NUMBER, NUMBER_PLURAL); 
    
  }