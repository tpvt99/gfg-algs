#include <iostream>

using namespace std;

void interchange(int r, int c, int (*arr)[5]);

int main()
{
    int arr[5][5] = {{1,2,3,4,5}, {6,7,8,9,10}, {12,23,34,45,56}, {76,65,54,43,32}, {12,23,34,45,56}};
    interchange(5, 5, arr);
    return 0;
}

void interchange(int r, int c, int (*arr)[5])
{
  //Your code here
  int (*row_ptr)[5] = arr;
  int temp;
  for(;row_ptr< arr + r;row_ptr++) {
      temp = *(*row_ptr);
      *(*row_ptr) = *((*row_ptr)+c-1);
      *((*row_ptr)+c-1) = temp;
  }
  //Printing the modified matrix
    for(int i=0;i<r;i++)
	   {
	       for(int j=0;j<c;j++)
    	    {
    	        cout<<arr[i][j]<<" ";

    	    }
    	 cout<<endl;
	   }
}
