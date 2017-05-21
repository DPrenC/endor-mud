/* SIMAURIA '/obj/pergamino.c'
   ===========================
   [w] Woo@simauria

   06-04-99 [w] Creación de este archivo. La única variable que puede
                cambiar es MaxCast así que uso P_AUX1 para guardarla.
                ScrollID es el nombre del hechizo que contiene y
                MaxCast es la cantidad de veces que se puede usar el
                pergamino. CanMemo sirve para indicar si puedes memorizar
                el hechizo de este scroll.
   10-04-99 [w] Terminada la parte de memorización.
   16-04-99 [w] Añadido el registro de pergaminos.
   29-05-99 [w] Añadido el identificativo QueryScroll() 1||0.
   27-09-99 [w] Añado más comprobantes a la hora de memorizarlo.
   08-10-99 [w] Le quito la función remove y lo llevo a otro lao.
   13-10-99 [w] Ahora lo hace a this_player y no a su environment.
   29-10-99 [t] Modifico el AddPlayerSpell() pa que concuerde con el
   		de verdad verdadosa.
   24-11-99 [w] Añadido el nuevo sistema de aprendizaje y la habilidad
                de memorizar.
   18-02-00 [w] Ahora los conjuros/hechizos son mas faciles de memorizar.
   11-04-00 [w] Reformado el sistema de notify_fails, cambiados por algunos
                writes ya que se hacia la picha un lio.
*/

inherit "/std/thing";
#include <properties.h>
#include <magia.h>
#include <skills.h>
#include <config.h>

string scroll_id,     // Nombre del hechizo.
       destruct_msg;  // Mensaje que aparece cuando se destruye.

int    can_memo,      // Indica si se puede memorizar de aquí.
       can_cast;      // Indica si puedes hacer el hechizo de aquí.

public string SetScrollID(string id)
{ return scroll_id=id||""; }

public string QueryScrollID()
{ return scroll_id||""; }

public int SetMaxCast(int max)
{
 if (max<1)
  Set(P_AUX1,0);
 else
  Set(P_AUX1,max);
 return Query(P_AUX1);
}

public int QueryMaxCast()
{ return Query(P_AUX1); }

public int SetCanMemorize(int can)
{ return can_memo=can||0; }

public int QueryCanMemorize()
{ return can_memo||0; }

public int SetCanCast(int can)
{ return can_cast=can||0; }

public int QueryCanCast()
{ return can_cast||0; }

public string SetDestructMsg(string msg)
{ return destruct_msg=msg||"El pergamino desaparece.\n"; }

public string QueryDestructMsg()
{ return destruct_msg||"El pergamino desaparece.\n"; }

public void Used()
{
 SetMaxCast(QueryMaxCast()-1);
 if (QueryMaxCast()<=0) {
  if (TP)
    tell_object(TP,destruct_msg);
  remove();
 }
}

public int QueryScroll()
{ return 1; }


create()
{
 seteuid(getuid());
 thing::create();
 "/obj/lib/register"->Register(TO,"PERGAMINOS");
 SetShort("un pergamino");
 SetLong("Un pergamino.\n");
 AddId("pergamino");
 SetScrollID("sinnombre");
 SetDestructMsg("El pergamino desaparece.\n");
 SetCanMemorize(1);
 SetCanCast(1);
 SetMaxCast(1);
 SetWeight(100); // [w] Un peso estándar.
}

init()
{
 ::init();
 add_action("cmd_memorizar","memorizar");
}

cmd_memorizar(str)
{
 string fichero;
 int rnd,yalotenia;
 mapping sp;

 yalotenia=0;
 if (!str) return notify_fail("¿Qué conjuro quieres intentar memorizar?\n"),0;
 str=lower_case(str);
 if (str!=lower_case(TO->QueryScrollID()))
 {
   notify_fail("No tienes nada de donde memorizar el conjuro "+str+".\n",NOTIFY_NOT_CMD);
   return 0;
 }

 if (!QueryCanMemorize())
  return write("No puedes memorizar el conjuro desde este objeto.\n"),1;

 if (!fichero=SPELL(str))
  return write("Ese tipo de conjuros está prohibido en Simauria.\n"),1;

 if (TP->HasSpell(QueryScrollID()))
 {
  sp=TP->QuerySpells();
  if (sp[str,1]>=70)
    return write("No puedes memorizar el conjuro mejor.\n"),1;
  yalotenia++;
 }

 if (fichero->QueryMemorizeLevel(TP->QueryGuild())>TP->QueryGuildLevel())
  return write("No tienes suficiente nivel para memorizar ese tipo de magia.\n"),1;

 if (TP->HasSkill(HAB_MEMORIZAR))
 {
   if (TP->UseSkill(HAB_MEMORIZAR,80)<1) {
   write("Has fallado al intentar memorizar el conjuro '"+str+"'.\n");
   call_out("Used",1);
   return 1;
   }
 }
 else if (rnd=TP->QueryInt()<20)
 {
  rnd=rnd/4;
  rnd=5-rnd;
  if (!random(rnd))
  {
   write("Has fallado al intentar memorizar el conjuro '"+str+"'.\n");
   call_out("Used",1);
   return 1;
  }
 }

 if (TP->AddPlayerSpell(str,1,70,0)<1)
  return write("No has podido memorizar el conjuro '"+str+"'.\n"),1;
 else
 {
  if (yalotenia)
   write("Has memorizado mejor el conjuro '"+str+"'.\n");
  else
   write("Has memorizado el conjuro '"+str+"'.\n");
  call_out("Used",1);
  return 1;
 }

 return 0;
}

