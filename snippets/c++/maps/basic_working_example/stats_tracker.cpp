#include <iostream>
#include <limits>

#include "stats_tracker.hpp"

stats_tracker::stats_tracker()
{

}

stats_tracker::~stats_tracker()
{

}

void stats_tracker::increment_packet_count(const packet_code _code)
{
    if (m_packet_stat_map[_code] >= std::numeric_limits<uint64_t>::max())
    {
        std::cout << "stats_tracker::increment_packet_sent_count: resetting count of ["
                    << std::to_string(_code) << "] to prevent uint64_t overflow" << std::endl;
    }

    ++m_packet_stat_map[_code];
}

void stats_tracker::print_counts(void)
{
    for (uint8_t code = packet_code::ACK; code <= packet_code::PDID; ++code)
    {
        if (m_packet_stat_map.count(code) == 1)
        {
            std::cout << std::to_string(code) << ": " << m_packet_stat_map[code] << std::endl;
        }
    }
}