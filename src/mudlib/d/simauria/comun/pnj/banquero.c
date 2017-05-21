/* banquero.c
Banquero estandard para Simauria basado en el esclavo de Angor (Akallab).

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

#define N_MAS ({"Bracco","Batio","Atenul","Larssen","Fimur","Jerm","Colen","Langlic"})
#define N_FEM ({"Radie","Lena","Meinl","Lindem","Anja","Reiji"})

void inicializa(){
 int i;
 string *nombres;

 i=random(100);
 (i>=75)?SetGender(GENDER_FEMALE):SetGender(GENDER_MALE);
 if (QueryGender()==GENDER_FEMALE) nombres=N_FEM;
                              else nombres=N_MAS;
 i=sizeof(nombres);
 SetStandard(nombres[random(i)], "humano",4,QueryGender());

    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    return;

    }

create() {
  ::create();
 inicializa();
  SetShort((QueryName()+(QueryGender()==GENDER_FEMALE?" la banquera":" el banquero")));
  SetLong(
     QueryName()+" es "+LAEL2+" banquer"+AO2+" de esta ciudad. Se encarga de llevar los libros\n"
     "de la oficina al dia y de las transacciones de los clientes.\n");
    Set(P_CANT_LURE,1);
    SetAlign(200);
  SetGoChance(0);
  SetAC(1);
  SetIds(({QueryName(),QueryRace(),(QueryGender()==GENDER_FEMALE?"banquera":"banquero")}));

 InitChats(4,({"El banquero tararea una cancion.\n",
  LAEL+" banquer"+AO2+" mira el libro de cuentas.\n",
  QueryName()+" mira el libro de cuentas y\n\
  dice: Hmmm, este se esta haciendo rico.\n",
  QueryName()+" banquer"+AO2+" trabaja sin descanso.\n",
  "Si quieres saber las condiciones del banco puedes coger uno de los\n\
  folletos que hay en el mostrador.\n",
  LAEL+" banquer"+AO2+" te pregunta: quieres algo?\n"}));

AddQuestion(({"nombre"}),
 LAEL+" banquer"+AO2+" dice sin girarse: Me llamo "+QueryName()+".\n");
AddQuestion(({"mensaje"}),
 LAEL+" banquer"+AO2+" dice: Para operar con tu cuenta, puedes coger un folleto\n"
 "que hay sobre el mostrador.\n");

 }