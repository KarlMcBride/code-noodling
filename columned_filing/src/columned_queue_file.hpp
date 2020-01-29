#ifndef __COLUMNED_QUEUE_FILE_HPP
#define __COLUMNED_QUEUE_FILE_HPP

#include <iostream>
#include <vector>

template<class data_type> class columned_queue_file
{
    public:
        columned_queue_file(const int _max_items)
        {
            max_items = _max_items;
            std::cout << __LINE__ << " - Default constructor called, max size [ " << max_items << " ]" << std::endl;
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
                getline(data_file, data_line);

                size_t pos = 0;
                std::vector<std::string> data_header_tokens;
                // Parse each line based on delimiter and load it into the token array
                while ((pos = data_line.find(FIELD_DELIMITER)) != std::string::npos)
                {
                    data_header_tokens.push_back(data_line.substr(0, pos));
                    data_line.erase(0, pos + FIELD_DELIMITER.length());
                }
                // Final token will be by itself, capture it independently
                data_header_tokens.push_back(data_line);

                // Cycle through all lines in file
                while ( getline(data_file, data_line) )
                {
                    std::cout << data_line << '\n';

                    size_t pos = 0;
                    std::vector<std::string> data_tokens;
                    // Parse each line based on delimiter and load it into the token array
                    while ((pos = data_line.find(FIELD_DELIMITER)) != std::string::npos)
                    {
                        data_tokens.push_back(data_line.substr(0, pos));
                        data_line.erase(0, pos + FIELD_DELIMITER.length());
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
                std::cout << "columned_queue_file::write: no items to write" << std::endl;
                return;
            }

            std::ofstream data_file;
            data_file.open(data_file_path);

            // Write data file headers first
            if (storageDeque.size() > 0)
            {
                data_file << storageDeque.front().file_header_line << std::endl;
            }

            for (data_type item : storageDeque)
            {
                data_file << item.file_data_line << std::endl;
            }
            data_file.close();
        }

    private:
        int max_items = 0;
        std::deque<data_type> storageDeque;
        std::string data_file_path = "data_file.txt";

        const std::string FIELD_DELIMITER = ";";
};


#endif // __COLUMNED_QUEUE_FILE_HPP