/*
DESCRIPCION  : Salida del tutorial
MODIFICACION : 2008-03-24 Angor
*/

#include "./path.h"
inherit ROOM;

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

int ir_puerta(){
  write("La puerta está cerrada y tras forcejear un poco con ella te das cuenta de que no "
        "puedes abrirla.\n");
  say(NOMBRE+" trata de abrir una puerta pero no puede.\n",TP);
  return 1;
}

int ir_trampilla(){
  write("Forcejeas con la trampilla pero no se abre. Debe estar atrancada por el otro lado.\n");
  say(NOMBRE+" trata de abrir la trampilla pero no puede.\n",TP);
  return 1;
}

public int abrir_cmd(string str)
{
 if (!str) return notify_fail("¿Qué es lo que quieres abrir?\n",NOTIFY_NOT_VALID)&&0;
 if (str=="puerta") {ir_puerta(); return 1;}
 if (str=="trampilla") {ir_trampilla(); return 1;}
 return 0;
}

create() {
  ::create();
  SetIntShort("un pasillo");
  SetIntLong(
"Te encuentras en un rellano. Al norte de aquí se halla la habitación de reposo "
"a la que trasladan a los pacientes de Asthar tras la operación para que se "
"recuperen y al sur queda una pequeña biblioteca. Unas escaleras permiten bajar "
"a la planta baja del edificio y al oeste hay una puerta cerrada.\n");


AddDetail(({"trampilla"}),
 "Es una plancha de madera que parece pesada. Conduce a algun lugar bajo este pasillo.\n");

AddDetail(({"puerta","puertas"}),
 "Las puertas conducen a las habitaciones de los siervos de los Dioses que viven "
 "en estre edificio. Suelen estar cerradas para evitar a los curiosos.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("No huele a nada en especial.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);

 AddExit("norte",SF(ir_puerta));
 AddExit("sur",SF(ir_puerta));
 AddExit("abajo",SF(ir_trampilla));
 AddExit("este",TEMPLO("escalera"));
 AddRoomCmd("abrir","abrir_cmd");
 SetSafe(1);
}


