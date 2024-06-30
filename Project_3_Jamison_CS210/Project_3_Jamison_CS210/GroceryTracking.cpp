/*
    Author: Emeth Jamison
    Class: CS-210
    Instructor: Bill Chan
    Date: 6/23/2024
    Assignment: Project 3
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
private:
    map<string, int> itemFreq; // Map to store item frequencies

public:
    // Constructor to read input file and populate item frequencies
    GroceryTracker() {
        ifstream inFile("CS210_Project_Three_Input_File.txt");
        string item;

        if (!inFile.is_open()) {
            cout << "Unable to open input file." << endl;
            return;
        }

        while (inFile >> item) {
            if (itemFreq.find(item) != itemFreq.end()) {
                itemFreq[item]++;
            }
            else {
                itemFreq[item] = 1;
            }
        }

        inFile.close();
    }

    // Function to search for item frequency
    void searchItemFrequency(const string& item) {
        map<string, int>::iterator i = itemFreq.find(item);
        if (i != itemFreq.end()) {
            cout << "Frequency of " << item << ": " << i->second << endl;
        }
        else {
            cout << item << " not found in records." << endl;
        }
    }

    // Function to print all items with their frequencies
    void printAllItemsWithFrequency() {
        for (map<string, int>::iterator i = itemFreq.begin(); i != itemFreq.end(); ++i) {
            cout << i->first << " " << i->second << endl;
        }
    }

    // Function to print histogram representation of item frequencies
    void printHistogram() {
        for (map<string, int>::iterator i = itemFreq.begin(); i != itemFreq.end(); ++i) {
            cout << i->first << " ";
            for (int j = 0; j < i->second; ++j) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Function to backup item frequencies to file
    void backupToFile() {
        ofstream outputFile("frequency.dat");
        for (map<string, int>::iterator i = itemFreq.begin(); i != itemFreq.end(); ++i) {
            outputFile << i->first << " " << i->second << endl;
        }
        outputFile.close();
        cout << "Data backed up to frequency.dat.\n";
    }
};

int main() {
    GroceryTracker tracker; // Create an instance of GroceryTracker
    
    int choice = 0;
    string item;

    while (choice != 4) {
        // Display menu options
        cout << "Corner Grocer Menu:\n";
        cout << "1. Search for item frequency\n";
        cout << "2. Print list of all items with frequencies\n";
        cout << "3. Print histogram representation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) { // Handle each option and direct to the corresponding function
        case 1:
            cout << "Enter item to search: ";
            cin >> item;
            tracker.searchItemFrequency(item);
            break;
        case 2:
            tracker.printAllItemsWithFrequency();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            tracker.backupToFile();
            cout << "Exiting program.\n";
            break;
        default: // Defualt choice to handle incorrect entries
            cout << "Invalid choice. Please enter a number between 1 and 4.\n";
            break;
        }
    };

    return 0;
}



