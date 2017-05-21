/***
Fichero: tronco.c
Autor: orome Endor-Mud
Descripción: el tronco de un árbol ya talado para cortarlo
Creación: 27/10/2014
***/
#include <wizlevels.h>
#include <properties.h>
#include <domain.h>
#include <moving.h>
#include <xp.h>
inherit THING;
#define PESO_SECCION 50000
public int Aplastamiento();
string pEstado,pTipoarbol="árbol";
int pTrozos,pMaxtrozos, pHachazos, pMaxhachazos;
public string QueryTipoArbol()         { return pTipoarbol; }
public string SetTipoArbol(string str) { return pTipoarbol = str; }
public int QueryTrozos()  {  return pTrozos;  }
public int SetTrozos(int i)  {  return pTrozos = i; }
public int QueryMaxTrozos()  {  return pMaxtrozos;  }
public int SetMaxTrozos(int i)  {  return pMaxtrozos = i; }
public int QueryHachazos()  {  return pHachazos;  }
public int SetHachazos(int i)  {  return pHachazos = i; }
public int QueryMaxHachazos()  {  return pMaxhachazos;  }
public int SetMaxHachazos(int i)  {  return pMaxhachazos = i; }

public string f_short(){
    return "un "+(QueryTrozos()<6 ? "tronco bastante corto" : "largo tronco")+" de un "+QueryTipoArbol()+
    (QueryHachazos()==QueryMaxHachazos() ? "" : ", con una de las secciones a medio cortar");
}

public f_long(){
    return "Es el enorme tronco de un "+QueryTipoArbol()+" derribado que se encuentra listo para ser cortado en secciones más pequeñas, "
    +(QueryTrozos()<5 ? "apenas se pueden sacar de él " : " todavía se pueden cortar unas ")+itoa(QueryTrozos())+" secciones"+
        (QueryHachazos()==QueryMaxHachazos() ? ".\n" : ", una de las secciones está a medio cortar.\n");
}

    create()
{
    ::create();
        if(QueryWeight()<300000) SetWeight(500000+random(800000));
    SetMaxTrozos(QueryWeight()/PESO_SECCION);
    SetTrozos(QueryMaxTrozos());
    SetMaxHachazos(10);
    SetHachazos(QueryMaxHachazos());
    SetShort(SF(f_short));
    SetLong(SF(f_long));
    SetIds(({"tronco","cortable"}));
    SetAds(({"enorme"}));
        SetSmell("huele a madera verde y resina.\n");
        Set(P_SIZE,P_SIZE_HUGE);
}

public int Aplastamiento(){
int provabilidad;
    object *a_chafar = filter(all_inventory(environment()) - ({TO}), (:living($1):));
    object elegido = a_chafar[random(sizeof(a_chafar))];
    if (!elegido->QueryIsPlayer() || elegido->QueryAway() || elegido->QueryStatusSleeping() || query_idle(elegido)>100)
           provabilidad=d2(); else provabilidad=d4();
    if(provabilidad==1 && present(elegido, environment()) && !IS_MAIA(elegido) && elegido->QueryLevel()>5){
    tell_room(environment(), "El enorme tronco de un "+environment()->QueryTipoArboles()+" cae encima de "+elegido->QueryShort()+
        " aplastándole por completo.\n", ({elegido}));
    tell_object(elegido, "El enorme tronco cae encima tuya aplastándote por completo.\n");
    elegido->Die();

    }else{
    tell_room(environment(), "El enorme tronco de un "+environment()->QueryTipoArboles()+" cae muy cerca de "+elegido->QueryShort()+
        " que ha evitado de ser aplastad"+elegido->QueryGenderEndString()+".\n", ({elegido}));
    tell_object(elegido, "El enorme tronco cae muy cerca de tí, casi te aplasta.\n");
}
return 1;
}

public void seccion_cortada(){
    seteuid(getuid());
    object seccion;

            if(TO->QueryTrozos()==2){
                for (int i = 0;i<2;i++) {
                        seccion=clone_object(OTROS("seccion_tronco"));
    seccion->SetTipoArbol(TO->QueryTipoArbol());
    seccion->QueryWeight(PESO_SECCION);
            seccion->move(environment(TO),M_SILENT);
        } // for
        tell_room(environment(TO), "Finalmente el tronco, debido a su tamaño, acaba partido en dos secciones.\n");
                                TP->exp(XP_BASICO*TO->QueryMaxHachazos()*2);
                        TO->remove();
                        return 0;
                        }else {
                            seccion=clone_object(OTROS("seccion_tronco"));
    seccion->SetTipoArbol(TO->QueryTipoArbol());
    seccion->QueryWeight(PESO_SECCION);
            seccion->move(environment(TO),M_SILENT);
tell_room(environment(TO), "Con el último hachazo una sección del tronco queda separada del resto.\n");
                        TP->exp(XP_BASICO*TO->QueryMaxHachazos());
    TO->SetTrozos(TO->QueryTrozos()-1);
    TO->SetHachazos(TO->QueryMaxHachazos());
    TO->SetWeight(TO->QueryWeight()-PESO_SECCION);
return 0;
}
}
