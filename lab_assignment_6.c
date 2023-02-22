#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    while (low <= high)
        if (numbers[low] == value)
            return low;
        else
            search(numbers, ++low, high, value);
    return -1;
}

void printArray(int numbers[], int sz) {
    int i;
    printf("Number array : ");
    for (i = 0; i < sz; ++i)
        printf("%d ",numbers[i]);
    printf("\n");
}

int main(void) {
    int i, numInputs;
    char* str;
    float average;
    int value;
    int index;
    int* numArray = NULL;
    int countOfNums;
    FILE* inFile = fopen("input.txt","r");

    fscanf(inFile, " %d\n", &numInputs);
    
    while (numInputs-- > 0) {
        fscanf(inFile, " %d\n", &countOfNums);
        numArray = (int *) malloc(countOfNums * sizeof(int));
        average = 0;
        
        for (i = 0; i < countOfNums; i++) {
            fscanf(inFile," %d", &value);
            numArray[i] = value;
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        value = average / countOfNums;
        index = search(numArray, 0, countOfNums - 1, value);
        if (index >= 0)
            printf("Item %d exists in the number array at index %d!\n",value, index);
        else
            printf("Item %d does not exist in the number array!\n", value);

        free(numArray);
    }
    fclose(inFile);
}

//typedef struct node {
//    int data;
//    struct node *link;
//}node;
//
//void addAtEnd(node *head, int data){    //####### KEEP FOR TESTING ######## INSERTS A NODE AT THE END OF A SINGLY LINKED LIST
//    node *current, *temp;
//    current = head;
//    temp = (node *) malloc(sizeof(node));
//
//    temp->data = data;
//    temp->link = NULL;
//
//    while (current->link != NULL)
//        current = current->link;
//    current->link = temp;
//}
//
//void countOfNodes(node *head){
//    int count = 0;
//    if (head == NULL)
//        printf("List is empty");
//    node *current = NULL;
//    current = head;
//    while (current != NULL) {
//        current = current->link;
//        count++;
//    }
//    printf("total: %d\n", count);
//}
//
//int main() {
//
//    return 0;
//}
//



//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node{
//    int data;
//    struct node *next;
//}node;
//
////typedef struct stack{
////    int data;
////    struct stack
////}
//
//void insertAfterN(node* head, int M, int N){
//    node *current = head;
//    while (current != NULL) {
//        if(current->data == N){
//            node *temp = (node *) malloc(sizeof(node));
//            temp->data = M;
//            temp->next = current->next;
//            current->next = temp;
//        }
//        current = current->next;
//    }
//}
//
//void insertEnd(node **head, int value){  //####### KEEP FOR TESTING ######## INSERTS A NODE AT THE END OF A SINGLY LINKED LIST
//    node *temp = (node *) malloc(sizeof(node));
//
//    temp->data = value;
//    temp->next = NULL;
//
//    if (*head == NULL)
//        *head = temp;
//    else{
//        node *current = *head;
//        while (current->next != NULL) {
//            current = current->next;
//        }
//        current->next = temp;
//    }
//}
//
//void printList(node *head){   //####### KEEP FOR TESTING ####### PRINTS THE VALUES OF A SINGLY LINKED LIST
//    printf("List:");
//    while (head != NULL) {
//        printf("%d ", head->data);
//        head = head->next;
//    }
//    printf("\n");
//}
//
//int isPalindrome(char *str) {
//    struct stack s;
//    initialize(&s);
//    int len = strlen(str);
//
//    for (int i = 0; i < len; i++)
//        push(&s, str[i]);
//
//    for (int i = 0; i < len; i++)
//        if (str[i] != pop(&s))
//            return 0; // Not a palindrome
//    return 1;
//}
//
//
//int main() {
//    node *head = NULL;
//
//    insertEnd(&head, 3);
//    insertEnd(&head, 6);
//    insertEnd(&head, 4);
//    insertEnd(&head, 6);
//    insertEnd(&head, 6);
//    insertEnd(&head, 5);
//
//    printList(head);
//
//    insertAfterN(head, 200, 6);
//
//    printList(head);
//
//}
