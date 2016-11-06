#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

struct Mutex {};
template<typename T> class Proxy {
public:
  Proxy(const string &name) : name_(name) {}
  const string& proxy_name() const { return name_; }

  void operator=(const T& val) const {
    cout << "set " << name_ << " " << val << endl;
  }
  operator T() const {
    cout << "get " << name_ << endl;
    T res;
    cin >> res;
    return res;
  }
private:
    string name_;
};
#define PROXY(T, name) Proxy<T> name(#name)

PROXY(bool, flag);
PROXY(Mutex, guard);
PROXY(int, result);

void pthread_mutex_lock(Proxy<Mutex> *addr) {
  cout << "lock " << addr->proxy_name() << endl;
}
void pthread_mutex_unlock(Proxy<Mutex> *addr) {
  cout << "unlock " << addr->proxy_name() << endl;
}

#include "8-template.c"
//#include "8-solution.c"

int main() {
  string op;
  if (!(cin >> op)) {
    return 0;
  }
  if (op == "set") {
    int val;
    cin >> val;
    set_result(val);
  } else {
    int val = get_result();
    cout << val << endl;
  }
  return 0;
}
