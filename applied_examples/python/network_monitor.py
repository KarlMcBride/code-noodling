
import matplotlib.pyplot as plt
import psutil
import sys
import threading
import time

"""
The intent of this script is to be able to monitor network bandwidth in the background,
and report instances of bandwidth usage above a specific limit.
"""

class network_monitor():
    warning_limit = None
    error_limit = None
    polling_interval_sec = None

    bandwidth_list = []
    worker_thread = None
    is_monitoring = False
    keep_monitoring = False

    def init(self, warning_lim, error_lim, poll_interval_sec=1):
        self.warning_limit = warning_lim
        self.error_limit = error_lim
        self.polling_interval_sec = poll_interval_sec

    def start(self):
        """ Starts the monitoring thread, but only if it's not already running. """
        if self.is_monitoring == False:
            self.worker_thread = threading.Thread(target=self.monitor_function)
            self.worker_thread.start()
            self.is_monitoring = True
        else:
            print("network_monitor:start: already running!")

    def stop(self):
        """ Stops monitoring and joins onto the worker thread. """
        if self.is_monitoring == False:
            print("network_monitor:start: not running!")
        else:
            self.keep_monitoring = False
            self.worker_thread.join()

    def get_bandwidth_data(self):
        return self.bandwidth_list

    def monitor_function(self):
        new_byte_count = 0
        last_byte_count = 0
        self.is_monitoring = True
        self.keep_monitoring = True
        while self.keep_monitoring == True:
            new_byte_count = psutil.net_io_counters().bytes_sent + psutil.net_io_counters().bytes_recv
            if last_byte_count != 0:
                bytes_used = new_byte_count - last_byte_count
                kbit_sec_used = convert_bytes_sec_to_kbit_sec(bytes_used)
                self.bandwidth_list.append(kbit_sec_used)
                print(str(kbit_sec_used) + " kbits/sec")

            last_byte_count = new_byte_count
            time.sleep(self.polling_interval_sec)


def convert_bytes_sec_to_kbit_sec(bytes):
    return int( (8 * bytes) / 1024 )


def print_msg(*args,end='\n'):
    for item in args:
        sys.stdout.write(str(item)+' ')
    sys.stdout.write(end)
    sys.stdout.flush()


if __name__ == "__main__":
    print = print_msg
    monitor = network_monitor()
    monitor.init(warning_lim=1000, error_lim=2000, poll_interval_sec=1)
    monitor.start()
    time.sleep(10)
    monitor.stop()

    bandwidth_data = monitor.get_bandwidth_data()

    stats_file=open('network_stats.txt','w')
    for data in bandwidth_data:
        stats_file.writelines(str(data) + '\n')
    stats_file.close()

    plt.plot(bandwidth_data)
    plt.xlabel("Measurements since start")
    plt.ylabel("Bandwidth (kbits/sec)")
    plt.grid()
    plt.show()
