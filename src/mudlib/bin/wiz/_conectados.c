/**
 * ENDOR '/bin/wiz/_conectados.c'
   comando conectados de uso para ainur.
 */

#include <properties.h>
#include <wizlevels.h>
#include <colours.h>
#include <config.h>
#include <bandos.h>
private int pornivel(object a, object b) {
  int i1, i2;
  //i1 = query_wiz_level(a) || a->QueryLevel();
  //i2 = query_wiz_level(b) || b->QueryLevel();
  i1 =/* query_wiz_level(a) ||*/ a->QueryAge();
  i2 =/* query_wiz_level(b) ||*/ b->QueryAge();
  return i1 < i2;
}

private int poredad(object a, object b) {
  int i1, i2;
      i1 = a->QueryAge();
  i2 =b->QueryAge();
  return i1 < i2;
}

public int main() {

 string str;
 int i, conec;
 mixed *jugadores;
 object *conectados;
 string *flags;

  jugadores = ({ });
 conectados = sort_array(users(), SF(poredad));
 for (i = 0; i < sizeof(conectados); i++) {
  string nick, tmp, bando, raza, gremio, locate, estados = "";
    // [w] Eliminamos a los invisibles, a los que entran y al gopher.
  if (   geteuid(conectados[i])!="ze/us"
      && geteuid(conectados[i])!="gopher"
      && (   !conectados[i]->Query(P_INWIZ)
          || IS_LEARNER(TP)))
    {
    flags = ({});
    if (conectados[i]->Query(P_INVIS) || conectados[i]->Query(P_HIDDEN)) {
    	tmp = "invis";
    	flags += ({ tmp });
    }
    if (conectados[i]->QueryAway()) {
    	flags += ({"ausente" });
    }
        if (conectados[i]->QueryStatusSleeping()) {
        flags += ({"durmiendo"});
    }
    if (conectados[i]->Fighting()) {
        flags += ({"luchando"});
    }
if (conectados[i]->QueryGhost() || conectados[i]->QueryHP()<0) {
        tmp = "muert"+(conectados[i]->QueryGender()==GENDER_FEMALE?"a":"o");
    	    	flags += ({ tmp  });
    }

    if (query_idle(conectados[i])/60) {
    	tmp = "pasiv"+ (conectados[i]->QueryGender()==GENDER_MALE ? "o" : "a");
    	tmp += " "+query_idle(conectados[i])/60;
    	flags += ({ tmp  });
    }

switch(conectados[i]->QueryBando()){
        case P_BANDO_NEUTRO: bando="(N)"; break;
        case P_BANDO_LUZ: bando="(L)"; break;
        case P_BANDO_OSCURIDAD: bando="(O)"; break;
        default: bando="* "; break;
        }

        if (sizeof(flags)) {
    	estados += " <" + implode(flags, "/") + ">";
    }
nick = conectados[i]->QueryRealName()+" "+bando+". ";
raza = conectados[i]->QueryRace()+" "+conectados[i]->QueryLevel()+". ";
gremio = conectados[i]->QueryGuild()+" "+conectados[i]->QueryGuildLevel()+". ";
locate = environment(conectados[i])->QueryLocate()+".";
    //tmp = sprintf("%-17s", nick)+sprintf("%-17s", raza)+sprintf("%-18s", gremio)+sprintf("%-21s", locate)+sprintf("%-23#s\n", estados);
    tmp = nick+raza+gremio+locate+estados+"\n";
        	if (!IS_LEARNER(conectados[i]))
            	jugadores += ({ tmp });
      }
 }
 str="";
 conec = sizeof(jugadores);
if (!sizeof(jugadores)) {
   str += "\n";
   str += " ================================================================\n";
   str += "                    [      La Tierra Media está deshabitada.      ]\n";
   str += " ================================================================\n";
 }
 else
 {
      str += "\n\t"+(conec==0 ? "Ningún" : (conec==1 ? "Un" : capitalize(itoa(conec)))) +
     (conec<2 ? " jugador está conectado" : " jugadores están conectados")+".\n";
              }

 if (sizeof(jugadores)) {
      foreach(string s:jugadores) str += s;
 }
 STR->smore(str, TP->QueryPageSize());
 return 1;
}
