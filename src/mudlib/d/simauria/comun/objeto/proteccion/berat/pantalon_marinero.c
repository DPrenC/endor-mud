/****************************************************************************
Fichero: pantalon_marinero.c
Autor: Ratwor
Fecha: 14/05/2010
Descripción: unos pantalones de tela para los marinos.
****************************************************************************/

#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
    ::create();
    SetStandard(AT_TROUSERS, 1, P_SIZE_LARGE, M_TELA);
    SetShort("unos pantalones azules");
    SetLong("Son unos pantalones de color azul oscuro que suelen utilizar algunos "
    "marineros.\n Son de resistente lona, y de camales anchos que apenas llega a los "
    "tobillos.\n");
    AddId(({"pantalón", "pantalones", "pantalon", "ropa"}));
    AddAdjective(({"de", "lona", "marino", "marinero", "azul", "azules"}));
    SetWeight(400);
    Set(P_NUMBER, NUMBER_PLURAL); 
    
  }