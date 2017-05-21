/* SIMAURIA '/bin/mortal/_hora.c'
   ==============================.
*/

#include <config.h>    //Por DAY_LENGTH
#include <nightday.h>  //Por las ctes. de tiempo y NIGHTDAY
//#define GAMECLOCK "/obj/gameclock"

int main(string str)
{
int tmp;
string msg;

seteuid(getuid());
if (!find_object(NIGHTDAY)&&!load_object(NIGHTDAY)) {
  notify_fail("No puedes ver si es de noche o de día.\n");
  return 0;
  }

tmp=(int)NIGHTDAY->QueryState();
if (environment(TP) && (!environment(TP)->QueryIndoors() || (environment(TP)->QueryIndoors()==1 && TP->QueryRazabase()=="elfo")))
{
  switch (tmp) {
    case ND_NIGHT   : {msg= "Es noche cerrada.";break;}
    case ND_PREDAWN : {msg= "La noche envejece y el alba se aproxima.";break;}
    case ND_DAWN    : {msg= "el alba hace palidecer el cielo oriental.\n";break;}
    case ND_SUNRISE : {msg= "está amaneciendo.\n";break;}
    case ND_PRENOON : {msg= "es plena mañana.\n";break;}
    case ND_DAY     : {msg= " es mediodía.\n";break;}
    case ND_POSTNOON: {msg= "es por la tarde.\n";break;}
    case ND_PREFALL : {msg= "ya es media tarde.\n";break;}
    case ND_FALL    : {msg= "está cayendo la noche.\n";break;}
    case ND_PRENIGHT: {msg= "la noche ha caído casi por completo.";break;}
    default: msg= "";
    }
  return write("En esta zona de Arda"+msg+"\n"),1;
}
else
{
  /* switch (tmp) {
    case ND_NIGHT   : {msg= "ser de noche.";break;}
    case ND_PREDAWN : {msg= "ser de noche, con el alba cercana.";break;}
    case ND_DAWN    : {msg= "ser el alba";break;}
    case ND_SUNRISE : {msg= "estar amaneciendo.";break;}
    case ND_PRENOON : {msg= "ser media mañana.";break;}
    case ND_DAY     : {msg= "ser mediodia.";break;}
    case ND_POSTNOON: {msg= "ser por la tarde.";break;}
    case ND_PREFALL : {msg= "ser media tarde.";break;}
    case ND_FALL    : {msg= "estar anocheciendo.";break;}
    case ND_PRENIGHT: {msg= "ser casi de noche.";break;}
    default: msg= "";
    }
  return write("Estás bajo techo pero debe "+msg+"\n"),1;
  */
  return write("No tienes capacidad para saber en que momento del día o de la noche te encuentras.\n"),1;
}

return 1;
}
