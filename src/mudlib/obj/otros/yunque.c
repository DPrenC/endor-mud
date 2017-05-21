/* Fichero: yunque.c 
Autor: Aulë
Fecha: 13/01/2015
Descripción: un yunque normal para poner en las herrerías.
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
  SetNoGet("El yunque es muy pesado y está firmemente sujeto al suelo como para que "
  "puedas llevártelo");
  SetShort("un pesado yunque");
  SetLong(
  "Se trata de una gran pieza de acero macizo más o menos rectangular. La parte trasera "
  "se estrecha y termina en forma de cuadrado mientras que la parte delantera se "
  "redondea terminando en punta. La superficie es totalmente plana para facilitar el "
  "martillado y cincelado de los objetos forjados, a los que ayudan a dar forma las "
  "distintas irregularidades del yunque. Está encajado en un bloque de hierro más "
  "grande que lo sustenta a la altura adecuada para que el herrero haga su trabajo.\n");
  
}