/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: entrada.c                                             * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Unas pequeños y resbaladizos escalones de piedra conducen a "
"pisos superiores de las cuevas, mientras que yendo hacia el este te adentras "
"un poco más en ellas. Notas que el ambiente a tu alrededor es menos húmedo, "
"el suelo no está tan resbaladizo y los techos parecen más trabajados.\n"));

AddDetail(({"escalera","escalera piedra","escalera de piedra","escalones",
"escalones piedra","escalones de piedra"}),W("Unos estreños pero firmes "
"escalones de piedra suben perdiéndose en la oscuridad.\n"));

AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Además también tienes la impresión de que "
"está más liso.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una señal de vida cercana.\n"));

SetIntSmell("Aspiras el aire y te llega un holor nauseabúndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");
SetIndoors(1);
SetIntBright(0);
AddExit("este","3sotano01");
AddExit("arriba",GSOT2("salida"));
}

int cmd_gritar(string str) {
  write(W("Te dispones a gritar, pero de pronto piensas que eso podría atraer a gran "
"multitud de seres con lo que desechas la idea.\n"));
  say(W(TP->QueryName() +" parece a dispuesto a hacer algo pero se "
"hecha atrás.\n"));
return 1;
}

init(){
::init();
add_action("cmd_gritar","gritar");
}
