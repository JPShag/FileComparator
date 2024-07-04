# FileComparator

FileComparator is a simple C++ program that compares two files by computing their MD5 hash values and outputs the percentage difference between the hashes.

## Features

- Computes the MD5 hash of two files.
- Outputs the hash values of both files.
- Calculates and displays the percentage difference between the two hash values.

## Prerequisites

- Visual Studio with C++ development tools.
- OpenSSL installed via vcpkg.

## Installation

1. **Install vcpkg**:
   ```sh
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
   ```

2. **Install OpenSSL via vcpkg**:
   ```sh
   .\vcpkg install openssl:x64-windows
   ```

3. **Clone the Repository**:
   ```sh
   git clone https://github.com/your-username/FileComparator.git
   cd FileComparator
   ```

## Building the Project

1. **Open the x64 Native Tools Command Prompt for Visual Studio**.

2. **Set OpenSSL Environment Variables**:
   ```sh
   set OPENSSL_ROOT_DIR=C:\path\to\vcpkg\installed\x64-windows
   set OPENSSL_INCLUDE_DIR=%OPENSSL_ROOT_DIR%\include
   set OPENSSL_LIB_DIR=%OPENSSL_ROOT_DIR%\lib
   ```

3. **Compile the Program**:
   ```sh
   cl /EHsc /MD /I"%OPENSSL_INCLUDE_DIR%" compare_files.cpp /link /LIBPATH:"%OPENSSL_LIB_DIR%" libssl.lib libcrypto.lib /MACHINE:X64 /out:compare_files.exe
   ```

## Usage

Run the executable with two file paths as arguments:

```sh
compare_files.exe file1.txt file2.txt
```

## Example Output

```
File 1 MD5: d41d8cd98f00b204e9800998ecf8427e
File 2 MD5: 0cc175b9c0f1b6a831c399e269772661
Percentage difference: 62.5%
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests.
