#include <combat.h>
#include <materials.h>

// Categorias de armas
#define WC_IMPROVISED	0				// Arma improvisada
#define WC_SIMPLE		1				// Arma simple
#define WC_MILITARY		2				// Arma de nivel militar
#define WC_SUPERIOR		3				// Arma de nivel superior

#define WC_MELEE		1				// Cuerpo a cuerpo
#define WC_RANGED		2				// A distancia

#define WC_ONE_HANDED	1				// Con una mano
#define WC_TWO_HANDED	2				// Con dos manos

// Grupos de armas
#define WG_AXE			1				// Hachas
#define WG_BOW			2				// Arcos
#define WG_CROSSBOW		3				// Ballestas
#define WG_FLAIL		4				// Manguales (o mayales o bola-y-cadena)
#define WG_HAMMER		5				// Martillos (de guerra)
#define WG_HEAVY_BLADE	6				// Espadas pesadas (espadones, espadas largas, etc.)
#define WG_LIGHT_BLADE	7				// Espadas ligeras (espadas cortas, dagas, floretes, etc.)
#define WG_MACE			8				// Mazas
#define WG_PICK			9				// Picos (de guerra)
#define WG_POLEARM		10				// Alabardas (y cualquier arma de mango largo)
#define WG_SLING		11				// Hondas
#define WG_SPEAR		12				// Lanzas
#define WG_STAFF		13				// Varas
#define WG_UNARMED		14				// Desarmado, las partes del cuerpo (codazos, rodillazos, cabezazos)

// Propiedas de las armas
#define WP_HEAVY_THROWN	1				// Se puede lanzar (de forma pesada) STRENGTH
#define WP_HIGH_CRIT	2				// Incrementa el critical
#define WP_LIGHT_THROWN	3				// Se puede lanzar (de forma ligera) DEXTERITY
#define WP_LOAD			4				// Para armas RANGED cuanto tardan en cargarse
#define WP_OFF_HAND		5				// Se puede usar como arma secundario (en la mano mala)
#define WP_REACH		6				// Icrementa el alcance de una MELEE en 2 cuadros
#define WP_SMALL		7				// Los personajes SMALL pueden usar una arma TWO_HANDED o VERSATIL que es MEDIUM
#define WP_VERSATILE	8				// Anade +1 de daño si se usa TWO_HANDED (cuando es ONE_HANDED)

