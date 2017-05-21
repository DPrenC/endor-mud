/*
DESCRIPCION  : Taramu, el viejo enano cascarrabias del gremio de aventureros
FICHERO      : /d/limbo/comun/pnj/taramu.c
MODIFICACION : 29-09-98 [Angor@Simauria] Creacion
               24-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <messages.h>
inherit NPC;

#define AE      (TP->QueryGender()==2?"a":"e")
#define AO      (TP->QueryGenderEndString())
#define A_      (TP->QueryGender()==2?"a":"")
#define NOMBRE  (capitalize(TP->QueryName()))

void despertar();
static int dormido;

create() {
  ::create();
  SetStandard("Taramu","enano",5,GENDER_MALE);
  SetName("Taramu");
  SetShort("Taramu, el viejo aventurero");
  SetLong(
     "Taramu en un anciano enano que pasa las horas sentado en uno de los butacones "
     "del salón del ayuntamiento contanto mil una batallas de su época como "
     "aventurero. Sus historias suelen ser bastante fantasiosas, lo cual lleva a "
     "dudar de la veracidad de muchas de ellas. Es un tipo bastante quisquilloso, "
     "aunque por suerte pasa gran parte del tiempo durmiendo.\n");

  SetGoChance(0);

  SetAlign(500);
  SetAC(5);
  SetMaxHP(70);
  SetHP(70);

  SetIds(({"taramu","enano","anciano"}));

  despertar();

  AddQuestion(({"gremio","Gremio","aventureros","aventurero"}),
     "El Gremio de Aventureros está aquí en el ayuntamiento, en la sala que queda al "
     "oeste de la puerta principal. Yo pertenecí a ese gremio y aún lo hago, pero a "
     "mi edad ya no busco más emociones fuertes. Si yo te contara algunas de las "
     "grandes aventuras que he tenido...\n");

  AddQuestion(({"daga","daga enjoyada","daga de Der-Ulm","Der-Ulm","der-ulm"}),
    "Robe a unos piratas la daga enjoyada de Tarami en mi juventud, pero acabe tan "
    "borracho en aquella aventura que no se donde demonios la escondí.\n");

  AddQuestion(({"asthar","Asthar","templo","templo de Asthar"}),
    "Está en el sudeste de la isla, ... ¿o era en el norte?, no se. Mi memoria ya "
    "no es la que era.\n");

  AddQuestion(({"angor","Angor"}),
    "La cosa es que ese nombre me suena, pero no acabo de localizarlo. A ver, quizá "
    "sea un dios o tal vez el nombre que le di a mi primer caballo... no se.\n");

  AddQuestion(({"akkron","Akkron"}),
    "¿Akkron? es el secretario del ayuntamiento. No es mal tipo, pero su caracter es "
    "muy fuerte, lo cual le ocasiona bastantes problemas. El otro día tuvo que "
    "ayudarme cuando un novato intento robar aquí en el ayuntamiento. Esta juventud "
    "ya no respeta nada.\n");

  AddQuestion(({"playa","playa de levante","playa de Levante"}), "Está junto al mar, ¿no?.\n");
  AddQuestion(({"mar","oceano"}), "¡Esto es una isla! El oceano está alrededor.\n");
  AddQuestion(({"llaves","llaves del templo"}),
    "En el fondo del mar.... Je, je, es una broma. ¿Qué me habias preguntado?.\n");
Set(P_CANT_FIGHT,1);
Set(P_CANT_STEAL,1);
}

init() {
  ::init();
  add_action("matar_cmd","matar");
  add_action("decir_cmd","'");
  add_action("decir_cmd","decir");
  add_action("coger_cmd","coger");
}

int decir_cmd(string str){
  if ((!str)||(str!="si")) return 0;
  write(
    "Taramu dice:'Entonces quieres que te cuente una historia, bien. A ver, a ver, si "
    "ya se, te contaré aquella en la que yo solo venci a toda una banda de piratas "
    "y consegui la daga enjoyada de Der-Ulm. Pues bien, tendria yo unos 25, no, más "
    "bien unos 20 años y llegaron unos piratas. Eran gente cruel y sin compasión a la "
    "que solo les ahhhhh (bostezo)... interesaba el oro y las joyas. Saquearon la "
    "casa de mis padres y el resto del poblado en busca de lo poco de valor que alli "
    "pudiera haber. Así las cosas yo, inconsciente juventud, decidí vengarme de "
    "aquella afrenta y por la noche me colé en el barco de los piratas, que por "
    "suerte se habian emborrachado con ahhhhh (bostezo) la cosecha local de vino que "
    "habian robado. Les robe una fabulosa daga con piedras preciosas que el capitan "
    "guardaba con celo, pero ahhhhh (bostezo) me vieron un par de piratas y tuvé que "
    "hacerme pasar por uno de ellos bebiendo como un cosaco. No se como, pero logre "
    "regresar a la isla y ahhhhhhhh (gran bostezo) la escondi, pero como estaba tan "
    "borracho ahhhhhh (gran bostezo) no recuerdo ahhhhhhh (gran bostezo) donde....' "
    "Taramu se ha dormido placidamente.\n");
  tell_room(environment(TP), ({ MSG_SEE,
    "Taramu comienza a contarle a "+NOMBRE+" una de sus largas y fantasiosas "
    "aventuras de juventud. "+NOMBRE+" aguanta el tipo sin bostezar hasta que "
    "finalmente Taramu se queda dormido.\n"}), ({ TP }));

  InitChats(3,({
    "Taramu duerme apaciblemente.\n",
    "'Zzzzz....Zzzzzz...'.\n",
    "Taramu cabecea en la butaca. En una de estas se despierta de nuevo.\n",
    "'Zzzzzzzzz....Zzzz....Zzzzz...'.\n",
    "Taramu ronca que da gusto.\n" }));
  dormido=1;
  call_out("despertar",120);
  return 1;
}

void despertar(){
  dormido=0;
  say(
  "Taramu da un cabeceo más brusco de lo normal y se despierta algo desorientado.\n" //
  "Taramu dice:'Eh, ¿dónde estoy? Ah, ya. Vaya, me he vuelto a dormir un rato'.\n");

  InitChats(3,({
  "\nTaramu te dice:'Sabes, el otro dia uno intento robar aquí en el ayuntamiento. "
  "¡Valiente sinverguenza! Pero yo le vi y avise a Akkron que lo detuvo. Ahora "
  "debe estar prisionero en algun lugar. Soy miembro un ciudadano responsable y "
  "era mi deber'.\n",
  "\nTaramu dice: '¡Ay si yo te contara! Yo he sido un gran aventurero aunque "
  "ahora solo veas a un pobre viejo. Si me dices que si, te contare alguna de "
  "las increibles aventuras que tuve cuando era más joven'.\n",
  "\nTaramu cabecea. Seguro que se duerme en cualquier momento. "
   }));
}


int matar_cmd(string str){
  object who;
  if (!str) return 0;

  if (!((str="taramu")||(str="Taramu")||(str="enano")||(str="viejo"))) return 0;

  who=TP;
  if (present(str, environment(who)) != TO) return 0;
  who->StopHunting(TO);
  write(
    "Taramu es pobre anciano que no representa ninguna amenaza. Además si le da por "
    "gritar seguro que aparece Akkron y ese si es una amenaza seria. Piensas que no "
    "merece la pena. Taramu te dice: '¿Te pasa algo?'\n");
  return 1;
}

int coger_cmd(string str)
{
 object obj;
 if (!str) return notify_fail("¿Qué es lo que quieres coger?\n",NOTIFY_NOT_VALID)&&0;
 if (str=="cabezas"){write("No puedes ya que están firmemente sujetas a la pared.\n");return 1;}
/*
// modificado por KoRSaRio... no podias coger nada que no fuera la red...
 if ((str=="red")||(str=="cazacangrejos")||("red cazacangrejos")) {
*/
if ((str=="red")||(str=="cazacangrejos")||(str=="red cazacangrejos")){
    if (dormido==0){
       write(
          "Te subes a un butacón y con cuidado desenganchas la red de la madera, pero "
          "cuando estás a punto de guardartela, el sillón chirria y el viejo Taramu "
          "despierta de nuevo. Al verte subid"+AO+" al butacón con la red en las manos dice: "
          "'No estarias tratando de robar ese trofeo ¿verdad?' Dibujas una sonrisa de "
          "circunstancias y dices todo lo seri"+AO+" que puedes: 'No, no, que va, solo "
          "estaba mirandola de cerca'. Vuelves a colocar la red en su sitio maldiciendo "
          "entre dientes lo ligero que tiene el suenyo el viejo. Debe haber otra forma...\n");
       say(
          NOMBRE+" se sube a un butacón e intenta coger la red cazacangrejos, pero en "
          "ese momento el viejo Taramu se despierta y le ve. "+NOMBRE+" se excusa y "
          "devuelve la red a su sitio.\n",TP);
          return 1;
       }
     else{
// Lo siguiente ha sido anyadido por Izet@Simauria, para que los jugatas
// no se pasen cogiendo redes de pesca.
       if (!present("red",TP) ) {
       write(
          "Te subes a un butacón y con cuidado desenganchas la red de la madera para luego "
          "guardártela. El viejo Taramu está dormido y no te ha visto...\n");
       say(
          NOMBRE+" se sube a un butacón y coge la red cazacangrejos que habia en la pared.\n",TP);
       obj=clone_object(OTRO("cazacangrejos"));
       obj->move(TP);
       return 1;
       } else {
         write("No hay más redes cazacangrejos en la pared.\n");
         return 1;
       }
     }
} else { return 0; }
}

