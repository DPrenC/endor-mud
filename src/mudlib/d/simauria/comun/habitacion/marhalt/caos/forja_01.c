/*****************************************************************************
 AUTOR:		[k] Kintups
 DETALLES:	Cavernas del Caos
            [Nyh] Muy modificado.
                  Creo la habitaci�n base, corrijo mogoll�n de typos y m�s
*****************************************************************************/

#include "path.h"

inherit CAOSHAB "_caos_base_room";

public create() {
  ::create();

  SetIntShort("el oeste de la Forja");
  SetIntLong("Est�s en la parte oeste de una habitaci�n irregular. Sus "
    "paredes y techo son de color marr�n oscuro. Al este se encuentra una "
    "forja, a tu lado hay un agujero de un metro de diametro en el suelo. "
    "La estancia esta llena de todo lo necesario para fabricar armas, "
    "escudos y armaduras. Tambien hay muchas armas y escudos a medio hacer "
    "tirados por el suelo. En las paredes hay bastantes agujeros repartidos "
    "por toda habitaci�n.\n"
    "La salida de la forja se encuentra al sur.\n");
  SetIntSmell("No hueles nada destacable, s�lo el olor tipico de las "
    "forjas.\n");
  SetIntNoise("No escuchas nada interesante, salvo el chasquido del fuego "
    "de la forja.\n");
  AddDetail(({"forja"}),
    "Esta m�s al este.\n");
  AddDetail(({"agujero","pozo"}),
    "No es m�s que un pozo de unos treinta y cinco metros de profundidad, "
    "que el herrero del lugar debe utilizar como pozo ciego para todo.\n");
  AddDetail(({"arma","armas","escudo","escudos","armadura","armaduras"}),
    "Est�n a medio hacer, por lo que no merece la pena molestarse en "
    "cogerlas.\n");
  AddExit("sur",CAOSHAB"forja_00");
  AddExit("este",CAOSHAB"forja_02");
  AddExit("sudeste",CAOSHAB"forja_03");
}
