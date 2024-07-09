#include "printer.h"

#include <stdarg.h>

namespace logger
{

void Printer::Print(const char* fmt, ...) const
{
	PrintHead(m_level);

	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
}

void Printer::PrintAppend(const char* fmt, ...) const
{
	va_list ap;
	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
}

Printer::Block Printer::PrintBlock(const std::string& title) const
{
	return Block(title, m_level);
}

Printer::Block::Block(const std::string& title, int& level)
	: m_level(level)
{
	Printer::PrintHead(level);

	printf("$begin %s\n", title.c_str());

	++m_level;
}

Printer::Block::~Block()
{
	--m_level;

	Printer::PrintHead(m_level);

	printf("$end\n");
}

void Printer::PrintHead(int level)
{
	for (int i = 0; i < level; ++i)
		printf("\t");
}

}