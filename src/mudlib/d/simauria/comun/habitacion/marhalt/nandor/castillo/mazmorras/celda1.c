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
    AddReadMsg(({"inscripci�n","inscripcion","pared"}),
    "Pone: 'Ya lo dijo el pirata: Nunca te fumes una cola de rata.'\n");
    AddItem(PNJ("marhalt/jashim"),REFRESH_DESTRUCT);
    AddExit("sur","./pasillo4");
    AddDoor("sur", "una puerta met�lica",
    "Una vieja puerta met�lica para cerrar la celda.\n",
    ({"puerta", "puerta met�lica", "puerta metalica", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_metalica"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_metalica"), P_MATERIAL : M_HIERRO]));
}
