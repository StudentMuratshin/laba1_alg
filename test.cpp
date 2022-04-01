#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "generator.h"
#include <vector>

TEST_CASE("Generator", "[vector]")
{
	int n, k;
	std::cin >> n >> k;

	Generator z(n, k);
	z.Generate();
	std::cout << std::endl << z.defoult << std::endl << std::endl;
	
	Generator g(n, k);
	g.Rec(k,0);
	std::cout << std::endl << g.rec << std::endl;

	REQUIRE(z.defoult == g.rec);
	
}