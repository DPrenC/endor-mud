/*
DESCRIPCION : fonda 'el Viejo Pescador'
FICHERO     : /d/limbo/comun/habitacion/limbo/limbo/fonda.c
MODIFICACION: 15-09-98 [Angor@Simauria] Creacion
              11-10-99 [Woo] Pasada a /std/pub
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit "/std/pub";

#define NOMBRE          (TP->QueryName())
#define SUF             (TP->QueryGenderEndString())
#define RODOR_DICE(s)    write("El posadero Rodor dice: '"+s+"'\n")

#include <moving.h>
#include <money.h>

#include <rooms.h>
#include <properties.h>


//--------------------------------------------------------------------------------
create() {
::create();
// reset();
SetIntShort("la fonda 'el Viejo Pescador'");
SetIntLong(
"Te encuentras en la fonda 'el Viejo Pescador'. El local es regentado por un "
"humano siervo de los dioses, Rodor, quien atiende a los clientes y cocina. "
"Prepara platos marineros y su zarzuela de marisco es inigualable. La comida es "
"sabrosa y los precios moderados. El local en si es un bajo no muy amplio pero "
"acogedor, lleno de mesas y decorado con elementos del mar: conchas, redes, etc.. "
"En una de las paredes se halla un tablon en el que puedes ver el menu.\n");

AddDetail(({"mesas"}),
"La fonda está llena de ellas. ¿Dónde sino iban a comer los clientes?\n");

SetIntNoise("Oyes a la gente comiendo.\n");
SetIntSmell("Hmmmm el olor que llega de la cocina te hace la boca agua.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);

AddExit("oeste",LIMBO("calle01"));

AddItem(PNJ("rodor"),REFRESH_DESTRUCT,1);
AddItem(PNJ("viejo"),REFRESH_DESTRUCT,1);

AddFood("marisco","una cazuela de",9,12,0);
AddFood("merluza al horno","una cazuela de",6,10,0);
AddFood("pulpo","una cazuela de",5,6,0);
AddFood("sardinas fritas","una ración de",5,5,0);
AddFood("sopa de pescado","un plato de",4,3,0);

AddDrink("vino","una jarra de",3,6,4,0);
AddDrink("cerveza","una jarra de",2,5,4,0);
}