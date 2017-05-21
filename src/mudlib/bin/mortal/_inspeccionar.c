/** ENDOR-MUD'/bin/mortal/_inspeccionar.c'
para obtener información sobre ropas y armaduras usando la habilidad de inspeccionar atavíos.
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
    string type,at,mat,peso,estado,ac,magia, res="";
  int inspeccionar, bonus_gremio = 0;
  if (!TP) return 0;
  if (!str)
    return notify_fail("¿Qué quieres inspeccionar?\n"),0;
  if (  !check_sight() || check_ghost() || check_delay())
    return 0;
  if (!ob=search(TP,str,SM_OBJECT|SEARCH_INV_ENV))
    return _notify_fail("No encuentras "+str+" por ningún sitio.\n");
  switch (TP->QueryGuild()){
    case "guerrero": bonus_gremio = BONUS_GUERREROS_IDENTIFICAR; break;
        case "aventurero": bonus_gremio = BONUS_AVENTUREROS_IDENTIFICAR; break;
            case "herrero": bonus_gremio = BONUS_HERREROS_IDENTIFICAR; break;
            }
  inspeccionar = TP->UseSkill(HAB_INSPECCIONAR, bonus_gremio);
  if ( !TP->HasSkill(HAB_INSPECCIONAR))
    return _notify_fail("No tienes conocimientos suficientes para hacer uso del comando inspeccionar.\n",
                      ({Descr(TP)+" observa "+Descr(ob)+" con notables dudas.\n",
			""}));
  if (member(inherit_list(ob),"/std/armour.c")==-1)
         return _notify_fail(Descr(ob,1)+" no parece que se pueda vestir ni equipar.\n",
		       ({Descr(TP,1)+" observa con atención "+Descr(ob)+".\n",
			 ""}));
    {
        switch(type = ob->QueryArmourType()){
         case AT_SKIN: type ="tu piel desnuda"; break;
         case AT_RING: type = "una joya de tipo anillo que se pone en un dedo"; break;
         case AT_AMULET: type = "una joya de tipo amuleto que se cuelga del cuello"; break;
         case AT_BOOTS: type = "unas piezas de vestir de tipo calzado que se pone en los pies"; break;
         case AT_CLOAK: type = "una prenda de vestir de tipo túnica que cubre el cuerpo"; break;
         case AT_MAIL: type = "una pieza de armadura de tipo coraza que cubre el torso"; break;
         case AT_GLOVES: type = "unas prendas de vestir de tipo guantes que se pone en las manos"; break;
         case AT_HELMET: type = "una pieza de armadura de tipo casco que cubre la cabeza"; break;
         case AT_SHIELD: type = "una pieza de armadura de tipo escudo que se lleva en la mano"; break;
	 case AT_TROUSERS: type = "una prenda de vestir de tipo pantalones que se pone en las piernas"; break;
	case AT_MANTO: type = "una prenda de vestir de tipo manto que cubre el cuerpo"; break;
	case AT_CAPUCHA: type = "una prenda de vestir de tipo capucha que se pone en la cabeza"; break;
	case AT_GREBAS: type = "unas piezas de armadura de tipo grebas que cubre las piernas"; break;
	case AT_CINTURON: type = "una prenda de ropa de tipo cinturón que se pone en la cintura"; break;
case AT_TALABARTE: type = "una prenda de ropa de tipo talabarte que se pone en el torso"; break;
case AT_BROCHE: type = "una joya de tipo broche que se pone en el torso"; break;
case AT_BRAZALES: type = "unas piezas de armadura de tipo brazales que cubre los brazos"; break;
case AT_PULSERA: type = "una joya del tipo pulsera que se pone en las muñecas"; break;
case AT_TABARDO: type = "una pieza de armadura de tipo tabardo que cubre el torso"; break;
case AT_TIARA: type = "una joya de tipo tiara que se pone en la cabeza"; break;
    case AT_FALDA: type = "una prenda de vestir de tipo falda que se pone en las piernas"; break;
        case AT_CAMISA: type = "una prenda de vestir de tipo camisa que se pone en el torso"; break;
	   default: type = "desconocida, informa a un Vala.\n";
      	    break;
      	    	} // switch armour
	res+="Inspeccionas meticulosamente "+Descr(ob)+" observando que se trata de ";
    mat = "que se ha hecho con "+ob->QueryMaterial();
	peso = PesoAprox(ob->QueryWeight());
	    estado = "su deterioro es "+(ob->QueryQuality()<5 ? "total, está inservible" : (ob->QueryQuality()>=99 ? "nulo, está en perfectas condiciones" : "del "+(ob->QueryResetQuality()-ob->QueryQuality())+"%"));
	    ac = "tiene una protección de "+ob->QueryAC();
	    magia = " y deduces que "+(ob->QueryMagic()==1 ? "es un objeto mágica.\n" : " no tiene pinta de ser un objeto mágica.\n");
	switch(inspeccionar){
	    case 0..5:
res += type; break; // tipo de armadura
	    case 6..10:
res += type+" y "+mat; break; //tipo  de armadura y material
	                case 11..20:
res += type+", "+mat+" y "+peso; break; // tipo de armadura, material y peso.
	                    case 21..35:
res += type+", "+mat+","+peso+" y "+estado; break; // tipo de armadura, material, peso y deterioro
	                        case 36..50:
res += type+", "+mat+", "+peso+", "+estado+" y "+ac;break; // tipo de armadura, material, peso, estado y protección
	                            case 51..300:
res += type+", "+mat+", "+peso+", "+estado+", "+ac+magia; break;// tipo de armadura, material, peso, estado, protección y armadura mágica.
	                                default:
	                                    res += "algo para ponerse en alguna parte del cuerpo";
	                                    break;
	                                } //switch inspeccionar
res += ".\n";
res += "Resultado de la tirada para testeo: "+inspeccionar+".\n";
      return _notify_succes(res,
		       ({Descr(TP,1)+" estudia con interés "+Descr(ob)+".\n",
		        ""}));
}
}
