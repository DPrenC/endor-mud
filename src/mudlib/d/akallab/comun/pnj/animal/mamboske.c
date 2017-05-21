/*
  **************************************************************
    Fichero para la generacion de mamiferos tipicos de un bosque

    04-11-98 	[Chaos]	Creacion
  **************************************************************
*/
#define ART (QueryArtIndString()+" ")

inherit "/d/akallab/comun/pnj/animal/animal";


  create(){
   int numero1;
   int numero2;
   ::create();
	numero1=random(12);
	numero2=random(2);
	SetSize(1);
	switch (numero1){
			case 0	:	SetGender(2);
					SetName(ART+"ardilla");
					AddId("ardilla");
					break;
			case 1	:	SetName(ART+"conejo");
					AddId("conejo");
					break;
			case 2	: 	SetName(ART+"raton");
					AddId("raton");
					break;
			case 3	: 	SetGender(2);
					SetName(ART+"marta");
					AddId("marta");
					break;
			case 4	: 	SetName(ART+"tejon");
					AddId("tejon");
					break;
			case 5	: 	SetGender(2);
					SetName(ART+"mofeta");
					SetSmell("Despide un olor muy desagradable.\n");
					AddId("mofeta");
					break;
			case 6  :	SetGender(2);
					SetName(ART+"mangosta");
					AddId("mangosta");
					SetDex(QueryLevel()+3);
					break;
			case 7  :	SetName(ART+"oso");
					SetSize(2);
					SetWeight(7500000);
					SetStr(QueryLevel()+3);
					AddId("oso");
					SetHands(({
		 					({"zarpa derecha",1,4+QueryLevel()/2}),
							({"zarpa izquierda",1,4+QueryLevel()/2}),
							({"boca",1,4+QueryLevel()/2})
						}));
					break;
			case 8  :	SetName(ART+"ciervo");
					SetSize(2);
					SetWeight(400000);
					AddId("ciervo");
					SetHands(({
		 					({"pata derecha",1,4+QueryLevel()/2}),
							({"pata izquierda",1,4+QueryLevel()/2}),
							({"cuernos",1,4+QueryLevel()/2})
						}));
					break;
			case 9  :	SetName(ART+"lince");
					AddId("lince");
					break;
			case 10  :	SetName(ART+"zorro");
					AddId("zorro");
					break;
			case 11	:	SetName(ART+"lobo");
					AddId("lobo");
					break;
			default : 	SetName(ART+"animalito");
					AddId("animalito");
					break;
   }
   	SetRace("mamifero");
	switch(numero2){
		case 0 	:  SetShort(QueryName());
			   SetLong("Es "+QueryName()+". Tiene todo su cuerpo recubierto de pelo. Se mueve por el "+
	 			  "con mucha naturalidad como si no estuvieses. Cuando le intentas tocar su piel se "+
				  "aleja.\n");
			   break;
		case 1	:  SetShort(QueryName());
			   SetLong("Es "+QueryName()+". Cuando te ve intenta esconderse. Parece que tu presencia "+
				  "le asusta, pero de pronto se te acerca con timidez, para ver que eres.\n");
			    break;
		default :  SetShort(QueryName());
			   SetLong("Es un animalillo tipico de un bosque. Se mueve entre los arboles, de cuando en "+
				  "en cuando te mira y se esconde para luego volver a salir y seguir con sus cosas.\n");
			  break;
   	return 1;
	}

}
