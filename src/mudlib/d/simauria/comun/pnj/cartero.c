/* banquero.c
Cartero estandard para Simauria basado en el esclavo de Angor (Akallab).

[m]

27/10/98 [m] Creacion del archivo.

*/

inherit NPC;

#include "./path.h"
#include <living.h>
#include <combat.h>
#include <properties.h>

#define AO      (TP->QueryGenderEndString())
#define A_      (TP->QueryGender()==GENDER_FEMALE?"a":"")

#define A_2     (QueryGender()==GENDER_FEMALE?"a":"")
#define AO2     QueryGenderEndString()
#define LAEL    (QueryGender()==GENDER_FEMALE?"La":"El")
#define LAEL2    (QueryArtDetString())

#define N_MAS ({"Cennort","Pect","Voig","Zoart","Glow","Mong","Crot"})
#define N_FEM ({"Frea","Hela","Fili","Betwa","Rena","Nella"})

void inicializa(){
 int i;
 string *nombres;

 i=random(100);
 (i>=75)?SetGender(GENDER_FEMALE):SetGender(GENDER_MALE);
 if (QueryGender()==GENDER_FEMALE) nombres=N_FEM;
                              else nombres=N_MAS;
 i=sizeof(nombres);
 SetName(nombres[random(i)]);

    SetRace("humano");
    SetWeight(70000-(QueryGender()==GENDER_FEMALE?15000:0));
    SetMaxHP(75);
    SetHP(60);
    SetLevel(4);
    SetStr(4);
    SetDex(4);
    SetCon(4);
    SetInt(5);
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    return;

    }

create() {
  ::create();
 inicializa();
  SetShort((QueryName()+(QueryGender()==GENDER_FEMALE?" la cartera":" el cartero")));
  SetLong(
     QueryName()+" es "+LAEL2+" carter"+AO2+" de esta ciudad. Se encarga de enviar los mensajes\n"
     "y de clasificar los que llegan. Normalmente esta muy ocupad"+AO2+".\n");
  SetAlign(200);
  SetGoChance(0);
  SetAC(1);
  SetIds(({QueryName(),QueryRace(),(QueryGender()==GENDER_FEMALE?"cartera":"cartero")}));

InitChats(4,({LAEL+" carter"+AO2+" tararea una cancion.\n",
 LAEL+" carter"+AO2+" mira al trasluz un mensaje.\n",
 QueryName()+" dice: Hmmm, esta zona no la conozco.\n",
 LAEL+" carter"+AO2+" trabaja sin descanso.\n",
 QueryName()+" carter"+AO2+" te pregunta: quieres algo?\n",
 LAEL+" carter"+AO2+" dice: Hmm, este se ha equivocado\n"
 "Y tira la carta a un cubo\n"}));

AddQuestion(({"nombre"}),
 LAEL+" carter"+AO2+" dice sin girarse: Me llamo "+QueryName()+".\n");
AddQuestion(({"mensaje"}),
 LAEL+" carter"+AO2+" dice: Para enviar un mensaje a alguien escribe correo seguido del\n"
 "nombre a quien quieras enviarselo.\n");

 }