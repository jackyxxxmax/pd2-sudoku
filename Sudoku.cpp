#include"Sudoku.h"

void Sudoku::giveQuestion(){
	ifstream infile("test1.txt");

	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			infile>>question[i][j];
		}
	}
	infile.close();
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			cout<<question[i][j];
			cout<<" ";
		}
	cout<<endl;
	}
}

void Sudoku::outputAns(){
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			cout<<map1[i][j];
			cout<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int Sudoku::test(int sudoku[][9],int row,int col,int fig){
	int i,j;
	for(i=0;i<9;++i){
		if((sudoku[row][i]==fig)||(sudoku[i][col]==fig)){ //checking in row and col
			return 0;
		}
	}

	int rowBegin=(row/3)*3; //checking in the grid
	int colBegin=(col/3)*3;
	for(i=rowBegin;i<(rowBegin+3);++i){
		for(j=colBegin;j<(colBegin+3);++j){
			if(sudoku[i][j]==fig){
				return 0;
			}
		}
	}
	return 1;
}

int Sudoku::try_1st(int sudoku[][9],int row,int col){
	int i;
	if(row<9&&col<9){
		if(sudoku[row][col]!=0){ //pre filled
			if((col+1)<9){
				return try_1st(sudoku,row,col+1);
			}
			else if((row+1)<9){
				return try_1st(sudoku,row+1,0);
			}
			else{
				return 1;
			}
		}
		else{
			for(i=0;i<9;++i){
				if(test(sudoku,row,col,i+1)){
					sudoku[row][col]=i+1;
					if((col+1)<9){
						if(try_1st(sudoku,row,col+1)){
							return 1;
						}
						else{
							sudoku[row][col]=0;
						}
					}
					else if((row+1)<9){
						if(try_1st(sudoku,row+1,0)){
							return 1;
						}
						else{
							sudoku[row][col]=0;
						}
					}
					else{
						return 1;
					}
				}
			}
		}
		return 0;
	}
	else{
		return 1;
	}
}

int Sudoku::try_2nd(int sudoku[][9],int row,int col){
	int i;
	if(row<9&&col<9){
		if(sudoku[row][col]!=0){ //pre filled
			if((col+1)<9){
				return try_2nd(sudoku,row,col+1);
			}
			else if((row+1)<9){
				return try_2nd(sudoku,row+1,0);
			}
			else{
				return 1;
			}
		}
		else{
			for(i=8;i>=0;i--){
				if(test(sudoku,row,col,i+1)){
					sudoku[row][col]=i+1;
					if((col+1)<9){
						if(try_2nd(sudoku,row,col+1)){
							return 1;
						}
						else{
							sudoku[row][col]=0;
						}
					}
					else if((row+1)<9){
						if(try_2nd(sudoku,row+1,0)){
							return 1;
						}
						else{
							sudoku[row][col]=0;
						}
					}
					else{
						return 1;
					}
				}
			}
		}
		return 0;
	}
	else{
		return 1;
	}
}

void Sudoku::solve(){
	int i,j;
	for(i=0;i<9;++i){
		for(j=0;j<9;++j){
			map2[i][j]=map1[i][j];
		}
	}
	if(try_1st(map1,0,0)){
		if(try_2nd(map2,0,0)){
			for(i=0;i<=8;i++){
				for(j=0;j<=8;j++){
					if(map1[i][j]!=map2[i][j]){ //相同代表唯一解
						cout<<"2"<<endl;
						exit(0);
					}
				}
			}
						cout<<"1"<<endl;
			for(i=0;i<=8;i++){
				for(j=0;j<=8;j++){
					cout<<map1[i][j];
					cout<<" ";
				}
				cout<<endl;
			}
		}
	}
	else cout<<"0"<<endl;
}

void Sudoku::readIn(){
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			cin>>map1[i][j];
		}
	}
}

void Sudoku::mapTobuffer(){ //將map寫入buffer
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			buffer[i][j]=map1[i][j];
		}
	}
}

void Sudoku::changeNum(int a,int b){
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			buffer[i][j]=map1[i][j];
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			if(map1[i][j]==a){map1[i][j]=b;}
			else if(map1[i][j]==b){map1[i][j]=a;}
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			buffer[i][j]=map1[i][j];
		}
	}
}

