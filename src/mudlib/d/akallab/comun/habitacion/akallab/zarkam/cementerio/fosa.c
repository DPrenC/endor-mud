/*
DESCRIPCION : fichero base de una fosa del cementerio
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/fosa.c
MODIFICACION: 25-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO

inherit ROOM;

#define PROB_MUERTO  75

public int abierta;       //se puede salir al exterior? 0=no, 1=si
public int agujero;       //puedes ir a la del al lado? 0=no, 1=si
public int saqueada;      //ataud intacto? 0=no, 1=si;

static int ataud_abierto;
static int ataud_vacio;
static int zombie;
static int skeleton;


reset() {
  ::reset();
  ataud_abierto=0;
  ataud_vacio=0;
  zombie=1;
}


string mirar_ataud(string str) {
if (saqueada==1)
   return "El ataud esta destrozado y los huesos esparcidos por el suelo. Si habia algo de "
          "valor, quien saqueo la tumba debio llevarselo.\n";

if (ataud_abierto==0)
   return "El ataud es una tosca caja rectangular de madera. Esta cerrado y no puedes ver "
          "que contiene en su interior.\n";
else
   return "El ataud es una tosca caja rectangular de madera. Esta abierto y en su interior "
          "puedes ver los restos de su propietario envueltos entre telas medio podridas. "
          "Aunque la idea no te resulte muy atractiva, piensas que se podrian registrar los "
          "restos para ver si se encuentra algo de valor en ellos.\n";
}


int abrir_cmd(string str) {
  if (str!="ataud") return 0;
  if (ataud_abierto==0) {
    write("Tras forcejear con la tapa, finalmente consigues abrir el ataud.\n");
    say(NOMBRE+" abre el ataud de esta tumba.\n",TP);
    ataud_abierto=1;
    return 1;
    }
  else {write("El ataud ya estaba abierto!\n"); return 1;}
}


int cerrar_cmd(string str) {
  if (str!="ataud") return 0;
  if (ataud_abierto==1) {
    write("Cierras el ataud con su tapa.\n");
    say(NOMBRE+" cierra el ataud de esta tumba.\n",TP);
    ataud_abierto=0;
    return 1;
    }
  else {write("El ataud ya estaba cerrado!\n");return 1;}
}


int registrar_cmd(string s) {
  object obj;
  int cobre, plata, oro;
  string str;

  if ((s!="restos")&&(s!="los restos")) return 0;
  if (ataud_abierto==0) {write("No ves ningunos restos por aqui cerca.\n"); return 1;}

  if (ataud_vacio==1) {
     write("Registras los putrefactos restos del ataud pero no consigues encontrar nada de "
           "valor. Sin duda alguien se te ha debido adelantar y ha limpiado el cadaver.\n");
     return 1;
     }
  else{
     //sorpresa?
     if (((random(100)<PROB_MUERTO?1:0)==1)&&(zombie==1)){
        write("Cuando estas registrando los restos del ataud de repente sientes que una fria "
              "mano te atrapa la munyeca. De repente una luz roja brilla en las cuencas "
              "vacias de los ojos del muerto que hay en el ataud y este se levanta dispuesto "
              "a atacarte.\n");
        obj=clone_object(PNJ("monstruo/muerto"));
        obj->SetAggressive(1);
        obj->SetGoChance(0);
        obj->move(TO);
        zombie=0;
        return 1;
        }
     else{
        cobre=4+random(8);
        plata=random(4);

        oro=random(2);
        obj=clone_object("/obj/money");
        obj->AdjustMoney((["cobre":cobre, "plata":plata]));
        obj->move(TP);
        str="Encuentras "+cobre+" monedas de cobre";
        if (plata!=0) str+=", "+plata+" de plata";
        if (oro!=0) str+=" y "+oro+" de oro";
        str+=" en el interior de ataud.\n";
        write(str);
        say(NOMBRE+" coge algo del ataud de la tumba.\n",TP);
        ataud_vacio=1;
        call_out("reset",300);
        return 1;
        }
     }
}

create() {
  string str;

  ::create();
  //descripcion y detalles
  SetIntShort("el interior de una tumba");
  str="";
  switch(random(2)){
    case 0: str+="Te encuentras en el interior de una tumba, en una estrecha fosa excavada en la "
                 "tierra. La fosa tendra un metro de ancho por dos y medio de largo y unos tres "
                 "de alto. Supones que esto ultimo es para apilar varios ataudes en su interior.\n";break;
    case 1: str+="Estas en el fondo de la estrecha fosa de una tumba. Un silencio sepulcral y un "
                 "aire humedo y putrefacto son tu unica companyia. La fosa es un estrecho y alto "
                 "agujero excavado en la tierra en el que apenas cabe el ataud de su propietario.\n";break;
    }

  if (abierta==0){
     str+="La lapida de la tumba que tienes sobre tu cabeza esta firmemente cerrada.\n";
     AddDetail(({"lapida"}),
        "La lapida es una gruesa plancha de piedra que cubre la fosa de la tumba. Parece "
        "muy pesada y esta en perfecto estado. Piensas que jamas podras levantarla y "
        "salir por ella al exterior de la tumba.\n");
     }
  else{
     str+="La lapida de la tumba que tienes sobre ti esta rota, permitiendote salir.\n";
     AddDetail(({"lapida","boquete"}),
        "La lapida es una gruesa plancha de piedra que cubre la fosa de la tumba. Parece "
        "muy pesada pero esta rota. Crees que podrias pasar por el boquete que hay en "
        "ella y salir al exterior de la tumba.\n");
     }

  if (saqueada==1) str+="La tumba ha debido ser saqueada, ya que el ataud que ves ante ti esta destrozado "
                        "y los huesos esparcidos por el suelo. Si habia algo de valor, ya no esta aqui.\n";
             else str+="El ataud que tienes ante ti esta intacto. Piensas que o bien esta tumba no era "
                       "de interes para los saqueadores o bien el ataud lleva poco tiempo aqui.\n";

  if (agujero==1){
     str+="Un boquete en la pared de la fosa te permite pasar a la de al lado.\n";
     AddDetail(({"boquete","agujero"}),
          "En la parede de la fosa hay un agujero que te permite pasar a la fosa de al lado. "
          "Piensas que lo mas probable es que lo hayan hecho los saqueadores de tumbas.\n");
     }

  SetIntLong(str);

  AddDetail(({"ataud"}), SF(mirar_ataud));

  SetIntNoise("Hay un silencio sepulcral.\n");
  SetIntSmell("Huele a tierra humeda y a putrefaccion.\n");
  SetLocate("cementerio de Zarkam");

  if (abierta==0){
       SetIndoors(1);
       SetIntBright(0);
       }
  else SetIndoors(0);

  AddRoomCmd("abrir",SF(abrir_cmd));
  AddRoomCmd("cerrar",SF(cerrar_cmd));
  AddRoomCmd("registrar",SF(registrar_cmd));

  reset();
}