// Armas standard (ya definidas)
/*
Melee Weapons
SIMPLE MELEE WEAPONS
One-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Club +2 1d6 - 1 gp 3 lb. Mace -
Dagger +3 1d4 5/10 1 gp 1 lb. Light blade Off-hand, light thrown
Javelin +2 1d6 10/20 5 gp 2 lb. Spear Heavy thrown
Mace +2 1d8 - 5 gp 6 lb. Mace Versatile
Sickle +2 1d6 - 2 gp 2 lb. Light blade Off-hand
Spear +2 1d8 - 5 gp 6 lb. Spear Versatile
Two-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Greatclub +2 2d4 - 1 gp 10 lb. Mace -
Morningstar +2 1d10 - 10 gp 8 lb. Mace -
Quarterstaff +2 1d8 - 5 gp 4 lb. Staff -
Scythe +2 2d4 - 5 gp 10 lb. Heavy blade -
MILITARY MELEE WEAPONS
One-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Battleaxe +2 1d10 - 15 gp 6 lb. Axe Versatile
Flail +2 1d10 - 10 gp 5 lb. Flail Versatile
Handaxe +2 1d6 5/10 5 gp 3 lb. Axe Off-hand, heavy thrown
Longsword +3 1d8 - 15 gp 4 lb. Heavy blade Versatile
Scimitar +2 1d8 - 10 gp 4 lb. Heavy blade High crit
Short sword +3 1d6 - 10 gp 2 lb. Light blade Off-hand
Throwing hammer +2 1d6 5/10 5 gp 2 lb. Hammer Off-hand, heavy thrown
Warhammer +2 1d10 - 15 gp 5 lb. Hammer Versatile
War pick +2 1d8 - 15 gp 6 lb. Pick High crit, versatile
Two-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Falchion +3 2d4 - 25 gp 7 lb. Heavy blade High crit
Glaive +2 2d4 - 25 gp 10 lb. Heavy blade, polearm Reach
Greataxe +2 1d12 - 30 gp 12 lb. Axe High crit
Greatsword +3 1d10 - 30 gp 8 lb. Heavy blade -
Halberd +2 1d10 - 25 gp 12 lb. Axe, polearm Reach
Heavy flail +2 2d6 - 25 gp 10 lb. Flail -
Longspear +2 1d10 - 10 gp 9 lb. Polearm, spear Reach
Maul +2 2d6 - 30 gp 12 lb. Hammer -
SUPERIOR MELEE WEAPONS
One-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Bastard sword +3 1d10 - 30 gp 6 lb. Heavy blade Versatile
Katar +3 1d6 - 3 gp 1 lb. Light blade Off-hand, high crit
Rapier +3 1d8 - 25 gp 2 lb. Light blade -
Two-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Spiked chain +3 2d4 - 30 gp 10 lb. Flail Reach
IMPROVISED MELEE WEAPONS
One-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Any* n/a 1d4 - - 1.5 lb. None -
Unarmed attack n/a 1d4 - - - Unarmed -
Two-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Any* n/a 1d8 - - 6.12 lb. None -
* Improvised weapons include anything you happen to pick up, from a rock to a chair.

Ranged Weapons
SIMPLE RANGED WEAPONS
One-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Hand crossbow +2 1d6 10/20 25 gp 2 lb. Crossbow Load free
Sling +2 1d6 10/20 1 gp 0 lb. Sling Load free
Two-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Crossbow +2 1d8 15/30 25 gp 4 lb. Crossbow Load minor
MILITARY RANGED WEAPONS
Two-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Longbow +2 1d10 20/40 30 gp 3 lb. Bow Load free
Shortbow +2 1d8 15/30 25 gp 2 lb. Bow Load free, small
SUPERIOR RANGED WEAPONS
One-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Shuriken (5) +3 1d4 6/12 1 gp 1/2 lb. Light blade Light thrown
IMPROVISED RANGED WEAPONS
One-Handed
Weapon Prof. Damage Range Price Weight Group Properties
Any* n/a 1d4 5/10 - 1 lb. None -
* Improvised weapons include anything you happen to pick up, from a rock to a chair.
*/

// Simple Melee one-handed
#define WS_CLUB							1		// Porra
#define WS_DAGGER						2		// Daga
#define WS_JAVELIN						3		// Javalina
#define WS_MACE							4		// Maza
#define WS_SICKLE						5		// Hoz
#define WS_SPEAR						6		// Lanza

// Simple Melee two-handed
#define WS_GREATCLUB					7		// Garrote
#define WS_MORNINGSTAR					8		// Mazo con pinchos
#define WS_QUARTERSTAFF					9		// Bastón
#define WS_SCYTHE						10		// Guadaña

// Military Melee one-handed
#define WS_BATTLEAXE					11		// Hacha de batalla
#define WS_FLAIL						12		// Mangual (Mayal)
#define WS_HANDAXE						13		// Hacha de mano
#define WS_LONGSWORD					14		// Espada larga
#define WS_SCIMITAR						15		// Cimitarra
#define WS_SHORT_SWORD					16		// Espada corta
#define WS_THROWING_HAMMER				17		// Martillo lanzador
#define WS_WARHAMMER					18		// Martillo de guerra
#define WS_WAR_PICK						19		// Pico de guera

// Military Melee two-handed
#define WS_FALCHION						20		// Espada falchion
#define WS_GLAIVE						21		// Glaive (espada con mango largo)
#define WS_GREATAXE						22		// Gran hacha
#define WS_GREATSWORD					23		// Espadón
#define WS_HALBERD						24		// Alabarda
#define WS_HEAVY_FLAIL					25		// Mangual pesado
#define WS_LONGSPEAR					26		// Pica
#define WS_MAUL							27		// Mazo

// Superior Melee one-handed
#define WS_BASTARD_SWORD				28		// Espada bastarda
#define WS_KATAR						29		// Katar (un tipo de daga)
#define WS_RAPIER						30		// Estoque

// Superior Melee two-handed
#define WS_SPIKED_CHAIN					31		// Cadena con pinchos

// Improvised Melee one-handed
#define WS_IMPROVISED_MELEE_ONE_ANY		32
#define WS_IMPROVISED_MELEE_ONE_UNARMED	33

