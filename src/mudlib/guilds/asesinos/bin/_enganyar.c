#include "/guilds/asesinos/sys/asesinos.h"

#include <moving.h>
#include <wizlevels.h>
#include <rooms.h>
#define COMMAND_NAME	HAB_ENGANYAR
#define MANA_COST	MANA_ENGANYAR// coge la lista del atributo engan

void GoBack(object ob)
{
    string *enganyado;
    string *msgin, *msgout;
    int msgcambiado;

    
    if(!ob) return;
    if(ob->Fighting())
    {
        call_out("GoBack",30,ob);
        return;
    }
    enganyado = ob->Query("enganyado");
    if (pointerp(enganyado) && sizeof(enganyado))
    {
        if (!query_once_interactive(ob) && !ob->QueryGoChance())
        // los players o los pnjs que tengan GoChance no se mueven de vuelta
        {
            if (member(RACEMASTER->AllPlayerRaceNames(), ob->QueryRace() || "") >= 0)
            // cambiamos los mensajes de que llega y se va
            {
                tell_object(ob, "Algo confus" + ob->QueryGenderEndString() + " te preguntas qué estás haciendo "
                                "por aquí. Encogiéndote de hombros, decides volver por donde habías venido.\n");
                msgin = ob->QueryMsgIn();
                msgout = ob->QueryMsgOut();
                ob->SetMsgOut(({"se va confus" + ob->QueryGenderEndString(), "Alguien se va"}));
                ob->SetMsgIn(({"llega confus" + ob->QueryGenderEndString(), "Alguien llega"}));
                msgcambiado = 1;
            }
            if (command(enganyado[<1], ob)) ob->Set("enganyado", enganyado[..<2]);
            if (sizeof(enganyado)) call_out("GoBack", 30, ob);
            if (msgcambiado)
            {
                ob->SetMsgIn(msgin);
                ob->SetMsgOut(msgout);
            }

        }
        else
        {
            if (enganyado && sizeof(enganyado)) ob->Set("enganyado", enganyado[..<2]);
            tell_object(ob, "Te sientes algo confus" + ob->QueryGenderEndString() + ". " + 
                        "Sacudes la cabeza y te despejas un poco\n");
        }
    }



}


string ExitName(string str)
{
   switch(str)
   {
      case "norte":
      case "sur":
      case "este":
      case "oeste":
      case "noreste":
      case "nordeste":
      case "noroeste":
      case "sureste":
      case "sudeste":
      case "suroeste":
      case "sudoeste":
         return "el "+str;
         break;
   }
   return str;
}

