/***
fichero: armazon.c
Autor: kastwey@simauria
Descripción: El armazón de los 5 recipientes unidos.
Creación: 06/12/2004
***/

public object QueryUsandose();
public object SetUsandose(object ob);
object pUsandose;

#include "path.h"

inherit THING;

create()
{
    ::create();
    SetShort("un armazón metálico");
    SetLong(W("Es un armazón metálico compuesto por seis recipientes amontonados.\n"
    "Dirías que tiene aproximadamente un metro y medio de altura.\n"));
    SetNoGet("Mejor no lo muevas, no sea que se caigan y se desmonten.\n");
    SetNoTake("Mejor no los toques mucho, no sea que se caigan y se rompan.\n");
    SetValue(0);
    AddId("armazon");
    AddId("armazón");
    AddId("armazón metálico");
    AddId("armazon metalico");
    AddId("armazon metálico");
    AddId("armazón metalico");
    AddId("recipientes");
    AddId("armazon_puesto_celdas");
}


public object SetUsandose(object ob)
{
    return pUsandose = ob;
}

    public object QueryUsandose() { return pUsandose; }
public string QueryLong()
{
    if (QueryUsandose() && TP != QueryUsandose())
        return ::QueryLong() + "Subid" + (QueryUsandose()->QueryGender() == 2?"a":"o") + " en lo alto, puedes ver a " + QueryUsandose()->QueryName() + ".\n";
    else if (QueryUsandose() && QueryUsandose() == TP)
        return "Desde lo alto de la estructura miras hacia abajo. Se te descompone el estómago solo de pensar en lo frágil que parece el armazón desde tu posición, y lo aparatosa que sería la caida desde ahi arriba.\n";
    else
        return ::QueryLong();
}
