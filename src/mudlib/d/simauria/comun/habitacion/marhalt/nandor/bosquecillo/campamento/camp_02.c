// camp_02.c

/*
 Junto al carro de Mossi y Beni
 (c) [n] nemesis@simauria
 Creaci�n:  14-Oct-2002 01:19:25 CEST
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
 W("Est�s junto a uno de los carromatos de la compa��a. A tu alrededor "
   "puedes ver algunos aparatos de gimnasia, as� como una cuerda tendida "
   "entre dos postes a varios metros del suelo. Hacia el este puedes ver "
   "una hoguera, y hacia el sur y el nordeste otros carros.\n"));
 SetIndoors(0);

 AddDetail(({"carromato","carro"}),
 W("Un robusto carro-vivienda, con coquetas cortinas en las ventanas "
   "y pintado de alegres colores. Es bastante grande, as� que es posible "
   "que lo ocupe m�s de una persona.\n"));
 AddDetail(({"ventanas"}),
 "Las ventanas tienen unas coquetas cortinas a cuadros blancos y azules.\n");
 AddDetail(({"cortinas","coquetas cortinas"}),
 W("Son unas cortinas a cuadros blancos y azules que le dan un toque "
   "muy hogare�o al carromato.\n"));
 AddDetail(({"carro del norte","carromato del norte"}),
 "Te preguntas por qu� aquel carro est� tan alejado de los otros.\n");
 AddDetail(({"carro del sur","carromato del sur"}),
 W("Parece bastante m�s peque�o que el que puedes ver aqu�, y, de alguna "
   "manera, m�s l�gubre.\n"));
 AddDetail(({"aparatos de gimnasia"}),
 "Puedes ver cuerdas, pesas y algunas pelotas.\n");
 AddDetail(({"cuerdas"}),
 "Son unas simples cuerdas de saltar.\n");
 AddDetail(({"pesas","pesas de gimnasia"}),
 W("No parecen muy pesadas. No son como las que usar�a alguien que "
   "quisiera fortalecer su musculatura a tope, sino m�s bien como "
   "las que tendr�a alguien que simplemente quiere hacer ejercicios "
   "para robustecer determinados m�sculos.\n"));
 AddDetail(({"pelotas"}),
 W("Las hay de todos los tama�os y colores. Son como las que usar�a "
   "un equilibrista en su n�mero.\n"));
 AddDetail(({"cuerda","cuerda entre dos postes","cuerda floja"}),
 W("Una delgada cuerda tendida entre dos postes, a uno de los cuales "
   "se puede ascender por una escalera. Tiene toda la pinta de ser "
   "parte de un espect�culo de equilibrismo.\n"));
 AddDetail(({"hoguera"}),
 "Parece ser el centro del campamento.\n");

// AddItem("mossi",REFRESH_REMOVE, 1);
// AddItem("beni",REFRESH_REMOVE, 1);

// AddExit("nordeste", "camp_01");
// AddExit("este", "centro");
// AddExit("sur","camp_04");

}
