/*
DESCRIPCION  : pradera (modelo a)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/pradera_a.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la pradera en el parque");
    SetIntLong("Est�s en un claro entre los bosquecillos de robles. A tus pies se extiende una inmensa pradera con una "
        "hierba alta que te cubre los pies. La brisa que sopla desde el oeste agita la hierba haciendo que los tallos se "
        "balanceen y parezca como si una ola avanzase por este mar verde que es la pradera.\n");
    AddDetail(({"hierba","tallos"}),"La hierba de la pradera tiene unos largos tallos de un color verde intenso.\n");
    AddDetail(({"pradera"}),"La pradera es una extensi�n de tierra en la que no crecen �rboles sino hierba.\n");
    AddDetail(({"bosquecillo","bosque","pradera"}),"Puedes distinguir en el parque zonas donde se agrupan unos cuantos "
        "�rboles y otras con claros donde crece la pradera.\n");
    AddDetail(({"parque","entrenamiento","novatos","parque de entrenamientos"}),"Est�s en el parque de entrenamiento para "
        "novatos de la isla Limbo. Es una zona dispuesta por los dioses para que los reci�n llegados a este mundo puedan "
        "practicar con las armas y as� ganar algo de experiencia y nivel antes de emprender aventuras en el resto del "
        "mundo.\n");
    SetIntNoise("Oyes a los p�jaros trinar y al viento agitar las ramas de los �rboles.\n");
    SetIntSmell("Huele a bosque.\n");
    SetLocate("parque de isla Limbo");
    SetIndoors(0);
}