void Sudoku::changeRow(int a,int b){
	for(;;){
		if(a==0){
			int temp[9][9];
			for(int i=0;i<=2;i++){
				for(int j=0;j<=8;j++){
					temp[i][j]=map1[i][j];
				}
			}
			if(b==0){break;}
			else if(b==1){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=8;j++){
						map1[i][j]=map1[i+3][j];
						map1[i+3][j]=temp[i][j];
					}
				}
				break;
			}
			else if(b==2){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=8;j++){
						map1[i][j]=map1[i+6][j];
						map1[i+6][j]=temp[i][j];
					}
				}
				break;
			}
		}		
		if(a==1){
			int temp[9][9];
			for(int i=0;i<=2;i++){
				for(int j=0;j<=8;j++){
					temp[i][j]=map1[i+3][j];
				}
			}
			if(b==0){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=8;j++){
						map1[i+3][j]=map1[i][j];
						map1[i][j]=temp[i][j];
					}
				}
				break;
			}
			else if(b==1){break;}
			else if(b==2){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=8;j++){
						map1[i+3][j]=map1[i+6][j];
						map1[i+6][j]=temp[i][j];
					}
				}
				break;
			}
		}
		if(a==2){
			int temp[9][9];
			for(int i=0;i<=2;i++){
				for(int j=0;j<=8;j++){
					temp[i][j]=map1[i+6][j];
				}
			}
			if(b==0){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=8;j++){
						map1[i+6][j]=map1[i][j];
						map1[i][j]=temp[i][j];
					}
				}
				break;
			}
			else if(b==1){
				for(int i=0;i<=2;i++){
					for(int j=0;j<=8;j++){
						map1[i+6][j]=map1[i+3][j];
						map1[i+3][j]=temp[i][j];
					}
				}
				break;
			}
			else if(b==2){break;}
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			buffer[i][j]=map1[i][j];
		}
	}
}

void Sudoku::changeCol(int a,int b){
	for(;;){
		if(a==0){
			int temp[9][9];
			for(int i=0;i<=8;i++){
				for(int j=0;j<=2;j++){
					temp[i][j]=map1[i][j];
				}
			}
			if(b==0){break;}
			else if(b==1){
				for(int i=0;i<=8;i++){
					for(int j=0;j<=2;j++){
						map1[i][j]=map1[i][j+3];
						map1[i][j+3]=temp[i][j];
					}
				}
				break;
			}
			else if(b==2){
				for(int i=0;i<=8;i++){
					for(int j=0;j<=2;j++){
						map1[i][j]=map1[i][j+6];
						map1[i][j+6]=temp[i][j];
					}
				}
				break;
			}
		}		
		if(a==1){
			int temp[9][9];
			for(int i=0;i<=8;i++){
				for(int j=0;j<=2;j++){
					temp[i][j]=map1[i][j+3];
				}
			}
			if(b==0){
				for(int i=0;i<=8;i++){
					for(int j=0;j<=2;j++){
						map1[i][j+3]=map1[i][j];
						map1[i][j]=temp[i][j];
					}
				}
				break;
			}
			else if(b==1){break;}
			else if(b==2){
				for(int i=0;i<=8;i++){
					for(int j=0;j<=2;j++){
						map1[i][j+3]=map1[i][j+6];
						map1[i][j+6]=temp[i][j];
					}
				}
				break;
			}
		}
		if(a==2){
			int temp[9][9];
			for(int i=0;i<=8;i++){
				for(int j=0;j<=2;j++){
					temp[i][j]=map1[i][j+6];
				}
			}
			if(b==0){
				for(int i=0;i<=8;i++){
					for(int j=0;j<=2;j++){
						map1[i][j+6]=map1[i][j];
						map1[i][j]=temp[i][j];
					}
				}
				break;
			}
			else if(b==1){
				for(int i=0;i<=8;i++){
					for(int j=0;j<=2;j++){
						map1[i][j+6]=map1[i][j+3];
						map1[i][j+3]=temp[i][j];
					}
				}
				break;
			}
			else if(b==2){break;}
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			buffer[i][j]=map1[i][j];
		}
	}
}

void Sudoku::rotate(int n){
	for(;;){
		if(n==0){break;}
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				map1[i][j]=buffer[j+8-2*j][i];
			}
		}
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				buffer[i][j]=map1[i][j];
			}
		}
		if(n==1){break;}
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				map1[i][j]=buffer[j+8-2*j][i];
			}
		}
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				buffer[i][j]=map1[i][j];
			}
		}
		if(n==2){break;}
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				map1[i][j]=buffer[j+8-2*j][i];
			}
		}
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				buffer[i][j]=map1[i][j];
			}
		}
		if(n==3){break;}
	}
}

void Sudoku::flip(int n){
	if(n==0){
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				map1[i][j]=buffer[8-i][j];
			}
		}
	}
	else if(n==1){
		for(int i=0;i<=8;i++){
			for(int j=0;j<=8;j++){
				map1[i][j]=buffer[i][8-j];
			}
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			buffer[i][j]=map1[i][j];
		}
	}
}

void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}

void Sudoku::transform(){
	readIn();
	change();
}
