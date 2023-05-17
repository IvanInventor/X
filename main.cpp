#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
// Завдання 1
float minimal(const std::vector<float>& array) {
	float min = *array.begin();

	for(auto i = ++array.begin(); i != array.end(); ++i) {
		min = std::min(*i, min);
	}

	return min;
}
// Завдання 2
float sum_between(const std::vector<float>& array) {
	size_t first = 0, last = 0;

	for(; first < array.size(); ++first)
		if(array[first] > 0)
			break;

	for(size_t i = first; i < array.size(); ++i)
		if(array[i] > 0)
			last = i;
	
	float sum = 0;
	for(size_t i = ++first; i < last; ++i)
		sum += array[i];

	return sum;
}
// Завдання 3
void transform(std::vector<float>& array) {
	for(size_t i = 0, j = 0; i < array.size(); ++i)
		if(array[i] == 0)
			std::swap(array[i], array[j++]);
}
// Виведення масиву
void print_array(std::vector<float>& array) {
	char delim[] = "\0 ";

	for(auto& i : array) {
		std::cout << delim << i;
		delim[0] = ',';
	}

	std::cout << '\n';
}
// Головна функція
int main() {
	std::srand(std::time(0));
	
	std::cout << "Enter array size: ";
	int size;
	std::cin >> size;

	if(size < 1) {
		std::cout << "Incorrect size!\n";
		return 1;
	}

	std::vector<float> array(size);
	for(auto& i : array)
		i = (float)(std::rand() % 3 ? (std::rand() % 101 - 50) / 10.0 : 0);

	std::cout << "\nFor array:\n";
	print_array(array);
	std::cout << "\nMinimal element: " << minimal(array) <<
		     "\n\nSum between two positives: " << sum_between(array) <<
		     "\n\nArray after transforming:\n";

	transform(array);
	print_array(array);

	return 0;
}
