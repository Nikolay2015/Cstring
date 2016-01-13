#ifndef CPP_STRING_H
#define CPP_STRING_H
#include <string>
#include <iostream>

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
		size_ = 0;
		const char *str_size = str;
		while (*str_size != '\0')
		{
			size_ += 1;
			str_size = (str_size + 1);
		}
		char *temp = new char[size_ + 1];
		while (*(temp++) = *(str++));
		temp = (temp - size_ - 1);
		str_ = temp;
	};

	String(const char *str, unsigned count)
	{
		char *temp = new char[count + 1];
		const char *str_temp = str;
		for (unsigned i = 0; i < count; i++)
		{
			temp[i] = *str_temp;
			str_temp = (str_temp + 1);
		}
		temp[count] = '\0';
		size_ = count;
		str_ = temp;
	};

	String(char ch, unsigned count)
	{
		char *temp = new char[count + 1];
		for (unsigned i = 0; i < count; i++)
		{
			temp[i] = ch;
		}
		temp[count] = '\0';
		size_ = count;
		str_ = temp;
	};

	String(const String &other)
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
		str_ = temp;
	};

	String(String &&other)
	{
		size_ = other.size_;
		str_ = other.str_;
		other.size_ = 0;
		other.str_ = NULL;
	};

	~String()
	{
		delete[] str_;
	};

	String &operator =(const String &other)
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
		str_ = temp;
		return *this;
	};

	String &operator =(String &&other)
	{
		size_ = other.size_;
		str_ = other.str_;
		other.size_ = 0;
		other.str_ = NULL;
		return *this;
	};

	String &operator +=(const String &suffix)
	{
		char *str;
		char *s = str_;
		char *temp = str = new char[size_ + suffix.size_ + 1];

		for (unsigned i = 0; i < size_; i++) 
		{
			*(temp++) = *(s++);
		}
		
		char *temp_str = suffix.str_;
		for (unsigned i = 0; i < suffix.size_; i++)
		{
			*(temp++) = *(temp_str++);
		}
		delete[] str_;
		*temp = '\0';
		size_ += suffix.size_;
		str_ = str;
		return *this;
	};

	String &operator +=(const char * suffix)
	{
		unsigned size = 0;
		const char *temp_suffix = suffix;
		while (*(temp_suffix++) != '\0') //size of suffix
		{
			size++;
		}
		temp_suffix = suffix;
		char *str;
		char *s = str_;
		char *temp = str = new char[size_ + size + 1];
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
		size_ += size;
		str_ = str;
		return *this;
	};

	String &operator +=(char suffix)
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
		size_ = size_ + 1;
		str_ = str;
		return *this;
	};

	void swap(String &other) 
	{
		char *temp;
		unsigned size;
		temp = str_;
		size = size_;
		str_ = other.str_;
		size_ = other.size_;
		other.str_ = temp;
		other.size_ = size;
	};

	char &operator [](unsigned pos) 
	{
		return *(str_ + pos);
	};

	const char operator [](unsigned pos) const 
	{
		return *(str_ + pos);
	};

	char & at(unsigned pos) 
	{
		if (pos >= size_) 
		{
			throw std::out_of_range("");
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

	friend std::ostream &operator <<(std::ostream &stream, const String &s)
	{
		stream << s.data();
		return stream;
	};

	friend bool operator ==(const String &lhs, const String &rhs) 
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

	friend bool operator <(const String &lhs, const String &rhs) 
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
				//std::cout << lhs.str_ + i << '\n';
				return true;
			}
			else if (*(lhs.str_ + i) > *(rhs.str_ + i)) 
			{
				//std::cout << lhs.str_ + i << '\n';
				return false;
			}
		}
		return false;
	};

private :
	unsigned int size_;
	char *str_;
};

String operator +(const String &lhs, const String &rhs)
{
	return String(lhs) += rhs;
};

String operator +(const String &lhs, const char *rhs)
{
	return String(lhs) += rhs;
};

String operator +(const char *lhs, const String &rhs)
{
	return String(lhs) += rhs;
};

bool operator !=(const String &lhs, const String &rhs)
{
	return !(lhs == rhs);
};

bool operator <=(const String &lhs, const String &rhs)
{
	return (lhs == rhs) || (lhs < rhs);
};

bool operator >(const String &lhs, const String &rhs)
{
	return !(lhs <= rhs);
};

bool operator >=(const String &lhs, const String &rhs)
{
	return !(lhs < rhs);
};
#endif
