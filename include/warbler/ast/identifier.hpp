#ifndef WARBLER_AST_IDENTIFIER_HPP
#define WARBLER_AST_IDENTIFIER_HPP

#include <warbler/result.hpp>
#include <warbler/token.hpp>
namespace warbler
{
typedef struct Identifier
{
	char *text;
} Identifier;

void identifier_init(Identifier *self);
void identifier_free(Identifier *self);
Error identifier_parse(Identifier *self, TokenIterator& iter);
void identifier_print_tree(Identifier *self, unsigned depth);
}
#endif
