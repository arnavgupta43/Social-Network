# Social-Network
This project is a simple social network simulator implemented in C. It uses graph theory concepts to represent users and their friendships, where each user is a node and each friendship is an edge between two nodes. Additionally, the program provides friend recommendations based on mutual friends, showcasing the application of adjacency lists and graph traversal.

Features
User Management: Add users to the social network.
Friendship Management: Create bidirectional friendships between users.
Friend Recommendations: Recommend friends to users based on their existing friends' connections (mutual friends).
Network Visualization: Display the entire social network and each user's friends.

Project Structure
main.c: Contains the full implementation of the social network, including user management, friendship management, and friend recommendation algorithms.
README.md: Project documentation and usage guide.


Example Output
When you run the program, you will see something like the following output:

Alice's friends: Bob 
Bob's friends: Alice Charlie 
Charlie's friends: Bob David 
David's friends: Charlie Eve 
Eve's friends: David Frank 
Frank's friends: Eve 

Friend recommendations for Alice: Charlie 
Friend recommendations for David: Frank 
Friend recommendations for George: No recommendations available

Code Breakdown
Data Structures
User: Each user is represented as a node (a struct) with a name and a linked list of friends.
socialNetwork: An array of User* that stores all users in the network.

Core Functions
createUser(): Creates a new user with a given name.
addUser(): Adds a user to the social network array.
addFriendship(): Establishes a friendship between two users.
printNetwork(): Prints the list of all users and their friends.
recommendFriends(): Recommends friends based on mutual friendships.


Friend Recommendation Logic
The friend recommendation system works by examining each friend of the user's friends and suggesting those who are not directly connected to the user. This is an application of graph traversal where the user's friends are treated as adjacent nodes in the graph.

Algorithm Performance and Complexity
The graph is represented using an adjacency list, making it efficient for operations like adding users, creating friendships, and traversing the network.

Time Complexity:
Adding a user: O(1)
Adding a friendship: O(1)
Friend recommendation: O(n + m) where n is the number of users and m is the number of friendships.
Space Complexity:
Overall space complexity: O(n + m), where n is the number of users and m is the number of friendships (edges).
Future Enhancements

Some potential improvements include:

Mutual Friend Count: Ranking recommendations based on the number of mutual friends.
Shortest Path Between Users: Finding the shortest path between two users (like in social networking platforms).
Graph Visualization: Adding visual representation for the network using a tool like Graphviz or a GUI-based application.
License

This project is licensed under the MIT License. Feel free to use, modify, and distribute as needed.
