/**
 * ENDOR '/bin/mortal/_conectados.c'
   mismo comando  que el quien.c
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
 int i, conec, level;
 mixed *ainur, *jugadores;
 object *conectados;
 string *flags;

 ainur = ({ });
 jugadores = ({ });
 conectados = sort_array(users(), SF(poredad));
 for (i = 0; i < sizeof(conectados); i++) {
  string nombre, titulo, nivel, tmp, color, bando;
  // [w] Eliminamos a los invisibles, a los que entran y al gopher.
  if (   geteuid(conectados[i])!="ze/us"
      && geteuid(conectados[i])!="gopher"
      && (   !conectados[i]->Query(P_INWIZ)
          || IS_LEARNER(TP)))
    {
    if (conectados[i]->QueryPresay()) {
    	nombre = conectados[i]->QueryPresay()+" ";
    }
    else {
    	nombre = "";
    }
    flags = ({});
    if (conectados[i]->Query(P_INWIZ)) {
    	tmp = "inwiz";
    	flags += ({ tmp });
    }
    if (conectados[i]->QueryAway()) {
    	flags += ({"ausente" });
    }
        if (conectados[i]->QueryStatusSleeping()) {
        flags += ({"durmiendo"});
    }
if (conectados[i]->QueryGhost() || conectados[i]->QueryHP()<0) {
        tmp = "muert"+(conectados[i]->QueryGender()==GENDER_FEMALE?"a":"o");
    	    	flags += ({ tmp  });
    }
    if (query_idle(conectados[i])/60) {
    	tmp = "pasiv"+(conectados[i]->QueryGender()==GENDER_FEMALE?"a":"o");
    	tmp += " " + query_idle(conectados[i])/60;
    	flags += ({ tmp  });
    }
    if (conectados[i]->QueryTitle() != "") {
    	nombre +=""+TC_BOLD+capitalize(conectados[i]->QueryRealName())+TC_BOLD_OFF+" "+TC_ITALIC+capitalize(conectados[i]->QueryTitle())+TC_NORMAL;
    }
switch(conectados[i]->QueryBando()){
        case P_BANDO_NEUTRO: bando="(N)"; color = P_BANDO_COLOR_NEUTRO; break;
        case P_BANDO_LUZ: bando="(L)"; color = P_BANDO_COLOR_LUZ; break;
        case P_BANDO_OSCURIDAD: bando="(O)"; color = P_BANDO_COLOR_OSCURIDAD; break;
        default: bando="* "; color = TC_NORMAL; break;
        }
nivel = "";
    level = query_wiz_level(conectados[i]);
    switch (level) {
    case 1..WIZARD_LVL-1:
    	 titulo = "Maia";
    	break;
    case LORD_LVL..CON_LVL-1:
    	    	titulo = (conectados[i]->QueryGender()==GENDER_FEMALE?"Heralda":"Heraldo");
    	break;
    case CON_LVL..GOD_LVL-1:
    	    	titulo = (conectados[i]->QueryGender()==GENDER_FEMALE?"Valie":"Vala");
    	    	break;
    case GOD_LVL..256:
    	    	titulo = "Aratar";		break;

    default:
    	      	titulo = ""+conectados[i]->QueryRace();
    }
        if (sizeof(flags)) {
    	nombre += TC_NORMAL+" <" + implode(flags, "/") + ">";
    }

    tmp = (TP->QueryTiflo()==1 ? sprintf("%-4s", bando) : "* ")+ color+sprintf("%-13s", titulo)+" -"+sprintf(" %-55#s\n", nombre);
    if (IS_LEARNER(conectados[i])) {
    	ainur += ({ tmp });
    }else {
    	jugadores += ({ tmp });
    }
  }
 }
 str="";
 conec = sizeof(jugadores);
if (!sizeof(ainur) && !sizeof(jugadores)) {
   str += "\n";
   str += " ================================================================\n";
   str += "                    [      La Tierra Media está deshabitada.      ]\n";
   str += " ================================================================\n";
 }
 else
 {
   str += (TP->QueryTiflo()==1 ? "\n" : "\n"+TC_CYAN+TC_BOLD+"      ||============ENDOR-MUD=====>>>"+TC_NORMAL+"\n");
   str += "\n\t"+TC_PURPLE+(conec==0 ? "Ningún" : (conec==1 ? "Un" : capitalize(itoa(conec)))) +
     (conec<2 ? " ser mortal vaga" : " seres mortales vagan")+" por Arda en estos momentos."+TC_NORMAL+"\n";
             str += TC_YELLOW+" ..............................==============.............................. "TC_NORMAL+"\n";
 }

 if (sizeof(jugadores)) {
   str += "\n"+TC_BOLD+" >>>>>>>>>>>>>>>>>>· HIJOS DE ILÚVATAR ·<<<<<<<<<<<<<<<<<<<<<<<<<<< "+TC_NORMAL+"\n";
   foreach(string s:jugadores) str += s;
 }

if (!sizeof(ainur)) {
    str += TC_YELLOW+" ..............................==============.............................. "TC_NORMAL+"\n";
    str += TC_PURPLE+"\n\t Tus sentidos mortales no son capaces de advertir la presencia de ningún Señor de Arda."+TC_NORMAL+"\n";
    }else{
   str += "\n"+TC_BOLD+" >>>>>>>>>>>>>>>>>>>>>>>· AINUR ·<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< "+TC_NORMAL+"\n";
   foreach(string s:ainur) str += s;
 }
    str += (TP->QueryTiflo()==1 ? "\n" : "\n                           "+TC_CYAN+TC_BOLD+" <<=====================||"+TC_NORMAL+"\n");
 STR->smore(str, TP->QueryPageSize());
 return 1;
}
