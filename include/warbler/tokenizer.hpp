#ifndef WARBLER_TOKENIZER_HPP
#define WARBLER_TOKENIZER_HPP

#define MAX_KEYWORD_LENGTH (15)
#define CHAR_TYPE_COUNT (128)
#define TEMP_KEY_SIZE (1023)

// local includes
#include <warbler/token.hpp>
#include <warbler/result.hpp>
#include <vector>

namespace warbler
{
	Error tokenizer_init();
	void tokenizer_free();

	Result<std::vector<Token>> tokenize(const char *filename, const char *src);
}

#endif
