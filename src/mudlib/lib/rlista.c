/* SIMAURIA '/lib/rlista.c'
   ========================
   [w] Woo@simauria
   [G] Gorthem@simauria

   10-09-99 [w] Creación: Este archivo contiene el mensaje de retorno
                del rquien/rwho.
   11-09-99 [w] Ya devuelve los datos el who.
   16-09-99 [w] Cambiada la devolución del quien.
   11-04-00 [G] Cambia le formato para el J-sim.
*/

#include <wizlevels.h>
#include "/secure/config.h"

#define PAIS(x) "/lib/country"->country(x)

private int ordenar(object a, object b)
{
  string s1, s2;
  s1 = a->QueryRealName() || "";
  s2 = b->QueryRealName() || "";
  return s1 > s2;
}

public string Quien()
{
 string str;
 int i;
 mixed *wizards, *jugadores;
 object *conectados;

 wizards = ({ });
 jugadores = ({ });
 conectados = sort_array(users(), SF(ordenar));

 for (i = 0; i < sizeof(conectados); i++)
 {
  string nombre, nivel, pais, sexo;

  // [w] Eliminamos a los invisibles, a los que entran y al gopher.
  if (!conectados[i]->QueryInvis() && geteuid(conectados[i])!="ze/us" &&  geteuid(conectados[i])!="gopher")
  {
    nombre = capitalize(conectados[i]->QueryRealName());
    pais = PAIS(conectados[i]);
    if (pais == "Desconocida") pais = "Unknown";
    if (query_wiz_level(conectados[i])==LEARNER_LVL) nivel = "Learner";
    if (query_wiz_level(conectados[i])==WIZARD_LVL) nivel = "Wizard";
    if (query_wiz_level(conectados[i])==25) nivel = "Wizard";
    if (query_wiz_level(conectados[i])==ARCH_LVL) nivel = "Archwiz";
    if (query_wiz_level(conectados[i])==GOD_LVL) nivel = "God";
    if (query_wiz_level(conectados[i])==VICE_LVL) nivel = (conectados[i]->QueryGender()==2?"ViceLady":"ViceLord");
    if (query_wiz_level(conectados[i])==LORD_LVL) nivel = (conectados[i]->QueryGender()==2?"Lady":"Lord");
    if (!IS_LEARNER(conectados[i])) nivel = "Level "+conectados[i]->QueryRealLevel();

    sexo = (conectados[i]->QueryGender()==2?"(F)":"(M)");

    if (IS_LEARNER(conectados[i]))
      wizards += ({ ({ nombre, nivel, pais, sexo }) });
    else
      jugadores += ({ ({ nombre, nivel, pais, sexo }) });
  }
 }


 str=" ";

/* Esto es de lo mas sencillo, @ indicara Wizard, # Player, todo en una lista.
los simbolos son para parsear mejor la cadena. De esta manera tenemos unos 900
caracteres para la lista de jugadores y wizards con el volumen actual de
simauria no deberiamos tener problemas */

if (sizeof(wizards) || sizeof(jugadores))
 {
 if (sizeof(wizards))
 {
   for (i=0;i<sizeof(wizards);i++)
   {

      str += " @ "+STR->ladjust(wizards[i][0],14,".")+STR->ladjust("["+wizards[i][1]+"]",11," ");
   }
 } else str+= "@";

 if (sizeof(jugadores))
 {
   for (i=0;i<sizeof(jugadores);i++)
   {
      str += " # "+STR->ladjust(jugadores[i][0],14,".")+STR->ladjust("["+jugadores[i][1]+"]",11," ");
  }
 } else str += "#";
/* if (!sizeof(wizards) && !sizeof(jugadores))
 {
   str += "Nadie";

 }*/
}
// write(str+"\n");
// return "";
 return str+"\n";
}
