#include <iostream>
#include "DArray.h"
using namespace std;

int main()
{
	DArray darr = DArray(3);
	cout << "Created DArray with a capacity of 3" << endl;

	darr.addElement(42);
	cout << "Added element to DArray: numOfElements: " << darr.getNumOfElements() << " capacity: " << darr.getCapacity() << endl;
	darr.addElement(12);
	cout << "Added element to DArray: numOfElements: " << darr.getNumOfElements() << " capacity: " << darr.getCapacity() << endl;
	darr.addElement(98);
	cout << "Added element to DArray: numOfElements: " << darr.getNumOfElements() << " capacity: " << darr.getCapacity() << endl;
	cout << "DArray: " << darr;

	if (darr.isSorted())
	{
		cout << "DArray is sorted" << endl;
	}
	else
	{
		cout << "DArray is not sorted" << endl;
	}

	cout << "Replacing element 12 at index 1 with 64..." << endl;
	darr.replaceElementAt(64, 1);
	cout << darr;

	if (darr.isSorted())
	{
		cout << "DArray is sorted" << endl;
	}
	else
	{
		cout << "DArray is not sorted" << endl;
	}

	int indexFound = darr.findElement(98);
	cout << "Searching for element " << 98 << "..." << endl;
	if (indexFound == -1)
	{
		cout << "Element not found." << endl;
	}
	else
	{
		cout << "Element found at index: " << indexFound << endl;
	}

	int indexFound2 = darr.findElement(12);
	cout << "Searching for element " << 12 << "..." << endl;
	if (indexFound2 == -1)
	{
		cout << "Element not found." << endl;
	}
	else
	{
		cout << "Element found at index: " << indexFound2 << endl;
	}

	DArray darr2 = darr;
	DArray darr3;
	darr3 = darr;

	cout << "DArray: " << darr;

	cout << "DArray 2 (copy constructor test): ";
	cout << darr2;

	cout << "DArray 3 (copy assignment operator test): ";
	cout << darr3;

	cout << "Comparing DArray and DArray2..." << endl;
	cout << darr;
	cout << darr2;
	if (darr.compareArrays(darr2))
	{
		cout << "DArray and DArray have the same values" << endl;
	}
	else
	{
		cout << "DArray and DArray do NOT have the same values" << endl;
	}

	darr3.replaceElementAt(109, 0);
	cout << "Replaced element 42 with 109 in DArray 3" << endl;
	cout << darr3;

	cout << "Comparing DArray and DArray3..." << endl;
	cout << darr;
	cout << darr3;
	if (darr.compareArrays(darr3))
	{
		cout << "DArray and DArray3 have the same values" << endl;
	}
	else
	{
		cout << "DArray and DArray3 do NOT have the same values" << endl;
	}

	darr.changeCapacity(4);
	darr2.changeCapacity(4);
	darr.addElement(400);
	darr2.addElement(400);
	cout << "Added element 400 to DArray, DArray2 and changed capacity of both to 4: numOfElements: " << darr.getNumOfElements() << " capacity: " << darr.getCapacity() << endl;
	cout << "Darray: " << darr;


	darr += darr2;

	cout << "DArray after element-wise addition with darr and darr2: ";
	cout << darr;

	return 0;
}
