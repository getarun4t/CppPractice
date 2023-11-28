#include <gtest/gtest.h>
#include "find_start_of_packet_marker.h"

TEST(AdventOfCode_StartOfPacketMarker, ShouldFindMarkerInSimpleCase) {
	string datastream = "mjqjpqmgbljsphdztnvjfqwrcgsmlb";
	int expected_marker_position = 7;
	int actual_marker_position = find_start_of_packet_marker(datastream);
	EXPECT_EQ(expected_marker_position, actual_marker_position);
}

TEST(AdventOfCode_StartOfPacketMarker, EmptyStringCase) {
	string datastream = "";
	int expected_marker_position = -1;
	int actual_marker_position = find_start_of_packet_marker(datastream);
	EXPECT_EQ(expected_marker_position, actual_marker_position);
}

TEST(AdventOfCode_StartOfPacketMarker, FiveStringCase) {
	string datastream = "pempl";
	int expected_marker_position = 5;
	int actual_marker_position = find_start_of_packet_marker(datastream);
	EXPECT_EQ(expected_marker_position, actual_marker_position);
}

int main(int argc, char** argv) {
	// Initialize the Google Test framework
	::testing::InitGoogleTest(&argc, argv);

	// Run the tests
	return RUN_ALL_TESTS();
}