#include <iostream>
using namespace std;
int main()
{
    int size = 5, tally = 0;
    int *arr = new int[5];
    int *narr = NULL;
START:
    do
    {
        cout << " Enter element or -1 to teminate : ";
        cin >> *(arr + tally);
        if (*(arr + tally) == -1)
            goto END;
        tally++;
        if (tally == size)
        {
            narr = new int[size + 5];
            for (int i = 0; i < size; i++)
            {
                *(narr + i) = *(arr + i);
            }
            size += 5;
            delete[] arr;
            arr = narr;
            narr = NULL;
            goto START;
        }
    } while (1);
END:

    cout << " Numbers in reverse order are : [ ";
    for (int i = (tally - 1); i >= 0; i--)
    {
        cout << *(arr + i) << ",";
    }
    cout << "]\n";

    delete[] arr;
    arr = NULL;
    system("pause");
}