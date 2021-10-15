/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 07/03/2016
Skopos				: Ylopoihsh ouras prosomoiwshs
Revision 			:  <Argyriou Nikolaos-23/3/18>
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tameio.h"
#include "ch6_QArray.h"
#include "TStoixeiouOuras.h"

#define BONUS_ENABLE   0

int main(void)
{	TOuras      	oura;				 /*oura pelatwn-aytokinhtvn */
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	xronos_eksipiretisis;/*xronos e3yphrethshs enos pelath*/ 
	unsigned int	xronos_prosomoiosis; /*synolikos xronos prosomoiwshs*/
	
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	unsigned int	enapomenon_xronos;	 /*xronos gia to telos e3yphrethshs enos pelath*/
	unsigned int	arithmos_pelaton; 	 /*plh8os e3yphreth8entwn pelatwn*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/
	TSOuras			Pelatis;		 	/* o pelaths sthn oyra*/
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	int             tamiasInactive=0;
	unsigned int	xronos_kleisimatos=0;
//	time_t			t;
	TTameio			*tameio;		  /* oi tamies */
	int	tamies;
	int				i, temp;
	int				closing_time;			/* xronos pou pragmatika stamataei i eksipiretisi pelatwn */
	unsigned int	extra_time = 0;		  /* epipleon lepta pou itan aparaitita gia tin eksipiretisi twn pelatwn */


	printf("Dwste units of time prosomoiwshs (0 <=), pi8anothta afikshs in unit of time (0,1) kai xrono e3yphrethshs (>=1) in unit of times )\n");
	scanf("%u %f %u",&xronos_prosomoiosis,&pithanotita_afiksis,&xronos_eksipiretisis);
	printf("Dwste xrono kleisimatos (> 0): ");
	scanf("%u", &xronos_kleisimatos);
	getchar();
	printf("H prosomoiwsh 8a diarkesei %4u units of time.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena unit of time einai: %4.2f.\n",pithanotita_afiksis);
	printf("H diarkeia e3yphrethshs enos pelath einai sta9erh %d units of time .\n",xronos_eksipiretisis);
	printf("O xronos kleisimatos einai se %d lepta.\n", xronos_kleisimatos);

	printf("Dwste plithos tameiwn: ");
	scanf("%u", &tamies);
	tameio = malloc(sizeof(TTameio) * tamies);

	OuraDimiourgia(&oura);
	xronos = 0;
	enapomenon_xronos = 0;
	arithmos_pelaton = 0;
	xronos_anamonis = 0;
	closing_time = -1;
//	srand((unsigned)time(&t));

	for (i = 0; i < tamies; i++)		//new addition, gia kathe tamia
		TameioDimiourgia(&tameio[i]);	//new addition, arxikopoiisi tou tamia

	while( xronos < xronos_prosomoiosis )
	{	/* Pelatis- Aytokinhto  */
		if (xronos < xronos_kleisimatos)
		{
			randomAfixi = (float)rand()/(float)RAND_MAX; 

			if ( randomAfixi < pithanotita_afiksis ){
				PelatisSetXronoEisodou(&Pelatis, xronos);
				temp = rand() % xronos_eksipiretisis;
				PelatisSetXronoEksipiretisis(&Pelatis, temp); /* new */
				temp = PelatisGetXronoEksipiretisis(&Pelatis);
				printf("%d: Eftase pelatis me xrono eksipiretisis: %d\n", xronos, temp);
				if (!OuraProsthesi(&oura, Pelatis)){
					  printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
					  getchar();
					  return 0;
        		};
    		};
		}
		else if (xronos == xronos_kleisimatos)
			printf("Kleisti trapeza, apagoreuetai i eisodos.\n");

    	/* Tameio-Elegxos */
    	for (i = 0; i < tamies; ++i)
			if (TameioFree(tameio[i]) == 1)	/*eley8eros tamias*/
			{
				if (!OuraKeni(oura))			/*yparxei pelaths*/
				{
					if (OuraApomakrynsh(&oura, &Pelatis) == 0)		/*phgainei sto tamio*/
					{
						printf("Adeia oura, mikrh! H prosomoivsh stamataei \n");
						exit(0);
					}
					xronos_anamonis += xronos - PelatisGetXronoEisodou(Pelatis);	/*ypologismos xronoy paramonhs sthn oura*/
					TameioNewCustomer(&tameio[i], Pelatis.XronosEksipiretisis); // νέος πελάτης στον ταμεία
					/* printf("Time is %d Time out %d\n", xronos, PelatisGetXronoEisodou(Pelatis)); */
					arithmos_pelaton++;
					enapomenon_xronos = xronos_eksipiretisis - 1; /* kallyptei to trexon unit time */
				}
				else
				{
					if (BONUS_ENABLE != 0)
					{
						if (!OuraGetSize(oura)) //an i oura einai adeia
							printf("O tamias %d kleinei giati den uparxoun pelates na eksupiretisei.\n", i); //o tameias kleinei
					}
					else
						TameioNoWork(&tameio[i]);  /* o tameias einai adranis */
				}
			}
			else 
			{
				TameioInService(&tameio[i]); // μειώνει χρόνο εξυπηρέτησης κατά 1
				TameioBusy(&tameio[i]); //o tameias einai apasxolimenos me pelati
			}
				
		/* an den exei oristei, kai exei kleisi i trapeza kai teleiwsan oi pelates */
		if (closing_time == -1 && xronos >= xronos_kleisimatos && OuraGetSize(oura) == 0)
			closing_time = xronos; /* kratame ton pragmatiko xrono kleisimatos */

		/* an i trapeza ekleise kai exei akoma pelates */
		if (xronos >= xronos_kleisimatos && OuraGetSize(oura))
			extra_time += 1; /* auksanontai ta lepta pou itan aparaitita */
		
		xronos += 1; /*o xronos prosomoivshs ay3anetai kata 1 unit of time*/
	} /*while( xronos < xronos_prosomoiosis )*/

	mesos_xronos = 0.0;
	for (i = 0; i < tamies; i++)
		if (TameioGetArithmosPelatwn(&tameio[i]))
			mesos_xronos += ((float)xronos_anamonis) / ((float)TameioGetArithmosPelatwn(&tameio[i]));

	if (closing_time == -1)
		closing_time = 0;

	printf("\n");
	printf("O mesos xronos anamonhs htan %4.2f lepta.\n", mesos_xronos);

	for (i = 0; i < tamies; i++)
	{
		printf("-----------\n");
		printf("O tamias %d htan adranis gia %d lepta\n", i, TameioGetInactiveXronos(&tameio[i]));
		printf("O tamias %d htan apasxolimenos gia %d lepta\n", i, TameioGetBusyXronos(&tameio[i]));
		printf("O tamias %d eksupiretise %d pelates\n", i, TameioGetArithmosPelatwn(&tameio[i]));
		printf("-----------\n");
	}

	printf("O pragmatikos telikos xronos leitourgias htan %d lepta.\n", closing_time);
	printf("Den eksupiretithikan %d pelates.\n", OuraGetSize(oura));
	printf("Ta epipleon lepta pou itan aparaitita htan %d.\n", extra_time);
	free(tameio);
	return 0;
}

