#include<iostream>
using namespace std;
/*complete the header of following functions by specifying return type and
paramters. Use const where ever function doesnt need to change the data.In all 
functions you have to deallocate the array or part of array that is not going to be 
used. Define the complete functions after main. All the functions work with integer arrays*/


/*The function takes a size and create and allocated dynamic
integer array of that size and returns the addressd of thae array*/
int* allocate_array(int p);


/*takes a pointer as input and return true if pointer is NULL of nullptr
else false*/
int is_nullptr(int *p);


/*This function take dynamic array as input and deallocates it
and changes the pointer of array to nullptr*/
int* deallocate_array(int *p);


/*This function takes an array as input and doubles its size,
the current elements are copies to first half of the new
bigger array. Note that the input array is doubled, size param should
also be doubled. Default value in 2nd half can be -1 */
void double_the_array(int*& p, int& size);


/*This functions take the array as input and reduce the size to half
element of only first half are retained. Note that the input array
is halfed. Size param should also be halfed*/
void half_the_array(int *&p, int &size);


/*This function takes any array, start index and end index as input
and returns a copy of slice of array from start index to end index.
Input array should not be effected.*/
int* slice_of_array( int *p, int size, int x, int y, int &size1);


/*This function takes an array as input and give the mean of
numbers of array*/
double mean_array(int *p, int size);


/*This function takes two arrays and there size
and returns a new array the is concatenation of both.
If size of both arrays is not same return False*/
int* concatenate_arrays(int *p, int *q, int size, int size1, int &size2);


/*This function takes two arrays and their sizes and
return's True if both have same elements in same order
else return false*/
bool compare_array(int *p, int *q, int size, int size1);


/*This function takes an array and sorts its inplace
sort inplace means sorting the input array, not creating its copy*/
int* sort_array(int *&p, int size);


/*This function take and array and returns it's sorted copy
orignal input array should not be effeected
Hint: you can use sort array function in this function*/
int* sorted_copy(int *p, int size);


/*this function takes an array as input; and a number and checkes
if number exists in array. If yes, return True else return false*/
bool exists(int *p,int size, int x);


/*This function takes an array and returns a new array containing only
distinct elements of input array. Original array should not be changed
It also returns the size of new array*/
int* distinct_copy(int* p, int size, int& size1);


/*This function takes an array deletes the redudant elements from it
So the input array will not have only distinct value. This function is
different from distinct_copy function, here input array is changed.*/
int* distinct_array(int*& p, int& size);


/*Function to print an array*/
void print_array(const int* p, int size)
{
    cout << "Array Size: " << size <<"\t"<<"Elements {";
    if (size <= 0)
        cout << "}" << endl;
    else
    {
        for (int i = 0; i < size - 1; i++)
            cout << p[i] << ", ";
        cout << p[size - 1] << "}" << endl;
    }
}


