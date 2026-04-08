#include<iostream>
#include<vector>

using namespace std;

int N, M; //global
vector<int> vec;

//  Solution using Recursion!!!!
//	very tricky more than i thought :(
//  2025-14056 정우진

vector<vector<int>> subfunc(int lower_bound, int num) {   //N부터 lower_bound중 num개
	vector<vector<int>> output;
	if (num == 1) { //1개 추출
		for (int i = N; i >= lower_bound; i--) {
			output.push_back({ i });
		}
		return output;
	}
	else if (N - lower_bound + 1 == num) { //M = N
		vector<int> temp;
		for (int i = N; i >= lower_bound; i--) {
			temp.push_back(i);
		}
		output.push_back(temp);
	}
	else { //otherwise
		vector<vector<int>> vec1 = subfunc(lower_bound + 1, num - 1);
		vector<vector<int>> vec2 = subfunc(lower_bound + 1, num); //
		for (vector<int> vec : vec1) {
			vec.push_back(lower_bound);
			vec2.push_back(vec);
		}
		output = vec2;
	}
	return output;
}

//사전순으로 만들기 위해, 배열을 역순으로 구성하고 역순으로 출력
void func(int cnt) {
	vector<vector<int>> results = subfunc(1, M);
	for (int i = results.size(); i >= 1; i--) {
		for (int j = M; j >= 1; j--) {
			cout << results[i - 1][j - 1] << " ";
		}
		cout << endl;
	}
}



int main() {
	cin >> N >> M;
	func(0);
}
