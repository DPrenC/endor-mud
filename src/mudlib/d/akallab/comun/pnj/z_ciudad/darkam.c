/********************
Fichero: /d/akallab/comun/pnj/z_ciudad/darkam.c
Autor: Yalin.
Fecha: 31/10/2007 20:57:02
Descripción: Aprendiz para la herboristería de Zarkam.
********************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;
    
create()
{
    ::create();
    SetStandard("Darkam","orco",10,GENERO_MASCULINO);
    SetName("Darkam");
    SetShort("Darkam, el aprendiz");
    SetLong("Darkam es un joven orco. Cojea de la pierna izquierda debido a una grave herida "
        "que sufrió hace tiempo en una batalla y que le hizo abandonar la carrera militar. Es "
        "por eso que ahora es el aprendiz del viejo herbolario Messur.\n");
    AddId(({"darkam","Darkam","aprendiz","tendero","orco"}));
}
