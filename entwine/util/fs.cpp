/******************************************************************************
* Copyright (c) 2016, Connor Manning (connor@hobu.co)
*
* Entwine -- Point cloud indexing
*
* Entwine is available under the terms of the LGPL2 license. See COPYING
* for specific license text and more information.
*
******************************************************************************/

#include <entwine/util/fs.hpp>

#include <sys/stat.h>

#include <cstdio>
#include <fstream>

namespace entwine
{

bool Fs::mkdir(const std::string& dir)
{
    const bool err(::mkdir(dir.c_str(), S_IRWXU | S_IRGRP | S_IROTH));
    return !err;
}

bool Fs::mkdirp(const std::string& dir)
{
    const bool err(::mkdir(dir.c_str(), S_IRWXU | S_IRGRP | S_IROTH));
    return (!err || errno == EEXIST);
}

bool Fs::fileExists(const std::string& filename)
{
    std::ifstream stream(filename);
    return stream.good();
}

bool Fs::removeFile(const std::string& filename)
{
    return remove(filename.c_str()) == 0;
}

bool Fs::writeFile(
        const std::string& filename,
        const std::vector<char>& contents,
        const std::ios_base::openmode mode)
{
    return writeFile(filename, contents.data(), contents.size(), mode);
}

bool Fs::writeFile(
        const std::string& filename,
        const std::string& contents,
        const std::ios_base::openmode mode)
{
    return writeFile(filename, contents.data(), contents.size(), mode);
}

bool Fs::writeFile(
        const std::string& filename,
        const char* data,
        const std::size_t size,
        const std::ios_base::openmode mode)
{
    std::ofstream writer(filename, mode);
    writer.write(data, size);
    return writer.good();
}

} // namespace entwine

