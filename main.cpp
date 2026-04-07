#include<iostream>
#include<vector>

using namespace std;

int N, M; //global
vector<int> vec;

//  Solution using Recursion!!!!
//  2025-14056 정우진

vector<vector<int>> subfunc(int upper_bound, int num) {//1부터 upper_bound중 num개
	vector<vector<int>> output;
	if (num == 1) { //1개 추출
		for (int i = 1; i <= upper_bound; i++) {
			output.push_back({ i });
		}
		return output;
	}
	else if (upper_bound == num) { //M = N
		vector<int> temp;
		for (int i = 1; i <= num; i++) {
			temp.push_back(i);
		}
		output.push_back(temp);
	}
	else { //otherwise
		vector<vector<int>> vec1 = subfunc(upper_bound - 1, num - 1);
		vector<vector<int>> vec2 = subfunc(upper_bound - 1, num);
		for (vector<int> vec : vec1) {
			vec.push_back(upper_bound);
			vec2.push_back(vec);
		}
		output = vec2;
	}
	return output;
}

void func(int cnt) {
	vector<vector<int>> results = subfunc(N, M);
	for (vector<int> vec : results) {
		for (int num : vec) {
			cout << num << " ";
		}
		cout << endl;
	}
}



int main() {
	cin >> N >> M;
	func(0);
}
