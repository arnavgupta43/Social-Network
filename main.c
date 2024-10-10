#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LEN 30

typedef struct User {
    char name[MAX_NAME_LEN];
    struct User* next;  
} User;
User* socialNetwork[MAX_USERS];
int userCount = 0;

User* createUser(const char* name) {
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->name, name);
    newUser->next = NULL;
    return newUser;
}

void addUser(const char* name) {
    socialNetwork[userCount++] = createUser(name);
}


int findUserIndex(const char* name) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(socialNetwork[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}


void addFriendship(const char* name1, const char* name2) {
    int index1 = findUserIndex(name1);
    int index2 = findUserIndex(name2);
    
    if (index1 == -1 || index2 == -1) {
        printf("User not found!\n");
        return;
    }


    User* friend1 = createUser(socialNetwork[index2]->name);
    friend1->next = socialNetwork[index1]->next;
    socialNetwork[index1]->next = friend1;

    
    User* friend2 = createUser(socialNetwork[index1]->name);
    friend2->next = socialNetwork[index2]->next;
    socialNetwork[index2]->next = friend2;
}


void printNetwork() {
    for (int i = 0; i < userCount; i++) {
        printf("%s's friends: ", socialNetwork[i]->name);
        User* temp = socialNetwork[i]->next;
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}


void recommendFriends(const char* name) {
    int userIndex = findUserIndex(name);
    if (userIndex == -1) {
        printf("User not found!\n");
        return;
    }

    int mutualFriendFound = 0;
    printf("Friend recommendations for %s: ", name);
    
  
    User* user = socialNetwork[userIndex];
    User* temp = user->next;
    
   
    while (temp != NULL) {
        int friendIndex = findUserIndex(temp->name);
        User* friendOfFriend = socialNetwork[friendIndex]->next;

        while (friendOfFriend != NULL) {
           
            if (findUserIndex(friendOfFriend->name) != userIndex && 
                findUserIndex(friendOfFriend->name) != -1) {
                printf("%s ", friendOfFriend->name);
                mutualFriendFound = 1;
            }
            friendOfFriend = friendOfFriend->next;
        }
        temp = temp->next;
    }

    if (!mutualFriendFound) {
        printf("No recommendations available");
    }
    printf("\n");
}

int main() {
    
    addUser("Alice");
    addUser("Bob");
    addUser("Charlie");
    addUser("David");
    addUser("Eve");
    addUser("Frank");
  
    addFriendship("Alice", "Bob");
    addFriendship("Bob", "Charlie");
    addFriendship("Charlie", "David");
    addFriendship("David", "Eve");
    addFriendship("Eve", "Frank");


    printNetwork();
  
    recommendFriends("Alice");
    recommendFriends("David");
    recommendFriends("George");

    return 0;
}

//OUTPUT
// Alice's friends: Bob 
// Bob's friends: Alice Charlie 
// Charlie's friends: Bob David 
// David's friends: Charlie Eve 
// Eve's friends: David Frank 
// Frank's friends: Eve 

// Friend recommendations for Alice: Charlie 
// Friend recommendations for David: Frank 
// Friend recommendations for George: No recommendations available

