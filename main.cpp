#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define ll long long

using namespace std;

double P_x(int n, double p, int x) {
	//returns P(X=x) = nCx (p)^x (1-p)^(1-x)
	if (x == 0)return pow(1 - p, n);

	if (x > n - x) x = n - x; 
	int nCx = 1;
	for (int i = 1; i <= x; i++) {
		nCx *= n - x + i;
		nCx /= i;
	}

	return double(nCx) * pow(p,x) * pow(1-p,n-x);
}
void BinomialVisualiser(int n, double p) {//n>0, p>0
	const string Unit = "@";
	const string EmptyUnit = ".";
	const string FilledBlock = "@@@@@@@|";
	const string EmptyBlock  = ".......|";
	const string Scale = "\n\t0.0\t0.1\t0.2\t0.3\t0.4\t0.5\t0.6\t0.7\t0.8\t0.9\t1.0\n\n"; 	//scale of probabilities
	const int TotalBlocks = 10; //size of grid in terms of blocks

	int TotalFilledBlocks; //Number of filled block = first decimal place of px if 0<px<1
	int TotalEmptyBlocks; //Number of filled block = first decimal place of px if 0<px<1

	int mode = p*(n+1);
	/*
		 p(n + 1) - 1 <= mode <= p(n + 1)
		 There is equality when $p(n + 1)$ is an integer -> 2 modes 
		- Binomial distribution has 1 or 2 modal values only.
	*/

	//Choose an appropriate scale
	//double GreatestProbability = P_x(n, p, mode);
	//const double BigInterval = GreatestProbability / 10;
	//const double SmallInterval = BigInterval / 8;
	cout << "\t\t\t X ¬ B (" << n << ", " << p << ")\n";
	cout << Scale;

	//can be optimised. No need to calculate both P_1 and P_{n-1}
	for (int x = 0;x <= n;x++) {
		string line = "x = " + to_string(x) + "\t |"; //line to be output
		double px = P_x(n, p, x); //P(X=x)

		TotalFilledBlocks = int(px*10);
		//add filled blocks
		for (int i = 0;i < TotalFilledBlocks;i++) {line += FilledBlock;}

		//remaining units 
		double remaining = px - double(TotalFilledBlocks) / double(10);
		int units = int(remaining * 8);
		if (units == 0) {
			TotalEmptyBlocks = TotalBlocks - TotalFilledBlocks;
		}
		else {
			//add remaining units
			for (int j = 0;j < 7;j++) {
				if (j < units) {line += Unit;}
				else {line += EmptyUnit;}
			}
			line += "|";
			TotalEmptyBlocks = TotalBlocks - TotalFilledBlocks - 1;
		}
		//add empty blocks
		for (int i = 0;i < TotalEmptyBlocks;i++) { line += EmptyBlock;}
		cout << line << "\n\n";
	}

	//add E(x), mode, Variance
}
int main() {
	//cout << P_x(10, 0.4, 0)<<"\n";
	BinomialVisualiser(5, 0.5);



	////smallest interval = 0.125
	cout << "\n\t0.0\t0.125\t0.250\t0.3\t0.4\t0.5\t0.6\t0.7\t0.8\t0.9\t1.0\n\n";
	cout << "x = 0\t |@@@@@@@|.......|.......|.......|.......|.......|.......|.......|.......|.......|\n\n";
	cout << "x = 1\t |@@@@@@@|@@@@@@@|@@@@...|.......|.......|.......|.......|.......|.......|.......|\n\n";
	cout << "x = 2\t |@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|.......|.......|.......|.......|.......|.......|\n\n";
	cout << "x = 3\t |@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|.......|.......|.......|.......|.......|\n\n";
	cout << "x = 4\t |@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|.......|.......|.......|.......|\n\n";
	cout << "x = 5\t |@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|.......|.......|.......|.......|.......|\n\n";
	cout << "x = 6\t |@@@@@@@|@@@@@@@|@@@@@@@|@@@@@@@|.......|.......|.......|.......|.......|.......|\n\n";
	cout << "x = 7\t |@@@@@@@|@@@@@@@|@@@@...|.......|.......|.......|.......|.......|.......|.......|\n\n";
	cout << "x = 8\t |@@@@@@@|.......|.......|.......|.......|.......|.......|.......|.......|.......|\n\n";

	system("pause");
}
