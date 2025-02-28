#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void printList(list<string> s) {
    list<string>::iterator i;
    for (i = s.begin(); i != s.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";
}

int main() {
    list<string> line_up;
    list<string>::iterator loc;

    // Alice stands in the queue first
    line_up.push_back("Alice");

    // Bob joins the queue
    line_up.push_back("Bob");

    // Oscar cuts in front of Bob
    loc = find(line_up.begin(), line_up.end(), "Bob");
    line_up.insert(loc, "Oscar");

    // Luffy, Sanji, Nami join at the back
    line_up.push_back("Luffy");
    line_up.push_back("Sanji");
    line_up.push_back("Nami");

    // First two people (Alice and Oscar) go into the restroom
    line_up.pop_front();  // Alice
    line_up.pop_front();  // Oscar

    // Naruto cuts after Luffy
    loc = find(line_up.begin(), line_up.end(), "Luffy");
    line_up.insert(++loc, "Naruto");

    // Prayath cuts at the front
    line_up.push_front("Prayath");

    // Tony joins after Prayath
    loc = find(line_up.begin(), line_up.end(), "Prayath");
    line_up.insert(++loc, "Tony");

    // Bob leaves the queue
    loc = find(line_up.begin(), line_up.end(), "Bob");
    if (loc != line_up.end()) {
        line_up.erase(loc);  // Remove Bob
    }

    // First three people (Oscar, Luffy, Sanji) go into the restroom
    line_up.pop_front();  // Oscar
    line_up.pop_front();  // Luffy
    line_up.pop_front();  // Sanji

    // Print the final list
    printList(line_up);

    return 0;
}
