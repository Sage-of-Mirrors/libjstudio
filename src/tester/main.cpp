#include <iostream>

#include <bstream.h>
#include <io/stb.hpp>

int main(int argc, char* arvgv[])
{
	bStream::CFileStream strm("D:\\SZS Tools\\archive_Demo19\\stb\\towerd.stb", bStream::Big, bStream::In);

	JStudio::IO::STBFile file;
	file.Deserialize(&strm);
}
