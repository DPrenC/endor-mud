/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/std/arco.c
Autor: Yalin
Fecha: 03/04/2009 12:25
Descripci�n: base para los Arcos de entrada al edificio.
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
        "clave es un semic�rculo perfecto que eleva su punto m�ximo 20 metros por encima de tu "
        "cabeza.\nSobre las paredes de piedra pulida, se ha grabado a ambos lados el ya conocido "
        "emblema de la diosa de estos territorios.\n");
    AddDetail(({"pared","paredes","muro","muros","emblema","diosa","dibujo","grabado"}),
        "Sobre la piedra pulida, ves grabada la imagen de la diosa: una mujer en pie, mirando al "
        "frente. Lleva una tiara con forma de b�ho, y en su mano izquierda sostiene una daga, con "
        "la que parece disponerse a decapitar a la serpiente que se enrosca en su brazo derecho.\n"
        "Al pasar bajo el arco, tienes la sensaci�n de que las im�genes enfrentadas, cruzan sus "
        "miradas, atraves�ndote.\n");
    SetIntSmell("Mezclado con el lejano aroma de la hierba del claustro, se percibe cierto olor a "
        "incienso y aromas artificiales empleados en los ritos religiosos.\n");
    SetIntNoise("Sobre el profundo silencio del interior, se aprecia aqu� un lejano rumor de alg�n "
        "surtidor de agua.\n");
    SetSoundEnvironment(SND_AMBIENTES("arroyo2"),3);
}
    