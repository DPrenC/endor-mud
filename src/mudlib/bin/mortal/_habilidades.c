/* SIMAURIA '/bin/mortal/_habilidades.c'
   =====================================

   [t] Theuzifan
   [h] Nyh
   11-12-98 [t] Creación
   10-03-99 [t] Separo los skills de gremio de los de player
   23-07-99 [t] Separo la clasificación de los skills en Personaje, Gremio
   		y Miscelaneo.
   26-10-99 [t] Quito el nivel exacto del spell... con que sepan el
   		string les basta.
   25-11-99 [t] Adecuado al nuevo sistema de Gremios. Reformateada la salida.
   02-03-00 [w] Corregido una cosa con el color, que fasllaba.
   28-03-00 [w] Ajustado mejor, ya que el casi perfecto aparecia en otra linea.
   06-04-00 [w] Puesta una proteccion para el caso 'excepcional' que haya un 0
                donde no toca... como era el caso de Tarod.
   13-06-00 [t] Corregida la 'division by zero' en la línea 85 aprox...
   09-11-03 [h] Quito las frases y pongo numeros, que los pj se vuelven locos.
*/

#include <skills.h>
#include <properties.h>
#include <colours.h>
#include <wizlevels.h>

object jugador;
/*
string nivel(int n)
{
  if (!n || n<0) return "desastroso";
  if (n>100) return "perfecto";
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
  mapping sk;
  mixed *idx;
  string g, p, o, nivel;
  int i, j, k, l;

  p=g=o="";
  j=k=l=0;

  if (!w) jugador=TP;
  else
    if (!IS_LEARNER(TP)) jugador=TP;
    else
    {
     if (!jugador=find_object(lower_case(w))) return notify_fail("No existe ese jugador..\n"),0;
     else
     {
      write("Mostrando las habilidades de "+capitalize(w)+"...\n");
     }
  }

  sk=jugador->QuerySkills();
  if (!sk || sizeof(sk)==0) return notify_fail("No tienes ninguna habilidad.\n");
  idx=m_indices(sk);
  for (i=0; i<sizeof(idx); i++)
  {
    int max;

    max=sk[idx[i],1];
    if (max<1) max=1;

    nivel = STR->radjust(to_string(sk[idx[i], 0]),3," ")+"/"+STR->radjust(to_string(max),3," ");

//lo nuevo...
    if (jugador->SkillIsEnabled(idx[i])) {
      if (member(HABILIDADES, jugador->QueryGuild()) && member(HABILIDADES[jugador->QueryGuild()], idx[i])!=-1) {
        if (!(k%2)) g+=sprintf("%-42s", "  "+STR->ladjust(idx[i]+" ",23,".")+" "+nivel);
        else if (!sk[idx[i],1]) g+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel+"\n";
        else g+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel+"\n";
        k++;
      }
      else if (member(HAB_GENERALES, idx[i])!=-1) {
        if (!(j%2)) p+=sprintf("%-42s", "  "+STR->ladjust(idx[i]+" ",23,".")+" "+nivel);
        else p+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel+"\n";
        j++;
      }
      else {
        if (!(l%2)) o+=sprintf("%-42s", "  "+STR->ladjust(idx[i]+" ",23,".")+" "+nivel);
        else o+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel+"\n";
        l++;
      }
    }
  }

/* // lo viejo
    if (jugador->SkillIsEnabled(idx[i])) {
      if (member(HABILIDADES, jugador->QueryGuild()) && member(HABILIDADES[jugador->QueryGuild()], idx[i])!=-1) {
        if (!(k%2)) g+=sprintf("%-42s", "  "+STR->ladjust(idx[i]+" ",23,".")+" "+nivel((sk[idx[i], 0]*100)/max));
        else if (!sk[idx[i],1]) g+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel((sk[idx[i], 0]*100)/1)+"\n";
        else g+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel((sk[idx[i], 0]*100)/max)+"\n";
        k++;
      }
      else if (member(HAB_GENERALES, idx[i])!=-1) {
        if (!(j%2)) p+=sprintf("%-42s", "  "+STR->ladjust(idx[i]+" ",23,".")+" "+nivel((sk[idx[i], 0]*100)/max));
        else p+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel((sk[idx[i], 0]*100)/max)+"\n";
        j++;
      }
      else {
        if (!(l%2)) o+=sprintf("%-42s", "  "+STR->ladjust(idx[i]+" ",23,".")+" "+nivel((sk[idx[i], 0]*100)/max));
        else o+=STR->ladjust(idx[i]+" ",23,".")+" "+nivel((sk[idx[i], 0]*100)/max)+"\n";
        l++;
      }
    }
  }
*/
  if (p!="")
  {
    write(TC_BOLD+"Habilidades de Personaje:\n"+TC_NORMAL);
    STR->smore(p,TP->QueryPageSize());
  }
  if (g!="")
  {
    write(TC_BOLD+"Habilidades de Gremio:\n"+TC_NORMAL);
    STR->smore(g,TP->QueryPageSize());
  }
  if (o!="")
  {
    write(TC_BOLD+"Habilidades Misceláneas:\n"+TC_NORMAL);
    STR->smore(o,TP->QueryPageSize());
  }
  return 1;
}
