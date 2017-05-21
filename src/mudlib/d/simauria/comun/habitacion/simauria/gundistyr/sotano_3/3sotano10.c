/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano10.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creación                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Estás en el centro de una enorme sala que utilizan los kobolds "
"que habitan estas cuevas para descansar. Por todas partes ves montones de "
"paja dispersos sin orden alguno. Se nota que los kobolds no son "
"precisamente una de las razas más ordenada.\n"));

AddDetail(({"monton pajanicho","monton de paja","montón paja","montón de "
"paja","paja"}),W("Palpeas uno de los nichos vacíos y lo notas ligeramente "
"blando. Levantas la vieja y destrozada manta que lo cubre y observas que no "
"es más que un montón de paja cubierta por una sucia manta.\n"));

AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Además también tienes la impresión de que "
"está más liso.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una señal de vida cercana.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseabúndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

SetIndoors(1);
SetIntBright(20);

AddExit("norte","3sotano06");
AddExit("oeste","3sotano09");
AddExit("este","3sotano11");
AddExit("sur","3sotano16");
AddExit("noroeste","3sotano05");
AddExit("nordeste","3sotano07");
AddExit("suroeste","3sotano15");
AddExit("sudeste","3sotano17");

AddItem(PNJGD("kobduerme"),REFRESH_REMOVE,3+random(3));
}

int cmd_gritar(string str) {
  write(W("Te dispones a gritar, pero de pronto piensas que despertarias y "
  "atraerias a todos los seres de estas cuevas con lo que desechas la "
  "idea.\n"));
  say(W(TP->QueryName() +" parece a dispuesto a hacer algo pero se "
  "hecha atrás.\n"));
return 1;
}

init(){
::init();
add_action("cmd_gritar","gritar");
}
