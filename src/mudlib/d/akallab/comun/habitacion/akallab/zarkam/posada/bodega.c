/*
DESCRIPCION : bodega de la fonda/posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/bodega.c
MODIFICACION: 16-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include "./posada.h"
#include <moving.h>
#include RAIZ "sys/macros.h"
inherit ROOM;

int ir_despensa(){
  write("Comienzas a ascender por la rampa de madera hasta la trampilla. Una vez alli, la "
        "abres y sales a la despensa, para luego cerrar de nuevo la trampilla.\n");

  say(   NOMBRE+" comienza a ascender por la rampa hasta llegar a la trampilla y, una "
        "vez alli, la abre y sale a la despensa. "+NOMBRE+" cierra la trampilla tras de si.\n");

  tell_room(Z_POSADA("despensa"),
      "Se levanta la trampilla de la bodega y "+NOMBRE+" aparece desde la bodega.\n");

  TP->move(Z_POSADA("despensa"),M_SILENT);
  return 1;
}


create() {
  ::create();
  SetIntShort("la bodega de la "+TIPO);
  SetIntLong(
    "Estas en la bodega de la "+TIPO+" "+POS_NOM+". Es una estancia no muy grande "
    "que se halla en el sotano de la "+TIPO+" en la que "+POSADERO+" almacena unos "
    "cuantos grandes barriles con los diversos vinos y cervezas que sirve en el "
    "local. Una rampa de madera permite subir hasta una trampilla de madera que "
    "comunica la bodega con la despensa que esta arriba.\n");

  AddDetail(({"barriles","grandes barriles"}),
    "Hay unos cuantos barriles de madera de roble de diversos tamanyos aqui en la "
    "bodega. Estan cubiertos por una gruesa capa de polvo a la espera de que "
    POSADERO+" necesite gastarlos.\n");

  AddDetail(({"rampa"}),
    "Es una resistente plancha de madera que permite subir hasta la despensa. Hay una "
    "rampa en lugar de una escalera para asi poder meter y sacar los barriles rodando "
    "en la bodega.\n");

  AddDetail(({"trampilla"}),
    "Es una gruesa plancha de madera de forma rectangular que permite acceder a la "
    "bodega desde la despensa.\n");

  SetIntNoise("Oyes el tipico ruido de cacharros proveniente de la cocina.\n");
  SetIntSmell("El aire es calido y el olor de los calderos tentador...\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(0);

  AddExit("arriba",SF(ir_despensa));
}