/***************************************************************************************
 ARCHIVO:	kenton.h
 AUTOR:		[z] Zomax
 FECHA:		19-02-2002
 COMENTARIOS:	Archivo de defines del Dominio de Kenton
 ***************************************************************************************/
#ifndef __KENTON_H
#define __KENTON_H

/**********    KENTON     **********/
#define DOMINIO	"kenton"
#include <domain.h>
#include <properties.h>

/************** caravanas ***********/


#define C_KENTON(x) CARAVANA("kenton/" + x)


/***********    FERIA     ***********/
#define FERHAB		HABITACION	"feria/"
#define FERPNJ		PNJ("feria/")
#define FERARM		ARMA("feria/")
#define FERPRT	  PROT("feria/")
#define FERVAR		OTRO("feria/")
#define FERBEB	 	BEBIDA("feria/")
#define FERFOD		COMIDA("feria/")
#define FERMAG		MAGIA("feria/"

/**********    FLENTON     **********/
#define FLENHAB		HABITACION	"flenton/"
#define FLENPNJ		PNJ("flenton/")
#define FLENARM		ARMA("flenton/")
#define FLENPRT		PROT("flenton/")
#define FLENVAR		OTRO("flenton/")
#define FLENBEB		BEBIDA("flenton/")
#define FLENFOD		COMIDA("flenton/")
#define FLENMAG		MAGIA("flenton/")

/**********    KHURTON     **********/
#define KHURHAB		HABITACION	"khurton/"
#define KHURPNJ		PNJ("khurton/")
#define KHURARM		ARMA("khurton/")
#define KHURPRT		PROT("khurton/")
#define KHURVAR		OTRO("khurton/")
#define KHURBEB		BEBIDA("khurton/")
#define KHURFOD		COMIDA("khurton/")
#define KHURMAG		MAGIA("khurton/")

/**********    KLARITON    **********/
#define KLARSYS   DOM_SYS "klariton.h"
#define KLARHAB		HABITACION	"klariton/"
#define KLARPNJ		PNJ("klariton/")
#define KLARARM		ARMA("klariton/")
#define KLARPRT		PROT("klariton/")
#define KLARVAR		OTRO("klariton/")
#define KLARBEB		BEBIDA("klariton/")
#define KLARFOD		COMIDA("klariton/")
#define KLARMAG		MAGIA("klariton/")

/**********    HURGATON    **********/
#define HURGHAB		HABITACION	"hurgaton/"
#define HURGPNJ		PNJ("hurgaton/")
#define HURGARM		ARMA("hurgaton/")
#define HURGPRT		PROT("hurgaton/")
#define HURGVAR		OTRO("hurgaton/")
#define HURGBEB		BEBIDA("hurgaton/")
#define HURGFOD		COMIDA("hurgaton/")
#define HURGMAG		MAGIA("hurgaton/")

/**********     NAINTON    **********/
#define NAINHAB		HABITACION	"nainton/"
#define NAINPNJ		PNJ("nainton/")
#define NAINARM		ARMA("nainton/")
#define NAINPRT		PROT("nainton/")
#define NAINVAR		OTRO("nainton/")
#define NAINBEB		BEBIDA("nainton/")
#define NAINFOD		COMIDA("nainton/")
#define NAINMAG		MAGIA("nainton/")

/**********     VARIOS    **********/
#define LINKKHA		"/d/kha-annu/comun/habitacion/caminos/kha-kenton/kha-kenton20"
#define CAR_FLE 	HABITACION "flenton/calles/plaza_00"
#define CAR_KHA 	"/d/kha-annu/comun/habitacion/kha-annu/ciudad/puertanor/hall2"
#define CAR_DEN	    C_KENTON("dentro")
#define FERIAMASTER	DOM_STD"feriamaster"

/**********     CONSTANTES**********/
#define LUZDEDIA    80

/*****  GRAMATICA GENERAL  *****/

#define AO	      (this_player()->QueryGender()==GENDER_FEMALE?"a":"o")
#define ENTP	    environment(this_player())
#define CATO 	    capitalize(this_object()->QueryRealName())
#define CATP 	    capitalize(this_player()->QueryRealName())

#endif /* __KENTON_H */