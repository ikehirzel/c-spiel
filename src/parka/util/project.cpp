#include "parka/util/project.hpp"
#include "parka/util/directory.hpp"
#include "parka/util/optional.hpp"
#include "parka/util/path.hpp"
#include "parka/util/print.hpp"

Optional<Project> Project::read(const String& path)
{
    auto srcPath = path::join(path, "src");
    auto directory = Directory::read(srcPath, path.length() + 1);

    if (!directory)
        return {};

    auto name = path::getFilename(path);
    auto project = Project(std::move(name), *directory);

    return project;
}

usize getDirectoryLinesOfCodeCount(const Directory& directory)
{
    usize count = 0;

    for (const auto& file : directory.files())
    {
        if (file.type() == FileType::Source)
            count += file.lineCount();
    }

    for (const auto& subdirectory :directory.subdirectories())
        count += getDirectoryLinesOfCodeCount(subdirectory);

    return count;
}

usize Project::getLinesOfCodeCount()
{
    return getDirectoryLinesOfCodeCount(_srcDirectory);
}