// Improvised Melee two-handed
#define WS_IMPROVISED_MELEE_TWO_ANY		34

// Simple Ranged one-handed
#define WS_HAND_CROSSBOW				35		// Ballesta de mano
#define WS_SLING						36		// Honda

// Simple Ranged two-handed
#define WS_CROSSBOW						37		// Ballesta

// Military Ranged two-handed
#define WS_LONGBOW						38		// Arco largo
#define WS_SHORTBOW						39		// Arco corto

// Superior Ranged one-handed
#define WS_SHURIKEN						40		// Shuriken

// Improvised Ranged one-handed
#define WS_IMPROVISED_RANGED_ONE_ANY	41

#define WS_FIRST						WS_CLUB
#define WS_LAST							WS_IMPROVISED_RANGED_ONE_ANY

// DAÃ±os permitods en DND 4E
#define W_DAMAGES_ONE_HANDED ({"1d4", "1d6", "1d8", "1d10", "1d12", "2d6", "2d8", "2d10"})
#define W_DAMAGES_TWO_HANDED ({"1d8", "2d4", "1d10", "1d12", "2d6", "2d8", "2d10"})

// -------------------------------------
// Compatibilidad con Simauria
// -------------------------------------

/*	WT_MANOPLA: HAB_MANOPLA    ,\	*/ 
/*	WT_LATIGO:  HAB_LATIGO     ,\	*/
#define WS_SIM_DND4E ([\
	WT_ESGRIMA: WS_DAGGER      ,\
 	WT_ESPADA:  WS_SCYTHE      ,\
	WT_HACHA:   WS_HANDAXE     ,\
	WT_MAZA:    WS_CLUB        ,\
	WT_LANZA:   WS_JAVELIN     ,\
	WT_CUCHILLO:WS_DAGGER      ,\
	WT_VARA:    WS_QUARTERSTAFF,\
	WT_ALABARDA:WS_GLAIVE      ,\
	WT_CADENA:  WS_FLAIL       ,\
	WT_MANGUAL: WS_FLAIL       ,\
 ])

#define WS_DND4E_SIM ([\
	WG_AXE:			WT_HACHA,\
	WG_BOW:			WT_CUCHILLO,\
	WG_CROSSBOW:	WT_CUCHILLO,\
	WG_FLAIL:		WT_MANGUAL,\
	WG_HAMMER:		WT_MAZA,\
	WG_HEAVY_BLADE:	WT_ESPADA,\
	WG_LIGHT_BLADE:	WT_CUCHILLO,\
	WG_MACE:		WT_MAZA,\
	WG_PICK:		WT_MAZA,\
	WG_POLEARM:		WT_ESPADA,\
	WG_SLING:		WT_CUCHILLO,\
	WG_SPEAR:		WT_LANZA,\
	WG_STAFF:		WT_VARA,\
])

#define WG_MATERIALS ([\
	WG_AXE:			M_HIERRO,\
	WG_BOW:			M_MADERA,\
	WG_CROSSBOW:	M_MADERA,\
	WG_FLAIL:		M_HIERRO,\
	WG_HAMMER:		M_HIERRO,\
	WG_HEAVY_BLADE:	M_HIERRO,\
	WG_LIGHT_BLADE:	M_HIERRO,\
	WG_MACE:		M_MADERA,\
	WG_PICK:		M_HIERRO,\
	WG_POLEARM:		M_HIERRO,\
	WG_SLING:		M_CUERO,\
	WG_SPEAR:		M_HIERRO,\
	WG_STAFF:		M_MADERA,\
])

#define WG_DAMAGES ([\
	WG_AXE:			TD_CORTE,\
	WG_BOW:			TD_PENETRACION,\
	WG_CROSSBOW:	TD_PENETRACION,\
	WG_FLAIL:		TD_APLASTAMIENTO,\
	WG_HAMMER:		TD_APLASTAMIENTO,\
	WG_HEAVY_BLADE:	TD_CORTE,\
	WG_LIGHT_BLADE:	TD_CORTE,\
	WG_MACE:		TD_APLASTAMIENTO,\
	WG_PICK:		TD_PENETRACION,\
	WG_POLEARM:		TD_CORTE,\
	WG_SLING:		TD_PENETRACION,\
	WG_SPEAR:		TD_PENETRACION,\
	WG_STAFF:		TD_APLASTAMIENTO,\
])
