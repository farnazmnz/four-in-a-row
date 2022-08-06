#include <iostream>
#include <stdlib.h>
#include <string> 
#include <math.h> 
#include <fstream>

using namespace std;
int height,width,piece;
//draws the board which uses board_info. if element of matrix is 0, empty and prints "    ". if it is 1,player one and prints 'X' .if it is 2,player 2  and prints 'O'.
void draw_board();
//indicates where is the piece of player and check which row of column should be. 
void player_movement(int player,string player_name);
//it checks who is winner by checking(vertical,horizontal,diagonals)
bool check_for_winner(int x,int y,int player);
//check if we have [for example] a four connected southwest to northeast line.
bool check_diagonal_SW_NE(int x,int y,int player);
//check if we have a four connected northwest to southeast line.
bool check_diagonal_NW_SE(int x,int y,int player);
//check if we have a four connected in a column.
bool check_vertical(int x,int y,int player);
//check if we have a four connected in a row.
bool check_horizontal(int x,int y,int player);
//compute the score of winner.
int compute_score(int m,int n,int p);
//the board's info which contain player's number(height as a row, width as a column)
int board_info[1000][1000];
					
void draw_new_board(){ system("CLS");
                	cout<<"\n\n\n";
	            	cout<<"\t\t";
	            	cout<<endl;
	            	cout<<"\t";
					for(int i=1;i<=width;i++){ 
	            cout<<" "<<i<<"  ";}
	            cout<<endl;
	            for(int y=0; y<height ;y++){
            	cout<<"\t";
         	for(int x=0; x<width+1 ;x++){
  	     	cout<<"| ";
  	    	if(board_info[y][x]==0)  cout<<"  ";
  		    else if(board_info[y][x]==1) cout<<"X ";
  		     else if(board_info[y][x]==2) cout<<"O ";
	  }
	  cout<<endl;
	}
}      
       
//store last movement							   
int lastmoveX ,lastmoveY;
//store player's name
string player1_name,player2_name;

