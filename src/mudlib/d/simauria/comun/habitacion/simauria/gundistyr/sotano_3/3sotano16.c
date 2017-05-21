/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano16.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("A tu alrededor observas gran cantidad de nichos dispuestos de "
"forma irregular en la amplísima sala en la que te encuentras.Sobre algunos "
"de ellos observas a kobolds durmiendo pese a que toda la sala esté iluminada "
"por las antorchas que prenden de la pared.\n"));

AddDetail(({"nicho","nichos","cama","camas"}),W("Palpeas uno de los nichos "
"vacíos y lo notas ligeramente blando. Levantas la vieja y destrozada manta "
"que lo cubre y observas que no es más que un montón de paja cubierta por "
" una sucia manta.\n"));

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

SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

SetIndoors(1);
SetIntBright(20);

AddExit("norte","3sotano10");
AddExit("este","3sotano17");
AddExit("oeste","3sotano15");
AddExit("noroeste","3sotano09");
AddExit("nordeste","3sotano11");
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
