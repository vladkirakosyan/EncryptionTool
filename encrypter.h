#ifndef ENCRYPTER_H
#define ENCRYPTER_H

#include <string>
#include <vector>

namespace constants
{
	const int cubeSize = 8;
	const char up = 'U';
	const char down = 'D';
	const char right = 'R';
	const char left = 'L';
};

class Encrypter
{	
public:
	Encrypter() = default;
	Encrypter(std::string text)
	{
		while(text.size() % constants::cubeSize != 0)
		{
			text.push_back(' ');
		}
		while(text.size() != 0)
		{
			m_str.push_back(text.substr(0, constants::cubeSize));
			text.erase(0, constants::cubeSize);
		}
	}
	Encrypter(const Encrypter&) = delete;
	Encrypter(Encrypter&&) = delete;
	Encrypter& operator=(Encrypter) = delete;

public:
	void rotateUp();
	void rotateDown();
	void rotateRight();
	void rotateLeft();
	void setText(std::string& str);
	std::string getText() const; 
	void setKey(std::string key);

private:
	std::vector<std::string> m_str;
};

void Encrypter::rotateUp()
{
	for(std::string & s : m_str)
	{
		std::string tmp {s};
		s[0] = tmp[2];
		s[1] = tmp[3];
		s[2] = tmp[6];
		s[3] = tmp[7];
		s[4] = tmp[0];
		s[5] = tmp[1];
		s[6] = tmp[4];
		s[7] = tmp[5];
	}
}

void Encrypter::rotateDown()
{
	for(std::string& s: m_str)
	{
	
		std::string tmp {s};
		s[0] = tmp[4];
		s[1] = tmp[5];
		s[2] = tmp[0];
		s[3] = tmp[1];
		s[4] = tmp[6];
		s[5] = tmp[7];
		s[6] = tmp[2];
		s[7] = tmp[3]; 
	}
}

void Encrypter::rotateRight()
{
	for(std::string & s : m_str)
	{
		std::string tmp {s};
		s[0] = tmp[4];
		s[1] = tmp[0];
		s[2] = tmp[6];
		s[3] = tmp[2];
		s[4] = tmp[5];
		s[5] = tmp[1];
		s[6] = tmp[7];
		s[7] = tmp[3];
	}
}

void Encrypter::rotateLeft()
{
	for(std::string & s : m_str)
	{
		std::string tmp {s};
		s[0] = tmp[1];
		s[1] = tmp[5];
		s[2] = tmp[3];
		s[3] = tmp[7];
		s[4] = tmp[0];
		s[5] = tmp[4];
		s[6] = tmp[2];
		s[7] = tmp[6];
	}
}

void Encrypter::setText(std::string& text) 
{
	while(text.size() % constants::cubeSize != 0)
	{	
		text.push_back(' ');
	}
	while(text.size() != 0)
	{
		m_str.push_back(text.substr(0, constants::cubeSize));
		text.erase(0, constants::cubeSize);
	}
}
std::string Encrypter::getText() const
{
	std::string tmp;
	for(int i = 0; i < m_str.size(); ++i)
		tmp += m_str[i];
	return tmp;
}
// example of key is "RUL" - means 1st cube rotate right, 2nd - up, 3rd - left
void Encrypter::setKey(std::string key)
{
	//int count = 0;
	for(char c : key)
	{
		if(c == constants::up) 
		{
			rotateLeft();
		}
		else if(c == constants::down)
		{
			rotateDown();
		}
		else if(c == constants::right)
		{
			rotateRight();
		}
		else if(c == constants::left)
		{
			rotateLeft();
		}
	}
}
#endif //ENCRYPTER_H
