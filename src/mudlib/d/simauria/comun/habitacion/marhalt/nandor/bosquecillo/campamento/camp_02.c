// camp_02.c

/*
 Junto al carro de Mossi y Beni
 (c) [n] nemesis@simauria
 Creación:  14-Oct-2002 01:19:25 CEST
 Modificado:

*/

#include <moving.h>

#include "./path.h"

inherit SIM_ROOM;

create() {
 ::create();

 SetLocate("Bosque de Lengor");
 SetPreIntShort("junto a");
 SetIntShort("el carro de los gemelos Trassi");
 SetIntLong(
 W("Estás junto a uno de los carromatos de la compañía. A tu alrededor "
   "puedes ver algunos aparatos de gimnasia, así como una cuerda tendida "
   "entre dos postes a varios metros del suelo. Hacia el este puedes ver "
   "una hoguera, y hacia el sur y el nordeste otros carros.\n"));
 SetIndoors(0);

 AddDetail(({"carromato","carro"}),
 W("Un robusto carro-vivienda, con coquetas cortinas en las ventanas "
   "y pintado de alegres colores. Es bastante grande, así que es posible "
   "que lo ocupe más de una persona.\n"));
 AddDetail(({"ventanas"}),
 "Las ventanas tienen unas coquetas cortinas a cuadros blancos y azules.\n");
 AddDetail(({"cortinas","coquetas cortinas"}),
 W("Son unas cortinas a cuadros blancos y azules que le dan un toque "
   "muy hogareño al carromato.\n"));
 AddDetail(({"carro del norte","carromato del norte"}),
 "Te preguntas por qué aquel carro está tan alejado de los otros.\n");
 AddDetail(({"carro del sur","carromato del sur"}),
 W("Parece bastante más pequeño que el que puedes ver aquí, y, de alguna "
   "manera, más lúgubre.\n"));
 AddDetail(({"aparatos de gimnasia"}),
 "Puedes ver cuerdas, pesas y algunas pelotas.\n");
 AddDetail(({"cuerdas"}),
 "Son unas simples cuerdas de saltar.\n");
 AddDetail(({"pesas","pesas de gimnasia"}),
 W("No parecen muy pesadas. No son como las que usaría alguien que "
   "quisiera fortalecer su musculatura a tope, sino más bien como "
   "las que tendría alguien que simplemente quiere hacer ejercicios "
   "para robustecer determinados músculos.\n"));
 AddDetail(({"pelotas"}),
 W("Las hay de todos los tamaños y colores. Son como las que usaría "
   "un equilibrista en su número.\n"));
 AddDetail(({"cuerda","cuerda entre dos postes","cuerda floja"}),
 W("Una delgada cuerda tendida entre dos postes, a uno de los cuales "
   "se puede ascender por una escalera. Tiene toda la pinta de ser "
   "parte de un espectáculo de equilibrismo.\n"));
 AddDetail(({"hoguera"}),
 "Parece ser el centro del campamento.\n");

// AddItem("mossi",REFRESH_REMOVE, 1);
// AddItem("beni",REFRESH_REMOVE, 1);

// AddExit("nordeste", "camp_01");
// AddExit("este", "centro");
// AddExit("sur","camp_04");

}
