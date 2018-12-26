# include <string>
# include <iostream>
# include <unordered_set>
# include <algorithm>

using namespace std;


/*
Determines if a string has all unique characters
  O(n) time
  O(n) space
Where n is the length of the string.
*/
bool is_unique(string &in) {
    unordered_set<char> character_storage;
    for (auto c: in) {
      auto it = character_storage.find(c);
      if (it != character_storage.end()) {
        // Character found
        return false;
      } else {
        character_storage.insert(c);
      }
    } // For
    return true;
}

/*
Determines if a string has all unique characters
  O(nlogn) time
  O(1) space
Where n is the length of the string
*/

bool is_unique_no_structs(string in) {
    int length = in.length();
    // Case 1
    if (length == 0 || length == 1) {
      return true;
    }

    // Sort
    sort(in.begin(), in.end());

    // Case 2
    for (int i = 1; i < length; i++) {
      if (in[i] == in[i-1]) {
        return false;
      }
    } // For

    return true;
}


int main() {

  string s1 = "good";
  string s2 = "bad";
  string s3 = "a";
  string s4 = "aaaa";
  string s5 = "";

  cout << "is_unique" << endl;
  cout << "Correct: false     Output: " << is_unique(s1) << endl;
  cout << "Correct: true      Output: " << is_unique(s2) << endl;
  cout << "Correct: true      Output: " << is_unique(s3) << endl;
  cout << "Correct: false     Output: " << is_unique(s4) << endl;
  cout << "Correct: true      Output: " << is_unique(s5) << endl;

  cout << "is_unique_no_structs" << endl;
  cout << "Correct: false     Output: " << is_unique_no_structs(s1) << endl;
  cout << "Correct: true      Output: " << is_unique_no_structs(s2) << endl;
  cout << "Correct: true      Output: " << is_unique_no_structs(s3) << endl;
  cout << "Correct: false     Output: " << is_unique_no_structs(s4) << endl;
  cout << "Correct: true      Output: " << is_unique_no_structs(s5) << endl;

  return 0;
}
