/*
DESCRIPCION  : Caverna junto a la entrada de las minas
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/mina/nivel0/caverna5.c
MODIFICACION : 03-11-99 [Angor@Simauria] Creacion
MODIFICACION : 07-11-01 [Cheto@Simauria] Modificacion para el quest
		de la copa
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

hacer_coger(string cad1){
object ob;
string donde;
string str;
if (!cad1) {
write("uso coger <que>\n");
return 1;}
if (cad1=="llama"){
ob=clone_object("/d/simauria/comun/objeto/otro/llama");
ob->move(TP);
write("Enciendes una antorcha con la llama imperecedera.\n");
}else{
write("No puedes coger eso.\n");
}//cad1
return 1;
}

create() {
  ::create();
  SetIntShort("un santuario");
  SetIntLong(
  "Te encuentras en una sala especialmente cuidada por los orcos, en el "
  "centro de la sala puedes ver una pequeña llama que parece lleva mucho"
  " tiempo encendida.\n");
  AddDetail("llama",
"Es la llama imperedera que fué entregada a los orcos por un ente superior "
"la cual no puede apagarse nunca mientras permanezca en este santuario.\n");
  SetIntNoise("Se oye el aullar del viento en el exterior de la mina.\n");
  SetIntSmell("Huele a polvo y tierra.\n");
  SetLocate("minas de Zarkam");
  SetIndoors(1);
  SetIntBright(50);
  AddExit("este",Z_MINAS("/camino/c_mina05"));
}
init(){
add_action("hacer_coger","coger");
::init();}

//falta añadir el clonar llama
