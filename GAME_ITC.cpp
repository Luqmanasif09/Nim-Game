#include<iostream>
using namespace std;
void my_intro(void);
void display_grid(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[]);
void menu(void);
void user_name(char player1[],char player2[]);
void play_game(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[],char player1[],char player2[]);
void menu2(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[],char player1[],char player2[]);
void display_after(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[],int pile1_count,int pile2_count,int pile3_count,int pile4_count,int pile5_count);
int main()
{
	char pile1[6]={"@@@@@"};
	char pile2[6]={"@@@@@"};
	char pile3[6]={"@@@@@"};
	char pile4[6]={"@@@@@"};
	char pile5[6]={"@@@@@"};
	char player1[20];
	char player2[20];
	my_intro();
	play_game(pile1,pile2,pile3,pile4,pile5,player1,player2);
}
void my_intro(void)
{
	cout<<"-------------------------------------\n";
	cout<<" |     Name : LUQMAN ASIF          |";
	cout<<endl<<" |    university : UCP             |";
	cout<<endl<<" |    Study : BSCS                 |";
	cout<<endl<<" |    contact no:03234520099       |";
	cout<<endl<<"------------------------------------\n";
}
void display_grid(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[])
{
	cout<<"\n\n*****         WELCOME TO NIM GAME      *****\n";
	cout<<" RULES ARE :\n> Nim is a 2 player game\n> where players take turns one by one \n> remove at least 1 stone from gird\n";
	cout<<"> Multiple stones may be removed  per turn\n> only from a single row from right end ";
	cout<<"\n\nGrid are :\n\n";

	cout<<"       --------------\n";
	cout<<"Pile 1 |  ";
	for(int i=0;pile1[i]!='\0';i++)
	{
		cout<<pile1[i]<<" ";
	}
	cout<<"|"<<endl;
	cout<<"Pile 2 |  ";
	for(int i=0;pile2[i]!='\0';i++)
	{
		cout<<pile2[i]<<" ";
	}
	cout<<"|"<<endl;
	cout<<"Pile 3 |  ";
	for(int i=0;pile3[i]!='\0';i++)
	{
		cout<<pile3[i]<<" ";
	}
	cout<<"|"<<endl;
	cout<<"pile 4 |  ";
	for(int i=0;pile4[i]!='\0';i++)
	{
		cout<<pile1[i]<<" ";
	}
	cout<<"|"<<endl;
      	cout<<"Pile 5 |  ";
	for(int i=0;pile5[i]!='\0';i++)
	{
		cout<<pile5[i]<<" ";
	}
	cout<<"|      ";
	cout<<"\n       --------------";
}
void menu(void)
{
	cout<<"\n Enter  1 to start a game ";
	cout<<"\n Enter  0 to exit a game ";
}
void user_name(char player1[],char player2[])
{
	cout<<"\nEnter a player 1 name : ";
	cin.ignore(1);
	cin.getline(player1,100);
	cout<<"Enter a player 2 name :  ";
	cin.ignore(1);
	cin.getline(player2,100);
}
void play_game(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[],char player1[],char player2[])
{
	int option=0;
	int win1=0;
	int win2=0;
	char s_b=0;
	menu();
	cout<<"\nEnter your option = ";
	cin>>option;
	if(option==1)
	{
	        user_name(player1,player2);
		display_grid(pile1,pile2,pile3,pile4,pile5);

		int select_pile;
		int pile1_count=5;
		int pile2_count=5;
		int pile3_count=5;
		int pile4_count=5;
		int pile5_count=5;
		int removed_stones=0;
		int remove_stone1=0;
		int remove_stone2=0;
		int remove_stone3=0;
		int remove_stone4=0;
		int remove_stone5=0;

		int total_stones=25;//we known total stone are 25,we use bcz running a loop
		while(total_stones>=1)
		{
			cout<<"\n\n"<<player1<<" : which pile do u want to remove stone : ";
			cin>>select_pile;
			while (select_pile < 1 || select_pile > 5 || 5 < select_pile)
 			{
				 cout <<"\n"<<player1<<" : is not a valid pile. Enter either ( 1 to 5 ) for the number piles: ";
				 cin >> select_pile;
			 }
			cout<<"\n\nHow much want to remove stone  in  pile "<<select_pile<<" : ";
			cin>>removed_stones;
			while (removed_stones < 1 || removed_stones > 5 || 5 < removed_stones)
 			{
				 cout <<"\n"<<player1<<" is not a valid stone. Enter either ( 1 to 5 )for the number of stones: ";
				 cin >>removed_stones;
			}
			if(select_pile==1)
			{
			      while(removed_stones>pile1_count)
               		      {
                  			 cout<<"enter again because in "<<pile1_count<<" remaining stone  = ";
                   			 cin>>removed_stones;
               		      }
				remove_stone1=removed_stones;
			}
			else if(select_pile==2)
			{
               			 while(removed_stones>pile2_count)
             		        {
                 			   cout<<"enter again because in "<<pile2_count<<"  remaining  stone in pile2  = ";
                    			   cin>>removed_stones;
                		}
				remove_stone2=removed_stones;
			}
			else if(select_pile==3)
			{
                		while(removed_stones>pile3_count)
               			{
                    			cout<<"enter again because in "<<pile3_count<<" remaining stone in pile 3  = ";
                   			 cin>>removed_stones;
               			 }
				remove_stone3=removed_stones;
			}
			else if(select_pile==4)
			{
                		while(removed_stones>pile4_count)
               		 	{
                 		   cout<<"enter again because in "<<pile4_count<<"  remaining  stone is pile4 = ";
                  		   cin>>removed_stones;
              		        }
				remove_stone4=removed_stones;
			}
			else if(select_pile==5)
			{
              			  while(removed_stones>pile5_count)
              			  {
                 			   cout<<"enter again because in "<<pile5_count<<"  remaining  stone in pile 5 = ";
                   			   cin>>removed_stones;
               			  }
				  remove_stone5=removed_stones;
			}
			total_stones=total_stones-removed_stones;

			pile1_count=pile1_count-remove_stone1;//to remove stone from piles
			pile2_count=pile2_count-remove_stone2;
			pile3_count=pile3_count-remove_stone3;
			pile4_count=pile4_count-remove_stone4;
			pile5_count=pile5_count-remove_stone5;
          	        
	 		display_after(pile1,pile2,pile3,pile4,pile5,pile1_count,pile2_count,pile3_count,pile4_count,pile5_count);
			if(total_stones==0)
        		{
            			cout<<"\n"<<player1<<" you are loss";
                     	 	win2++;
       			}
            		//NOW,PLAYER 2 TURN :
			//stone will be again zero beacuse now it's player 2 turn
			removed_stones=0;
			remove_stone1=0;
			remove_stone2=0;
			remove_stone3=0;
			remove_stone4=0;
			remove_stone5=0;

		if(total_stones>=1)
		{
			cout<<"\n\n"<<player2<<" : which pile do u want to remove stone : ";
			cin>>select_pile;
			while (select_pile < 1 || select_pile > 5 || 5 < select_pile)
 			{
				 cout <<"\n"<<player2<<" : is not a valid pile. Enter either ( 1 to 5 ) for the number piles: ";
				 cin >> select_pile;
			 }
			cout<<"\n\nHow much want to remove stone  in  pile "<<select_pile<<" : ";
			cin>>removed_stones;
			while (removed_stones < 1 || removed_stones > 5 || 5 < removed_stones)
 			{
				 cout <<"\n"<<player2<<" is not a valid stone. Enter either ( 1 to 5 )for the number of stones: ";
				 cin >>removed_stones;
			}
			if(select_pile==1)
			{
			     	while(removed_stones>pile1_count)
               			 {
                        		 cout<<"enter again because in "<<pile1_count<<"  remaining  stone in pile 1 = ";
                   			 cin>>removed_stones;
               			 }
				remove_stone1=removed_stones;
			}
			else if(select_pile==2)
			{
                		while(removed_stones>pile2_count)
               		        {
                    			cout<<"enter again because in "<<pile2_count<<"remaining  stone in pile 2 = ";
                   			 cin>>removed_stones;
              		        }
				remove_stone2=removed_stones;
			}
			else if(select_pile==3)
			{
               			 while(removed_stones>pile3_count)
               			 {
                   			 cout<<"enter again because in "<<pile3_count<<"  remaining stone in pile 3  = ";
                    			 cin>>removed_stones;
              		         }

				 remove_stone3=removed_stones;
			}
			else if(select_pile==4)
			{
               			 while(removed_stones>pile4_count)
              			 {
                  			  cout<<"enter again because in "<<pile4_count<<"  remaining  stone in pile 4  = ";
                    			  cin>>removed_stones;
              		         }
				remove_stone4=removed_stones;
			}
			else if(select_pile==5)
			{
               			 while(removed_stones>pile5_count)
               			 {
                 			   cout<<"enter again because in "<<pile5_count<<"  remaining stone in pile 5 = ";
                    			   cin>>removed_stones;
              		         }
				remove_stone5=removed_stones;
			}


			total_stones=total_stones-removed_stones;

			pile1_count=pile1_count-remove_stone1;//to remove stone from piles
			pile2_count=pile2_count-remove_stone2;
			pile3_count=pile3_count-remove_stone3;

			pile4_count=pile4_count-remove_stone4;
			pile5_count=pile5_count-remove_stone5;
          
			display_after(pile1,pile2,pile3,pile4,pile5,pile1_count,pile2_count,pile3_count,pile4_count,pile5_count);


			removed_stones=0;
			remove_stone1=0;
			remove_stone2=0;
			remove_stone3=0;
			remove_stone4=0;
			remove_stone5=0;
			if(total_stones==0)
          		{
                   		 cout<<"\n"<<player2<<" you are loss";
                  		  win1++;
            	        }
          	  }
      	     }
	}
	cout<<"\nEnter 's' to show score_board : ";
	cin>>s_b;
	if(s_b=='s'||s_b=='S')
        {
             cout<<endl<<endl<<"	SCORE_BOARD         \n"<<player1<<"		|	"<<player2<<endl<<endl;
             cout<<win1<<"           |       "<<win2;
        }
	
	if(option==0)
	{
		cout<<"You EXIT  a game ";
	}
	menu2(pile1,pile2,pile3,pile4,pile5,player1,player2);
}
void display_after(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[],int pile1_count,int pile2_count,int pile3_count,int pile4_count,int pile5_count)
{
	cout<<endl;
	cout<<"       --------------\n";
	cout<<"Pile 1  ";
	for(int i=0;i<pile1_count;i++)
	{
		cout<<pile1[i]<<" ";
	}
	cout<<endl;
	cout<<"Pile 2  ";
	for(int i=0;i<pile2_count;i++)
	{
		cout<<pile2[i]<<" ";
	}
	cout<<endl;
	cout<<"Pile 3  ";
	for(int i=0;i<pile3_count;i++)
	{
		cout<<pile3[i]<<" ";
	}
	cout<<endl;
	cout<<"pile 4  ";
	for(int i=0;i<pile4_count;i++)
	{
		cout<<pile1[i]<<" ";
	}
	cout<<endl;
        cout<<"Pile 5  ";
	for(int i=0;i<pile5_count;i++)
	{
		cout<<pile5[i]<<" ";
	}
	cout<<endl;
	cout<<"\n       --------------";
}
void menu2(char pile1[],char pile2[],char pile3[],char pile4[],char pile5[],char player1[],char player2[])
{
	char select;
	cout<<"\n\nIf u want to play a game again:\n\nEnter 'y' to play \n\nenter 'N' to exit\nEnter your option = ";
	cin>>select;
	if(select=='y'||select=='Y')
	{
		cout<<"You play again "<<endl<<endl;
		play_game(pile1,pile2,pile3,pile4,pile5,player1,player2);
		
	}
	else if(select=='n'||select=='N')
	{
		cout<<"\n\nYOu exit a game";

	}
}		
