/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Argyriou Nikolaos-23/3/18>
**************************************************/
#ifndef __TStoixeiouOuras__ 
#define __TStoixeiouOuras__

typedef struct {
	int XronosEisodou; /* Minute of entering queue */
	int XronosEksipiretisis; /* Xronos eksipiretisis pelati */
} TSOuras; /* name TSOuras is used in ATD Oura - not to be changed */

void TSOurasSetValue(TSOuras *stoixeioPtr, TSOuras testdata);
/* name TSOurasSetValue is used in ATD Oura - not to be changed */

/* All names below indicate that Typos Stoixeiou is Pelatis */
void PelatisSetXronoEisodou(TSOuras *stoixeioPtr, int xronos);
int PelatisGetXronoEksipiretisis(TSOuras *stoixeioPtr);
int  PelatisGetXronoEisodou(TSOuras stoixeio);
void PelatisSetXronoEksipiretisis(TSOuras *stoixeioPtr, int xronos);

#endif

