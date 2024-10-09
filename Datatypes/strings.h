#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>
#include <cstring>

namespace MyStringNamespace
{
    class MyString
    {
    private:
        char *data;
        size_t len;
        int strcmp(const MyString &other) const
        {
            const char *str1 = data;
            const char *str2 = other.data;
            while (*str1 && (*str1 == *str2))
            {
                str1++;
                str2++;
            }
            return *(unsigned char *)str1 - *(unsigned char *)str2;
        }
        static size_t custom_strlen(const char *data)
        {
            size_t size = 0;
            while (data[size] != '\0')
            {
                ++size;
            }
            return size;
        }

        // Custom strcpy function
        static char *custom_strcpy(char *destination, const char *source)
        {
            size_t i = 0;
            while (source[i] != '\0')
            {
                destination[i] = source[i];
                ++i;
            }
            destination[i] = '\0'; // Add the null terminator
            return destination;
        }

    public:
        MyString() : data(nullptr), len(0) {}
        MyString(const char *s)
        {
            if (s)
            {
                len = std::strlen(s);
                data = new char[len + 1];
                std::strcpy(data, s);
            }
            else
            {
                data = nullptr;
                len = 0;
            }
        }

        MyString(const MyString &other)
        {
            len = other.len;
            data = new char[len + 1];
            std::strcpy(data, other.data);
        }

        MyString &operator=(const MyString &other)
        {
            if (this == &other)
            {
                return *this;
            }
            delete[] data;
            len = other.len;
            data = new char[len + 1];
            std::strcpy(data, other.data);
            return *this;
        }

        ~MyString()
        {
            delete[] data;
        }

        friend std::ostream &operator<<(std::ostream &os, const MyString &s)
        {
            os << s.data;
            return os;
        }

        friend std::istream &operator>>(std::istream &is, MyString &s)
        {
            char temp[1000];
            is >> temp;
            s = MyString(temp);
            return is;
        }

        MyString operator+(const MyString &other) const
        {
            MyString result;
            result.len = len + other.len;
            result.data = new char[result.len + 1];
            std::strcpy(result.data, data);
            std::strcat(result.data, other.data);
            return result;
        }

        bool operator==(const MyString &other) const
        {
            return std::strcmp(data, other.data) == 0;
        }
        bool operator!=(const MyString &other) const
        {
            return std::strcmp(data, other.data) != 0;
        }
        bool operator<(const MyString &other) const
        {
            return std::strcmp(data, other.data) < 0;
        }

        void print() const
        {
            std::cout << data << std::endl;
        }

        // Capitalize First
        void CapitalizeFirst()
        {
            MyString *tokens = strtok(' ');
            int numWords = coutwords(' ');
            for (int i = 0; i < numWords; i++)
            {
                char *tokenData = tokens[i].data;
                if (tokenData[0] >= 'a' && tokenData[0] <= 'z')
                {
                    tokenData[0] = tokenData[0] - 'a' + 'A';
                }
                std::cout << tokenData << " ";
            }
            std::cout << std::endl;
            delete[] tokens;
        }

        // Lower First
        void lowerFirst()
        {
            MyString *tokens = strtok(' ');
            int numWords = coutwords(' ');
            for (int i = 0; i < numWords; i++)
            {
                char *tokenData = tokens[i].data;
                if (tokenData[0] >= 'A' && tokenData[0] <= 'Z')
                {
                    tokenData[0] = tokenData[0] + 'a' - 'A';
                }
                std::cout << tokenData << " ";
            }
            std::cout << std::endl;
            delete[] tokens;
        }

        // Upper All
        void upperAll()
        {
            MyString *tokens = strtok(' ');
            int numWords = coutwords(' ');
            for (int i = 0; i < numWords; i++)
            {
                char *tokenData = tokens[i].data;
                for (int j = 0; j < custom_strlen(tokenData); j++)
                {
                    if (tokenData[j] >= 'a' && tokenData[j] <= 'z')
                    {
                        tokenData[j] = tokenData[j] - 'a' + 'A';
                    }
                }
                std::cout << tokenData << " ";
            }
            std::cout << std::endl;
            delete[] tokens;
        }

        // Invert Case
        // void invertcase() {
        //     MyString* tokens = strtok(' ');
        //     int numWords = coutwords(' ');
        //     for (int i = 0; i < numWords; i++) {
        //         char* tokenData = tokens[i].data;
        //         for (int j = 0; j < custom_strlen(tokenData); j++) {
        //             if (std::islower(tokenData[j])) {
        //                 tokenData[j] = std::toupper(tokenData[j]);
        //             } else if (std::isupper(tokenData[j])) {
        //                 tokenData[j] = std::tolower(tokenData[j]);
        //             }
        //         }
        //         std::cout << tokenData << " ";
        //     }
        //     std::cout << std::endl;
        //     delete[] tokens;
        // }

        // Count words
        int coutwords(char delimiter = ' ')
        {
            int NoOfWords = 0;
            int i = 0;
            while (data[i] != '\0')
            {
                if (data[i] == delimiter)
                {
                    NoOfWords++;
                }
                i++;
            }
            return NoOfWords + 1;
        }

        // Substring function
        MyString substr(int start = 0, int length = -1)
        {
            if (length == -1)
            {
                length = custom_strlen(data) - start;
            }
            char *newData = new char[length + 1];
            for (int i = 0; i < length; ++i)
            {
                newData[i] = data[start + i];
            }
            newData[length] = '\0';
            MyString newString(newData);
            delete[] newData;
            return newString;
        }

        MyString *strtok(char delimiter = ' ')
        {
            int size = coutwords(delimiter);
            MyString *arr = new MyString[size];
            int index = 0;

            int start = 0;
            for (int i = 0; i <= custom_strlen(data); i++)
            {
                if (data[i] == delimiter || data[i] == '\0')
                {
                    arr[index] = substr(start, i - start);
                    start = i + 1;
                    index++;
                }
            }
            return arr;
        }

        double toDouble() const
        {
            double result = 0.0;
            int sign = 1;
            bool decimalPoint = false;
            double decimalPlace = 0.1;

            for (int i = 0; data[i] != '\0'; i++)
            {
                if (data[i] == '-')
                {
                    sign = -1;
                }
                else if (data[i] == '.')
                {
                    decimalPoint = true;
                }
                else if (data[i] >= '0' && data[i] <= '9')
                {
                    if (decimalPoint)
                    {
                        result += (data[i] - '0') * decimalPlace;
                        decimalPlace /= 10;
                    }
                    else
                    {
                        result = result * 10 + (data[i] - '0');
                    }
                }
            }
            return sign * result;
        }

        // Converts double to MyString
        static MyString fromDouble(double value)
        {
            char buffer[50];
            snprintf(buffer, sizeof(buffer), "%.2f", value);
            return MyString(buffer);
        }
    };
}

#endif