#ifndef DARRAY_H
#define DARRAY_H
#include <ostream>

class DArray
{
private:
	int* a;
	int capacity;
	int numOfElements;

public:
	DArray();
	DArray(int newCapacity);
	DArray(const DArray& other);
	DArray& operator=(const DArray& other);
	DArray& operator+=(const DArray& right);
	~DArray();

	void addElement(int newElement);
	int getNumOfElements() const;
	int getCapacity() const;
	int findElement(const int& key) const;
	bool isSorted() const;
	friend std::ostream& operator<<(std::ostream& out, const DArray& myArray);
	void replaceElementAt(int newElement, int idx) const;
	bool compareArrays(const DArray& otherArray) const;
	void changeCapacity(int newCapacity);
};

#endif
