#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

class Sudoku{
	public:
		void giveQuestion();
		void outputAns();
		int test(int sudoku[][9],int row,int col,int fig);
		int try_1st(int sudoku[][9],int row,int col);
		int try_2nd(int sudoku[][9],int row,int col);
		void solve();
		void readIn();
		void mapTobuffer();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void change();
		void transform();
	private:
		int question[9][9];
		int buffer[9][9];
		int map1[9][9];
		int map2[9][9];
};
