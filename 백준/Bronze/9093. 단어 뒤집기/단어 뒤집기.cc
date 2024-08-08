#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); // to ignore the newline character after the number of test cases

    while (T--) {
        string sentence;
        getline(cin, sentence);

        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            reverse(word.begin(), word.end());
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
