#include <stdio.h>
#include <stdlib.h>

struct Node {
    void* value; // I use void* in order to pass various data types.
    struct Node* next;
};

struct Node* createNode() { // Creates the head Node and returns a pointer to it.

    struct Node* head;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->value = NULL;
    head->next = NULL;
    return head;
};

void pushElement(struct Node* hNode, void* element) { // Pushes a new Node at the end of the Node chain.
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = element;
    newNode->next = NULL;

    struct Node* currentNode = hNode;

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;

    return;
}

void popElement(struct Node* hNode) { // Delete/Pop the last Node from the Node chain.
    struct Node* currentNode = hNode;
    while (currentNode->next != NULL) {
        if ((currentNode->next)->next == NULL) {
            struct Node* tempNode = currentNode->next;
            currentNode->next = NULL;
            currentNode = tempNode;
            break;
        }
        currentNode = currentNode->next;
    }
    free(currentNode);

    return;
}

void* getElement(struct Node* hNode, int index) { // Get the value attribute from a Node by it's index (Starting from 0).
    // Indexes like: -1,-2, are not supported yet.
    struct Node* currentNode = hNode;
    int counter = -1;
    if (currentNode->next == NULL) {
        printf("This Node Has No Elements\n");
        return;
    }
    do {
        counter++;
        currentNode = currentNode->next;

        if (counter == index) {
            return (void*)(currentNode->value);
        }
    } while (currentNode->next != NULL);

    printf("Index out of bound.\n");
    return;
}

//Not as D.R.Y as possible, but it works for now...
void printNodeInt(struct Node* hNode) {
    if (hNode->next == NULL) {
        printf("This Node Has No Elements.\n");
        return;
    }
    int counter = 0; // Element Counter

    struct Node* currentNode = hNode;

    do {
        currentNode = currentNode->next;
        printf(
            "Element #%d: %3d (Node Memory Address: 0x%x) (Next Node Memory Address: 0x%x)\n",
            counter, *(int*)(currentNode->value), currentNode, currentNode->next); //Typecast to int* in order to dereference the pointer and get the value.
        counter++;
    } while (currentNode->next != NULL);

    return;
}

void printNodeFloat(struct Node* hNode) {
    if (hNode->next == NULL) {
        printf("This Node Has No Elements.\n");
        return;
    }
    int counter = 0; // Element Counter

    struct Node* currentNode = hNode;

    do {
        currentNode = currentNode->next;
        printf(
            "Element #%d: %8.4f (Node Memory Address: 0x%x) (Next Node Memory Address: 0x%x)\n",
            counter, *(float*)(currentNode->value), currentNode, currentNode->next);
        counter++;
    } while (currentNode->next != NULL);

    return;
}

void printNodeStr(struct Node* hNode) {
    if (hNode->next == NULL) {
        printf("This Node Has No Elements.\n");
        return;
    }
    int counter = 0; // Element Counter

    struct Node* currentNode = hNode;

    do {
        currentNode = currentNode->next;
        printf(
            "Element #%d: %3s (Node Memory Address: 0x%x) (Next Node Memory Address: 0x%x)\n",
            counter, (char*)(currentNode->value), currentNode, currentNode->next); //I don't dereference the char* because i need the whole string.
            //Dereferencing the pointer will return the first character of the string.
        counter++;
    } while (currentNode->next != NULL);

    return;
}

int main(int argc, char const* argv[]) {
    struct Node* intNode = createNode();
    struct Node* floatNode = createNode();
    struct Node* strNode = createNode();

    //Sample Data
    int dataInt[5] = {19, 222, 364, 12, 87};
    float dataFloat[5] = {19.05f, 22.42f, 3.064f, 7.12f, 14.87f};
    char dataStr[5][4] = {"ABC", "DEF", "GHI", "JKL", "MNO"};
    int i;
    for (i = 0; i < 5; i++) {
        pushElement(intNode, &dataInt[i]);
        pushElement(floatNode, &dataFloat[i]);
        pushElement(strNode, &dataStr[i]);
    }

    //Print All The Nodes (Node Chain)
    printf("\n\t\t\t |Integer Nodes|\n\n");
    printNodeInt(intNode);
    printf("\n\t\t\t |Float Nodes|\n\n");
    printNodeFloat(floatNode);
    printf("\n\t\t\t |String Nodes|\n\n");
    printNodeStr(strNode);

    return 0;
}
