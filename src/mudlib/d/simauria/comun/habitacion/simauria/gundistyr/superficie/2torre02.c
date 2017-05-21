/* **************************************************************** */
/* *                                                              * */
/* *         ARCHIVO:2torre02.c                                   * */
/* *         AUTOR: [a] Articman                                  * */
/* *         MODIFICADO: 3/11/01 Creación                         * */
/* **************************************************************** */

#include "path.h"
#include <colours.h>
#include <skills.h>

inherit SIM_ROOM;

int cmd_trepar(string str) {
int esc;
  if (!str || str=="pared" || str=="pared oeste" || str=="pared del oeste")
  esc=TP->UseSkill(HAB_TREPAR);
   if (esc<=-15) {
     write("Intentas bajar por la pared de piedra pero resbalas y caes.\n");
     say(TP->QueryName() +" trata de bajar por una pared al "
     "oeste pero cae.\n");
     TP->SetHP(TP->QueryHP()-10);
     TP->move(GSUP("2torre01"));
     return 1;
     }
   else  {
     write("Consigues escalar la pared con éxito.\n");
     say(TP->QueryName() +" baja por la pared del oeste.\n");
     TP->move(GSUP("2torre01"));
     return 1;
     }
}
create() {
::create();

SetIntShort("las ruinas de Gundistyr");
SetIntLong(W("Desde tu posición observas las ruinas de la antigua torre de "
"Gundistyr en su lamentable actual estado. Estás rodeado por altos árboles "
"que te limitan mucho el movimiento. Tan sólo un camino se abre hacia el "
"nordeste, aunque parece que podrías bajar por la pared de piedra al "
"oeste.\n"));


AddDetail(({"pared","pared oeste"}),W("Hacia el oeste tienes una pared "
"natural, creada por la propia montaña. No parece tener excesiva altura y "
"observándola bien ves algunas pequeñas rendijas que podrías usar para "
"bajar por ella.\n"));
AddDetail(({"arboles","árboles","pinos"}),W("Ves unos enormes pinos a tu "
"alrededor. Apenas hay espacio entre ellos, tan sólo te parece ver un pequeño "
"sendero que va hacia el nordeste.\n"));
AddDetail(({"torre","ruinas"}),W("Deste aquí observas con facilidad las "
"ruinas que conforman las ruinas de Gundistyr. La verdad es que están en "
"un lamentable estado.\n"));

SetIntSmell(W("Respiras profundamente y te llega el agradable olor de la "
"hierba.\n"));

AddRoomCmd("bajar","cmd_trepar");
AddExit("nordeste","2torre03");


}