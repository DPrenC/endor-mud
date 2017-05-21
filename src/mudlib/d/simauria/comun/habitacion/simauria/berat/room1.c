//[Maler]
#define HP TP->QueryHP()
#define MAXHP TP->QueryMaxHP()
#include "./path.h"
#include "/secure/wizlevels.h"
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <sounds.h>



inherit SIM_ROOM;
static int despertar();
static int suenyo();

create() {
   ::create();

  SetIntShort("la posada de Grenel");
  SetIntLong(W("Esta debe ser la habitacion mas modesta de la "
"posada, unicamente tiene una pequeña cama, y un cuadro.\n"));
   SetIntBright(70);
   SetIndoors(1);


   AddDetail(({"cuadro","pequeño cuadro"}),
"Representa un paisaje lleno de flores.\n");
  AddDetail(({"cama"}),
"Es una pequeña cama, preparada para poder dormir tranquilamente.\n");
  AddExit("pasillo","./fonda2");
AddDoor("pasillo","la puerta del pasillo","Es una puerta de madera lisa, muy corriente.\n",
    ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE,"llave1hum",
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
}
init() {
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
       write("No tienes suenyo.\n");
       return 1;
    } else {
    write("Te acercas a la cama y duermes. Escribe 'despertar' para levantarte.\n");
    suenyo();
    return 1;
   }
}
static int suenyo() {
if ( HP >= MAXHP -4 )
{
    despertar();
} else {
  TP->SetHP(HP + 5);
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