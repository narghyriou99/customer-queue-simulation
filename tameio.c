#include "tameio.h"

void TameioDimiourgia(TTameio *tameio) //αρχικοποιεί τα μέλη του struct ταμείο
{
	tameio->TimeBusy = 0;
	tameio->TimeInactive = 0;
	tameio->enapomenonXronos = 0;
	tameio->ArithmoPleaton = 0;
}

// αυξάνει τον μετρητή πελατών και αρχικοποιεί εναπομείναντα χρόνο εξυπηρέτησης
void TameioNewCustomer(TTameio *tameio, int Duration)
{
	tameio->ArithmoPleaton++;
	tameio->enapomenonXronos = Duration;
	TameioBusy(tameio);
}

// μειώνει χρόνο εξυπηρέτησης κατά 1
void TameioInService(TTameio *tameio)
{
	tameio->enapomenonXronos-=1;
}

void TameioNoWork(TTameio *tameio) // αυξάνει χρόνο αδράνειας
{
	tameio->TimeInactive+=1;
}

void TameioBusy(TTameio *tameio) // αυξάνει χρόνο απασχόλησης
{
	tameio->TimeBusy+=1;
}

int TameioGetInactiveXronos(TTameio *tameio) // επιστρέφει χρόνο αδράνειας
{
	return tameio->TimeInactive;
}

int TameioGetBusyXronos(TTameio *tameio) // επιστρέφει χρόνο απασχόλησης
{
	return tameio->TimeBusy;
}
int TameioFree(TTameio tameio) // ελέγχει αν είναι διαθέσιμος
{
	return tameio.enapomenonXronos == 0;
}

int TameioGetArithmosPelatwn(TTameio *tameio) // επιστρέφει αριθμό πελατών
{
	return tameio->ArithmoPleaton;
}

