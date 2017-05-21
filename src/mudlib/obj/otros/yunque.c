/* Fichero: yunque.c 
Autor: Aul�
Fecha: 13/01/2015
Descripci�n: un yunque normal para poner en las herrer�as.
*/
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetValue(25000);
  SetWeight(150000);
  SetIds(({"yunque"}));
  SetNoGet("El yunque es muy pesado y est� firmemente sujeto al suelo como para que "
  "puedas llev�rtelo");
  SetShort("un pesado yunque");
  SetLong(
  "Se trata de una gran pieza de acero macizo m�s o menos rectangular. La parte trasera "
  "se estrecha y termina en forma de cuadrado mientras que la parte delantera se "
  "redondea terminando en punta. La superficie es totalmente plana para facilitar el "
  "martillado y cincelado de los objetos forjados, a los que ayudan a dar forma las "
  "distintas irregularidades del yunque. Est� encajado en un bloque de hierro m�s "
  "grande que lo sustenta a la altura adecuada para que el herrero haga su trabajo.\n");
  
}