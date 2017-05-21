/*
ARCHIVO: salalider.c
AUTOR: [a] Articman

MODIFICADO: 23/01/02 [a] Creaci�n
            23/03/02 [n] Retocadas descripciones y esas cosas...
NOTA: Como dije tiempo ha, si vuelvo a ver escrito "tapizes" en lugar
      de "tapiCes", el responsable ser� fusilado al amanecer

*/


#include "path.h"

inherit SIM_ROOM;

create() {
::create();

SetIntShort("el sal�n del trono");
SetIntLong(W("Est�s en una espaciosa sala dominada por una especie de "
"trono desde el cual el troll Korthal esclaviza y abusa de los d�biles "
"kobolds sobre los que hace mucho tiempo se impuso. "
// Un troll abusando de un kobold... tio, est�s enfermo...
// Esto deber�a estar en un AddDetail("toques de decoraci�n")
"A diferencia de todas las restantes salas de la cuevas esta tiene unos "
"leves toques de decoraci�n con dos viejas mesas carcomidas, unos tapices "
"ra�dos y una alfombra deshilachada.\n"));

AddDetail(({"trono"}),W("Es una enorme silla de madera sin ning�n ornamento "
"particular,pero que es utilizada por el jefe de los kobolds como trono para "
"demostrar su autoridad.\n"));
AddDetail(({"mesa","mesas","mesa carcomida","mesas carcomidas"}),W("Son dos "
"peque�as mesas de madera viejas y podridas por el paso del tiempo y la "
"humedad. Sobre ellas est� el delicioso manjar destinado al jefe kobold.\n"));
AddDetail(({"tapiz","tapices","tapiz raido","tapices raidos",
            "tapiz ra�do","tapices ra�dos"}),W("Son unos "
"antiguos tapices totalmente destrozados hasta el punto de que no es posible "
"adivinar lo que en su d�a representaban.\n"));
AddDetail(({"alfombra","alfombra deshilachada"}),W("Hay una alfombra a los "
"pies del trono. Est� totalmente destrozada, cubierta de agujeros y con una "
"forma irregular.\n"));

SetIndoors(1);
SetIntBright(40);
SetIntSmell(W("El aire aqu� es nauseabundo. Te sientes incapaz de respirar "
"esto durante mucho tiempo.\n"));
SetIntNoise(W("Tan s�lo escuchas gemidos de kobolds que retumban por las paredes "
"de la sala.\n"));

AddExit("sur","3sotano19");
AddExit("este","sala_baculo");
AddExit("oeste","plataforma");

AddItem(PNJGD("jefetroll"),REFRESH_REMOVE);
AddItem(PNJGD("gkob"),REFRESH_REMOVE,2+random(4));
AddItem(PNJGD("kob"),REFRESH_REMOVE,1+random(3));


}