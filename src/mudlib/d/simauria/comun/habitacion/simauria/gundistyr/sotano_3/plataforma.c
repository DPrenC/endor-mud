/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: plataforma.c                                          * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 28/1/02 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"
#include <moving.h>

inherit SIM_ROOM;


object *ob;
int i;
int final;

create(){
::create();

SetShort("la base kobold");
SetIntLong(W("Est�s en una plataforma de madera con forma rectangular. La "
"plataforma esta formado por gruesos troncos de �rbol unidos por fuerte "
"cuerda. Notas una suave brisa sobre tu cabeza. Lanzas la mirada hacia "
"arriba y ves que no hay nada, ni siquiera techo. Sobre tu cabeza hay "
"un agujero del cual no llegas a divisar el final. En uno de los laterales "
"de la plataforma hay una soga que llega desde arriba. Hacia el este "
"observas una salida.\n"));

AddDetail(({"pared","paredes"}),W("Las paredes de est�s cuevas son bastante "
"altas y est�n formadas de dura piedra caliza.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza no hay absolutamente nada "
"mas que aire.\n"));

AddDetail(({"suelo","plataforma"}),W("Bajo tus pies hay una plataforma de "
"madera hecha de troncos de �rboles atados por una dura cuerda que impide "
"que se separen.\n"));

AddDetail(({"soga"}),W("En uno de los lados ves una cuerda que sube hacia "
"arriba y se pierde de tu visi�n. Da la impresi�n de que podr�as "
"estirarla.\n"));


SetIndoors(1);
SetIntBright(0);
SetIntSmell("Aspiras el aire y te llega un olor nauseab�ndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

AddExit("este","salalider");
}
// Funci�n del no-gritar

int cmd_gritar(string str) {
  write(W("Te dispones a gritar, pero de pronto piensas que eso podr�a atraer a gran "
"multitud de seres con lo que desechas la idea.\n"));
  say(W(TP->QueryName() +" parece a dispuesto a hacer algo pero se "
"hecha atr�s.\n"));
return 1;
}

// Funci�n que pone en marcha la plataforma

int cmd_estirar(string str) {

if (!str) {
 write("�Qu� deseas estirar?\n");
 return 1;
 }
else {
  if (str!="soga") {
   write("No puedes estirar eso.\n");
   return 1;
  }
  else {
   write(W("Te acercas a la cuerda y empiezas a estirar de ella. Te das "
   "cuenta de que la plataforma va subiendo conforme tu estiras de la "
   "cuerda.\n"));
   say(W(TP->QueryName() +" empieza a estirar de una cuerda "
   "y la plataforma de mueve.\n"));
   filter(all_inventory(TO),SF(living))->move(GSOT3("platarriba"),M_SILENT);
   return 1;
   }
 }
}

init(){
::init();
add_action("cmd_gritar","gritar");
add_action("cmd_estirar","estirar");
}

