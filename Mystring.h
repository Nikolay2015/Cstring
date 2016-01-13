#ifndef CPP_STRING_H
#define CPP_STRING_H
#include <iostream>
#include <stdexcept>
#include <string>

class String
{
public:

	String()
	{
		str_ = new char[1];
		*str_ = '\0';
		size_ = 0;
	};

	String(const char *str)
	{
		size_ = std::strlen(str);
		str_ = new char[size_ + 1];
		while (*(str_++) = *(str++));
		str_ = (str_ - size_ - 1);
	};

	String(const char *str, unsigned count)
	{
		str_ = new char[count + 1];
		const char *str_temp = str;
		for (unsigned i = 0; i < count; i++)
		{
			str_[i] = *str_temp;
			str_temp++;
		}
		str_[count] = '\0';
		size_ = count;
	};

	String(char ch, unsigned count)
	{
		str_ = new char[count + 1];
		for (unsigned i = 0; i < count; i++)
		{
			str_[i] = ch;
		}
		str_[count] = '\0';
		size_ = count;
	};

	String(const String &other)
	{
		size_ = other.size_;
		char *str_temp = other.str_;
		str_ = new char[other.size_ + 1];
		for (unsigned i = 0; i < other.size_; i++)
		{
			str_[i] = *str_temp;
			str_temp = (str_temp + 1);
		}
		str_[other.size_] = '\0';
	};

	String(String &&other)
	{
		size_ = other.size_;
		str_ = other.str_;
		other.size_ = 0;
		other.str_ = nullptr;
	};

	~String()
	{
		delete[] str_;
	};

	String &operator=(const String &other)
	{
		size_ = other.size_;
		char *str_temp = other.str_;
		char *temp = new char[other.size_ + 1];
		for (unsigned i = 0; i < other.size_; i++)
		{
			temp[i] = *str_temp;
			str_temp = (str_temp + 1);
		}
		temp[other.size_] = '\0';
		delete[] str_;
		str_ = temp;
		return *this;
	};

	String &operator=(String &&other)
	{
		delete[] str_;
		size_ = other.size_;
		str_ = other.str_;
		other.size_ = 0;
		other.str_ = nullptr;
		return *this;
	};

	String &operator+=(const String &suffix)
	{
		char *str;
		char *s = str_;
		char *temp = str = new char[size_ + suffix.size_ + 1];
		char *temp_str = suffix.str_;
		copy_suffix(temp, s, suffix.size_, temp_str);
		size_ += suffix.size_;
		str_ = str;
		return *this;
	};

	String &operator+=(const char * suffix)
	{
		unsigned size = std::strlen(suffix);
		const char *temp_suffix = suffix;
		char *str;
		char *s = str_;
		char *temp = str = new char[size_ + size + 1];
		copy_suffix(temp, s, size, temp_suffix);
		size_ += size;
		str_ = str;
		return *this;
	};

	String &operator+=(char suffix)
	{
		char *str;
		char *s = str_;
		char *temp = str = new char[size_ + 2];//
		for (unsigned i = 0; i < size_; ++i)
		{
			*(temp++) = *(s++);
		}
		*(temp++) = suffix;
		*temp = '\0';
		delete[] str_;
		size_++;
		str_ = str;
		return *this;
	};

	void swap(String &other)
	{
		std::swap(str_, other.str_);
		std::swap(size_, other.size_);
	};

	char &operator[](unsigned pos)
	{
		return *(str_ + pos);
	};

	const char operator[](unsigned pos) const
	{
		return *(str_ + pos);
	};

	char &at(unsigned pos)
	{
		if (pos >= size_)
		{
			throw std::out_of_range("position > your size");
		}
		char *temp_pos = (str_ + pos);
		return *(temp_pos);
	};

	const char * data() const
	{
		return str_;
	};

	unsigned size() const
	{
		return size_;
	};

	friend std::ostream &operator<<(std::ostream &stream, const String &s)
	{
		stream << s.data();
		return stream;
	};

	friend bool operator==(const String &lhs, const String &rhs)
	{
		if (lhs.size_ == rhs.size_) // if size equal then 
		{
			char *temp_left = lhs.str_;
			char *temp_right = rhs.str_;
			for (unsigned i = 0; i <= lhs.size_; i++)
			{
				if (*(temp_left++) != *(temp_right++))// if not equal then false
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}

	};

	friend bool operator<(const String &lhs, const String &rhs)
	{
		unsigned size = lhs.size_;
		if (size <= rhs.size_)
		{
			size = rhs.size_;
		}
		for (unsigned i = 0; i < size; i++)
		{
			if (*(lhs.str_ + i) < *(rhs.str_ + i))
			{
				return true;
			}
			else if (*(lhs.str_ + i) > *(rhs.str_ + i))
			{
				return false;
			}
		}
		return false;
	};

private:
	unsigned int size_;
	char *str_;

	void copy_suffix(char *temp, char *s, unsigned size, const char *temp_suffix)
	{
		for (unsigned i = 0; i < size_; i++)// copy of str_ 
		{
			*(temp++) = *(s++);
		}
		for (unsigned i = 0; i < size; i++)//copy of suffix
		{
			*(temp++) = *(temp_suffix++);
		}
		*temp = '\0';
		delete[] str_;
	};

	void copy_suffix(char *temp, char *s, unsigned size, char *temp_suffix)
	{
		for (unsigned i = 0; i < size_; i++)// copy of str_ 
		{
			*(temp++) = *(s++);
		}
		for (unsigned i = 0; i < size; i++)//copy of suffix
		{
			*(temp++) = *(temp_suffix++);
		}
		*temp = '\0';
		delete[] str_;
	};
};

String operator+(const String &lhs, const String &rhs)
{
	return String(lhs) += rhs;
};

String operator+(const String &lhs, const char *rhs)
{
	return String(lhs) += rhs;
};

String operator+(const char *lhs, const String &rhs)
{
	return String(lhs) += rhs;
};

bool operator!=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
};

bool operator<=(const String &lhs, const String &rhs)
{
	return (lhs == rhs) || (lhs < rhs);
};

bool operator>(const String &lhs, const String &rhs)
{
	return !(lhs <= rhs);
};

bool operator>=(const String &lhs, const String &rhs)
{
	return !(lhs < rhs);
};
#endif
