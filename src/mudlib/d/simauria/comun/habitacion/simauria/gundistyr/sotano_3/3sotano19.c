/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: 3sotano19.c                                           * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 23/1/02 [a] Creaci�n                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "path.h"

inherit SIM_ROOM;

create(){
::create();
SetIntShort("la base kobold");
SetIntLong(W("Est�s en un pasillo dentro de las cuevas de Gundistyr, en la "
"zona habitada por los kobolds. El estrecho pasillo se extiende de norte a "
"sur, descendiendo tambi�n en una peque�a pendiente. A tu alrededor el "
"paisaje no varia mucho. Est�s rodeado por fr�a y h�meda roca. De las "
"negras paredes cuelgan unas antorchas. Al norte de aqu� ves un arco "
"burdamente decorado, parece que lo que hay en esa direcci�n es "
"importante\n"));

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

AddDetail(({"arco","arco norte","norte","arco del norte"}),W("Es un arco "
"de piedra muy tosco y con decoraciones muy burdas que ni siquiera llegas "
"a distinguir. Parece como si estuviera hecho por un ni�o y no est� en "
"absoluto cuidado.\n"));

SetIntSmell("Aspiras el aire y te llega un olor nauseab�ndo.\n");
SetIntNoise("Unos chillidos retumban por las paredes de la cueva.\n");

SetIndoors(1);
SetIntBright(20);

AddExit("norte","salalider");
AddExit("sur","3sotano22");

AddItem(PNJGD("kob"),REFRESH_REMOVE,3);
AddItem(PNJGD("gkob"),REFRESH_REMOVE);
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
