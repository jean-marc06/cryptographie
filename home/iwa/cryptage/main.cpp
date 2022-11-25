#include <iostream>
#include <ctype.h>
#include <string.h>

#define TAILLE_MAX 10000

using namespace std;

void  chiffrement(char message[TAILLE_MAX],
                  char cle[TAILLE_MAX],
                  int tailleCle){
    int iTab, iCle;
    for(iTab=0, iCle=0;message[iTab]!='\0';++iTab){
        if(isupper(message[iTab])){
            char typo, lettreCle;
            typo=(isupper(message[iTab])) ? 'A' : 'a';
            lettreCle=tolower(cle[iCle]) - 'a';
            iCle= (iCle + 1)%tailleCle;

            message[iTab]-=typo;
            message[iTab]=((message[iTab] + lettreCle)%26 + 26)%26;
            message[iTab]+=typo;
        }
    }
}


void  dechiffrement(
        char message[TAILLE_MAX],
        char cle[TAILLE_MAX],
        int tailleCle){
    int iTab, iCle;
    for(iTab=0, iCle=0;message[iTab]!='\0';++iTab){
        if(isupper(message[iTab])){
            char typo, lettreCle;
            typo=(isupper(message[iTab])) ? 'A' : 'a';
            lettreCle=tolower(cle[iCle]) - 'a';
            iCle= (iCle + 1)%tailleCle;

            message[iTab]-=typo;
            message[iTab]=((message[iTab] - lettreCle)%26 + 26)%26;
            message[iTab]+=typo;
        }
    }
}


void viderBuffer(void){
    int c;
    c=0;
    while(c!='\n' && c!= EOF){
        c = getchar();
    }
}


int main() {
   char message[TAILLE_MAX];
   char cle[TAILLE_MAX];
   int tailleCle,x;

   cout<<"Entrez le message: ";
   cin>>message;
   viderBuffer();

   cout<<"Entrez la cle: ";
   cin>>cle;
   tailleCle=strlen(cle);

   cout<<"1- Encrypter le mot."<<endl;
   cout<<"2- Decrypter le mot."<<endl;
   cout<<"Choisissez une option: ";
   cin>>x;

   while(x!=1 && x!=2){
       cout<<"Choisissez entre 1 et 2.";
       cin>>x;
   }

   if(x==1){
       chiffrement(message,cle,tailleCle);
       cout<<"Le message encode est: "<<message<<endl;
   }
   if(x==2){
       dechiffrement(message,cle,tailleCle);
       cout<<"Le message decode est: "<<message<<endl;
   }

}
