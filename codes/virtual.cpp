
#include <iostream>
class Shape {
public:
  int getValuePublic() { return getValuePrivate(); }

private:
  virtual int getValuePrivate() { return 0; }
};
class Circle : public Shape {
private:
  //   int getValuePrivate() override { return 1; }
};
signed main() {
  Circle c;
  //   Shape *ptr = &c;
  Circle *ptr = &c;
  std::cout << ptr->getValuePublic() << std::endl;
  return 0;
}
