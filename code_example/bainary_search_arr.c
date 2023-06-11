#include <stdio.h>

int  binarySearch(int arr[] , int n,int element);
/*
// Function to perform binary search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Key not found
    return -1;
}

*/



void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    key = 22;

    int result = binarySearch(arr, n, key);

    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    return 0;
}




//bable sort  commper each two elements and flip if needed 
/*
void babel_sort(int arr,int n) 
{
    for(int i = 0 ; i < n -1  ;i++)
        for(int j = 0  ; l < n-i-1  ;j++ )
            {
                if(arr[j] > arr[j+1])
                {
                    //swap 
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                }

            }



}


*/



//binarry search (find given element)
// on a sorted Arr
//--------------M(n/2)---------------
//i ------------M(n/2)  j -------N  


int  binarySearch(int arr[] , int n , int element)
{

    int i , j ;
    i = 0;
    j = n ;
    int M;
    
    while(i < j){

        M = j / 2;     
        if(arr[M] == element){
            printf("element found at index %d",M);
            break;
        }
        else if (arr[M] < element)
        {
            //search right 
            i = M+1;
            
        }
        else{
            j = M +1; 
            //serach left 

        }
        

    }
    return M;


 }
    
    




    



