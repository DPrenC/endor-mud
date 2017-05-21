/*
DESCRIPCION  : un oso para los bosques
FICHERO      : /d/akallab/comun/pnj/animal/oso.c
MODIFICACION : 18-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>

inherit AK_PNJ;

//#include PNJ("animal/oso_base.h")
#include "oso_base.h"

//#include <living.h>
//#include <combat.h>
//

int osoInit;
int osoTipo;
int osoFactor;
int osoClase;

void SetTipo(int t){
   int i;
   string *tipos;
   tipos=OSO_TIPO_M;
   i=sizeof(tipos);
   if ((t>=0) && (t<=i)) osoTipo=t;
   else osoTipo=random(i);
   return;
}

int QueryClase(){return osoClase;}

int QueryTipo(){return osoTipo;}

string QueryTipoStr(){
   string *tipos;
   if (QueryClase()==2)
      tipos=OSO_TIPO_F;
   else tipos=OSO_TIPO_M;
   return tipos[osoTipo];
}

int UsaFactor(int i){
   int *factor;
   factor=OSO_FACTOR;
   return (factor[osoTipo]*i/100);
}

void SetClase(int c)
{
osoClase=c;
osoInit=1;
return;
}

string QueryClaseStr()
{
   string *clase;
   clase=OSO_CLASE;
   return clase[osoClase-1];
}

create() {
    string *tipos;

  if (!osoInit)
    {
    SetClase(random(3)+1);
    tipos=OSO_TIPO_M;
    SetTipo(random(sizeof(tipos)));
    }

  ::create();

  switch(osoClase)
  {
  case OSO:
     {
     SetStandard("oso","oso",UsaFactor(11+random(4)),GENDER_MALE);
     SetShort("un oso "+QueryTipoStr());
     SetLong("Es un enorme oso "+QueryTipoStr()+" que busca algo de "
            "comida entre los matojos del suelo abriendose paso con "
            "sus grandes patas y afiladas garras. Su mirada de "
            "pocos amigos no anima mucho a pelear con el. Podria "
            "destrozarte de un solo zarpazo.\n");
     SetWeight(UsaFactor(85000));
     SetAds(({"enorme","hambriento"}));
     break;
     }
  case OSA:
     {
     SetStandard("osa","osa",UsaFactor(9+random(6)),GENDER_FEMALE);
     SetShort("una osa "+QueryTipoStr());
     SetLong("Es una enorme osa "+QueryTipoStr()+" que busca algo de "
            "comida entre los matojos del suelo abriendose paso con "
            "sus grandes patas y afiladas garras. Su mirada de "
            "pocos amigos no anima mucho a pelear con ella. Podria "
            "destrozarte de un solo zarpazo.\n");
     SetWeight(UsaFactor(80000));
     SetAds(({"enorme","hambrienta"}));
     break;
     }
  case OSEZNO:
     {
     SetStandard("un osezno "+QueryTipoStr(),"osezno",UsaFactor(6+random(4)),GENDER_MALE);
     SetShort("un osezno "+QueryTipoStr());
     SetLong("Es un osezno "+QueryTipoStr()+" que busca algo de "
            "comida entre los matojos del suelo abriendose paso con "
            "sus grandes patas y afiladas garras. Su mirada de "
            "pocos amigos no anima mucho a pelear con el. Si bien aun "
            "no es un adulto podria ser bastante peligroso.\n");
     SetWeight(UsaFactor(50000));
     SetAds(({"hambriento"}));
     break;
     }
  }

  //SetRace("animal");
  //SetGender(GENDER_MALE);
  //SetIds(({"oso"}));
  //SetAds(({"enorme","hambriento"}));
  //SetLevel(10);
  //SetMaxHP(150);
  //SetHP(130);
  //SetDex(8);
  //SetStr(12);
  //SetInt(8);
  //SetWhimpy(0);
  //SetAlign(100);
  //SetAC(3);

  //SetName(QueryClaseStr());
  SetRace("oso");
  SetIds(({QueryClaseStr(),"animal"}));
  SetHands(({({"la boca",0,UsaFactor(10)}),({"la zarpa izquierda",0,UsaFactor(10)}),({"la zarpa derecha",0,UsaFactor(10)})}));

  InitChats(3,({
  capitalize(ART2)+" "+QueryClaseStr()+" se lame la miel que queda entre sus garras.\n",
  capitalize(ART2)+" "+QueryClaseStr()+" te mira desconfiad"+AO2+", aunque no parece "
  "tenerte ningun miedo.\n",
  capitalize(ART2)+" "+QueryClaseStr()+" se muestra irritad"+AO2+" y furios"+
  AO2+"o, tal vez por que este sea su territorio.\n",
  capitalize(ART2)+" "+QueryClaseStr()+" aparta un gran tronco sin esfuerzo "
  "aparente y se pone a rebuscar bajo el.\n",
  }));

  InitAChats(10,({
  capitalize(ART2)+" "+QueryClaseStr()+" aumenta el ritmo de su respiracion.\n",
  capitalize(ART2)+" "+QueryClaseStr()+" se pone en pie ante ti y da zarpazos al aire.\n",
  capitalize(ART2)+" "+QueryClaseStr()+" se lanza contra ti.\n"  }));

}
