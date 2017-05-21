/****
comando buscar.c
creado por orome el 19/10/2014
comando para buscar cosas, como le�a, lombrices y caracoles, por ejemplo.
****/
#include <domain.h>
#include <moving.h>
#include <properties.h>
#include <skills.h>
#include <xp.h>
public void RecogerLenya();
int lenya,bonus_gremio_lenya=0,bonus_gremio_arboles=0,busqueda=0;
object ramas,arbol;
int main(string str) {
    lenya=0;

    switch (TP->QueryGuild()){
            case "aventurero":  bonus_gremio_arboles = BONUS_AVENTUREROS_ARBOLES; bonus_gremio_lenya = BONUS_AVENTUREROS_LENYA; break;
            case "artesano": bonus_gremio_lenya = BONUS_ARTESANOS_LENYA; break;
                            default: bonus_gremio_lenya=0; bonus_gremio_arboles=0; break;
            } //switch bonus_gremio

    if (TP->QueryAttribute("buscalenya"))
        return notify_fail("Est�s ocupad"+TP->QueryGenderEndString()+" ahora mismo.\n",NOTIFY_NOT_VALID);
                  if(TP->QueryAttribute("buscaarbol"))
      return notify_fail("Est�s ocupad"+TP->QueryGenderEndString()+" ahora mismo.\n",NOTIFY_NOT_VALID);
    if(!str) return notify_fail("�Qu� quieres buscar exactamente?\n",0);
    if (!TP->CanSee()) return notify_fail("No puedes ver ahora mismo para ponerte a buscar.\n",NOTIFY_NOT_VALID);
    if (TP->QueryCombatDelay()) return notify_fail(TP->QueryCombatDelayMsg()||"No puedes moverte.\n",NOTIFY_NOT_VALID);
    if (TP->Fighting()) return notify_fail("Est�s luchando y necesitas dedicar toda tu concentraci�n al combate.\n",NOTIFY_NOT_VALID);
    if(TP->QueryTP()<3) return notify_fail("te encuentras algo cansad"+TP->QueryGenderEndString()+", descansa un rato.\n",
            NOTIFY_NOT_VALID);
    switch(str){
        case "le�a": case "lenya":
            {
        if ( !TP->HasSkill(HAB_LE�A))
    return notify_fail("Eso de buscar le�a nunca ha ido contigo, mejor ded�cate a otra cosa.\n"),0;
        if(!environment(TP)->QueryHaylenya())
        return notify_fail("En esta zona no es posible que puedas encontrar le�a.\n"),0;
        busqueda=TP->UseSkill(HAB_LE�A, bonus_gremio_lenya);
        write("Te entretienes un rato buscando algo de le�a...");
        say(CAP(TNAME)+" se pone a buscar algo de le�a...");
        TP->AddTP(-d4());
        TP->AddSP(-d4());
        TP->SetAttribute("buscalenya",time());
        call_out("RecogerLenya",d6());
            break;
            } //le�a
        case "arbol": case "�rbol": case "arboles": case "�rboles":
{
        if ( !TP->HasSkill(HAB_ARBOLES))
    return notify_fail("No te crees capaz de diferenciar los �rboles que se podr�an talar, te faltan conocimientos.\n"),0;
        if(!environment(TP)->QueryHayarboles())
        return notify_fail("En esta zona no es posible que puedas encontrar �rboles propicios para talar.\n"),0;
                            busqueda=TP->UseSkill(HAB_ARBOLES, bonus_gremio_arboles);
        write("Ojeas por los alrededores de la zona inspeccionando los �rboles que te rodean...");
        say(CAP(TNAME)+" inspecciona con actitud experimentada los �rboles que nos rodean...");
        TP->AddTP(-d2());
                TP->AddSP(-d2());
                TP->SetAttribute("buscaarbol",time());
        call_out("LocalizarArboles",d6());
            break;
            } // arbol
            default: write("No te crees capaz de ponerte a buscar "+str+".\n");
    } // switch str
return 1;
}

public void RecogerLenya(){
    TP->RemoveAttribute("buscalenya");
    if(busqueda<1 || environment(TP)->QueryCantidadLenya()<1){
        write(" pero por m�s que te esfuerzas no consigues encontrar nada que te pueda servir.\n"+
        (environment(TP)->QueryCantidadLenya()<1 ? "En esta zona no queda le�a.\n" : ""));
        say(" pero no parece que encuentre nada.\n");
        return 0;
    }else{
        lenya=(busqueda*environment(TP)->QueryCantidadLenya())/100; // busqueda es el tanto por ciento que va a coger de le�a
        if(lenya<1) lenya=1;
        environment(TP)->AddCantidadLenya(-lenya);
        write (" y consigues encontrar "+(lenya>1 ? itoa(lenya)+" ramas" : "una rama")+" de le�a que te pueden servir.\n");
        say(" y parece que ha conseguido encontrar algo que le pueda servir.\n");
        TP->exp(lenya*XP_BASICO);
        seteuid(getuid());
        for (int i = 0;i<lenya;i++) {
            ramas=clone_object(OTROS("quemable"));
            if (ramas->move(TP,M_SILENT)!=ME_OK){
                ramas->move(environment(TP),M_SILENT);
                write("llevas muchas cosas encima y no consigues coger "+ramas->QueryShort()+", decides dejarla en el suelo.\n");
                say(CAP(TNAME)+" deja "+ramas->QueryShort()+" porque lleva demasiadas cosas encima.\n");
            } //move
        } //for
    return 0;
} //busqueda
return 0;
} //call_out recoger le�a

public void LocalizarArboles(){
    TP->RemoveAttribute("buscaarbol");
    if(busqueda<10 || environment(TP)->QueryCantidadArboles()<1){
        write(" pero los �rboles que est�s observando no te parecen propicios para ser talados.\n"+
        (environment(TP)->QueryCantidadArboles()<1 ? "Mejor busca en otra zona.\n" : ""));
        say(" pero no parece que encuentre ninguno que pueda ser talado.\n");
        return 0;
    }else{
                        environment(TP)->AddCantidadArboles(-1);
        write(" encuentras un estupendo ejemplar de "+environment(TP)->QueryTipoArboles()+
        " que est� preparado para ser talado, lo marcas para que se diferencie del resto.\n");
        say(" y parece que ha conseguido encontrar un buen �rbol que pueda ser talado.\n");
        TP->exp(busqueda);
                seteuid(getuid());
            arbol=clone_object(OTROS("arbol_talable"));
            arbol->SetTipoArbol(environment(TP)->QueryTipoArboles());
            arbol->AddId(environment(TP)->QueryTipoArboles());
                            arbol->move(environment(TP),M_SILENT);
                                                        return 0;
} //busqueda arbol
return 0;
} //call_out LocalizarArboles

