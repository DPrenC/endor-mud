//1.c (c) Nemesis@Simauria
//Celda numero 1

#include "./path.h"
#include <door.h>
#include <materials.h>
#include <sounds.h>
#include <properties.h>

inherit SIM_ROOM;

create () {
    ::create();
    SetLocate("el castillo de Nandor");
    SetIntShort("una húmeda celda");
    SetIntLong("Te encuentras en una pequeña y húmeda celda. Lo único que te acompaña "
    "son un cutre camastro de paja y una vieja silla.\n En una de las paredes se "
    "aprecia una inscripción.\n");
    SetIntBright(10);
    SetIntSmell("Huele a humedad.\n");
    SetIntNoise(
    "Extrañamente no se oye nada. El lugar esta tan silencioso como una tumba...\n");
    AddDetail(({"cama","camastro"}),
    "Es una yacija cubierta de paja. No parece demasiado cómoda.\n");
    AddDetail(({"inscripción","pared", "inscripcion"}),
    "Quizá puedas leer la inscripción.\n");
    AddDetail(({"vieja silla","silla"}),
    "Es una silla como otra cualquiera, si bien está cubierta de polvo.\n");
    AddReadMsg(({"inscripción","inscripcion","pared"}),
    "Pone: 'Ya lo dijo el pirata: Nunca te fumes una cola de rata.'\n");
    AddItem(PNJ("marhalt/jashim"),REFRESH_DESTRUCT);
    AddExit("sur","./pasillo4");
    AddDoor("sur", "una puerta metálica",
    "Una vieja puerta metálica para cerrar la celda.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}
