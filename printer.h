#pragma once

#include <string>

namespace logger
{

class Printer
{
public:
	void Print(const char* fmt, ...) const;
	void PrintAppend(const char* fmt, ...) const;

	void Push() { ++m_level; }
	void Pop() { --m_level; }

public:
	class Block
	{
	public:
		Block(const std::string& title, int& level);
		~Block();

	private:
		int& m_level;

	}; // Block

	Block PrintBlock(const std::string& title) const;

private:
	static void PrintHead(int level);

private:
	mutable int m_level = 0;

	friend class Block;

}; // Printer

}