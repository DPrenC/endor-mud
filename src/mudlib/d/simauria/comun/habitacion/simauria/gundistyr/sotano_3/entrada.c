/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: entrada.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Unas peque�os y resbaladizos escalones de piedra conducen a "
"pisos superiores de las cuevas, mientras que yendo hacia el este te adentras "
"un poco m�s en ellas. Notas que el ambiente a tu alrededor es menos h�medo, "
"el suelo no est� tan resbaladizo y los techos parecen m�s trabajados.\n"));

AddDetail(({"escalera","escalera piedra","escalera de piedra","escalones",
"escalones piedra","escalones de piedra"}),W("Unos estre�os pero firmes "
"escalones de piedra suben perdi�ndose en la oscuridad.\n"));

AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Adem�s tambi�n tienes la impresi�n de que "
"est� m�s liso.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una se�al de vida cercana.\n"));

SetIntSmell("Aspiras el aire y te llega un holor nauseab�ndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");
SetIndoors(1);
SetIntBright(0);
AddExit("este","3sotano01");
AddExit("arriba",GSOT2("salida"));
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
