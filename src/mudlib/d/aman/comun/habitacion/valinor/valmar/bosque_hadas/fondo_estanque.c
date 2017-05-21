/*****************************************************************************************
 ARCHIVO:       fondo_estanque.c
 AUTOR:         Ztico
 FECHA:         17-01-2006
 DESCRIPCI�N:   Fondo del estanque en el bosque de las hadas (bosque60)
 COMENTARIOS:   Cojo las funciones del lago de Gaddaro
                A�ado una runa para el quest del santuario druida

                Cuando un pj muere ahogado en esta room, si estaba con alg�n player
                pone que �ste mat� al primero... que abuso!
                
                ���PONER QUE LA RUNA S�LO APAREZCA SI EL PJ TIENE 'ACTIVADO' EL QUEST!!!
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
    SetIntLong("Est�s en el fondo de un diminuto lago. No sabes como has llegado aqu� "
        "pero no podr�s permanecer por mucho m�s tiempo, si no quieres ahogarte "
        "claro.\n");

    AddExit("arriba", SF(f_ir_superficie));
}

public int f_ir_superficie()
{
    if (TP->QueryStatus() == STATUS_SLEEPING) return 0;
    TP->move(HAB_BOSQUE_HADAS("bosque60"), M_SPECIAL,
        ({"toma impulso como puede y asciende hasta la superficie",
          "sale r�pido del estanque y respira profundamente",
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

    msg =(({"�Te est�s ahogando!.\n",
            "�No podr�s aguantar la respiraci�n durante mucho m�s tiempo!\n",
            "Necesitas aire, �Est�s muriendo!\n",
            "Tus pulmones no podr�n aguantar mucho m�s...\n",
            "�Aire, aire! �necesitas respirar!\n"}));
    pl->SetDieMsg("#jug# muri� ahogad" + AO + " en el fondo de un peque�o estanque.");
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
