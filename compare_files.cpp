#include <iostream>
#include <fstream>
#include <iomanip>
#include <openssl/md5.h>
#include <sstream>
#include <windows.h>

// Function to calculate MD5 hash of a file
std::string calculateMD5(const std::string& filename) {
    unsigned char c[MD5_DIGEST_LENGTH];
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];

    std::ifstream file(filename, std::ifstream::binary);
    if (!file) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return "";
    }

    MD5_Init(&mdContext);
    while ((bytes = file.readsome(reinterpret_cast<char*>(data), sizeof(data)))) {
        MD5_Update(&mdContext, data, bytes);
    }
    MD5_Final(c, &mdContext);

    std::stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)c[i];
    }

    return ss.str();
}

// Function to calculate percentage difference between two hashes
double calculatePercentageDifference(const std::string& hash1, const std::string& hash2) {
    int differences = 0;
    for (size_t i = 0; i < hash1.size(); ++i) {
        if (hash1[i] != hash2[i]) {
            differences++;
        }
    }
    return (static_cast<double>(differences) / hash1.size()) * 100;
}

// Function to compare two files and output their hash and percentage difference
void compareFiles(const std::string& file1, const std::string& file2) {
    std::string hash1 = calculateMD5(file1);
    std::string hash2 = calculateMD5(file2);

    if (hash1.empty() || hash2.empty()) {
        std::cerr << "Error calculating hashes." << std::endl;
        return;
    }

    std::cout << "File 1 MD5: " << hash1 << std::endl;
    std::cout << "File 2 MD5: " << hash2 << std::endl;

    double percentageDifference = calculatePercentageDifference(hash1, hash2);
    std::cout << "Percentage difference: " << percentageDifference << "%" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file1> <file2>" << std::endl;
        return 1;
    }

    std::string file1 = argv[1];
    std::string file2 = argv[2];

    compareFiles(file1, file2);

    return 0;
}
