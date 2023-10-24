#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
void print(vector<int> a) {
	for(int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

pair<string, int> func(string a) {
	return make_pair(a, a.size());
}
int main() {
	string a = "nice to meet YOu, my Xlj";
	transform(a.begin(), a.end(), a.begin(), ::toupper);
	cout << a << endl;
	
	vector<int> num = {1,2,3,4,5,6};
	vector<int> numof2 = {0,0};
	transform(num.begin(), num.end(), numof2.begin(), [](int n) {return n * 2;} ); //lambda表达式
	print(numof2); // 只会产生2个数
	transform(num.begin(), num.end(), std::back_inserter(numof2), [](int n) {return n * 2;} );
	print(numof2);
	
//	vector<string> word = {"fuck", "taking", "genius", "god"};
//	vector<pair<string, int>> dict;
//	transform(word.begin(), word.end(), std::back_inserter(dict), [](string a){return make_pair(a, a.size());});
//	for(auto i = dict.begin(); i != dict.end(); i++) {
//		cout << i -> first << ":" << i -> second << endl;
//	}
	vector<string> word = {"fuck", "taking", "genius", "god"};
	vector<pair<string, int>> dict;
	transform(word.begin(), word.end(), std::back_inserter(dict), func); // 代替lambda
	for(auto i = dict.begin(); i != dict.end(); i++) {
		cout << i -> first << ":" << i -> second << endl;
	}
	
	vector<int> t1 = {1,3,5,7,9,8};
	vector<int> t2 = {2,4,6,8,10};
	vector<int> ans;
	transform(t1.begin(), t1.end(), t2.begin(), std::back_inserter(ans), [](int a, int b) {return a + b;});
	print(ans);
	cout << endl;

	//套娃
	transform(word.begin(), word.end(), word.begin(), [](string a){transform(a.begin(), a.end(), a.begin(), ::toupper); return a;});
	for(int i = 0; i < word.size(); i++) {
		cout << word[i] << " ";
		
	}
	cout << endl;
	//////////////////////////一下是copyif的主场
	vector<int> test = {1,2,3,4,5,6,7,8,9};
	vector<int> tans;
	copy_if(test.begin(), test.end(), std::back_inserter(tans), [](int n) {return n % 2 == 0;});
	print(tans);
}