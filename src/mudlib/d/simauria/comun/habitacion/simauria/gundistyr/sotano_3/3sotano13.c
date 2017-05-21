/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano13.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Te encuentras en una pequeña encrucijada dentro de las cuevas."
"En este punto confluyen dos pasillos, uno que va de este a oeste y otro con "
"dirección sur. Las paredes de la cueva están enngrecidas a causa del humo de "
"las antorchas, porque es evidente que aqui no hay salida de aire.\n"));

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

AddExit("este","3sotano14");
AddExit("oeste","3sotano12");
AddExit("sur","3sotano18");
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
