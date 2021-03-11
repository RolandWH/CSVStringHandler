#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int arrayCharCount(std::vector<char> charArray, char targetChar) {
    int count = 0;
    for (int i = 0; i < charArray.size(); i++) {
        if (charArray[i] == targetChar) {
            count++;
        }
    }
    return count;
}


int stringCharCount(std::string stringObject, char targetChar) {
    int count = 0;
    for (int i = 0; i < stringObject.size(); i++) {
        if (stringObject[i] == targetChar) {
            count++;
        }
    }
    return count;
}


int main() {
    // Set up variables
    int count = 0;
    std::string userInput;
    std::vector<int> freqList;
    std::vector<char> processedChars;

    // Get user input
    std::cout << "Enter a string: ";
    std::getline(std::cin, userInput);
    while (stringCharCount(userInput, '"') || stringCharCount(userInput, '\'')) {
        std::cout << "Sorry but quotation marks are not supported as they mess up CSV rendering, please enter another string: ";
        std::getline(std::cin, userInput);
    }

    // Find frequency
    count = 0;
    for (int i = 0; i < userInput.size(); i++) {
        if (arrayCharCount(processedChars, userInput[i]) == 0) {
            freqList.push_back(stringCharCount(userInput, userInput[i]));
            processedChars.push_back(userInput[i]);
        }

    }

    // Export to CSV file
    std::ofstream csvFile;
    csvFile.open("CSVStringHandler.csv");
    csvFile << "Character,Freqency" << std::endl;
    for (int i = 0; i < processedChars.size(); i++) {
        csvFile << '"' << processedChars[i] << '"' << ',' << freqList[i] << std::endl;
    }

    return 0;
}