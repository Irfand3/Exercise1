#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//struct declaration
struct element
{
     int id;
     int value;
};

//compare for sorting algorithm
bool compare(element a, element b)
{
	if(a.value < b.value)
		return 1;
	else
		return 0;
}

int main()
{
    //variable declaration
    int SIZE=5; //size of array
    struct element a[SIZE]; //array of structures
    int finalResult; //to store final result
    element result; //struct for result


    //to enter values in array of structs, ids are incremently added
    for (int i=0; i<SIZE; i++){
        cout <<"Enter element in array: "<<endl;
        cin>> a[i].value;
        a[i].id=i;
    }
    cout<<"Cin finished"<<endl;

    //sort array of structs
    sort(a,a+SIZE,compare);

    //nested for loop to count how many times value appear in array
    for (int i=0; i<SIZE; i++){
        int counter = 0;

       for(int j=0; j<SIZE; j++)
       {
           if(a[i].value == a[j].value)
           {
               counter++;
           }
       }

        //when we get element that appears at least twice in a list
       if(counter >=2)
       {
           //take that value and add 1 one to
         int checkValue = a[i].value + 1;
         //for loop that goes from index of value to check
          for(int k=i; k<SIZE; k++){

                //if our value to check is not presented in a list and it is a positive number, we take that value as a result.
            if(checkValue != a[k].value && checkValue > 0)
            {
                finalResult = checkValue;
                result.value=finalResult;
                result.id=SIZE+1;
            }
            else
                checkValue++;
          }
       }

       cout <<"Value: "<<a[i].value << " Appears: " << counter <<endl;


    }

    cout << "Final result: " << result.value<< " with ID: " << result.id << endl;


    return 0;
}
