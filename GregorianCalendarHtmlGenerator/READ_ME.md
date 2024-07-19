
# Gregorian Calendar to HTML

Use this software to create a static HTML page that displays a Gregorian calendar.

## MIT License

```text
MIT License

Copyright (c) 2024 Gonçalo Filipe Duarte Pinto

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

# Build and Test Instructions

This project uses `make` to manage the build and test processes. Below are the commands and their descriptions for building and testing the project.

## Prerequisites

Ensure you have `make` and `gcc` installed on your system. Additionally, you will need the CUnit testing framework installed. On Debian-based systems, you can install CUnit with:

```sh
sudo apt-get install libcunit1-dev
```

## 1. Clean
Remove all build artifacts including object files and executables.

```sh
make clean
```
Description: This command cleans up all the compiled files and binaries to ensure that the next build starts from a clean state. It removes all object files and the main and test executables.

## 2. Build
Compile the source files and generate the main and test executables.

```sh
make all
```
Description: This command builds the project by compiling the source files and linking them to create the main executable and the test executable. It uses the default settings defined in the Makefile.


## 3. Run Tests
Execute the test suite to verify that the project behaves as expected.


```sh
make test
```
Description: This command runs the test suite using the test executable. It assumes that the tests have been compiled and that any necessary test data files are available. The results of the test run will be displayed in the terminal.


## 4. Full Build and Test Workflow
To clean the build directory, build the project, and then run the tests, execute the following combined command:

```sh
make clean; make all; make test
```
Description: 
Clean up previous build artifacts.
Build the project from scratch.
Run the test suite to ensure everything is working correctly.
By following these instructions, you can maintain a clean build environment and ensure your project is thoroughly tested.

## 5.Troubleshooting
If you encounter issues, ensure that all required dependencies are installed.
Verify that the paths in the Makefile are correct and that source files are in the expected locations.
Review the output from the make commands for any error messages and resolve them as needed.
For further assistance, refer to the Makefile documentation or consult the project maintainers.

# Contact
**Author:** Gonçalo Pinto  
**Email:** [eng.goncalo.pinto@gmail.com](mailto:eng.goncalo.pinto@gmail.com)  
**Last Updated:** `2024/07/19`