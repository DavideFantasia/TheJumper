#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string>
using namespace std;
char retry='y';
int score=0, highscore=0;
string nome="G1";
main()
{

	system("title Jump");
	system("color 02");
	
    cout <<endl;
  	
  	//titolo
    cout <<"\t\t\t*****  *   *  ** **  *****\n";
    cout <<"\t\t\t    *  *   *  * * *  *   *\n";
    cout <<"\t\t\t    *  *   *  *   *  *****\n";
    cout <<"\t\t\t*   *  *   *  *   *  *    \n";
    cout <<"\t\t\t*****  *****  *   *  *    \n\n";
    
    cout <<"You can move right using D, left using A, jump using SPACE, use K for a kick with A or D for direct it\n";
    cout<<"Use your kick for kill the enemy and collect the coin all around the map";
    cout <<endl;
    
    cout<<"\tINSERISCI UN NOME UTENTE\n";
    cin>>nome;
     
    
while (retry=='y' || retry == 'Y')
{
	srand(time(NULL));
	int round=0;		//più in un clock interno per i refresh 
	score=0;
	int life=3;			//inizi vite
    int enemylife=3;	//inizi vite nemico
    int xpunto, ypunto;
    int giro=0; //indica il lato di percorrenza della navicella

	ypunto=(rand()-1)%17+1;
    xpunto=(rand()-1)%18+1;
    int x[10];//supponi che la lunghezza del sprite non sia superiore a 10
    int y[10];
    x[0]=9;//posizionamento del serpente
    y[0]=18;
    int nave=10;           //array movimento della nave, indica la posizione nell'asse delle X
    int passi=0;
	int object=10;
    int ular=1;	//prima era 3
    string a[20][20];//larghezza della mappa
    int preclife=life;
    char ctr='p';//movimento iniziale del serpente
	char prec;
	
	while (score<object)	//obbiettivo
    {
    	if(life==0)	//controllo per vite
        {
        	break;
		}
	prec=ctr;
    ctr='p';
    cout<<"your life = "<<life<<"\t\tGiocatore: "<<nome<<endl;
    cout<<"enemy life = "<<enemylife<<endl;
    cout<<"score = "<<score<<endl;
    cout<<"object = "<<object<<endl;
        for (int i=0;i<20;i++)
        {
            for (int j=0;j<20;j++)
            {

                if (i==19)
                     a[i][j]="* ";//bordo di stampa
                else if(i==0)
                	a[i][j]="__";                	
                else if (j==0 || j==19)
                	a[i][j]="|";//muri laterali
                	
                	
                else if(i==16 && j==17) //piattaforma 1
                	a[i][j]="**";
                else if(i==16 && j==18) //piattaforma 1
                	a[i][j]="**";
                	
                	
                else if(i==14 && j==15) // piattaforma 2
                {
                	a[i][j]="**";
                }
                else if(i==14 && j==16) // piattaforma 2
                {
                	a[i][j]="**";
                }
                
                else if(i==17 && j==1)	//piattaforma 3
                {
                	a[i][j]="**";
                }
                else if(i==17 && j==2)	//piattaforma 3
                {
                	a[i][j]="**";
                }
                else if(i==14 && j==4) //piattaforma 4
                {
                	a[i][j]="**";
				}
				else if(i==14 && j==3) //piattaforma 4
                {
                	a[i][j]="**";
				}
				else if(i==12 && (j==6 || j==7 || j==8 || j==9 || j==10 || j==11 || j==12 || j==13))	//piattaforma centrale
				{
					a[i][j]="**";
				}
				else if(i==9 && j==14)	//piattaforma laterale piccola
				{
					a[i][j]="**";
				}
				else if(i==9 && j==5)	//piattaforma laterale piccola 2
				{
					a[i][j]="**";
				}
				else if(i==7 && j==15)	//piattaforma laterale piccola 3
				{
					a[i][j]="**";
				}
				else if(i==7 && j==4)	//piattaforma laterale piccola 4
				{
					a[i][j]="**";
				}
				else if(i==5 && (j==3 || j==2 || j==1))	//piattaforma laterale
				{
					a[i][j]="**";
				}
				else if(i==5 && (j==16 || j==17 || j==18))	//piattaforma laterale 2
				{
					a[i][j]="**";
				}
                else
                     a[i][j]="  ";//strada
            }
        }
        
        a[ypunto][xpunto]="O "; //moneta
        
        if(y[0]!=18)	//gravità
		{
			y[0]=y[0]+1;	
		}
		
		//gravità delle piattaforme
        if(x[0]==17 && y[0]==16)	//piattaforma 1
        {
        	y[0]--;
        }
        if(x[0]==18 && y[0]==16)	//piattaforma 1
        {
        	y[0]--;
		}
        if(x[0]==15 && y[0]==14)	//piattaforma 2
        {
        	y[0]--;
        }
        if(x[0]==16 && y[0]==14)	//piattaforma 2
        {
        	y[0]--;
        }
        
        if(y[0]==17 && x[0]==1)	//piattaforma 3
        {
        	y[0]--;
		}
        if(y[0]==17 && x[0]==2)	//piattaforma 3
        {
        	y[0]--;
		}
		
        if(y[0]==14 && x[0]==3)	//piattaforma 4
        {
        	y[0]--;
		}
		if(y[0]==14 && x[0]==4)	//piattaforma 4
        {
        	y[0]--;
		}
		if(y[0]==12 && (x[0]==6 || x[0]==7 || x[0]==8 || x[0]==9 || x[0]==10 || x[0]==11 || x[0]==12 || x[0]==13)) //piattaforma centrale
        {
        	y[0]--;
		}
        if(y[0]==9 && x[0]==14)	//piattaforma laterale piccola
				{
					y[0]--;
				}
		if(y[0]==9 && x[0]==5)	//piattaforma laterale piccola 2
			{
				y[0]--;
			}
				 if(y[0]==7 && x[0]==15)	//piattaforma laterale piccola 3
				{
					y[0]--;
				}
				if(y[0]==7 && x[0]==4)	//piattaforma laterale piccola 4
				{
					y[0]--;
				}
		if(y[0]==5 && (x[0]==1 || x[0]==2 || x[0]==3))	//piattaforma laterale
        {
			y[0]--;
		}
        
         if(y[0]==5 && (x[0]==16 || x[0]==17 || x[0]==18))	//piattaforma laterale 2
        {
			y[0]--;
		}
		
		
		
		
		
        
        //NEMICO
        
        
        
        
        
        
        
        if(enemylife==2 || enemylife==3)
        a[1][nave]="<>";	//sprite
        else if(enemylife==1)
        a[1][nave]="< ";
        else
        a[1][nave]="  ";
        
        
    if(giro==0)	//se il giro è da sinistra verso destra
    {
        if(enemylife==3)	//controllo vite del minion, in base alla fase va più veloce o più lento
        {
        	if(passi==9)
        	{
        		nave++;
        		passi=0;
			}
		}else if(enemylife==2)
		{
			if(passi==6)
			{
				nave++;
				passi=0;
			}
		}else if(enemylife==1)
		{
			if(passi==3)
			{
				nave++;
				passi=0;
			}
		}
	}else if(giro==1)	//se il giro è da sinistra verso destra
	{
		if(enemylife==3)	//controllo vite del minion
        {
        	if(passi==9)
        	{
        		nave--;
        		passi=0;
			}
		}else if(enemylife==2)
		{
			if(passi==6)
			{
				nave--;
				passi=0;
			}
		}else if(enemylife==1)
		{
			if(passi==3)
			{
				nave--;
				passi=0;
			}
		}
	}
		if(nave==18)
		{
			giro++;
			nave--;
		}
		else if(nave==1)
		{
			giro--;
			nave++;
		}
		
		
        passi++;
        
                
        if(y[0]==1 && x[0]==nave)		//punti vita in meno se si tocca la navicella
        {
        	life--;
		}
        
        
        for(int s=ular;s>0;s--)
        {
            x[s]=x[s-1];//in modo che il corpo e la coda seguano la testa
            y[s]=y[s-1];
        }
        for (int r=0;r<=ular;r++)	//assegnazione forma dello sprite
        {
            a[y[r]][x[r]]="[]";
        }
        if (kbhit())//richiesta di input w, a, s, d per il movimento del serpente
        {
            ctr=getch();
        }
       
        if(ctr=='a')
            x[0]--;
        if(ctr=='d')
            x[0]++;
        if(ctr=='k')	//pugno
        {
        	for (int r=0;r<=ular;r++)
        	{
        	if(prec=='d')
                         a[y[r]][x[r]]="[]o";	//pugno direzionato a sinistra
            else if(prec=='a')
                 a[y[r]][x[r]]="o[]";	//pugno direzionato a destra
       		}	
		}
		if(ctr==' ')
		{
			if(prec==' ')	//per evitare che il salto venga ripetuto troppo
			{
				goto controllo;
			}
			y[0]=y[0]-4;
			
		}
        controllo:
        //controllo delle posizioni dello sprite
        
        if(x[0]==0) //controllo di posizione a sinistra della mappa
    	{
    		x[0]++;
		}
		if(x[0]==19)
		{
			x[0]--;
		}
		
		
		if(((x[0]-1==nave)||(x[0]+1==nave))&&ctr=='k')	//punti di vita in meno se si tocca la navicella
		{
			enemylife--;
		}
		
        // 

        
        for(int m=0;m<20;m++)
        {
            for (int n=0;n<20;n++)
            {
                cout << a[m][n]; //stampa gioco
                
            }
        cout <<endl;
        
        if(preclife>life)		//respawn
            {
            	x[0]=9;
            	y[0]=18;
			}
        }
        preclife=life;
        
        
        if (x[0]==xpunto && y[0]==ypunto)
        {
        	score++;
        	a[ypunto][xpunto]=' ';
        	
        	xpunto=rand()%17;
        	ypunto=rand()%17+1;
		}
		
    round++;   
        for (int gh=1;gh<ular;gh++) //morte del serpente
        {
            if (x[0]==x[gh] && y[0]==y[gh])
            {
                x[0]=0;
            }
        }
        
        
    Sleep(100); //tempo tra ogni ricaricamento
    system("cls");	//pulitura della chat
	}
	if(life==0)
	{
	 cout << "\n\t\t\t\tGAMEOVER!\n" <<endl;
	 cout<<"\t\t\t\t"<<nome<<" ha perso"<<endl;
    }
	else if(score>=3)
	cout<<"\n\t\t\t\tYOU WON!\n"<<endl;
    cout << "\t\t\t\tScore = " << score<<"\n"<<endl;
    if (score > highscore)
    {
        highscore=score;
    }
    
    cout << "\t\t\t\tHigh Score = "<<highscore<<"\n"<<endl;
    cout << "\t\t\t\tretry (y/n)"; cin >>retry;
}
	return 0;
}




