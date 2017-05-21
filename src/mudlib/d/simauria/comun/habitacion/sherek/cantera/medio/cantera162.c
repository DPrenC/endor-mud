/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/medio/cantera162.c
Autor: Lug y Yalin
Fecha: 13/12/2006
Descripci�n: en la cantera de Sherek.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <skills.h>
#include <sounds.h>
inherit SHERCAN("medio/cantera1");
#define AO  (TP->QueryGenderEndString())
    
private int trepando()
{
    if (TP->QueryStatus() == STATUS_SLEEPING) return 0;
    if (TP->QueryTP() < 5) return notify_fail("Est�s muy cansad"+AO+" para trepar.\n",
        NOTIFY_NOT_VALID);
    int sube = TP->UseSkill(HAB_TREPAR,TP->QueryDex());
    if (sube >= 0)
    {
        int azar;
        switch(sube)
        {
            case 0..19: azar=d20();break;
            case 20..49: azar=d10();break;
            default: azar=d4();break;
        }
        if (azar == 1 || sube >=80)
        {
            /* Trepa bien, as� que se va. */
            TP->SetFollowers(0);
            write("En un alarde de maestr�a, te izas hasta el agujero.\n�Mi�eeeeee�r...! "
                "Demasiado tarde, adviertes que el agujero da directamente sobre "
                "una empinada pendiente, por la que te despe�as sin poder "
                "evitarlo...\nVas a caer sobre las rocas, con el agugero del que "
                "saliste, all� arriba, muy lejos de tu alcance.\n");
            say(CAP(TP->QueryName())+" se desliza por la pared como una "
                "lagartija, y desaparece de tu vista.\n",TP);
            int celda, road, col;
            road = d6();
            col = d6();
            celda = 200+(road*10)+col;
            tell_room(SHERCAN("fondo/cantera"+celda),CAP(TP->QueryName())+" cae "
                "misteriosamente desde arriba.\n");
            return TP->move(SHERCAN("fondo/cantera"+celda), M_GO);
        }
        else if (sube>=19)
        {
            /* Sabe trepar, pero no bien, sube m�s alto, por tanto, m�s fatiga y
            * m�s da�o. */
            TP->AddTP(-10);
            TP->AddHP(-15);
            play_sound(TO,SND_SUCESOS("caida_fuerte"));
            say(CAP(TP->QueryName())+" comienza a escalar por la pared, pero "
                "cuando est� casi al borde del agujero, pierde apoyo, y cae a tus "
                "pies hecho un gui�apo.\n",TP);
            return notify_fail("Subes trepando la pared, pero tu inexperiencia hace que pierdas "
                "apoyo, y te estrellas contra el suelo.\nEst�s "+TP->QueryHealthMsg()+".\n",
                NOTIFY_NOT_VALID);
        }
        /* No sabe trepar, as� que sube un poco y se cae, poco cansancio y poco da�o. */
        TP->AddTP(-5);
        TP->AddHP(-5);
        play_sound(TO,SND_SUCESOS("caida_fuerte"));
        say(CAP(TNAME)+" trata de escalar la pared, pero se resbala "
            "y cae al suelo.\n",TP);
        return notify_fail("Tratas de escalar la pared, pero te resbalas y "
            "caes.\nEst�s "+TP->QueryHealthMsg()+".\n",NOTIFY_NOT_VALID);
    }
    // menos de 0. No sabe trepar en absoluto
    say(CAP(TNAME)+" trata de escalar la pared, pero dada su torpeza, sus pies y manos no "
        "consiguen hacer presa en las rocas.\n",TP);
    return notify_fail("Intentas subir por las rocas, pero eres demasiado torpe y no consigues "
        "agarrarte bien.\n",NOTIFY_NOT_VALID);
}

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Debido a alg�n derrumbamiento, la pared se ha "
        "medio desmoronado, presentando un agujero en la roca, muy por "
        "encima de ti, pero la pared fracturada te podr�a permitir trepar "
        "hasta all�.\n");
    AddDetail("pared","La pared parece medio derruida, y presenta muchas "
        "grietas y resquebrajaduras.\n");
    AddDetail("agujero","Est� muy lejos de tu alcance, no lo ves bien.\n");
    AddExit("suroeste",SHERCAN("medio/cantera153"));
    AddExit("trepar",SF(trepando));
    pongo();
}
