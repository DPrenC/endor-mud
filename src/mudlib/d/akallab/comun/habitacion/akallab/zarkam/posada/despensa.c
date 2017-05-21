/*
DESCRIPCION : despensa de la fonda/posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/despensa.c
MODIFICACION: 16-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include "./posada.h"
#include <moving.h>
#include RAIZ "sys/macros.h"
inherit ROOM;

int ir_bodega(){
  write("Levantas la trampilla de la bodega y comienzas a descender por una rampa de "
        "madera hasta ella. Una vez abajo, la trampilla se cierra sobre tu cabeza.\n");

  say(NOMBRE+" levanta la trampilla de la bodega y desciende por la rampa de "
      "madera. La trampilla se cierra tras "+PRO+".\n");

  tell_room(Z_POSADA("bodega"),
      NOMBRE+" levanta la trampilla del techo y baja por la rampa hasta la bodega.\n");

  TP->move(Z_POSADA("bodega"),M_SILENT);
  return 1;
}


create() {
  ::create();
  SetIntShort("la despensa de la "+TIPO);
  SetIntLong(
    "Te encuentras en la despensa de la "+TIPO+" "+POS_NOM+". Es una estancia de "
    "tamanyo medio llena de estanterias repletas de los mas diversos productos que "
    "son necesarios para hacer las comidas que se sirven en este local. En el suelo "
    "hay una trampilla que permite acceder a la bodega donde "+POSADERO+" guarda los "
    "barriles de vino y cerveza. Al oeste de aqui se halla la cocina.\n");

  AddDetail(({"estanterias","productos"}),
    "Hay estanterias a lo largo de las paredes de la despensa. En ellas puedes ver "
    "todo tipo de productos que "+COCINERO+" emplea para preparar las comidas que se "
    "sirven en la "+TIPO+". Ves muchos tipo de frascos, botes y tinajas ademas de "
    "cajas de madera de distintos tamanyos.\n");

  AddDetail(({"trampilla","argolla"}),
    "Es una gruesa plancha de madera de forma rectangular que permite acceder a la "
    "bodega desde la despensa. Tiene una argolla de metal para tirar de ella.\n");

  AddDetail(({"cocina"}),
    "La habitacion que queda al oeste es la cocina de la "+TIPO+".\n");

  SetIntNoise("Oyes el tipico ruido de cacharros proveniente de la cocina.\n");
  SetIntSmell("El aire es calido y el olor de los calderos tentador...\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("abajo",SF(ir_bodega));
  AddExit("oeste",Z_POSADA("cocina"));
}