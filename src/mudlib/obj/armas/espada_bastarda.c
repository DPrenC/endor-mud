/* Fichero: espada_bastarda.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create()
{
  ::create();

  SetStandard(WT_ESPADA_MEDIANA,9,P_SIZE_GENERIC, M_HIERRO);
  SetShort("una espada de mano y media");
  SetLong("Esta espada es ligeramente m�s pesada y la hoja y empu�adura son algo m�s "
  "largas de lo habitual. La hoja recta posee dos formidables filos y va estrech�ndose "
  "casi imperceptiblemente desde la empu�adura, para hacerlo en forma m�s pronunciada "
  "cerca del final, terminando as� en una aguzada punta. La empu�adura tiene el "
  "suficiente espacio como para apoyar ambas manos, aunque el equilibrio del arma "
  "permite hacerlo solo a una. La parte media de la cruz es maciza para equilibrar el "
  "arma hacia la empu�adura y los recios gabilanes se estrechan hacia las puntas "
  "curvadas ligeramente hacia la hoja.\n"
  "Este tipo de armas, aunque no muy abundante en la Tierra Media en la actualidad, "
  "fueron ampliamente utilizadas por los Elfos de los D�as Antiguos y los N�men�reanos de "
  "Oesternnesse. Sin duda un arma d�ctil, poderosa y precisa, aunque su manejo "
  "ambivalente requiere de cierto aprendizaje que no est� al alcance de cualquiera.\n");
}