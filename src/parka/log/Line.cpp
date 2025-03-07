#include "parka/log/Line.hpp"
#include "parka/log/Color.hpp"
#include "parka/log/Margin.hpp"

namespace parka::log
{
	StringView Line::getPreText(const fs::FileSnippet& snippet)
	{
		// const auto& position = snippet.position();
		const char *base = snippet.file().text().c_str();
		const char *end = snippet.ptr();
		const char *iter = end;

		while (iter > base)
		{
			if (iter[-1] == '\n')
				break;

			iter -= 1;
		}

		return StringView(iter, end - iter);
	}

	StringView Line::getPostText(const fs::FileSnippet& snippet)
	{
		const char *start = snippet.ptr() + snippet.length();
		const char *iter = start;

		while (iter[0])
		{
			if (iter[0] == '\n')
				break;

			iter += 1;
		}

		return StringView(start, iter - start);
	}

	std::ostream& operator<<(std::ostream& out, const Line& line)
	{
		auto margin = Margin(line._snippet.position().line());

		out << margin;
		out << Color::none << line._preText << Color::reset;
		out << line._snippet;
		out << Color::none << line._postText << Color::reset;
		out << '\n';

		return out;
	}
}
