
#include <properties.h>
#include <sounds.h>
inherit NPC;
public void snd_rata();
create() {
    ::create();
    SetStandard("una rata","roedor",5,GENERO_FEMENINO);
    SetShort("una enorme rata negra");
    SetLong("Es una enorme rata negra con larga cola y afilados dientes.\n Tiene unas "
    "medidas exageradas y su aspecto es de transmitir enfermedades nada convencionales.\n");
    AddId(({"rata", "rata negra", "rata enorme"}));
    SetSize(P_SIZE_SMALL);
    SetHands(({({"la pata izquierda",0,3}),
             ({"la pata derecha",0,3}),
             ({"los dientes",1,4})}));
    InitAChats(8,({
   "Una rata da vueltas a tu alrededor.\n",
   "Una rata se te intenta subir a los tobillos.\n",
    SF(snd_rata),
     "Una rata te mordisquea una pierna.\n"
  }));
    InitChats(5, ({SF(snd_rata),
    "Una rata roe un hueso que hay tirado por ahí.\n",
    "Una rata te enseña sus dientes amarillos.\n",
    "Una rata parece MUUUUY hambrienta.\n",
"Una rata te mira con gesto amenazador.\n"}));
}

public void snd_rata(){
    tell_room(environment(), "Una rata chilla.\n");
    play_sound(environment(), SND_PNJS("ratas"));
}
