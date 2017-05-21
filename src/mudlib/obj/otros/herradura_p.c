/* Fichero: herradura_p.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: una herradura para cabalgaduras peque�as como poneys
*/

#include <properties.h>

inherit THING;

create() {
  ::create();
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetValue(80);
  SetWeight(500);
  SetIds(({"herradura","herradura de poney", "herredura peque�a"}));

  SetShort("una peque�a herradura");
  SetLong(
  "Es una herradura, una s�lida l�mina de hierro con forma m�s o menos de arco y "
  "orificios para introducir los clavos que la unen al casco del animal. Sirve para "
  "impedir el desgaste excesivo de los cascos de las monturas.\n"
  "En este caso se trata de una herradura para cabalgaduras de menor envergadura como "
  "los poneys.\n");
}