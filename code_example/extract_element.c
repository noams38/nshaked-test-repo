#include <stdio.h> 
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



/* 1,2,3,4,5 */


bool extract_element(int * arr,size_t size ,int index )
{

  int extract = arr[index];

  if(size == 0 || index >= size)
  {
	  printf("wrong size or index\n");
	  return false ;
  }
  memcpy(arr+1 , arr ,sizeof(arr[index])*index) ;
  arr[0]=0;


  for (int i =0;i<size;i++ )
	  printf(" %d ",arr[i]);
 
	
  return true;

}


void main(int argc,char **argv)
{

   int arr[]={1,2,3,4,5};
   int index = 3 ;
   
   //if(argc<2)
	//printf("please enter index to extract in teh commandline \n");

   //index = atoi(argv[1]);


   int arr_size = sizeof(arr)/sizeof(arr[0]);
   bool flag;
   flag = extract_element(arr,arr_size,index);
}






