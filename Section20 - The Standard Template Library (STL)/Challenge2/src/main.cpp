#include <iostream>
#include <list>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <cctype>

class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;

public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const
    {
        return name;
    }
    std::string get_artist() const
    {
        return artist;
    }
    int get_rating() const
    {
        return rating;
    }
    bool operator<(const Song &rhs) const
    {
        return this->name < rhs.name;
    }
    bool operator==(const Song &rhs) const
    {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu()
{
    std::cout << "F - Play First Song\n"
              << "N - Play Next Song\n"
              << "P - Play Previous Song\n"
              << "A - Add and play a new Song at current location\n"
              << "L - List the current playlist\n"
              << std::setw(50) << std::setfill('=') << "" << std::endl
              << std::setfill(' ')
              << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
    // This function should display
    // Playing: followed by the song that is playing
    std::cout << "Playing:" << std::endl
              << song << std::endl << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
    // This function should display the current playlist
    // and then the current song playing
    std::for_each(playlist.begin(), playlist.end(), [&](const Song s) { std::cout << s << std::endl; });
    std::cout << "Current song:\n"
              << current_song << std::endl << std::endl;
}

void process_selection(const char &selection, std::list<Song> &playlist, std::list<Song>::iterator &current_song)
{
    switch (selection)
    {
    case 'F':
    case 'f':
    {
        current_song = playlist.begin();
        std::cout << "Playing first song" << std::endl;
        play_current_song(*current_song);
        break;
    }
    case 'N':
    case 'n':
    {
        if(++current_song == playlist.end())
            current_song = playlist.begin();
        std::cout << "Playing next song" << std::endl;
        play_current_song(*current_song);
        break;
    }
    case 'P':
    case 'p':
    {
        if(current_song == playlist.begin())
            current_song = --playlist.end();
        std::cout << "Playing previous song" << std::endl;
        play_current_song(*current_song);
        break;
    }
    case 'A':
    case 'a':
    {
        std::string name{};
        std::string artist{};
        int rating{};
        // discards the input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Adding and playing a new song" << std::endl;
        std::cout << "Enter song name: ";
        std::getline(std::cin, name);
        std::cout << "Enter song artist: ";
        std::getline(std::cin, artist);
        std::cout << "Enter song rating (1-5): ";
        std::cin >> rating;
        playlist.emplace(current_song, name, artist, rating);
        current_song--;
        play_current_song(*current_song);
        break;
    }
    case 'L':
    case 'l':
    {
        display_playlist(playlist, *current_song);
        break;
    }
    case 'q':
    case 'Q':
        std::cout << "Goodbye" << std::endl;
        break;
    default:
        std::cout << "Unknown option -- try again..." << std::endl;
    }
}

int main()
{
    std::list<Song> playlist{
        {"God's Play", "Drake", 5},
        {"Never Be The Same", "Camila Cabello", 5},
        {"Pray For Me", "The Weekend and K.Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroon 5", 5},
        {"Whatever It Takes", "Imagine Dragons", 3}};

    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    char selection{};
    do
    {
        display_menu();
        std::cin >> selection;
        process_selection(selection, playlist, current_song);
    } while (selection != 'q' && selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
