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
    SetIntShort("una h�meda celda");
    SetIntLong("Te encuentras en una peque�a y h�meda celda. Lo �nico que te acompa�a "
    "son un cutre camastro de paja y una vieja silla.\n En una de las paredes se "
    "aprecia una inscripci�n.\n");
    SetIntBright(10);
    SetIntSmell("Huele a humedad.\n");
    SetIntNoise(
    "Extra�amente no se oye nada. El lugar esta tan silencioso como una tumba...\n");
    AddDetail(({"cama","camastro"}),
    "Es una yacija cubierta de paja. No parece demasiado c�moda.\n");
    AddDetail(({"inscripci�n","pared", "inscripcion"}),
    "Quiz� puedas leer la inscripci�n.\n");
    AddDetail(({"vieja silla","silla"}),
    "Es una silla como otra cualquiera, si bien est� cubierta de polvo.\n");
    AddReadMsg(({"inscripcion","inscripci�n","pared"}),
    "Pone: 'Lo sabe hasta la fr�a Muerte: en el 7 esta la suerte.'\n");
    AddExit("norte","./pasillo4");
    AddDoor("norte", "una puerta met�lica",
    "Una vieja puerta met�lica para cerrar la celda.\n",
    ({"puerta", "puerta met�lica", "puerta metalica", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}
