/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano01.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();

SetIntShort("la base kobold");
SetIntLong(W("Est�s en un corredor en el interior de las cuevas de Gundistyr. "
"Este pasillo de piedra da la impresi�n de haber sido ligeramente cuidado y "
"no libre a manos de la naturaleza. Hacia el oeste observas unas escaleras "
"mientras que hacia el sureste te parece ver alguna luz.\n"));

AddDetail(({"escalera","escalera piedra","escalera de piedra","escalones",
"escalones piedra","escalones de piedra"}),W("Un poco alejado hacia el este "
"eres capaz de ver una vieja escalera.\n"));
AddDetail(({"pasillo","pasillo piedra","pasillo de piedra"}),W("Est�s en un "
"peque�o pasillo rodeado de piedra.\n"));
AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Adem�s tambi�n tienes la impresi�n de que "
"est� m�s liso.\n"));
AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una se�al de vida cercana.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseab�ndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

SetIndoors(1);
SetIntBright(0);

AddExit("oeste","entrada");
AddExit("este","3sotano02");
}

int cmd_gritar(string str) {
  write(W("Te dispones a gritar, pero de pronto piensas que eso podr�a atraer a gran "
"multitud de seres con lo que desechas la idea.\n"));
  say(W(TP->QueryName() +" parece a dispuesto a hacer algo pero se "
"hecha atr�s.\n"));
return 1;
}

init(){
::init();
add_action("cmd_gritar","gritar");
}
