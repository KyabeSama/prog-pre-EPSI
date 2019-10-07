#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;
int question, oui=1;
int nombreAleatoire;
const int a=1,b=16;
const int StationService=1, Banque=2, Cafe=3, Canal=4, Chalet=5, ClubHouse=6, Consulat=7, Favelas=8, Frontiere=9, GratteCiel=10, Hereford=11, Villa=12, Oregon=13, ParcAttractions=14, Tour=15;
int main()
{
 question=oui;
 while(question==oui){
    srand(time(NULL));
    nombreAleatoire = rand()%(b-a)+a;
// Je genère un nombre entier aléatoire qui rentre dans [a;b[ 4 fois

if (nombreAleatoire == StationService){
    cout<<"Station de Service"<<endl;
}else if(nombreAleatoire == Banque){
    cout<<"Banque"<<endl;
}else if(nombreAleatoire == Cafe){
    cout<<"Cafe"<<endl;
}else if (nombreAleatoire == Canal){
    cout<<"Canal"<<endl;
}else if (nombreAleatoire == Chalet){
    cout<<"Chalet"<<endl;
}else if (nombreAleatoire == ClubHouse){
    cout<<"Club House"<<endl;
}else if (nombreAleatoire == Consulat){
    cout<<"Consulat"<<endl;
}else if (nombreAleatoire == Favelas){
    cout<<"Favelas"<<endl;
}else if (nombreAleatoire == Frontiere){
    cout<<"Frontiere"<<endl;
}else if (nombreAleatoire == GratteCiel){
    cout<<"Gratte-Ciel"<<endl;
}else if (nombreAleatoire == Hereford){
    cout<<"Hereford"<<endl;
}else if (nombreAleatoire == Villa){
    cout<<"Villa"<<endl;
}else if (nombreAleatoire == Oregon){
    cout<<"Oregon"<<endl;
}else if (nombreAleatoire == ParcAttractions){
    cout<<"Parc d'Attractions"<<endl;
}else if (nombreAleatoire == Tour){
    cout<<"Tour"<<endl;}

question=0;
cout<<"Relancer le random ?" <<endl;
cin>>question;
}
 system("pause");
    return 0;
}
