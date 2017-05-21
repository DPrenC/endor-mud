/****************************************************************************
Fichero: sanbernardo.c
Autor: Dharkus
Fecha: 20/03/2010
Descripción: Un perro San Bernardo para Berat
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
inherit GUARD;
create()
{
    "*"::create();
      
    AddId(({"perro", "sanbernardo", "chucho"}));
    SetStandard("un San Bernardo", "perro", ([GC_TORPE:19]), GENDER_MALE);
    SetAlign(250);
    SetShort("Un gran San Bernardo");
    SetLong("Es un gran perro San Bernardo propiedad de la guardia de Berat.\n Es un "
    "enorme animal con largo y abundante pelaje color marrón grisáceo.\n A pesar de "
    "su gran tamaño, aprecias una mirada amistosa en su rostro medio tapado por su "
    "largo pelo.\n Ajustado a su musculoso cuello, ves un collar con una placa "
    "identificativa.\n");
    AddSubDetail(({"collar", "placa"}), "Se trata de un collar de cuero con una placa "
    "de bronce con la insignia de la guardia de Berat.\n");
    SetWeight(90000);
    SetSmell("Tiene un fuerte olor a perro.\n");
    InitChats(2, ({"El San Bernardo sacude la cabeza.\n", "El perro se tumba un "
      "momento y se vuelve a levantar.\n", "El perro te olisquea curioso.\n"}));
    InitAChats(3, "El San Bernardo gruñe furioso.\n");
    SetShrugMsg("El SanBernardo agradece tus palabras con un lametón.\n");
    SetGoChance(50);
//    AddWalkZones(SIMA("berat"));
    SetCitizenship("berat");
    SetGuardDefendMsg("El San Bernardo ataca rabioso.\n");
    SetHP(QueryHP()*2);
    SetCon(QueryCon()*2);
}

init(){
    ::init();
    call_out("saludo", 1);
}
  
  public void saludo(){
    if(TP->QueryRace()=="humano"){
        write("El San bernardo te saluda lamiéndote.\n");
    say("El San bernardo saluda a "+CAP(TP->QueryName())+" lamiéndole.\n", TP);
    }else{
        write("El san bernardo te gruñe.\n");
        say("El Sanbernardo gruñe a"+CAP(TNAME)+" cuando lo bve.\n",TP);
    }
}