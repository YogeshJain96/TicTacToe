// Tic Tac Toe
#include<iostream>
using namespace std;

char ar[3][3];
int count=0;
void initMatrix(){
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                ar[i][j]='_';
                }
              }
}
void dispMatrix(){
	for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
               		cout<<ar[i][j]<<"\t";
                }
                cout<<"\n\n";
        }
}
int validMatrix(int l){
	int i=0; //Checking Availablity
	
	if(l==1 && ar[0][0]=='_')
		i=1;
	else if(l==2 && ar[0][1]=='_')
		i=1;
	else if(l==3 && ar[0][2]=='_')
		i=1;
	else if(l==4 && ar[1][0]=='_')
		i=1;
	else if(l==5 && ar[1][1]=='_')
		i=1;
	else if(l==6 && ar[1][2]=='_')
		i=1;
	else if(l==7 && ar[2][0]=='_')
		i=1;
	else if(l==8 && ar[2][1]=='_')
		i=1;
	else if(l==9 && ar[2][2]=='_')
		i=1;
	else i=0;
	
	//---------------------------------

	if(i==1)
		return true;
	else
		return false;
}
void editMatrix(int location,char x){
        if(location==1)
                ar[0][0]=x;
	else if(location==2)
		 ar[0][1]=x;
	else if(location==3)
                 ar[0][2]=x;
	else if(location==4)
                 ar[1][0]=x;
	else if(location==5)
                 ar[1][1]=x;
	else if(location==6)
                 ar[1][2]=x;
	else if(location==7)
                 ar[2][0]=x;
	else if(location==8)
                 ar[2][1]=x;
	else if(location==9)
                 ar[2][2]=x;
	else
		cout<<"Enter Valid Location!";
		}

void won(char p){
	cout<<"Player "<<p<<" Won!!\n";
	dispMatrix();
	exit(0);
}

void checkMatrix(){
//8WaystoWin 3Horiz 3Vert 2Diagon

/*00--01--02
 *10--11--12
 *20--21--22*/
	
	//3Horizon
		if(ar[0][0]=='X' && ar[0][1]=='X' && ar[0][2]=='X')
			won('X');
		else if(ar[1][0]=='X' && ar[1][1]=='X' && ar[1][2]=='X')
			won('X');
		else if(ar[2][0]=='X' && ar[1][1]=='X' && ar[2][2]=='X')
			won('X');
	//3Verti
		else if(ar[0][0]=='X' && ar[1][0]=='X' && ar[2][0]=='X')
			won('X');
		else if(ar[0][1]=='X' && ar[1][1]=='X' && ar[2][1]=='X')
			won('X');
		else if(ar[0][2]=='X' && ar[1][2]=='X' && ar[2][2]=='X')
			won('X');
	//2 Diagon
		else if(ar[0][0]=='X' && ar[1][1]=='X' && ar[2][2]=='X')
			won('X');
		else if(ar[0][2]=='X' && ar[1][1]=='X' && ar[2][0]=='X')
			won('X');
//------------------------------------------------------------------------------------
	//3Horizon
		if(ar[0][0]=='O' && ar[0][1]=='O' && ar[0][2]=='O')
			won('O');
		else if(ar[1][0]=='O' && ar[1][1]=='O' && ar[1][2]=='O')
			won('O');
		else if(ar[2][0]=='O' && ar[1][1]=='O' && ar[2][2]=='O')
			won('O');
	//3Verti
		else if(ar[0][0]=='O' && ar[1][0]=='O' && ar[2][0]=='O')
			won('O');
		else if(ar[0][1]=='O' && ar[1][1]=='O' && ar[2][1]=='O')
			won('O');
		else if(ar[0][2]=='O' && ar[1][2]=='O' && ar[2][2]=='O')
			won('O');
	//2 Diagon
		else if(ar[0][0]=='O' && ar[1][1]=='O' && ar[2][2]=='O')
			won('O');
		else if(ar[0][2]=='O' && ar[1][1]=='O' && ar[2][0]=='O')
			won('O');
		else if(count==9){
			cout<<"Draw\n\n";
			exit(0);}
		else 
			;

}

int main(){
	//for 3*3 Matrix
	cout<<"Welcome to TTTv1.0 \n";

	int p=0;// Player's Turn
	int location=0;// Matrix Location
	initMatrix();
	//User's Location Map
	cout<<"\n1-\t-2-\t-3\n4-\t-5-\t-6\n7-\t-8-\t-9\n \nEnter Location's \n";

	//Taking Location Input From User
	while(count<9){
	if(p%2==0){
		p++;
		cout<<"Player X's turn:"<<endl;
		cin>>location;
		if(validMatrix(location))
			editMatrix(location,'X');
		else{
			count--;
			p--;
			cout<<"Enter Unoccupied Location!!"
		}
	}
	else{
		p++;
		cout<<"Player O's turn"<<endl;
		cin>>location;
		editMatrix(location,'O');
	}
	count++;
	checkMatrix();	
	dispMatrix();	
	}

	return 0;
}



