#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

long double P_x(const int n, const long double p, const int x) {
	//returns P(X=x) = nCx (p)^x (1-p)^(1-x)
	if (x == 0)return pow(1 - p, n);
	int k=x;
	if (x > n - x) k = n - x; 
	long long nCx = 1;
	for (long long i = 1; i <= k; i++) {
		nCx *= n - k + i;
		nCx /= i;
	}

	return long double(nCx) * pow(p,x) * pow(1-p,n-x);
}
void ProbabilityTable(int n, long double p) {
	cout << "x\t P(X=x)\n";
	for (int x = 0;x <= n;x++) {
		string line = to_string(x) + "\t"; //line to be output
		double px = P_x(n, p, x); //P(X = x)
		line += to_string(px);
		cout << line << "\n";
	}
}
void BinomialVisualiser(const int n, const long double p) {//n>0, p>0
	const int TotalBlocks = 10; //number of blocks that can be displayed horizontally
	const int Subdivisions = 8; // number of subdivisions in each block
	const string Unit = "@"; // a block consists of either a unit or an empty unit
	const string EmptyUnit = ".";
	const string FilledBlock = "@@@@@@@|";
	const string EmptyBlock  = ".......|";

	int TotalFilledBlocks; //Number of filled block for each row
	int TotalEmptyBlocks; //Number of filled block for each row

	//Choose a scale using multiples or sub-multiples of 1, 2, 5
	string Scale = "\n"; 	//scale of probabilities
	int mode = int(p * long double(n + 1));
	long double MaxProbability = P_x(n, p, mode); 
	const long double BigGap = (MaxProbability / long double(TotalBlocks)); //gap size between blocks
	const long double SmallGap = BigGap / Subdivisions; // gap size between subdivisions
	for (long double i = 0;i < 11;i++) {
		Scale += "\t" + to_string(BigGap * i).substr(0,5);
	}
	Scale += "\n\n";

	cout << "\t\t\t\t\t X ~ B (" << n << ", " << p << ")\n"; //header
	cout << Scale;

	for (int x = 0;x <= n;x++) {
		string line = "x = " + to_string(x) + "\t |"; //line to be output
		long double px = P_x(n, p, x); //P(X = x)
		
		//add filled blocks
		TotalFilledBlocks = int(px/BigGap);
		for (int i = 0;i < TotalFilledBlocks;i++) {line += FilledBlock;}

		//remaining units 
		long double remaining = px - long double(TotalFilledBlocks)*BigGap;
		int units = int(remaining/SmallGap);
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
	ProbabilityTable(n, p);

	//add E(x), mode, Variance
}
int main() {
	//improve to support standard notation
	//cout << P_x(10, 0.4, 0)<<"\n";
	//cout << RoundUp(0.01);

	BinomialVisualiser(10, 0.5);
	system("pause");


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
