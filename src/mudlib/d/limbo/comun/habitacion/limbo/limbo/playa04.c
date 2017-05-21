/*
DESCRIPCION  : playa de Levante
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/playa04.c
MODIFICACION :

27-07-98 [Angor@Simauria] Creacion
14-02-00 [Angor@Simauria] wrap, corregido el bug consistente en que
         si fallaba al darte los objetos, no caian al suelo
*/

#include "./path.h"
#include <config.h> //[a] anyadido por NOTIFY_NOT_CMD
#define NOMBRE  (capitalize(TP->QueryName()))
//
inherit LIMBO("playa");

static int vacio, cangrejo;

reset() {
  ::reset();
  cangrejo=0;
  vacio=0;
}

string mirar_agujero(){
  if (vacio==0) return
     W("En uno de los agujeros de las rocas ves algo que brilla. Al acercarte un poco te "
     "das cuenta de que se trata de unas llaves.\n");
  else return
     "Es un peque�o agujero en la roca. No tiene nada de especial.\n";
}

string mirar_llaves(){
if (vacio==0) return
 W("Son tres llaves de tama�o mediano hechas de plata. Cada una tiene incrustada "
 "en su cabeza una gema de gran valor y las tres se hallan engarzadas en una "
 "argolla de oro.\n");
else
  if (cangrejo==1) return
     W("Las llaves las tiene el cangrejo dentro del agujero, por lo apenas si puedes "
     "verlas cuando te asomas al agujero.\n");
  else return "No ves ningunas llaves por aqu�.\n";
}

string mirar_cangrejo(){
if (vacio==0) return "El cangrejo se esconde en el fondo del agujero de la roca.\n";
else return "No ves ning�n cangrejo por aqu�.\n";
}


int coger_cmd(string str) {
  if (str=="cangrejo"){
     write("No puedes coger el cangrejo ya que se esconde al final del agujero de la roca.\n");
     return 0;
     }
  if (str!="llaves") return 0;
  if (cangrejo==0){
      write(W("Alargas el brazo para coger las llaves del agujero pero cuando estas a punto de "
            "lograrlo aparece un cangrejo desde el interior que las atrapa con una de sus "
            "pinzas y se retira de nuevo al interior del agujero. Ahora es el cangrejo quien "
            "tiene las llaves y no parece querer soltarlas.\n"));
      say(NOMBRE+" trata de coger algo de un agujero en la roca, pero falla.\n",TP);
      cangrejo=1;
      return 0;
      }
  else{
      write(W("Las llaves ahora las tiene el cangrejo y no parece querer soltarlas. Adem�s se "
            "ha escondido al final del agujero de la roca y no parece querer salir de all�.\n"));
      return 0;
      }
}


