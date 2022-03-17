// local headers
#include <warbler/parser.hpp>
#include <warbler/validator.hpp>
#include <warbler/util/print.hpp>

// standard headers
#include <stdio.h>
#include <assert.h>


const char *src = R"==(

	type Person: struct
	{
		age: u32
	}

)==";

using namespace warbler;

int main()
{
	auto file = File::from(src);
	auto parse_res = parse(file);

	if (!parse_res)
	{
		print_error("failed to parse source");
		return 1;
	}

	auto syntax = parse_res.unwrap();
	auto context_res = validate(syntax);

	if (!context_res)
	{
		print_error("errors when validating source");
		return 1;
	}
	
	print_note("successfully validated ast");

	return 0;
}