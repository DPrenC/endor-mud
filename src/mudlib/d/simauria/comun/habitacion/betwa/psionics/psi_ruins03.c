/* psi_ruins03.c
   En el jard�n del Gremio
   Creaci�n: [n] Nemesis, 16-Abr-2001 01:12:50 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un bello jard�n");
SetIntLong(
W("Hubo un tiempo en que esto fue un bello jard�n cubierto de cristal para\
 evitar que el fr�o exterior lo malograra. Ahora, sin embargo, s�lo es un\
 sitio de desolaci�n. La cubierta tiene enormes agujeros por todas partes\
 y el suelo est� cubierto de cristales rotos. Sin embargo, una extra�a\
 magia parece operar todav�a en este lugar, ya que est�s rodeado de flores\
 de todos los colores que no se han marchitado. Sientes una paz inmensa que\
 impregna a�n todo el lugar. Sin duda todav�a queda un resto del poder que\
 construy� este edificio.\
 Al oeste puedes o�r el sonido del agua corriendo alegremente, y al este\
 puedes entrar a una oscura sala en el Gremio.\n" ));
SetIndoors(1);
SetIntNoise("Oyes el ruido de agua corriendo proveniente del oeste.\n");

AddDetail(({"cubierta","techo"}),
"Todo el jard�n estuvo una vez cubierto de cristal, pero la mayor parte se ha "
"venido abajo.\n");
AddDetail(({"jard�n","jardin"}),
"A pesar del fr�o intenso que reina en la cumbre de la monta�a, el jard�n no "
"se ha marchitado.\n");
AddDetail(({"cristales","cristales rotos"}),
"Cubren el suelo, crujiendo cuando los pisas. Deben provenir del techo.\n");
AddDetail(({"agujeros"}),
"El fr�o de las cumbres deber�a haber penetrado por ellos y arruinado el "
"jard�n, pero, por alguna raz�n, no ha sido as�.\n");
AddDetail(({"flores","flores multicolores"}),
"Aqu� crecen todo tipo de flores hermosas. Te preguntas c�mo es posible.\n");

AddExit("este","./psi_ruins02");
AddExit("oeste","psi_ruins04");

}