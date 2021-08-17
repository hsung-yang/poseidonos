#include "src/helper/string_helper.h"

#include <gtest/gtest.h>

TEST(StringHelper, Trim_testIfBothLTrimAndRTrimWorksWell)
{
    // Given
    string testStr = " This is a string for trim test.    ";

    // When
    string outStr = trim(testStr);
    string expectedTrimmedStr = "This is a string for trim test.";
    bool actual = outStr == expectedTrimmedStr;

    // Then
    ASSERT_TRUE(actual);
}
