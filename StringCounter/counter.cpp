#include "counter.h"

int counter::count_string(const char* counted) {
	for (count_value = 0; counted[count_value]; ++count_value) {
		;
	}
	return count_value;
}
