

//             Librerias  //
#include <iostream>
#include "usuario.h"
#include "tarjeta.h"
#include "banco.h"
#include "atm.h"
#include "sbancario.h"
// -----------------------------------
using namespace std;

// funciones adicionales //
//-----------------------//

//----------------------------------------------------------
// entrada: class usuer
// salida: int
// operacion: preguntarle al usuario que tarjeta desea usar.
int select_card(user usua)
{
    int respuesta;

    cout<<"Que tarjeta va utilizar: "<<endl;
    cout<<"1."<<(usua.get_tarjeta(1))->get_nombreBanco()<< "      ";
    cout<<"2."<<(usua.get_tarjeta(2))->get_nombreBanco()<<endl;
    cout<<"dijite que tarjeta va usar: ";
    cin>>respuesta;

    return respuesta;
}

//----------------------------------------------------------
// entrada: class user y int
// salida:
// operacion: mostrar por pantalla los datos de un usuaio
void printInformacionUsuario(user usuario, int numeroUsuario)
{
    
    cout<<"usuario "<<numeroUsuario<<endl;
    cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
    cout<<"nombre de usuario: "<<usuario.get_Name()<<endl;
    cout<<"contraseña: "<<usuario.get_Pasword()<<endl;
    cout<<"tarjeta 1: "<<endl;
    cout<<"nombre del banco: "<<usuario.get_tarjeta(1)->get_nombreBanco()<<endl;
    cout<<"numero cuenta: "<<usuario.get_tarjeta(1)->get_numeroCuenta()<<endl;
    cout<<"cantidad retiro: "<<usuario.get_tarjeta(1)->get_cantidadRetiro()<<endl;
    cout<<"tarjeta 2: "<<endl;
    cout<<"nombre del banco: "<<usuario.get_tarjeta(2)->get_nombreBanco()<<endl;
    cout<<"numero cuenta: "<<usuario.get_tarjeta(2)->get_numeroCuenta()<<endl;
    cout<<"cantidad retiro: "<<usuario.get_tarjeta(2)->get_cantidadRetiro()<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    
}

// entrada: tres class ATM
// salida: class ATM
// operacion: que el usuario escoja un cajero.
ATM select_cajero(ATM cajero1, ATM cajero2, ATM cajero3)
{
    int cajero;
    ATM temp;
    
    cout<<"escoja uno de los siguientes cajeros: "<<"1. atm popular  2. atm bogota  3.atm davivienda "<<endl;
    cin>>cajero;
    
    while (cajero != 1 & cajero != 2 & cajero != 3)
    {
        cout<<"debe seleccionar un cajero. "<<endl;
        cout<<"escoja uno de los siguientes cajeros: "<<"1. atm popular  2. atm bogota  3.atm davivienda "<<endl;
        cin>>cajero;
    }
    
    if (cajero == 1)
    {
        temp = cajero1;
    }
    else if(cajero == 2)
    {
        temp = cajero2;
    }
    else if(cajero == 3)
    {
        temp = cajero3;
    }
    
    return temp;
}

// entrada: dos class user
// salida:: class user
// operacion: seleccionar un usuario
user select_usuario(user usuario1, user usuario2)
{
    int selector;
    user temp;
    
    cout<<"escoja un usuario: "<<"1. "<<usuario1.get_Name()<<"    2."<<usuario2.get_Name()<<endl;
    cin>>selector;
    
    while (selector != 1 & selector !=2 )
    {
        cout<<"tiene que elegir un usuario..."<<endl;
        cout<<"escoja un usuario: "<<"1. "<<usuario1.get_Name()<<"    2."<<usuario2.get_Name()<<endl;
        cin>>selector;
    }
    
    if(selector == 1)
    {
        temp = usuario1;
    }
    else{
        temp = usuario2;
    }
    
    return temp;
}

// entrada: class SB, class ATM y class user
// salida: class *Bank
// operacion: retorna el banco en el que se encuentra la cuenta del usuario.
Bank* select_bank(SB sb, ATM cajero, user usuario)
{
    int i,j,salir=false;
    
    Bank *temp_selec;
    
    for (i=0; (i<3 & salir == false); i++)
    {
        temp_selec = sb.get_bank(i);
        
        for (j=0; (j<2 & salir == false); j++)
        {
                if(cajero.CheckAccount(usuario.get_tarjeta(j)->get_numeroCuenta(), temp_selec->get_Accounts()) == true)
                   {
                       salir = true;
                   }
        }
    }
    
   return temp_selec;
}
                   
