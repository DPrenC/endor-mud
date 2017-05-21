    /****************************************************************************
    Fichero: garita_oeste.c
    Autor: Ratwor
    Fecha: 22/01/2008
    Descripción: Una de las garitas de los lados de la puerta del castillo
    ****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit SIM_ROOM;
create(){
    ::create();
    SetLocate("el castillo de Nandor");
    SetIndoors(0);
    SetIntShort("una garita descubierta");
    SetIntLong("Te encuentras en una especie de torrecilla rodeada de almenas alzada "
    "sobre la muralla. Un agujero practicado en el suelo permite, mediante una escalera "
    "de mano, descender al adarbe. Es un sitio estrecho, construído para que los "
    "arqueros defiendan desde arriba la entrada al puente levadizo y la zona del "
    "mecanismo que lo mueve. Algo mas al este ves una torrecilla similar, mientras "
    "que al norte divisas la vertiente de la colina, el sendero y el bosque de Cored.\n");
    AddDetail("escalera", "Una sencilla escalera de madera que comunica la garita con "
    "el adarbe.\n");
    AddDetail("bosque", "Al norte del camino de Marhalt, se extiende el bosque de "
    "Cored, una oscura masa de añosos árboles de aspecto ominoso.\n");
    AddDetail(({"colina", "ladera", "declive"}), "Al norte del castillo la ladera de la "
    "colina desciende en un declive poco pronunciado y cubierto de hierba, por el cual "
    "discurre el sendero trillado que al pie de la elevación se une al camino norte de "
    "Marhalt.\n");
    AddDetail("almenas", "Un muro de unos cincuenta centímetros de espesor que llega a "
    "la altura del pecho de un hombre rematado a intervalos regulares por cortos fustes "
    "cuadrados entre los cuales los defensores se asoman para disparar o derribar a los "
    "asaltantes. A cada pocos metros en la parte baja hay saeteras, estrechas aberturas "
    "mas anchas en la parte interior que en la esterior, utilizadas para disparar desde "
    "una posición cubierta o deslizar armas penetrantes como lanzas para ensartar a "
    "cualquier enemigo que trepe por escalas de asalto sin que éste pueda hacer "
    "nada para evitarlo.\n");

    AddExit("abajo", "./muralla07");
    AddItem(PNJCASTILLO("arquero"), REFRESH_DESTRUCT);
}
