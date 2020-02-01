#ifndef __DEQUED_FILE
#define __DEQUED_FILE

#include <bits/stdc++.h> // Required for std::sort
#include <iostream>

#include <deque>
#include <string>
#include <vector>

#include <constants.hpp>

template<class data_type> class dequed_file
{
    public:
        dequed_file(const int _max_items, std::vector<std::string> _data_columns, std::string _data_file)
        {
            max_items = _max_items;
            data_columns = _data_columns;
            data_file_path = _data_file;

            std::cout << "dequed_file constructor called" << std::endl;
        }

        ~dequed_file()
        {
            std::cout << "dequed_file deconstructor called" << std::endl;
        }

        void add_item(data_type _new_item)
        {
            while(storageDeque.size() >= max_items)
            {
                std::cout << "add_item: dropping [ " << storageDeque.front().as_string() << " ]" << std::endl;
                storageDeque.pop_front();
            }

            std::cout << "add_item: [ " << _new_item.as_string() << " ]" << std::endl;
            storageDeque.push_back(_new_item);
            std::sort(storageDeque.begin(), storageDeque.end());
        }

        // Test function for checking struct comparisons
        void check_equality()
        {
            for (data_type left_item : storageDeque)
            {
                for (data_type right_item : storageDeque)
                {
                    if (left_item == right_item)
                    {
                        std::cout << "Left [ " << left_item.as_string() << " ] = Right [ "  << right_item.as_string() << " ]" << std::endl;
                    }
                    if (left_item < right_item)
                    {
                        std::cout << "Left [ " << left_item.as_string() << " ] < Right [ "  << right_item.as_string() << " ]" << std::endl;
                    }
                    if (left_item > right_item)
                    {
                        std::cout << "Left [ " << left_item.as_string() << " ] > Right [ "  << right_item.as_string() << " ]" << std::endl;
                    }
                }
            }
        }

        int length(void)
        {
            return storageDeque.size();
        }

        void print_forward()
        {
            std::cout << '\n';
            for (data_type item : storageDeque)
            {
                std::cout << "print_forward: " << item.as_string() << std::endl;
            }
            std::cout << '\n';
        }

        void read(void)
        {
            std::ifstream data_file(data_file_path);
            std::string data_line;

            if (data_file.is_open())
            {
                // Get file headers before loading data
                std::string header_line;
                getline(data_file, header_line);

                size_t pos = 0;
                std::vector<std::string> data_header_tokens;
                // Parse header line into tokens based on delimiter
                while ((pos = header_line.find(constants::FIELD_DELIMITER)) != std::string::npos)
                {
                    data_header_tokens.push_back(header_line.substr(0, pos));
                    header_line.erase(0, pos + constants::FIELD_DELIMITER.length());
                }
                // Final token will be by itself, capture it independently
                data_header_tokens.push_back(header_line);

                for (std::string line : data_header_tokens)
                {
                    std::cout << "read: " << line << std::endl;
                }

                // Cycle through all lines in file
                while ( getline(data_file, data_line) )
                {
                    std::cout << data_line << '\n';

                    size_t pos = 0;
                    std::vector<std::string> data_tokens;
                    // Parse each line based on delimiter and load it into the token array
                    while ((pos = data_line.find(constants::FIELD_DELIMITER)) != std::string::npos)
                    {
                        data_tokens.push_back(data_line.substr(0, pos));
                        data_line.erase(0, pos + constants::FIELD_DELIMITER.length());
                    }
                    // Final token will be by itself, capture it independently
                    data_tokens.push_back(data_line);

                    // Create new data entry with parsed tokens
                    data_type new_data_entry(data_tokens, data_header_tokens);
                }
                data_file.close();
            }
        }

        void write(void)
        {
            if (storageDeque.size() < 0)
            {
                std::cout << "dequed_file::write: no items to write" << std::endl;
                return;
            }

            std::ofstream data_file;
            data_file.open(data_file_path);

            // Write data file headers
            std::string header = "";
            for (int column_index = 0; column_index < data_columns.size(); column_index++)
            {
                // For all columns except last, append the column and delimiter.
                if (column_index < data_columns.size() - 1)
                {
                    header += data_columns[column_index] + constants::FIELD_DELIMITER;
                }
                // For last column, don't append anything else
                else
                {
                    header += data_columns[column_index];
                }
            }
            std::cout << "header: [ " << header << " ]" << std::endl;
            data_file << header << std::endl;

            for (data_type item : storageDeque)
            {
                data_file << item.as_string() << std::endl;
            }
            data_file.close();
        }

    protected:

    private:
        int max_items = 0;
        std::deque<data_type> storageDeque;
        std::vector<std::string> data_columns;
        std::string data_file_path;
};


#endif // __DEQUED_FILE