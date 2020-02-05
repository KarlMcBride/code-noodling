#ifndef __DEQUED_FILE
#define __DEQUED_FILE

#include <bits/stdc++.h> // Required for std::sort
#include <iostream>

#include <deque>
#include <string>

#include <constants.hpp>

template<class data_type> class dequed_file
{
    public:
        dequed_file(const int _max_items, std::vector<std::string> _defined_data_columns, std::string _data_file)
        {
            max_items = _max_items;
            defined_data_columns = _defined_data_columns;
            data_file_path = _data_file;

            parse_file_deques();
        }

        ~dequed_file()
        {

        }

        void add_item(data_type _new_item)
        {
            while(storage_deque.size() >= max_items)
            {
                std::cout << "add_item: dropping [ " << storage_deque.front().as_string() << " ]" << std::endl;
                storage_deque.pop_front();
            }

            storage_deque.push_back(_new_item);
            std::sort(storage_deque.begin(), storage_deque.end());
        }

        // Test function for checking struct comparisons
        void check_equality()
        {
            for (data_type left_item : storage_deque)
            {
                for (data_type right_item : storage_deque)
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
            return storage_deque.size();
        }

        void print_forward()
        {
            std::cout << '\n';
            for (data_type item : storage_deque)
            {
                std::cout << "print_forward: " << item.as_string() << std::endl;
            }
            std::cout << '\n';
        }

        void write_file(void)
        {
            if (storage_deque.size() < 0)
            {
                std::cout << "dequed_file::write: no items to write" << std::endl;
                return;
            }

            std::ofstream data_file;
            data_file.open(data_file_path);

            // Write data file headers
            std::string header = "";
            for (int column_index = 0; column_index < defined_data_columns.size(); column_index++)
            {
                // For all columns except last, append the column and delimiter.
                if (column_index < defined_data_columns.size() - 1)
                {
                    header += defined_data_columns[column_index] + constants::FIELD_DELIMITER;
                }
                // For last column, don't append anything else
                else
                {
                    header += defined_data_columns[column_index];
                }
            }

            data_file << header << std::endl;

            for (data_type item : storage_deque)
            {
                data_file << item.as_string() << std::endl;
            }
            data_file.close();
        }

    protected:
        void read_file(std::deque<std::string>& file_column_header_deque, std::deque<std::deque<std::string>>& _file_data_deque)
        {
            std::ifstream data_file(data_file_path);
            std::string data_line;

            if (data_file.is_open())
            {
                // Get file headers before loading data
                getline(data_file, data_line);
                parse_line_into_deques(data_line, file_column_header_deque);

                // Cycle through all data lines in file
                while ( getline(data_file, data_line) )
                {
                    std::deque<std::string> new_line_deque;
                    parse_line_into_deques(data_line, new_line_deque);
                    _file_data_deque.push_back(new_line_deque);
                }
                data_file.close();
            }
        }

        std::deque<int> get_header_indices(std::deque<std::string>& _file_column_header_deque)
        {
            std::deque<int> data_indices;

            for (std::string defined_data_column : defined_data_columns)
            {
                int defined_column_index = 0;
                int matched_index = -1;
                for (std::string file_column_header : _file_column_header_deque)
                {
                    if (defined_data_column.compare(file_column_header) == 0)
                    {
                        matched_index = defined_column_index;
                    }
                    defined_column_index++;
                }
                data_indices.push_back(matched_index);
            }

            return data_indices;
        }

        void parse_file_deques(void)
        {
            std::deque<std::string> file_column_headers;
            std::deque<std::deque<std::string>> file_data;
            read_file(file_column_headers, file_data);
            std::deque<int> header_indices = get_header_indices(file_column_headers);

            // Loop through file deques and create deque of structs
            for (auto item_data : file_data)
            {
                data_type new_data = data_type(item_data, header_indices);
                add_item(new_data);
            }
        }

    private:
        int max_items = 0;
        std::deque<data_type> storage_deque;
        std::vector<std::string> defined_data_columns;
        std::string data_file_path;

        void parse_line_into_deques(std::string _line_to_parse, std::deque<std::string>& _line_deque)
        {
            size_t pos = 0;
            // Parse header line into tokens based on delimiter
            while ((pos = _line_to_parse.find(constants::FIELD_DELIMITER)) != std::string::npos)
            {
                _line_deque.push_back(_line_to_parse.substr(0, pos));
                _line_to_parse.erase(0, pos + constants::FIELD_DELIMITER.length());
            }
            // Final token will be by itself, capture it independently
            _line_deque.push_back(_line_to_parse);
        }
};


#endif // __DEQUED_FILE