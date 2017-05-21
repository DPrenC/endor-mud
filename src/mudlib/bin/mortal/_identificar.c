/** ENDOR-MUD'/bin/mortal/_identificar.c'
para obtener información sobre armas usando la habilidad de identificar armas.
 *  =========================================
 */

#include <skills.h>
#include <materials.h>
#include <combat.h>
#include <properties.h>
#include "./funciones.ic"

int main(string str)
{
    object ob;
  string td_txt,type,res = "";
  string td,manos,hab,mat,peso,estado,wc,magia;
  int identificar, bonus_gremio = 0;
  if (!TP) return 0;
  if (!str)
    return notify_fail("¿Qué quieres identificar?\n"),0;
  if (  !check_sight() || check_ghost() || check_delay())
    return 0;
  if (!ob=search(TP,str,SM_OBJECT|SEARCH_INV_ENV))
    return _notify_fail("No encuentras "+str+" por ningún sitio.\n");
  switch (TP->QueryGuild()){
    case "guerrero": bonus_gremio = BONUS_GUERREROS_IDENTIFICAR; break;
        case "aventurero": bonus_gremio = BONUS_AVENTUREROS_IDENTIFICAR; break;
            case "herrero": bonus_gremio = BONUS_HERREROS_IDENTIFICAR; break;
                default: bonus_gremio=0; break;
            }
  identificar = TP->UseSkill(HAB_IDENTIFICAR, bonus_gremio);
  if ( !TP->HasSkill(HAB_IDENTIFICAR))
    return _notify_fail("No tienes conocimientos suficientes para hacer uso del comando identificar.\n",
                      ({Descr(TP)+" observa "+Descr(ob)+" con notables dudas.\n",
			""}));
  if (member(inherit_list(ob),"/std/weapon.c")==-1)
         return _notify_fail(Descr(ob,1)+" no tiene la apariencia de poder utilizarse como arma.\n",
		       ({Descr(TP,1)+" observa con atención "+Descr(ob)+".\n",
			 ""}));
    {
      switch (ob->QueryWeaponType())
	{
	 case WT_ALABARDA: type=HAB_ALABARDA; break;
	 case WT_HACHA:    type=HAB_HACHA;    break;
	 case WT_CADENA:   type=HAB_CADENA;   break;
	 case WT_MAZA:     type=HAB_MAZA;     break;
	 case WT_CUCHILLO: type=HAB_CUCHILLO; break;
	 case WT_LANZA:    type=HAB_LANZA;    break;
	 case WT_VARA:     type=HAB_VARA;     break;
	 case WT_ESPADA:   type=HAB_ESPADA;   break;
	 case WT_ESGRIMA:  type=HAB_ESGRIMA;  break;
	 case WT_LATIGO:   type=HAB_LATIGO;   break;
	 case WT_MANOPLA:  type=HAB_MANOPLA;  break;
	 case WT_MANGUAL:  type=HAB_MANGUAL;  break;
	    case WT_DAGA: type=HAB_DAGA;  break;
	        case WT_GARROTE:  type=HAB_GARROTE;   break;
	            case WT_ESPADA_CORTA:  type=HAB_ESPADA_CORTA;  break;
	                case WT_CIMITARRA:  type=HAB_CIMITARRA;  break;
	                    case WT_MANDOBLE:  type=HAB_MANDOBLE;  break;
	                    case WT_CAYADO:  type=HAB_CAYADO;  break;
	                    case WT_JABALINA:  type=HAB_JABALINA;  break;
	                    case WT_PICA:  type=HAB_PICA;  break;
	                    case WT_CIMITARRA_PESADA:  type=HAB_CIMITARRA_PESADA;  break;
	                    case WT_MAZA_PESADA:  type=HAB_MAZA_PESADA;  break;
	                    case WT_MARTILLO:  type=HAB_MARTILLO;  break;
	                    case WT_MARTILLO_PESADO:  type=HAB_MARTILLO_PESADO;  break;
	                    case WT_HACHA_PESADA:  type=HAB_HACHA_PESADA;  break;
	                    case WT_HACHA_KHAZAD:  type=HAB_HACHA_KHAZAD;  break;
	                    case WT_MANGUAL_PESADO:  type=HAB_MANGUAL_PESADO;  break;
	                    case WT_ESPADA_SINDA:  type=HAB_ESPADA_SINDA;  break;
	                    case WT_PICO:  type=HAB_PICO;  break;
	                    case WT_AZADON:  type=HAB_AZADON;  break;
	                    case WT_ESPADA_MEDIANA:  type=HAB_ESPADA_MEDIANA;  break;
	                    case WT_IMPROVISADA:  type=HAB_IMPROVISADA;  break;
	 default: {
	    type= "desconocida";
res = 	    "El tipo de daño "+ob->QueryWeaponType()+
	    " no está registrado, informa a un Vala.\n";
	} //default
	} // switch type
switch (ob->QueryDamType()){
    case TD_CORTE: td_txt=TD_CORTE_TXT; break;
    case TD_APLASTAMIENTO: td_txt=TD_APLASTAMIENTO_TXT; break;
        case TD_PENETRACION: td_txt=TD_PENETRACION_TXT; break;
            case TD_LACERACION: td_txt=TD_LACERACION_TXT; break;
                case TD_ABRASIVO: td_txt=TD_ABRASIVO_TXT; break;
                }// switch td_txt

	res+="Analizas con detenimiento "+Descr(ob)+" llegando a la conclusión que ";
	td= "hace un daño del tipo "+td_txt;
	manos = "se empuña con "+(ob->QueryNumberHands()==1 ? "una mano" : "las dos manos");
	    hab = "es imprescindible dominar la habilidad de "+type;
	    mat = "se ha hecho con "+ob->QueryMaterial();
	    peso = PesoAprox(ob->QueryWeight());
	    estado = "su deterioro es "+(ob->QueryQuality()<5 ? "total, está inservible" : (ob->QueryQuality()>=99 ? "nulo, está en perfectas condiciones" : "del "+(ob->QueryResetQuality()-ob->QueryQuality())+"%"));
	    wc = "produce un daño de "+ob->QueryWC();
	    magia = " y deduces que "+(ob->QueryMagic()==1 ? "es un arma mágica.\n" : " no tiene pinta de ser un arma mágica.\n");
	switch(identificar){
	    case 0..5:
res += td; break; // tipo de daño
	        case 6..10:
res += td+" y "+manos; break; // tipo de daño + cantidad de manos
	            case 11..15:
res += td+", "+manos+" y "+hab; break; //tipo de daño, cantidad de manos y habilidad
	            case 16..25:
res += td+", "+manos+", "+hab+" y "+mat; break; //tipo de daño, manos, habilidad y material.
	                case 26..40:
res += td+", "+manos+", "+hab+", "+mat+" y "+peso; break; // tipo de daño, manos, habilidad, material y peso.
	                    case 41..60:
res += td+", "+manos+", "+hab+", "+mat+","+peso+" y "+estado; break; // tipo de daño, manos, habilidad, material, peso y deterioro
	                        case 61..85:
res += td+", "+manos+", "+hab+", "+mat+", "+peso+", "+estado+" y "+wc;break; // tipo de daño, manos, habilidad, material, peso, estado y wc
	                            case 86..300:
res += td+", "+manos+", "+hab+", "+mat+", "+peso+", "+estado+", "+wc+magia; break;// tipo de daño, manos, habilidad, material, peso, estado, wc y arma mágica.
	                                default:
	                                    res += "posiblemente se pueda usar como arma";
	                                    break;
	                                } //switch identificar
res += ".\n";
res += "Resultado de la tirada para testeo: "+identificar+".\n";
      return _notify_succes(res,
		       ({Descr(TP,1)+" estudia con interés "+Descr(ob)+".\n",
		        ""}));
}
}
