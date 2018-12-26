# include <string>
# include <iostream>

using namespace std;



// Modify the given string directly
string URLify(string &in, int len) {
  int space_count = 0;

  for (int i = 0; i < len; i++) {
    if (in[i] == ' ') {
      space_count++;
    }
  }

  int buffer_len = len + 2 * space_count;

  if (buffer_len < in.length()) {
    in[buffer_len] = '\0'; // End
  }


  for (int i = len - 1; i >= 0; i--) {
    if (in[i] == ' ') {
      in[buffer_len - 1] = '0';
      in[buffer_len - 2] = '2';
      in[buffer_len - 3] = '%';
      buffer_len-=3;
    } else {
      in[buffer_len - 1] = in[i];
      buffer_len--;
    }
  } // For

  return in;
}




int main() {
  string test = "Mr John Smith      ";
  int len = 13;
  string test2 = "Hello Boo! Boo!        ";
  int len2 = 15;


  cout << URLify(test, len) << endl;
  cout << URLify(test2, len2) << endl;

  
  return 0;
}
