/*****************************************************************************************
 ARCHIVO:       tdhab30.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <moving.h>

inherit ROOM;

object obj1,obj2;
int visto;

string mirar_esqueletos();

public void create()
{
    ::create();

    SetIntShort("la enfermería");
    SetIntLong("Continúas estando en la destrozada enfermería. Sólo hay camas.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("camas", "Encima de algunas reposan los esqueletos de algunos pacientes, "
          "que no pudieron huir del infortunio que acabó con el templo y sus "
          "moradores.\n");
    AddDetail("esqueletos", SF(mirar_esqueletos));

    AddExit("noroeste", ALULAGO("templo/tdhab32.c"));
    AddExit("norte", ALULAGO("templo/tdhab34.c"));
}

string mirar_esqueletos()
{
    if(visto) return "Sus huesos están esparcidos por doquier.\n";

    obj1 = clone_object(ALUPNJ("esquelt.c"));
    obj2 = clone_object(ALUPNJ("esquelt.c"));
    obj1->move(TO, M_SILENT);
    obj2->move(TO, M_SILENT);
    visto = 1;
    return "Los ojos de los esqueletos se encienden ... y se levantan!!!\n";
}

public varargs void reset()
{
   visto = 0;
   ::reset();
}