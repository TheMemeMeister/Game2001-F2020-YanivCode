#pragma once
#include <cassert>
#include <cstring>
template<class T>
//TODO make base class array 
class UnorderedArray
{
public:
	//Constructor 
	UnorderedArray(int size, int growby = 1) :
		m_array(NULL), m_maxsize = 0, m_growsize = 0, m_numElements = 0;
	{
		if (size)
		{
			m_size = false;
			m_array = new T[m_maxsize]; //Dynamically allocating an array to m_maxsize
			memset(m_array, 0, sizeof(T)* m_maxsize); //Explicitly allocating memory based on type T

			m_growsize = ((growBy > 0 ? ) ? growBy = 0); //makes sure array is never shrinking
		}
	}

	//Destructor
	~UnorderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}

	//Insertion
		//Fast insertion for unordered array -> big O = 0(1)
	void push(T val)
	{
		assert(m_array != NULL)
			if (m_numElements >= m_maxsize)
			{
				//Expand 
			}
		m_array[m_numElements] = val;
		m_numElements++;
	}

	//Deletion (2 methods) 
		//remove last item in array 
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
		//remove an item given an index
		//(almost) brute force -- big O = O(N)
	void remove(int index)
	{
		assert(m_array != NULL);
		
		if (index >= m_numElements)
		{
			return;
		}
		for (int i = index; i < m_numElements; i++)
		{
			if (i + 1 < m_numElements) 
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	//Searching 
		//linear search -- big O = N
	int search(T val)
	{
		assert(m_array != NULL);

		//brute force search 
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
	//Overloading the [] opperator
	T& operator[](int index)
	{
		assert(m_array != NULL && index < m_numElements);
		return m_array[index];
	}
	//Clear
	void clear()
	{
		m_numElements = 0; 
	}
	//Gets and sets 
	int GetSize() 
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxsize;
	}
	int GetGrowSize()
	{
		return m_growSize
	}
	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growsize = val;
	}
private:
	//Expansion
	bool Expand() 
	{
		if (m_growsize <= 0) 
		{
			return false;
		}
		//create a new array 
		T* temp = new T[m_maxsize + m_growsize];
		assert(temp != NULL);

		//copy original array contents into new array 
		memcpy(temp, m_array, sizeof(T) * m_maxsize);

		//delete old array
		delete[] m_array;

		//clean up variable assignments 
		m_array = temp;
		temp = NULL;
		m_maxSize += m_growsize
		return true;
	}
private:
	//Variables
	T* m_array; //pointer to begining of array 

	int m_maxsize;
	int m_growsize;
	int m_numElements;

};