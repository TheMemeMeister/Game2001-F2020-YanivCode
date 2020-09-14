// Generic classes/functions
// Compare 2 numbers. Return Smallest. Return Largest.
#include <iostream>
using namespace std;

// Compare/check 2 "things". Return the Smallest. 
template <class T>

T min_func(T Lval, T Rval) 
{
	if (Lval > Rval)
	{
		return Rval;
	}
	return Lval;
}

// Compare/check 2 "things". Return the Largest. 

template <class T>
T max_func(T Lval, T Rval)
{
	if (Lval < Rval)
	{
		return Rval;
	}
	return Lval;
}

// Implement template here
template <class T>
class TempClass
{
public:
	TempClass(T val) 
	{
		m_val = val;
	}

	//EZ TO MISS THIS STEP 
	bool operator<(TempClass& Rval)
	{
		return m_val < Rval.GetVal();
	}
	bool operator>(TempClass& Lval)
	{
		return m_val > Lval.GetVal();
	}
	T GetVal()
	{
		return m_val;
	}
private:
	T m_val;

};


//Main 

int main()
{
	cout << "Template Example" << endl << endl;
	cout << "Min = " << min_func(30, 26) << endl;
	cout << "Max = " << max_func(56.1, 43.6) << endl;

	//Create 2 "TempClass" class obj and compare them. 
	cout << "Max (objects) = " << max_func(TempClass<int>(7), TempClass<int >(4)).GetVal();
	system("pause");
	return 0;
}