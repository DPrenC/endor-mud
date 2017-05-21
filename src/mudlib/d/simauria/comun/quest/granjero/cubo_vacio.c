/**********************************************************************
fichero: cubo_vacio.c
autor: kastwey
Descripción: El cubo vacío para guardar la leche del granjero...
Bueno, que ha sonado super mal... para guardar la leche extraida de
las vacas del granjero... Mejor, mejor...
**********************************************************************/

#include "./path.h"
#include <properties.h>

inherit THING;

string pOwner;
public string SetOwner(string own) { return pOwner = own; }
public string QueryOwner() { return pOwner; }

public create()
{
    ::create();
    SetShort("un cubo de madera");
    SetLong(W("Es un cubo de madera bastante deteriorado. Sin "
              "embargo, parece que aún es capaz de contener líquidos.\n"));
    AddId(({"qbo","cubo"}));
    SetWeight(750);
    Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
}
