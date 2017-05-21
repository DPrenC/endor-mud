/*
DESCRIPCION  : Banco del poblado de pescadores
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/banco.c
MODIFICACION : 02-10-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <moving.h>

inherit BANK;


create() {
  ::create();
  SetIntShort("el banco de Limbo");
  SetIntLong(
    "Te encuentras en el banco del poblado. Aunque es bastante modesto, cumple su cometido perfectamente: puedes "
    "abrir o cancelar una cuenta, sacar y meter dinero, etc...\n");
  SetIntNoise("El único ruido es el del banquero pasando páginas.\n");
  SetIntSmell("Hueles el dinero, ¿eh?.\n");
  SetLocate("isla Limbo");
  SetBankName("limbo");
  SetIntBright(50);

  SetKeeper(PNJ("banquero"));
  AddExit("este",LIMBO("calle03"));
}