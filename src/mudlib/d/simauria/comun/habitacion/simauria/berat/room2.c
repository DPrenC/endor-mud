/*
 Creado por Icaro, seguramente, aunque no puso cabecera.
 Así que yo, Nemesis, reclamo esta habitación y le hago
 algunas guarreridas, como cambiar el cuadro de Icaro
 por otro de unos perros jugando a las cartas.
 Y también añadir un bonito explorer point, que me aburría ;)
*/

#define HP TP->QueryHP()
#define MAXHP TP->QueryMaxHP()
#include "path.h"
#include "/secure/wizlevels.h"
#include <door.h>
#include <properties.h>
#include <materials.h>



inherit SIM_ROOM;
static int despertar();
static int suenyo();

string VerPerro()
{
    TP->SetExplored();
    return"Mirándolo bien te recuerda te recuerda a... ¡Anda! Si se parece mogollón a ti.\n";
}

create()
{
    ::create();
    SetIntShort("la posada de Grenel");
    SetIntLong("Te hallas en la habitación noble de la posada de Grenel. En ella ves una "
        "confortable cama en la que poder reposar.\nÚnicamente un cuadro adorna la habitación, "
        "iluminada por una antorcha.\n");
    SetIntBright(70);
    SetIndoors(1);
    AddDetail(({"antorcha"}),"Es una antorcha normal y corriente. Ilumina la estancia con su luz.\n");
    AddDetail(({"cuadro"}),"Representa a un grupo de perros jugando a las cartas. Te preguntas "
        "a quién se le ocurriría algo tan estúpido.\n");
    AddDetail(({"firma","firma del cuadro"}),"No está firmado. Parece que nunca sabrás quién "
        "es el responsable de 'eso'...\n");
    AddDetail(({"perros","perros jugando a las cartas","perros ludópatas"}),
        "El de las orejas puntiagudas te recuerda a alguien.\n");
    AddDetail(({"perro de orejas puntiagudas",
	       "perro con orejas puntiagudas",
	       "perro que me recuerda a alguien",
 	      "perro de orejas puntiagudas que me recuerda a alguien",
	       "perro con orejas puntiagudas que me recuerda a alguien"}),SF(VerPerro));
	   AddDetail(({"cama"}),"Es una cama confortable de tamaño normal. Las sábanas están limpias, "
        "y se puede dormir en ella sin mayores problemas.\n");
    AddExit("pasillo","./fonda2");
    AddDoor("pasillo","la puerta del pasillo","Es una puerta de madera lisa, aunque muy bien pintada y barnizada.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE,"llave2nob",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}

init()
{
    (::init());
    add_action("getaction","",1);
        getinput();
}

getaction(string str) { return getcmds(query_verb() ); }

getinput(string str) {
  mixed ret;
    if (ret = getcmds(str)) input_to("getinput");
    return ret;
}

getcmds(string str) {
   if (find_call_out("suenyo") == -1) {
      switch(str) {
         case "dormir": { descansar(); return 1; }
         case "descansar": { descansar(); return 1; }
         case "despertar": { write("Pero... no estas durmiendo!\n"); return 1; }
         default: { return 0; }
      }
   }
   if (find_call_out("suenyo") != -1) {
     switch(str) {
       case "estado": {
            return 0;
       }
       case "quien": {
            return 0;
       }
       case "canales": { return 0; }
       case "abandonar": {
             despertar();
             return 1;
             }
       case "exit": {
            despertar();
            return 1;
            }
       case "reiniciar": {
            despertar();
            return 1;
            }
       case "quit": {
            despertar();
            return 1;
            }
       case "despertar": {
            despertar();
            return 1;
       }
       case "dormir": {
            write("Ya estas durmiendo.\n");
            return 1;
       }
       default: {
             if (IS_LEARNER(TP) ) { return 0; }
             else {
                if (str[0..0] == "=") return 0;
                if (str[0..4] == "canal") return 0;
                if (str[0..4] == "ayuda") return 0;

                write("No puedes hacer eso mientras duermes.\n");
                return 1;
             }
       }
     }
  }
}

int descansar() {
    if (HP >= MAXHP) {
       write("No tienes sueño.\n");
       return 1;
    } else {
    write(
"Te acercas a la cama y duermes. Escribe 'despertar' para levantarte.\n");
    suenyo();
    return 1;
   }
}
static int suenyo() {
if ( HP >= MAXHP -9 )
{
    despertar();
} else {
  TP->SetHP(HP + 10);
  switch(random(5)) {
    case 0: write("Zzzz... Zzzz... Zzzz...\n");
            break;
    default: break;
  }
  call_out("suenyo",5);
  return 1;
   }
}

static int despertar() {
   remove_call_out("suenyo");
   write("\nTe despiertas despues de tu descanso.\n\n");
   TP->LookAfterMove();
    return 1;
}
