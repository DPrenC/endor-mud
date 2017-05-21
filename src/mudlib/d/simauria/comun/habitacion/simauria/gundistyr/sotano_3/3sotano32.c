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
SetIntLong(W("Te encuentras en una de las habitaciones usada como despensa "
"de comida para los kobolds.A tu alrededor ves un montón de animales "
"semiputrefactos y mutilados la mayoria de ellos. Están colocados sin "
"ningún orden particular y con multitud de insectos sobre ellos, "
"revoloteando a su alrededor.\n"));
AddDetail(({"animal","animales"}),W("Ves distintos tipos de animales muertos "
"cubiertos por gusanos y demás insectos. Aunque la gran mayoria son animales "
"granja,puedes ver otros tipos, como ratas.\n"));
AddDetail(({"insecto","insectos"}),W("Un montón de moscas, cucarachas y otros "
"insectos que no alcanzas a reconocer están sobre los podridos cuerpos de los "
"animales.\n"));

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

SetIntSmell("¡Huele asquerosamente a podrido por todas partes!\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

SetIndoors(1);
SetIntBright(20);

AddExit("nordeste","3sotano30");
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
