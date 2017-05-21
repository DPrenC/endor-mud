/****************************************************************************
Fichero: /guilds/kisalas/obj/hierbas.c
Autor: Yalin
Fecha: 28/01/2008 19:48
Descripción: Hierbas para el bálsamo curativo.
****************************************************************************/

#include "path.h"
#include <herbs.h>

inherit HERB;

private int tiene;

public void describe()
{
    if (tiene<=0)
    {
        remove();
        return;
    }
    SetShort("un paquete de hierbas medicinales con "+tiene+" dosis");
    SetLong("Es un paquetito de hierbas extrañas, agrupadas en grumos, cada uno con la dosis "
        "calculada para una mezcla precisa.\nLe quedan "+tiene+" dosis.\n");
    SetWeight(tiene*10);
    SetValue((QueryPowerNumber()*5)*tiene);
    return;
}

//control de dosis
public void SetContent(int cont)
{
    tiene=cont;
    describe();
    return;
}
public int QueryContent() { return tiene; }

create()
{
    ::create();
    tiene=6;
    describe();
    AddId(({"hierbas","paquete de hierbas","balsamo_hierba"}));
    SetSmell("Estas hierbas huelen a verde, con un agradable matiz almizclado.\n");
    SetClass(HERB_CLASS_HEALING);
    SetPower(random(100));
}
