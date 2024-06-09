#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// true or false game
typedef struct {
    char question[60];
    bool isTrue;
} Question;

typedef struct {
    Question* questions;
    int numOfQuestions;
    int capacity;
} ListOfQuestions;

void init_list(ListOfQuestions* list, int capacity){
    list->capacity = capacity;
    list->numOfQuestions = 0;
    list->questions = malloc(list->capacity * sizeof(Question));
}

int create_and_append_question(ListOfQuestions* list, char question[], bool isTrue) {
    if(list->capacity == list->numOfQuestions) {
        printf("the list of question is full");
        return 1;
    }
    Question quest;
    strcpy(quest.question, question);
    quest.isTrue = isTrue;

    list->questions[list->numOfQuestions] = quest;
    list->numOfQuestions++;
    return 0;
}

void print(ListOfQuestions* list) {
    for(int i = 0; i < list->numOfQuestions; i++) {
        printf("%s\n", list->questions[i].question);
        printf("%d\n", list->questions[i].isTrue);
    }
}

int main() {
    ListOfQuestions list;
    init_list(&list, 10);
    create_and_append_question(&list, "Bananas is always yellow", false); 
    create_and_append_question(&list, "Paris is the capital of France", true); 
    create_and_append_question(&list, "The highest mountian in the world is 8048 meters over the sea", true); 

    print(&list);

  return 0;
}

