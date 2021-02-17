#include <iostream>

using namespace std;

// 计算a+b
int main() {
  long a;
  long b;
  while (cin >> a >> b) {
    cout << a + b << endl;
  }
  return 0;
}

// 计算a+b，先输入测试几组数值
int main() {
  int count;
  long a;
  long b;

  cin >> count;
  while (count-- > 0) {
    cin >> a >> b;
    cout << a + b << endl;
  }
  return 0;
}

// 计算a+b，输入为0 0则结束输入
int main() {
  long a;
  long b;
  while (cin >> a >> b) {
    if (a == b && a == 0) {
      break;
    }
    cout << a + b << endl;
  }
  return 0;
}

// 计算a+b，每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100),
// n为0的时候结束输入
int main() {
  int count;
  while (cin >> count && count != 0) {
    long sum = 0;
    long i;
    while (count-- && cin >> i) {
      sum += i;
    }
    cout << sum << endl;
  }
  return 0;
}

int main() {
  int line;
  cin >> line;
  while (line--) {
    int count;
    cin >> count;
    long sum = 0;
    long i;
    while (count-- && cin >> i) {
      sum += i;
    }
    cout << sum << endl;
  }
  return 0;
}

int main() {
  long sum = 0;
  long val = 0;
  char c;
  while (cin.get(c)) {
    if (c == '\n') {
      sum += val;
      cout << sum << endl;
      sum = 0;
      val = 0;
    } else if (c == ' ') {
      sum += val;
      val = 0;
    } else {
      val = val * 10 + (c - '0');
    }
  }
  return 0;
}

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  int count;
  cin >> count;
  while (cin.get() != '\n') {
  }
  //   multimap
  multiset<string> cache;
  while (count--) {
    char c;
    string s;
    while (cin.get(c)) {
      if (c != ' ' && c != '\n') {
        s += c;
      } else {
        cache.emplace(s);
        s = "";
      }
    }
  }
  int i = 1;
  for (multiset<string>::iterator it = cache.begin(); it != cache.end(); it++) {
    cout << *it;
    if (i++ != cache.size()) {
      cout << ' ';
    }
  }
  cout << '\n';
  return 0;
}

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  multiset<string> cache;
  char c;
  string s;
  while (cin.get(c)) {
    if (c != ' ' && c != '\n') {
      s += c;
    } else {
      cache.emplace(s);
      s = "";
    }
    if (c == '\n') {
      int i = 1;
      for (multiset<string>::iterator it = cache.begin(); it != cache.end();
           it++) {
        cout << *it;
        if (i++ != cache.size()) {
          cout << ' ';
        }
      }
      cout << '\n';
      cache.clear();
    }
  }

  return 0;
}

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
  multiset<string> cache;
  char c;
  string s;
  while (cin.get(c)) {
    if (c != ',' && c != '\n') {
      s += c;
    } else {
      cache.emplace(s);
      s = "";
    }
    if (c == '\n') {
      int i = 1;
      for (multiset<string>::iterator it = cache.begin(); it != cache.end();
           it++) {
        cout << *it;
        if (i++ != cache.size()) {
          cout << ',';
        }
      }
      cout << '\n';
      cache.clear();
    }
  }

  return 0;
}