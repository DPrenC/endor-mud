/***
Fichero: Encina.c
Autor: [ztico].
Creaci�n: 04-03-05.
07-03-05: [kastwey]: Retoco un par de cosillas.
***/



inherit THING;

string leer();

public create()
{
    ::create();

    SetShort("una encina");
    SetLong(W("Es una espl�ndida y corpulenta encina cuyo grueso tronco invita a apoyarse en �l "
         "y descansar. Las ramas cubiertas de magn�ficas hojas verdes y brillantes proporcionan "
         "sombra a toda la plaza ofreciendo cobijo a los cansados caminantes. Vi�ndola, percibes "
         "una sensaci�n muy especial, como si de su interior brotara una poderosa energ�a que te "
         "llena de paz. Sientes que el �rbol te est� transmitiendo un mensaje. Fij�ndote con  "
         "atenci�n, descubres una talla en la corteza que quiz�s puedas leer.\n"));
    SetIds(({"arbol","�rbol","encina","la encina","Encina","La encina"}));
    SetNoGet("Est� fuertemente sujeta al suelo, es imposible que la puedas coger.\n");
    AddSubReadMsg(({"talla","la talla","inscripcion","inscripci�n"}),SF(leer));
}

string leer()
{
    say(CAP(TNAME) + " lee la talla de la encina.\n",TP);
    return
       W("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
         "     Al mayor Andross Coraz�n de Le�n, guerrero verdadero que supo luchar por la vida con valor,\n"
         "     derrochando amistad y  compa�erismo durante el breve tiempo que pas� entre nosotros. Por su\n"
         "     coraje,  por su simpat�a, por su  constancia  y por su generosidad. Siempre te recordaremos.\n"
         "\n"
         "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
}

