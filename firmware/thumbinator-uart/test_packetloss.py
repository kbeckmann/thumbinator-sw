#!/bin/env python2
import time

f = open("/dev/ttyACM0", "rb")
f.readline()

def get_index(f):
    line = f.readline()
    if line == '\n':
        line = f.readline()

    data = line.split(" ")
    index = int(data[0], 16)
    return index, line

miss = 0
tot = 0
num_bytes = 0
t0 = time.time()

x, data = get_index(f)
num_bytes += len(data)

try:
    while True:
        newx, data = get_index(f)
        num_bytes += len(data)
        tot += 1
        if newx - x != 1:
            miss += 1
            print "missed packet. %d/%d (%d => %d)" % (miss, tot, x, newx)
        x = newx
except KeyboardInterrupt:
    t1 = time.time()
    tdiff = t1 - t0
    kilobytes_per_second = (num_bytes / 1024.0) / tdiff
    print ""
    print "Missed %d packets out of %d total" % (miss, tot)
    print "Collected %d bytes during %.2f seconds. %.2f kB/s" % (num_bytes, tdiff, kilobytes_per_second)
