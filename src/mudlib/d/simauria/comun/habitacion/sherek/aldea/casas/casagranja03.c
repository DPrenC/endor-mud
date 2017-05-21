/* Archivo: /d/simauria/comun/habitacion/sherek/aldea/casas/casagranja03.c
* Descripci�n: El cuarto de la guardia en la casa de administraci�n.
* Autor: Lug y Yalin.
*/
#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el cuarto de la guardia");
    SetIntLong("Aqu� es donde los guardianes mayores descansan por turno, "
        "mientras esperan el momento del cambio de guardia.\nTambi�n es "
        "donde Daryl, el jefe del cuerpo, despacha los asuntos que le son "
        "propios por su cargo: interrogar sospechosos o culpables de delitos "
        "o des�rdenes, distribuir los grupos de guardias en servicio, etc.\nUna puerta comunica al oeste con el resto de la casa.\n");
    SetIntSmell("Huele a acuartelamiento militar: sudor, metal de armas y "
        "armaduras y cuero de las correas.\n");
    SetIntNoise("Llega el murmullo del resto de la casa.\n");
    AddDetail(({"suelo"}), "Est� formado por placas de piedra pulida.\n");
    AddDetail(({"placas","piedra","piedras"}), "Son planchas rectangulares de "
        "granito pulido, probablemente extra�do de la cantera propiedad de "
        "los monjes de Sherek.\n");
    AddDetail(({"techo"}), "Es un techo de madera no muy alto sostenido por "
        "fuertes vigas que lo cruzan de lado a lado.\n");
    AddDetail(({"viga", "vigas"}), "Son gruesos troncos pulidos y pintados "
        "que soportan el peso de la planta superior de la casa.\n");
    AddDetail(({"pared","paredes","muro","muros"}), "Las paredes est�n "
        "hechas de la misma piedra que el resto de la casa, sin adornos. "
        "S�lo tienen una hilera de peque�os ganchos clavados en la piedra.\n");
    AddDetail(({"gancho","ganchos"}), "Son unos peque�os garfios de hierro, "
        "que sirven para colgar ocasionalmente las armas, cuando los "
        "guardianes van a comer o se ponen a descansar.\nDe uno de ellos "
        "cuelga un quinqu� de aceite.\n");
    AddDetail(({"quinqu�","quinque"}), "Es un dep�sito lleno de aceite, "
        "donde introduce su extremo una mecha de hilos retorcidos, que sube "
        "por un cilindro de cristal colocado sobre el dep�sito, y cuyo otro "
        "extremo se enciende para iluminar por la noche.\n");
    AddItem(QUEST+"sherek/daryl",REFRESH_DESTRUCT,1);
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_DESTRUCT,4);
    AddExit("oeste", SHERALD("casas/casagranja01"));
}
