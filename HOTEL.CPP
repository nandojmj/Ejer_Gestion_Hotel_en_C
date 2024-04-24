#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define hsenc 80000
#define hlujo 100000

//Lista A
typedef struct NodoCliente {
	char cedula[12];
	char nombre[30];
	char apellido[30];
	char procedencia[30];
	char telefono[10];

	struct NodoCliente *sigC;
}Cliente;
typedef Cliente *CNodo;
typedef Cliente *CLista;


//Lista B
typedef struct NodoHabitacion {
	int NoHabitacion;
	int NoPiso;
	int tipo;
	long valor;

	struct NodoHabitacion *sigH;
}Habitacion;
typedef Habitacion *HNodo;
typedef Habitacion *HLista;


//Lista C
typedef struct NodoFacturacion {
	int NoFactura;
	int NoDias;
	long valorTotal;
	long consumo;

	struct NodoFacturacion *sigF;
}Facturacion;
typedef Facturacion *FNodo;
typedef Facturacion *FLista;

void insertar(CLista *listac, HLista *listah, FLista *listaf);
void facturaXcliente(CLista listac, HLista listah,FLista listaf);
void busqXcliente(CLista listac, HLista listah, char ape[]);
void busqXhabit(CLista listac, HLista listah, FLista listaf, int hab);
void insConsumo(CLista listac, HLista listah,FLista listaf);
void mostrar(CLista l);

int fact=1;

void main()
{
   CLista listac = NULL;
   HLista listah = NULL;
   FLista listaf = NULL;
   char op, ape[30], ced[12];
   int hab=0;
    do {
	   clrscr();
	 cout<<"\n\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออป";
	 cout<<"\n\tบ                                                     บ";
	 cout<<"\n\tบ               -- HOTEL CARLANCHIN --                บ";
	 cout<<"\n\tบ                                                     บ";
	 cout<<"\n\tฬอออออออออออออออออออออออออออออออออออออออออออออออออออออน";
	 cout<<"\n\tบ                                                     บ";
	 cout<<"\n\tบ     A.- INGRESAR DATOS                              บ";
	 cout<<"\n\tบ     B.- INGRESAR CONSUMO DEL CLIENTE                บ";
	 cout<<"\n\tบ     C.- IMPRIMIR FACTURAS                           บ";
	 cout<<"\n\tบ     D.- BUSQUEDA POR HABITACION                     บ";
	 cout<<"\n\tบ     E.- BUSQUEDA POR CLIENTES                       บ";
	 cout<<"\n\tบ     F.- MOSTRAR LISTA DE CLIENTES                   บ";
	 cout<<"\n\tบ     S.- SALIR                                       บ";
	 cout<<"\n\tบ                                                     บ";
	 cout<<"\n\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออผ";
	 cout<<"\n\n\t--> DIGITE UNA OPCION : ";
	 op = getch();
	   switch(toupper(op))
	   {
	      case 'A': insertar(&listac, &listah, &listaf);
			break;

	      case 'B': insConsumo(listac,listah,listaf);
			break;

	      case 'C': facturaXcliente(listac, listah, listaf);
			break;

	      case 'D': cout<<"\n\n\tDIGITE Nง DE HABITACION: ";
			cin>>hab;
			busqXhabit(listac, listah, listaf, hab);
			break;

	      case 'E': cout<<"\n\n\tDIGITE APELLIDO DEL CLIENTE: ";
			cin>>ape;
			busqXcliente(listac, listah, ape);
			break;

	      case 'F': mostrar(listac);
			break;

	      case 'S': exit(0);
			break;
	   }
    }while(op != 'S');
}
//*****************************************************************
void insertar(CLista *listac, HLista *listah, FLista *listaf)
{
   CNodo nCliente;
   HNodo nHabitacion;
   FNodo nFacturacion;

   char ced[12], nom[30], ape[30], proc[30],tel[10];
   int nhab=0, npiso=0; int tip; long v;
   int ndias; long vtotal;
   int sw=0;

   clrscr();
   gotoxy(1,1);cout<<"DATOS DEL CIENTE";
   gotoxy(1,3); cout<<"CEDULA     : ";
   gotoxy(14,3); cin>>ced;
   gotoxy(1,5); cout<<"NOMBRE     : ";
   gotoxy(14,5); cin>>nom;
   gotoxy(1,7); cout<<"APELLIDO   : ";
   gotoxy(14,7); cin>>ape;
   gotoxy(1,9); cout<<"PROCEDENCIA: ";
   gotoxy(14,9); cin>>proc;
   gotoxy(1,11); cout<<"TELEFONO   : ";
   gotoxy(14,11); cin>>tel;
   nCliente = new Cliente;
   strcpy(nCliente->cedula,ced);
   strcpy(nCliente->nombre,nom);
   strcpy(nCliente->apellido,ape);
   strcpy(nCliente->procedencia,proc);
   strcpy(nCliente->telefono,tel);
   nCliente->sigC = *listac;
   *listac = nCliente;

   do {
	sw=0;
	gotoxy(30,1); cout<<"DATOS HABITACION";
	gotoxy(30,3); cout<<"Nง. HABITACION: ";
	gotoxy(46,3); cin>>nhab;
	nHabitacion = *listah;
	while(nHabitacion)
	{
	   if(nHabitacion->NoHabitacion == nhab)
	   {
	      gotoxy(30,5);
	      cout<<"HAB. OCUPADA";
	      sw=1;
	   }
	   nHabitacion = nHabitacion->sigH;
	}
	if(sw == 0)
	{
	   gotoxy(30,5); cout<<"Nง. PISO      : ";
	   gotoxy(46,5); cin>>npiso;
	   gotoxy(30,7); cout<<"TIPO DE HABITACION : ";
	   gotoxy(30,9); cout<<"1.H. Sencilla";
	   gotoxy(30,11); cout<<"2.H. Lujo";
	   gotoxy(52,7); cin>>tip;
	   if(tip==1){v=hsenc;}
	   if(tip==2){v=hlujo;}
	   nHabitacion = new Habitacion;
	   nHabitacion->NoHabitacion = nhab;
	   nHabitacion->NoPiso = npiso;
	   nHabitacion->tipo=tip;
	   nHabitacion->valor = v;
	   nHabitacion->sigH = *listah;
	   *listah = nHabitacion;
	}
   }while(sw != 0);

   gotoxy(55,1); cout<<"DATOS FACTURACION";
   gotoxy(55,3); cout<<"FACTURA Nง : "<<fact;
   gotoxy(55,5); cout<<"Nง DE DIAS : ";
   gotoxy(71,5); cin>>ndias;
   vtotal = nHabitacion->valor * ndias;
   gotoxy(55,7); cout<<"VALOR TOTAL HAB.: $ "<<vtotal;
   getch();
   nFacturacion = new Facturacion;
   nFacturacion->NoFactura = fact;
   nFacturacion->NoDias = ndias;
   nFacturacion->valorTotal = vtotal;
   nFacturacion->consumo = 0;
   nFacturacion->sigF = *listaf;
   *listaf = nFacturacion;
   fact++;
}

