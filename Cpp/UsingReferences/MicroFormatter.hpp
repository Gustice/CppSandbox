#if !defined(MICROFORMATTER_H)
#define MICROFORMATTER_H

#include <array>
#include <cstdarg>
#include <cstdio>
#include <string>

template <int N> class MicroFormatter {
  private:
    std::array<char, N> _buffer;

  public:
    MicroFormatter(/* args */) {}
    ~MicroFormatter() = default;

    template <class ... Args>
    std::string format(const char *fmt, Args... args) {
        // int i = sprintf(_buffer, fmt, args...);
        int i = sprintf(_buffer.begin(), fmt, args...);
        _buffer[i] = '\0';
        return std::string{_buffer.begin()};
    }
};

extern MicroFormatter<512> fmt;

#endif // MICROFORMATTER_H
