/*
DESCRIPCION  : Pescado para el quest de "las llaves del templo de Asthar"
FICHERO      : /d/limbo/comun/obj/otro/pescado.c
MODIFICACION : 22-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

inherit THING;
#include <properties.h> //por el P_NOSELL

create() {
  ::create();
  SetShort("un pequenyo pescado");
  SetLong(
 "Es un pequenyo pescado de color azulado. No ha debido ser pescado hace mucho ya\n"
 "que aun esta fresco.\n");

 AddId(({"pescado_quest","pescado","pequenyo pescado"}));
 SetWeight(250);
 SetValue(4);
 Set(P_NOSELL,1);
}

init() {
  ::init();
  add_action("comer_cmd","comer");
}

int comer_cmd(string str){
if (str!="pescado") return 0;
write(
  "Esta crudo y es demasiado pequenyo asi que como alimento no sirve de mucho. No\n"
  "te lo comes y piensas que quiza le encuentres algun uso mas tarde.\n");
return 1;
}