//**********************************************************************
void insConsumo(CLista listac, HLista listah,FLista listaf)
{
   CNodo nCliente = listac;
   FNodo nFacturacion = listaf;
   HNodo nHabitacion = listah;

   char ced[12];
   long cons;
   int sw=0;
   if(!listac) cout<<"\n\n\tLISTA DE CLIENTES VACIA";
   else {
      clrscr();
      cout<<"\n\n\tDIGITE CEDULA CLIENTE: ";
      cin>>ced;

      while(nCliente)
      {
	 if(strcmp(ced,nCliente->cedula) == 0)
	 {
	    cout<<"\n\n\tCEDULA        : "<<nCliente->cedula;
	    cout<<"\n\tNOMBRE        : "<<nCliente->nombre;
	    cout<<"\n\tAPELLIDO      : "<<nCliente->apellido;
	    cout<<"\n\tHABITACION Nง : "<<nHabitacion->NoHabitacion;
	    cout<<"\n\tDIGITE CONSUMO: $ ";
	    cin>>cons;
	    nFacturacion->consumo =((nFacturacion->consumo) + cons);
	    nFacturacion->valorTotal =((nFacturacion->valorTotal) + cons);
	    sw=1;
	 }
	 nCliente = nCliente->sigC;
	 nFacturacion = nFacturacion->sigF;
	 nHabitacion = nHabitacion->sigH;
      }
      if(sw == 0)
      {
	 cout<<"\n\tEL CLIENTE NO ESTA REGISTRADO";
      }
  }
  getch();
}

//**************************************************************************
void facturaXcliente(CLista listac,HLista listah, FLista listaf)
{
   CNodo nCliente = listac;
   FLista nFacturacion = listaf;
   HNodo nHabitacion = listah;


   if(!listaf) cout<<"\n\n\tLISTA DE CLIENTES VACIA";
   else
   {
      clrscr();
      while(nFacturacion)
      {
	 cout<<"\nFACTURA Nง          : "<<nFacturacion->NoFactura;
	 cout<<"\nNOMBRE              : "<<nCliente->nombre;
	 cout<<"\nAPELLIDO            : "<<nCliente->apellido;
	 cout<<"\nHABITACION Nง       : "<<nHabitacion->NoHabitacion;
	 if(nHabitacion->tipo==1){
	    cout<<"\nTIPO                : HABITACION SENCILLA";
	 }
	 if(nHabitacion->tipo==2){
	    cout<<"\nTIPO                : HABITACION DE LUJO";
	 }
	 cout<<"\nVALOR HABITACION DIA: $ "<<nHabitacion->valor;
	 cout<<"\nNง DIAS             : "<<nFacturacion->NoDias;
	 cout<<"\nCONSUMO             : $ "<<nFacturacion->consumo;
	 cout<<"\nVALOR TOTAL         : $ "<<nFacturacion->valorTotal;
	 cout<<"\n/--------------------------------------/\n";
	 getch();
	 nCliente = nCliente->sigC;
	 nFacturacion = nFacturacion->sigF;
	 nHabitacion = nHabitacion->sigH;

      }

   }
   getch();
}

