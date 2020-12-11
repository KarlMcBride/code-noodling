#ifndef __STATS_TRACKER_HPP_
#define __STATS_TRACKER_HPP_

#include <map>

enum packet_code : uint8_t
{
    ACK   = 0x40,
    NAK   = 0x41,
    PDID  = 0x45
};

class stats_tracker
{
    public:
        stats_tracker();
        ~stats_tracker();

        void increment_packet_count(const packet_code _code);
        void print_counts(void);

    private:
        std::map<uint8_t, uint64_t> m_packet_stat_map;
};

#endif // __STATS_TRACKER_HPP_
