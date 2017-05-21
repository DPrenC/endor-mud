/* psi_ruins05.c
   En el jard�n del Gremio
   Creaci�n: [n] Nemesis, 16-Abr-2001 21:47:09 CEST
   NOTAS: De alguna manera, la estatua guardar� una de las piedras que el
          pringao del jugata busca.
   Modificaciones: [k] Karu a�ade al lenguaron.
                   [n] Lo cambia por un lenguar�n, que es m�s majo ;)
		       De paso, retoca las descripciones.
*/

#include "./path.h"
inherit SIM_ROOM;

public int QueryJardinLenguaron() { return 1; }

create() {
::create();
SetLocate("Ruinas del Gremio de Psi�nicos");
SetIntShort("un bello jard�n");
SetIntLong(
W("Est�s en el extremo norte del jard�n. Por alguna raz�n, la c�pula de\
 cristal est� intacta aqu�, y puedes sentir una gran paz. Sientes que\
 en este lugar el antiguo poder del Gremio se manifiesta con mayor intensidad.\
 Hay una estatua rodeada por bellos macizos de flores, sin duda la estatua\
 de alguien importante.\n\
El jard�n contin�a hac�a el sur, hacia un peque�o atrio.\n" ));
SetIndoors(1);
SetIntNoise("Oyes el alegre sonido del agua proveniente del sur.\n");

AddDetail(({"cubierta","techo","c�pula","cupula"}),
"Por alguna extra�a raz�n, la c�pula se conserva intacta en este lugar.\n");
AddDetail(({"jard�n","jardin"}),
"A pesar del intenso fr�o que reina en la cumbre de la monta�a, el jard�n no "
"se ha marchitado.\n");
AddDetail(({"cristales","cristales rotos"}),
"En este lugar no hay m�s cristal que el de la c�pula, y est� intacto.\n");
AddDetail(({"flores","flores multicolores"}),
"Aqu� crecen todo tipo de flores hermosas. Te preguntas c�mo es posible.\n");
AddDetail(({"estatua"}),
"Representa a un humano vestido con una larga t�nica y sosteniendo en su "
"mano alguna especie de amuleto. Tiene una placa con una inscripci�n.\n");
AddDetail(({"placa","inscripci�n"}),
"Tal vez deber�as leerla.\n");
AddReadMsg(({"placa","inscripci�n","inscripcion"}),
"Pone: Guldan de Ikkin, primer Mentat del Gremio de Psi�nicos.\n");

AddExit("sur","psi_ruins04");
AddItem("/d/simauria/comun/pnj/lenguaron",REFRESH_REMOVE,1);

}
