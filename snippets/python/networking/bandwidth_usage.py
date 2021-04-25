
import psutil
import sys
import time

def print_msg(*args,end='\n'):
    for item in args:
        sys.stdout.write(str(item)+' ')
    sys.stdout.write(end)
    sys.stdout.flush()


def main():
    last_byte_count = 0

    while True:
        new_byte_count = psutil.net_io_counters().bytes_sent + psutil.net_io_counters().bytes_recv

        if last_byte_count != 0:
            bytes_used = new_byte_count - last_byte_count
            kbit_sec_used = convert_bytes_sec_to_kbit_sec(bytes_used)
            print(str(kbit_sec_used) + " kbits/sec")

        last_byte_count = new_byte_count

        time.sleep(1)

def convert_bytes_sec_to_kbit_sec(bytes):
    return int( (8 * bytes) / 1024 )


print = print_msg
main()