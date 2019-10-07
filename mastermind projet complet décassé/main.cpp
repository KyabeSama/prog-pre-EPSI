#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;
//Les variables du 1er mode de jeu
int i = 0;
int nombreAleatoire;
int aleaA, aleaB,aleaC, aleaD;
int nombreJoueurA, nombreJoueurB,nombreJoueurC, nombreJoueurD;
int malPlaceA, malPlaceB,malPlaceC, malPlaceD;
int tamponA, tamponB, tamponC, tamponD;
int a=1, b=7;
int nombreMalPlaces, nombreJuste;

        /*
        Les 4 prochaines fonctions permettent à la machine de comparer les valeurs données par l'utilisateur à celles qu'il a généré
        pour detecter si elles existent dans sa combinaison ou pas et en informer l'utilisateur
        */
int detection(int Joueur)
{
    int nbm=0;

    if (Joueur==aleaB)
    {
        nbm++;
    }
    else if (Joueur==aleaC)
    {
        nbm++;
    }
    else if (Joueur==aleaD)
    {
        nbm++;
    }

    return nbm;
}


//Les variables du 2eme mode de jeu
int j = 0;
int DB[1297];
int remplisseurDB = 0, genA =0, genB=0, genC=0, genD=0;
int chercheurDB=0, mesureurDB=0, compteurMesureurDB;
int maitreA=0, maitreB=0, maitreC=0, maitreD=0;
int finJeuIA=0, tentativesIA=1, choixMachine=0;
int iaA=0,iaB=0, iaC=0, iaD=0;
int BPia=0, MPia=0;
int iaAtampon=0, iaBtampon=0, iaCtampon=0, iaDtampon=0;
int dbA, dbB, dbC, dbD, dbBP, dbMP;
int dbAtampon=0, dbBtampon=0, dbCtampon=0, dbDtampon=0;
int trieurDB=1, victoireIA=0;
int enter=0, garde=0, mesureurTri=0;
int combiA, combiB, combiC, combiD, tampA, tampB, tampC, tampD;
int TriT, TriJ, TriP;
int plomb=0;
int TcombiA, TcombiB, TcombiC,TcombiD;

int comparMachineCombinaison(int Machine)
{
    int nombresBienPlaces=0;

    if (Machine==TcombiB)
    {
        nombresBienPlaces++;
        TcombiB=0;
    }
    else if (Machine==TcombiC)
    {
        nombresBienPlaces++;
TcombiC=0;
    }
    else if (Machine==TcombiD)
    {
        nombresBienPlaces++;
TcombiD=0;
    }

    return nombresBienPlaces;
}


//Les variables du dernier mode de jeu
int nbrA, nbrB, nbrC, nbrD;
int Temps, Blocker=2;
int BienP=7, MalP=7;
int essaiA, essaiB, essaiC, essaiD;
int nbmA, nbmB, nbmC, nbmD;
int gagne=0;


