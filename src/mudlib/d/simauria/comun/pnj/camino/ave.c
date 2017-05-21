   /*___________________________________________________________________*
   	*             Creacion 15-10-98 [C] Chaos                           *
   	*                                                                   *
   	*Este fichero funciona para la subraza ave dentro de animales.      *
   	*                                                                   *
   	*Genera desde el  Tamanyo, la descripcion, el nivel, los ataques    *
   	*su armadura y el peso del ave.                                     *
    *                                                                   *
   	*Esto es una prueba ya intentare pulirlo mas.                       *
    *																    *
   	*Disculpen las descripciones que aparecen mas adelante pondre alguna*
   	*mucho mejor que las que hay ahora.									*
    *___________________________________________________________________*/
// inherit "/std/npc/animal";
inherit "d/simauria/comun/pnj/camino/animal";


create() {
  ::create();
  SetRace("ave");
  SetSize(1);
  AddId("ave","pajaro");
  SetLevel(1+random(2));
}
 int SetSize(int i){
  int out;
  int valor;
  out=::SetSize(i);
  switch (QuerySize()) {
     case 1:   		SetLong("Es "+QueryShort()+". Tiene unas plumas muy vistosas y bonitas que le ayudan\n"+
  			  				"a la hora de volar. En el suelo es algo torpe por que sus patas no estan\n"+
              				"preparadas para correr.\n");
					//SetLevel(1+random(4));
					valor=((QueryLevel()+1)/2);
					SetHands(({ ({"pico",0,valor}) }));
  					SetAC(0);
					SetWeight(!QueryWeight()?3000:QueryWeight());
					break;
     case 2:		SetLong("Es "+QueryShort()+". Tiene unas plumas que le recubren todo el cuerpo\n"+
	 						"Sus extremidades superiores se han convertido en alas para poder volar. Sus\n"+
  			  				"patas tienen cuatro dedos y no estan preparadas para correr.\n");
					//SetLevel(5+random(6));
					valor=((QueryLevel()+1)/2);
					SetHands(({ ({"pico",0,(valor+2)}),({"garra derecha",0,(valor-2)}),({"garra izquierda",0,(valor-2)}) }));
  					SetAC(3);
					SetWeight(!QueryWeight()?80000:QueryWeight());
					break;
     case 3:   		SetLong("Es "+QueryShort()+". Cada pluma es larga como una espada corta y ancha como\n"+
	 						"un libro. La sombra que proyecta es enorme y cubre toda una carreta con el\n"+
							"tiro incluido.Es capaz cazar vacas y animales de un tamanyo mayor con sus\n"+
							"garras. Sus patas acaban en enormes garras que estan afiladas como cuchillas.\n");
					//SetLevel(11+random(10));
					valor=((QueryLevel()+1)/2);
					SetHands(({ ({"pico",0,(valor+4)}),({"garra derecha",0,valor}),({"garra izquierda",0,valor}) }));
  					SetAC(6);
					SetWeight(!QueryWeight()?4000000:QueryWeight());
					break;
	default:		SetLong("Es "+QueryShort()+". Tiene unas plumas muy vistosas y bonitas que le ayudan\n"+
  			  				"a la hora de volar. En el suelo es algo torpe por que sus patas no estan\n"+
              				"preparadas para correr.\n");
					SetLevel(1+random(4));
					SetHands(({ ({"pico",0,3}) }));
  					SetAC(0);
					break;
  }
 return out;
}
