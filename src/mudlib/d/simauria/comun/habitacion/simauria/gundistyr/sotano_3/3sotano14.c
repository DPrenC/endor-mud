/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano14.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Unas antorchas cuelgan de las paredes emitiendo una ténue luz."
"Las dimensiones de este pasillo son ligeramente menores que las del resto de "
"las cuevas, los techos son mas bajos y las paredes algo más estrechas. El "
"camino parece estrecharse más aun hacia el oeste, mientras que hacia el "
"nordeste se ensancha levemente.\n"));

AddDetail(({"pasillo","pasillo piedra","pasillo de piedra"}),W("Estás en un "
"pequeño pasillo rodeado de piedra.\n"));

AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Además también tienes la impresión de que "
"está más liso.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una señal de vida cercana.\n"));

AddDetail(({"antorcha de pared","antorcha pared","antorchas de pared",
"antorchas pared"}),W("Unas antorchas encendidas están a ambos lados de la "
"pared de piedra. Desprenden un humo muy negro.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");
SetIndoors(1);
SetIntBright(20);

AddExit("nordeste","3sotano08");
AddExit("oeste","3sotano13");
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
