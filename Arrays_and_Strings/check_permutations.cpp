# include <string>
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

// Only works with a-z

/*
Determines if one string is the permutation of another
    O(nlogn) time
    O(1) space
Where n is the length of the strings when they are of equal length
*/
bool is_permutation(string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();

  if (len1 != len2) {
    return false;
  }

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  return s1 == s2;
}

/*
Determines if one string is the permutation of another
    O(n) time
    O(n) space
Where n is the length of the strings when they are of equal length
*/
bool is_permutation_2(string &s1, string &s2) {
  vector<int> character_counts (26);
  int len1 = s1.length();
  int len2 = s2.length();

  if (len1 != len2) {
    return false;
  }

  for (char c : s1) {
    character_counts[c - 'a']++;
  }

  for (char c : s2) {
    character_counts[c - 'a']--;
    if (character_counts[c - 'a'] < 0) {
      return false;
    }
  }
  return true;
}




int main() {
  string s1 = "test";
  string s2 = "estt";
  string s3 = "tess";

  cout << "is_permutation" << endl;
  cout << "Correct: true      Output: " << is_permutation(s1, s2) << endl;
  cout << "Correct: false     Output: " << is_permutation(s1, s3) << endl;

  cout << "is_permutation_2" << endl;
  cout << "Correct: true      Output: " << is_permutation_2(s1, s2) << endl;
  cout << "Correct: false     Output: " << is_permutation_2(s1, s3) << endl;


  return 0;
}
