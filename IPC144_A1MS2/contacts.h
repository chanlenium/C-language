//==============================================
// Name:           Dongchan Oh
// Student Number: 128975190
// Email:          dcoh@myseneca.ca
// Section:        M
// Date:           Mar. 2 2020
//==============================================
// Assignment:     1
// Milestone:      1
//==============================================

// Structure type Name declaration
struct Name
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
struct Address
{
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};


// Structure type Numbers declaration
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};