/*
DESCRIPCION  : La habitacion en la que saltas...
FICHERO      : /d/kenton/comun/quest/bruja/oliphab.c
MODIFICACION : 9-10-00 [Nyh] Creacion.
COMENTARIOS  :	Bien, nadie me dice na... pos la hago como sea y los
		vacios ya los llenara alguien...
--------------------------------------------------------------------------------
*/
// [Nyh] que chepais que los comentarios chorras jur jur son mios :p
inherit ROOM;
#include "./path.h"
#include <properties.h>
#include <skills.h>
#include <combat.h>

#define DIFICULTAD_SALTO 20

#define SUELO 0
#define PRIMERA 1
#define SEGUNDA 2
#define TERCERA 3
#define BOTA 4

private object compitiendosalto;
private int nivel;

create() {
  ::create();
  SetIntShort("el estadio de Klariton.");
  SetIntLong(W("Estas en el 'inmenso' estadio de Klariton, aqui, los kenders se divierten con las distintas "
"pruebas que propone el ingenioso Glunt. Ahora mismo hay 6 competiciones "
"pensadas por el genio de este kender. Puedes ver que en este momento estan disputando "
"la divertida prueba del salto de la rana.\n"));
  AddExit("noroeste","/players/diox/vacia");
}

init()
{
::init();
add_action("cmd_competir","competir");
add_action("cmd_saltar","saltar");
}

public object QueryCompitiendoSalto() {return compitiendosalto;}
public object SetCompitiendoSalto(object ob) {return compitiendosalto=ob;}

public int QueryNivel() {return nivel;}
public int SetNivel(int i) {return nivel=i;}
public int SubirNivel() {return (nivel>3)?4:nivel+=1;}
public int BajarNivel() {return (nivel<1)?0:nivel-=1;}

private string NivToString(int i){
switch (i) {
	case 0: return "al suelo";
	case 1: return "a la primera plataforma";
	case 2: return "a la segunda plataforma";
	case 3: return "a la tercera plataforma";
	case 4: return "a la bota";
	}
return 0;
}

// uso: competir EN xxxx
// uso QueryIsRana() fale, avisado... si da 1 lo es...
cmd_competir(string str) {
string what;
if (!TP) return 1;
// la linea del chequeo...descomentar para modo real :)
if(!TP->QueryRace()=="rana_quest") {write("Sólo pueden competir ranas.\n"); return 1;}
if (!str) {write("¿competir en que?\n"); return 1;}
if (!(sscanf(str,"en %s",what)==1)) {write("¿competir en que?\n"); return 1;}
switch (what) {
	case "salto": if (QueryCompitiendoSalto()!=0) {write(W("Lo siento,pero en estos momentos esta compitiendo "+QueryCompitiendoSalto()->QueryName()+".\n")); return 1;}
				  tell_object(TP,"Te apuntas a la competicion de salto de rana.\nLas reglas son: tienes que saltar por las tres plataformas hasta llegar a la mas alta, y desde alli saltar de nuevo y caer en la bota, para ello, empiezas en el suelo y vas subiendo escribiendo saltar primera, segunda, tercera o bota.\n");
				  tell_room(environment(TP),W(""+TP->QueryName()+" se apunta al concurso de salto de rana.\n"),({TP}));
				  SetCompitiendoSalto(TP);
				  SetNivel(SUELO);
				  return 1;
				  break;
	default: write("¿En que quieres competir?\n");
			 return 1;
	}
}


cmd_saltar(string str) {
int perc, adonde;
object bota;
if (!TP) return 1;
if (TP!=QueryCompitiendoSalto()) {write("Lo siento, pero no estas compitiendo.\n"); return 1;}
if (!str) {write("¿A donde quieres saltar?"); return 1;}
switch (str) {
	case "suelo":   adonde=SUELO; break;
	case "primera": adonde=PRIMERA; break;
	case "segunda": adonde=SEGUNDA; break;
	case "tercera": adonde=TERCERA; break;
	case "bota":    adonde=BOTA; break;
	default: {write("¿A donde quieres saltar?\n"); return 1;}
	}
if (QueryNivel()==0) {
	switch (adonde) {
			case SUELO: { write("¡Ya estas alli!\n"); return 1; break;}
			case PRIMERA: {Saltar(SUELO,PRIMERA); return 1; break;}
			case SEGUNDA: {write("Cojes carrerilla, te impulsas con todas tus fuerzas, pero eres incapaz de llegar a la segunda plataforma.\n"); return 1; break;}
			case TERCERA: {write("¿No crees que eso esta DEMASIADO alto?\n"); return 1; break;}
			case BOTA: {write("No puedes saltar directamente a la bota, antes debes subir por las plataformas.\n"); return 1; break;}
			default:
			}

}
if ((QueryNivel()==TERCERA) && (adonde==BOTA)) {// es a a bota...
	tell_object(TP,W("Das un salto impresionante desde "+NivToString(QueryNivel())+" y empiezas a caer...\n"));
	tell_room(environment(TP),W("Ves como "+TP->QueryName()+" da un salto impresionante desde "+NivToString(QueryNivel())+" y empieza a caer...\n"),({TP}));
SetCompitiendoSalto(0);
tell_object(TP,"¡¡¡Caes dentro de la bota!!!.\n");
tell_room(environment(TP),W(TP->QueryName()+" cae dentro de la bota.\n"),({TP}));
TP->SetRace("rana_bota_quest");
RACEMASTER->InitRace(TP,"rana_bota_quest");
RACEMASTER->AdjustStats(TP);
return 1;
}
// y sino us el saltar general...
Saltar(QueryNivel(),adonde);
return 1;
}

