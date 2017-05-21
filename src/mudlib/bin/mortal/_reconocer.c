/** ENDOR-MUD'/bin/mortal/_identificar.c'
 *  =========================================
 */

#include <skills.h>
#include <herbs.h>

int main(string str)
{
  object planta;

  if (!TP->HasSkill(HAB_IDPLANTAS))
    return notify_fail("No tienes muy claro que es, necesitarías la habilidad de "
    "'reconocer plantas' para poder llegar a tener conocimientos sobre hierbas y otro tipo de plantas.\n");
  if (!str) return notify_fail("¿Qué planta quieres reconocer?\n");

  planta = present(str, TP);
  if (!planta && environment(TP)) planta=present(str, environment(TP));
  if (!planta) return notify_fail("No encuentras "+str+" aquí.\n");
  if (member(inherit_list(planta), "/obj/herb.c")==-1)
    return notify_fail("Es importante que lo que quieres reconocer sea una planta, una "
    "seta, unas raíces o cualquier otro tipo de vegetal.\n");
    say(CAP(TNAME)+" observa con detenimiento "+planta->QueryShort()+".\n");
  if (TP->UseSkill(HAB_IDPLANTAS) < 0)
  {
    write("Observas "+planta->QueryShort()+" estudiando sus propiedades, pero no consigues averiguar nada.\n");
    return 1;
  }

  write("Estudiando a "+planta->QueryShort()+" consigues reconocer que es del tipo "
  +planta->QueryType()+" y que sus propiedades podrían tener un efecto "+planta->QueryClass());
  if (planta->QueryClass()!=HERB_CLASS_UNKNOWN) write(" "+planta->QueryPowerString());
  write(".\n");
  return 1;
}
