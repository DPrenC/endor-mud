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
    if(!que) return notify_fail("¿Qué quieres talar?\n", NOTIFY_NOT_VALID);
        arbol= present(que, environment(TP));
        if(!arbol) return notify_fail("No ves ningún árbol marcado para talar por aquí.\n", NOTIFY_NOT_VALID);
            if(!arbol->id("talable")) return notify_fail("Busca otroárbol para talar, si "
            	"lo intentaras con ese podrías sufrir algún percance.\n", NOTIFY_NOT_VALID);
    if ( !TP->HasSkill(HAB_TALAR))
    return notify_fail("Para talar un árbol deberás primero aprender como hacerlo.\n",NOTIFY_NOT_VALID);
    if (!TP->CanSee()) return notify_fail("Sería un peligro si te pones a talar sin ver lo que haces.\n",NOTIFY_NOT_VALID);
    hacha=present("hacha", TP);
    if (!hacha || !hacha->QueryEquipped())
    return notify_fail("\n Necesitas empuñar un hacha si pretendes talar ese árbol.\n",NOTIFY_NOT_VALID);
    if(TP->QueryTP()<3 || TP->QuerySP()<3)
        return notify_fail("No tienes fuerzas para propinar un solo hachazo más, ni concentración para acertar en el tronco.\n", NOTIFY_NOT_VALID);
    if(TP->QueryHP()<10) return notify_fail("Estando al borde de la muerte no es conveniente que te pongas a hacer ese tipo de tareas.\n",
        NOTIFY_NOT_VALID);
    TP->AddTP(-d3());
    TP->AddSP(-1);
     talar= TP->UseSkill(HAB_TALAR, bonus_gremio);
     hachazo=1;
     if(hacha->id("hacha_leñador")) hachazo++;
                write(talar+".\n");
    if(talar<1){
        play_sound(environment(TP), SOUND_EVENTOS("hachazo_fallido"));
    switch(talar){
        case -20..0: //falla un poco
            write("\n Sujetas el mango de "+hacha->QueryShort()+" y asestas un desmesurado "
            "golpe contra el tronco de "+arbol->QueryShort()+
    " pero calculas mal y la hoja pasa de largo raspando la corteza de refilón.\n\n");
    say(CAP(TNAME)+" lanza un golpe demasiado entusista con "+hacha->QueryShort()+" y la hoja pasa rozando de refilón la corteza de "+arbol->QueryShort()+".\n\n");
    TP->AddTP(-d2()); //se cansa un poco más por fallar.
    TP->AddSP(-1); //fallar también da más fustración.
    TP->AddHP(-1); //se daña un poco
        break;
        case -50.. -21: //falla bastante más.
            write("\n Aferras con decisión el mango de "+hacha->QueryShort()+" e intentas propinarle un hachazo al tronco del "+arbol->QueryShort()+
    " pero calculas mal, golpeando con el plano de la hoja y lastimándote, de paso las muñecas.\n");
    say(CAP(TNAME)+" golpea torpemente con el plano de "+hacha->QueryShort()+" en el tronco de "+arbol->QueryShort()+".\n");
    TP->AddTP(-d3()); //se cansa un poco más por fallar.
    TP->AddSP(-2); //fallar también da más fustración.
    TP->AddHP(-2); //se daña un poco
    break;
        default:  //falla mogollón
            write("\n Tus nudillos se ponen blancos cuando cierras los puños con fuerza "
            "sobre el mango de "+hacha->QueryShort()+". Con la intención de derribar  "+arbol->QueryShort()+
    " de una vez, giras sobre ti mismo propinando un descomunal golpe que, al haber "
    "calculado mal, hiende el aire haciéndote girar sobre ti mismo. Resbalas y caes al "
    "suelo pero te levantas rápidamente, antes de que nadie pueda verte de tan vergonzosa guisa.\n");
    say(CAP(TNAME)+" aferra el mango de "+hacha->QueryShort()+" y lanza un golpe demoledor sobre "
    +arbol->QueryShort()+" pero falla por mucho y la inercia lo hace girar sobre sí mismo "
    "acabando por los suelos con hacha y todo.\n");
    TP->AddTP(-d4()); //se cansa un poco más por fallar.
    TP->AddSP(-3); //fallar también da más fustración.
    TP->AddHP(-3); //se daña más.
    break;
}

    return 1;
    }else{
        play_sound(environment(TP),SOUND_EVENTOS("hachazo"));
        switch(talar){
            case 1..15:
        write("Hachéas débilmente el tronco de "+arbol->QueryShort()+" en forma dubitativa, dejando una pequeña marca.\n");
        say(CAP(TNAME)+" da un torpe hachazo de novat"+TP->QueryGenderEndString()+" sobre el tronco de "+arbol->QueryShort()+".\n");
        break;
            case 16..30:
                write("Asestas un hachazo algo torpe al tronco de "+arbol->QueryShort()+" dejando una hendidura sesgada.\n");
        say(CAP(TNAME)+" propina un torpe hachazo al tronco de "+arbol->QueryShort()+".\n");
        break;
            case 31..45:
                write("Asestas un buen hachazo al tronnnnnco de "+arbol->QueryShort()+", aunque te has desviado un poco.\n");
        say(CAP(TNAME)+" asesta un buen hachazo al tronco de "+arbol->QueryShort()+", pero se desvía del lugar adecuado.\n");
        break;
            case 46..60:
                write("Descargas un soberbio hachazo sobre el tronco de "+arbol->QueryShort()+" haciendo saltar astillas y produciendo una profunda hendedura.\n");
        say(CAP(TNAME)+" propina u soberano hachazo sobre el tronco de "+arbol->QueryShort()+" haciendo saltar astillas y dejando una profunda hendidura.\n");
        break;
            case 61..75:
                write("Con gran maestría asestas un poderoso hachazo bien dirigido en el tronco de "+arbol->QueryShort()+", haciendo saltar astillas por todas partes y adentrándote profundamente en la madera.\n");
        say(CAP(TNAME)+" asesta un poderoso hachazo con gran maestría y fuerza sobre el tronco de "+arbol->QueryShort()+" profudizando en la madera y haciendo saltar una nube de astillas.\n");
        hachazo++;
        break;
            case 76..300:
                write("Empuñando con suma maestría "+hacha->QueryShort()+", lanzas un "
                "tremendo hachazo haciendo que la hoja traze un sibilante y relumbrante "
                "arco, incrustándose hasta el mango en el tronco de "+arbol->QueryShort()+" "
                "en el punto exacto. El árbol retiembla de la copa a las raíces.\n");
        say(CAP(TNAME)+" aferra con soltura el mango de "+hacha->QueryShort()+" "
        "y girando sobre sí, lanza un magistral hachazo contra "+arbol->QueryShort()+", "
        "trazando un fulgurante arco en el aire que finaliza con la hoja incrustada "
        "hasta el mango en el tronco, justo donde deseaba.\n"
        "El árbol se estremece de la copa a las raíces por la rudeza del golpe.\n");
        hachazo++;
        break;
        }

        TP->exp(XP_BASICO);
        arbol->SetHachazos(arbol->QueryHachazos()-hachazo);
                if(arbol->QueryHachazos()<1){
        TP->command_me("gritar ¡árbol vaaaa!");
        arbol->cae_arbol();

        }
        return 1;
        }
}
