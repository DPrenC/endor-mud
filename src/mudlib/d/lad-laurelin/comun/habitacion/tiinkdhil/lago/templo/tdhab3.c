/*****************************************************************************************
 ARCHIVO:       tdhab3.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el salón");
    SetIntLong("Por lo que te han dicho, esta sala debió ser el salón de recepciones y "
          "de actos religiosos. Seguramente fue magnífica...\n"
          "Ves a lo lejos el gran Altar de Dehim.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");
    AddDetail("altar", "Está demasiado lejos para examinarlo.\n");

    AddExit("este", ALULAGO("templo/tdpas7.c"));
    AddExit("oeste", ALULAGO("templo/tdhab4.c"));
    AddExit("norte", ALULAGO("templo/tdhab7.c"));
    AddExit("noroeste", ALULAGO("templo/tdhab8.c"));
}
