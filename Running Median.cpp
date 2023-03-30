#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

float median(vector<int> vect)
{
    int size = vect.size();

    int mid = (size-1)/2;

    if ((size)%2 == 0)
    {
        float sum = (vect.at(mid)+vect.at(mid+1));
        return (sum/2);
    }

    return vect.at(mid);
}

int main()
{
    int n;

    cin >> n;

    bool firsttime = true;

    vector<int> array;

    for (int i=0; i<n; i++)
    {
        int ele;

        cin >> ele;

        if (firsttime)
        {
            array.insert(array.begin() ,ele);
            firsttime = false;
        }

        else
        {
            for (int j=0; j<array.size(); j++)
            {
                if (ele < array.at(j))
                {
                    array.insert(array.begin()+j,ele);
                    break;
                }


                else
                {
                    array.insert(array.end()-1, ele);
                    break;
                }   
            }
        }

        for (int l:array)
        {
            cout << "element: "<< l << " ";
        }
        cout << "\n";

        float answer = median(array);

        cout << fixed;
        cout << setprecision(1);
        cout << answer << endl;
    }
}

