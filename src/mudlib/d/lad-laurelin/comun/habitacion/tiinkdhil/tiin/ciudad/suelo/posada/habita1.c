/*

 La unica diferencia es el SetHp(quality)

*/



#define HP TP->QueryHP()
#define MAXHP TP->QueryMaxHP()
#include "./path.h"
#include "/secure/wizlevels.h"
inherit ROOM;
static int despertar();
static int suenyo();

create() {
   ::create();

  SetIntShort("una habitacion en la posada El Viajero.");
  SetIntLong(
"Sin decoracion alguna, esta debe ser la mas pequenya de las habitaciones. La\n"
"cama ocupa toda la estancia y no es que sea demasiado grande, aunque servira\n"
"para descansar un rato y recuperarte un poco.\n");
   SetIntBright(70);
   SetIndoors(1);


   AddDetail(({"alfombra","gran alfombra"}),
"Es de color rojo y cubre todo el suelo de la habitacion.\n");
  AddDetail(({"cama"}),
"Una cama preparada, con sabanas limpias en la que puedes dormir.\n");
  AddExit("pasillo","./pasillo1");
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
    write(
"Te acercas a la cama y duermes. Escribe 'despertar' para levantarte.\n"
    );
    suenyo();
    return 1;
   }
}
int suenyo() {
if ( HP >= MAXHP )
{
    despertar();
} else {
  TP->SetHP(HP + 1);
  switch(random(5)) {
    case 0: write("Zzzz... Zzzz... Zzzz...\n");
            break;
    default: break;
  }
  call_out("suenyo",1);
  return 1;
   }
}

int despertar() {
   remove_call_out("suenyo");
   write("\nTe despiertas despues de tu descanso.\n\n");
   TP->LookAfterMove();
    return 1;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                         