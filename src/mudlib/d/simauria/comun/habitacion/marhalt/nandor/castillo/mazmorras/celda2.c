//2.c (c) Nemesis@Simauria
//Celda numero 2

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <materials.h>

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
    AddReadMsg(({"inscripcion","inscripción","pared"}),
    "Pone: 'Lo sabe hasta la fría Muerte: en el 7 esta la suerte.'\n");
    AddExit("norte","./pasillo4");
    AddDoor("norte", "una puerta metálica",
    "Una vieja puerta metálica para cerrar la celda.\n",
    ({"puerta", "puerta metálica", "puerta metalica", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}
