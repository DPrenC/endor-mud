/*****************************************************************************************
 ARCHIVO:       fondo_estanque.c
 AUTOR:         Ztico
 FECHA:         17-01-2006
 DESCRIPCIÓN:   Fondo del estanque en el bosque de las hadas (bosque60)
 COMENTARIOS:   Cojo las funciones del lago de Gaddaro
                Añado una runa para el quest del santuario druida

                Cuando un pj muere ahogado en esta room, si estaba con algún player
                pone que éste mató al primero... que abuso!
                
                ¡¡¡PONER QUE LA RUNA SÓLO APAREZCA SI EL PJ TIENE 'ACTIVADO' EL QUEST!!!
*****************************************************************************************/

#include "./path.h"
#include <properties.h>
#include <moving.h>
#include <combat.h>

inherit BASE_HADAS;

public int f_ir_superficie();
public void f_se_ahoga();
public int f_asfixiar(object ob);
public void f_clonar_runa();

create()
{
    if(::create()) return 1;

    SetIntShort("el fondo de un estanque");
    SetIntLong("Estás en el fondo de un diminuto lago. No sabes como has llegado aquí "
        "pero no podrás permanecer por mucho más tiempo, si no quieres ahogarte "
        "claro.\n");

    AddExit("arriba", SF(f_ir_superficie));
}

public int f_ir_superficie()
{
    if (TP->QueryStatus() == STATUS_SLEEPING) return 0;
    TP->move(HAB_BOSQUE_HADAS("bosque60"), M_SPECIAL,
        ({"toma impulso como puede y asciende hasta la superficie",
          "sale rápido del estanque y respira profundamente",
          "Empiezas a nadar hacia la superficie hasta que lo consigues"}));
    return 1;

}

public void f_se_ahoga()
{
    object *inv;

    inv = filter(all_inventory(), SF(f_asfixiar));
    if (sizeof(inv)) call_out("f_se_ahoga", 5);
    else while (remove_call_out("f_se_ahoga") != -1);
}

public int f_asfixiar(object pl)
{
    string *msg;
    if (!pl || !living(pl)) return 0;

    msg =(({"¡Te estás ahogando!.\n",
            "¡No podrás aguantar la respiración durante mucho más tiempo!\n",
            "Necesitas aire, ¡Estás muriendo!\n",
            "Tus pulmones no podrán aguantar mucho más...\n",
            "¡Aire, aire! ¡necesitas respirar!\n"}));
    pl->SetDieMsg("#jug# murió ahogad" + AO + " en el fondo de un pequeño estanque.");
    tell_object(pl, msg[random(sizeof(msg))]);
    pl->Defend(7, DT_NOAIR,
               DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);

    return 1;
}

public void f_clonar_runa()
{
    object runa;
    runa = clone_object(COMUN + "quest/runas/runa_5");
    runa->move(TO, M_SILENT);
    return;
}

public varargs void init()
{
    ::init();

    if(TP) call_out("f_se_ahoga", 5);
    f_clonar_runa();
}
