// Tic Tac Toe
#include<iostream>
using namespace std;
#define size 3
//or can be defined as
//const int size=3;

char ar[size][size];
int count=0;
void initMatrix(){
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                ar[i][j]='_';
                }
              }
}
void dispMatrix(){
	for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
               		cout<<ar[i][j]<<"\t";
                }
                cout<<"\n\n";
        }
}
int validMatrix(int l){
	int i=0; //Checking Availablity
	//Generalising
	int loc=1;
	for(int j=0;j<size;j++){
		for(int k=0;k<size;k++){
			if(l==loc && ar[j][k]=='_')
				i=1;

			loc++;
		}
	}

	if(i==1)
		return true;
	else
		return false;
}
void editMatrix(int location,char x){
	//Generalising
	int loc=1;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(location==loc)
				ar[i][j]=x;

			loc++;
		}
	}

}
void won(char p){
	dispMatrix();
	cout<<"Player "<<p<<" Won!!\n";
	exit(0);
}

void checkMatrix(){
//Generalising Winning condition for size*size Matrix
int z=0;
char c='X';
	//Draw Condition
	if(count==(size*size)){
		cout<<"Match Draw\n\n";
		dispMatrix();
		exit(0);
	}
while(z<2){	
	if(z%2==0)
		c='X';
	else
		c='O';
	
	//Horizon
	int h=0;
	for(int i=0,j=0;i<size;i++,j++){
		for(int j=0;j<size;j++){		
			if(ar[i][j]==c)
				h++;
		}
		
		if(h==size)
			won(c);
		h=0;
	}
	
	//Vertical
	int v=0;
	for(int i=0,j=0;i<size;i++,j++){
		for(int j=0;j<size;j++){		
			if(ar[i][j]==c)
				v++;
		}
		
		if(v==size)
			won(c);
		v=0;
	}		

	//2 Diagon
	int ld=0;
		for(int i=0;i<size;i++)		
			if(ar[i][i]==c)
				ld++;
		if(ld==size)
			won(c);
	int rd=0;
		for(int i=0,j=size-1;i<size;i++,j--)		
			if(ar[i][j]==c)
				rd++;
		if(rd==size)
			won(c);

	   
z++;
}
}

void printMap(){
	int m=1;
	cout<<"\n";
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			cout<<"["<<m++<<"]\t";
	cout<<"\n";
	}
	cout<<endl;

}

int main(){
	//for n*n Matrix
	cout<<"Welcome to TicTacToev1.0 \n";

	int p=0;// Player's Turn
	int location=0;// Matrix Location
	
	//initializing Matrix	
	initMatrix();

	//User's Location Map
	printMap();

	//Taking Location Input From User
	while(count<(size*size)){
	if(p%2==0){
		p++;
		cout<<"Player X's turn:"<<endl;
		cin>>location;
		if(validMatrix(location) && location>=1 && location<=9)
			editMatrix(location,'X');
		else{
			count--;
			p--;
			cout<<"Enter Unoccupied Valid Location!!\n";
		}
	}
	else{
		p++;
		cout<<"Player O's turn"<<endl;
		cin>>location;
		if(validMatrix(location)  && location>=1 && location<=9)
                        editMatrix(location,'O');
                else{
                        count--;
                        p--;
                        cout<<"Enter Unoccupied Valid Location!!\n";
                }

	}
	count++;
	checkMatrix();	
	dispMatrix();	
	}

	return 0;
}
