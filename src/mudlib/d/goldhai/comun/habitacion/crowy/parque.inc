
//pnjs
 AddItem(PNJ("parque/ardilla"), REFRESH_DESTRUCT, 1+random(2) );
 AddItem(PNJ("parque/liebre"), REFRESH_DESTRUCT,random(1) );
 AddItem(PNJ("parque/conejo"), REFRESH_DESTRUCT, 1+random(2) );
 //AddItem(PNJ("parque/oso"), REFRESH_DESTRUCT,random(1));
 //AddItem(PNJ("parque/osezno"), REFRESH_DESTRUCT,4);


//ambiente
 SetIntShort("el parque");
 SetIntNoise("Los pájaros cantan y los insectos zumban.\n");
 SetIntSmell("Hueles a naturaleza, árboles y plantas.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto 
 
//detalles
 AddDetail("matorrales","Son densos y frecuentes en esta zona.\n");
 AddDetail(({"arbol","arboles"}),"Hay bastantes árboles en este parque.\n");
 AddDetail("muro","No parece muy grueso pero es lo suficientemente alto.\n");
 AddDetail("parque","Es un area verde entre la ciudad y el muro de la cidudad.\n");
 AddDetail("flores","Huelen bien.\n");
//varios 
 SetLocate("Crowy");
