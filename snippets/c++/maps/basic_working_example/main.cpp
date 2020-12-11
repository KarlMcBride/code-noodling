#include "stats_tracker.hpp"

int main()
{
    stats_tracker tracker;

    tracker.increment_packet_count(packet_code::ACK);
    tracker.increment_packet_count(packet_code::ACK);
    tracker.increment_packet_count(packet_code::ACK);
    tracker.increment_packet_count(packet_code::NAK);
    tracker.increment_packet_count(packet_code::NAK);
    tracker.increment_packet_count(packet_code::PDID);
    tracker.print_counts();

    return 0;
}