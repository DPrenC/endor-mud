/* SIMAURIA '/lib/rwebwho.c'
   ========================
   [w] Woo@simauria
   [G] Gorthem@simauria
   [m] Mirill@Simauria

   10-09-99 [w] Creación: Este archivo contiene el mensaje de retorno
                del rquien/rwho.
   11-09-99 [w] Ya devuelve los datos el who.
   16-09-99 [w] Cambiada la devolución del quien.
   11-04-00 [G] Cambia le formato para el J-sim.
   16-06-00 [m] Basandose en lo anterior, modifico el formato para devolverlo
   		por la web.
   08-09-00 [m] Arreglo un bug por el que si no hay wizards,
                devuelve una lista vacia.
   22-10-01 [m] Vuelto a arreglar para que aparezcan los councilers
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

private int pornivel(object a, object b) {
  int i1, i2;
  i1 = query_wiz_level(a) || a->QueryLevel();
  i2 = query_wiz_level(b) || b->QueryLevel();
  return i1 < i2;
}

public string Quien()
{
 string str;
 int i, level;
 mixed *wizards, *jugadores;
 object *conectados;

 wizards = ({ });
 jugadores = ({ });
// conectados = sort_array(users(), SF(ordenar));
 conectados = sort_array(users(), SF(pornivel));
 for (i = 0; i < sizeof(conectados); i++)
 {
  string nombre, titulo, nivel, pais, sexo;

  // [w] Eliminamos a los invisibles, a los que entran y al gopher.
  if (!conectados[i]->QueryInvis() && geteuid(conectados[i])!="ze/us" &&  geteuid(conectados[i])!="gopher")
  {
    nombre = capitalize(conectados[i]->QueryRealName());
    level = query_wiz_level(conectados[i]);
    switch (level) {
    case 1..WIZARD_LVL-1:
    	nivel = "W"+level;
    	titulo = "Learner";
    	break;
    case WIZARD_LVL..VICE_LVL-1:
    	nivel = "W"+level;
    	titulo = "Wizard";
    	break;
    case VICE_LVL..LORD_LVL-1:
    	nivel = "W"+level;
    	titulo = (conectados[i]->QueryGender()==2?"ViceLady":"ViceLord");
    	break;
    case LORD_LVL..ARCH_LVL-1:
    	nivel = "W"+level;
    	titulo = (conectados[i]->QueryGender()==2?"Lady":"Lord");
    	break;
    case ARCH_LVL..CON_LVL-1:
    	nivel = "W"+level;
    	titulo = "Archwiz";
    	break;
    case CON_LVL..GOD_LVL-1:
    	nivel = "W"+level;
    	titulo = "Counciler";
    	break;
    case GOD_LVL..256:
    	nivel = "W"+level;
    	titulo = "God";
    	break;
    default:
    	nivel = to_string(conectados[i]->QueryLevel());
      	titulo = capitalize((conectados[i]->QueryGuild()||"sin gremio"));
    }

    pais = PAIS(conectados[i]);
    if (pais == "Desconocida") pais = "Desconocida";
    sexo = (conectados[i]->QueryGender()==2?"F":"M");

    if (IS_LEARNER(conectados[i]))
      wizards += ({ ({ nombre, nivel, titulo, pais, sexo }) });
    else
      jugadores += ({ ({ nombre, nivel, titulo, pais, sexo }) });
  }
 }


 str="\n";

/* Esto es de lo mas sencillo, se corta por %SEP% y lo que quede arriba son wizards y lo de abajo players.
Los simbolos (;) son para parsear mejor la cadena. De esta manera tenemos unos 900
caracteres para la lista de jugadores y wizards con el volumen actual de
simauria no deberiamos tener problemas. Si alguna vez necesitamos más, se puede
partir la petición con un comando para wizs y otro para jugadores. */

if (sizeof(wizards) || sizeof(jugadores))
 {
 if (sizeof(wizards))
 {
   for (i=0;i<sizeof(wizards);i++)
   {
      str += wizards[i][0]+";"+wizards[i][1]+";"+wizards[i][2]+";"+wizards[i][3]+";"+wizards[i][4]+".\n";
   }
 }
 str += "%SEP%\n";
 if (sizeof(jugadores))
 {
   for (i=0;i<sizeof(jugadores);i++)
   {
    str += jugadores[i][0]+";"+jugadores[i][1]+";"+jugadores[i][2]+";"+jugadores[i][3]+";"+jugadores[i][4]+".\n";
   }

}
 if (!sizeof(wizards) && !sizeof(jugadores))
 {
   str += "Nadie";
 }

 }

// write(str+"\n");
// return "";
 return str+"\n";
}