public int main(string str)
{
    object *all, *livings, target, room, env;
    string who, exit, ExitName, exit_back;
    string *exits;
    mixed *enganyado;
    mapping AllExits;
    int count, check, check_skill, i, int_tp, int_victim;


    if(TP->HasSkill(COMMAND_NAME) != 1) return 0;

    if(!str)
        return notify_fail(W("Uso:   engañar a <nombre> hacia <salida>\n"
                             "       engañar desde <salida>\n"));

    if(sscanf(str,"a %s hacia %s",who,exit) != 2 && sscanf(str,"desde %s",exit) != 1)
        return notify_fail(W("Uso:   engañar a <nombre> hacia <salida>\n"
                             "       engañar desde <salida>\n"));

    if(who && exit)
    {
        exits = map((env = environment(TP))->ExitList()[0], (:pointerp($1) ? $1[0] : $1:));
        
        exit = env->map_normal_exit(exit);      
        if (who && member(exits, exit) == -1)
            return notify_fail("Esa salida no existe.\n");

        target=present(who, environment(TP));
        if(!target ||!TP->CanSeeObject(target))
            return notify_fail(W("No ves a "+capitalize(who)+" a tu alrededor.\n"));
        
        if(IS_LEARNER(target) && !IS_LEARNER(TP) )
            return notify_fail(W("No podrás engañar a un wizard.\n"));

      if(!living(target))
            return notify_fail(W("Intentas engañar a ese objeto inanimado, pero fallas.\n"));

        if((time()-TP->Query("_last_lure"))<TIMER_ENVIAR && !query_wiz_level(TP))
        {
            return notify_fail(W("Tendrás que esperar antes de volver a intentarlo.\n"));
        }
        if (query_once_interactive(target) && IS_BEGINNER(target))
        // ¡no se puede engañar a los nobatos!
        {
            log_file("TRY_LURE", ctime() + ". " + TNREAL + " intentó engañar al novato " + NREAL(target) + ".\n");
            return notify_fail("¡No puedes engañar a los novatos!\n");
        }
        if (query_wiz_level(target) || target->QueryAggressive() || target->Query(P_CANT_LURE))
        // A los agresivos no se les puede engañar, cuestión de seguridad, y a los que
        // tienen el CantLure a 1, tampoco.
        {
            return notify_fail("No puedes engañar a " + NNAME(target) + ".\n");
        }
        check = (int_tp = TP->QueryInt()) - (int_victim = target->QueryInt());
        check += (TP->QueryGuildLevel() - target->QueryGuildLevel()) / 2;
        check *= 3;
        // 10 puntitos menos por cada vez que este bicho haya sido engañado y no se haya recuperado
        if ((enganyado = target->Query("enganyado")) && pointerp(enganyado))
        {
            check -= (sizeof(enganyado) * 10);
        }
        check_skill = TP->UseSkill(COMMAND_NAME);
        if (check_skill < -70) check = check_skill;
        else check += check_skill;
        TP->SetAttribute("_last_lure", time());
        if(check < -40)
        // no puede engañarle
        {
            write(W("Intentas engañar a "+capitalize(who)+", pero no consigues convencerle.\n"));
            if(interactive(target))
            {
                tell_object(target,W(TNAME+" intenta persuadirte para que vayas hacia " + ExitName(exit)+".\n"));
                call_out("command",1,"reir "+getuid(TP),target);
            }
            else
            {
                write(W(capitalize(who)+" se ríe de tí.\n"));
                call_out("say",1,W(target->QueryName()+" se ríe de "+TNAME+".\n"));
            }
        }
        else if(check <= 0)
        {
            write(W("Intentas engañar a "+capitalize(who)+", pero fallas.\n"));
            tell_object(target, TNAME + " intenta convencerte para que vayas hacia " + (ExitName = ExitName(exit)) + " " + 
                        "pero no lo consigue.\n");
            say(TNAME + " intenta convencer a " + NNAME(target) + " para que vaya hacia " + ExitName +
                ", pero no lo consigue.\n", ({target, TP}));
        }
        else
        {
            string *msgin = target->QueryMsgIn(), *msgout = target->QueryMsgOut();
            write(W("Engañas a "+ CAP(NNAME(target)) +" para que vaya hacia " +
                  (ExitName = ExitName(exit)) + ".\n"));
            tell_object(target,TNAME+" te convence para que vayas hacia "+ExitName(exit)+".\n");
            target->SetMsgIn(({"llega con la mirada estraviada", "Alguien llega"}));
            target->SetMsgOut(({"se va distraídamente", "Alguien se va"}));
            if (   command(exit, target) > 0
                || (stringp((AllExits = env->QueryExits())[exit]) && !AllExits[exit, EXIT_DOOR] && target->move(AllExits[exit], M_GO, exit) == ME_OK))
            {
                if (exit_back = env->BackExit(exit))
                {
                    if (enganyado && pointerp(enganyado)) enganyado += ({exit_back});
                    else enganyado = ({exit_back});
                    target->Set("enganyado", enganyado);
                }
                call_out("GoBack",TIME_HOME,target);
            }
            target->SetMsgIn(msgin);
            target->SetMsgOut(msgout);
        }
        return 1;
    }
    if(!who && exit)
    {
        mapping all_exits;
        exits = m_indices(all_exits = (env = environment(TP))->QueryExits());
        exit = env->map_normal_exit(exit);
        if(member(exits, exit) < 0)
            return notify_fail(W("La salida '"+exit+"' no existe.\n"));
        if (!stringp(all_exits[exit]))
        {
            return notify_fail("No puedes atraer a nadie a través de esa salida.\n");
        }
        if((time()-TP->Query("_last_backstab"))<TIMER_ATRAER)
        {
            if(!query_wiz_level(TP))
                return notify_fail(W("Tendrás que esperar antes de volver a intentarlo.\n"));
        }

        room = load_object(all_exits[exit]);
        if(room) all=all_inventory(room);
        count=0;
        
        for (i=sizeof(all); i--;)
        {
            if (!living(all[i]) || all[i]->QueryAggressive() || query_wiz_level(all[i]) || all[i]->Query(P_CANT_LURE)) continue;
            target=all[i];
            check = (int_tp = TP->QueryInt()) - (int_victim = target->QueryInt());
            check += (TP->QueryGuildLevel() - target->QueryGuildLevel()) / 2;
            check *= 3;
            if (enganyado = target->Query("enganyado")) check -= (sizeof(enganyado) * 10);
            // si la habilidad es demasiado desastrosa, no pasa
            if ((check_skill = TP->UseSkill(COMMAND_NAME)) < -70) check = 0;
            else check += check_skill;
            if(check <= 0)
            {
                tell_object(target,W("Oyes como alguien te llama desde algún sitio, pero no haces mucho caso.\n"));
            }
            else
            {
                string *msgin = target->QueryMsgIn(), msgout = target->QueryMsgOut();
                target->SetMsgIn(({"llega con la mirada estraviada", "Alguien llega"}));
                target->SetMsgOut(({"se va distraídamente", "Alguien se va"}));
                if (((exit_back = env->BackExit(exit)) && command(exit_back, target)) || target->move(env, M_GO, exit) == ME_OK)
                {
                    enganyado = target->Query("enganyado");
                    if (!enganyado) enganyado = ({exit});
                    else enganyado += ({exit});
                    target->Set("enganyado", enganyado);
                    call_out("GoBack",TIME_HOME,target);
                    count++;
                }
                target->SetMsgIn(msgin);
                target->SetMsgOut(msgout);
            }
        }
        if(!count)
        {
            write(W("Hmmmm. Nadie viene.\n"));
        }
        TP->Set("_last_lure",time());
        return 1;
    }
}
