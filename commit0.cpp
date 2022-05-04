#include <iostream>
#define DIM 50
/*Inserire un nuovo libro (Codice ISBN, Titolo, Autore, Editore, Anno di Pubblicazione, Prezzo, Tag del Genere)
Visualizzare l’intero catalogo della biblioteca
Cancellare un libro (attraverso il codice ISBN)
Ricercare un particolare libro (attraverso il codice ISBN)
Effettuare delle modifiche (si ricerca il libro attraverso ISBN e si possono modificare tutte le relative informazioni)*/

using namespace std;
struct libro
{
    string codice;
    string titolo;
    string autore;
    string editore;
    int anno_pub;
    float prezzo;
    string tag_genere;
};

void stampaMenu()
{
    cout<<"Seleziona l'opzione: "<<endl<<endl;
    cout<<"1) Inserire nuovo libro"<<endl;
    cout<<"2) Visualizza il catalogo della biblioteca"<<endl;
    cout<<"3) Cancellare libro"<<endl;
    cout<<"4) Ricercare un libro"<<endl;
    cout<<"5) Effettuare modifiche"<<endl;
    cout<<"6) Uscita dal menu"<<endl;
}

libro inserisciLibro()
{
    libro input;
    cout<<"Inserire il codice: ";
    cin>>input.codice;
    cout<<"Inserire il titolo: ";
    cin>>input.titolo;
    cout<<"Inserire l' autore: ";
    cin>>input.autore;
    cout<<"Inserire l' editore: ";
    cin>>input.editore;
    cout<<"Inserire l' anno di pubblicazione: ";
    cin>>input.anno_pub;
    cout<<"Inserire il prezzo: ";
    cin>>input.prezzo;
    cout<<"Inserire il tag del genere: ";
    cin>>input.tag_genere;

    return input;
}

void visualizzaCatalogo(libro catalogo[], int n)
{
    for(int i = 0; i<n; i++)
    {
        cout<<catalogo[i].codice<<" - "<<catalogo[i].titolo<<" - "<<catalogo[i].autore<<" - "<<catalogo[i].tag_genere<<endl;

    }
}

int ricercaCodice(libro libri[], int n, string codice)
{
    for(int i = 0; i<n; i++)
    {
        if(codice == libri[i].codice)
        {
            return i;
        }
    }
    return -1;
}

int ricercaTitolo(libro libri[], int n, string titolo)
{
    for(int i = 0; i<n; i++)
    {
        if(titolo == libri[i].titolo)
        {
            return i;
        }
    }
    return -1;
}


void cancellaLibro(libro libri[], int &n)
{
    string codice;
    int indice;
    visualizzaCatalogo(libri, n);
    cout<<"Seleziona il libro da cancellare: ";
    cin>>codice;
    indice = ricercaCodice(libri, n, codice);
    if(indice != -1)
    {
        for(int j = indice; j<n-1; j++)
        {
            libri[j] = libri[j+1];
        }
        n--;
    }
    else{
        cout<<"Impossibile trovare il codice inserito"<<endl;
    }
}








int main()
{
    int scelta;
    int cont = 0;
    libro libri[DIM];
    do{

        stampaMenu();
        cin>>scelta;
        switch(scelta)
        {
            case 1:
                if(cont < DIM)
                {
                    libri[cont] = inserisciLibro();
                    cont++;
                }
                else{
                    cout<<"Memoria terminata :("<<endl;
                }
                break;
            case 2:
                visualizzaCatalogo(libri, cont);
                break;
            case 3:
                cancellaLibro(libri, cont);
                break;
            case 4:
                break;
            case 5:
                break;

        }

    }while(scelta != 6);
    cout<<"Ciao Ciao";
    return 0;
}
