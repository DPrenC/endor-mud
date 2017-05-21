/* Archivo: /d/simauria/comun/habitacion/sherek/aldea/casas/casagranja03.c
* Descripción: El cuarto de la guardia en la casa de administración.
* Autor: Lug y Yalin.
*/
#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el cuarto de la guardia");
    SetIntLong("Aquí es donde los guardianes mayores descansan por turno, "
        "mientras esperan el momento del cambio de guardia.\nTambién es "
        "donde Daryl, el jefe del cuerpo, despacha los asuntos que le son "
        "propios por su cargo: interrogar sospechosos o culpables de delitos "
        "o desórdenes, distribuir los grupos de guardias en servicio, etc.\nUna puerta comunica al oeste con el resto de la casa.\n");
    SetIntSmell("Huele a acuartelamiento militar: sudor, metal de armas y "
        "armaduras y cuero de las correas.\n");
    SetIntNoise("Llega el murmullo del resto de la casa.\n");
    AddDetail(({"suelo"}), "Está formado por placas de piedra pulida.\n");
    AddDetail(({"placas","piedra","piedras"}), "Son planchas rectangulares de "
        "granito pulido, probablemente extraído de la cantera propiedad de "
        "los monjes de Sherek.\n");
    AddDetail(({"techo"}), "Es un techo de madera no muy alto sostenido por "
        "fuertes vigas que lo cruzan de lado a lado.\n");
    AddDetail(({"viga", "vigas"}), "Son gruesos troncos pulidos y pintados "
        "que soportan el peso de la planta superior de la casa.\n");
    AddDetail(({"pared","paredes","muro","muros"}), "Las paredes están "
        "hechas de la misma piedra que el resto de la casa, sin adornos. "
        "Sólo tienen una hilera de pequeños ganchos clavados en la piedra.\n");
    AddDetail(({"gancho","ganchos"}), "Son unos pequeños garfios de hierro, "
        "que sirven para colgar ocasionalmente las armas, cuando los "
        "guardianes van a comer o se ponen a descansar.\nDe uno de ellos "
        "cuelga un quinqué de aceite.\n");
    AddDetail(({"quinqué","quinque"}), "Es un depósito lleno de aceite, "
        "donde introduce su extremo una mecha de hilos retorcidos, que sube "
        "por un cilindro de cristal colocado sobre el depósito, y cuyo otro "
        "extremo se enciende para iluminar por la noche.\n");
    AddItem(QUEST+"sherek/daryl",REFRESH_DESTRUCT,1);
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_DESTRUCT,4);
    AddExit("oeste", SHERALD("casas/casagranja01"));
}
