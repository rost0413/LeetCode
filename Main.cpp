#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include "N-Queens.cpp"
using namespace std;

int main() {
	Solution s;
	vector<vector<string> > result;
	result = s.solveNQueens(2);

	for (int i=0;i<result.size();i++){
		for (int j=0;j<result[i].size();j++) {
			cout << result[i][j] << endl;
		}
		cout << endl;
	}

	return 0;
}
