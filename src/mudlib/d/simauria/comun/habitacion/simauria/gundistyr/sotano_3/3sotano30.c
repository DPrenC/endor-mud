/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano30.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Estás en un pasillo dentro de las cuevas de Gundistyr, en la "
"zona habitada por los kobolds. El estrecho pasillo se extiende de este a "
"oeste, descendiendo también en una pequeña pendiente. A tu alrededor el "
"paisaje no varía mucho. Estás rodeado por fría y húmeda roca. De las "
"negras paredes cuelgan unas antorchas. Hacia el sur y suroeste dos estrechos "
"caminos parecen separarse del corredor principal\n"));

AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Además también tienes la impresión de que "
"está más liso.\n"));

AddDetail(({"pared","paredes"}),W("Las paderes de dura roca están negras a "
"causa del humo de las antorchas y la falta de una salida de aire.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una señal de vida cercana.\n"));

AddDetail(({"antorcha de pared","antorcha pared","antorchas de pared"}),
W("Unas antorchas encendidas están a ambos lados de la pared de piedra. "
"Desprenden un humo muy negro.\n"));

AddDetail(({"roca","fragmentos","fragmentos de roca","rocas"}),W("Algunas "
"pequeñas rocas están sobre el suelo. Parecen ser fragmentos de las paredes "
"y techos.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

SetIndoors(1);
SetIntBright(20);

AddExit("este","3sotano31");
AddExit("oeste","3sotano29");
AddExit("sur","3sotano33");
AddExit("suroeste","3sotano32");
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
