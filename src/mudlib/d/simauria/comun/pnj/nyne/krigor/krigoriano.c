/*=============================================================*
 |         << Simauria.Krigor [Ch] Chaos@simauria >>           |
 *=============================================================*
 |               Creacion............. 05-11+01                |
 |               Modificacion..........27-11-01                                              |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


inherit NPC;


  string nombre,raza,raza1,art,tmp2;
  int rnd,nivel,sexo,edad,guerrero,borracho,tmp;
  int cobre, plata, oro;
  object item;

create(){
  ::create();
	nombre="";
	rnd=random(2)+1;
	switch(rnd)
	{
		 case 1: sexo=1; art="un ";   break;  //masculino
		 case 2: sexo=2; art="una ";  break;  //femenino
		 default: sexo=1;break;
	}

	rnd=random(5)+1;                // Edad del habitante de krigor.
	switch(rnd)
	{
		 case 1: edad=0;    nombre+="bebe "; AddId("bebe");  break;
		 case 2: edad=1;    nombre+=(sexo==1?"pequeño ":"pequeña ");
	                    AddId((sexo==1?"pequeño":"pequeña"));
	                    AddId((sexo==1?"pequeño":"pequeña"));   break;
		 case 3: edad=2;    break; // Mediana edad
		 case 4: edad=3;    nombre+=(sexo==1?"viejo ":"vieja ");
			    AddId((sexo==1?"viejo":"vieja"));   break;
		 case 5: edad=4;    nombre+=(sexo==1?"anciano ":"anciana ");
                	    AddId((sexo==1?"anciano":"anciana"));  break;
 		default: edad=2;   break; // Por defecto es mediana edad
	}

	guerrero=0;                   // Por defecto no son guerreros.
	if(edad!=0&&edad!=4)          // Ni bebes ni ancianos pueden ser guerreros.
	{
		 rnd=random(3)+1;
		 if(rnd==3)
		{
   		    guerrero=1;
   			if (nombre!="") AddId((sexo==1?nombre+"guerrero":nombre+"guerrera"));
               			nombre+=(sexo==1?"guerrero ":"guerrera ");
               			AddId((sexo==1?"guerrero":"guerrera"));
 		}
	 }

	 raza1=(sexo==1?"pueblerino":"pueblerina");
	 raza="humano";


/*
Minimo nivel 5, maximo nivel 18:
                      bebe......5 a 6
                      pequeño..5 a 8
                      normal....12 a 15
                      viejo.....10 a 12
                      anciano...7 a 10
                      Si es hembra se le resta 1 al total
                      Si es guerrero/a se le añade 3 al total
*/
	nivel=5;
	switch(edad)
	{ // De 0 a 4
		 case 0:  nivel+=random(2);break;
		 case 1:  nivel+=random(4);break;
		 case 2:  nivel+=7+random(4);break;
		 case 3:  nivel+=5+random(3);break;
		 case 4:  nivel+=2+random(3);break;
		default: break;
	}
	if(guerrero==1) nivel+=3;

/* Si es macho, guerrero y edad superior a 1 tienes mas posibilidad
   de estar borracho y si lo estas, pues lo estas mas aun. Un bebe no
   puede estarlo jamas. */
	borracho=0;
	tmp=2+(sexo==1?0:1)+(guerrero==1?0:2)+(edad<2?3:0)+random(1);
	rnd=random(tmp)+1;
	if((rnd==tmp-1)&&(edad!=0))
	{
		borracho=1;
 		tmp2=(sexo==2?"borracha":"borracho");
    	 	AddId(tmp2);
		tmp2=raza1+" "+tmp2;
		AddId(tmp2);
	}

/* Se establecen los valores random */
	AddId(raza1);
	nombre+=raza1;
	AddId(nombre);
	if(borracho)
	{
		nombre+=(sexo==2?" borracha":" borracho");
		SetAlcohol(40);
	}
	AddId(nombre);
	nombre=art+nombre;
	SetStandard(nombre,raza,nivel,sexo);
	SetShort(nombre);
	SetLong("Se trata de "+nombre+".\n");
	SetAlign(0);
	SetWhimpy(QueryMaxHP()/4); // Que huya facilmente

	cobre=0; plata=0;
	switch(edad)
	{
 		case 0: cobre=random(7)+5;
        	break;
		case 1: cobre=random(3)+4; plata=random(1)+1;
        	break;
		case 2: plata=random(2)+3;
	        break;
		case 3: plata=random(4)+2;
	        break;
		case 4: plata=random(3)+2;
	        break;
		default: cobre=13; break;
	}
	if(borracho) // Si estas borracho tienes la mitad del dinero
	{
		cobre=cobre/2; plata=plata/2;
	}
	AddItem("/obj/money",REFRESH_REMOVE,
 		(["Money":(["cobre":cobre,"plata":plata])]));

	if (edad==0||edad==1)
	{
		InitChats(3,({
		    capitalize(TO->QueryName())+" llora desconsoladamente.. buuaahhhhhh..\n" }));
 		InitAChats(20,({
  		    capitalize(TO->QueryName())+" llora desconsoladamente.. buuaahhhhhh..\n" }));
	}

	if (guerrero && TO->QuerySize()==P_SIZE_MEDIUM && !borracho)
	{
			 if (edad >1 && edad <5)
		 {
			  AddItem(ARMA("claymore"),REFRESH_REMOVE,SF(wieldme));
			  AddItem(PROT("casco_hierro"),REFRESH_REMOVE,SF(wearme));
			  AddItem(PROT("camisa_cuero"),REFRESH_REMOVE,SF(wearme));
		 }
	}
	else
			 if (edad >1 && edad <5)
		{

  		          AddItem(ARMA("espada"),REFRESH_REMOVE,SF(wieldme));
  		}

	if (TO->QuerySize()==P_SIZE_MEDIUM && random(5)>2 && !guerrero)

		  AddItem(PROT("camisa_cuero"),REFRESH_REMOVE,SF(wearme));

	if (edad > 2 && !guerrero && random(5)>2 && TO->QuerySize()==P_SIZE_MEDIUM)

		 AddItem(ARMA("daga"),REFRESH_REMOVE,SF(wieldme));

	if (TO->QuerySize()==P_SIZE_SMALL && edad <2)
	{
		  AddItem(PROT("camisa_cuero_p"),REFRESH_REMOVE,SF(wearme));

		  if (guerrero)

		     AddItem(ARMA("vara"),REFRESH_REMOVE,SF(wieldme));
	}
	if (edad==5 && !guerrero)

		  AddItem(ARMA("vara"),REFRESH_REMOVE,SF(wieldme));

}

public int QueryKrigoriano()
{
return 1;
}
