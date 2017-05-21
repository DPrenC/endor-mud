/*****************************************************************************************
 ARCHIVO:       posada04_hab2.c
 AUTOR:         Ztico
 FECHA:         13-04-2005
 DESCRIPCIÓN:   Posada del Unicornio Azul. Habitación.
 COMENTARIOS:   Faltan los detalles y pijaditas.
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("la habitación 2 de la posada");
    SetIntLong("Se trata de una alcoba no demasiado grande pero donde descubres todas "
        "las comodidades para un agradable descanso. Al fondo, una mullida cama y a "
        "su lado, un aguamanil con jarra de plata para que puedas refrescarte. El "
        "suelo está cubierto por una alfombra.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("oeste", "./posada03_atrio");
    AddDoor("oeste", "la puerta de salida", 
    "Es una puerta de madera simple que sale al atrio de la posada.\n",
    ({"puerta del atrio", "puerta de madera", "puerta de salida", "puerta", "puerta oeste",
     "puerta del oeste"}));
}