cae(int i) { // jur, jur que diver
// aqui me tengo que inventar al funcion de cuando cae y eso...
// de momento no hace na mas que enviar el mensaje... quiza luegor haga
// cositas mas divertidas.. por ejemplo que tarde en caer tiempo...
tell_object(TP,"Te estempanas contra el suelo.\n");
tell_room(environment(TP),W("Ves como"+TP->QueryName()+" se estempana contra el suelo.\n"),({TP}));
return 1;
}


/* Haciendo pruebas con una dex y str de 30, lo empeze a conseguir con una
habilidad de salto de 40, con 45 ya lo hacia casi una de cada tres intentos
(me refiero a conseguir saltar correctamente las TRES plataformas) */
Saltar(int origen, int destino) {
int per,chance,dist,d;
if (origen==destino) {write("¡Ya estas alli!\n"); return 1;}
tell_object(TP,W("Intentas saltar desde "+NivToString(origen)+" a "+NivToString(destino)+"\n"));
tell_room(environment(TP),W("Ves como"+TP->QueryName()+" intenta saltar desde "+NivToString(origen)+" hasta "+NivToString(destino)+"\n"),({TP}));
chance=((TP->QueryDex()*2+TP->QueryStr())/3-DIFICULTAD_SALTO);
if (origen<destino) (d=destino-origen); else d=origen-destino;
chance=chance-(destino-1)*10-d*d*10;
per=TP->UseSkill(HAB_SALTAR,chance);
if (per<-50) {// jur, jur, oxtiazo...
	{  if (origen!=SUELO) {
		if (destino!=SUELO) {
		tell_object(TP,"Pero fallas de forma catastrófica y empiezas a caer al vacio...\n");
		tell_room(environment(TP),"Pero falla de forma catastrófica y empieza a caer al vacio...\n",({TP}));
		cae(destino); // tomo que cae desde a donde pretendia saltar...
		}
	  else {
		tell_object(TP,"Pero decides que la forma más sana de volver al suelo es de cabeza.\n");
		tell_room(environment(TP),"Pero decide que la forma más sana de volver al suelo es de cabeza.\n",({TP}));
		cae(origen); // cae desde donde estaba...
		}
	  }
	else {
		tell_object(TP,"Pero fallas de forma catastrófica y acabas chocando de bruces con el suelo.\n");
		tell_room(environment(TP),"Pero falla de forma catastrófica y acaba chocando de bruces con el suelo.\n",({TP}));
		}
	}
	SetNivel(SUELO);
	TP->Defend(40*dist,DT_BLUDGEON,DEFEND_NOMSG);
	return 1;
	}
else if (per<=0) { // solofalla, pero tb se la pega :)
	{  if (origen!=SUELO) {
		if (destino!=SUELO) {
		tell_object(TP,"Pero no consigues llegar a la siguiente plataforma y empiezas a caer al vacio...\n");
		tell_room(environment(TP),"Pero no consigue llegar a la siguente plataforma y empieza a caer al vacio...\n",({TP}));
		cae(destino);
		}
	  else {
		tell_object(TP,"Pero no consigues tomar tierra de forma adecuada y te lastimas.\n");
		tell_room(environment(TP),"Pero no consigue tomar tierra de forma adecuada y se lastima.\n",({TP}));
		cae(origen);
		}
	  }
	else {
		tell_object(TP,"Pero no consigues llegar hasta la primera plataforma y acabas chocando con en el suelo.\n");
		tell_room(environment(TP),"Pero no consigue llegar hasta la primera plataforma y acaba chocando con el suelo.\n",({TP}));
		}
	}
	SetNivel(SUELO);
	TP->Defend(20*dist,DT_BLUDGEON,DEFEND_NOMSG);
	return 1;
	}
else {	//per>0, acierta...
	if (destino!=SUELO) {
		tell_object(TP,W("Y consigues encaramarte "+NivToString(destino)+".\n"));
		tell_room(environment(TP),W("Y consigue encaramarse "+NivToString(destino)+".\n"),({TP}));
		SetNivel(destino);
		return 1;
	}
	else {
		tell_object(TP,"Y consigues bajar al suelo de un salto perfecto.\n");
		tell_room(environment(TP),"Y consigue bajar al suelo de un salto perfecto.\n",({TP}));
		SetNivel(destino);
		return 1;
	}
}
}
