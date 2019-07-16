#pragma once

template <typename TData> class CArray
{
public:

  CArray()
  {
    m_buffer = 0;
    m_capacity = 0;
    m_size = 0;
  }

  CArray(
    const CArray & _array
  )
  {
    m_capacity = _array.m_capacity;
    m_size = _array.m_size;
    m_buffer = new TData[m_size];
    for (unsigned int i = 0; i < m_size; ++i)
    {
      m_buffer[i] = _array.m_buffer[i];
    }
  }

  ~CArray()
  {
    delete[] m_buffer;
  }

  void push_back(
    const TData & _value
  )
  {
    if (m_size >= m_capacity)
    {
      reserve((m_capacity + 1) * 2);
    }
    m_buffer[m_size++] = _value;
  }


  void insert(
    unsigned int  _index, const TData & _value
  )
  {
    if (m_capacity == m_size + 1)
    {
      reserve((m_capacity + 1) * 2);
    }
		
    for (unsigned int i = m_size + 1; i > _index; --i)
    {
      m_buffer[i + 1] = m_buffer[i];
    }
    m_buffer[_index] = _value;
    ++m_size;
  }

  void erase(
    unsigned int _index
  )
  {
    if (_index > m_size)
    {
      return;
    }

    for (unsigned int i = _index; i < m_size; ++i)
    {
      m_buffer[i] = m_buffer[i + 1];
    }
    
	  --m_size;
  }

  void clear()
  {
    m_size = 0;
    m_capacity = 0;
    delete[] m_buffer;
    m_buffer = 0;
  }

  unsigned int size() const
  {
    return m_size;
  }

  TData & operator[](
    unsigned int _index
  )
  {
    return m_buffer[_index];
  }

  void reserve(
    unsigned int _capacity
  )
  {
    if (m_buffer == 0)
    {
      m_size = 0;
      m_capacity = 0;
    }
    TData * buffer = new TData[_capacity];
    unsigned int n_size;
	  
    if (m_capacity > m_size)
    {
      n_size = _capacity;
    }
    else
    {
      n_size = m_size;
    }

    for (unsigned int i = 0; i < n_size; ++i)
    {
      buffer[i] = m_buffer[i];
    }
    m_capacity = _capacity;
	  
    delete[] m_buffer;
    m_buffer = buffer;
  }

protected:
  unsigned int m_size;
  unsigned int m_capacity;
  TData * m_buffer;
  const unsigned int c_minCapacity = 5;
};

