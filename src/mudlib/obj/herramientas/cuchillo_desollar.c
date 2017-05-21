/*  fichero: cuchillo_desollar.c 
Autor: Aulë
Fecha: 13/09/2014
Descripción: 
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
  "Este pequeño cuchillo dispone de una hoja fina, resistente y afiladísima que se "
  "curva hacia la punta y se ensancha ligeramente en la parte media, de forma que el "
  "filo traza un ligero semicírculo. El mango de madera ha sido torneado para adaptarse "
  "perfectamente a la mano y favorecer la precisión de su manejo. La parte anterior de "
  "la hoja dispone de unos pequeños dientes afilados para raspar la piel y liberarla de "
  "los pequeños trozos de carne o grasa que se hayan podido quedar adheridos.\n");
}