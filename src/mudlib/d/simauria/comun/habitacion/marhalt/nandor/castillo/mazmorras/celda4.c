//4.c (c) Nemesis@Simauria
//Celda numero 4

#include "./path.h"
#include <properties.h>
#include <moving.h>
#include <sounds.h>
#include <materials.h>
#include <door.h>

inherit SIM_ROOM;

private int removido;


remover(str) {
object ob;
if (!str) { write("QUE quieres remover?\n"); }
else {
 if (str!="paja") {
 write("No hay nada parecido a "+str+" por aqui.\n");
 }
 else {
   if (removido) write("Demasiado tarde, se te han adelantado...\n");
   else {
   write("Remueves la paja y encuentras... UNA PALA!\n");
   ob=clone_object("/std/thing");
   ob->SetShort("una oxidada pala");
   ob->SetLong("Es una pala oxidada.\n");
   ob->Set(P_GENDER,GENDER_FEMALE);
   ob->SetValue(125);
   ob->SetWeight(2000);
   ob->SetIds(({"pala","qpala"}));
   ob->move(TO, M_SILENT);
   removido=1;
   RemoveDetail(({"cama","camastro"}));
   RemoveDetail(({"paja"}));
   TO->AddDetail(({"cama","camastro"}),
   "Alguien ha removido la paja...\n");
   TO->AddDetail(({"paja"}),"Alguien la ha removido.\n");
  }
 }
}
return 1;
}



init() {
    add_action("remover","remover");
    ::init();
}

reset() {
    removido=0;
    ::reset();
}


create () {
    ::create();
    SetIntShort("una húmeda celda");
    SetLocate("el castillo de Nandor");
    SetIntLong("Te encuentras en una pequeña y húmeda celda. Lo único que te acompaña "
    "son un cutre camastro de paja y una vieja silla.\n En una de las paredes se "
    "aprecia una inscripción.\n");
    SetIntBright(10);
    SetIntSmell("Huele a humedad.\n");
    SetIntNoise(
    "Extrañamente no se oye nada. El lugar esta tan silencioso como una tumba...\n");
    AddDetail("paja",
    "Está puesta como si alguien hubiera escondido algo debajo...\n");
    AddDetail(({"cama","camastro"}),
    "Es una yacija cubierta de paja. No parece demasiado cómoda.\n Parece que "
    "alguien se ha encargado de extender la paja cuidadosamente... Te preguntas "
    "el por que...\n");
    AddDetail(({"inscripción","pared", "inscripcion"}),
    "Quizá puedas leer la inscripción.\n");
    AddDetail(({"vieja silla","silla"}),
    "Es una silla como otra cualquiera, si bien está cubierta de polvo.\n");
    AddReadMsg(({"inscripcion","inscripción","pared"}),
     "Pone: 'El del numero dos tiene tos.'\n");
    AddExit("norte","./pasillo5");
    AddDoor("norte", "una puerta metálica",
    "Una vieja puerta metálica para cerrar la celda.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}
