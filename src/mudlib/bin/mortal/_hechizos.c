/* SIMAURIA '/bin/mortal/_conjuros.c'
   ==================================
   [w] Woo@simauria
   [a] Angor@Simauria
   [h] Nyh@Simauria

   07-04-99 [w] Creación de este archivo basándome en el de habilidades.
   30-06-99 [a] Cambia el orden de descripcion/valor y hace varias
                justificaciones
   27-11-99 [t] Adaptados a los nuevos gremios (spells activos/inactivos)
   09-11-03 [h] Quito las frases y pongo numeros, que los pj se vuelven locos.
*/

#include <properties.h>
#include <colours.h>

/*
string nivel(int n)
{
  if (!n) return "desconocido";
  switch (n) {
    case 0..4:   return "desastroso";
    case 5..9:   return "fatal";
    case 10..14: return "pésimo";
    case 15..19: return "muy mal";
    case 20..24: return "bastante mal";
    case 25..29: return "mal";
    case 30..39: return "regular";
    case 40..49: return "aceptable";
    case 50..54: return "adecuado";
    case 55..64: return "bueno";
    case 65..69: return "muy bueno";
    case 70..79: return "excelente";
    case 80..89: return "óptimo";
    case 90..98: return "casi perfecto";
    case 99..100: return "perfecto";
    default: return "desconocido";
  }
  return "desconocido";
 }
*/
int main(string w)
{
  mapping sp;
  mixed *idx;
  string p, nivel;
  int i, k;

  p="";
  k=0;

  sp=TP->QuerySpells();
  if (!sp || !sizeof(sp)) return notify_fail("No conoces ningún conjuro.\n");

  idx=m_indices(sp);

  for (i=0; i<sizeof(idx); i++)
    if (TP->SpellIsEnabled(idx[i])) {
      nivel = STR->radjust(to_string(sp[idx[i], 0]),3," ")+"/"+STR->radjust(to_string(sp[idx[i],1]),3," ");
      if (!(k%2)) p+=sprintf("%-42s", "  "+STR->ladjust(idx[i]+" ",25,".")+" "+nivel);
      else p+=STR->ladjust(idx[i]+" ",25,".")+" "+nivel+"\n";
      k++;
    }

  /*
  for (i=0; i<sizeof(idx); i++)
    p+="  "+STR->ladjust(idx[i]+" ",35,".",8,".")+" "+nivel(sp[idx[i], 0])+".\n";
  */
  seteuid(getuid(TP));
  if (p!="")
  {
    write(TC_BOLD"Conjuros que tienes memorizados:\n"TC_NORMAL);
    STR->smore(p,TP->QueryPageSize());
  }
  else return notify_fail("No conoces ningún conjuro.\n");
  return 1;
}
