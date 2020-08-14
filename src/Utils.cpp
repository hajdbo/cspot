#include "Utils.h"

std::vector<uint8_t> blockRead (int fd, size_t readSize)
{
    std::vector<uint8_t> buf(readSize);
	unsigned int idx = 0;
	ssize_t n;

	while (idx < readSize) {
		if ((n = recv (fd, &buf[idx], readSize - idx, 0)) <= 0) {
			return buf;
		}
		idx += n;
	}
	return buf;
}

ssize_t blockWrite (int fd, std::vector<uint8_t> data)
{
	unsigned int idx = 0;
	ssize_t n;

	while (idx < data.size()) {
		if ((n = send (fd,  &data[idx], data.size() - idx, 0)) <= 0) {
			return data.size();
		}
		idx += n;
	}
	return data.size();
}
