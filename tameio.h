/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Argyriou Nikolaos-23/3/18>
**************************************************/
#ifndef TAMEIO_H
#define TAMEIO_H

#include <stdio.h>

typedef struct TTameio {
	int TimeBusy; /* Xronos pou itan apasxolimenos */
	int TimeInactive; /* Xronos itan adranis */
	int ArithmoPleaton; /* Arithmos pelatwn pou eksipiretise */
	int enapomenonXronos; /* Enapomenon xronos gia eksipiretisi pelati */
} TTameio;

void TameioDimiourgia(TTameio *); //αρχικοποιεί τα μέλη του struct ταμείο
void TameioNoWork(TTameio *); // αυξάνει χρόνο αδράνειας
void TameioNewCustomer(TTameio *, int Duration); // αυξάνει τον μετρητή πελατών και αρχικοποιεί εναπομείναντα χρόνο εξυπηρέτησης
void TameioInService(TTameio *); // μειώνει χρόνο εξυπηρέτησης κατά 1
void TameioBusy(TTameio *); // αυξάνει χρόνο απασχόλησης
int TameioGetArithmosPelatwn(TTameio *); // επιστρέφει τον αριθμό πελατών
int TameioGetInactiveXronos(TTameio *); // επιστρέφει χρόνο αδράνειας
int TameioFree(TTameio); // ελέγχει αν είναι διαθέσιμο
int TameioGetBusyXronos(TTameio *); // επιστρέφει χρόνο απασχόλησης

#endif
