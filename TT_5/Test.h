#pragma once
#include <string>
#include "CArray.h"
class Test
{
public:

  void intTest();

  void intAddTwentyNumbers(
    CArray<int> & _array
  );
  void sotrIntArray(
    CArray<int> & _array
  );
  void deleteEvenNumber(
    CArray<int> & _array
  );
  void insertTenRandomNumber(
    CArray<int> & _array
  );
  void clear(
    CArray<int> & _array
  );

  template <typename TData>
  void printAll(
    CArray<TData> & _array
  ) const;


  void stringTest();

  void addRandomWords(
    CArray<std::string> & _array
  );
  void sotrStringArray(
    CArray<std::string> & _array
  );
  void removeSomeWords(
    CArray<std::string> & _array
  );
  void addRandomWordInRndomPosition(
    CArray<std::string> & _array
  );


private:
  const unsigned int c_randomRange = 101;
  template <typename TData>
  void qsort(
    CArray<TData> & _array, int _left, int _right
  );
  std::string randomString();
};

