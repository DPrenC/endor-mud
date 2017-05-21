/***
fichero: armazon.c
Autor: kastwey@simauria
Descripci�n: El armaz�n de los 5 recipientes unidos.
Creaci�n: 06/12/2004
***/

public object QueryUsandose();
public object SetUsandose(object ob);
object pUsandose;

#include "path.h"

inherit THING;

create()
{
    ::create();
    SetShort("un armaz�n met�lico");
    SetLong(W("Es un armaz�n met�lico compuesto por seis recipientes amontonados.\n"
    "Dir�as que tiene aproximadamente un metro y medio de altura.\n"));
    SetNoGet("Mejor no lo muevas, no sea que se caigan y se desmonten.\n");
    SetNoTake("Mejor no los toques mucho, no sea que se caigan y se rompan.\n");
    SetValue(0);
    AddId("armazon");
    AddId("armaz�n");
    AddId("armaz�n met�lico");
    AddId("armazon metalico");
    AddId("armazon met�lico");
    AddId("armaz�n metalico");
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
        return "Desde lo alto de la estructura miras hacia abajo. Se te descompone el est�mago solo de pensar en lo fr�gil que parece el armaz�n desde tu posici�n, y lo aparatosa que ser�a la caida desde ahi arriba.\n";
    else
        return ::QueryLong();
}
