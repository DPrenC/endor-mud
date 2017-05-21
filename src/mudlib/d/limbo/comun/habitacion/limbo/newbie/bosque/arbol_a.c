/*
DESCRIPCION  : junto al pie de un arbol (modelo a)
FICHERO      : /d/limbo/comun/habitacion/limbo/newbie/bosque/arbolo_a.c
MODIFICACION : 06-08-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetPreIntShort("junto a");
    SetIntShort("el pie de un �rbol");
    SetIntLong("Te encuentras junto al pie de un �rbol en un bosquecillo del parque. La brisa sopla suavemente desde el "
        "oeste agitando las ramas de los �rboles. El �rbol junto al que te encuentras es lo suficientemente robusto como "
        "para poder subir a su copa.\n");
    AddDetail(({"arbol","�rbol"}),"El �rbol junto al que te encuentras es un roble adulto. Calculas que tendr� como unos "
        "tres o quiz� cuatro metros de altura y parece bastante robusto.\n");
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
