/*
DESCRIPCION : cuentacuentos
FICHERO     : /d/kenton/comun/quest/bruja/velac.c
MODIFICACION: 16-7-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <living.h>
#include <combat.h>
#include <moving.h>

#include <money.h>
#include <properties.h>
#define T1 "titulo1" //titulo del primer cuento, sustituye titulo1 por lo q sea
#define T2 "titulo2" //titulo del primer cuento, sustituye titulo2 por lo q sea
#define T3 "titulo3" //titulo del primer cuento, sustituye titulo3 por lo q sea
#define T4 "titulo4" //titulo del primer cuento, sustituye titulo4 por lo q sea
#define T5 "titulo5" //titulo del primer cuento, sustituye titulo5 por lo q sea
#define C1 "cuento1\n" // adivina
#define C2 "cuento2\n" // adivina
#define C3 "cuento3\n" // adivina
#define C4 "cuento4\n" // adivina
#define C5 "cuento5\n" // adivina


inherit NPC;
int flag,flagg;
init() {

  ::init();

  add_action("pedir_cmd","preguntar");
  add_action("dar_cmd","decir");
  add_action("dar_cmd","'");
  add_action("cuentos_cmd","escuchar");
  add_action("escoger_cmd","escoger");

}

int pedir_cmd(string str) {
object from;
string nombre,cosa;
from=TP;
if (!from || !str) return 0;
if (sscanf(str,"a %s sobre %s",nombre,cosa)!=2)return 0;
if(nombre!="velac" && nombre!="Velac" && nombre!="cuenta cuentos") return 0;
if(cosa!="pelo"){write("Velac se encoge de hombros.\n");return 1;}
   write(W("Velac te dice:  Mmmmm... ¿Qué quereis hacer con mi cabello...? "
   "¿magia?¿maldades?¿brujería?.\n"));
flag=1;
return 1;
}
dar_cmd(string str){
object ob;
if(flag!=1)return 0;
if(flag=1)
{
if(str=="si"){write("Velac te dice: ¿Haces brujería? no te dare mi pelo.\n");flag=0;return 0;}
if(str=="no")
{
   								   ob=clone_object("/d/kenton/comun/quest/bruja/pelo");
								   if (ob->move(TP,M_SILENT)!=ME_OK)
								    {
								        tell_object(TP,"Velac te dice: ¡¡No puedes con el pelo!!.\n");
								        ob->remove();
									}
									else
									tell_object(TP,W("Velac te dice: Vale, tomad uno de mis cabellos.\n"
									"Ves como Velac tira de uno de sus cabellos y te "
									"lo da con una amplia sonrisa.\n"));
flag=0;
 }
 }
   return 1;
}
cuentos_cmd()
{
tell_room(environment(),"Velac dice: A ver, niños, ¿Qué historia quereis que os cuente?.\n");
tell_room(environment(),"Ves como los niños no se ponen de acuerdo y decides elegir.\n",(({TP})));
tell_room(environment(),W("Ves como los niños no se ponen de acuerdo y decides elegir.(pon escoger 'cuento' para elegir.)\n"));
flagg=1;
return 1;
}
escoger_cmd(string str)
{
if(flagg==0){tell_room(environment(),"Quizá deberías pararte a escuchar antes.\n");return 1;}
if(str!=T1 && str!=T2 && str!=T3 && str!=T4 && str!=T5){tell_room(environment(),"Velac dice: No conozco ese cuento.\n");return 1;}

tell_object(TP,W("Velac te sonríe y dice: De acuerdo, os contaré la historia de "+str+".\n"));
tell_room(environment(),W("Velac sonríe y dice: De acuerdo, os contaré la historia de "+str+".\n"),(({TP})));
if(str==T1)
{
tell_room(environment(),W(C1));
}
if(str==T2)
{
tell_room(environment(),W(C2));
}
if(str==T3)
{
tell_room(environment(),W(C3));
}
if(str==T4)
{
tell_room(environment(),W(C4));
}
if(str==T5)
{
tell_room(environment(),W(C5));
}
flagg=0;
return 1;
}

create() {
  ::create();
SetStandard("Velac","kender",20,GENERO_MASCULINO);
AddAdjective("el");
SetIds(({"cuentacuentos","cuentista","torpedo sexual"}));
SetNoGet(1);
SetShort("Velac, el cuenta cuentos");
SetLong(W("Es un kender apacible, bajito, como todos los kenders, con cara "
 "de bonachón y sonrisa que indica una vida llena de felicidad. Su "
 "cara esta marcada por las arrugas, quizás de tanto sonreir. Ves "
 "que está rodeado de críos. Quizás puedas escuchar algo de lo que "
 "dice.\n"));
SetAggressive(0); //0 no, 1 si.
SetAlign(100);
flag=0;
flagg=0;
InitChats(3,({"Velac dice: vamos a ver, cual quereis que os cuente?\n","Velac dice: Aqui ira una lista de los cuentos.\n" ,
"Velac dice: ¡¡¡Ese lo acabo de contar!!!.\n"}));
}



