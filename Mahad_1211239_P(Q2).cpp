#include<iostream>
#include <fstream>
#include<cstring>
#include<cctype>
#include <string>

using namespace std;

struct node {
	string name;
	node* next;
	node* down;
};

node* Create(string s) {
	node* newNode = new node();
	newNode->name = s;
	newNode->next = NULL;
	newNode->down = NULL;
	return newNode;
}

node* insertMovie(node*& Movie, string s) {
	node* newMovie = Create(s);
	if (Movie == NULL) {
		return newMovie;
	}
	Movie->next = newMovie;
	return newMovie;

}

node* insertActor(node*& Actor, string s) {
	node* newActor = Create(s);
	if (Actor == NULL) {
		return newActor;
	}
	Actor->down = newActor;
	return newActor;
}

void search(node* root, string s, bool check) {
	node* findMovie = root;
	while (findMovie != NULL) {
		if (findMovie->name == s) {
			break;
		}
		findMovie = findMovie->next;
	}
	if (check) {
		if (findMovie == NULL) {
			cout << "Movie not found.\n";
			return;
		}
		cout << "Actors in " << s << "\n";
	}
	else {
		if (findMovie == NULL) {
			cout << "Actor not found.\n";
			return;
		}
		cout << "Movies by " << s << "\n";
	}
	node* printActors = findMovie->down;
	while (printActors != NULL) {
		cout << printActors->name << "\n";
		printActors = printActors->down;
	}
	return;
}

void dulplicate(node* head)
{
	node* n1 = head;
	node* n2 = head;
	node* n5 = head;
	while (n1) {
		while (n2) {
			if (n1->name == n2->name) {
				if (n2 == n1) {
					cout << "Actor: " << n1->name << endl;
					//n5->next = n2->next;
					n5 = n2;
					n2 = n2->next;
					continue;
				}
				cout << "Actor: " << n1->name << endl;
				node* n4 = n1;
				while (n4->down) {
					n4 = n4->down;
				}
				//n4 = n2->down;
				n4 = insertActor(n4, n2->down->name);
				//cout << "    Movie: " << n4->name << endl;
				n5->next = n2->next;

			}
			n5 = n2;
			n2 = n2->next;
		}
		if (n1) {
			n2 = n1;
		}
		n1 = n1->next;

	}
}

void createLists(node*& movie, node*& actor) {
	fstream input;
	int count_m = 0;
	int count_a = 0;
	string curr_Movie;
	node* curr_actors2 = NULL;
	node* curr_movie2 = NULL;
	input.open("movie.txt", ios::in);
	if (input.is_open()) {
		string movieName;
		node* currentMovie = NULL;
		while (getline(input, movieName)) {
			currentMovie = insertMovie(currentMovie, movieName);
			if (movie == NULL) {
				movie = currentMovie;
			}

			string actors;
			node* currentActor = NULL;
			//curr_actors2 = NULL;
			while (getline(input, actors)) {
				if (actors == "#") {
					break;
				}
				currentActor = insertActor(currentActor, actors);
				curr_actors2 = insertMovie(curr_actors2, actors);
				if (currentMovie->down == NULL) {
					currentMovie->down = currentActor;
				}
				if (actor == NULL) {
					actor = curr_actors2;
				}
				curr_movie2 = insertActor(curr_movie2, movieName);
				if (curr_actors2->down == NULL) {
					curr_actors2->down = curr_movie2;
				}
				count_a++;
				curr_movie2 = NULL;

			}

			count_m++;
			//currentMovie = currentMovie;
		}
		input.close();
	}
}

double average(node* Node) {
	node* curr1 = Node;
	node* curr2 = NULL;
	int count1 = 0, count2 = 0;
	while (curr1) {
		curr2 = curr1->down;
		while (curr2) {
			curr2 = curr2->down;
			count2++;
		}
		count1++;
		curr1 = curr1->next;
	}
	return (count2 / (count1 * 1.0));
}

int main() {
	node* movie = NULL;
	node* actor = NULL;
	createLists(movie, actor);

	dulplicate(actor);
	int x = 0;
	cout << "=====================================\n";
	cout << "             Question 2\n";
	cout << "=====================================\n";

	string value;
	cin.clear();
	cout << " 1. Search list by Movie Name \n 2. Search list by Actor Name\n 3. Average Actors per Movie\n 4. Average Movies per Actor\n";
	cout << "-------------------------------------\n";
	cout << "Enter your Movie name: ";
	getline(cin, value);
	search(movie, value, true);
	cout << "\n-------------------------------------\n\n";
	cout << "Enter your Actor name: ";
	getline(cin, value);
	search(actor, value, false);
	cout << "\n-------------------------------------\n\n";
	cout << "Average actors per movie: " << average(movie) << endl;
	cout << "\n-------------------------------------\n\n";
	cout << "Average movies per actor: " << average(actor) << endl;
	cout << "=====================================\n";

	return 0;
}