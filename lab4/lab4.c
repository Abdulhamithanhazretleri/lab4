#include <stdio.h>
#include <string.h>
#include "stdlib.h"
struct node {
    char tagname[10];
    struct node *next;
};
int uzunluk(char inp[]) {
    int len;
    for (int i = 0; i < 99999; i++) {
        if (inp[i] == '\n') {
            inp[i] = '\0';
        }
    }
    len = strlen(inp);
    return len;
}

void generateOutput(char input[], char output[]) {
    int length = uzunluk(input);
    int insideTag = 0;
    int outputIndex = 0;

    for (int i = 0; i < length; i++) {
        if (input[i] == '<') {
            insideTag = 1;
            output[outputIndex++] = input[i];
        } else if (input[i] == '>') {
            insideTag = 0;
            output[outputIndex++] = input[i];
        } else if (insideTag) {
            output[outputIndex++] = input[i];
        }
    }

    // Null-terminate the output string
    output[outputIndex] = '\0';
}

int main() {
    int ý = 0;
    char input[99999];
    fgets(input, 99999, stdin);
    char output[99999];
    struct node *head = NULL;
    struct node *root = NULL;
    generateOutput(input, output);
    char tagnam[20];
    int j;

    for (int i = 0; i < strlen(output); ++i) {
        if (output[i - 1] == '<') {
            j = 0;
            while (output[i] != '>' && j < 19) {
                tagnam[j] = output[i];
                j++;
                i++;
            }
            tagnam[j] = '\0';  // Null-terminate the tag name
            if (head != NULL) {
                if (tagnam[0] == '/') {
                    // Baþýndaki '/' sembolünü kaldýr
                    memmove(tagnam, tagnam + 1, strlen(tagnam));

                    // Þimdi tagnam ile head->tagname'i karþýlaþtýr
                    if (strcmp(tagnam, head->tagname) == 0) {
                        if (head == root){

                            head == NULL;

                            printf("correct");



                        } else{
                        // Stack'tan en üstteki elemaný sil
                        struct node *temp = head;
                        head = head->next;
                        free(temp);
                         }
                    } else{
                        printf("error <%s> \n",head->tagname);
                        break;
                        char tempp[20];
                        strcpy(tempp, "/");
                        strcat(tempp, tagnam);

                            struct node *yeni = (struct node *) malloc(sizeof(struct node));
                            yeni->next = NULL;


                            strcpy(yeni->tagname, tempp);


                            // Add the new node to the stack
                            yeni->next = head;
                            head = yeni;



                    };

                } else {
                    // Create a new node for the opening tag
                    struct node *yeni = (struct node *) malloc(sizeof(struct node));
                    yeni->next = NULL;
                    strcpy(yeni->tagname, tagnam);

                    // Add the new node to the stack
                    yeni->next = head;
                    head = yeni;
                }
            }

            if (head == NULL) {
                // Create a new node for the opening tag
                struct node *yeni = (struct node *) malloc(sizeof(struct node));
                yeni->next = NULL;

                strcpy(yeni->tagname, tagnam);

                // Set the head and root to the new node
                head = yeni;
                root = yeni;
            }
        }
    }






    return 0;
}
