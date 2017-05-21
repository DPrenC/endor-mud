/* Fichero: clavos_herrar.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: cuatro clavos para colocar en la herradura de una montura.
*/
#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetValue(40);
  SetWeight(100);
  SetIds(({"clavo","clavos"}));

  SetShort("unos clavos de herradura");
  SetLong(
  "Son cuatro clavos de hierro espec�ficos para encajar en la herradura de una "
  "montura y de esta forma unirla al casco del animal.\n");
}