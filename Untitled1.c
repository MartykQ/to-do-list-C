#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define n 120 //max liczba zadan
#define m 100 //liczba znakow tresci zadan


struct zadania {
int rok;
int miesiac;
int dzien;
int priorytet;
char tresc[100];
}zadanie[n],schow_z;

struct wykonane_zadania{
int w_rok;
int w_miesiac;
int w_dzien;
int w_priorytet;
char w_tresc[100];
}wykonane[n],schow_w;

int main()
{
    //otwieranie pliku
    FILE *plik;
    if((plik=fopen("zadania.txt", "r"))==NULL)
    {
        printf("\n Nie udalo sie otworzc pliku \n");
        exit(1);
    }


    printf("\notwarto pomyslnie!");


    //Sprawdzanie ile jest zadan, odczytywanie liczby wierszy w pliu

    char linia;
    int dlugosc=0;

    while((linia=fgetc(plik))!=EOF)
    {
        if(linia=='\n')
            dlugosc++;
    }
    fclose(plik);
    printf("dlugosc to %d", dlugosc);
    getchar();



    //kopiowanie tresci pliku do tablic pomocniczych

        int tab_prior[n];
        int tab_year[n];
        int tab_month[n];
        int tab_day[n];
        char tab_text[n][m];
        int i=0;
        int j=0;


        FILE *plik2=fopen("zadania.txt", "r");
        while(feof(plik2)==0&&(i<dlugosc))
        {
        fscanf(plik2, "%d", &tab_year[i]);
        fscanf(plik2, "%d", &tab_month[i]);
        fscanf(plik2, "%d", &tab_day[i]);
        fscanf(plik2, "%d", &tab_prior[i]);
        fseek(plik2, 1, 1); //przesuniecie sie w pliku o 1 pozycje (ze wgzlefu na fgets)
        fgets(tab_text[i],m,plik2);
        //fscanf(plik2, "%s", &tab_text[i]);

        i=i+1;

        }

        fclose(plik2);
        i=0;
        //printf("\nTekst1: %s", tab_text[1]);
        //getchar();


//kopiowanie z tablicy pomocniczej do struktury
    while(i<dlugosc)
    {
        zadanie[i].priorytet=tab_prior[i];
        zadanie[i].rok=tab_year[i];
        zadanie[i].miesiac=tab_month[i];
        zadanie[i].dzien=tab_day[i];
        strcpy(zadanie[i].tresc, tab_text[i]);
        i++;
    }

    //printf("\nTekst: %s", zadanie[i].tresc);
    //getchar();

        /*-----------------
          ----PLIK 2-------
          -----------------*/

        FILE *pliczek;
        if((pliczek=fopen("wykonane.txt", "r"))==NULL)
        {
            printf("\n Nie udalo sie otworzc pliku \n");
            exit(1);
        }

        int w_dlugosc=0;

        while((linia=fgetc(pliczek))!=EOF)
        {
            if(linia=='\n')
                w_dlugosc++;
        }
        fclose(pliczek);
        printf("\ndlugosc wykonanych to %d", w_dlugosc);
        getchar();

        FILE *pliczek2=fopen("wykonane.txt", "r");
        i=0;
        while((feof(pliczek2)==0)&&(i<w_dlugosc))
        {
            fscanf(pliczek2, "%d", &tab_year[i]);
            fscanf(pliczek2, "%d", &tab_month[i]);
            fscanf(pliczek2, "%d", &tab_day[i]);
            fscanf(pliczek2, "%d", &tab_prior[i]);
            fseek(pliczek2,1,1);
            fgets(tab_text[i],m,pliczek2);
            i++;
        }
        fclose(pliczek2);
        i=0;
        while(i<w_dlugosc)
        {
            wykonane[i].w_rok=tab_year[i];
            wykonane[i].w_miesiac=tab_month[i];
            wykonane[i].w_dzien=tab_day[i];
            wykonane[i].w_priorytet=tab_prior[i];
            strcpy(wykonane[i].w_tresc, tab_text[i]);
            i++;
        }




        /*------------------------------
          ------------------------------
          -----------FUNKCJE------------
          ------------------------------
          ------------------------------*/

			void podaj_date_zadanie()
				{
					printf("Podaj date wykonania: ");
	                           printf("\nROK: ");
	                           scanf("%d", &zadanie[i].rok);
	                           blad_miesiac:
	                           printf("\nMIESIAC: ");
	                           scanf("%d", &zadanie[i].miesiac);

	                           if(zadanie[i].miesiac==1 || zadanie[i].miesiac==3 || zadanie[i].miesiac==5 || zadanie[i].miesiac==7 || zadanie[i].miesiac==8 || zadanie[i].miesiac==10 || zadanie[i].miesiac==12)
	                           {
		                           	printf("\nDZIEN: ");
		                           	blad_dzien1:
		                           	scanf("%d", &zadanie[i].dzien);
		                           	if(zadanie[i].dzien>31)
		                           	{
		                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
		                           		goto blad_dzien1;
									}

							   }

								else if(zadanie[i].miesiac==4 || zadanie[i].miesiac==6 || zadanie[i].miesiac==9 || zadanie[i].miesiac==11)
	                           {
		                           	printf("\nDZIEN: ");
		                           	blad_dzien2:
		                           	scanf("%d", &zadanie[i].dzien);
		                           	if(zadanie[i].dzien>30)
		                        	{

		                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
		                           		goto blad_dzien2;
									}
							   }

							   else if(zadanie[i].miesiac==2)
	                           {
		                           	printf("\nDZIEN: ");
		                           	blad_dzien3:
		                           	scanf("%d", &zadanie[i].dzien);
		                            if(zadanie[i].rok%4==0 && zadanie[i].rok%100!=0)
		                            {
			                           	if(zadanie[i].dzien>29)
			                           	{
			                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
			                           		goto blad_dzien3;
										}
									}
									else
									{
			                           	if(zadanie[i].dzien>28)
			                           	{
			                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
			                           		goto blad_dzien3;
										}
									}
							   }
							   else
							   {
							   	printf("Nie ma takiego miesiaca. Podaj go ponownie.");
							   	goto blad_miesiac;
							   }

				}


			void podaj_date_wykonane()
			{
				printf("Podaj date wykonania: ");
	                           printf("\nROK: ");
	                           scanf("%d", &wykonane[i].w_rok);
	                           blad_miesiac:
	                           printf("\nMIESIAC: ");
	                           scanf("%d", &wykonane[i].w_miesiac);

	                           if(wykonane[i].w_miesiac==1 || wykonane[i].w_miesiac==3 || wykonane[i].w_miesiac==5 || wykonane[i].w_miesiac==7 || wykonane[i].w_miesiac==8 || wykonane[i].w_miesiac==10 || wykonane[i].w_miesiac==12)
	                           {
		                           	printf("\nDZIEN: ");
		                           	blad_dzien1:
		                           	scanf("%d", &wykonane[i].w_dzien);
		                           	if(wykonane[i].w_dzien>31)
		                           	{
		                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
		                           		goto blad_dzien1;
									}

							   }

								else if(wykonane[i].w_miesiac==4 || wykonane[i].w_miesiac==6 || wykonane[i].w_miesiac==9 || wykonane[i].w_miesiac==11)
	                           {
		                           	printf("\nDZIEN: ");
		                           	blad_dzien2:
		                           	scanf("%d", &wykonane[i].w_dzien);
		                           	if(wykonane[i].w_dzien>30)
		                        	{

		                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
		                           		goto blad_dzien2;
									}
							   }

							   else if(wykonane[i].w_miesiac==2)
	                           {
		                           	printf("\nDZIEN: ");
		                           	blad_dzien3:
		                           	scanf("%d", &wykonane[i].w_dzien);
		                            if(wykonane[i].w_rok%4==0 && wykonane[i].w_rok%100!=0)
		                            {
			                           	if(zadanie[i].dzien>29)
			                           	{
			                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
			                           		goto blad_dzien3;
										}
									}
									else
									{
			                           	if(wykonane[i].w_dzien>28)
			                           	{
			                           		printf("Miesiac ma mniej dni. Podaj ponownie dzien.");
			                           		goto blad_dzien3;
										}
									}
							   }
							   else
							   {
							   	printf("Nie ma takiego miesiaca. Podaj go ponownie.");
							   	goto blad_miesiac;
							   }
			}


            void wypisz_niezrobione()
            {
                system("cls");
                int i=0;
                printf("ZADANIA: \n");
                for(i=0;i<dlugosc;i++)
                {
                        printf("*****************");
                        printf("\nZadanie nr: %d\n", i+1);
                        printf("TRESC: %s", zadanie[i].tresc);
                        printf("PRIORYTET: %d\n", zadanie[i].priorytet);
                        printf("DEADLINE: %02d-%02d-%d\n", zadanie[i].dzien, zadanie[i].miesiac, zadanie[i].rok);
                        printf("*****************\n\n");

                }

            }

            void wypisz_zrobione()
                {
                    system("cls");
                    printf("*****************\n");
                    printf("*****ZADANIA*****\n");
                    printf("*****************\n\n\n");

                    for(i=0;i<w_dlugosc;i++)
                    {
                        printf("*****************");
                        printf("\nZadanie nr: %d\n", i+1);
                        printf("TRESC: %s", wykonane[i].w_tresc);
                        printf("PRIORYTET: %d\n", wykonane[i].w_priorytet);
                        printf("DEADLINE: %02d-%02d-%d\n", wykonane[i].w_dzien, wykonane[i].w_miesiac, wykonane[i].w_rok);
                        printf("*****************\n\n");
                    }

                }



            void dodaj_zadanie()
            {
                int i,j;
                system("cls");
                char pom='t';
                printf("Siemandero podaj zadnanie XD \nxd\n");
                while(pom=='t'||pom=='T')

                       {
                           fflush(stdin);
                           i=dlugosc;
                           dlugosc++;
                           printf("\n*********\n");
                           printf("\nPodaj tresc zadania: ");
                           gets(zadanie[i].tresc);
                           strcat(zadanie[i].tresc,"\n");
                           printf("\nPodaj priorytet zadania:  ");
                           scanf("%d", &zadanie[i].priorytet);

                           podaj_date_zadanie();

                           printf("\n\nDODANO!\n\nChcesz podawac dalej?(T/N)");
                           scanf("%s", &pom);


                       }

            }

            void dodaj_wykonane()
                {
                    system("cls");
                    char pom='t';
                    printf("Dodaj wykonane zadanie\n");

                    while(pom=='t'||pom=='T')
                    {
                        fflush(stdin);
                        i=w_dlugosc;
                        w_dlugosc++;
                        printf("Podaj tresc zadania: ");
                        gets(wykonane[i].w_tresc);
                        strcat(wykonane[i].w_tresc,"\n");
                        printf("\nPodaj priorytet zadania: ");
                        scanf("%d", &wykonane[i].w_priorytet);
                        printf("\nPodaj DEADLINE");
                        printf("\nDZIEN: ");
                        scanf("%d", &wykonane[i].w_dzien);
                        printf("\nMIESIAC: ");
                        scanf("%d", &wykonane[i].w_miesiac);
                        printf("\nROK: ");
                        scanf("%d", &wykonane[i].w_rok);
                        printf("\n\nDODANO! Chcesz podawac dalej(T/N)?");
                        scanf("%s", &pom);
                    }

                }

            void usun_zadanie()
                {
                    usunac:
                    system("cls");
                    wypisz_niezrobione();
                    printf("\n\nKtory element chcesz usunac?");
                    int help;
                    scanf("%d", &help);
                    help=help-1;
                    if((help<dlugosc)&&(help>=0))
                    {
                        dlugosc=dlugosc-1;
                        for(i=help;i<dlugosc;i++)
                        {
                            schow_z=zadanie[i+1];
                            zadanie[i]=schow_z;
                        }
                    printf("\n Zadanie zostalo usuniete :) \n");
                    system("pause");

                    }
                    else  {
                            printf("\nPodales zly numer\nJeszcze Raz\n");
                            system("pause");
                            usun_zadanie();
                              }

                    }

            void usun_wykonane()
                {
                    usunac:
                    system("cls");
                    wypisz_zrobione();
                    printf("\n\nKtory element chcesz usunac?");
                    int help;
                    scanf("%d", &help);
                    help=help-1;
                    if((help<w_dlugosc)&&(help>=0))
                    {
                        w_dlugosc=w_dlugosc-1;
                        for(i=help;i<w_dlugosc;i++)
                        {
                            schow_w=wykonane[i+1];
                            wykonane[i]=schow_w;
                        }
                    printf("\n Zadanie zostalo usuniete :) \n");
                    system("pause");

                    }
                    else  {
                            printf("\nPodales zly numer\nJeszcze Raz\n");
                            system("pause");
                            usun_wykonane();
                              }

                    }





                void sortuj_priorytety()
            	{
            		int zamiana;
                    do
                    {
						zamiana=0;
	                    for(i=0;i<dlugosc;i++)
	                    {
	                    	if(zadanie[i].priorytet<zadanie[i+1].priorytet)
	                    	{
	                    		zamiana++;
	                    		schow_z=zadanie[i];
	                    		zadanie[i]=zadanie[i+1];
	                    		zadanie[i+1]=schow_z;
							}

							else if(zadanie[i].priorytet==zadanie[i+1].priorytet)
							{
								if(zadanie[i].rok>zadanie[i+1].rok)
								{
									zamiana++;
		                    		schow_z=zadanie[i];
		                    		zadanie[i]=zadanie[i+1];
		                    		zadanie[i+1]=schow_z;
								}

								else if(zadanie[i].rok==zadanie[i+1].rok)
								{
									if(zadanie[i].miesiac>zadanie[i+1].miesiac)
									{
										zamiana++;
			                    		schow_z=zadanie[i];
			                    		zadanie[i]=zadanie[i+1];
			                    		zadanie[i+1]=schow_z;
									}

									else if(zadanie[i].miesiac==zadanie[i+1].miesiac)
									{
										if(zadanie[i].dzien>zadanie[i+1].dzien)
										{
										zamiana++;
			                    		schow_z=zadanie[i];
			                    		zadanie[i]=zadanie[i+1];
			                    		zadanie[i+1]=schow_z;
										}
									}
								}

							}
						}
					}
					while(zamiana!=0);
				}


            void sortuj_data()
                    {

              		int zamiana;
                    do
                    {
						zamiana=0;
	                    for(i=0;i<dlugosc-1;i++)
	                    {

								if(zadanie[i].rok>zadanie[i+1].rok)
								{
									zamiana++;
		                    		schow_z=zadanie[i];
		                    		zadanie[i]=zadanie[i+1];
		                    		zadanie[i+1]=schow_z;
								}

								else if(zadanie[i].rok==zadanie[i+1].rok)
								{
									if(zadanie[i].miesiac>zadanie[i+1].miesiac)
									{
										zamiana++;
			                    		schow_z=zadanie[i];
			                    		zadanie[i]=zadanie[i+1];
			                    		zadanie[i+1]=schow_z;
									}

									else if(zadanie[i].miesiac==zadanie[i+1].miesiac)
									{
										if(zadanie[i].dzien>zadanie[i+1].dzien)
										{
										zamiana++;
			                    		schow_z=zadanie[i];
			                    		zadanie[i]=zadanie[i+1];
			                    		zadanie[i+1]=schow_z;
										}
										else if(zadanie[i].dzien==zadanie[i+1].dzien)
										{
											if(zadanie[i].priorytet<zadanie[i+1].priorytet)
						                    	{
						                    		zamiana++;
						                    		schow_z=zadanie[i];
						                    		zadanie[i]=zadanie[i+1];
						                    		zadanie[i+1]=schow_z;
												}
										}
									}
								}


						}
					}
					while(zamiana!=0);



                }

            void sortuj_data_wykonane()
                    {

              		int zamiana;
                    do
                    {
						zamiana=0;
	                    for(i=0;i<w_dlugosc-1;i++)
	                    {

								if(wykonane[i].w_rok>wykonane[i+1].w_rok)
								{
									zamiana++;
		                    		schow_w=wykonane[i];
		                    		wykonane[i]=wykonane[i+1];
		                    		wykonane[i+1]=schow_w;
								}

								else if(wykonane[i].w_rok==wykonane[i+1].w_rok)
								{
									if(wykonane[i].w_miesiac>wykonane[i+1].w_miesiac)
									{
                                        zamiana++;
                                        schow_w=wykonane[i];
                                        wykonane[i]=wykonane[i+1];
                                        wykonane[i+1]=schow_w;
									}

									else if(wykonane[i].w_miesiac==wykonane[i+1].w_miesiac)
									{
										if(wykonane[i].w_dzien>wykonane[i+1].w_dzien)
										{
                                            zamiana++;
                                            schow_w=wykonane[i];
                                            wykonane[i]=wykonane[i+1];
                                            wykonane[i+1]=schow_w;
										}
										else if(wykonane[i].w_dzien==wykonane[i+1].w_dzien)
										{
											if(wykonane[i].w_priorytet<wykonane[i+1].w_priorytet)
						                    	{
						                    		zamiana++;
						                    		schow_w=wykonane[i];
						                    		wykonane[i]=wykonane[i+1];
						                    		wykonane[i+1]=schow_w;
												}
										}
									}
								}


						}
					}
					while(zamiana!=0);

                	}


                void sortuj_priorytet_wykonane()
                    {

              		int zamiana;
                    do
                    {
						zamiana=0;
	                    for(i=0;i<w_dlugosc-1;i++)
	                    {
								if(wykonane[i].w_priorytet<wykonane[i+1].w_priorytet)
						           	{
						          		zamiana++;
						               	schow_w=wykonane[i];
						               	wykonane[i]=wykonane[i+1];
						             	wykonane[i+1]=schow_w;
									}

									else if(wykonane[i].w_priorytet==wykonane[i+1].w_priorytet)
										{

											if(wykonane[i].w_rok>wykonane[i+1].w_rok)
											{
												zamiana++;
					                    		schow_w=wykonane[i];
					                    		wykonane[i]=wykonane[i+1];
					                    		wykonane[i+1]=schow_w;
											}

											else if(wykonane[i].w_rok==wykonane[i+1].w_rok)
											{
												if(wykonane[i].w_miesiac>wykonane[i+1].w_miesiac)
												{
			                                        zamiana++;
			                                        schow_w=wykonane[i];
			                                        wykonane[i]=wykonane[i+1];
			                                        wykonane[i+1]=schow_w;
												}

												else if(wykonane[i].w_miesiac==wykonane[i+1].w_miesiac)
												{
													if(wykonane[i].w_dzien>wykonane[i+1].w_dzien)
													{
			                                            zamiana++;
			                                            schow_w=wykonane[i];
			                                            wykonane[i]=wykonane[i+1];
			                                            wykonane[i+1]=schow_w;
													}

												}
											}
										}

						}
					}

					while(zamiana!=0);

                	}


                void zapisz()
                    {
                        //FILE *plik3=fopen("zadania.txt", "w");
                        FILE *plik4=fopen("zadania.txt", "w");
                        for(i=0;i<dlugosc;i++)
                        {


                            fprintf(plik4,"%d ",zadanie[i].rok);
                            fprintf(plik4,"%d ",zadanie[i].miesiac);
                            fprintf(plik4,"%d ",zadanie[i].dzien);
                            fprintf(plik4,"%d ",zadanie[i].priorytet);
                            fprintf(plik4,"%s",zadanie[i].tresc);


                        }

                        fclose(plik4);
                    }

                void zapisz_wykonane()
                    {

                        FILE *pliczek3=fopen("wykonane.txt", "w");
                        for(i=0;i<w_dlugosc;i++)
                        {


                            fprintf(pliczek3,"%d ",wykonane[i].w_rok);
                            fprintf(pliczek3,"%d ",wykonane[i].w_miesiac);
                            fprintf(pliczek3,"%d ",wykonane[i].w_dzien);
                            fprintf(pliczek3,"%d ",wykonane[i].w_priorytet);
                            fprintf(pliczek3,"%s",wykonane[i].w_tresc);


                        }

                        fclose(pliczek3);
                    }


void edytuj_zadanie()
                        {
                            int i=0;
                            int help;
                            char pom;
                            system("cls");
                            wypisz_niezrobione();

                            printf("\n\n**********************\nKtore zadanie chcesz edytowac? ");
                            scanf("%d", &help);
                            i=help-1;
                            printf("\ni=%d\n", i);

                            if((i>dlugosc)||(i<0))
                                {
                                    printf("\nNie ma takiego numeru!");
                                    printf("\ni=%d\n", i);
                                    system("pause");
                                    edytuj_zadanie();
                                }
                            printf("\nCzy chcesz edytowac tresc?(T/N)");
                            printf("\ni=%d\n", i);
                            scanf("%s", &pom);
                            printf("\ni=%d\n", i);

                            if(tolower(pom)=='t')
                                {
                                    //TUTAJ i sie zeruje??!??! CZEMU
                                    printf("\ni=%d\n", i);
                                    fflush(stdin);
                                    printf("\nPodaj tresc zadania: ");
                                    gets(zadanie[i].tresc);
                                    strcat(zadanie[i].tresc,"\n");
                                    printf("\ni=%d\n", i);
                                }
                            printf("Czy chcesz zmienic priorytet?(T/N)");
                            scanf("%s", &pom);
                            if(tolower(pom)=='t')
                            {
                                printf("\ni=%d\n", i);
                                printf("\nPodaj nowy priorytet: ");
                                scanf("%d", &zadanie[i].priorytet);
                            }
                            printf("\nCzy chcesz zmienic date zadania?(T/N)");
                            scanf("%s", &pom);
                            if(tolower(pom)=='t')
                            {
                                podaj_date_zadanie();
                            }


                            printf("\n*************\nEdytowano pomyslnie!");
                            system("pause");

                        }

                    void edytuj_wykonane()
                        {
                            int i;
                            int help;
                            char pom;
                            system("cls");
                            wypisz_zrobione();

                            printf("\n\n**********************\nKtore zadanie chcesz edytowac? ");
                            scanf("%d", &help);
                            i=help-1;

                            if((i>w_dlugosc)||(i<0))
                                {
                                    printf("\nNie ma takiego numeru!");
                                    system("pause");
                                    edytuj_wykonane();
                                }
                            printf("\nCzy chcesz edytowac tresc?(T/N)");
                            scanf("%s", &pom);
                            if(tolower(pom)=='t')
                                {
                                    fflush(stdin);
                                    printf("\nPodaj tresc zadania: ");
                                    gets(wykonane[i].w_tresc);
                                    strcat(wykonane[i].w_tresc,"\n");
                                }
                            printf("Czy chcesz zmienic priorytet?(T/N)");
                            scanf("%s", &pom);
                            if(tolower(pom)=='t')
                            {
                                printf("\nPodaj nowy priorytet: ");
                                scanf("%d", &wykonane[i].w_priorytet);
                            }
                            printf("\nCzy chcesz zmienic date zadania?(T/N)");
                            scanf("%s", &pom);
                            if(tolower(pom)=='t')
                            {
                                podaj_date_wykonane();
                            }


                            printf("\n*************\nEdytowano pomyslnie!");
                            system("pause");

                        }

                void zmien_status_zadania()
	                {
	                    system("cls");
	                    int pom;
	                    int help;
	                    wypisz_niezrobione();
	                    printf("\n\n\nKtore zadanie oznaczyc jako wykonane?: ");
	                    scanf("%d", &i);
	                    i=i-1;

	                    if((i>dlugosc)||i<0)
	                    {
	                        printf("\n\nZLY NUMER!! JESZCZE RAZ");
	                        zmien_status_zadania();
	                    }

	                    //przekopiowanie zadania do wykonanych
	                    pom=w_dlugosc;
	                    w_dlugosc=w_dlugosc+1;
	                    strcpy(wykonane[pom].w_tresc, zadanie[i].tresc);
	                    wykonane[pom].w_priorytet=zadanie[i].priorytet;
	                    wykonane[pom].w_rok=zadanie[i].rok;
	                    wykonane[pom].w_miesiac=zadanie[i].miesiac;
	                    wykonane[pom].w_dzien=zadanie[i].dzien;

	                    //usuniecie zadania

	                    dlugosc=dlugosc-1;

	                    for(help=i;help<dlugosc;help++)
	                    {
		                    schow_z=zadanie[help+1];
		                    zadanie[help]=schow_z;
	                    }

	                    printf("\n\nUDALO SIE!");
                        system("pause");


	                }

            void zmien_status_wykonanego()
                {
                    system("cls");
                    wypisz_zrobione();
                    printf("\n\nKtor zadanie chcesz oznaczyc jako niewykonane?: ");
                    scanf("%d", &i);
                    i=i-1;
                    int pom;
                    if(i>w_dlugosc||i<0)
                    {
                        printf("\n\nPodales zly indeks! JESZCZE RAZ!");
                        zmien_status_wykonanego();
                    }
                    pom=dlugosc;
                    dlugosc++;

                    strcpy(zadanie[pom].tresc, wykonane[i].w_tresc);
                    zadanie[pom].priorytet=wykonane[i].w_priorytet;
                    zadanie[pom].rok=wykonane[i].w_rok;
                    zadanie[pom].miesiac=wykonane[i].w_miesiac;
                    zadanie[pom].dzien=wykonane[i].w_dzien;

                    w_dlugosc=w_dlugosc-1;

                    for(pom=i;pom<dlugosc;pom++)
                    {
                        schow_w=wykonane[pom+1];
                        wykonane[pom]=schow_w;
                    }
                    printf("\n\nUDALO SIE!\n\n");
                    system("pause");



                }



        /*--------------------------
          --------------------------
          ----------MENU------------
          --------------------------
          -------------------------- */

int x,y;


while(1)
{
    system("cls");
    printf("********************");
    printf("\n********************");
    printf("\n********MENU********");
    printf("\n********************");
    printf("\n********************\n\n");
    printf("1.ZADANIA DO ZROBIENIA\n");
    printf("2.ARCHIWUM");
    printf("\n3.ZAPISZ");
    printf("\n4.WYJDZ Z PROGRAMU");
    printf("\n\nWYBIERZ: ");
    scanf("%d", &x);
    printf("\n");


            if(x==1)
            {
                ZADANIA:
                printf("ZADANIA DO ZROBIENIA\n\n");
                wypisz_niezrobione();
                printf("\n1. SORTUJ PO DACIE");
                printf("\n2. SORTUJ PO PRIORYTECIE");
                printf("\n3. DODAJ NOWE ZADANIE");
                printf("\n4. USUN ZADANIE");
                printf("\n5. EDYTUJ ZADANIE");
                printf("\n6. ZMIEN NA WYKONANE");
                printf("\n7. POWROT");
                printf("\n\nWYBIERZ: ");
                scanf("%d", &y);



                            if(y==1)
                            {
                                sortuj_data();
                                printf("UDALO SIE!\n");
                                system("pause");
                                goto ZADANIA;
                            }
                            if(y==2) {
                                    sortuj_priorytety();
                                    printf("\nUDALO SIE! \n");
                                    system("pause");
                                    goto ZADANIA;
                            }

                            if (y==3)   {
                                    dodaj_zadanie();
                                    goto ZADANIA;
                            }

                            if(y==4)
                            {
                                usun_zadanie();
                                goto ZADANIA;
                            }

                            if(y==5)
                            {
                                edytuj_zadanie(); //nie edytuje daty!!!!!!
                                goto ZADANIA;
                            }

                            if(y==6)
                            {

                                zmien_status_zadania();
                                goto ZADANIA;
                            }

                            if(y==7)
                            {
                               continue;
                            }

            }



            if(x==2)
            {
                ARCHIWUM:
                wypisz_zrobione();
                printf("\n1. SORTUJ PO DACIE");
                printf("\n2. SORTUJ PO PRIORYTECIE");
                printf("\n3. DODAJ ZADANIE DO ARCHIWUM");
                printf("\n4. USUN ZADANIE");
                printf("\n5. EDYTUJ ZADANIE");
                printf("\n6. ZMIEN STATUS NA DO ZROBIENIA");
                printf("\n7. POWROT");
                printf("\n\nWYBIERZ: ");
                scanf("%d", &y);

                            if(y==1)
                            {
                                sortuj_data_wykonane();
                                printf("\nUDALO SIE! \n");
                                system("pause");
                                goto ARCHIWUM;

                            }
                            if (y==2)
                            {
                                sortuj_priorytet_wykonane();
                                printf("\nUDALO SIE!\n");
                                system("pause");
                                goto ARCHIWUM;
                            }

                            if(y==3)
                            {
                                dodaj_wykonane(); //dodaj_wykonane nie ma sprawdzania daty
                                printf("\nUDALO SIE!\n");
                                system("pause");
                                goto ARCHIWUM;
                            }

                            if(y==4)
                            {
                                usun_wykonane();;
                                goto ARCHIWUM;
                            }

                            if(y==5)
                            {
                                edytuj_wykonane(); //nie edytuje daty
                                goto ARCHIWUM;
                            }

                            if(y==6)
                            {
                                zmien_status_wykonanego();
                                goto ARCHIWUM;
                            }

                            if(y==7) continue;
                        }


        if(x==3) {
                zapisz();
                zapisz_wykonane();
                continue;
                }

        if(x==4) exit(0);

    return 0;

}
}