int main()
{
    int a;
    cout<<" A quel mode de jeu voulez vous jouer ?"<< endl;
    cout<<" 1: Le Mode Entrainement"<< endl;
    cout<<" 2: Le Mode Algorithme" <<endl;
    cout<<" 3: Le Mode Joueur vs Joueur"<<endl;
    cout<<" Autre: Quitter le jeu"<<endl;
    cin >>a;
    cout << string( 50, '\n' );
    if(a==1)
    {
        srand(time(NULL));
        for(i=0; i<4; i++)
        {

            nombreAleatoire = rand()%(b-a)+a;
            // Je genère un nombre entier aléatoire qui rentre dans [a;b[ 4 fois
            if(i==0)
            {
                aleaA = nombreAleatoire;
                tamponA = aleaA;
            }
            else if(i==1)
            {
                aleaB = nombreAleatoire;
                tamponB=aleaB;
            }
            else if(i==2)
            {
                aleaC = nombreAleatoire;
                tamponC=aleaC;
            }
            else if(i==3)
            {
                aleaD = nombreAleatoire;
                tamponD=aleaD;
            }
            /* puis je les stock dans 4 variables différentes pour créer ma séquence à déchiffrer*/
        }
        cout << aleaA << " " << aleaB << " " << aleaC << " " << aleaD << endl; //je garde cette ligne pour me faciliter les tests du programme
        cout << " " << endl;


        for(j=0; j<12; j++)
        {

            cout << "Quelle est la combinaison ?" << endl;
            cin >> nombreJoueurA >> nombreJoueurB >> nombreJoueurC >> nombreJoueurD;
            cout << " " << endl;

            cout << "Combinaison du joueur " << nombreJoueurA << ", " << nombreJoueurB << ", " << nombreJoueurC << ", " << nombreJoueurD<< endl;
            if(nombreJoueurA == aleaA)
            {
                nombreJuste++;
                tamponA = aleaA;

                aleaA = nombreJoueurA - aleaA;

            }
            if(nombreJoueurB == aleaB)
            {
                nombreJuste++;
                tamponB = aleaB;

                aleaB = nombreJoueurB - aleaB;


            }
            if(nombreJoueurC == aleaC)
            {
                nombreJuste++;
                tamponC = aleaC;

                aleaC = nombreJoueurC - aleaC;

            }
            if(nombreJoueurD == aleaD)
            {
                nombreJuste++;
                tamponD = aleaD;

                aleaD = nombreJoueurD - aleaD;
            }

            if(aleaA != 0)
            {
                malPlaceA = detection(nombreJoueurA);
            }
            if(aleaB != 0)
            {
                malPlaceB = detection(nombreJoueurB);
            }
            if(aleaC != 0)
            {
                malPlaceC = detection(nombreJoueurC);
            }
            if(aleaD != 0)
            {
                malPlaceD = detection(nombreJoueurD);
            }
            nombreMalPlaces = malPlaceA + malPlaceB + malPlaceC +malPlaceD;

            cout << "Nombres de bien places: " << nombreJuste << endl;
            cout << " " << endl;

            cout << "Nombres de mal places: " << nombreMalPlaces << endl;


            aleaA = tamponA;
            aleaB = tamponB;
            aleaC = tamponC;
            aleaD = tamponD;

            nombreJuste = 0;
            nombreMalPlaces = 0;
            malPlaceA = 0;
            malPlaceB = 0;
            malPlaceC = 0;
            malPlaceD = 0;

            if(nombreJoueurA == aleaA && nombreJoueurB == aleaB && nombreJoueurC == aleaC && nombreJoueurD == aleaD)
            {
                cout << "C'est gagne pour toi" << endl;
                j= 12;
            }
            else
            {
                cout << "Essaie encore" << endl;
                cout << " " << endl;
            }
        }
                system("pause");

    }
    else if (a==2)
    {
        srand (time(NULL));
        for(genA=1000; genA<6001; genA=genA+1000)  //ces 4 boucles generent la liste de toutes les combinaisons possible et les place dans le tableau DB
        {
            for(genB=100; genB<601; genB=genB+100)
            {
                for(genC=10; genC<61; genC=genC+10)
                {
                    for(genD=1; genD<7; genD++)
                    {
                        DB[remplisseurDB]=genA+genB+genC+genD;
                        //cout<<DB[remplisseur]<<endl;   //le cout est ici pour tester et debug la generation
                        remplisseurDB=remplisseurDB+1;
                    }
                }
            }
        }
        DB[1296]=plomb;
        cout<<"Entrez la combinaison a trouver"<<endl;
        cin>>combiA>>combiB>>combiC>>combiD;
        tampA = combiA;
        tampB = combiB;
        tampC = combiC;
        tampD = combiD;


       while (finJeuIA==0)
    {
        TriT=0;
            while(TriT=0)
            {
                TriJ=0;
                for(TriJ=0; TriJ<1296; TriJ++)
                {
                    if(DB[TriJ]>DB[TriJ+1])
                    {
                        TriP=DB[TriJ];
                        DB[TriJ]=DB[TriJ+1];
                        DB[TriJ+1]=TriP;

                    }
                if(DB[0]<DB[1295]){
                        TriT=1;
                }
                }
            }

      //  for(int p=0;p<1297;p++){ cout<<DB[p]<<endl;}

  cout << string( 50, '\n' );

    cout<<"Tentative "<<tentativesIA<<":"<<endl;

           mesureurDB=0;

            compteurMesureurDB=0;
            while (compteurMesureurDB<1297)
            {
                if(DB[compteurMesureurDB]!=plomb)
                {
                    mesureurDB=mesureurDB+1;
                }
                compteurMesureurDB=compteurMesureurDB+1;
           }
            cout<<mesureurDB<<" combinaisons possibles"<<endl;
            trieurDB=0;

            choixMachine=plomb;
            chercheurDB=0;
           while(choixMachine==plomb)
            {
                chercheurDB=rand()%(1296);
                choixMachine=DB[chercheurDB];
           }
            cout<<"Choix de la machine: "<<choixMachine<<endl;

            iaA=choixMachine/1000;
            iaB=(choixMachine-(iaA*1000))/100;
            iaC=(choixMachine-(iaA*1000+iaB*100))/10;
            iaD= choixMachine-(iaA*1000+iaB*100+iaC*10);

//comparaison entre le resultat de l'IA et notre combinaison
                    if(1==1)
                {
            if(iaA == combiA)
            {
                BPia++;
                iaAtampon = combiA;
                combiA = iaA - combiA;
            }
            if(iaB == combiB)
            {
                BPia++;
                iaBtampon = combiB;
                combiB = iaB - combiB;
            }
            if(iaC == combiC)
            {
                BPia++;
                iaCtampon = combiC;
                combiC = iaC - combiC;
            }
            if(iaD == combiD)
            {
                BPia++;
                iaDtampon = combiD;
                combiD = iaD - combiD;
            }

        TcombiA = combiA;
        TcombiB = combiB;
        TcombiC = combiC;
        TcombiD = combiD;

            if(combiA != 0)
            {
                MPia = comparMachineCombinaison(iaA)+MPia;
            }
            if(combiB != 0)
            {
                MPia = comparMachineCombinaison(iaB)+MPia;
            }
            if(combiC != 0)
            {
                MPia = comparMachineCombinaison(iaC)+MPia;
            }
            if(combiD != 0)
            {
                MPia = comparMachineCombinaison(iaD)+MPia;
            }


            cout << "Nombres de bien places: " << BPia << endl;
            cout << " " << endl;

            cout << "Nombres de mal places: " << MPia << endl;
            cout<<" "<<endl;

            combiA = tampA;
            combiB = tampB;
            combiC = tampC;
            combiD = tampD;

            cout<<combiA<<combiB<<combiC<<combiD<<endl;
            if (BPia==4)
            {
                victoireIA=1;
                finJeuIA=1;
            }
            if (BPia+MPia!=0)
            {
            for(j=0; j<1296; j++)
            {

                dbA=DB[j]/1000;
                dbB=(DB[j]-(dbA*1000))/100;
                dbC=(DB[j]-(dbA*1000+dbB*100))/10;
                dbD= DB[j]-(dbA*1000+dbB*100+dbC*10);

                combiA = iaA;
                combiB = iaB;
                combiC = iaC;
                combiD = iaD;

                if(dbA == combiA)
                {
                    dbBP++;
                    dbAtampon = combiA;
                    combiA = 0;
                }
                if(dbB == combiB)
                {
                    dbBP++;
                    dbBtampon = combiB;
                    combiB = 0;
                }
                if(dbC == combiC)
                {
                    dbBP++;
                    dbCtampon = combiC;
                    combiC = 0;
                }
                if(dbD == combiD)
                {
                    dbBP++;
                    dbDtampon = combiD;
                    combiD = 0;
                }


        TcombiA = combiA;
        TcombiB = combiB;
        TcombiC = combiC;
        TcombiD = combiD;

                if(combiA != 0)
                {
                    dbMP = comparMachineCombinaison(dbA)+dbMP;
                }
                if(combiB != 0)
                {
                    dbMP = comparMachineCombinaison(dbB)+dbMP;
                }
                if(combiC != 0)
                {
                    dbMP = comparMachineCombinaison(dbC)+dbMP;
                }
                if(combiD != 0)
                {
                    dbMP = comparMachineCombinaison(dbD)+dbMP;
                }

                if(dbMP==MPia)
                {
                    if(dbBP==BPia)
                    {
                        garde=1;
                    }
                }

                if (garde==0)
                {
                    DB[j]=plomb;
                }
                garde=0;


                combiA = tampA;
                combiB = tampB;
                combiC = tampC;
                combiD = tampD;

                dbBP = 0;
                dbMP = 0;
                }
            }

        }

        if (tentativesIA==12)
        {
            victoireIA=0;
            finJeuIA=1;
        }

        tentativesIA=tentativesIA+1;
        BPia = 0;
        MPia = 0;
         system("pause");

    }
    if (victoireIA==1){
         cout << string( 50, '\n' );
        cout<<"La partie est terminee. La machine a gagne en "<< tentativesIA << " coups" <<endl;

        }

    return 0;
}
    else if (a==3)
    {
          cout << "Le joueur 1 sera celui qui défini la combinaison a trouver et le Joueur 2 sera celui qui devra la trouver." << endl;
        system("pause");

    while (Blocker!=0) // C'est une boucle qui évite au Joueur 1 de tricher
    {
        cout << string( 100, '\n' ); // cette fonction permet de créer beaucoup d'espace pour nettoyer l'écran, on suppose donc que le joueur n'a pas accès à la souris
        if (Blocker==1)
        {
            cout << "Veuillez ne pas tricher ! Mettez un chiffre entre 1 et 6" << endl;
        }

        cout << "Le Joueur 1, decide de la combinaison" << endl;
        cin >> nbrA >> nbrB >> nbrC >> nbrD;

        if (nbrA<1 || nbrB<1 || nbrC<1 || nbrD<1 || nbrA>6 || nbrB>6 || nbrC>6 || nbrD>6 )
        {

            Blocker=1;
        }
        else
            Blocker=0;

    }
    Blocker=2; // ça initialise le bloqueur

    for (Temps=0 ; Temps<12 ; Temps=Temps+1) // C'est la grosse boucle que permet de respecter la règle des 12 tours de jeu
    {

        while (Blocker!=0) // C'est une boucle qui évite au Joueur 2 de tricher
        {
            cout << string( 100, '\n' );
            if (Blocker==1)
            {
                cout << "Veuillez ne pas tricher ! Mettez un chiffre entre 1 et 6." << endl;
            }
            if (BienP!=7) // Quand les valeurs de base sont changées, on montre le nombre de bien placés et de mals placés
            {
                cout << "Le Joueur 1 a dit qu'il y a " << BienP << " bien places, et " << MalP << " mal places !" << endl;
            }


            cout << "Le joueur 2 fait sa supposition" << endl;
            cin >> essaiA >> essaiB >> essaiC >> essaiD;

            if (essaiA<1 || essaiB<1 || essaiC<1 || essaiD<1 || essaiA>6 || essaiB>6 || essaiC>6 || essaiD>6 )
            {

                Blocker=1;
            }
            else
                Blocker=0;

        }
        Blocker=2; // ça initialise le bloqueur

        while (Blocker!=0) // C'est une boucle qui évite au Joueur 1 de tricher
        {
            cout << string( 100, '\n' );

            if (Blocker==1)
            {

                cout << "Donnez au moins un chiffre entre 0 et 4" << endl;
            }

            cout << "Le joueur a donne :" << essaiA << essaiB << essaiC << essaiD << endl;
            cout << "Donnez le nombre de bien places !" << endl;
            cin >> BienP;
            cout << "Donnez le nombre de mal places !" << endl;
            cin >> MalP;

            if (BienP<0 || MalP<0 || BienP>4 || MalP>4 )
            {
                Blocker=1;
            }
            else
                Blocker=0;
        }
        Blocker=2;  // ça initialise le bloqueur
        if (BienP==4)
        {
            Temps=12; // on stoppe la partie si le Joueur 1 a dit qu'il y a 4 bien placés
            gagne=1;
        }
    }
    if (gagne==0)
    {
        cout << string( 100, '\n' );
        cout << "Fin de partie, le Joueur 1 gagne !";
    }
    if (gagne==1)
    {
        cout << string( 100, '\n' );
        cout << "Fin de partie, le Joueur 2 gagne !";
        system("pause");


    }
    }
}


