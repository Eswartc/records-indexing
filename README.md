# PrimaryIndexing.cpp

This C++ program implements a simple data management system using primary indexing. It allows users to add, search, display, and remove student records based on their unique USN (University Serial Number). The program maintains a data file (`data.txt`), a primary index file (`primary.txt`), and a secondary index file (`secondary.txt`).

## Features

- Add a new student record by providing name, USN, and branch details.
- Search for student records based on either name or USN. If duplicates exist for a name, the program will prompt for the USN to display matching records.
- Display all student records in the data file (`data.txt`).
- Display the primary index information to demonstrate the primary indexing technique.
- Display the secondary index information to demonstrate the secondary indexing technique.
- Remove a student record based on their USN.

## How to Use

1. Compile the `PrimaryIndexing.cpp` program using a C++ compiler.
2. Run the executable file generated after compilation.
3. The program will display a menu with options to perform various operations.
4. Follow the on-screen prompts to add, search, display, or remove student records.
5. The program will demonstrate primary and secondary indexing techniques.

## File Structure

- `PrimaryIndexing.cpp`: Main C++ program implementing the primary indexing data management system.
- `data.txt`: Data file storing student records in the format `Name|USN|Branch`.
- `primary.txt`: Primary index file storing the USN and corresponding file offset in the data file.
- `secondary.txt`: Secondary index file storing the Name and corresponding USN.

## Note

This program is for educational purposes and may not handle all possible edge cases. Feel free to extend or modify it as per your requirements.

# SecondaryIndexing.cpp

This C++ program extends the data management system implemented in the `PrimaryIndexing.cpp` program by introducing secondary indexing. The secondary index file (`secondary.txt`) maintains the relationship between student names and their corresponding USNs, offering a quick search mechanism based on names.

## Features

- All the `PrimaryIndexing.cpp` features are retained, including adding, searching, displaying, and removing student records.
- The program now demonstrates secondary indexing, allowing quick searches based on student names.

## How to Use

1. Compile the `SecondaryIndexing.cpp` program using a C++ compiler.
2. Run the executable file generated after compilation.
3. The program will display a menu with options to perform various operations, including secondary index information.
4. Follow the on-screen prompts to add, search, display, or remove student records.
5. The program will demonstrate both primary and secondary indexing techniques.

## File Structure

- `SecondaryIndexing.cpp`: Main C++ program implementing the data management system with secondary indexing.
- `data.txt`: Data file storing student records in the format `Name|USN|Branch`.
- `primary.txt`: Primary index file storing the USN and corresponding file offset in the data file.
- `secondary.txt`: Secondary index file storing the Name and corresponding USN.

## Note

This program builds upon the previous version (`PrimaryIndexing.cpp`) and may not handle all possible edge cases. It is intended for educational purposes, and you can extend or modify it as per your specific needs.

Keep on learning and organizing! 📝
