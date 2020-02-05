#include <fault_deque.hpp>

#include <iostream>
#include <deque>
#include <vector>

const std::string DATA_FILE_PATH = "fault_file.txt";

std::vector<std::string> fault_columns = { "DATE_TIME", "SEVERITY", "APPLICATION", "FAULT_MESSAGE" };

// Inherit dequed_file as base class, and call its constructor with the
// local max size parameter and data columns from above

fault_deque::fault_deque(const int _max_size) : dequed_file(_max_size, fault_columns, DATA_FILE_PATH)
{

}

fault_deque::~fault_deque(void)
{

}