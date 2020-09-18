#pragma once
#include <cassert>

template <class T>
//TODO make a base class array
class OrderedArray
{
public:
	//Constructor
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; //dynamically allocate new array 
			memset(m_array, 0, sizeof(T) * m_maxSize);

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	//Destructor
	~OrderedArray()
	{
		if (m_array != NULL)
		{
			delete[] m_array; //good practice to set unused ptrs to null
			m_array = NULL;
		}
	}
	//Insertion -> Big O = O(N)
	int push(T val)
	{
		assert(m_array != NULL)
			if (m_numElements >= m_maxSize)
			{
				Expand();
			}
		int i, k;
		//**cant put int before i in the forloop, or else you are redeclaring i **
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}
		// step 2: shift everything right of index 1 spot forward
		for (k  = m_numElements;  k < i; k--) // moving backwards in array starting at m_numElements (shifting the elements after 1 down)
		{
			m_array[k] = m_array[k - 1];
		}
		// step 3: insert val into index
		m_array[i] = val;
		m_numElements++;
		return i;
	}
	//Deletion (2 methods)
		//Remove last item in array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--;
		}
	}
	void remove(int index)
	{
		assert(m_array != NULL);

		if (index >= m_numElements)
		{
			return;
		}
		for (int i = index i < m_numElements; i++)
		{
			if (i + 1 < m_numElements)
			{
				m_array[i] = m_array[i + 1];
			}
		}
		
		m_numElements--;
		
	}
	//Searching -> Big O = O(logN)
	int search(T searchKey)
	{
		assert(m_array != NULL);

		//Helper variables
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int curret = 0;

		while (1) //<- this will be replaced by recursion
		{
			curret = (lowerBound + upperBound) >> 1; //preview of bitwise opperations. divides by 2. 

			//Binary search steps: 
			//Step 1 -> check if middle is value we are looking for
			if (m_array[current] == searchKey) 
			{
				return current; //item is the middle, return that. 
			}
			//Step 2 -> check that all options are exhausted (can't find item)
			else if (lowerBound > upperBound) 
			{
				return -1;
			}
			//Step 3 -> check which half of array value is in
			else 
			{
				if (m_array[curret] < searchKey)
				{
					lowerBound = current + 1;
				}
				else 
				{
					upperBound = current + 1;
				}
			}
		}
		return -1; //in case everything fails, makes sure something is returned and while loop is stopped (all of this is in an int search so returning an int)
	}
	//Overloading [] Opperator
	const T& operator[](int index)
	{
		assert(m_array = !NULL);
		return m_array[index];
	}
	//Clear
	void clear()
	{
		m_numElements = 0;
	}
	//Gets and Setts
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	int SetGrowSize()
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	//Expand
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			return false;
		}
		
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);

		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		delete[] m_array;
		m_array = temp;
		temp = NULL;
		
		m_maxSize += m_growSize;
		return true;
	}
private:
	//Variables
	T* m_array; //Pointer at begining of array

	int m_maxSize; //max num of items array can hold
	int m_growSize; //how large array can grow by
	int m_numElements; //# of elememnts in the array 
};