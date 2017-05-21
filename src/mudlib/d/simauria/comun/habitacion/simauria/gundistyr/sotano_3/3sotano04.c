/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: sotano04.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 26/01/02 [a] Creaci�n                              * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();

SetShort("la base kobold");
SetIntLong(W("Te das cuenta de que el paisaje a tu alrededor es ligeramente "
"distinto al que veias al principio de estas cuevas. Las paredes siguen "
"siendo igual de altas y la sensaci�n claustrofobica rode�ndote. Son por "
"ejemplo los techos y un suelo mas llano lo que ha cambiado. Son muestras "
"claras de que cerca de aqui habitan seres vivos...\n"));

AddDetail(({"pared","paredes"}),W("Las paredes de est�s cuevas son bastante "
"altas y est�n formadas de dura piedra caliza.\n"));
AddDetail(({"techo","techos"}),W("Ves algo que te llama mucho la atenci�n en "
"estos techos. Algunas maderas conectan el techo con las paredes "
"apuntal�ndolos. Es se�al inequivoca de que estas cuevas no son solo lugar "
"de paso para algunas criaturas, sino que es su hogar.\n"));
AddDetail(({"suelo"}),W("Te fijas que en esta zona el suelo est� m�s liso "
"que en las salas que se extienden al norte de aqu�. Esto hace que sea "
"much�simo m�s facil caminar.\n"));

SetIndoors(1);
SetIntBright(0);
SetIntSmell("Aspiras el aire y te llega un olor nauseab�ndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

AddExit("sudeste","3sotano08");
AddExit("oeste","3sotano03");
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
