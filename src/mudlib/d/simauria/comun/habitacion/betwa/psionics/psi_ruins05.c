/* psi_ruins05.c
   En el jardín del Gremio
   Creación: [n] Nemesis, 16-Abr-2001 21:47:09 CEST
   NOTAS: De alguna manera, la estatua guardará una de las piedras que el
          pringao del jugata busca.
   Modificaciones: [k] Karu añade al lenguaron.
                   [n] Lo cambia por un lenguarón, que es más majo ;)
		       De paso, retoca las descripciones.
*/

#include "./path.h"
inherit SIM_ROOM;

public int QueryJardinLenguaron() { return 1; }

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un bello jardín");
SetIntLong(
W("Estás en el extremo norte del jardín. Por alguna razón, la cúpula de\
 cristal está intacta aquí, y puedes sentir una gran paz. Sientes que\
 en este lugar el antiguo poder del Gremio se manifiesta con mayor intensidad.\
 Hay una estatua rodeada por bellos macizos de flores, sin duda la estatua\
 de alguien importante.\n\
El jardín continúa hacía el sur, hacia un pequeño atrio.\n" ));
SetIndoors(1);
SetIntNoise("Oyes el alegre sonido del agua proveniente del sur.\n");

AddDetail(({"cubierta","techo","cúpula","cupula"}),
"Por alguna extraña razón, la cúpula se conserva intacta en este lugar.\n");
AddDetail(({"jardín","jardin"}),
"A pesar del intenso frío que reina en la cumbre de la montaña, el jardín no "
"se ha marchitado.\n");
AddDetail(({"cristales","cristales rotos"}),
"En este lugar no hay más cristal que el de la cúpula, y está intacto.\n");
AddDetail(({"flores","flores multicolores"}),
"Aquí crecen todo tipo de flores hermosas. Te preguntas cómo es posible.\n");
AddDetail(({"estatua"}),
"Representa a un humano vestido con una larga túnica y sosteniendo en su "
"mano alguna especie de amuleto. Tiene una placa con una inscripción.\n");
AddDetail(({"placa","inscripción"}),
"Tal vez deberías leerla.\n");
AddReadMsg(({"placa","inscripción","inscripcion"}),
"Pone: Guldan de Ikkin, primer Mentat del Gremio de Psiónicos.\n");

AddExit("sur","psi_ruins04");
AddItem("/d/simauria/comun/pnj/lenguaron",REFRESH_REMOVE,1);

}
