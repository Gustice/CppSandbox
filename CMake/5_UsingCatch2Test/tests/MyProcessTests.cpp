#include "catch.hpp"

TEST_CASE( "Successful", "[group]" ) {
    REQUIRE( true );
}

TEST_CASE( "Failing", "[group]" ) {
    REQUIRE( false );
}
