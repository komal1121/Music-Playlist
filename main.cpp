#include <iostream>
#include <limits>
#include <queue>
#include <string>
using namespace std;

class Playlist {
private:
    queue<string> songQueue;

public:
    void addSong() {
        string song;
        cout << "\nEnter song name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, song);

        if (song.empty()) {
            cout << ">> Song name cannot be empty.\n";
            return;
        }

        songQueue.push(song);
        cout << ">> \"" << song << "\" added to the playlist!\n";
    }

    void playNextSong() {
        if (songQueue.empty()) {
            cout << ">> Playlist is empty. No song to play.\n";
            return;
        }

        string song = songQueue.front();
        cout << ">> Now Playing: " << song << "\n";
        songQueue.pop();
    }

    void viewPlaylist() {
        if (songQueue.empty()) {
            cout << ">> Playlist is empty.\n";
            return;
        }

        queue<string> temp = songQueue;
        cout << "\n--- Current Playlist (play order) ---\n";
        int position = 1;
        while (!temp.empty()) {
            cout << position << ". " << temp.front() << "\n";
            temp.pop();
            position++;
        }
        cout << "------------------------------------\n";
    }

    void displayCurrentSong() {
        if (songQueue.empty()) {
            cout << ">> No song currently in the playlist.\n";
            return;
        }
        cout << ">> Current Song (up next): " << songQueue.front() << "\n";
    }

    void countSongs() {
        cout << ">> Total Songs in Playlist: " << songQueue.size() << "\n";
    }
};

void showHeader() {
    cout << "\n===== MUSIC PLAYLIST MANAGEMENT SYSTEM =====\n";
    cout << "A queue-based music app using FIFO order.\n";
    cout << "Add songs, play the next track, and view the playlist.\n";
}

void showMenu() {
    cout << "\n1. Add Song\n";
    cout << "2. Play Next Song\n";
    cout << "3. View Playlist\n";
    cout << "4. Display Current Song\n";
    cout << "5. Count Total Songs\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Playlist playlist;
    int choice = 0;

    showHeader();

    do {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: playlist.addSong(); break;
            case 2: playlist.playNextSong(); break;
            case 3: playlist.viewPlaylist(); break;
            case 4: playlist.displayCurrentSong(); break;
            case 5: playlist.countSongs(); break;
            case 6: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}