//public varargs usar_cmd(string str) {
int usar_cmd(string str) {
  string que,donde;
  object ob,llaves;

  if (!str) return notify_fail("�Qu� es lo que quieres usar?\n",NOTIFY_NOT_VALID)&&0;
  if (sscanf(str,"%s con %s",que,donde)<2) return notify_fail("�Usar qu� con qu�?\n"),0;

  //if ((sscanf(str,"red")==1)&&((sscanf(str,"cangrejo")==1)||(sscanf(str,"agujero")==1))){
  if ((que=="red")&&((donde=="cangrejo")||(donde=="agujero"))){

     ob  =  present("cazacangrejos",TP);
     if (!ob){
        say(W("Tras mirar atentamente las rocas llenas de cangrejos, "+NOMBRE+" revisa sus "
            "cosas en busca de algo, pero finalmente parece cambiar de idea y no hace nada. "),TP);
        write("Revisas tu inventario pero no encuentras una red con la que atrapar cangrejos.\n");
        return 1;
        }

     //if (call_other(ob,"id","cazacangrejos_cebada")){

     /*write((string)ob->QueryIds());
     write("\n");
     write((string)member(ob->QueryIds(),"cazacangrejos_cebada"));
     write("\n");

     write(member(ob->QueryIds(),"cazacangrejos_cebada"));
     write("\n");*/

     //if (member(ob->QueryIds(),"cazacangrejos_cebada")!=-1){

     if (ob->QueryCebada()==1){
         say(
           W("Tras mirar atentamente las rocas llenas de cangrejos, "+NOMBRE+" revisa sus "
            "cosas en busca de algo. Coge una especie de bolsa hecha con una red en cuyo "
            "interior parece haber alg�n tipo de cebo, y la coloca frente a una agujero de la "
            "roca. Un cangrejo es atra�do por el cebo y cae en la trampa, que "+NOMBRE+" "
            "recoge r�pidamente.\n"),TP);
         write(
           W("Sacas la red cazacangrejos. H�bilmente y con cuidado colocas la trampa frente al "
            "agujero de las rocas en el que se ha escondido en cangrejo, para a continuaci�n "
            "retirarte un poco. Al momento el cangrejo se asoma al exterior con las llaves en "
            "una de las pinzas y no pudiendo resistir la tentaci�n entra en la red. Te "
            "acercas y retiras la trampa.\n"));
         ob->descebar();
         ob=clone_object(PNJ("cangrejo"));
         llaves=clone_object(OTRO("llaves_templo"));

         if (TP->QueryWeight()+ob->QueryWeight()>TP->QueryMaxWeight())
            {
            write("No puedes cargar con nada m�s. El cangrejo se te cae al suelo.\n");
            ob->move(environment(TP));
            }
         else
            {
            ob->move(TP);
            write("Coges el cangrejo de la red.\n");
            }

         if (TP->QueryWeight()+llaves->QueryWeight()>TP->QueryMaxWeight())
            {
            write("No puedes cargar con nada m�s. Las llaves se te caen al suelo.\n");
            llaves->move(environment(TP));
            }
         else
            {
            llaves->move(TP);
            write("Coges las llaves de la red.\n");
            }

         vacio=1;
         call_out("reset",300); //5 minutos
         return 1;
         }
      else{
         write("La red cazacangrejos no est� cebada y por lo tanto no atraer� al cangrejo.\n");
         return 1;
         }
     }
  else{
     if ((que=="red")||(donde=="red")) {notify_fail("�Usar red con qu�?\n");return 0;}
     if ((que=="cangrejo")||(donde=="cangrejo")) {notify_fail("�Usar qu� con cangrejo?\n");return 0;}
     if ((que=="agujero")||(donde=="agujero")) {notify_fail("�Usar qu� con agujero?\n");return 0;}
     notify_fail("�Usar qu� con qu�?\n");
     return 0;

     /*if (sscanf(str,"red")==1) return notify_fail("Usar red con que?\n", NOTIFY_NOT_CMD);
     if (sscanf(str,"cangrejo")==1) return notify_fail("Usar que con cangrejo?\n", NOTIFY_NOT_CMD);
     if (sscanf(str,"agujero")==1) return notify_fail("Usar que con agujero?\n", NOTIFY_NOT_CMD);
     return notify_fail("Usar que con que?\n", NOTIFY_NOT_CMD);*/
     }
}


create() {
  ::create();
  SetIntShort("la playa de Levante");
  SetIntLong(
     W("Has llegado al extremo norte de la playa de Levante. Aqu� la playa "
       "acaba en las rocas al pie del acantilado de que forman las monta�as "
       "del norte de la isla. Las olas te salpican al chocar contra las "
       "rocas. Al suroeste, observas las dunas que el viento ha formado "
       "al llevarse arena de la playa. Ves algo que brilla en el fondo de "
       "un agujero entre las rocas.\n"));

AddDetail(({"acantilado","montanyas","monta�as"}),
 W("En la parte norte de la isla Limbo hay algunas monta�as elevadas que hacen "
 "que la costa norte sea una banda continua de altos y rocosos acantilados. Te "
 "hayas al principio de esta zona de costa.\n"));

AddDetail(({"rocas","roca"}),
 W("Las olas embisten incansablemente las rocas de la costa. Ten cuidado si piensas "
 "caminar sobre las rocas, pues estan muy resbaladizas y una caida podr�a resultar "
 "fatal.\n"));

AddDetail(({"hueco","agujero"}),SF(mirar_agujero));
AddDetail(({"llaves","llave"}),SF(mirar_llaves));
AddDetail(({"cangrejo"}),SF(mirar_cangrejo));

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
W("La isla Limbo es el lugar magico de Simauria donde habitan los dioses. Gracias "
"a ellos, es en este lugar donde las almas de los seres se encarnan y dan sus "
"primeros pasos para vivir en este mundo.\n"));

 AddDetail(({"playa","playa de Levante"}), QueryIntLong());

 AddDetail(({"duna","dunas"}),
W("Son grandes montones de arena arrastrados por el viento desde la playa hasta el "
"l�mite del bosque, donde la vegetaci�n contiene su avance.\n"));

SetIntNoise("Oyes las olas chocar contra las rocas.\n");
SetIntSmell("Huele a mar.\n");
SetLocate("isla Limbo");
SetIndoors(0);
AddExit("suroeste",LIMBO("playa02"));
AddRoomCmd("coger",SF(coger_cmd));
AddRoomCmd("usar",SF(usar_cmd));
reset();
}
