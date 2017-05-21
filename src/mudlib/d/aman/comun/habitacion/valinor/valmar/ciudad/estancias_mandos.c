/*
Fichero: estancias_mandos.c
Autor: Aul�
Fecha: 01/08/2014
Descripci�n: estancias de Mandos, donde van a parar los esp�riitus de los muertos
*/
#include "./path.h"

#include <colours.h>

inherit STD_VALINOR("hab_valinor");
#define NOMBRE  (capitalize(TP->QueryRealName()))

public int retornar_cmd(){
  if (!(TP->QueryGhost()))
  return notify_fail(
      "Mandos te dice: No tomes a la ligera a los Valar, "+NOMBRE+", o el castigo caer� "
      "sobre ti. Ya dispones de una envoltura carnal.\n",NOTIFY_NOT_VALID);
  write("Mandos clava en ti su mirada exenta de toda piedad y te eval�a, impert�rrito "
  "durante largos momentos..\n"
  "Mandos dice: Se te permitir� retornar, si as� lo deseas, una vez m�s a las Tierras Mortales y "
  "se te proporcionar� un cuerpo para que habites en �l. Aprovecha esta oportunidad, pues Eru "
  "y los Valar no hacen escepciones sin una raz�n de peso.\n"
  "Mandos alza la mano derecha con adem�n perent�reo....\n\n"
  "Mandos dice: Ve en paz, "+NOMBRE+", que Eru te guarde.\n\n"
  "Tu consciencia se estremece y riela...\n"
  "Olvidas todo lo acontecido desde tu muerte y revives toda tu vida pasada...\n"
  "\n Con un estallido de viv�sima luz blanca eres arrancad"+TP->QueryGenderEndString()+" de las Estancias de Mandos..\n"
  "Despiertas sobresaltad"+TP->QueryGenderEndString()+" y abres los ojos totalmente desorientad"
  +TP->QueryGenderEndString()+".\n\n");
  TP->SetGhost(0);
  say("Mandos observa durante un largo momento a "+TP->QueryRealName()+" y le da su bendici�n.\n"
  "Se produce un estallido de luz y "+TP->QueryRealName()+" desaparece disolvi�ndose en el aire.\n");
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
    "Te hayas bajo una alt�sima b�veda que resplandece como si en todo momento la "
    "iluminara un sol poniente estival.\n"
    "Altas y esbeltas columnas de piedra blanca sustentan el techo y en todas "
    "direcciones se extiende una incomensurable sala dividida en largas avenidas "
    "cuajadas de hermosas fuentes y jalonadas por bancos de m�rmol.\n"
    "La grandiosidad, paz y tranquilidad que se respiran en estos amplios salones "
    "invitan a la reflexi�n y la introspecci�n interna, pues el tiempo parece haberse "
    "detenido. Multitud de figuras van y vienen por las amplias avenidas columnadas o "
    "reposan en los bancos. Los habitantes del lugar charlan entre ellos en voz baja o "
    "van y vienen sumidos en profundas cavilaciones.\n"
    "Hasta donde alcanza la vista no se ve ninguna entrada o salida, y los p�treos muros "
    "blancos se alzan hasta fundirse con el lejano cielo raso sin grieta alguna en su "
    "inamovible superficie.\n"
    "Son estas las Estancias de Mandos, lugar de espera para las almas inmortales de "
    "todas las razas inteligentes, incluso para los Hombres que permanecen aqu� un "
    "breve lapso de tiempo antes de partir m�s all� de Arda, s�lo Eru sabe a donde.\n"
    "Estos salones son los dominios de Mandos, se�or de los muertos y juez de los Valar, "
    "y nadie, sea Elfo Hombre o Vala puede traspasar sus muros hacia el interior o el exterior "
    "si �l as� no lo quiere.\n");
    AddDetail("columnas",
    "Finas columnas de piedra blanca que se extienden hacia el alt�simo techo cual si de "
    "troncos de un umbr�o bosque se trataran.\n");
    AddDetail("bancos",
    "Largos bancos de m�rmol que jalonan las amplias avenidas.\n");
    AddDetail(({"siluetas", "espiritus", "esp�ritus", "almas", "habitantes"}),
    "A pesar de la vastedad del lugar es obvio que su n�mero es incalculable.\n"
    "Vestidos con sencillez, de gris o blanco, la mayor�a son Elfos pero puedes "
    "distinguir a muchas otras razas. Sus rostros emanan una serenidad y una paz "
    "inmutable mientras esperan a que el destino de Arda se consume y devenga la "
    "Dagor Dagorath, la �ltima Batalla que pondr� fin al mundo.\n");
    //SetIntSmell("No puedes oler nada en tu estado inmaterial.\n");
    SetIntNoise("Las fuentes canturrean suavemente mientras a lo lejos el adormecedor de "
    "las olas del Oc�ano Exterior resuena bajo la alta b�veda.\n");
    AddRoomCmd("retornar","retornar_cmd");
AddItem(PNJ_VALMAR("/ciudad/mandos"));
ForbidAllMagic();

}

