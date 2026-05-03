#include <iostream>
#include <string_view>

class Base {
public:
  std::string_view getName() const { return "Base"; } // not virtual
  virtual std::string_view getNameVirtual() const { return "Base"; } // virtual
};

class Derived : public Base {
public:
  std::string_view getName() const { return "Derived"; }
  virtual std::string_view getNameVirtual() const override { return "Derived"; }
};

class Super_Derived : public Derived {
public:
  std::string_view getName() const { return "Derived"; }
  virtual std::string_view getNameVirtual() const override {
    return "Supera_Derived";
  }
};

int main() {

  Super_Derived super_dervied{};
  Derived &derived{super_dervied};

  Base &base{derived};

  std::cout << "base has static type " << base.getName() << '\n';
  std::cout << "base has dynamic type " << base.getNameVirtual() << '\n';
  std::cout << "derived has static type " << derived.getName() << '\n';
  std::cout << "derived has dynamic type " << derived.getNameVirtual() << '\n';

  return 0;
}
