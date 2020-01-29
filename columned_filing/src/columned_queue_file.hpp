#ifndef __COLUMNED_QUEUE_FILE_HPP
#define __COLUMNED_QUEUE_FILE_HPP


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
                std::cout << "print_forward: " << item.as_string() <<  std::endl;
            }
            std::cout << '\n';
        }

    private:
        int max_items = 0;
        std::deque<data_type> storageDeque;
};


#endif // __COLUMNED_QUEUE_FILE_HPP