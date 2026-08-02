/*
    Music Playlist Using Queue
    ---------------------------
    A console-based music playlist manager built with the STL queue
    to demonstrate push, pop, front, empty, and size operations.

    Features:
      1. Add a new song
      2. Play the next song
      3. View the playlist
      4. Display the current song
      5. Count total number of songs
      6. Exit
*/

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Playlist {
private:
    queue<string> songQueue;   // main queue holding the playlist

public:
    // 1. Add a new song to the rear of the queue
    void addSong() {
        string song;
        cout << "Enter song name: ";
        cin.ignore();
        getline(cin, song);

        songQueue.push(song);
        cout << ">> \"" << song << "\" added to the playlist!\n";
    }

    // 2. Play the next song (front of the queue)
    void playNextSong() {
        if (songQueue.empty()) {
            cout << ">> Playlist is empty. No song to play.\n";
            return;
        }

        string song = songQueue.front(); // read the song at the front
        cout << ">> Now Playing: " << song << "\n";
        songQueue.pop();                 // remove it after playing
    }

    // 3. View the entire playlist (without losing data)
    void viewPlaylist() {
        if (songQueue.empty()) {
            cout << ">> Playlist is empty.\n";
            return;
        }

        queue<string> temp = songQueue; // copy to preserve original queue
        cout << "\n--- Current Playlist (play order) ---\n";
        int position = 1;
        while (!temp.empty()) {
            cout << position << ". " << temp.front() << "\n";
            temp.pop();
            position++;
        }
        cout << "--------------------------------------\n";
    }

    // 4. Display the current song (front of the queue, without removing it)
    void displayCurrentSong() {
        if (songQueue.empty()) {
            cout << ">> No song currently in the playlist.\n";
            return;
        }
        cout << ">> Current Song (up next): " << songQueue.front() << "\n";
    }

    // 5. Count total number of songs
    void countSongs() {
        cout << ">> Total Songs in Playlist: " << songQueue.size() << "\n";
    }
};

// Display menu
void showMenu() {
    cout << "\n===== MUSIC PLAYLIST (Queue) =====\n";
    cout << "1. Add Song\n";
    cout << "2. Play Next Song\n";
    cout << "3. View Playlist\n";
    cout << "4. Display Current Song\n";
    cout << "5. Count Total Songs\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Playlist playlist;
    int choice;

    do {
        showMenu();
        cin >> choice;

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