int main(){
	int option;
	cout<<"1.start"<<endl<<"2.setting"<<endl<<"3.record"<<endl<<"4.exit"<<endl;
	cin>>option;
  switch(option){
  	case 1: 
  		{ system("CLS");
  		ofstream myfile;
  		myfile.open ("winner.txt",fstream::app);
  		height=6;
  		
  		width=7;
  		
  		piece=4;
  		
  		
		int counter=0;
  		bool winner =false;
  		int counter_player1,counter_player2,score;
  		cout<<"name of player 1:";
  		cin>>player1_name;
  		cout<<"name of player 2:";
  		cin>>player2_name;
  		draw_board();
  		 counter_player1=0;
	   counter_player2=0; 
		
  		for(int i=0;i<21;i++)
  		{  counter_player1++;
  		player_movement(1,player1_name);
  		draw_board();
        winner=check_for_winner(lastmoveX,lastmoveY,1);
        	height=6;
  		
  		width=7;
  		
  		piece=4;
  		
		 if(winner)
		 { score=compute_score(7,6,counter_player1);
		 cout<<"\n you win"<<" "<<player1_name<<endl;
		 cout<<"\n your score is :"<<score<<"\n";
		 myfile<<player1_name<<" "<<score<<" "<<"\n";
		 cout<<"\n";
		 myfile.close();
		 break;
		 }
		  
		 
		counter_player2++;
		player_movement(2,player2_name);
  		draw_board();
        winner=check_for_winner(lastmoveX,lastmoveY,2);
        	height=6;
  		
  		width=7;
  		
  		piece=4;
  		
		 if(winner)
		 { score=compute_score(7,6,counter_player2);
		 cout<<"\n you win"<<" "<<player2_name<<endl;
		 cout<<"\n your score is :"<<score<<"\n";
		 myfile<<player2_name<<" "<<score<<" "<<"\n";
		 cout<<"\n";
		  myfile.close();
		 break;
		 }	   		
		  }
		  system("PAUSE");
		  break;
		  }
	case 2:
	    {   system("CLS");
	    int setting_option;
	     cout<<"1.height of board: 6"<<endl<<"2.width of board: 7"<<endl<<"3.connected pieces: 4"<<endl<<"4.change these items"<<endl<<"5.back to menu"<<endl;;
	     cin>>setting_option;
	    switch(setting_option){
		
	      case 4: {
	
		        cout<<"new height of board :";
	            cin>>height;
	            cout<<endl<<"new width of board :";
	            cin>>width;
	            cout<<endl<<"new connected pieces :";
	            cin>>piece;
	            {
				 system("CLS");
  		ofstream myfile;
  		myfile.open ("winner.txt",fstream::app);
  		int counter=0;
		 
  		bool winner =false;
  		int counter_player1,counter_player2,score;
  		cout<<"name of player 1:";
  		cin>>player1_name;
  		cout<<"name of player 2:";
  		cin>>player2_name;
  		draw_new_board();
	   counter_player1=0;
	   counter_player2=0;         
	for(int i=0;i<(width*height)/2;i++){
		counter_player1++; 
  		player_movement(1,player1_name);
		draw_new_board();
	winner=check_for_winner(lastmoveX,lastmoveY,1);
		 if(winner)
		 { score=compute_score(width,height,counter_player1);
		 cout<<"\n you win"<<" "<<player1_name<<endl;
		 cout<<"\n your score is :"<<score<<"\n";
		 myfile<<player1_name<<" "<<score<<" "<<"\n";
		 cout<<"\n";
		 myfile.close();
		 break;
		 }
		 
	  
		counter_player2++;
		player_movement(2,player2_name);
  			draw_new_board();
        winner=check_for_winner(lastmoveX,lastmoveY,2);
		 if(winner)
		 { score=compute_score(width,height,counter_player2);
		 cout<<"\n you win"<<" "<<player2_name<<endl;
		 cout<<"\n your score is :"<<score<<"\n";
		 myfile<<player2_name<<" "<<score<<" "<<"\n";
		 cout<<"\n";
		  myfile.close();
		 break;
		 }
		 }	  system("PAUSE");}
		  break;
		  }  		
	            
			
	        
	       case 5:
	     	{ system("CLS");
	     	 main();
			 break;	
			 }
	     
		 cin>>setting_option;
	     switch(setting_option){
	     case 5:
	     	{ system("CLS");
	     	 main();
			 break;	
			 } 
			 break;}
	     default:     cout<<"error"<<endl; 
break;	} 
	break;
}
	case 3:
			{   system("CLS");
				int record_option;
				cout<<"1.show record"<<endl<<"2.back to menu"<<endl;
	             cin>>record_option;
	             switch(record_option){
				case 1:{
				
		 string player_name;
		 int score;
		   ifstream myfile;
		   myfile.open("winner.txt");
		  
		  while(getline(myfile,player_name)){
		  	 cout<<player_name<<" "<<score<<"\n";
		  }
		   myfile.close();
		  
		   
		 break;  
		
		}
		 case 2:{system("CLS");
	     	 main();
				break;
			   }}
		cin>>record_option;
	             switch(record_option){
				 
		       case 2:{system("CLS");
	     	 main();
				break; 
			   }
	      	}
			   break;}
	case 4:   {  system("EXIT");
	} 
} 
  
  
return 0;
}
int compute_score(int n,int m,int p){
	int score;
	  score=pow(m,n)/p;
	  return score;
}
void draw_board(){
	int height=6;
	int width=7;
	int piece=4;
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\t\tplease select a number from (1-7)"<<endl;
	cout<<endl; 
	cout<<"\t\t| 1 | 2 | 3 | 4 | 5 | 6 | 7 |"<<endl;
	cout<<"\t\t-----------------------------";
	cout<<endl; 
  for(int y=0; y<height ;y++){
  	cout<<"\t\t";
  	for(int x=0; x<width+1 ;x++){
  		cout<<"| ";
  		if(board_info[y][x]==0)  cout<<"  ";
  		else if(board_info[y][x]==1) cout<<"X ";
  		else if(board_info[y][x]==2) cout<<"O ";
	  }
	  cout<<endl;
  }
}
void player_movement(int player,string player_name)
{  int choice;
   cout<<"\n\t"<<player_name<<" "<<"it's your turn, ";
   cin>>choice;
   
   while (choice>width || choice<=0){
   	cout<<"\nplease select again:";
   	cin>>choice;
   }
   int number=0;
   while(board_info[(height-1)-number][choice-1]!=0){
   	number++;
   	if(number>(height-1)){
   	cout<<"\nplease select again:"; 
   	cin>>choice;
	   number=0; //you must reset the number else it will start at the begining of array	
	   }
   }
   board_info[(height-1)-number][choice-1]=player;
   lastmoveY=(height-1)-number;   
   lastmoveX=choice-1;
}
bool check_for_winner(int x,int y,int player)
{
	bool winner;
	if (check_diagonal_SW_NE(x,y,player)) return true;
	else if (check_diagonal_NW_SE(x,y,player)) return true;
	else if (check_vertical(x,y,player)) return true;
	else if (check_horizontal(x,y,player)) return true;
	else return false;
}
bool check_diagonal_SW_NE(int x,int y,int player)
{
	int score=1;
	int count=1;
	while((y-count>=0)&&(x+count<width)){
		if (board_info[y-count][x+count]==player)//check sw to ne
		{
			score++;
			count++;
		}
		else break; //if no combo is detected break from loop.
	}
	count=1;
	while((y+count<height)&&(x-count>=0))
	{  if( board_info[y+count][x-count]==player)//check ne to sw
	{
		score++;
		count++;
	}
	else break;
	}
	if(score==piece) return true;
	else return false;
}
bool check_diagonal_NW_SE(int x,int y,int player){
	int score=1;
	int count=1;
	while((y+count>=0)&&(x+count<width)){
		if(board_info[y+count][x+count]==player)//check nw to se
		{
			score++;
			count++;
		}
		else break;
	}
	count=1;
	while((y-count<height)&&(x-count>=0)){
		if(board_info[y-count][x-count]==player)//check se to nw
		{
			score++;
			count++;
		}
		else break;
	}
	if(score==piece) return true; 
	else return false;
}
bool check_vertical(int x,int y,int player){
	int score=1;
	int count=1;
	
	while((y+count>=0)&&(y+count<height)){
		if(board_info[y+count][x]==player)//check down
		{
			score++;
			count++;
		}
		else break;
	}
	if(score==piece) return true;
	else return false; 
}
bool check_horizontal(int x,int y,int player){
	int score=1; 
	int count=1;
	while((x+count>=0)&&(x+count<width)){
		if(board_info[y][x+count]==player)//check left
		{
			score++;
			count++;
		}
		else break;
	}
	count=1;
	while((x-count<width)&&(x-count>=0)){
		if(board_info[y][x-count]==player)//check right
		{
			score++; 
			count++;
		}
		else break;
	}
	if(score==piece) return true;
	else return false;
}

 
