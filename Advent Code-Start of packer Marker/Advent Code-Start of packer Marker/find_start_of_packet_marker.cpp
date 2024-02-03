#include "find_start_of_packet_marker.h"
#include <set>

int find_start_of_packet_marker(const string& datastream) {
    if (datastream.size() >= 4){
        std::set<char> charSet;
        for (int i = 4; i < datastream.size()+1; ++i) {
            if (set<char>(datastream.begin() + i - 4, datastream.begin() + i).size() == 4) {
                return i;
            }
        }
    }
    return -1;
}
