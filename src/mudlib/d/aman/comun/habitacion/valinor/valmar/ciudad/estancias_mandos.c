/*
Fichero: estancias_mandos.c
Autor: Aulë
Fecha: 01/08/2014
Descripción: estancias de Mandos, donde van a parar los espíriitus de los muertos
*/
#include "./path.h"

#include <colours.h>

inherit STD_VALINOR("hab_valinor");
#define NOMBRE  (capitalize(TP->QueryRealName()))

public int retornar_cmd(){
  if (!(TP->QueryGhost()))
  return notify_fail(
      "Mandos te dice: No tomes a la ligera a los Valar, "+NOMBRE+", o el castigo caerá "
      "sobre ti. Ya dispones de una envoltura carnal.\n",NOTIFY_NOT_VALID);
  write("Mandos clava en ti su mirada exenta de toda piedad y te evalúa, impertérrito "
  "durante largos momentos..\n"
  "Mandos dice: Se te permitirá retornar, si así lo deseas, una vez más a las Tierras Mortales y "
  "se te proporcionará un cuerpo para que habites en él. Aprovecha esta oportunidad, pues Eru "
  "y los Valar no hacen escepciones sin una razón de peso.\n"
  "Mandos alza la mano derecha con ademán perentóreo....\n\n"
  "Mandos dice: Ve en paz, "+NOMBRE+", que Eru te guarde.\n\n"
  "Tu consciencia se estremece y riela...\n"
  "Olvidas todo lo acontecido desde tu muerte y revives toda tu vida pasada...\n"
  "\n Con un estallido de vivísima luz blanca eres arrancad"+TP->QueryGenderEndString()+" de las Estancias de Mandos..\n"
  "Despiertas sobresaltad"+TP->QueryGenderEndString()+" y abres los ojos totalmente desorientad"
  +TP->QueryGenderEndString()+".\n\n");
  TP->SetGhost(0);
  say("Mandos observa durante un largo momento a "+TP->QueryRealName()+" y le da su bendición.\n"
  "Se produce un estallido de luz y "+TP->QueryRealName()+" desaparece disolviéndose en el aire.\n");
  "/room/room_inicio"->enclaves();
  return 1;
}
//--------------------------------------------------------------------------------

create()
{
    ::create();
    	SetLocate("Valmar");
    	SetIntBright(35);
  SetIndoors(1);

    SetIntShort("Estancias de Mandos");
    SetIntLong(
    "Te hayas bajo una altísima bóveda que resplandece como si en todo momento la "
    "iluminara un sol poniente estival.\n"
    "Altas y esbeltas columnas de piedra blanca sustentan el techo y en todas "
    "direcciones se extiende una incomensurable sala dividida en largas avenidas "
    "cuajadas de hermosas fuentes y jalonadas por bancos de mármol.\n"
    "La grandiosidad, paz y tranquilidad que se respiran en estos amplios salones "
    "invitan a la reflexión y la introspección interna, pues el tiempo parece haberse "
    "detenido. Multitud de figuras van y vienen por las amplias avenidas columnadas o "
    "reposan en los bancos. Los habitantes del lugar charlan entre ellos en voz baja o "
    "van y vienen sumidos en profundas cavilaciones.\n"
    "Hasta donde alcanza la vista no se ve ninguna entrada o salida, y los pétreos muros "
    "blancos se alzan hasta fundirse con el lejano cielo raso sin grieta alguna en su "
    "inamovible superficie.\n"
    "Son estas las Estancias de Mandos, lugar de espera para las almas inmortales de "
    "todas las razas inteligentes, incluso para los Hombres que permanecen aquí un "
    "breve lapso de tiempo antes de partir más allá de Arda, sólo Eru sabe a donde.\n"
    "Estos salones son los dominios de Mandos, señor de los muertos y juez de los Valar, "
    "y nadie, sea Elfo Hombre o Vala puede traspasar sus muros hacia el interior o el exterior "
    "si él así no lo quiere.\n");
    AddDetail("columnas",
    "Finas columnas de piedra blanca que se extienden hacia el altísimo techo cual si de "
    "troncos de un umbrío bosque se trataran.\n");
    AddDetail("bancos",
    "Largos bancos de mármol que jalonan las amplias avenidas.\n");
    AddDetail(({"siluetas", "espiritus", "espíritus", "almas", "habitantes"}),
    "A pesar de la vastedad del lugar es obvio que su número es incalculable.\n"
    "Vestidos con sencillez, de gris o blanco, la mayoría son Elfos pero puedes "
    "distinguir a muchas otras razas. Sus rostros emanan una serenidad y una paz "
    "inmutable mientras esperan a que el destino de Arda se consume y devenga la "
    "Dagor Dagorath, la última Batalla que pondrá fin al mundo.\n");
    //SetIntSmell("No puedes oler nada en tu estado inmaterial.\n");
    SetIntNoise("Las fuentes canturrean suavemente mientras a lo lejos el adormecedor de "
    "las olas del Océano Exterior resuena bajo la alta bóveda.\n");
    AddRoomCmd("retornar","retornar_cmd");
AddItem(PNJ_VALMAR("/ciudad/mandos"));
ForbidAllMagic();

}

