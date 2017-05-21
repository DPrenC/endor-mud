/*****
comando cortar.
orome 26/10/2014
comando para cortar un tronco en distintas secciones obtenido de talar un �rbol
****/


#include <skills.h>
#include <properties.h>
#include <xp.h>
#include <moving.h>
#include <sounds.h>
int main(string que) {
    object hacha, tronco, sierra;
    int i,bonus_gremio=0,hachazo=1;
    int talar;
    if(!que) return notify_fail("�Qu� quieres cortar?\n", NOTIFY_NOT_VALID);
        tronco= present(que, environment(TP));
        if(!tronco) return notify_fail("No ves ning�n tronco que puedas cortar en secciones por los alrededores.\n", NOTIFY_NOT_VALID);
            if(!tronco->id("cortable")) return notify_fail("Este tronco no es id�neo para ser cortado en secciones m�s peque�as.\n", NOTIFY_NOT_VALID);
    if ( !TP->HasSkill(HAB_TALAR))
    return notify_fail("Para cortar un tronco en secciones m�s peque�as necesitar�as tener algunos conocimientos relacionados con talar �rboles.\n",NOTIFY_NOT_VALID);
    if (!TP->CanSee()) return notify_fail("Ser�a un peligro si te pones con esas actividades sin ver lo que haces.\n",NOTIFY_NOT_VALID);
    hacha=present("hacha", TP);
    sierra=present("sierra", TP);
    if (!hacha || !hacha->QueryEquipped()) // || !sierra || !sierra->QueryEquipped())
    return notify_fail("\n Necesitas empu�ar un hacha o una sierra si pretendes cortar en secciones ese tronco.\n",NOTIFY_NOT_VALID);
    if(TP->QueryTP()<3 || TP->QuerySP()<3)
        return notify_fail("No tienes fuerzas para propinar un solo hachazo m�s, ni concentraci�n para acertar en el tronco.\n", NOTIFY_NOT_VALID);
    if(TP->QueryHP()<10) return notify_fail("Estando al borde de la muerte no es conveniente que te pongas a hacer ese tipo de tareas.\n",
        NOTIFY_NOT_VALID);
    TP->AddTP(-d3());
    TP->AddSP(-1);
     talar= TP->UseSkill(HAB_TALAR, bonus_gremio);
     hachazo=1;
     if(hacha->id("hacha_le�ador")) hachazo++;
                write(talar+".\n");
    if(talar<1){
        play_sound(environment(TP), SOUND_EVENTOS("hachazo_fallido"));
    switch(talar){
        case -20..0: //falla un poco
            write("\n Aferras con decisi�n el mango de "+hacha->QueryShort()+" e intentas propinarle un hachazo al tronco pero calculas mal, golpeando con el plano de la hoja y lastim�ndote, de paso, las mu�ecas.\n\n");
    say(CAP(TNAME)+" golpea torpemente con el plano de "+hacha->QueryShort()+" en el tronco.\n\n");
    TP->AddTP(-d2()); //se cansa un poco m�s por fallar.
    TP->AddSP(-1); //fallar tambi�n da m�s fustraci�n.
    TP->AddHP(-1); //se da�a un poco
        break;
        case -50.. -21: //falla bastante m�s.
            write("\n Aferras con decisi�n el mango de "+hacha->QueryShort()+" e intentas propinarle un hachazo al tronco pero calculas mal, golpeando con el plano de la hoja y lastim�ndote, de paso las mu�ecas.\n");
    say(CAP(TNAME)+" golpea torpemente con el plano de "+hacha->QueryShort()+" en el tronco.\n");
    TP->AddTP(-d3()); //se cansa un poco m�s por fallar.
    TP->AddSP(-2); //fallar tambi�n da m�s fustraci�n.
    TP->AddHP(-2); //se da�a un poco
    break;
        default:  //falla mogoll�n
            write("\n Aferras con decisi�n el mango de "+hacha->QueryShort()+" e intentas propinarle un hachazo al tronco pero calculas mal, golpeando con el plano de la hoja y lastim�ndote, de paso las mu�ecas.\n");
    say(CAP(TNAME)+" golpea torpemente con el plano de "+hacha->QueryShort()+" en el tronco.\n");
    TP->AddTP(-d4()); //se cansa un poco m�s por fallar.
    TP->AddSP(-3); //fallar tambi�n da m�s fustraci�n.
    TP->AddHP(-3); //se da�a m�s.
    break;
}

    return 1;
    }else{
        play_sound(environment(TP),SOUND_EVENTOS("hachazo"));
        switch(talar){
            case 1..15:
        write("Con gran maestr�a consigues acertar un hachazo en el tronco.\n");
        say(CAP(TNAME)+" est� ocupad"+TP->QueryGenderEndString()+" cortando un tronco.\n");
        break;
            case 16..30:
                write("Con gran maestr�a consigues acertar un hachazo en el tronco.\n");
        say(CAP(TNAME)+" est� ocupad"+TP->QueryGenderEndString()+" cortando un tronco.\n");
        break;
            case 31..45:
                write("Con gran maestr�a consigues acertar un hachazo en el tronco.\n");
        say(CAP(TNAME)+" est� ocupad"+TP->QueryGenderEndString()+" cortando un tronco.\n");
        break;
            case 46..60:
                write("Con gran maestr�a consigues acertar un hachazo en el tronco.\n");
        say(CAP(TNAME)+" est� ocupad"+TP->QueryGenderEndString()+" cortando un tronco.\n");
        break;
            case 61..75:
                write("Con gran maestr�a consigues acertar un hachazo en el tronco.\n");
        say(CAP(TNAME)+" est� ocupad"+TP->QueryGenderEndString()+" cortando un tronco.\n");
        hachazo++;
        break;
            case 76..300:
                write("Con gran maestr�a consigues acertar un hachazo en el tronco.\n");
        say(CAP(TNAME)+" est� ocupad"+TP->QueryGenderEndString()+" cortando un tronco.\n");
        hachazo++;
        break;
        }

        TP->exp(XP_BASICO);
        tronco->SetHachazos(tronco->QueryHachazos()-hachazo);
                if(tronco->QueryHachazos()<1){
                tronco->seccion_cortada();
        }
        return 1;
        }
}
