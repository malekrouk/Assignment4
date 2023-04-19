#include <iostream>
#include <vector>

using namespace std;




void insertAfter(int firstV, int secondV, vector<int>& v)
{
		for (int i = 0; i<int(v.size()); i++) 
		{
			if (v.at(i) == firstV)
			{
				v.insert(v.begin() + i + 1, secondV); /*inserting values into the vector using the insert function*/ 
				/*insert function has an adavnatge on push back because we can precise the index we want, which is why we use it here*/
			}
		}	
}


int main()
{
	int n;
	vector<int> v;
	cout << "Number of integers to be stored in the vector" << endl;
	cin >> n;
	int m;
	cout << "Now insert the integers in the vector" << endl;
	for (int i = 0; i < n; i++) /*filling the vector*/
	{
		cin >> m;
		v.push_back(m); /*inserting values into the vector using the push_back function*/
	}

	cout << "Now enter the first and second value " << endl;
	int one, two;
	cin >> one >> two;

	cout << "Print before" << endl;
	for (int i = 0; i < (int)v.size(); i++)
	cout << v[i] << " ";

	insertAfter(one, two, v); /*calling function*/

	cout << endl;
	cout << "Print after" << endl;
	for (int i = 0; i < (int)v.size(); i++)
		cout << v[i] << " ";



}