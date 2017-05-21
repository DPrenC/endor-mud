/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/std/arco.c
Autor: Yalin
Fecha: 03/04/2009 12:25
Descripción: base para los Arcos de entrada al edificio.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERAB("std/int");

create()
{
    ::create();
    SetPreIntShort("Bajo");
    SetIntShort("el arco ");
    SetIntLong("Apoyada sobre unas imponentes paredes de 7 metros de ancho por 15 de alto, la "
        "clave es un semicírculo perfecto que eleva su punto máximo 20 metros por encima de tu "
        "cabeza.\nSobre las paredes de piedra pulida, se ha grabado a ambos lados el ya conocido "
        "emblema de la diosa de estos territorios.\n");
    AddDetail(({"pared","paredes","muro","muros","emblema","diosa","dibujo","grabado"}),
        "Sobre la piedra pulida, ves grabada la imagen de la diosa: una mujer en pie, mirando al "
        "frente. Lleva una tiara con forma de búho, y en su mano izquierda sostiene una daga, con "
        "la que parece disponerse a decapitar a la serpiente que se enrosca en su brazo derecho.\n"
        "Al pasar bajo el arco, tienes la sensación de que las imágenes enfrentadas, cruzan sus "
        "miradas, atravesándote.\n");
    SetIntSmell("Mezclado con el lejano aroma de la hierba del claustro, se percibe cierto olor a "
        "incienso y aromas artificiales empleados en los ritos religiosos.\n");
    SetIntNoise("Sobre el profundo silencio del interior, se aprecia aquí un lejano rumor de algún "
        "surtidor de agua.\n");
    SetSoundEnvironment(SND_AMBIENTES("arroyo2"),3);
}
    