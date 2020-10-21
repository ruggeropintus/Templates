#include <chrono>

class Timer {
   private:
	std::chrono::high_resolution_clock::time_point m_startTimePoint;
	const char* m_text;

   public:
	Timer(const char* text) {
		m_startTimePoint = std::chrono::high_resolution_clock::now();
		m_text = text;
	}
	~Timer() {
		auto endTimePoint = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(
						 m_startTimePoint)
						 .time_since_epoch()
						 .count();
		auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(
					   endTimePoint)
					   .time_since_epoch()
					   .count();
		auto duration = end - start;
		std::cout << m_text << " processing in " << duration << "ms"
				  << std::endl;
	}
};
