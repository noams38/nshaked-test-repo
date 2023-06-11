#include <stdio.h>
#include <stdbool.h>
#include <string.h>






/*
 האם המחרוזת או המספר הוא פולינדרום. הפונקציה משתמשת בלולאת while כדי לבדוק האם התווים בתחילת המחרוזת זהים לתווים בסוף המחרוזת, ומחזירה אמת אם המחרוזת היא פולינדרום או שקר אחרת.

בתוכנית זו, הגדרנו מערך של תווים בגודל 100. זה מספיק גדול כדי לקבל כל מחרוזת או מספר שהמש

*/

int isPolydrom(char * Arr, int len);


void main()
{

    char Arr[100];
    int n;

    printf ("please enter a string to check if Ploydrom \n");
    scanf("%s",Arr);
    n = strlen(Arr);

    if (isPolydrom(Arr,n))
        printf("the provided string is polydrom \n");
    else
        printf("the provided string is NOT !!! polydrom \n");
    

}

int isPolydrom(char * Arr, int len)
{
    int i=0 , j=0 ;

    j = len-1;

    while(i < j)
    {
        if(Arr[i] != Arr[j])
            return 0;
        else{
            i++;
            j--;
        }
        return 1;

    }

}













/*
bool isPalindrome(char arr[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (arr[i] != arr[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char arr[100];
    printf("Enter a string or number: ");
    scanf("%s", arr);
    int n = strlen(arr);
    if (isPalindrome(arr, n)) {
        printf("%s is a palindrome\n", arr);
    }
    else {
        printf("%s is not a palindrome\n", arr);
    }
    return 0;
}
*/
