#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define ll long long

using namespace std;

long double P_x(const int n, const long double p, const int x) {
	//returns P(X=x) = nCx (p)^x (1-p)^(1-x)
	if (x == 0)return pow(1 - p, n);
	int k=x;
	if (x > n - x) k = n - x; 
	long double  nCx = 1;
	bool multiplied = 0;
	for (long double i = 1; i <= k; i++) {
		nCx *= n - k + i;
		nCx /= i;
		if (nCx > 99999999) { nCx *= pow(p, x) * pow(1 - p, n - x);multiplied = 1; }
	}
	if (multiplied == 1) {
		return nCx;
	}
	return nCx * pow(p, x) * pow(1 - p, n - x);
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
	const int TotalBlocks = 10; //number of blocks that can be displayed horizontally. Keep < 25.
	const int Subdivisions = 8; // number of smaller interval within each block. Do not change. keep > 1
	const string Unit = "@"; // a block consists of either a unit or an empty unit
	const string EmptyUnit = ".";
	
	//create FilledBlock
	string temp = "";
	for (int i = 1;i < Subdivisions;i++) {temp += Unit;}
	temp += "|";
	const string FilledBlock = temp;

	//create EmptyBlock
	temp = "";
	for (int i = 1;i < Subdivisions;i++) { temp += EmptyUnit;}
	temp += "|";
	const string EmptyBlock = temp;

	
	int TotalFilledBlocks; //Number of filled block for each row
	int TotalEmptyBlocks; //Number of filled block for each row

	//Create a scale of probabilities 
	string Scale = "\n\t";
	const int NumberOfDP = 3; //Number of decimal places in numbers displayed on scale. DO NOT CHANGE.
	int mode = int(p * long double(n + 1));
	long double MaxProbability = P_x(n, p, mode); 
	const long double BigGap = (MaxProbability / long double(TotalBlocks)); //gap size between blocks
	const long double SmallGap = BigGap / Subdivisions; // gap size between subdivisions
	// "/t"  =  8 characters
	// ONLY DISPLAY numbers every 2 intervals
	for (int i = 0;i <= TotalBlocks; i++) {
		if (i % 2 == 0) {
			Scale += to_string(BigGap * long double(i)).substr(0, NumberOfDP + 2) + "\t\t";
		}
	}
	Scale += "\n\n";

	cout << "\t\t\t\t\t X ~ B (" << n << ", " << p << ")\n"; //header
	cout << Scale;

	string grid = "";
	int FirstNonZeroX = -1;
	int LastNonZeroX = -1;
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
			for (int j = 0;j < Subdivisions-1;j++) {
				if (j < units) {line += Unit;}
				else {line += EmptyUnit;}
			}
			line += "|";
			TotalEmptyBlocks = TotalBlocks - TotalFilledBlocks - 1;
		}
		//add empty blocks
		if (TotalEmptyBlocks != TotalBlocks) {
			if (FirstNonZeroX == -1)FirstNonZeroX = x;
			if (FirstNonZeroX != -1)LastNonZeroX = x;

			for (int i = 0;i < TotalEmptyBlocks;i++) { line += EmptyBlock; }
			grid += line + "\n\n";
		}
	}
	string FullLineOfEmptyBlocks = "";
	for (int i = 0;i < TotalBlocks;i++) {FullLineOfEmptyBlocks += EmptyBlock;}

	if (FirstNonZeroX != 0) {
		grid = "x < " + to_string(FirstNonZeroX) + "\t |" + FullLineOfEmptyBlocks + "\n\n" + grid;
	}
	if (LastNonZeroX != n) {
		grid += "x > " + to_string(LastNonZeroX) + "\t |" + FullLineOfEmptyBlocks + "\n\n";

	}
	cout << grid;
}
int main() {
	BinomialVisualiser(100, 0.123);
	system("pause");

}
