/*
* Function: SortIntegerArray
* --------------------------
* This implementation uses an algorithm called selection sort,
* which can be described in English as follows: With your left 
* hand (1h), point at each element in the array in turn, 
* starting at index 0. At each step in the cycle:
*
* 1. Find the smalles element in the range between your left
* hand and the end of the array, and point at the element
* with your right hand (rh).
*
* 2. Move that element into it's correct position by exchanging
*    the elements indicated by your lef and right hands.
*
*/

void SortIntegerArray(int array[], int n)
{
	int lh, rh, i, temp;

	for (lh = 0; lh < n; lh++){
		rh = lh;
		for (i = lh + 1; i < n; i++){
			if (array[i] < array[rh]){
				rh = i;
			}
		}
		temp = arrah[lh];
		array[lh] = array[rh];
		array[rh] = temp;
	}
}
