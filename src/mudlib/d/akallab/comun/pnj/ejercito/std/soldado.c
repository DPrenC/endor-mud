/*
DESCRIPCION  : pnj base del ejercito orco
FICHERO      : soldado.c
MODIFICACION : 02-03-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include "soldado.h"
inherit NPC;

string *raza; //formato ({masculino, femenino})
int grado; //grado dentro de su unidad (soldado, sargento, etc..)
int clase; //clase de unidad (guerrero, arquero, caballero, lanzahachas, etc..)
int experiencia; //nivel de experiencia
int edad;
int sexo;
int ayudado;
string queProtege; //el castillo de la ciudad de Zarkam, el puente, etc...

int NivelBonus()
{
	int bonus;
	int *tabla;
    bonus=0;
    tabla=SO_EXP_BONUS;
	bonus+=tabla[experiencia];//experiencia
    tabla=SO_EDAD_BONUS;
	bonus+=tabla[edad];//edad
    tabla=SO_SEXO_BONUS;
	bonus+=tabla[sexo-1];//sexo
    bonus+=random(5);//random
	return bonus;
}

int NivelBase()
{
	int *base;
	int nivel;
	base=SO_GRADO_NIVEL_BASE;
	nivel=base[grado-1];
	return nivel;
}

void ValoresPorDefecto()
{
int i;
int *prob;

	raza=({"orco","orca"});

	//sexo
	sexo=(random(100)<SO_SEXO_PROB?GENDER_FEMALE:GENDER_MALE);
	//SetGender(sexo);

	//edad
	prob=SO_EDAD_PROB;
	i=random(100);
	edad=0;
	do{edad++;
	    }while (i>prob[edad]);
	edad--;

    //experiencia
	prob=SO_EXP_PROB;
	i=random(100);
	experiencia=0;
	do{experiencia++;
	    }while (i>prob[experiencia]);
	experiencia--;
	if ((edad==SO_EDAD_VIEJO)&&(experiencia==SO_EXP_NOVATO)) experiencia++;

	grado=SO_GRADO_SOLDADO;
	clase=SO_CLASE_GUERRERO;

	ayudado=0;
	return;
}

string QueryEdadMsg()
{
  string *str;
  str=(QueryGender()==GENDER_FEMALE?SO_EDAD_FEM:SO_EDAD_MAS);
  return str[edad];
}

string QueryExperienciaMsg()
{
  string *str;
  str=(QueryGender()==GENDER_FEMALE?SO_EXP_FEM:SO_EXP_MAS);
  return str[experiencia];
}

string QueryGradoMsg()
{
  string *str;
  str=(QueryGender()==GENDER_FEMALE?SO_GRADO_FEM:SO_GRADO_MAS);
  return str[grado-1];
}

string QueryClaseMsg()
{
  string *str;
  str=(QueryGender()==GENDER_FEMALE?SO_CLASE_FEM:SO_CLASE_MAS);
  return str[clase];
}

string QueryGenderMsg(){return raza[(QueryGender()==GENDER_FEMALE?1:0)];}

create()
  {
  string s;
  string *str;
  int bonus;

  //seteuid(getuid());

  if (!grado) ValoresPorDefecto();
  ::create();
  SetGender(sexo);
  SetAggressive(2);
  SetAttackOwnRace(0);
  s=UNA_2;
  if (QueryEdadMsg()!="") s+=" ";
  s+=QueryEdadMsg();
  if (QueryExperienciaMsg()!="") s+=" ";
  s+=QueryExperienciaMsg()+" "+QueryGradoMsg()+" "+QueryClaseMsg()+" "+QueryGenderMsg();
  SetStandard(s,raza[0],NivelBase()+NivelBonus(),sexo);
  SetShort(s);
  //SetName("guardia");

  s="Es "+UNA_2+" ";
  switch(edad)
  {
  	case SO_EDAD_JOVEN: s+=QueryEdadMsg()+" "+QueryGenderMsg(); break;
  	case SO_EDAD_NORMAL: s+=QueryGenderMsg()+" de mediana edad"; break;
  	case SO_EDAD_VIEJO: s+=QueryEdadMsg()+" "+QueryGenderMsg(); break;
  }
  s+=". Por su indumentaria y armamento se ve claramente que se trata de "+UNA_2+
     " "+QueryClaseMsg()+" del poderoso ejercito orco, con el grado de "+
	 QueryGradoMsg()+".";

  if (clase==SO_CLASE_GUARDIA) s+=" Su tarea es la de proteger "+queProtege+".";

  s+=" Va bien armad"+AO2+" y su aspecto indica que debe ";
  switch(experiencia)
  {
  	case SO_EXP_NOVATO: s+="ser aun "+UNA_2+" "+QueryExperienciaMsg()+" en la lucha."; break;
  	case SO_EXP_NORMAL: s+="ya ha participado en mas de una batalla."; break;
  	case SO_EXP_EXPERTO: s+="estar ya curtid"+AO2+" en la experiencia de la lucha."; break;
    case SO_EXP_AS: s+="ser "+UNA_2+" maestr"+AO2+" en el arte de la lucha."; break;
  }
  switch(random(6))
  {
  	case 0: s+=" Luce unos gruesos anillos de cobre en las orejas"; break;
    case 1: s+=" Una fea cicatriz recorre su fiero rostro"; break;
    case 2: s+=" Sus modales son toscos y vulgares"; break;
    case 3: s+=" No te pierde de vista un solo momento"; break;
    case 4: s+=" Lleva la piel de su cara llena de extranyos tatuajes"; break;
	case 5: s+=" Por su gesto duro y seco no crees que este para muchas tonterias";break;
  }
  s+=".\n";
  SetLong(s);

  AddId(({raza[QueryGender()-1],QueryGradoMsg(),QueryClaseMsg(),QueryExperienciaMsg(),QueryEdadMsg()}));
  SetAlign(-100);
  SetWhimpy(0); // mata o muere
  //AddSkill(HAB_ROBAR, 70);
  //SetCon(QueryCon()+3);
  //SetStr(QueryStr()+4);

  //AddItem(PROT("casco_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("escudo_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("guantes_orco"), REFRESH_REMOVE, SF(wearme));
  //AddItem(PROT("botas_orco"), REFRESH_REMOVE, SF(wearme));

  switch(clase)
  {
  case SO_CLASE_GUERRERO:
  	{
	if ((grado==SO_GRADO_SOLDADO)||(grado==SO_GRADO_CABO))
	    {
		AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
		AddItem(PROT("coraza"),REFRESH_REMOVE,SF(wearme));
  		AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
  		AddItem(PROT("escudo_orco"),REFRESH_REMOVE,SF(wearme));
		bonus=4;
		}
	if (grado==SO_GRADO_SARGENTO)
        {
		AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
        AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
		AddItem(PROT("coraza"),REFRESH_REMOVE,SF(wearme));
  		AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
		bonus=6;
 	    }
	if (grado==SO_GRADO_TENIENTE)
        {
		AddItem(ARMA("katana"),REFRESH_REMOVE,SF(wieldme));
        AddItem(ARMA("katana_negra"),REFRESH_REMOVE,SF(wieldme));
		AddItem(PROT("coraza"),REFRESH_REMOVE,SF(wearme));
  		AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
		bonus=8;
 	    }
	if (grado==SO_GRADO_CAPITAN)
        {
		AddItem(ARMA("katana_negra"),REFRESH_REMOVE,SF(wieldme));
        AddItem(ARMA("katana_negra"),REFRESH_REMOVE,SF(wieldme));
		AddItem(PROT("coraza"),REFRESH_REMOVE,SF(wearme));
  		AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
		bonus=10;
 	    }
	break;
	}
  case SO_CLASE_EXPLORADOR:
    {
	AddItem(ARMA("daga"),REFRESH_REMOVE,SF(wieldme));
    AddItem(ARMA("espada_corta"),REFRESH_REMOVE,SF(wieldme));
  	AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
	AddItem(PROT("camisa_cuero"),REFRESH_REMOVE,SF(wearme));
	AddItem(PROT("cota_malla"),REFRESH_REMOVE,SF(wearme));
	bonus=2;
    }
  case SO_CLASE_GUARDIA:
    {
	AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
    AddItem(ARMA("espada_corta"),REFRESH_REMOVE,SF(wieldme));
	AddItem(PROT("coraza"),REFRESH_REMOVE,SF(wearme));
  	AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
  	AddItem(PROT("escudo_orco"),REFRESH_REMOVE,SF(wearme));
	bonus=6;
    }
  }

  AddItem("/obj/money",REFRESH_REMOVE,
  (["Money":(["cobre":random(10+bonus),"plata":random(7+bonus),"oro":random(2+bonus)])]));

  Set("soldado_Akallab",1);

  if (random(100)<SO_HABLAR_PROB)
  	{
  	InitAChats(10,({
  	    MAY(QueryShort())+" te grita:'Vas a morir!!'\n",
  	    MAY(QueryShort())+" se avanza contra ti.\n",
	    MAY(QueryShort())+" esquiva tu ataque y contraataca fieramente.\n",
  	    MAY(QueryShort())+" se defiende como puede.\n"}));
    InitChats(10,({
        MAY(QueryShort())+" te mira con y murmura:'si, creo que mi espada ya necesita algo de ejercicio...'\n",
	    MAY(QueryShort())+" te mira con desden y dice:'Largate de aqui miserable antes de que me enfade!'.\n",
		MAY(QueryShort())+" dice: 'Pareces muy insolente tu, me pregunto si seguirias asi si fueses esclavo...'.\n",
	    MAY(QueryShort())+" te pregunta: 'Que haces aqui escoria? vuelve a tu trabajo!'.\n",
        MAY(QueryShort())+" grita:'Eh tu! que demonios haces por aqui! Este no es lugar para ti'.\n",
        MAY(QueryShort())+" repasa sus armas sin quitarte la vista de encima.\n",
        MAY(QueryShort())+" te mira desconfiadamente.\n",
        MAY(QueryShort())+" murmura algo sobre la tardanza del individuo que debe relevarle.\n"}));
	}

}

int QueryAyudado(){return ayudado;}
void SetAyudado(int i){ayudado=i;return;}

int EsSoldado(object obj){return obj->Query("soldado_Akallab");}

DoDamage(int dmg) // Si le atacan busca a los guardias para que le defiendan.
{
 int i,j;
 object *soldados,proteccion;

 //puede pedir ayuda?
 if (!ayudado)
 {
  i=1+random(grado);
  say("\n"+capitalize(QueryShort())+" grita pidiendo ayuda a sus companyeros.\n"+i+
     " de ellos llega"+(i>1?"n":"")+" desde las cercanias en su ayuda.\n\n");
  for(j=0;j<i;j++)
  	{
	switch(random(100)+(grado-1)*15)
	{
	case 0..40: proteccion = clone_object(PNJ("ejercito/soldado/guerrero_soldado"));break;
	case 41..80: proteccion = clone_object(PNJ("ejercito/soldado/guerrero_sargento"));break;
	case 81..100: proteccion = clone_object(PNJ("ejercito/soldado/guerrero_capitan"));break;
	default: proteccion = clone_object(PNJ("ejercito/soldado/guerrero_soldado"));break;
    }

	//proteccion->AddEnemies(TO->QueryEnemies());
	//proteccion->SetAggressive(1);
	proteccion->SetAyudado(1);
	proteccion->move(environment(TP));
	//proteccion->Kill(TP || PO);
	}
    ayudado=1;
 }

 //hay ayuda alrededor?
 soldados = filter(deep_inventory(environment(TO)),SF(EsSoldado));
 if(sizeof(soldados))
 	{
    say("Los companyeros de "+lower_case(QueryShort())+" acuden en su defensa.\n");
    for(i=0;i<sizeof(soldados);i++)
  		soldados[i]->Kill(TP || PO);
	}

 return ::DoDamage(dmg);
}

public varargs void Die(mixed silent) {
 Set("soldado_Akallab",0);
 ::Die(silent);
}
