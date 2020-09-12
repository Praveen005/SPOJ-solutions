//   https://www.spoj.com/problems/MKJUMPS/

#include<iostream>
using namespace std;
int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int ans ;

void place(int board[][10], int i, int j, int count) {

	if (i < 0 || i >= 10 || j < 0 || j >= 10 || board[i][j] == 0) {
		return;
	}
	board[i][j] = 0;
	ans = max(ans, count + 1);

	for (int k = 0; k < 8; k++) {
		int row = i + x[k];
		int col = j + y[k];
		place(board, row, col, count + 1);
	}
	board[i][j] = 1;
}
int main() {

	int t;
	int l = 1;
	while (cin >> t and t != 0) {
		int validBoxCount = 0;
		int board[10][10] = {0};
		for (int i = 0; i < t; i++) {
			pair<int, int>rc;
			cin >> rc.first;
			cin >> rc.second;
			validBoxCount += rc.second;
			for (int k = rc.first ; k < rc.first + rc.second; k++) {
				board[i][k] = 1;
			}
		}
		

		ans = 0;
		
		place(board, 0, 0, 0);
		cout << "Case " << l << ", ";
		if (validBoxCount - ans != 1)
			cout << validBoxCount - ans << " squares can not be reached." << endl;
		else
			cout << validBoxCount - ans << " square can not be reached." << endl;
		l++;
	}
}
