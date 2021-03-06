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
	cout<<"Player "<<p<<" Won!!\n";
	dispMatrix();
	exit(0);
}

void checkMatrix(){
//Generalising Winning condition for size*size Matrix
int z=0;
char c='X';
	//Draw Condition
	if(count==9){
		cout<<"Draw\n\n";
		exit(0);}
while(z<2){	
	if(z%2==0)
		c='X';
	else
		c='O';
	
	//Horizon
	
	for(int i=0,j=0;i<size;i++){
		if(ar[i][j]==c && ar[i][++j]==c && ar[i][++j]==c)
			won(c);
	j=0;
	}
	
	//Vertical
	for(int i=0,j=0;i<size;i++){
		if(ar[j][i]==c && ar[++j][i]==c && ar[++j][i]==c)
			won(c);
	j=0;
	}

	//2 Diagon
		if(ar[0][0]==c && ar[1][1]==c && ar[2][2]==c)
			won(c);
		else if(ar[0][2]==c && ar[1][1]==c && ar[2][0]==c)
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
	//for 3*3 Matrix
	cout<<"Welcome to TTTv1.0 \n";

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
		if(validMatrix(location))
			editMatrix(location,'X');
		else{
			count--;
			p--;
			cout<<"Enter Unoccupied Location!!\n";
		}
	}
	else{
		p++;
		cout<<"Player O's turn"<<endl;
		cin>>location;
		if(validMatrix(location))
                        editMatrix(location,'O');
                else{
                        count--;
                        p--;
                        cout<<"Enter Unoccupied Location!!\n";
                }

	}
	count++;
	checkMatrix();	
	dispMatrix();	
	}

	return 0;
}
