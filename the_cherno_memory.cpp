#include <chrono>
#include <iostream>

std::size_t numberOfAllocations = 0;
std::size_t bytesAllocated = 0;
bool withinOurProgram = false;

void* operator new(size_t size) {
	if (withinOurProgram) {
		printf("Allocating %d bytes\n", int(size));
		numberOfAllocations++;
		bytesAllocated += size;
	}
	return malloc(size);
}

// {
// 	// in class possibly
// 	bool* const m_WithinOurProgram;
//  bool* withinOurProgram;
// 	m_WithinOurProgram(withinOurProgram);
//  *m_WithinOurProgram = false;
// }

int main(int argc, char** argv) {
	std::cout << "--------------------------" << std::endl;
	withinOurProgram = true;

	std::size_t bytesAllocatedHandle = 0;
	bytesAllocatedHandle = bytesAllocated;

	std::cout << "--------------------------" << std::endl;
	std::cout << "numberOfAllocations - " << numberOfAllocations << std::endl;
	std::cout << "bytesAllocated      - " << bytesAllocated << std::endl;
	withinOurProgram = false;
	return 0;
}
