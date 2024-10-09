# include <iostream>
# include <fstream>
using namespace std;

// ofstream	-> Creates and writes to files
// ifstream	-> Reads from files
// fstream	-> A combination of ofstream and ifstream: creates, reads, and writes to files

int main()
{
    string  my_text;
    fstream my_file("files.txt");

    // my_file << "hello\nThis is a file test\n";   // -> write to the file
    while (getline(my_file, my_text)) { // -> this while is for reading from the file
        cout << my_text;
    }
    my_file.close();
}

// #include <iostream>
// #include <fstream>  // for file handling
// #include <string>   // for std::string

// int main() {
//     // Create an object of ifstream to read from a file
//     std::ifstream infile;

//     // Open the file in read mode
//     infile.open("example.txt");

//     // Check if the file is open
//     if (infile.is_open()) {
//         std::string line;
        
//         // Read the file line by line
//         while (std::getline(infile, line)) {
//             std::cout << line << std::endl;
//         }
//         infile.close();  // Close the file after reading
//     } else {
//         std::cout << "Error opening file for reading!\n";
//     }

//     return 0;
// }

