/*****
comando talar.
orome 26/10/2014

****/


#include <skills.h>
#include <properties.h>
#include <xp.h>
#include <moving.h>
#include <sounds.h>
int main(string que) {
    object hacha, arbol;
    int i,bonus_gremio=0,hachazo=1;
    int talar;
    if(!que) return notify_fail("�Qu� quieres talar?\n", NOTIFY_NOT_VALID);
        arbol= present(que, environment(TP));
        if(!arbol) return notify_fail("No ves ning�n �rbol marcado para talar por aqu�.\n", NOTIFY_NOT_VALID);
            if(!arbol->id("talable")) return notify_fail("Busca otro�rbol para talar, si "
            	"lo intentaras con ese podr�as sufrir alg�n percance.\n", NOTIFY_NOT_VALID);
    if ( !TP->HasSkill(HAB_TALAR))
    return notify_fail("Para talar un �rbol deber�s primero aprender como hacerlo.\n",NOTIFY_NOT_VALID);
    if (!TP->CanSee()) return notify_fail("Ser�a un peligro si te pones a talar sin ver lo que haces.\n",NOTIFY_NOT_VALID);
    hacha=present("hacha", TP);
    if (!hacha || !hacha->QueryEquipped())
    return notify_fail("\n Necesitas empu�ar un hacha si pretendes talar ese �rbol.\n",NOTIFY_NOT_VALID);
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
            write("\n Sujetas el mango de "+hacha->QueryShort()+" y asestas un desmesurado "
            "golpe contra el tronco de "+arbol->QueryShort()+
    " pero calculas mal y la hoja pasa de largo raspando la corteza de refil�n.\n\n");
    say(CAP(TNAME)+" lanza un golpe demasiado entusista con "+hacha->QueryShort()+" y la hoja pasa rozando de refil�n la corteza de "+arbol->QueryShort()+".\n\n");
    TP->AddTP(-d2()); //se cansa un poco m�s por fallar.
    TP->AddSP(-1); //fallar tambi�n da m�s fustraci�n.
    TP->AddHP(-1); //se da�a un poco
        break;
        case -50.. -21: //falla bastante m�s.
            write("\n Aferras con decisi�n el mango de "+hacha->QueryShort()+" e intentas propinarle un hachazo al tronco del "+arbol->QueryShort()+
    " pero calculas mal, golpeando con el plano de la hoja y lastim�ndote, de paso las mu�ecas.\n");
    say(CAP(TNAME)+" golpea torpemente con el plano de "+hacha->QueryShort()+" en el tronco de "+arbol->QueryShort()+".\n");
    TP->AddTP(-d3()); //se cansa un poco m�s por fallar.
    TP->AddSP(-2); //fallar tambi�n da m�s fustraci�n.
    TP->AddHP(-2); //se da�a un poco
    break;
        default:  //falla mogoll�n
            write("\n Tus nudillos se ponen blancos cuando cierras los pu�os con fuerza "
            "sobre el mango de "+hacha->QueryShort()+". Con la intenci�n de derribar  "+arbol->QueryShort()+
    " de una vez, giras sobre ti mismo propinando un descomunal golpe que, al haber "
    "calculado mal, hiende el aire haci�ndote girar sobre ti mismo. Resbalas y caes al "
    "suelo pero te levantas r�pidamente, antes de que nadie pueda verte de tan vergonzosa guisa.\n");
    say(CAP(TNAME)+" aferra el mango de "+hacha->QueryShort()+" y lanza un golpe demoledor sobre "
    +arbol->QueryShort()+" pero falla por mucho y la inercia lo hace girar sobre s� mismo "
    "acabando por los suelos con hacha y todo.\n");
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
        write("Hach�as d�bilmente el tronco de "+arbol->QueryShort()+" en forma dubitativa, dejando una peque�a marca.\n");
        say(CAP(TNAME)+" da un torpe hachazo de novat"+TP->QueryGenderEndString()+" sobre el tronco de "+arbol->QueryShort()+".\n");
        break;
            case 16..30:
                write("Asestas un hachazo algo torpe al tronco de "+arbol->QueryShort()+" dejando una hendidura sesgada.\n");
        say(CAP(TNAME)+" propina un torpe hachazo al tronco de "+arbol->QueryShort()+".\n");
        break;
            case 31..45:
                write("Asestas un buen hachazo al tronnnnnco de "+arbol->QueryShort()+", aunque te has desviado un poco.\n");
        say(CAP(TNAME)+" asesta un buen hachazo al tronco de "+arbol->QueryShort()+", pero se desv�a del lugar adecuado.\n");
        break;
            case 46..60:
                write("Descargas un soberbio hachazo sobre el tronco de "+arbol->QueryShort()+" haciendo saltar astillas y produciendo una profunda hendedura.\n");
        say(CAP(TNAME)+" propina u soberano hachazo sobre el tronco de "+arbol->QueryShort()+" haciendo saltar astillas y dejando una profunda hendidura.\n");
        break;
            case 61..75:
                write("Con gran maestr�a asestas un poderoso hachazo bien dirigido en el tronco de "+arbol->QueryShort()+", haciendo saltar astillas por todas partes y adentr�ndote profundamente en la madera.\n");
        say(CAP(TNAME)+" asesta un poderoso hachazo con gran maestr�a y fuerza sobre el tronco de "+arbol->QueryShort()+" profudizando en la madera y haciendo saltar una nube de astillas.\n");
        hachazo++;
        break;
            case 76..300:
                write("Empu�ando con suma maestr�a "+hacha->QueryShort()+", lanzas un "
                "tremendo hachazo haciendo que la hoja traze un sibilante y relumbrante "
                "arco, incrust�ndose hasta el mango en el tronco de "+arbol->QueryShort()+" "
                "en el punto exacto. El �rbol retiembla de la copa a las ra�ces.\n");
        say(CAP(TNAME)+" aferra con soltura el mango de "+hacha->QueryShort()+" "
        "y girando sobre s�, lanza un magistral hachazo contra "+arbol->QueryShort()+", "
        "trazando un fulgurante arco en el aire que finaliza con la hoja incrustada "
        "hasta el mango en el tronco, justo donde deseaba.\n"
        "El �rbol se estremece de la copa a las ra�ces por la rudeza del golpe.\n");
        hachazo++;
        break;
        }

        TP->exp(XP_BASICO);
        arbol->SetHachazos(arbol->QueryHachazos()-hachazo);
                if(arbol->QueryHachazos()<1){
        TP->command_me("gritar ��rbol vaaaa!");
        arbol->cae_arbol();

        }
        return 1;
        }
}
