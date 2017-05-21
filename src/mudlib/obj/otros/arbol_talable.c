/***
Fichero: arbol_talable.c
Autor: orome Endor-Mud
Descripci�n: Un �rbol para usar la habilidad de talar.
Creaci�n: 23/10/2014
***/
#include <properties.h>
#include <moving.h>
#include <domain.h>
#include <xp.h>
#include <sounds.h>
inherit THING;
public void arbol_talado();
string pEstado,pTipoarbol="�rbol";
int pHachazos,pMaxhachazos;
public string QueryTipoArbol()         { return pTipoarbol; }
public string SetTipoArbol(string str) { return pTipoarbol = str; }
public int QueryHachazos()  {  return pHachazos;  }
public int SetHachazos(int i)  {  return pHachazos = i; }
public int QueryMaxHachazos()  {  return pMaxhachazos;  }
public int SetMaxHachazos(int i)  {  return pMaxhachazos = i; }
public string f_estado() {
    int talado=(QueryHachazos()*100)/QueryMaxHachazos();
    switch(100-talado){
        case -100..0: pEstado=" marcado para talar"; break;
        case 1..25: pEstado=" con unos pocos hachazos en su tronco"; break;
        case 26..66: pEstado=" a medio talar"; break;
        case 67..90: pEstado=" con una gran hendidura horizontal en el tronco"; break;
        case 91..100: pEstado=" practicamente talado"; break;
        default: pEstado=" totalmente talado, que deber�a de haberse ca�do"; break;
     }
     return pEstado;
}

public string f_short(){
    return "un "+QueryTipoArbol()+f_estado();
}

public f_long(){
    return "Se trata de un magn�fico ejemplar de "+QueryTipoArbol()+" cuya calidad, forma "
    "y posici�n lo hacen ideal para ser talado y aprovechado., est�"+f_estado()+".\n";
}

    create()
{
    ::create();
        SetWeight(600000+random(1000000));
    SetMaxHachazos(QueryWeight()/40000);
    SetHachazos(QueryMaxHachazos());
    SetShort(SF(f_short));
    SetLong(SF(f_long));
    SetIds(({"arbol","�rbol","talable"}));
    SetAds(({"enorme"}));
    SetNoTake("No solo pesa demasiado para que lo cojas, si no que adem�s sus grandes "
    "ra�ces est�n firmemente incrustadas en la tierra.\n");
    Set(P_SIZE,P_SIZE_HUGE);
    SetSmell("huele a madera verde y follaje.\n");
}


public void cae_arbol(){
    call_out("arbol_talado",d3());
}
public void arbol_talado(){
    seteuid(getuid());
    object tocon,tronco;

    tocon=clone_object(THING);
    tocon->SetShort("un toc�n");
    tocon->SetLong("Es el toc�n de un "+environment(TP)->QueryTipoArboles()+".\n");
    tocon->SetNoGet("Por mucho que tiras el toc�n est� bien enraizado en el suelo y no cede un mil�metro.\n");
    tocon->SetIds(({"tocon","toc�n"}));
    tocon->move(environment(TO), M_SILENT);

    tronco=clone_object(OTROS("tronco"));
    tronco->SetTipoArbol(TO->QueryTipoArbol());
    tronco->SetMaxHachazos(QueryMaxHachazos()/2);
    tronco->SetHachazos(tronco->QueryMaxHachazos());
    tronco->move(environment(TO),M_SILENT);
    tell_room(environment(TO), "finalmente el "+TO->QueryTipoArbol()+" cede por su propio peso y se derrumba con un fuerte crujido de madera astillada y follaje aplastado.\n");

play_sound(environment(TO),SOUND_EVENTOS("arbol_talado"));
    TP->exp(XP_BASICO*TO->QueryMaxHachazos());
    tronco->Aplastamiento();
remove();
return 0;
}
