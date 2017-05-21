#include "path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit BANK;

create()
{
  ::create();
  SetIntLong(W("Estás en el banco de Atbalnin. Aquí podrás realizar "
  	"todo tipo de transacciones monetarias, como crear una cuenta, o meter "
  	"y sacar dinero.\n"));
  SetIntShort("el banco de Atbalnin");
  SetBankName("atbalnin");
  SetLocate("la ciudad de Atbalnin");
  SetIntNoise("El murmullo de la ciudad es aquí un poco más tenue.\n");

  SetKeeper(PNJ("atbalnin/ciudad/salndlin"));
  SetLastDest(ATB_CI("ciudad27"));
  AddExit("oeste",ATB_TI("taquillas"));
  AddExit("salir", ATB_CI("ciudad27"));

AddDoor("salir", "la puerta de la calle",
    "Es la puerta de  la calle.\n",
    ({"puerta de la calle", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}

