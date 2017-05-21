//5.c (c) Nemesis@Simauria
//Celda numero 5

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <moving.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>

inherit SIM_ROOM;

private int removido,cavado;

remover(str) {
object ob;
if (cavado) write("No hay nada que hacer, se han llevado todo el tesoro...\n");
else {
 if (!str) { write("�Qu� quieres remover?\n"); }
 else {
  if (str!="paja") {
  write("De alguna manera,  eso no es posible removerlo.\n");
  }
  else {
   if (!removido) {
   write(
   "Remueves la paja y descubres un mont�n de tierra con una gran X pintada en "
   "su centro...\n Si pudieras cavar, quiz� encontrar�as algo...\n");
    removido=1;
    RemoveDetail(({"cama","camastro"}));
    TO->AddDetail(({"cama","camastro"}),
    "Alguien ha removido la paja. Un mont�n de tierra con una X es visible ahora.\n");
   }
   else write("Ya han removido la paja. Solo te queda cavar...\n");
  }
 }
}
return 1;
}

cavar() {
object ob1,ob2,ob3;
if (cavado==1) return notify_fail("Alguien ha cavado ya y se ha llevado todo lo que hubiera.\n");
if (!present("qpala",TP)) write(
"Comienzas a cavar la tierra con las manos, pero pronto te das cuenta de que "
"vas a necesitar herramientas.\n");
else {
 write("Comienzas a cavar con la pala y pronto encuentras varias cosas...\n");
 ob1=clone_object("/std/weapon");
 ob1->SetShort("un cuchillo oxidado");
 ob1->SetLong(
 "Un cuchillo mugriento y oxidado. Parece que lleva enterrado mucho tiempo.\n");
 ob1->SetWeaponType(WT_CUCHILLO);
 ob1->Set(P_GENDER,GENDER_MALE);
 ob1->SetWC(2);
 ob1->SetQuality(50);
 ob1->SetWeight(500);
 ob1->SetValue(30);
 ob1->move(TO,M_SILENT);

 ob2 = clone_object(QUEST + "granjero/cubo_vacio");
 ob2->SetOwner(TNREAL);
 ob2->move(TO);

 ob3=clone_object("std/thing");
 ob3->SetShort("un rub�");
 ob3->SetLong(
 "Un bello rub� de color rojizo. A pesar de lo sucio que est�, se puede ver "
 "claramente que... ARG! ES FALSO! En fin, parece que los tesoros ya no son "
 "lo que eran...\n");
 ob3->AddId(({"rubi", "rub�"}));
 ob3->SetWeight(40);
 ob3->SetValue(10);
 ob3->move(TO,M_SILENT);

 cavado=1;
 RemoveDetail(({"cama","camastro"}));
 TO->AddDetail(({"cama","camastro"}),
    "Alguien ha estado cavando. Bajo la cama ahora se ve un enorme agujero.\n");
 }

return 1;
}

init() {
    add_action("remover","remover");
    add_action("cavar","cavar");
    ::init();
}

reset() {
    removido=0;
    cavado=0;
    ::reset();
}

create () {
    ::create();
    SetLocate("el castillo de Nandor");
    SetIntShort("una h�meda celda");
    SetIntLong("Te encuentras en una peque�a y h�meda celda. Lo �nico que te acompa�a "
    "son un cutre camastro de paja y una vieja silla.\n En una de las paredes se "
    "aprecia una inscripci�n.\n");
    SetIntBright(10);
    SetIntSmell("Huele a humedad.\n");
    SetIntNoise(
    "Extra�amente no se oye nada. El lugar esta tan silencioso como una tumba...\n");
    AddDetail("paja",
    "Est� puesta de una forma un tanto sospechosa.\n");
    AddDetail(({"cama","camastro"}),
    "Es una yacija cubierta de paja. No parece demasiado c�moda.\n Por entre la paja "
    "se puede ver algo que llama la atenci�n.\n");
    AddDetail(({"inscripci�n","pared", "inscripcion"}),
    "Quiz� puedas leer la inscripci�n.\n");
    AddDetail(({"vieja silla","silla"}),
    "Es una silla como otra cualquiera, si bien est� cubierta de polvo.\n");
    AddReadMsg(({"inscripcion","inscripci�n","pared"}),
    "Pone: 'Al cinco y al seis nunca m�s los vereis.'\n");
    AddExit("sur","./pasillo6");
    AddDoor("sur", "una puerta met�lica",
    "Una vieja puerta met�lica para cerrar la celda.\n",
    ({"puerta", "puerta met�lica", "puerta metalica", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}