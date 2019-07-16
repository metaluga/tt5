#include "Test.h"
#include <iostream>

void Test::intTest()
{
  CArray<int> myArray;
  intAddTwentyNumbers(myArray);
  printAll(myArray);

  sotrIntArray(myArray);
  printAll(myArray);

  deleteEvenNumber(myArray);
  printAll(myArray);

  insertTenRandomNumber(myArray);
  printAll(myArray);

  clear(myArray);
  printAll(myArray);
}

void Test::intAddTwentyNumbers(
	CArray<int>& _array
)
{
  const int c_addingNumber = 20;

  for (int i = 0; i < c_addingNumber; ++i)
  {
    _array.push_back(rand() % c_randomRange);
  }
}

void Test::sotrIntArray(
  CArray<int>& _array
)
{
  qsort(_array, 0, _array.size()-1);
}

void Test::deleteEvenNumber(
  CArray<int>& _array
)
{
  for (int i = _array.size() % 2 == 0 ? _array.size() : _array.size() - 1; i >= 0; i -= 2)
  {
    _array.erase(i);
  }
}

void Test::insertTenRandomNumber(
  CArray<int>& _array
)
{
  const int c_insertNumber = 10;
  for (int i = 0; i < c_insertNumber; ++i)
  {
    _array[rand() % _array.size()] = rand() % c_randomRange;
  }
}

void Test::clear(
  CArray<int>& _array
)
{
  _array.clear();
}

template <typename TData>
void Test::printAll(
  CArray<TData> & _array
) const
{
  for (unsigned int i = 0; i < _array.size(); ++i)
  {
    std::cout << _array[i] << " ";
  }
  std::cout << std::endl;
}

void Test::stringTest()
{
  CArray<std::string> myArray;

  addRandomWords(myArray);
  printAll(myArray);

  sotrStringArray(myArray);
  printAll(myArray);

  removeSomeWords(myArray);
  printAll(myArray);

  addRandomWordInRndomPosition(myArray);
  printAll(myArray);
}

void Test::addRandomWords(
  CArray<std::string>& _array
)
{
  const int c_addingNumber = 15;

  for (int i = 0; i < c_addingNumber; ++i)
  {
    _array.push_back(randomString());
  }
}

void Test::sotrStringArray(
  CArray<std::string>& _array
)
{
  qsort(_array, 0, _array.size() - 1);
}

void Test::removeSomeWords(
  CArray<std::string>& _array
)
{
  const std::string c_keyForDelete = "abcde";
  for (int i = _array.size() - 1; i >= 0; --i)
  {
    for (int j = 0; j < c_keyForDelete.size(); ++j)
    {
      if (_array[i].find(c_keyForDelete[j]) != std::string::npos)
      {
        _array.erase(i);
        break;
      }
    }
  }
}

void Test::addRandomWordInRndomPosition(
  CArray<std::string>& _array
)
{
  const int c_insertNumber = 3;
  for (int i = 0; i < c_insertNumber; ++i)
  {
    _array[rand() % _array.size()] = randomString();
  }
}

template <typename TData>
void Test::qsort(
  CArray<TData> & _array, int _left, int _right
)
{
  int i = _left;
  int j = _right;
  TData tmp;
  TData pivot = _array[(_left + _right) / 2];

  while (i <= j)
  {
    while (_array[i] < pivot)
	{
      i++;
    }

    while (_array[j] > pivot)
    {
      j--;
    }

    if (i <= j)
    {
      tmp = _array[i];
      _array[i] = _array[j];
      _array[j] = tmp;
      i++;
      j--;
    }
  }

  if (_left < j)
  {
    qsort(_array, _left, j);
  }

  if (i < _right)
  {
    qsort(_array, i, _right);
  }
}


std::string Test::randomString()
{
  const std::string c_validChars = "abcdefghijklmnaoqrstuvwxyz";
  const int c_maxWordLen = 20;

  int length = rand() % c_maxWordLen + 1;

  std::string word = "";

  for (int i = 0; i < length; ++i)
  {
    word += c_validChars[rand() % c_validChars.length()];
  }

  return word;
}