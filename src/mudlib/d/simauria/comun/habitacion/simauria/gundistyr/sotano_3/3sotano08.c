/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano08.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;
create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("La luz ya es más intensa. No hay duda de que al suroeste de "
"aquí hay una fuente de luz que ilumina el interior de las cuevas. A tu "
"alrededor puedes ver señales de vida cercana además de la luz, como un "
"extraño trozo de madera en el suelo o una especie de tejido.\n"));

AddDetail(({"madera","trozo madera","trozo de madera"}),W("En el suelo "
"observas un alargado trozo de madera. Mirándolo con detenimiento da "
"la impresión de ser el fragmento de una lanza.\n"));

AddDetail(({"tejido","tela"}),W("Un trozo de tela está tirado en el "
"suelo. La tela es de color rojo.\n"));

AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Además también tienes la impresión de que "
"está más liso.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una señal de vida cercana.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");
SetIndoors(1);
SetIntBright(5);

AddExit("suroeste","3sotano14");
AddExit("noroeste","3sotano04");

AddItem(PNJGD("gkob"),REFRESH_REMOVE,3);
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
