#include <iostream>
#include <vector>
using namespace std;
void mostrarListado(vector<int> list){
    vector<int>::iterator it;
    int posicion = 1;
    for(it = list.begin(); it < list.end(); it++){
        cout<<"POSICION: "<<posicion<<" CLAVE DE TURNO: "<<*it<<"\n"; 
        posicion++;      
    }
}
void darTurno(vector<int>& list, int *turnos)
{
    int prioritario, position, nuevoTurno = *turnos;
    do
    {
        cout << "USTED ES PRIORITARIO? \n 1.SI \n 2.NO \n";
        cin >> prioritario;

    } while (prioritario < 1 || prioritario > 2);
    if(prioritario == 1){
        do{

        cout<<"ACTUALMENTE HAY: "<<list.size()<<"POSICIONES"<<"\n INDIQUE POR FAVOR UNA POSICION: ";
        cin>>position;
        }while(position > list.size() || position < list.size());
        list.insert(list.begin() + position, *turnos);
        *turnos = nuevoTurno + 1;
    }else{
        list.push_back(*turnos);
        cout<<"SU CLAVE DE TURNO ES: "<<*turnos<<"\n";
        *turnos = nuevoTurno += 1;
        cout<<"TURNO AGREGADO CORRECTAMENTE \n";
    }
}
int main()
{
    bool salidaSistema = false;
    vector<int> turnos;
    int numeroTurnos = 1; // Clave de turnos autoincrementable
    do
    {
        int opc;
        cout << "---SISTEMA DE ATENCION AL CLIENTE--- \n";
        cout << "1. DAR TURNO \n";
        cout << "2. ATENDER PERSONA \n";
        cout << "3. CANCELAR TURNO \n";
        cout << "4. MOSTRAR LISTADO TURNOS \n";
        cout << "5. SALIR DEL SISTEMA \n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "---DAR TURNO---- \n";
            darTurno(turnos, &numeroTurnos)     ;
            break;
        case 2:
            cout << "---ATENDER PERSONA---- \n";
            break;
        case 4:
            cout<<"---MOSTRAR LISTADO TURNOS--- \n";
            mostrarListado(turnos);
            break;
        }
    } while (!salidaSistema);
}