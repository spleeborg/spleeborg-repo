#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
	node* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int len = length(head);
	char* string = (char*)malloc((size_t)(len + 1) * sizeof(char));

	if (string == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	node* temp = head;
	int i = 0;
	while (temp != NULL)
	{
		string[i] = temp->letter;
		temp = temp->next;
		i++;
	}

	string[i] = '\0';
	return string;


}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL)
    {
        exit(1); 
    }

    temp->letter = c;
    temp->next = NULL;

    if (*pHead == NULL)
    {
        // if the list is empty, set the new node as the head
        *pHead = temp;
    }
    else
    {
        
        node* lastNode = *pHead;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = temp;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	while (*pHead != NULL)
	{
		node* temp = *pHead;
		*pHead = (*pHead)->next;
		free(temp);
	}
	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
			
			
		}

		str = toCString(head);
		
		printf("String is : %s\n", str);
		//printf("\n \nThe count of nodes is: %d", length(head));
		
		free(str);
		
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}
	
	fclose(inFile);
}