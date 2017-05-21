#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Te encuentras muy abajo en los túneles...tan abajo que quizas da\n"
    "hasta miedo lo que pueda encontrarse aqui... no esta un poco cerrado\n"
    "esto? un derrumbe significaria una muerte segura...\n"
    );
  SetIndoors(1);
  SetIntBright(15);
  SetIntSmell(
    "Huele a tierra.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddExit("arriba",MPISO3+"nivel3-8");
AddExit("este",MPISO4+"nivel4-2");
  SetLocate("");
}
