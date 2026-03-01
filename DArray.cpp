#include "DArray.h"
#include <iostream>

DArray::DArray()
{
	capacity = 50;

	a = new int[capacity];

	if (a == nullptr)
	{
		std::cout << "Error: Memory allocation failed DArray constructor. \n";
		exit(1);
	}

	numOfElements = 0;
}

DArray::DArray(int newCapacity)
{
	capacity = newCapacity;

	a = new int[capacity];

	if (a == nullptr)
	{
		std::cout << "Error: Memory allocation failed DArray parameterized constructor. \n";
		exit(1);
	}

	numOfElements = 0;
}

DArray::DArray(const DArray& other)
{
	capacity = other.capacity;
	numOfElements = other.numOfElements;

	a = new int[capacity];

	if (a == nullptr)
	{
		std::cout << "Error: Memory allocation failed DArray copy constructor.\n";
		exit(1);

	}

	for (int i = 0; i < numOfElements; i++)
	{
		a[i] = other.a[i];
	}
}

DArray& DArray::operator=(const DArray& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] a;
	a = nullptr;

	capacity = other.capacity;
	numOfElements = other.numOfElements;

	a = new int[capacity];

	if (a == nullptr)
	{
		std::cout << "Error: Memory Allocation failed in DArray copy assingment operator. \n";
		exit(1);
	}

	for (int i = 0; i < numOfElements; i++)
	{
		a[i] = other.a[i];
	}

	return *this;
}

DArray& DArray::operator+=(const DArray& right)
{
	if (numOfElements != right.numOfElements)
	{
		std::cout << "Mismatched number of elements" << std::endl;
		return *this;
	}

	for (int i = 0; i < numOfElements; i++)
	{
		a[i] += right.a[i];
	}

	return *this;
}

std::ostream& operator<<(std::ostream& out, const DArray& myArray)
{
	for (int i = 0; i < myArray.numOfElements; i++)
	{
		out << myArray.a[i] << " ";
	}
	std::cout << std::endl;
	return out;
}

DArray::~DArray()
{
	delete[] a;
	a = nullptr;
}

void DArray::addElement(int newElement)
{
	if (numOfElements >= capacity)
	{
		std::cout << "Error: Array full, allocate more memory." << std::endl;
		return;
	}

	a[numOfElements] = newElement;
	numOfElements++;
}

int DArray::getNumOfElements() const
{
	return numOfElements;
}

int DArray::getCapacity() const
{
	return capacity;
}

int DArray::findElement(const int& key) const
{
	for (int i = 0; i < numOfElements; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}
	return -1;
}

bool DArray::isSorted() const
{
	bool isAscending = true;

	for (int i = 0; i < numOfElements - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < numOfElements; j++)
		{
			if (a[j] < a[minIndex])
			{
				isAscending = false;
				break;
			}
		}
	}

	bool isDescending = true;

	for (int i = 0; i < numOfElements - 1; i++)
	{
		int maxIndex = i;
		for (int j = i + 1; j < numOfElements; j++)
		{
			if (a[j] > a[maxIndex])
			{
				isDescending = false;
				break;
			}
		}
	}

	if (isAscending)
	{
		std::cout << "The array is ascending" << std::endl;
	}
	else if (isDescending)
	{
		std::cout << "The array is descending" << std::endl;
	}
	else
	{
		std::cout << "The array is not sorted" << std::endl;
	}

	if (!isAscending && !isDescending)
	{
		return false;
	}

	
	return true;
}

void DArray::replaceElementAt(int newElement, int idx) const
{
	if (idx < 0 || idx > capacity - 1)
	{
		std::cout << "Error: Invalid index" << std::endl;
		return;
	}

	a[idx] = newElement;
}

bool DArray::compareArrays(const DArray& otherArray) const
{
	for (int i = 0; i < numOfElements; i++)
	{
		if (a[i] != otherArray.a[i])
		{
			return false;
		}
	}

	return true;
}

void DArray::changeCapacity(int newCapacity)
{
	if (newCapacity < numOfElements)
	{
		std::cout << "Error: setting this new capacity would erase data." << std::endl;
		return;
	}
	else if (newCapacity == capacity)
	{
		std::cout << "The new capacity is the same as the old capacity." << std::endl;
		return;
	}
	else
	{
		capacity = newCapacity;

		int* tempArray = new int[capacity];

		for (int i = 0; i < numOfElements; i++)
		{
			tempArray[i] = a[i];
		}

		delete[] a;
		a = tempArray;

		tempArray = nullptr;
	}
}
