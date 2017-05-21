/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano31.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Te encuentras en una curva dentro de las cuervas de Gundistyr. "
"El camino hace un brusco giro conectado las salidas al norte y al oeste. El "
"camino esta salpicados con peque�o fragmentos de roca. Pegadas a las "
"paredes ves unas gruesas maderas que llegan hasta el techo, asi como unas "
"viejas antorchas que le dan una leve iluminaci�n a la sala.\n"));

AddDetail(({"suelo","suelos"}),W("Puedes pisar el suelo con bastante firmeza"
"sin correr el riesgo de caerte. Adem�s tambi�n tienes la impresi�n de que "
"est� m�s liso.\n"));

AddDetail(({"pared","paredes"}),W("Las paderes de dura roca est�n negras a "
"causa del humo de las antorchas y la falta de una salida de aire.\n"));

AddDetail(({"techo","techos"}),W("Sobre tu cabeza ves algunos maderos que "
"apuntalan los techos para evitar desprendimientos. Es sin lugar a dudas "
"una se�al de vida cercana.\n"));

AddDetail(({"antorcha de pared","antorcha pared","antorchas de pared"}),
W("Unas antorchas encendidas est�n a ambos lados de la pared de piedra. "
"Desprenden un humo muy negro.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseab�ndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

AddDetail(({"roca","fragmentos","fragmentos de roca","rocas"}),W("Algunas "
"peque�as rocas est�n sobre el suelo. Parecen ser fragmentos de las paredes "
"y techos"));

AddDetail(({"madera","maderas","gruesas maderas","maderas gruesas"}),W("Unos "
"gruesos maderos est�n pegados a la pared y ascienden hasta el techo, donde "
"otro madero conecta las dos paderes. Sin duda alguien ha apuntalado este "
"techo.\n"));

SetIndoors(1);
SetIntBright(20);

AddExit("norte","3sotano25");
AddExit("oeste","3sotano30");
}

int cmd_gritar(string str) {
  write(W("Te dispones a gritar, pero de pronto piensas que eso podr�a "
  "atraer a gran multitud de seres con lo que desechas la idea.\n"));
  say(W(TP->QueryName() +" parece a dispuesto a hacer algo pero "
  "se hecha atr�s.\n"));
return 1;
}

init(){
::init();
add_action("cmd_gritar","gritar");
}
