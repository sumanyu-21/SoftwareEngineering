# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
using namespace std;

/*
                |     set             | unordered_set
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |

search time     | log(n)              | O(1) -> Average
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search

Deletion time   | log(n) + Rebalance  | Same as search
*/

//set--> Elemets are sorted in ascending order on the basis of keys(no values are present)
//map--> Elements are sorted in ascending order on the basis of keys(vales are also present).
//unordered_set--> Same as hash tables except that it contains only keys.
//unordered_map--> Same as hash tables with both key value pair.


bool comparator(int first_element,int second_element)
{
	return first_element>second_element; // Sorts in descending order.
}

void vectorDemo()
{
	vector<int> A = {11,2,3,14};

	// Sorting in ascending order.
	sort(A.begin(), A.end());
	// Sorting in Specific way
	sort(A.begin(), A.end(), comparator)


	// Once sorted, we can perform binary search.Gives first occurence.
	bool present = binary_search(A.begin(), A.end(), 3);


	// Adding new elements to vector;
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);


	// Lower bound. Returns iterator to first element >= Given Element
	vector<int>::iterator itr1 = lower_bound(A.begin(), A.end(),100);
	// Upper bound. Returns iterator to first element > Given Element.
	vector<int>::iterator itr2 = upper_bound(A.begin(), A.end(), 100);


	// printing content of iterator
	cout<<*itr1;
	// Iterator Arithmetic same as pointer arithmetic.
	cout<<itr2-itr1;  // prints 3;
	//Printing Vector
	vector<int>::iterator itr3;
	for(itr3 = A.begin();itr3!= A.end();itr3++)
		cout<<*itr3<<" "<<endl;

	for(int x:A)//Iterating without refrence.
	{
		x++;//Contents of vector does not change.
		cout<<x<<" "<<endl;
	}

	for(int &x:A)//Iterating with refrence.
	{
		x++;//Contents of vector have changed.
		cout<<x<<" "<<endl;
	}
}

void setDemo()
{
	// Set internally mantains ascending order using BST.
	set<int>S;
	S.insert(1);
	S.insert(2);
	S.insert(-1);
	S.insert(-10);

	for(int x:S)
		cout<<x<<" ";

	//Binary Search on Set(since it is ordered data structure)
	auto it = S.find(-1);
	if(it==S.end())
	{
		cout<<"Not present"
	}

	//Set is always sorted. Hence the class itself has the upper_bound function.
	auto itr2 = S.upper_bound(-1);
	auto itr3 = S.lower_bound(-1);

	auto itr4 = S.upper_bound(2) //Returns S.end();

}

int main()
{


}
