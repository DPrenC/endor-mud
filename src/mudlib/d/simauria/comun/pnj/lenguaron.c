/***************************************************************************************
 ARCHIVO:   lenguaron.c
 AUTOR:     [k] Karu
 FECHA:     21-03-2002
 COMENTARIOS:   Un lenguaron
 ***************************************************************************************/

#include <skills.h>
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>

inherit NPC;

string powner;

public void SetOwner(string name) { powner = name; }

public string QueryOwner() { return powner; }


private string desc_larga()
{
    string generico = "Es un lenguarón. Te recuerda a un cruce entre una ardilla "
                      "y un lemur. Tiene el pelaje marrón y muy suave, sus grandes ojos "
                      "y orejas se mueven constantemente. ";
    object env = environment();
    if (!env || !living(env))
    {
        return generico + "Siempre está alerta y te parece muy escurridizo. Si quieres "
               "hacerte con él tal vez necesites algo más que un arma.\n";
    }
    else if (env == TP)
    {
        return generico + "Lo sientes temblar, mientras te mira con ojillos temerosos.\n";
    }
    return generico + "Mira a " + CAP(NNAME(env)) + " con ojillos temerosos.\n";
}


create(){
  ::create();
  SetStandard("un lenguarón","animal",2,GENERO_MASCULINO);
  SetIds(({"lenguarón","lenguaron","bicho"}));
  SetShort("un lenguarón");
  SetLong(SF(desc_larga));
  SetSize(P_SIZE_SMALL);
  SetWhimpy(20);
  SetWeight(200);
  InitAChats(10,({"El lenguarón hace ruidos extraños: hi, hi, hiei, hi\n",
          "El lenguarón hace ruidos extraños: grrrr, grrrr\n",
          "El lenguarón hace ruidos extraños: niu, ñiui, nyau\n"}));
  SetHands(({({"pata delantera derecha",1,5}),({"pata delantera izquierda",1,5}),({"los dientes",1,8})}));
  SetNoGet(0);

}

public void init()
{
    ::init();
    if (environment() == TP) return;
    add_action("cmd_cazar", "cazar");
    add_action("cmd_cazar", "atrapar");
}

int cmd_cazar(string str)
{
    if (member(QueryIds(), str) < 0)
    {
        return notify_fail("¿" + CAP(query_verb()) + " qué?\n", NOTIFY_NOT_VALID);
    }
    return TP->command_me("coger " + str);
}

    public varargs int move(mixed dest, int method, mixed extra)
{
    object cable;
    object env, pl;
    int val;


    if (!(pl = TP)) return ::move(dest, method, extra);
    env = environment();

    if (method == M_DROP && env == pl)
    {
        call_out("escapar", 1);
        return ::move(dest, method, extra);
    }
    if (method == M_GIVE && env == pl)
    {
        write("Cuando el lenguarón va a cambiar de manos, hace un "
                 "movimiento brusco y se escabulle hacia el suelo.\n");
        call_out("escapar",1);
        ::move(environment(TP), M_DROP);
        return ME_NO_GIVE;
    }
    if (method != M_GET) return ::move(dest, method, extra);
    if (!(cable = present("cable para cazar", TP)) || !cable->QueryEquipped())
    {
        write("Intentas coger el lenguarón con las manos, pero se te escabulle con "
        "facilidad.\n");
        tell_room(environment(), ({MSG_SEE, CAP(TNAME) + " intenta coger un lenguarón "
                                      "con las manos, pero se le escabulle.\n"}), ({pl}));
        return ME_NO_GET;
    }

    if (TP->UseSkill(HAB_LANZAR) < 10)
    {
        write("Lanzas el cable hacia el lenguarón, pero no consigues "
            "atraparlo.\n");
        tell_room(env, ({MSG_SEE, CAP(TNAME) + " lanza un cable hacia el "
                                  "lenguarón pero no consigue atraparle.\n"}), ({pl}));
        return ME_NO_GET;
    }

    write("Lanzas el cable hacia el lenguarón y consigues atraparlo. Rápidamente "
          "lo coges.\n");
    tell_room(env, ({MSG_SEE, CAP(TNAME) +" lanza un cable hacia el lenguarón y consigue "
      "atraparlo.\n"}), ({pl}));
    if ((val = ::move(TP,M_GET)) != ME_OK)
    // no pudo cogerlo
    {
        write("Sin embargo, se te escurre y escapa rápidamente. "
              "Quizás llevas demasiadas cosas encima y te impiden poder cojer al "
              "animalillo con facilidad.\n");
        tell_room(env, ({MSG_SEE, "Sin embargo, se le escurre y se escapa.\n"}), ({pl}));
        return val;
    }
    SetOwner(TP->QueryRealName());
    cable->remove();
    write("En vista de que el cable ya te ha servido para lo que querías, "
        "lo tiras lejos.\n");
    if (env->QueryJardinLenguaron())
    {
        tell_room(env, ({MSG_SEE, CAP(TNAME) + " tira el cable, que desaparece "
                                  "entre las flores de uno de los macizos "
                                  "del jardín.\n"}), ({pl}));
    }
    else
    {
        tell_room(env, ({MSG_SEE, CAP(TNAME) + " tira el cable lejos.\n"}), ({pl}));
    }
    return val;
}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    TP->StopAttack();
    StopAttack();
    write("El lenguarón esquiva tu ataque con facilidad.\n");
    tell_room(environment(TP), ({MSG_SEE, CAP(TNAME) + " intenta matar al "
                                          "lenguarón, pero este esquiva su ataque "
                                        "con facilidad.\n"}), ({TP}));
    return 0;
}

public void escapar()
{
    tell_room(environment(), ({MSG_SEE, "El lenguarón echa una carrera y desaparece de tu "
                                "vista.\n"}));
    remove();
}




