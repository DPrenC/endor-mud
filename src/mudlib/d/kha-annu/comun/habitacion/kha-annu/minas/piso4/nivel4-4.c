#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Te encuentras muy abajo en los t�neles...en una zona que no esta muy\n"
    "bien escabada aun.Parece que en esta zona no se han puesto apuntalamientos\n"
    "de seguridad, lo cual te hace sentir que el techo se puede venir abajo en un\n"
    "momento y acabar con tu pobre vida... realmente te sientes valiente por llegar\n"
    "aqui, tu mente se pregunta: �seguire adelante?\n"
    );
  SetIndoors(1);
  SetIntBright(15);
  SetIntSmell(
    "Huele a tierra.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddExit("oeste",MPISO4+"nivel4-3");
  AddExit("sudeste",MPISO4+"nivel4-5");
  SetLocate("");
}
