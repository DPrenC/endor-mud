/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 16-11-98              |
 |            Ultima Modificacion........23-02-99              |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <moving.h>


inherit THING;

int cuerda_atada;

create() {
 ::create();
 cuerda_atada=0;
 SetShort("una gran roca");
 SetIds(({"roca","piedra","gran roca","roca enorme"}));
 SetValue(0); // Aunque la cogieras.. no ibas a sacar mucha pasta ;)
 Set(P_NOGET,"La roca pesa demasiado para que puedas cogerla.");
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
}

init(){
::init();
 add_action("_atar","atar");
 add_action("_atar","anudar");
 add_action("_desatar","desatar");
 add_action("_desatar","cortar");
 add_action("_desatar","desanudar");
 add_action("_bajar","bajar");
 add_action("_bajar","saltar");
 add_action("_bajar","descender");
}

QueryLong()
{
if (!cuerda_atada)
  return
"Ante ti tienes una roca enorme situada a escasos metros del acantilado. Igual\n\
si consigues una cuerda lo suficientemente larga pudieras atarla a la roca para\n\
poder bajar a la playa.\n";
else
   return
"Ante ti tienes una roca enorme situada a escasos metros del acantilado con\n\
una cuerda fuertemente atada a su alrededor.\n";
}

_desatar(string str)
{
int i;
mixed *armas;
object arma_cortante,cuerda;

 if (!str)
  return notify_fail("¿Qué es lo que quieres "+query_verb()+"?\n"),0;
 if (str!="cuerda de la roca" && str!="cuerda de roca" &&
     str!="cuerda enorme de roca" && str!="cuerda roca" &&
     str!="cuerda" && str!="cuerda enorme")
 return notify_fail("No entiendo que quieres "+query_verb()+".\n"),0;

 if (!cuerda_atada || !cuerda=present("cuerda",ENV(TP)))
  return notify_fail("No ves ninguna cuerda que puedas "+query_verb()+".\n"),0;
 armas=TP->QueryWeapons();
  if (!armas || armas==({}))
   if (query_verb()=="cortar")
      return notify_fail("Quizás si tuvieras una arma cortante lo podrias conseguir.\n"),0;
   else
      return notify_fail("La cuerda está fuertemente atada y resulta casi imposible de "+query_verb()+
                         ".\nQuizás si tuvieras una arma cortante lo podrias conseguir.\n"),0;

 for (i=0;i<sizeof(armas);i++)
 {
  if (armas[i]->QueryDamType()==DT_SLASH)
    arma_cortante=armas[i];
 }
 if (!arma_cortante)
  return notify_fail("Quizás si tuvieras una arma cortante lo podrias conseguir.\n"),0;
 else
 {
  write("Cortas la cuerda con "+arma_cortante->QueryShort()+".\n");
  write("La cuerda cae por el acantilado y se engancha en una roca.\n");
  cuerda->remove();
  cuerda_atada=0;
  return 1;
 }
 return 0;
}

_atar(string str)
{
 object cuerda;

 if (!str)
  return notify_fail("¿Qué es lo que quieres atar?\n"),0;

 if (str=="cuerda" || str=="cuerda larga" || str=="enorme cuerda")
  return notify_fail("¿Dónde quieres atar la cuerda?\n"),0;

 if (str=="cuerda a la roca" || str=="cuerda en la roca" ||
     str=="cuerda enorme a la roca" || str=="cuerda en roca" ||
     str=="cuerda roca" || str=="cuerda a roca")
 {
  if (!cuerda=present("cuerda",TP))
   return notify_fail("No tienes ninguna cuerda.\n"),0;
  else
  {
   cuerda->move(ENV(TO),M_SILENT);
   cuerda->SetShort("una cuerda atada a la roca");
   cuerda->SetLong("Ves una cuerda atada a la roca y que cae por el acantilado.\n");
   cuerda->Set(P_NOGET,"La cuerda está fuertemente atada a la roca y no puedes cogerla.\n");
   write("Atas una cuerda a la roca.\n");
   cuerda_atada=1;
   return 1;
  }
 }
 return 0;
}

_bajar(string str)
{
 if (!cuerda_atada)
   return notify_fail("No querrás lanzarte por el acantilado, ¿no?.\n"),0;

 if ( ME_OK!=TP->move(ACANTILADO("playa_barco"),M_SILENT))
   return notify_fail("Por alguna extraña razón no puedes bajar.\n"),0;

 write("Consigues bajar por la cuerda hasta la playa.\n");
 tell_room(environment(TO),CAP(TNAME)+" consigue bajar por la cuerda hasta la playa.\n");
 return 1;
}


