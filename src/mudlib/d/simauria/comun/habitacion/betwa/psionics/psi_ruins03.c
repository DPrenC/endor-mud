/* psi_ruins03.c
   En el jardín del Gremio
   Creación: [n] Nemesis, 16-Abr-2001 01:12:50 CEST
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
::create();
SetLocate("Ruinas del Gremio de Psiónicos");
SetIntShort("un bello jardín");
SetIntLong(
W("Hubo un tiempo en que esto fue un bello jardín cubierto de cristal para\
 evitar que el frío exterior lo malograra. Ahora, sin embargo, sólo es un\
 sitio de desolación. La cubierta tiene enormes agujeros por todas partes\
 y el suelo está cubierto de cristales rotos. Sin embargo, una extraña\
 magia parece operar todavía en este lugar, ya que estás rodeado de flores\
 de todos los colores que no se han marchitado. Sientes una paz inmensa que\
 impregna aún todo el lugar. Sin duda todavía queda un resto del poder que\
 construyó este edificio.\
 Al oeste puedes oír el sonido del agua corriendo alegremente, y al este\
 puedes entrar a una oscura sala en el Gremio.\n" ));
SetIndoors(1);
SetIntNoise("Oyes el ruido de agua corriendo proveniente del oeste.\n");

AddDetail(({"cubierta","techo"}),
"Todo el jardín estuvo una vez cubierto de cristal, pero la mayor parte se ha "
"venido abajo.\n");
AddDetail(({"jardín","jardin"}),
"A pesar del frío intenso que reina en la cumbre de la montaña, el jardín no "
"se ha marchitado.\n");
AddDetail(({"cristales","cristales rotos"}),
"Cubren el suelo, crujiendo cuando los pisas. Deben provenir del techo.\n");
AddDetail(({"agujeros"}),
"El frío de las cumbres debería haber penetrado por ellos y arruinado el "
"jardín, pero, por alguna razón, no ha sido así.\n");
AddDetail(({"flores","flores multicolores"}),
"Aquí crecen todo tipo de flores hermosas. Te preguntas cómo es posible.\n");

AddExit("este","./psi_ruins02");
AddExit("oeste","psi_ruins04");

}