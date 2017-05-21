/*
DESCRIPCION  : en la copa de un arbol (modelo a)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbol_a.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la copa de un �rbol");
    SetIntLong("�Desde aqu� se observa mejor el paisaje! Te hallas en la parte media de la copa de uno de los �rboles del "
        "parque de entrenamiento. Las ramas en las que te apoyas se doblan bajo el efecto de tu peso y no crees "
        "conveniente subir mucho m�s arriba, donde las ramas son a�n m�s delgadas.\n");
    AddDetail(({"ramas"}),"A la altura a la que est�s, las ramas son razonablemente gruesas como para soportar tu peso, "
        "aunque no te acaba de gustar c�mo se doblan...\n");
    AddDetail(({"bosquecillo","bosque","pradera"}),"Puedes distinguir en el parque zonas donde se agrupan unos cuantos "
        "�rboles y otras con claros donde crece la pradera.\n");
    AddDetail(({"parque","entrenamiento","novatos","parque de entrenamiento"}),"Est�s en el parque de entrenamiento para "
        "novatos de la isla Limbo. Es una zona dispuesta por los dioses para que los reci�n llegados a este mundo puedan "
        "practicar con las armas y as� ganar algo de experiencia y nivel antes de emprender aventuras en el resto del "
        "mundo.\n");
    SetIntNoise("Oyes a los p�jaros trinar y al viento agitar las ramas de los �rboles.\n");
    SetIntSmell("Huele a bosque.\n");
    SetLocate("parque de isla Limbo");
    SetIndoors(0);
}
