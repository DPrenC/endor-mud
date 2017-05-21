/* SIMAURIA '/bin/mortal/_lanzar.c'
   --------------------------------
   [w] woo@simauria
   [h] nyh@simauria
   [i] izet@simauria
   27-03-00 [w] Creado el comando para que use la habilidad 'lanzar'
   21-06-00 [w] Modificada la formula del daño, ahora es 'bastante' más
   		probable que pierdas el objeto del todo y además te
   		deja aturdido 2 segundos...
   10-04-01 [h] añade el chekeo de safe
   29-04-01 [i] Modificado el lanzar original para los asesinos. Hacia
                muy poco daño, solo el WC del arma mas un numero aleatorio
                entre 0 y 4.
*/

#include <properties.h>
#include <combat.h>
#include <wizlevels.h>
#include <skills.h>
#include <moving.h>
#include "/guilds/asesinos/path.h"
#define COMMAND_NAME HAB_LANZAR

mixed
main(string str)
{
int wc, i,acierto,tipo_danyo;
string a, b, *donde;
object que, quien;

  if (TP->HasSkill(COMMAND_NAME) != 1)
     return notify_fail(W("No tienes la habilidad 'lanzar'. Contacta con un wizard.\n"));

  if (!str)
     return notify_fail(W("¿Lanzar qué contra quién?\n"));

  if (sscanf(str,"%s contra %s",a,b)!=2)
     return notify_fail(W("¿Lanzar qué contra quién?\n"));

  if (TP->QueryStunned()>0)
  	return notify_fail(W("No puedes lanzar nada en estos instantes.\n"));

  que = present(a, TP);
  quien = present(b, environment(TP));
  if (quien->Query(P_INVIS) && !TP->Query(P_SEE_INVIS) ) quien=0;

  if (environment(TP)->QuerySafe())
     return notify_fail(W("No puedes lanzar nada aquí.\n"));

  if (!que)
     return notify_fail(W("No tienes ningún objeto que se llame '"+a+"'.\n"));

  if (!quien)
     return notify_fail(W("No puedes ver a "+b+" aquí.\n"));

  if (!living(quien))
  {
     tell_room(environment(quien),
        W(TP->QueryName()+" lanza su "+a+" contra "+
        quien->QueryShort()+" y acierta.\n"),({TP}));
     return notify_fail(W("Lanzas "+que->QueryShort()+" contra "+quien->QueryShort()+" y aciertas.\n"));
  }

  if (IS_LEARNER(quien))
     return notify_fail(W(quien->QueryName()+" es un wizard! No querrás lanzarle eso!\n"));

  if(quien->QueryGhost())
  {
     que->move(environment(TP),M_SILENT);
     return notify_fail(W("Lanzas "+que->Queryshort()+" contra el fantasma de "+quien->QueryName()+" y "+que->QueryShort()+" le atreviesa.\n"));
  }

  if (quien->Query(P_CANT_FIGHT))
     return notify_fail(W("No puedes atacar a "+capitalize(b)+".\n"));

  if (que->QueryGuildObject())
     return notify_fail(W("Tu gremio no vería con buenos ojos que lanzases eso.\n"));

  if (que->QueryNoDrop())
     return notify_fail(W("No puedes lanzar eso.\n"));

  if (que->QueryNoGive())
     return notify_fail(W("No puedes lanzar eso.\n"));

  if (!query_wiz_level(TP) && TP != quien && query_once_interactive(quien))
  // PK?
  {
    seteuid(getuid());
    log_file("TRY_PK", ctime() + ". " + TNREAL + " intentó lanzarle " + que->QueryShort() + " a " + NREAL(quien) + ".\n");
    return notify_fail("La lucha entre jugadores no está permitida.\n");
  }

  acierto=TP->UseSkill(COMMAND_NAME);
  if (acierto > 0)
  {
     tell_object(quien, W(TP->QueryName()+" te lanza "+que->QueryShort()+" y te acierta! Ouch!\n"));
     write(W("Lanzas "+que->QueryShort()+" contra "+quien->QueryName()+" y le aciertas!\n"));
     tell_room(environment(quien),W(TP->QueryName()+" lanza "+que->QueryShort()+
               " contra "+quien->QueryName()+" y le acierta!\n"),({TP,quien}));
     wc = que->QueryWC();
     wc += random(TP->QueryStr()) + (acierto/2);
     if(que->QueryDamageType()) tipo_danyo=que->QueryDamageType();
     else tipo_danyo=DT_BLUDGEON;
     if(wc > quien->QueryHP()) wc=quien->QueryHP();
     quien->Defend(wc,tipo_danyo,1);
     if (quien) TP->Kill(quien);
     if(acierto<71 || tipo_danyo==DT_BLUDGEON)
     {
        que->move(environment(TP),M_SILENT);
        write(W("Tu "+a+" cae al suelo.\n"));
        tell_room(environment(quien),
           W("El arma de "+TP->QueryName()+" cae al suelo.\n"),({TP}) );
     }
     else
     {
        donde=({"el torso","el muslo izquierdo","el muslo derecho","la cabeza",
                "el brazo derecho","el brazo izquierdo"});
        i=random(sizeof(donde));
        que->move(environment(TP),M_SILENT);
        write(W("Tu "+a+" se queda clavada en "+donde[i]+" de "+quien->QueryName()+".\n"));
        tell_object(quien,
           W("El arma de "+TP->QueryName()+" se te clava en "+
           donde[i]+".\n"));
        tell_room(environment(quien),
           W("El arma de "+TP->QueryName()+" se clava"
           " en "+donde[i]+" de "+quien->QueryName()+".\n"),({quien,TP}));
     }
     TP->SetCombatDelay(1,"Continuas lanzando.\n");
  }
  else
  {
     tell_object(quien, W(TNAME+" te lanza "+que->QueryShort()+", pero falla.\n"));
     write(W("Lanzas "+que->QueryShort()+" contra "+quien->QueryName()+" pero fallas.\n"));
     tell_room(environment(quien),W(TNAME+" lanza "+que->QueryShort()+
               " contra "+quien->QueryName()+", pero falla.\n"),({TP,quien}));
     write(W("Tu "+a+" cae al suelo.\n"));
     que->move(environment(TP),M_SILENT);
     TP->SetCombatDelay(2,"Estás lanzando...\n");
  }
  if(wc) return wc;
  else return -1;
}
