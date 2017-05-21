/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:2torre01.c                                    * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creaci�n                         * */
/* **************************************************************** */

#include "path.h"
#include <colours.h>
#include <skills.h>

inherit SIM_ROOM;

int cmd_trepar() {
int esc;
  esc=TP->UseSkill(HAB_TREPAR);
   if (esc<=-15) {
     write("Intentas trepar la pared de piedra pero resbalas y caes.\n");
     say(TP->QueryName() +" trata de escalar una pared al "
     "este pero cae.\n");
     TP->SetHP(TP->QueryHP()-10);
     return 1;
     }
   else  {
     write("Consigues trepar la pared con �xito.\n");
     say(TP->QueryName() +" trepa la pared al este.\n");
     TP->move(GSUP("2torre02"));
     return 1;
     }
}
create() {
::create();

SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Est�s en el segundo piso de la derruida torre de Gundistyr. "
"Parece que te encuentras medio suspendido en el aire ya que nada de suelo "
"te rodea en ninguna direcci�n. �nicamente hacia el este una escarpada pared "
"natural de piedra hay en este piso.\n"));


AddDetail(({"pared","pared este"}),W("Hacia el este tienes una pared natural, "
"creada por la propia monta�a. No parece tener excesiva altura y observ�ndola "
"bien ves algunas peque�as rendijas que podr�as usar para treparla.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"hierba.\n"));

AddRoomCmd("trepar","cmd_trepar");
AddExit("abajo","escarriba");


}