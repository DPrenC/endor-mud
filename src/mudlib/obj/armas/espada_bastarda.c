/* Fichero: espada_bastarda.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
  ::create();

  SetStandard(WT_ESPADA_MEDIANA,9,P_SIZE_GENERIC, M_HIERRO);
  SetShort("una espada de mano y media");
  SetLong("Esta espada es ligeramente más pesada y la hoja y empuñadura son algo más "
  "largas de lo habitual. La hoja recta posee dos formidables filos y va estrechándose "
  "casi imperceptiblemente desde la empuñadura, para hacerlo en forma más pronunciada "
  "cerca del final, terminando así en una aguzada punta. La empuñadura tiene el "
  "suficiente espacio como para apoyar ambas manos, aunque el equilibrio del arma "
  "permite hacerlo solo a una. La parte media de la cruz es maciza para equilibrar el "
  "arma hacia la empuñadura y los recios gabilanes se estrechan hacia las puntas "
  "curvadas ligeramente hacia la hoja.\n"
  "Este tipo de armas, aunque no muy abundante en la Tierra Media en la actualidad, "
  "fueron ampliamente utilizadas por los Elfos de los Días Antiguos y los Númenóreanos de "
  "Oesternnesse. Sin duda un arma dúctil, poderosa y precisa, aunque su manejo "
  "ambivalente requiere de cierto aprendizaje que no está al alcance de cualquiera.\n");
}