// entrada:
// salida:
// operacion: busqueda de los datos del usuario
//int Account_existente(sbancario banco);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
int main(){
    
// variables locales.
    string name;
    bool next, salir=false;
    int option, pass, numeroTarjeta;

    // class tarjeta
    card tarj1, tarj2, tarj3, tarj4, *tarjPuntero;
    
    // class usuarios
    user usr1(tarj1,tarj2),usr2(tarj3,tarj4), usuario_selec;
    
    // class banco
    Bank ban1, ban2, ban3, *sbancario;
    

    
    // class sbancario
/*  ban1 = banco bogota
    ban2 = banco popular
    ban3 = banco davivienda
 */
    SB sb(ban1,ban2,ban3);
    
    // class atm
    ATM atm, atm1,atm2, atm_selec;
    
    // asignaciones: 
    
    // usuario 1  //
    usr1.set_Name("pepito");
    (usr1.set_Pasword(1234));
    // usuario 1 tarjeta 1  //
    (usr1.get_tarjeta(1))->set_numeroCuenta(123456);
    (usr1.get_tarjeta(1))->set_cantidadRetiro(1000000);
    (usr1.get_tarjeta(1))->set_nombreBanco("banco popular");
    // usuario 1 tarjeta 2  //
    (usr1.get_tarjeta(2))->set_numeroCuenta(001212352);
    (usr1.get_tarjeta(2))->set_cantidadRetiro(600000);
    (usr1.get_tarjeta(2))->set_nombreBanco("banco bogota");

    
    // usuario 2 //
    usr2.set_Name("mierda");
    (usr2.set_Pasword(111));
    // usuario 2 tarjeta 1 //
    (usr2.get_tarjeta(1))->set_nombreBanco("banco davivienda");
    (usr2.get_tarjeta(1))->set_cantidadRetiro(10000000);
    (usr2.get_tarjeta(1))->set_numeroCuenta(123131312);
    // usuario 2 tarjeta 2 //
    (usr2.get_tarjeta(2))->set_nombreBanco("banco bogota");
    (usr2.get_tarjeta(2))->set_cantidadRetiro(200000);
    (usr2.get_tarjeta(2))->set_numeroCuenta(12312321);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    // Muestra por pantalla los datos del los dos usuarios //
    printInformacionUsuario(usr1, 1);
    printInformacionUsuario(usr2, 2);
    
    //                  bancos.                 //
    
    // banco1 asignacion (banco bogota) //
    // inscripcion del usuario 1 al banco1
    ban1.set_bank_name("banco bogota");
    (ban1.set_usuario_account(usr1,2));
    (ban1.set_usuario_password(usr1));
    (ban1.set_usuario_balance(200000));
    //--------------------------------
    // inscripcion del usuario 2 al banco1
    (ban1.set_usuario_account(usr2,2));
    (ban1.set_usuario_password(usr2));
    (ban1.set_usuario_balance(200000));
    
    // banco2 asignacion (banco popular) //
    // inscripcion del usuario 1 al banco2
    ban2.set_bank_name("banco popular");
    (ban2.set_usuario_account(usr1,1));
    (ban2.set_usuario_password(usr1));
    (ban2.set_usuario_balance(100000000));
    
    // banco3 asignacion (banco davivienda) //
    // inscripcion del usuario 2 al banco3
    ban3.set_bank_name("banco davivienda");
    (ban3.set_usuario_account(usr2,1));
    (ban3.set_usuario_password(usr2));
    (ban3.set_usuario_balance(250000));

    // cajeros //
    // cajero atm(banco popular) //
    atm.set_tipo_bank("banco popular");
    atm.set_dinero_atm(10000000);
    
    // cajero atm(banco bogota) //
    atm1.set_tipo_bank("banco bogota");
    atm1.set_dinero_atm(1000000);
    // cajero atm(banco davivienda) //
    atm2.set_tipo_bank("banco davivienda");
    atm2.set_dinero_atm(800000);

    
    
    
    
    // loop principal //
    while (salir == false)
    {
        // select user //
        usuario_selec = select_usuario(usr1, usr2);
        // select atm //
        atm_selec = select_cajero(atm, atm1, atm2);
        // select sistem abancario //
        sbancario = select_bank(sb,atm_selec,usuario_selec);
        
            
        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
        //  Interaction between the person and the ATM
        cout << "Hello, welcome to your cajero "<<atm_selec.get_tipo_bank()<<", please slide your card..." << endl;
        cout << "Enter your card" << endl;
        cout << "What card you want use: "<< endl;
        numeroTarjeta = select_card(usuario_selec);
        while (numeroTarjeta != 1 & numeroTarjeta != 2)
        {
            cout<<"tiene que seleccionar una tarjeta"<<endl;
            numeroTarjeta = select_card(usuario_selec);
        }
        cout<<"verificación de password"<<endl;
        cout<<"escriba su password: ";
        cin >> pass;
        
        // here comes the verification of the password
        do{
            next = atm_selec.CheckPass((usuario_selec.get_tarjeta(numeroTarjeta))->get_numeroCuenta(),usuario_selec.get_Pasword(), sbancario->get_Accounts(), sbancario->get_Passwords());
            if (next == true)
            {
                cout << "Password Checked...\n" << endl;
            }
            else{
                cout << "Wrong password try again...\n" << endl;
                cout << "Please enter your password once again: " << endl;
                cin >> pass;
            }
        }while(next == false);

        // Once the password is accepted, the user has to choose between the following options
        cout << "What do you wanto to do now, (1) withdraw (2) Balance   (3) Salir \n" << endl;
        cin >> option;
        if (option == 1)
        {
            cout << "Please digit the amount of money you would like to withdraw: " << endl;
            cin >> option;
            next = atm_selec.Checkbal((usuario_selec.get_tarjeta(numeroTarjeta))->get_numeroCuenta(),ban1.get_Accounts(), usuario_selec.get_tarjeta(numeroTarjeta)->get_cantidadRetiro(), ban1.get_Balances());
            if (next == true)
            {
                cout << "Success \n" << endl;
            }
            else
                cout << "Error, please try again \n" << endl;
        }
        
        else if (option == 2)
        {
            option = atm_selec.recipe((usuario_selec.get_tarjeta(numeroTarjeta))->get_numeroCuenta(), usuario_selec.get_Pasword(), sbancario->get_Accounts(), sbancario->get_Passwords(),sbancario->get_Balances());
            if (option != 0){
                cout << "Currently, your balance is: " << option << endl;}
            else
                cout << "Either your account or your password is incorrect" << endl;
        }
        else if (option == 3)
        {
            salir = true;
            cout<<" Thank your for using your moma's ATM" <<endl;
        }
        else
            {
                cout << "Wrong option please try again \n" << endl;
                cout << "Thank your for using your moma's ATM " << usuario_selec.get_Name() << endl;
            }
    }
    
//-------------------------------------------------------------------------------------------------
//  
//        //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//        //  Interaction between the person and the ATM
//        cout << "Hello, welcome to your cajero "<<cajero_seleccionado->get_tipo_bank()<<",  please slide your card..." << endl;
//        //cout << "Please enter your name: " << endl;
//        //getline(cin,name);
//        //usr1.set_Name(name);
//        //cout << "Enter your card's password: " << endl;
//        cout << "Enter your card" << endl;
//        cout << "What card you want use: "<< endl;
//        numeroTarjeta = select_card(usua);
//        while (numeroTarjeta != 1 & numeroTarjeta != 2)
//        {
//            cout<<"tiene que seleccionar una tarjeta"<<endl;
//            numeroTarjeta = select_card(usua);
//        }
//        cout<<"verificación de password"<<endl;
//        cout<<"escriba su password: ";
//        //cout << usr1.get_tarjeta.get_Name << endl
//        cin >> pass;
//        // here comes the verification of the password
//        do{
//            next = atm.CheckPass((usua.get_tarjeta(numeroTarjeta))->get_numeroCuenta(),usua.get_Pasword(), ban1.get_Accounts(), ban1.get_Passwords());
//            if (next == true)
//            {
//                cout << "Password Checked...\n" << endl;
//            }
//            else{
//                cout << "Wrong password try again...\n" << endl;
//                cout << "Please enter your password once again: " << endl;
//                cin >> pass;
//                }
//        }while(next == false);
//        
//        // Once the password is accepted, the user has to choose between the following options
//        cout << "What do you wanto to do now, (1) withdraw (2) Balance \n" << endl;
//        cin >> option;
//        if (option == 1)
//        {
//            cout << "Please digit the amount of money you would like to withdraw: " << endl;
//            cin >> option;
//            next = atm.Checkbal((usua.get_tarjeta(numeroTarjeta))->get_numeroCuenta(),ban1.get_Accounts(), usua.get_tarjeta(numeroTarjeta)->get_cantidadRetiro(), ban1.get_Balances());
//            if (next == true)
//            {
//                cout << "Success \n" << endl;
//            }
//            else
//                cout << "Error, please try again \n" << endl;
//        }
//        
//        else if (option == 2)
//        {
//            option = atm.recipe((usua.get_tarjeta(numeroTarjeta))->get_numeroCuenta(), usua.get_Pasword(), ban1.get_Accounts(), ban1.get_Passwords(),ban1.get_Balances());
//            if (option != 0){
//                cout << "Currently, your balance is: " << option << endl;}
//            else
//                cout << "Either your account or your password is incorrect" << endl;
//        }
//        else 
//            cout << "Wrong option please try again \n" << endl;
//        
//        
//        cout << "Thank your for using your moma's ATM " << usua.get_Name() << endl;
        
    return 0;
        
}