//*************************************************************************
void busqXcliente(CLista listac,HLista listah, char ape[])
{
   CNodo nCliente = listac;
   HNodo nHabitacion = listah;
   int sw=0;

   if(!listac) cout<<"\n\n\tLISTA DE CLIENTES VACIA";
   else
   {
      clrscr();
      while(nCliente)
      {
	 if(strcmp(ape,nCliente->apellido) == 0)
	 {
	    cout<<"\n\nHABITACION Nง :\t"<<nHabitacion->NoHabitacion;
	    cout<<"\nCEDULA        :\t"<<nCliente->cedula;
	    cout<<"\nNOMBRE        :\t"<<nCliente->nombre;
	    cout<<"\nAPELLIDO      :\t"<<nCliente->apellido;
	    cout<<"\nPROCEDENCIA   :\t"<<nCliente->procedencia;
	    cout<<"\nTELEFONO      :\t"<<nCliente->telefono;
	    cout<<"\n/--------------------------------------/\n";
	    getch();
	    sw=1;
	 }
	 nCliente = nCliente->sigC;
	 nHabitacion = nHabitacion->sigH;
      }
      if(sw == 0)
      {
	 cout<<"\n\tEl Cliente NO est  registrado";
      }
   }
   getch();
}

//*************************************************************************
void busqXhabit(CLista listac, HLista listah, FLista listaf, int hab)
{
   CNodo nCliente = listac;
   HNodo nHabitacion = listah;
   FLista nFacturacion = listaf;

   int sw=0;

   if(!listah) cout<<"\n\n\tLISTA DE HAB. VACIA";
   else
   {
      clrscr();
      while(nHabitacion)
      {
	 if(nHabitacion->NoHabitacion == hab)
	 {
	    cout<<"\nHABITACION Nง        : "<<nHabitacion->NoHabitacion;
	    cout<<"\n\nPISO                 : "<<nHabitacion->NoPiso;
	    cout<<"\nNOMBRE               : "<<nCliente->nombre;
	    cout<<"\nAPELLIDO             : "<<nCliente->apellido;
	    cout<<"\nCEDULA               : "<<nCliente->cedula;
	    if(nHabitacion->tipo==1){
	       cout<<"\nTIPO                 : HABITACION SENCILLA";
	    }
	    if(nHabitacion->tipo==2){
	       cout<<"\nTIPO                 : HABITACION DE LUJO";
	    }
	    cout<<"\nVALOR HABITACION DIA : $ "<<nHabitacion->valor;
	    cout<<"\nNง DIAS              : "<<nFacturacion->NoDias;
	    cout<<"\nCONSUMO              : $ "<<nFacturacion->consumo;
	    cout<<"\nVALOR TOTAL          : $ "<<nFacturacion->valorTotal;
	    sw=1;
	 }
	 nCliente = nCliente->sigC;
	 nFacturacion = nFacturacion->sigF;
	 nHabitacion = nHabitacion->sigH;
      }
      if(sw == 0)
      {
	 cout<<"\n\tHABITACION DESOCUPADA";
      }
   }
   getch();
}

//************************************************************************
void mostrar(CLista listac)
{
   CNodo nCliente = listac;
   int y=3;

   if(!listac) cout<<"\n\n\tLISTA DE CLIENTES VACIA";
   else
   {
      clrscr();
      gotoxy(1,1);  cout<<"CEDULA";
      gotoxy(10,1); cout<<"NOMBRE";
      gotoxy(20,1); cout<<"APELLIDO";
      gotoxy(30,1); cout<<"PROCEDENCIA";
      gotoxy(42,1); cout<<"TELEFONO";
      while(nCliente)
      {
	 gotoxy(1,y);  cout<<nCliente->cedula;
	 gotoxy(10,y); cout<<nCliente->nombre;
	 gotoxy(20,y); cout<<nCliente->apellido;
	 gotoxy(30,y); cout<<nCliente->procedencia;
	 gotoxy(42,y); cout<<nCliente->telefono;

	 nCliente = nCliente->sigC;
	 y++;
     }
   }
   getch();
}