/****************************************************************************
Fichero: foso_base.c
Autor: Riberales
Creación: 4/10/2005
Descripción: La habitación base de los fosos de Annufam.
****************************************************************************/

#include "./path.h"
#define TREPAR ({"por foso","por el foso","foso","por las paredes del foso",\
"las paredes del foso","paredes del foso","paredes de foso","por las paredes",\
"por la pared","por la pared del foso","por pared","por paredes"})



inherit ROOM;



int cmd_trepar(string str)
// trepar por las paredes del foso.
// es imposible
{
    if (!str || member(TREPAR,str) < 0)
    // sintaxis incorrecta
    {
    return notify_fail("¿Trepar por dónde?\n",NOTIFY_NOT_VALID);
}
if (QueryIndoors())
// el portón tapa la parte superior de esta hab del foso
{
    return notify_fail("Aunque pudieses trepar por estas resbalosas paredes, "
                       "teniendo el portón encima de tu cabeza, no parece "
                       "ser de mucha utilidad.\n", NOTIFY_NOT_VALID);
    }
    write("Intentas apoyar los pies en una de las paredes del foso. Sin "
          "embargo, la capa de limo de las mismas, hace que resbales sin tan "
          "siquiera haber trepado un palmo del suelo.\n");
    say(CAP(TNAME) + " se dispone a trepar por una de las paredes del foso. "
        "Sin embargo, la pátina de limo del foso le impiden agarrarse a las "
        "paredes, y vuelve a caer al suelo.\n");
    return 1;
}


public void create()
{
    ::create();

    SetLocate("annufam");

    AddDetail(({"pared","paredes"}),
              W("Son paredes de tierra, sin tratar ni nada por el estilo. Los "
                "enanos cavaron el foso y no se preocuparon mucho de "
                "arreglarlo. Más bien parece que sólo lo hicieron para "
                "dejarlo lo más liso posible y que fuera "
                "prácticamente impensable trepar por ellas.\n"));



    AddDetail(({"fondo","suelo"}),
              W("A través del agua ves el suelo, bastante embarrado debido a "
                "la presencia del líquido elemento. Intenta no pisar muy "
                "fuerte no sea que te hundas.\n"));


    AddDetail("agua",
              W("Es una agua bastante verdosa que no sabes muy bien de dónde "
                "vendrá. Más vale no abrir la boca no sea que pegues algún "
                "mal trago.\n"));



    SetIntSmell("Huele a agua estancada y medio corrompida.\n");
    AddItem(PNJ_CIUDAD_ANNUFAM("cocodrilo"),REFRESH_DESTRUCT,4 + random(7));

    AddRoomCmd(({"trepar","escalar"}),"cmd_trepar");

}