int main()
{
    int* my_array1 = allocate_array(50);
    if (is_nullptr(my_array1))
        cout << "my_array1 is nullptr" << endl;
    else
        cout << "my_array1 is not nullptr" << endl;
    cout << endl;    // OUTPUT  my_array1 is not nullptr


    print_array(my_array1, 50);
    cout << endl; // OUTPUT Array Size: 50       Elements {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}


    deallocate_array(my_array1);
    if (is_nullptr(my_array1))
        cout << "my_array1 is nullptr" << endl;
    else
        cout << "my_array1 is not nullptr" << endl;
    cout << endl;   // OUTPUT my_array1 is nullptr


    int my_array_size = 10;
    int* my_array = new int[my_array_size] { 5, 6, 7, 8, 10, 11, 12, 34, 16, 14 };
    print_array(my_array, my_array_size);
    cout << endl;  // OUTPUT Array Size: 10  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}


    double_the_array(my_array, my_array_size);
    print_array(my_array, my_array_size);
    cout << endl;  //OUTPUT Array Size: 20  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}


    my_array[14] = 100;
    print_array(my_array, my_array_size);
    cout << endl; //OUTPUT Array Size: 20  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, -1, -1, -1, -1, 100, -1, -1, -1, -1, -1}
    half_the_array(my_array, my_array_size);
    print_array(my_array, my_array_size);
    cout << endl;  //OUTPUT Array Size: 10   Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}


    /*Slice of array */
    int my_slice_size = 0;
    int* my_slice =slice_of_array(my_array, my_array_size, 3, 5, my_slice_size);
    print_array(my_array, my_array_size);
    cout << endl;//OUTPUT Array Size: 10    Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    print_array(my_slice, my_slice_size);
    cout << endl;//OUTPUT Array Size: 3     Elements {8, 10, 11}


    /*mean of array */
    double mean = mean_array(my_array, my_array_size);
    cout << "mean= " << mean << endl;
    cout << endl;  // OUTPUT 12.3


    /* Concat arrays */
    int concat_array_size = 0;
    int my_array2_size = 3;
    int* my_array2 = new int[my_array2_size] { 10, 5, 6 };
    print_array(my_array, my_array_size);
    cout << endl;  //OUTPUT Array Size: 10 Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}


    print_array(my_array2, my_array2_size);
    cout << endl;  // OUTPUT Array Size: 3 Elements {10, 5, 6}


    int* concat_array =concatenate_arrays(my_array, my_array2, my_array_size, my_array2_size, concat_array_size);
    print_array(my_array, my_array_size);
    cout << endl;  // OUTPUT Array Size: 10 Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
            

    print_array(my_array2, my_array2_size);
    cout << endl;  //OUTPUT  Array Size: 3   Elements {10, 5, 6}
    print_array(concat_array, concat_array_size);
    cout << endl;  // OUTPUTArray Size: 13   Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14, 10, 5, 6}


    /*Compare array */
    cout << compare_array(my_array, my_array2, my_array_size, my_array2_size) << endl;
    cout << endl;  //OUTPUT  0
    cout << compare_array(my_array, my_array, my_array_size, my_array_size) << endl;
    cout << endl;//OUTPUT  1


    /*Sort arrays */
    print_array(my_array2, my_array2_size);
    cout << endl;  //OUTPUT Array Size: 3  Elements {10, 5, 6}
    sort_array(my_array2, my_array2_size);
    print_array(my_array2, my_array2_size);
    cout << endl;  //OUTPUT Array Size: 3 Elements {5, 6, 10}


    print_array(my_array, my_array_size);
    cout << endl;  //OUTPUT Array Size: 10  Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    int* my_array_sorted = sorted_copy(my_array, my_array_size);
    print_array(my_array, my_array_size);
    cout << endl;  //OUTPUT Array Size: 10       Elements {5, 6, 7, 8, 10, 11, 12, 34, 16, 14}
    print_array(my_array_sorted, my_array_size);
    cout << endl;  //OUTPUT  Array Size: 10       Elements {5, 6, 7, 8, 10, 11, 12, 14, 16, 34}
    deallocate_array(my_array_sorted);
    

    /*Exists */
    cout << exists(my_array, my_array_size, 1000) << endl;	//OUTPUT 0
    cout << endl;
    cout << exists(my_array, my_array_size, 34) << endl;	// OUTPUT 1
    cout << endl;
    

    /*Distinct */
    int my_array3_size = 6;
    int* my_array3 = new int[my_array3_size] { 44, 6, 7, 6, 7, 5 };
    print_array(my_array3, my_array3_size);
    cout << endl;  // OUTPUT Array Size: 6    Elements {44, 6, 7, 6, 7, 5} 


    int distinct_myarray3_copy_size = 0;
    int* distinct_myarray3_copy = distinct_copy(my_array3, my_array3_size, distinct_myarray3_copy_size);
    print_array(my_array3, my_array3_size);
    cout << endl;  // OUTPUT Array Size: 6     Elements {44, 6, 7, 6, 7, 5}
    print_array(distinct_myarray3_copy, distinct_myarray3_copy_size);
    cout << endl;  //OUTPUT Array Size: 4  Elements {44, 6,  7,  5}


    distinct_array(my_array3, my_array3_size);
    print_array(my_array3, my_array3_size);
    cout << endl;  //OUTPUT Array Size: 4     Elements {44, 6,  7,  5}

    deallocate_array(my_array);
    deallocate_array(my_array1);
    deallocate_array(my_array2);
    deallocate_array(my_slice);
    deallocate_array(distinct_myarray3_copy);
    deallocate_array(my_array3);
    deallocate_array(concat_array);
}
int* allocate_array(int p)
{
    int* arr = new int[p];
    for (int i = 0; i < p; i++)
    {
        arr[i] = 0;
    }
    return arr;
}
int is_nullptr(int* p)
{
    if (*p != 0)
        return true;
    else
        return false;
}
int* deallocate_array(int* p)
{
    delete[] p;
    p = nullptr;
    return p;
}
void double_the_array(int*& p, int& size)
{
    size = size * 2;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = p[i];
    }
    for (int i = (size / 2); i < size; i++)
    {
        arr[i] = -1;
    }
    delete[] p;
    p = arr;
    arr = nullptr;
}
void half_the_array(int*& p, int& size)
{
    size = size / 2;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = p[i];
    }
    delete[] p;
    p = arr;
    arr = nullptr;
}
int* slice_of_array(int* p, int size, int x, int y, int &size1)
{
    for (int i = x; i <= y; i++)
    {
        size1++;
    }
    int* arr = new int[size1];
    int j = 0;
    for (int i = x; i <= y; i++,j++)
    {
        *(arr+j) = *(p+i);
    }
    return arr;
}
double mean_array(int *p, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + p[i];
    }
    sum = sum / size;
    return sum;
}
int* concatenate_arrays(int* p, int* q, int size, int size1, int &size2)
{
    size2 = size + size1;
    int* arr = new int[size2];
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        *(arr+i) = *(p+i);
        count++;
    }
    for (int i = 0,j=count; i < size1; i++,j++)
    {
        *(arr+j) = *(q+i);
    }
    return arr;
}
bool compare_array(int* p, int* q, int size, int size1) 
{
    int flag=0;
    if (size != size1)
        return 0;
    if (size == size1)
    {
        for (int i = 0; i < size; i++)
        {
            if (p[i] == q[i])
                flag++;
            else
                return 0;
        }
    }
    if (flag == size && flag == size1)
        return 1;
    else
        return 0;
}
int* sort_array(int *&p, int size)
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    return p;
}
int* sorted_copy(int* p, int size)
{
    int temp=0;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = p[i];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
bool exists(int *p, int size, int num)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (p[i] == num)
        {
            flag++;
        }
    }
    if (flag == 0)
        return false;
        
    else
        return true;
}
int* distinct_copy(int* p, int size, int &size1)
{
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = p[i];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < size; k++)
                {
                    arr[k] = arr[k + 1];
                }
                size--;
                j--;
            }
        }
    }
    size1 = size;
    int* arr1 = new int[size1];
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[i];
    }
    return arr1;
    delete[]p;
    p = arr;
    arr = arr1;
    arr1 = nullptr;
}
int* distinct_array(int*& p, int &size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (p[i] == p[j])
            {
                for (int k = j; k < size; k++)
                {
                    p[k] = p[k + 1];
                    flag++;
                }
                size--;
                j--;
                
            }
        }
    }
    size = flag - 1;
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = p[i];
    }
    return arr;
    delete[] p;
    p = arr;
    arr = nullptr;
}
