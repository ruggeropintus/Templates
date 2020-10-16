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
// 	m_WithinOurProgram(withinOurProgram);
// }

int main(int argc, char** argv) {
	std::cout << "--------------------------" << std::endl;
	withinOurProgram = true;

	std::size_t bytesAllocatedHandle = 0;
	bytesAllocatedHandle = bytesAllocated;

	auto startTimePoint = std::chrono::high_resolution_clock::now();

	auto endTimePoint = std::chrono::high_resolution_clock::now();
	auto start =
		std::chrono::time_point_cast<std::chrono::milliseconds>(startTimePoint)
			.time_since_epoch()
			.count();
	auto end =
		std::chrono::time_point_cast<std::chrono::milliseconds>(endTimePoint)
			.time_since_epoch()
			.count();
	auto duration = end - start;
	std::cout << "processing in " << duration << "ms" << std::endl;

	std::cout << "--------------------------" << std::endl;
	std::cout << "numberOfAllocations - " << numberOfAllocations << std::endl;
	std::cout << "bytesAllocated      - " << bytesAllocated << std::endl;
	withinOurProgram = false;
	return 0;
}
