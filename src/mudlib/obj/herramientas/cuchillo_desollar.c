/*  fichero: cuchillo_desollar.c 
Autor: Aul�
Fecha: 13/09/2014
Descripci�n: 
CUCHILLO PARA DESOLLAR CUERPOS, QUITAR LA PIEL VAMOS.
*/
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO, 2,P_SIZE_GENERIC,M_ACERO);
  AddId(({"cuchillo", "herramienta", "cuchillo_desollar"}));
  SetAds(({"desollador", "de", "desollar", "despellejar"}));
  SetShort("un cuchillo de desollar");
  SetLong(
  "Este peque�o cuchillo dispone de una hoja fina, resistente y afilad�sima que se "
  "curva hacia la punta y se ensancha ligeramente en la parte media, de forma que el "
  "filo traza un ligero semic�rculo. El mango de madera ha sido torneado para adaptarse "
  "perfectamente a la mano y favorecer la precisi�n de su manejo. La parte anterior de "
  "la hoja dispone de unos peque�os dientes afilados para raspar la piel y liberarla de "
  "los peque�os trozos de carne o grasa que se hayan podido quedar adheridos.\n");
}