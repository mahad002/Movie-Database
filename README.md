# Movie-Database

In this question, you are required to create a movie database. The movie database will contain list of
movies along with the actors that worked in that particular movie. You are required to create this
database using Linked List data structure. First, let us talk about the details of each node in the linked
list. Your node structure shall contain the following information:
1) String (to store name of the movie or an actor)
2) Pointer to the next node in the linked list
3) Pointer to the node below the current node
Data for the movie database is provided to you in a file named “movie.txt”.
Following is the format of data in the movie file:
Movie name 1
Actor name
Actor name
Actor name
#
Movie name 2
Actor name
Actor name
Actor name
#

(After list of actors we have # sign in the next line).
The first line in “movie.txt” file would contain the name of a particular movie. You have to store this
name in the string of the node (details given above). For the next few lines, you will have list of actors
who have worked in that particular movie. Each single line would contain name of only one actor. As
soon as the lists of actors end, you will have a # symbol. In the next line, you will have another movie
name (which will always be unique) followed by its list of actors and then again a # sign.

For the first linked list, you need to arrange the file information in such a way that each parent node
of the linked list contains name of the movies. Each parent node has two pointers. The “next” pointer
points to another parent node which has name of some other movie in it. The “below” pointer points
to the actor who has worked in the movie. So essentially, the first row of the linked list (containing
parent nodes) has list of all the movies in it. Below each movie node is the list of all the actors that
have worked in that movie.

For second linked list, the parent node would represent actors and the child node represents movies
corresponding to that actor. Both the linked lists take a structure like branches of a tree.

After you have constructed both linked lists, user will have two types of options to perform searching
a) Search by movie name
If the user enters a movie name then you will have to display all actors against that movie by
performing search in the first linked list.
b) Search by actor name.
If the user opts for actor name then you need to display all the movies corresponding to that
actor by performing search in the second linked list.

By constructing the above linked lists, you can also answer questions like:
i) On average how many films does an actor work in?
ii) ii) On average how many actors does a film typically has?

IMPORTANT NOTE:
Since File I/O is a very costly operation, you are required to traverse the file once and create link lists
simultaneously; otherwise you will lose 50% marks for this problem.
