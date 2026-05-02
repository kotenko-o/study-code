#include <string>
#include <iostream>

class Note {
    private:
        std::string* text;
    public:
        Note(std::string note);
        Note(Note &note);
        ~Note();
        void display();
};

Note::Note(std::string note) {
    this->text = new std::string;
    *text = note;
}

Note::~Note() {
    delete(this->text);
    this->text = nullptr;
    std::cout << "Memory released." << std::endl;
}

void Note::display() {
    std::cout << *this->text << std::endl;
}

Note::Note(Note &note) {
    this->text = new std::string;
    *this->text = *note.text;
}

int main() {
    Note note = Note("Some Text");
    Note note_1 = Note(note);
    note.display();
    note_1.display();
    note.~Note();
    note_1.display();
    return 0;
}