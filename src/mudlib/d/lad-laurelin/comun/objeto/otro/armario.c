// Descripcion: Armario SIN cerradura para QUEST del Templo de Dehim
// Creado por : Alura (Julio del 2001)

#include <properties.h>
#include <lock.h>
#include <moving.h>
#include <search.h>
#include <config.h>     //por el QUESTMASTER
#include <colours.h>

inherit "/std/room/items"; // reset() is here
inherit CONTAINER;


#define THIS TO
#define NOMBRE  (capitalize(TP->QueryName()))

#define P_ABIERTO 1
#define P_CERRADO 0

/*-------------------------------------------------------------------------*/

public int QueryEstado(){
 return TO->Query("estado");
}

public SetEstado(int est){
 TO->Set("estado",est);
}

//PARA QUEST DEL TEMPLO DE DEHIM
int pon_estatua(string str){
	object estatua;
 	object from;
 	string a, b, Quests;
 	from=TP;
 	if (!from || !str) return 0;
	estatua=present("estatuilla",TP);
	if (str==0) return 0;
	if ((upper_case(str[0..6])=="ESTATUA" || upper_case(str[0..9])=="ESTATUILLA") && estatua!=0)
	     if ((upper_case(str[0..6])=="ESTATUA" && upper_case(str[7..17])==" EN ARMARIO") || (upper_case(str[0..9])=="ESTATUILLA" && upper_case(str[10..20])==" EN ARMARIO"))
		{if (estatua->Query("llevamedal")==1 && TO->QueryEstado()==1) {
			tell_object(TP,TC_BLUE"Los monjes muertos del templo vuelven a sus tumbas y\n"+
			"la presencia del dios Dehim vuelve a este lugar gracias a ti.\n"TC_NORMAL);
			estatua->remove();
			Quests=from->QueryQuests();
    			if (!Quests) Quests="hallo";
    			if (sscanf(Quests,"%ssalvacion_templo_Dehim%s",a,b)!=11) {
    			write(TC_RED"\nAcabas de resolver el quest: Salvación del templo de Dehim.\n"TC_NORMAL);
    			QUESTMASTER->InformSolution("Los monjes del templo de Dehim descansan en paz gracias a "+NOMBRE);
    			QUESTMASTER->SetPlayerQuest("salvacion_templo_Dehim",TP);
		    	//Hacer aparecer vara magica (cuando se pueda) y pocion de curacion de 1 uso
			AddItem("/d/lad-laurelin/comun/objeto/magico/pocion_cur");
			//cierro el armario ;-)
			write("El armario se cierra de golpe.\n");
			TO->SetEstado(0);
			return 1;
    		} else return 0;
	     }else return 0;
  } else return 0;
}

create () {
  container::create();
  SetShort ("el armario del altar");
  SetIntShort ("dentro del armario del altar");
  SetLong ("Es un armario pequeño sin cerrojo.\n");
  SetIntLong ("Estás en el interior del armario del altar.\n");
  SetPreContent ("Contiene:\n");
  SetValue (0);
  SetWeight (8000000);
  SetMaxIntWeight (10000);
  AddId ("armario");
  Set("estado",P_CERRADO);
  Set(P_NOGET,1);  //No se puede dar
  Set(P_NODROP,1); //No se puede coger
}

/*-------------------------------------------------------------------------
** Si el armario esta cerrado, coger cosas del interior no es posible.
** En ese caso, devuelve ME_NO_LEAVE, si no ME_NO_PREVENT.
-------------------------------------------------------------------------*/

public int prevent_leave (mixed dest, int method, mixed extra) {
  if (!TP || TP != PO || LSTATE_GHOST != TP->Query(P_LSTATE)) {
    if (Query("estado") != P_ABIERTO) {
      if (TP || TI)
        write ("El armario está cerrado.\n");
      return ME_NO_LEAVE;
    }
  }
  return container::prevent_leave(dest, method, extra);
}

/*-------------------------------------------------------------------------
** Si el armario esta cerrado, poner cosas dentro es imposible.
** En ese caso, devuelve ME_NO_ENTER.
** Si esta abierto, puede estar lleno. Pregunta /std/container para eso
-------------------------------------------------------------------------*/

public int allow_enter (int method, mixed extra) {
  if (!TP || TP != PO || LSTATE_GHOST != TP->Query(P_LSTATE)) {
    if (Query("estado") != P_ABIERTO) {
      if (TP || TI)
          write ("El armario está cerrado.\n");
      return ME_NO_ENTER;
    }
  }
  return container::allow_enter (method, extra);
}

/*-------------------------------------------------------------------------
** Si esta cerrado, el jugador no puede encontrar o ver nada a traves de
** su material (a menos de que sea un fantasma o el armario sea transparente).
--------------------------------------------------------------------------*/

public varargs object *Locate (mixed item, int mode) {
  if (Query("estado") != P_ABIERTO
    && member(deep_inventory(THIS), TP) == -1 &&  LSTATE_GHOST != TP->Query(P_LSTATE)){
	 return (mode & SEARCH_OBJECT) ? 0 : ({});
   	 }
    return container::Locate (item, mode);
}

/*-------------------------------------------------------------------------
** El contenido es siempre visible al interior, pero no al exterior... ya
** sabes, a menos que no este cerrado o sea transparente
-------------------------------------------------------------------------*/

public varargs string Content (string what, mixed exclude) {
  if (member(deep_inventory(THIS), TP) == -1
   && LSTATE_GHOST != TP->Query(P_LSTATE)
   && Query("estado") != P_ABIERTO
     )
    return "No puedes ver el contenido porque está cerrado.\n";
  return container::Content(what, exclude);
}

/*************************************************************************/

init(){
   ::init();
   add_action("pon_estatua","poner");
}