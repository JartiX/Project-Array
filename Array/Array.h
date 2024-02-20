#include <iostream>
using namespace std;

const int DEFAULT_CAPACITY = 10;

class ArrayException {};

class Array {
  int *ptr;

  int size, capacity;

  bool isFail;

public:
  int &operator[](int index);

  void remove(int index);
  void insert(int index, int elem);
  void insert(int elem);

  explicit Array(int startCapacity = DEFAULT_CAPACITY);
  ~Array();
  Array(const Array &arr);

  Array &operator=(const Array &arr);

  bool fail();

  void increaseCapacity(int newCapacity);

  int getSize() const;

  friend ostream &operator<<(ostream &out, const Array &arr);
};