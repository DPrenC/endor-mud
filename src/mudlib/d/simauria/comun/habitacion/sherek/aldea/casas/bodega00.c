/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/bodega00.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: Bodega de la aldea de Sloch, nave de prensado.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el lagar de la bodega");
    SetIntLong("Ésta es la nave donde se trae la uva de la vendimia para ser "
        "pisada para la producción del vino de la aldea.\nLa producción no "
        "es muy elevada, pero abastece bien a la aldea, da para pagar "
        "algunos barriles a los monjes, y aún sobra algún que otro tonel "
        "para vender en los mercados de otros pueblos.\nEn la mitad sur, "
        "junto a la puerta, a derecha e izquierda están amontonados los "
        "canastos, ahora vacíos, donde se recoge la uva en los viñedos para "
        "volcarla en el lagar, que se halla ocupando la mitad norte, "
        "extendiéndose de pared a pared, y desde la mitad de la habitación "
        "hasta la pared norte.\nUna escalera permite bajar al piso inferior, "
        "donde se recoge el mosto.\n");
    SetIntSmell("Huele a bodega, una mezcla de madera y vino viejo.\n");
    SetIntNoise("no oyes nada, las bodegas son siempre silenciosas. Al vino "
        "no le gusta el ruido.\n");
    AddDetail(({"canastas","canastos","cestas","cestos"}), "Los canastos son "
        "de mimbre trenzado. Son cilindros más anchos que largos, y están "
        "apilados unos dentro de otros.\n");
    AddDetail(("lagar"), "Es una especie de piscina pequeña, que empieza con un "
        "escalón algo alto, y va en pendiente hasta la pared del fondo, "
        "donde alcanza un metro y medio de profundidad. Igualmente una "
        "ligera pendiente va desde los laterales al centro de la parte "
        "profunda, donde un agujero permite la salida del mosto al caño.\n");
    AddDetail(({"agujero","caño"}), "Te metes en el lagar y te agachas para "
        "mirar. Ves un agujero de unos 20 centímetros de diámetro que se "
        "estrecha en forma de embudo, hasta la punta, que la oscuridad no te "
        "permite ver.\n");
    AddExit("sur", SHERALD("campo/vinyedo31"));
    AddExit("abajo", SHERALD("casas/bodega01"));
}
