/*
ARCHIVO: salalider.c
AUTOR: [a] Articman

MODIFICADO: 23/01/02 [a] Creación
            23/03/02 [n] Retocadas descripciones y esas cosas...
NOTA: Como dije tiempo ha, si vuelvo a ver escrito "tapizes" en lugar
      de "tapiCes", el responsable será fusilado al amanecer

*/


#include "path.h"

inherit SIM_ROOM;

create() {
::create();

SetIntShort("el salón del trono");
SetIntLong(W("Estás en una espaciosa sala dominada por una especie de "
"trono desde el cual el troll Korthal esclaviza y abusa de los débiles "
"kobolds sobre los que hace mucho tiempo se impuso. "
// Un troll abusando de un kobold... tio, estás enfermo...
// Esto debería estar en un AddDetail("toques de decoración")
"A diferencia de todas las restantes salas de la cuevas esta tiene unos "
"leves toques de decoración con dos viejas mesas carcomidas, unos tapices "
"raídos y una alfombra deshilachada.\n"));

AddDetail(({"trono"}),W("Es una enorme silla de madera sin ningún ornamento "
"particular,pero que es utilizada por el jefe de los kobolds como trono para "
"demostrar su autoridad.\n"));
AddDetail(({"mesa","mesas","mesa carcomida","mesas carcomidas"}),W("Son dos "
"pequeñas mesas de madera viejas y podridas por el paso del tiempo y la "
"humedad. Sobre ellas está el delicioso manjar destinado al jefe kobold.\n"));
AddDetail(({"tapiz","tapices","tapiz raido","tapices raidos",
            "tapiz raído","tapices raídos"}),W("Son unos "
"antiguos tapices totalmente destrozados hasta el punto de que no es posible "
"adivinar lo que en su día representaban.\n"));
AddDetail(({"alfombra","alfombra deshilachada"}),W("Hay una alfombra a los "
"pies del trono. Está totalmente destrozada, cubierta de agujeros y con una "
"forma irregular.\n"));

SetIndoors(1);
SetIntBright(40);
SetIntSmell(W("El aire aquí es nauseabundo. Te sientes incapaz de respirar "
"esto durante mucho tiempo.\n"));
SetIntNoise(W("Tan sólo escuchas gemidos de kobolds que retumban por las paredes "
"de la sala.\n"));

AddExit("sur","3sotano19");
AddExit("este","sala_baculo");
AddExit("oeste","plataforma");

AddItem(PNJGD("jefetroll"),REFRESH_REMOVE);
AddItem(PNJGD("gkob"),REFRESH_REMOVE,2+random(4));
AddItem(PNJGD("kob"),REFRESH_REMOVE,1+random(3));


}