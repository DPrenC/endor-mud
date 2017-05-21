/*
DESCRIPCION  : callejon
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/callejon.c
MODIFICACION : 28-10-99 [icaro@simauria]creacion
			   12-6-00 [Maler]elimino retornos de carro
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <combat.h>
#include <moving.h>

inherit SIM_ROOM;
inherit "/lib/money";


create() {
::create();
SetIntShort("un callejón");
SetIntLong("Estás en un oscuro callejón húmedo y sombrío, entre las sombras puedes ver la figura de un hombre.\n");
SetIndoors(0);
SetIntNoise("puedes oir las a las ratas correteando.\n");
SetIntSmell("Huele a alcantarilla.\n");
AddDetail(({"ratas"}),W("aunque te es imposible verlas en tal "
"oscuridad, puedes oirlas a decenas.\n"));
AddDetail(({"callejon"}),"con lo tenebroso que es te preguntas que haces aquí.\n");
AddExit("oeste","./cmerc3");
AddRoomCmd("comprar","Comprar");
AddItem("/d/simauria/comun/pnj/simauria/berat/timador");
}
init()
{   ::init();
add_action("comprar","comprar");

}
int comprar(string str) {
object ob;
if ((str == "espada") || (str == "espada magica")){
if (QuerySomeonesValue(TP)>=35000){
write("El hombre misterioso te dice: buena compra, hasta otra forastero.\n");
say(TP->QueryName()+" intercambia algo con el hombre misterioso.\n");
ob = clone_object("/std/weapon");
    ob->SetShort("una espada magica"),
    ob->SetValue(35000),
    ob->SetLong("Es una espada larga un tanto extraña.\n"),
    ob->SetIds(({"espada","espada larga"})),
    ob->SetWeight(5000),
    ob->SetWC(8);
    ob->SetWeaponType(WT_ESPADA);
    ob->SetDamType(DT_SLASH);
    ob->SetWeaponHands(2);
ob->move(TP,M_GET);
PayValue(TP,35000);
return 1;
                                             }
else{
  write("El hombre misterioso te dice: no tienes dinero suficiente, vuelve cuando lo tengas.\n");
 return 1;
    }
                                              }
else{
write("El hombre misterioso te dice: ¿Te crees que esto es una tienda?\n");
return 1;
    }
                         }