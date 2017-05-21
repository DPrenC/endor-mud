/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitación base, corrijo mogollón de typos y más
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el oeste de la Forja");
  SetIntLong("Estás en la parte oeste de una habitación irregular. Sus "
    "paredes y techo son de color marrón oscuro. Al este se encuentra una "
    "forja, a tu lado hay un agujero de un metro de diametro en el suelo. "
    "La estancia esta llena de todo lo necesario para fabricar armas, "
    "escudos y armaduras. Tambien hay muchas armas y escudos a medio hacer "
    "tirados por el suelo. En las paredes hay bastantes agujeros repartidos "
    "por toda habitación.\n"
    "La salida de la forja se encuentra al sur.\n");
  SetIntSmell("No hueles nada destacable, sólo el olor tipico de las "
    "forjas.\n");
  SetIntNoise("No escuchas nada interesante, salvo el chasquido del fuego "
    "de la forja.\n");
  AddDetail(({"forja"}),
    "Esta más al este.\n");
  AddDetail(({"agujero","pozo"}),
    "No es más que un pozo de unos treinta y cinco metros de profundidad, "
    "que el herrero del lugar debe utilizar como pozo ciego para todo.\n");
  AddDetail(({"arma","armas","escudo","escudos","armadura","armaduras"}),
    "Están a medio hacer, por lo que no merece la pena molestarse en "
    "cogerlas.\n");
  AddExit("sur",CAOSHAB"forja_00");
  AddExit("este",CAOSHAB"forja_02");
  AddExit("sudeste",CAOSHAB"forja_03");
}
