#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int a;
string const nomFicher("C:/Users/user/Desktop/prog perso/Cours de prog c++/test.txt");
int main()
{
    cout<<"Que voulez vous faire ?"<<endl;
    cout<<"1: Ecrire"<<endl;
    cout<<"2: Lire"<<endl;
    cin>>a;

    if(a==1)
    {
        ofstream monFlux(nomFicher.c_str(), ios::app);
        if(monFlux)
        {
            monFlux<< "Ceci est une phrase test." << endl;
            monFlux<<"je teste aussi les accents é è â ï à ù" << endl;
            monFlux<<49+5854.584/98<< endl;
            cout<<"C'est ajouté"<<endl;
        }
        else
        {
            cout<< "Erreur: Impossible d'ouvrir le ficher"<< endl;
        }
    }
    if(a==2){

        ifstream monFlux(nomFicher.c_str());
        if(monFlux)
        {


        }

    else
    {
        cout<< "Erreur: Impossible d'ouvrir le ficher en lecture"<< endl;
    }
}



return 0;
}
